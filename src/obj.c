#include "obj.h"
#include <gc.h>

static Obj empty = {.t = EMPTY};
ObjPtr empty_ptr = &empty;
static Obj undef = {.t = UNDEF};
ObjPtr undef_ptr = &undef;
static Obj otrue = {.t = BOOLEAN_TRUE};
ObjPtr true_ptr = &otrue;
static Obj ofalse = {.t = BOOLEAN_FALSE};
ObjPtr false_ptr = &ofalse;
static Obj strempty = {.t = STREMPTY};
ObjPtr strempty_ptr = &strempty;
ObjPtr quote_ptr = NULL;
static Obj oeof = {.t = OEOF};
ObjPtr eof_ptr = &oeof;
static Obj oapply = {.t = PROC_APPLY};
ObjPtr apply_ptr = &oapply;

ObjPtr iport = NULL;
ObjPtr oport = NULL;
ObjPtr eport = NULL;

ObjPtr cur_iport = NULL;
ObjPtr cur_oport = NULL;
ObjPtr cur_eport = NULL;

ObjPtr num_err(char *name, ObjPtr argl);
ObjPtr domain_err(char *name, ObjPtr argl);
static size_t clength(ObjPtr p);
ObjPtr utf8_to_scmstr(const char *s);
void cwrite(ObjPtr p, ObjPtr port);
ObjPtr enew(ObjPtr m, ObjPtr o);

ObjPtr scm_eqv_p(ObjPtr argl) {
  if (clength(argl) != 2) {
    return num_err("eqv?", argl);
  }
  ObjPtr p1 = argl->p->l;
  if (err_p(p1)) {
    return p1;
  }
  Type t1 = p1->t;
  ObjPtr p2 = argl->p->r->p->l;
  if (err_p(p2)) {
    return p2;
  }
  Type t2 = p2->t;
  switch (t1) {
  case BOOLEAN_TRUE:
  case BOOLEAN_FALSE:
  case SYM:
  case SYMV:
  case EMPTY:
  case PAIR:
  case STR:
  case STREMPTY:
  case PROC:
  case CPROC:
  case PROC_APPLY:
  case UNDEF:
  case IPORT:
  case OPORT:
  case IPORT_CLOSED:
  case OPORT_CLOSED:
  case IBPORT:
  case OBPORT:
  case IBPORT_CLOSED:
  case OBPORT_CLOSED:
  case OEOF:
  case VEC:
    return p1 == p2 ? true_ptr : false_ptr;
  case COMPLEX: {
    if (t2 == COMPLEX) {
      return mpc_cmp(p1->z, p2->z) == 0 ? true_ptr : false_ptr;
    }
    return false_ptr;
  }
  case RATIONAL: {
    if (t2 == RATIONAL) {
      return mpq_equal(p1->q, p2->q) ? true_ptr : false_ptr;
    }
    return false_ptr;
  }
  case CHAR: {
    if (t2 == CHAR) {
      return p1->uc == p2->uc ? true_ptr : false_ptr;
    }
    return false_ptr;
  }
  case CONT:
    return false_ptr;
  case ERR:
  case RERR:
  case FERR:
    return p1 == p2 ? true_ptr : false_ptr;
  }
}
ObjPtr scm_eq_p(ObjPtr argl) {
  if (clength(argl) != 2) {
    return num_err("eq?", argl);
  }
  if (err_p(argl->p->l)) {
    return argl->p->l;
  }
  if (err_p(argl->p->l)) {
    return argl->p->l;
  }
  if (err_p(argl->p->r->p->l)) {
    return argl->p->r->p->l;
  }
  return argl->p->l == argl->p->r->p->l ? true_ptr : false_ptr;
}
static ObjPtr onew(Type t) {
  ObjPtr out = GC_MALLOC(sizeof(Obj));
  out->t = t;
  return out;
}
static ObjPtr stack = NULL;
void save(ObjPtr p) { stack = pnew(p, stack); }
ObjPtr restore() {
  ObjPtr p = stack->p->l;
  stack = stack->p->r;
  return p;
}
static ObjPtr cpnew(Type t, ObjPtr l, ObjPtr r) {
  ObjPtr out = onew(t);
  out->p = GC_MALLOC(sizeof(Pair));
  out->p->l = l;
  out->p->r = r;
  return out;
}
/* environment */
static ObjPtr add_binding_to_frame(ObjPtr var, ObjPtr val, ObjPtr frame) {
  frame->p->l = pnew(var, frame->p->l);
  frame->p->r = pnew(val, frame->p->r);
  return undef_ptr;
}
static ObjPtr make_frame(ObjPtr variables, ObjPtr values) {
  return pnew(variables, values);
}

ObjPtr enclosing_environment(ObjPtr env) { return env->p->r; }
static ObjPtr first_frame(ObjPtr env) { return env->p->l; }
static ObjPtr frame_variables(ObjPtr frame) { return frame->p->l; }
static ObjPtr frame_values(ObjPtr frame) { return frame->p->r; }
static size_t clength(ObjPtr p) {
  size_t len = 0;
  for (ObjPtr p0 = p; p0 != empty_ptr; p0 = p0->p->r) {
    len++;
  }
  return len;
}
ObjPtr extend_environment(ObjPtr vars, ObjPtr vals, ObjPtr base_env) {
  ObjPtr vars0 = empty_ptr;
  ObjPtr vals0 = empty_ptr;
  ObjPtr vals1 = vals;
  for (ObjPtr vars1 = vars; vars1 != empty_ptr; vars1 = vars1->p->r) {
    if (vars1->t == SYM || vars1->t == SYMV) {
      vars0 = pnew(vars1, vars0);
      vals0 = pnew(vals1, vals0);
      return pnew(make_frame(vars0, vals0), base_env);
    }
    if (vals1 == empty_ptr) {
      fprintf(eport->port->fh, "Too few arguments supplied\n");
      cwrite(vars, eport);
      fprintf(eport->port->fh, "\n");
      cwrite(vals, eport);
      fprintf(eport->port->fh, "\n");
      exit(1);
    }
    if (vars1->p->l->t != SYM && vars1->p->l->t != SYMV) {
      fprintf(eport->port->fh, "Error: parameters\n");
      cwrite(vars1->p->l, eport);
      fprintf(eport->port->fh, "\n");
      cwrite(vars, eport);
      fprintf(eport->port->fh, "\n");
      exit(1);
    }
    vars0 = pnew(vars1->p->l, vars0);
    vals0 = pnew(vals1->p->l, vals0);
    vals1 = vals1->p->r;
  }
  if (vals1 != empty_ptr) {
    fprintf(eport->port->fh, "Too many arguments supplied\n");
    cwrite(vars, eport);
    fprintf(eport->port->fh, "\n");
    cwrite(vals, eport);
    fprintf(eport->port->fh, "\n");
    exit(1);
  }
  return pnew(make_frame(vars0, vals0), base_env);
}
static ObjPtr lookup_variable_value_scan(ObjPtr var, ObjPtr env, ObjPtr vars,
                                         ObjPtr vals);
static ObjPtr lookup_variable_value_env_loop(ObjPtr var, ObjPtr env);
static ObjPtr lookup_variable_value_scan(ObjPtr var, ObjPtr env, ObjPtr vars,
                                         ObjPtr vals) {
  if (vars == empty_ptr) {
    return lookup_variable_value_env_loop(var, enclosing_environment(env));
  }
  if (var == vars->p->l) {
    return vals->p->l;
  }
  return lookup_variable_value_scan(var, env, vars->p->r, vals->p->r);
}
static ObjPtr the_empty_environment_ptr = NULL;
static ObjPtr lookup_variable_value_env_loop(ObjPtr var, ObjPtr env) {
  if (env == the_empty_environment_ptr) {
    fprintf(stderr, "unbound variable ");
    cwrite(var, eport);
    fprintf(stderr, "\n");
    exit(1);
  }
  ObjPtr frame = first_frame(env);
  return lookup_variable_value_scan(var, env, frame_variables(frame),
                                    frame_values(frame));
}
ObjPtr lookup_variable_value(ObjPtr var, ObjPtr env) {
  return lookup_variable_value_env_loop(var, env);
}
static ObjPtr set_variable_value_scan(ObjPtr var, ObjPtr val, ObjPtr env,
                                      ObjPtr vars, ObjPtr vals);
static ObjPtr set_variable_value_env_loop(ObjPtr var, ObjPtr val, ObjPtr env);
static ObjPtr set_variable_value_scan(ObjPtr var, ObjPtr val, ObjPtr env,
                                      ObjPtr vars, ObjPtr vals) {
  if (vars == empty_ptr) {
    return set_variable_value_env_loop(var, val, enclosing_environment(env));
  }
  if (var == vars->p->l) {
    vals->p->l = val;
    return undef_ptr;
  }
  return set_variable_value_scan(var, val, env, vars->p->r, vals->p->r);
}
static ObjPtr set_variable_value_env_loop(ObjPtr var, ObjPtr val, ObjPtr env) {
  if (env == the_empty_environment_ptr) {
    fprintf(stderr, "unbound variable -- set! ");
    cwrite(var, eport);
    fprintf(stderr, "\n");
    exit(1);
  }
  ObjPtr frame = first_frame(env);
  return set_variable_value_scan(var, val, env, frame_variables(frame),
                                 frame_values(frame));
}
ObjPtr set_variable_value(ObjPtr var, ObjPtr val, ObjPtr env) {
  return set_variable_value_env_loop(var, val, env);
}
static ObjPtr define_variable_scan(ObjPtr frame, ObjPtr var, ObjPtr val,
                                   ObjPtr vars, ObjPtr vals) {
  if (vars == empty_ptr) {
    return add_binding_to_frame(var, val, frame);
  }
  if (var == vars->p->l) {
    vals->p->l = val;
    return undef_ptr;
  }
  return define_variable_scan(frame, var, val, vars->p->r, vals->p->r);
}
ObjPtr define_variable(ObjPtr var, ObjPtr val, ObjPtr env) {
  ObjPtr frame = first_frame(env);
  return define_variable_scan(frame, var, val, frame_variables(frame),
                              frame_values(frame));
}
ObjPtr num_err(char *name, ObjPtr argl) {
  char *s = NULL;
  asprintf(&s, "(%s) wrong number of arguments --", name);
  ObjPtr p = enew(utf8_to_scmstr(s), pnew(argl, empty_ptr));
  free(s);
  return p;
}
ObjPtr domain_err(char *name, ObjPtr argl) {
  char *s = NULL;
  asprintf(&s, "(%s) argument out of domain --", name);
  ObjPtr p = enew(utf8_to_scmstr(s), pnew(argl, empty_ptr));
  free(s);
  return p;
}

/* pair */
ObjPtr pnew(ObjPtr l, ObjPtr r) { return cpnew(PAIR, l, r); }
bool clist_p(ObjPtr p) {
  for (ObjPtr p0 = p; p0 != empty_ptr; p0 = p0->p->r) {
    if (p0->t != PAIR) {
      return false;
    }
  }
  return true;
}
ObjPtr creverse(ObjPtr p) {
  ObjPtr out = empty_ptr;
  for (ObjPtr p0 = p; p0 != empty_ptr; p0 = p0->p->r) {
    out = pnew(p0->p->l, out);
  }
  return out;
}
ObjPtr scm_cons(ObjPtr argl) {
  if (clength(argl) != 2) {
    return num_err("cons", argl);
  }
  ObjPtr p1 = argl->p->l;
  ObjPtr p2 = argl->p->r->p->l;
  if (err_p(p1)) {
    return p1;
  }
  if (err_p(p2)) {
    return p2;
  }
  return pnew(p1, p2);
}
ObjPtr scm_car(ObjPtr argl) {
  if (clength(argl) != 1) {
    return num_err("car", argl);
  }
  ObjPtr p = argl->p->l;
  if (err_p(p)) {
    return p;
  }
  if (p->t != PAIR) {
    return domain_err("car", argl);
  }
  return p->p->l;
}
ObjPtr scm_cdr(ObjPtr argl) {
  if (clength(argl) != 1) {
    return num_err("cdr", argl);
  }
  ObjPtr p = argl->p->l;
  if (err_p(p)) {
    return p;
  }
  if (p->t != PAIR) {
    return domain_err("cdr", argl);
  }
  return p->p->r;
}
ObjPtr scm_set_car(ObjPtr argl) {
  if (clength(argl) != 2) {
    return num_err("set-car!", argl);
  }
  ObjPtr p1 = argl->p->l;
  ObjPtr p2 = argl->p->r->p->l;
  if (err_p(p1)) {
    return p1;
  }
  if (p1->t != PAIR) {
    return domain_err("set-car!", argl);
  }
  if (err_p(p2)) {
    return p2;
  }
  p1->p->l = p2;
  return undef_ptr;
}
ObjPtr scm_set_cdr(ObjPtr argl) {
  if (clength(argl) != 2) {
    return num_err("set-cdr!", argl);
  }
  ObjPtr p1 = argl->p->l;
  if (err_p(p1)) {
    return p1;
  }
  ObjPtr p2 = argl->p->r->p->l;
  if (err_p(p2)) {
    return p2;
  }
  if (p1->t != PAIR) {
    return domain_err("set-cdr!", argl);
  }
  p1->p->r = p2;
  return undef_ptr;
}
ObjPtr scm_null_p(ObjPtr argl) {
  if (clength(argl) != 1) {
    return num_err("null?", argl);
  }
  if (err_p(argl->p->l)) {
    return argl->p->l;
  }
  return argl->p->l == empty_ptr ? true_ptr : false_ptr;
}
ObjPtr scm_pair_p(ObjPtr argl) {
  if (clength(argl) != 1) {
    return num_err("pair?", argl);
  }
  if (err_p(argl->p->l)) {
    return argl->p->l;
  }
  return argl->p->l->t == PAIR ? true_ptr : false_ptr;
}
/* string */
ObjPtr strnew(ObjPtr l, ObjPtr r) { return cpnew(STR, l, r); }
ObjPtr scm_string_p(ObjPtr argl) {
  if (clength(argl) != 1) {
    return num_err("string?", argl);
  }
  if (err_p(argl->p->l)) {
    return argl->p->l;
  }
  Type t = argl->p->l->t;
  return t == STR || t == STREMPTY ? true_ptr : false_ptr;
}
ObjPtr scm_list_to_string(ObjPtr argl) {
  if (clength(argl) != 1) {
    return num_err("list->string", argl);
  }
  ObjPtr p = argl->p->l;
  if (err_p(p)) {
    return p;
  }
  if (!clist_p(p)) {
    return domain_err("list->string", argl);
  }
  p = creverse(p);
  ObjPtr out = strempty_ptr;
  for (ObjPtr p0 = p; p0 != empty_ptr; p0 = p0->p->r) {
    ObjPtr p1 = p0->p->l;
    if (p1->t != CHAR) {
      return domain_err("list->string", argl);
    }
    out = strnew(p1, out);
  }
  return out;
}
size_t cslength(ObjPtr p) {
  size_t len = 0;
  for (ObjPtr p0 = p; p0 != strempty_ptr; p0 = p0->p->r) {
    len++;
  }
  return len;
}
ObjPtr scm_string_to_list(ObjPtr argl) {
  size_t len = clength(argl);
  if (len == 1) {
    ObjPtr p = argl->p->l;
    if (p->t == STR || p->t == STREMPTY) {
      ObjPtr out = empty_ptr;
      for (ObjPtr p0 = p; p0 != strempty_ptr; p0 = p0->p->r) {
        ObjPtr c = p0->p->l;
        if (err_p(c)) {
          return c;
        }
        if (c->t != CHAR) {
          return domain_err("string->list", argl);
        }
        out = pnew(c, out);
      }
      return creverse(out);
    }
    if (err_p(argl)) {
      return argl;
    }
    return domain_err("string->list", argl);
  }
  return num_err("string->list", argl);
}
ObjPtr scm_string_set(ObjPtr argl) {
  if (clength(argl) != 3) {
    return num_err("string-set!", argl);
  }
  ObjPtr p1 = argl->p->l;
  ObjPtr p2 = argl->p->r->p->l;
  ObjPtr p3 = argl->p->r->p->r->p->l;
  if ((p1->t == STR || p1->t == STREMPTY) && p2->t == RATIONAL &&
      p3->t == CHAR && mpz_cmp_ui(mpq_denref(p2->q), 1) == 0 &&
      mpz_cmp_ui(mpq_numref(p2->q), 0) > 0) {
    size_t k = mpz_get_ui(mpq_numref(p2->q));
    if (k < cslength(p1)) {
      ObjPtr p = p1;
      for (size_t i = 0; i < k; i++) {
        p = p->p->r;
      }
      p->p->l = p3;
      return undef_ptr;
    }
  }
  if (err_p(argl)) {
    return argl;
  }
  return domain_err("string-set!", argl);
}
ObjPtr utf8_to_scmstr(const char *s) {
  glong items_written;
  gunichar *ucs = g_utf8_to_ucs4_fast(s, -1, &items_written);
  ObjPtr out = strempty_ptr;
  for (glong i = items_written - 1; i >= 0; i--) {
    out = strnew(cnewuc(ucs[i]), out);
  }
  g_free(ucs);
  return out;
}
char *cscmstr_to_utf8(ObjPtr p) {
  size_t len = cslength(p);
  gunichar ucs[len];
  size_t i = 0;
  for (ObjPtr p0 = p; p0 != strempty_ptr; p0 = p0->p->r) {
    ucs[i] = p0->p->l->uc;
    i++;
  }
  char *s = g_ucs4_to_utf8(ucs, len, NULL, NULL, NULL);
  char *out = GC_STRDUP(s);
  g_free(s);
  return out;
}
/* symbol */
GHashTable *symtab = NULL;
GStringChunk *chunk = NULL;
ObjPtr symnew(char *s) {
  gchar *sym = g_string_chunk_insert_const(chunk, s);
  ObjPtr p = g_hash_table_lookup(symtab, sym);
  if (p == NULL) {
    /* p = onew(SYM); */
    p = malloc(sizeof(Obj));
    p->t = SYM;
    p->s = sym;
    g_hash_table_insert(symtab, sym, p);
  }
  return p;
}
ObjPtr symvnew(char *s) {
  gchar *sym = g_string_chunk_insert_const(chunk, s);
  ObjPtr p = g_hash_table_lookup(symtab, sym);
  if (p == NULL) {
    /* p = onew(SYMV); */
    p = malloc(sizeof(Obj));
    p->t = SYMV;
    p->s = sym;
    g_hash_table_insert(symtab, sym, p);
  }
  return p;
}
ObjPtr contnew(Ptr p) {
  ObjPtr out = onew(CONT);
  out->ptr = p;
  return out;
}
ObjPtr scm_symbol_p(ObjPtr argl) {
  if (clength(argl) != 1) {
    return num_err("symbol?", argl);
  }
  Type t = argl->p->l->t;
  return t == SYM || t == SYMV ? true_ptr : false_ptr;
}
ObjPtr scm_symbol_to_string(ObjPtr argl) {
  if (clength(argl) != 1) {
    return num_err("symbol->string", argl);
  }
  ObjPtr p = argl->p->l;
  if (err_p(p)) {
    return p;
  }
  Type t = p->t;
  if (t != SYM && t != SYMV) {
    return domain_err("symbol->string", argl);
  }
  return utf8_to_scmstr(p->s);
}
ObjPtr scm_string_to_symbol(ObjPtr argl) {
  if (clength(argl) != 1) {
    return num_err("string->symbol", argl);
  }
  ObjPtr p = argl->p->l;
  if (err_p(p)) {
    return p;
  }
  if (p->t != STR && p->t != STREMPTY) {
    return domain_err("string->symbol", argl);
  }
  char *s = cscmstr_to_utf8(p);
  return symvnew(s);
}
/* numbers */
ObjPtr qnew(char *s) {
  ObjPtr p = onew(RATIONAL);
  mpq_init(p->q);
  mpq_set_str(p->q, s, 10);
  mpq_canonicalize(p->q);
  return p;
}
static mpfr_prec_t prec = 53;
static mpq_t opq1;
static mpf_t opf1;
static mpfr_t opfr1;
static mpc_t opc1;
static mpq_t qzero;
ObjPtr znewfr(char *s) {
  ObjPtr p = onew(COMPLEX);
  mpc_init2(p->z, prec);
  mpfr_set_str(mpc_realref(p->z), s, 10, MPFR_RNDN);
  mpfr_set_ui(mpc_imagref(p->z), 0, MPFR_RNDN);
  return p;
}
void zreal(char *s) { mpfr_set_str(opfr1, s, 10, MPFR_RNDN); }
void zrealq(char *s) {
  mpq_set_str(opq1, s, 10);
  mpfr_set_q(opfr1, opq1, MPFR_RNDN);
}
ObjPtr znew_fr_fr(char sgn, char *s) {
  ObjPtr p = onew(COMPLEX);
  mpc_init2(p->z, prec);
  mpfr_set(mpc_realref(p->z), opfr1, MPFR_RNDN);
  mpfr_set_str(mpc_imagref(p->z), s, 10, MPFR_RNDN);
  if (sgn == '-') {
    mpfr_neg(mpc_imagref(p->z), mpc_imagref(p->z), MPFR_RNDN);
  }
  return p;
}
ObjPtr znew_fr_q(char sgn, char *s) {
  ObjPtr p = onew(COMPLEX);
  mpc_init2(p->z, prec);
  mpfr_set(mpc_realref(p->z), opfr1, MPFR_RNDN);
  mpq_set_str(opq1, s, 10);
  if (sgn == '-') {
    mpq_neg(opq1, opq1);
  }
  mpfr_set_q(mpc_imagref(p->z), opq1, MPFR_RNDN);
  return p;
}
ObjPtr znew_fr(char *s) {
  ObjPtr p = onew(COMPLEX);
  mpc_init2(p->z, prec);
  mpfr_set_ui(mpc_realref(p->z), 0, MPFR_RNDN);
  mpfr_set_str(mpc_imagref(p->z), s, 10, MPFR_RNDN);
  return p;
}
ObjPtr znew_q(char *s) {
  ObjPtr p = onew(COMPLEX);

  mpc_init2(p->z, prec);
  mpfr_set_ui(mpc_realref(p->z), 0, MPFR_RNDN);
  mpq_set_str(opq1, s, 10);
  mpfr_set_q(mpc_imagref(p->z), opq1, MPFR_RNDN);
  return p;
}
ObjPtr znew_s_s(char *s1, char *s2) {
  ObjPtr p = onew(COMPLEX);
  mpc_init2(p->z, prec);
  mpfr_set_str(mpc_realref(p->z), s1, 10, MPFR_RNDN);
  mpfr_set_str(mpc_imagref(p->z), s2, 10, MPFR_RNDN);
  return p;
}
ObjPtr scm_ceiling(ObjPtr argl) {
  if (clength(argl) != 1) {
    return num_err("ceiling", argl);
  }
  ObjPtr p = argl->p->l;
  if (err_p(p)) {
    return p;
  }
  switch (p->t) {
  case COMPLEX: {
    if (!mpfr_zero_p(mpc_imagref(p->z))) {
      return domain_err("ceiling", argl);
    }
    ObjPtr out = onew(COMPLEX);
    mpc_init2(out->z, prec);
    mpfr_ceil(mpc_realref(out->z), mpc_realref(p->z));
    mpfr_set_ui(mpc_imagref(out->z), 0, MPFR_RNDN);
    return out;
  }
  case RATIONAL: {
    ObjPtr out = onew(RATIONAL);
    mpq_init(out->q);
    mpz_cdiv_q(mpq_numref(out->q), mpq_numref(p->q), mpq_denref(p->q));
    mpz_set_ui(mpq_denref(out->q), 1);
    return out;
  }
  default:
    return domain_err("ceiling", argl);
  }
}
ObjPtr scm_denominator(ObjPtr argl) {
  if (clength(argl) != 1) {
    return num_err("denominator", argl);
  }
  ObjPtr p = argl->p->l;
  if (err_p(p)) {
    return p;
  }
  switch (p->t) {
  case RATIONAL: {
    ObjPtr out = onew(RATIONAL);
    mpq_init(out->q);
    mpz_set(mpq_numref(out->q), mpq_denref(p->q));
    mpz_set_ui(mpq_denref(out->q), 1);
    return out;
  }
  default:
    return domain_err("denominator", argl);
  }
}
ObjPtr scm_numerator(ObjPtr argl) {
  if (clength(argl) != 1) {
    return num_err("numerator", argl);
  }
  ObjPtr p = argl->p->l;
  if (err_p(p)) {
    return p;
  }
  switch (p->t) {
  case RATIONAL: {
    ObjPtr out = onew(RATIONAL);
    mpq_init(out->q);
    mpz_set(mpq_numref(out->q), mpq_numref(p->q));
    mpz_set_ui(mpq_denref(out->q), 1);
    return out;
  }
  default:
    return domain_err("numerator", argl);
  }
}
ObjPtr scm_exact(ObjPtr argl) {
  if (clength(argl) != 1) {
    return num_err("exact", argl);
  }
  ObjPtr p = argl->p->l;
  if (err_p(p)) {
    return p;
  }
  switch (p->t) {
  case COMPLEX: {
    if (!mpfr_zero_p(mpc_imagref(p->z))) {
      return domain_err("exact", argl);
    }
    mpfr_get_f(opf1, mpc_realref(p->z), MPFR_RNDN);
    ObjPtr out = onew(RATIONAL);
    mpq_init(out->q);
    mpq_set_f(out->q, opf1);
    return out;
  }
  case RATIONAL:
    return p;
  default:
    return domain_err("exact", argl);
  }
}
ObjPtr scm_truncate(ObjPtr argl) {
  if (clength(argl) != 1) {
    return num_err("truncate", argl);
  }
  ObjPtr p = argl->p->l;
  if (err_p(p)) {
    return p;
  }
  switch (p->t) {
  case COMPLEX: {
    if (!mpfr_zero_p(mpc_imagref(p->z))) {
      return domain_err("truncate", argl);
    }
    ObjPtr out = onew(COMPLEX);
    mpc_init2(out->z, prec);
    mpfr_trunc(mpc_realref(out->z), mpc_realref(p->z));
    mpfr_set_ui(mpc_imagref(out->z), 0, MPFR_RNDN);
    return out;
  }
  case RATIONAL: {
    ObjPtr out = onew(RATIONAL);
    mpq_init(out->q);
    mpz_tdiv_q(mpq_numref(out->q), mpq_numref(p->q), mpq_denref(p->q));
    mpz_set_ui(mpq_denref(out->q), 1);
    return out;
  }
  default:
    return domain_err("truncate", argl);
  }
}
ObjPtr scm_real_part(ObjPtr argl) {
  if (clength(argl) != 1) {
    return num_err("real-part", argl);
  }
  ObjPtr p = argl->p->l;
  if (err_p(p)) {
    return p;
  }
  switch (p->t) {
  case COMPLEX: {
    ObjPtr out = onew(COMPLEX);
    mpc_init2(out->z, prec);
    mpfr_set_fr(mpc_realref(out->z), mpc_realref(p->z), MPFR_RNDN);
    mpfr_set_ui(mpc_imagref(out->z), 0, MPFR_RNDN);
    return out;
  }
  case RATIONAL: {
    ObjPtr out = onew(RATIONAL);
    mpq_init(out->q);
    mpq_set(out->q, p->q);
    return out;
  }
  default:
    return domain_err("real-part", argl);
  }
}
ObjPtr scm_imag_part(ObjPtr argl) {
  if (clength(argl) != 1) {
    return num_err("imag-part", argl);
  }
  ObjPtr p = argl->p->l;
  if (err_p(p)) {
    return p;
  }
  switch (p->t) {
  case COMPLEX: {
    ObjPtr out = onew(COMPLEX);
    mpc_init2(out->z, prec);
    mpfr_set_fr(mpc_realref(out->z), mpc_imagref(p->z), MPFR_RNDN);
    mpfr_set_ui(mpc_imagref(out->z), 0, MPFR_RNDN);
    return out;
  }
  case RATIONAL:
    return qnew("0");
  default:
    return domain_err("imag-part", argl);
  }
}
ObjPtr scm_angle(ObjPtr argl) {
  if (clength(argl) != 1) {
    return num_err("angle", argl);
  }
  ObjPtr p = argl->p->l;
  if (err_p(p)) {
    return p;
  }
  switch (p->t) {
  case COMPLEX: {
    ObjPtr out = onew(COMPLEX);
    mpc_init2(out->z, prec);
    mpc_arg(mpc_realref(out->z), p->z, MPC_RNDNN);
    mpfr_set_ui(mpc_imagref(out->z), 0, MPFR_RNDN);
    return out;
  }
  case RATIONAL: {
    ObjPtr out = onew(COMPLEX);
    mpc_init2(out->z, prec);
    mpc_set_q_q(opc1, p->q, qzero, MPC_RNDNN);
    mpc_arg(mpc_realref(out->z), opc1, MPC_RNDNN);
    mpfr_set_ui(mpc_imagref(out->z), 0, MPFR_RNDN);
    return out;
  }
  default:
    return domain_err("angle", argl);
  }
}
ObjPtr scm_infinite_p(ObjPtr argl) {
  if (clength(argl) != 1) {
    return num_err("infinite?", argl);
  }
  ObjPtr p = argl->p->l;
  if (err_p(p)) {
    return p;
  }
  switch (p->t) {
  case COMPLEX:
    return mpfr_inf_p(mpc_realref(p->z)) || mpfr_inf_p(mpc_imagref(p->z))
               ? true_ptr
               : false_ptr;
  case RATIONAL:
    return false_ptr;
  default:
    return domain_err("infinite?", argl);
  }
}
ObjPtr scm_nan_p(ObjPtr argl) {
  if (clength(argl) != 1) {
    return num_err("nan?", argl);
  }
  ObjPtr p = argl->p->l;
  if (err_p(p)) {
    return p;
  }
  switch (p->t) {
  case COMPLEX:
    return mpfr_nan_p(mpc_realref(p->z)) || mpfr_nan_p(mpc_imagref(p->z))
               ? true_ptr
               : false_ptr;
  case RATIONAL:
    return false_ptr;
  default:
    return domain_err("nan?", argl);
  }
}

ObjPtr scm_number_p(ObjPtr argl) {
  if (clength(argl) != 1) {
    return num_err("number?", argl);
  }
  if (err_p(argl->p->l)) {
    return argl->p->l;
  }
  switch (argl->p->l->t) {
  case COMPLEX:
  case RATIONAL:
    return true_ptr;
  default:
    return false_ptr;
  }
}
ObjPtr scm_exact_p(ObjPtr argl) {
  if (clength(argl) != 1) {
    return num_err("number?", argl);
  }
  switch (argl->p->l->t) {
  case RATIONAL:
    return true_ptr;
  default:
    return false_ptr;
  }
}
ObjPtr scm_floor(ObjPtr argl) {
  if (clength(argl) != 1) {
    return num_err("floor", argl);
  }
  ObjPtr p = argl->p->l;
  if (err_p(p)) {
    return p;
  }
  switch (p->t) {
  case COMPLEX: {
    if (!mpfr_zero_p(mpc_imagref(p->z))) {
      return domain_err("floor", argl);
    }
    ObjPtr out = onew(COMPLEX);
    mpc_init2(out->z, prec);
    mpfr_floor(mpc_realref(out->z), mpc_realref(p->z));
    mpfr_set_ui(mpc_imagref(out->z), 0, MPFR_RNDN);
    return out;
  }
  case RATIONAL: {
    ObjPtr out = onew(RATIONAL);
    mpq_init(out->q);
    mpz_fdiv_q(mpq_numref(out->q), mpq_numref(p->q), mpq_denref(p->q));
    mpz_set_ui(mpq_denref(out->q), 1);
    return out;
  }
  default:
    return domain_err("floor", argl);
  }
}
ObjPtr scm_round(ObjPtr argl) {
  if (clength(argl) != 1) {
    return num_err("round", argl);
  }
  ObjPtr p = argl->p->l;
  if (err_p(p)) {
    return p;
  }
  switch (p->t) {
  case COMPLEX: {
    if (!mpfr_zero_p(mpc_imagref(p->z))) {
      return domain_err("round", argl);
    }
    ObjPtr out = onew(COMPLEX);
    mpc_init2(out->z, prec);
    mpfr_round(mpc_realref(out->z), mpc_realref(p->z));
    mpfr_set_ui(mpc_imagref(out->z), 0, MPFR_RNDN);
    return out;
  }
  case RATIONAL: {
    ObjPtr out = onew(RATIONAL);
    mpq_init(out->q);
    mpf_set_q(opf1, p->q);
    mpz_set_f(mpq_numref(out->q), opf1);
    mpz_set_ui(mpq_denref(out->q), 1);
    return out;
  }
  default:
    return domain_err("round", argl);
  }
}
ObjPtr scm_math_equal(ObjPtr argl) {
  if (argl == empty_ptr || argl->p->r == empty_ptr) {
    return num_err("=", argl);
  }
  bool flag = true;
  ObjPtr p0 = argl->p->l;
  if (err_p(p0)) {
    return p0;
  }
  switch (p0->t) {
  case RATIONAL:
    break;
  case COMPLEX:
    flag = false;
    break;
  default:
    return domain_err("=", argl);
  }
  for (ObjPtr p = argl->p->r; p != empty_ptr; p = p->p->r) {
    ObjPtr p1 = p->p->l;
    if (err_p(p1)) {
      return p1;
    }
    if (flag) {
      switch (p1->t) {
      case RATIONAL: {
        if (mpq_equal(p0->q, p1->q)) {
          p0 = p1;
          break;
        }
        return false_ptr;
      }
      case COMPLEX: {
        mpc_set_q_q(opc1, p0->q, qzero, MPC_RNDNN);
        if (mpc_cmp(opc1, p1->z) == 0) {
          p0 = p1;
          flag = false;
          break;
        }
        return false_ptr;
      }
      default:
        return domain_err("=", argl);
      }
    } else {
      switch (p1->t) {
      case RATIONAL: {
        mpc_set_q_q(opc1, p1->q, qzero, MPC_RNDNN);
        if (mpc_cmp(p0->z, opc1) == 0) {
          p0 = p1;
          flag = true;
          break;
        }
        return false_ptr;
      }
      case COMPLEX: {
        if (mpc_cmp(p0->z, p1->z) == 0) {
          p0 = p1;
          break;
        }
        return false_ptr;
      }
      default:
        return domain_err("=", argl);
      }
    }
  }
  return true_ptr;
}
ObjPtr scm_add(ObjPtr argl) {
  mpq_set_ui(opq1, 0, 1);
  bool flag = true;
  for (ObjPtr p = argl; p != empty_ptr; p = p->p->r) {
    ObjPtr p0 = p->p->l;
    if (err_p(p0)) {
      return p0;
    }
    if (flag) {
      switch (p0->t) {
      case RATIONAL: {
        mpq_add(opq1, opq1, p0->q);
        break;
      }
      case COMPLEX: {
        mpfr_set_q(opfr1, opq1, MPFR_RNDN);
        mpc_add_fr(opc1, p0->z, opfr1, MPC_RNDNN);
        flag = false;
        break;
      }
      default:
        return domain_err("+", argl);
      }
    } else {
      switch (p0->t) {
      case RATIONAL: {
        mpfr_set_q(opfr1, p0->q, MPFR_RNDN);
        mpc_add_fr(opc1, opc1, opfr1, MPC_RNDNN);
        break;
      }
      case COMPLEX: {
        mpc_add(opc1, opc1, p0->z, MPC_RNDNN);
        break;
      }
      default:
        return domain_err("+", argl);
      }
    }
  }
  if (flag) {
    ObjPtr p = onew(RATIONAL);
    mpq_init(p->q);
    mpq_set(p->q, opq1);
    return p;
  }
  ObjPtr p = onew(COMPLEX);
  mpc_init2(p->z, prec);
  mpc_set(p->z, opc1, MPC_RNDNN);
  return p;
}
ObjPtr scm_mul(ObjPtr argl) {
  mpq_set_ui(opq1, 1, 1);
  bool flag = true;
  for (ObjPtr p = argl; p != empty_ptr; p = p->p->r) {
    ObjPtr p0 = p->p->l;
    if (err_p(p0)) {
      return p0;
    }
    if (flag) {
      switch (p0->t) {
      case RATIONAL: {
        mpq_mul(opq1, opq1, p0->q);
        break;
      }
      case COMPLEX: {
        mpfr_set_q(opfr1, opq1, MPFR_RNDN);
        mpc_mul_fr(opc1, p0->z, opfr1, MPC_RNDNN);
        flag = false;
        break;
      }
      default:
        return domain_err("*", argl);
      }
    } else {
      switch (p0->t) {
      case RATIONAL: {
        mpfr_set_q(opfr1, p0->q, MPFR_RNDN);
        mpc_mul_fr(opc1, opc1, opfr1, MPC_RNDNN);
        break;
      }
      case COMPLEX: {
        mpc_mul(opc1, opc1, p0->z, MPC_RNDNN);
        break;
      }
      default:
        return domain_err("*", argl);
      }
    }
  }
  if (flag) {
    ObjPtr p = onew(RATIONAL);
    mpq_init(p->q);
    mpq_set(p->q, opq1);
    return p;
  }
  ObjPtr p = onew(COMPLEX);
  mpc_init2(p->z, prec);
  mpc_set(p->z, opc1, MPC_RNDNN);
  return p;
}
ObjPtr scm_div(ObjPtr argl) {
  if (argl == empty_ptr) {
    return num_err("/", argl);
  }
  if (argl->p->r == empty_ptr) {
    ObjPtr p = argl->p->l;
    if (err_p(p)) {
      return p;
    }
    switch (p->t) {
    case COMPLEX: {
      ObjPtr out = onew(COMPLEX);
      mpc_init2(out->z, prec);
      mpc_pow_si(out->z, p->z, -1, MPC_RNDNN);
      return out;
    }
    case RATIONAL: {
      ObjPtr out = onew(RATIONAL);
      mpq_init(out->q);
      mpq_inv(out->q, p->q);
      return out;
    }
    default:
      return domain_err("/", argl);
    }
  }
  ObjPtr p0 = argl->p->l;
  if (err_p(p0)) {
    return p0;
  }

  bool flag = true;
  switch (p0->t) {
  case RATIONAL:
    mpq_set(opq1, p0->q);
    break;
  case COMPLEX:
    mpc_set(opc1, p0->z, MPC_RNDNN);
    flag = false;
    break;
  default:
    return domain_err("/", argl);
  }
  for (ObjPtr p1 = argl->p->r; p1 != empty_ptr; p1 = p1->p->r) {
    ObjPtr p2 = p1->p->l;
    if (err_p(p2)) {
      return p2;
    }

    if (flag) {
      switch (p2->t) {
      case RATIONAL:
        mpq_div(opq1, opq1, p2->q);
        break;
      case COMPLEX:
        mpfr_set_q(opfr1, opq1, MPFR_RNDN);
        mpc_fr_div(opc1, opfr1, p2->z, MPC_RNDNN);
        flag = false;
        break;
      default:
        return domain_err("/", argl);
      }
    } else {
      switch (p2->t) {
      case RATIONAL:
        mpfr_set_q(opfr1, p2->q, MPFR_RNDN);
        mpc_div_fr(opc1, opc1, opfr1, MPC_RNDNN);
        break;
      case COMPLEX:
        mpc_div(opc1, opc1, p2->z, MPC_RNDNN);
        break;
      default:
        return domain_err("/", argl);
      }
    }
  }
  if (flag) {
    ObjPtr out = onew(RATIONAL);
    mpq_init(out->q);
    mpq_set(out->q, opq1);
    return out;
  }
  ObjPtr out = onew(COMPLEX);
  mpc_init2(out->z, prec);
  mpc_set(out->z, opc1, MPC_RNDNN);
  return out;
}
ObjPtr scm_lt(ObjPtr argl) {
  if (argl == empty_ptr || argl->p->r == empty_ptr) {
    return num_err("<", argl);
  }
  bool flag = true;
  ObjPtr p0 = argl->p->l;
  if (err_p(p0)) {
    return p0;
  }

  switch (p0->t) {
  case RATIONAL:
    break;
  case COMPLEX:
    if (!mpfr_zero_p(mpc_imagref(p0->z))) {
      return domain_err("<", argl);
    }
    flag = false;
    break;
  default:
    return domain_err("<", argl);
  }
  for (ObjPtr p = argl->p->r; p != empty_ptr; p = p->p->r) {
    ObjPtr p1 = p->p->l;
    if (err_p(p1)) {
      return p1;
    }

    if (flag) {
      switch (p1->t) {
      case RATIONAL: {
        if (mpq_cmp(p0->q, p1->q) < 0) {
          p0 = p1;
          break;
        }
        return false_ptr;
      }
      case COMPLEX: {
        if (!mpfr_zero_p(mpc_imagref(p1->z))) {
          return domain_err("<", argl);
        }
        if (mpfr_cmp_q(mpc_realref(p1->z), p0->q) > 0) {
          p0 = p1;
          flag = false;
          break;
        }
        return false_ptr;
      }
      default:
        return domain_err("=", argl);
      }
    } else {
      switch (p1->t) {
      case RATIONAL: {
        if (mpfr_cmp_q(mpc_realref(p0->z), p1->q) < 0) {
          p0 = p1;
          flag = true;
          break;
        }
        return false_ptr;
      }
      case COMPLEX: {
        if (!mpfr_zero_p(mpc_imagref(p1->z))) {
          return domain_err("<", argl);
        }
        if (mpfr_less_p(mpc_realref(p0->z), mpc_realref(p1->z))) {
          p0 = p1;
          break;
        }
        return false_ptr;
      }
      default:
        return domain_err("=", argl);
      }
    }
  }
  return true_ptr;
}

ObjPtr scm_number_to_string(ObjPtr argl) {
  size_t len = clength(argl);
  if (len == 1) {
    ObjPtr p = argl->p->l;
    if (err_p(p)) {
      return p;
    }

    switch (p->t) {
    case COMPLEX: {
      char *s;
      mpfr_asprintf(&s, "%Rf%+Rfi", mpc_realref(p->z), mpc_imagref(p->z));
      ObjPtr out = utf8_to_scmstr(s);
      return out;
    }
    case RATIONAL: {
      char *s = NULL;
      gmp_asprintf(&s, "%Qd", p->q);
      ObjPtr out = utf8_to_scmstr(s);
      return out;
    }
    default:
      return domain_err("number->string", argl);
    }
  }
  return num_err("number->string", argl);
}
/* chars */
ObjPtr cnewuc(gunichar uc) {
  ObjPtr p = onew(CHAR);
  p->uc = uc;
  return p;
}
gunichar getuc(FILE *fh) {
  char p[5];
  for (gsize max_len = 1;; max_len++) {
    char c = fgetc(fh);
    if (c == EOF) {
      return EOF;
    }
    p[max_len - 1] = c;
    gunichar uc = g_utf8_get_char_validated(p, max_len);
    if (uc != (gunichar)-2) {
      return uc;
    }
  }
}
ObjPtr scm_char_p(ObjPtr argl) {
  if (clength(argl) != 1) {
    return num_err("char?", argl);
  }
  if (err_p(argl->p->l)) {
    return argl->p->l;
  }

  return argl->p->l->t == CHAR ? true_ptr : false_ptr;
}
ObjPtr scm_char_to_integer(ObjPtr argl) {
  if (clength(argl) != 1) {
    return num_err("char->integer", argl);
  }
  ObjPtr p = argl->p->l;
  if (err_p(p)) {
    return p;
  }
  if (p->t != CHAR) {
    return domain_err("char->integer", argl);
  }
  ObjPtr out = onew(RATIONAL);
  mpq_init(out->q);
  mpq_set_ui(out->q, p->uc, 1);
  return out;
}
ObjPtr scm_integer_to_char(ObjPtr argl) {
  if (clength(argl) != 1) {
    return num_err("integer->char", argl);
  }
  ObjPtr p = argl->p->l;
  if (err_p(p)) {
    return p;
  }

  switch (p->t) {
  case COMPLEX: {
    if (!mpfr_zero_p(mpc_imagref(p->z))) {
      return domain_err("integer->char", argl);
    }
    mpfr_floor(opfr1, mpc_realref(p->z));
    if (mpfr_equal_p(mpc_realref(p->z), opfr1)) {
      return cnewuc(mpfr_get_si(mpc_realref(p->z), MPFR_RNDN));
    }
    return domain_err("integer->char", argl);
  }
  case RATIONAL: {
    if (mpz_cmp_ui(mpq_denref(p->q), 1) == 0) {
      return cnewuc(mpz_get_si(mpq_numref(p->q)));
    }
    return domain_err("integer->char", argl);
  }
  default:
    return domain_err("integer->char", argl);
  }
}
ObjPtr scm_char_alphabetic_p(ObjPtr argl) {
  if (clength(argl) != 1) {
    return num_err("char-alphabetic?", argl);
  }
  ObjPtr p = argl->p->l;
  if (err_p(p)) {
    return p;
  }

  if (p->t == CHAR) {
    return g_unichar_isalpha(p->uc) ? true_ptr : false_ptr;
  }
  return domain_err("char-alphabetic?", argl);
}
ObjPtr scm_char_downcase(ObjPtr argl) {
  if (clength(argl) != 1) {
    return num_err("char-downcase", argl);
  }
  ObjPtr p = argl->p->l;
  if (err_p(p)) {
    return p;
  }

  if (p->t == CHAR) {
    return cnewuc(g_unichar_tolower(p->uc));
  }
  return domain_err("char-downcase", argl);
}
ObjPtr scm_char_foldcase(ObjPtr argl) {
  if (clength(argl) != 1) {
    return num_err("char-foldcase", argl);
  }
  ObjPtr p = argl->p->l;
  if (err_p(p)) {
    return p;
  }

  if (p->t == CHAR) {
    char outbuf[6];
    int len = g_unichar_to_utf8(p->uc, outbuf);
    char *s = g_utf8_casefold(outbuf, len);
    ObjPtr out = onew(CHAR);
    out->uc = g_utf8_get_char(s);
    g_free(s);
    return out;
  }
  return domain_err("char-foldcase", argl);
}
ObjPtr scm_char_lower_case_p(ObjPtr argl) {
  if (clength(argl) != 1) {
    return num_err("char-lower-case?", argl);
  }
  ObjPtr p = argl->p->l;
  if (err_p(p)) {
    return p;
  }

  if (p->t == CHAR) {
    return g_unichar_islower(p->uc) ? true_ptr : false_ptr;
  }
  return domain_err("char-lower-case?", argl);
}
ObjPtr scm_char_numeric_p(ObjPtr argl) {
  if (clength(argl) != 1) {
    return num_err("char-numeric?", argl);
  }
  ObjPtr p = argl->p->l;
  if (p->t == CHAR) {
    return g_unichar_isdigit(p->uc) ? true_ptr : false_ptr;
  }
  return domain_err("char-numeric?", argl);
}
ObjPtr scm_char_upcase(ObjPtr argl) {
  if (clength(argl) != 1) {
    return num_err("char-upcase", argl);
  }
  ObjPtr p = argl->p->l;
  if (err_p(p)) {
    return p;
  }

  if (p->t == CHAR) {
    return cnewuc(g_unichar_toupper(p->uc));
  }
  return domain_err("char-upcase", argl);
}
ObjPtr scm_char_upper_case_p(ObjPtr argl) {
  if (clength(argl) != 1) {
    return num_err("char-upper-case?", argl);
  }
  ObjPtr p = argl->p->l;
  if (err_p(p)) {
    return p;
  }

  if (p->t == CHAR) {
    return g_unichar_isupper(p->uc) ? true_ptr : false_ptr;
  }
  return domain_err("char-upper-case?", argl);
}
ObjPtr scm_char_whitespace_p(ObjPtr argl) {
  if (clength(argl) != 1) {
    return num_err("char-whitespace?", argl);
  }
  ObjPtr p = argl->p->l;
  if (err_p(p)) {
    return p;
  }
  if (p->t == CHAR) {
    return g_unichar_isspace(p->uc) ? true_ptr : false_ptr;
  }
  return domain_err("char-whitespace?", argl);
}
ObjPtr scm_digit_value(ObjPtr argl) {
  if (clength(argl) != 1) {
    return num_err("digit-value", argl);
  }
  ObjPtr p = argl->p->l;
  if (err_p(p)) {
    return p;
  }
  if (p->t == CHAR) {
    gint n = g_unichar_digit_value(p->uc);
    if (n == -1) {
      return false_ptr;
    }
    ObjPtr out = onew(RATIONAL);
    mpq_init(out->q);
    mpq_set_ui(out->q, n, 1);
    return out;
  }
  return domain_err("digit-value", argl);
}
/* boolean */
ObjPtr scm_boolean_p(ObjPtr argl) {
  if (clength(argl) != 1) {
    return num_err("boolean?", argl);
  }
  if (err_p(argl->p->l)) {
    return argl->p->l;
  }
  Type t = argl->p->l->t;
  return t == BOOLEAN_TRUE || t == BOOLEAN_FALSE ? true_ptr : false_ptr;
}
/* vector */
ObjPtr vecnew(ObjPtr l, size_t len) {
  ObjPtr o = onew(VEC);
  o->v = GC_MALLOC(sizeof(Vect));
  o->v->len = len;
  ObjPtr p = l;
  ObjPtr *v = GC_MALLOC(sizeof(ObjPtr) * len);
  for (size_t i = 0; i < len; i++) {
    v[i] = p->p->l;
    p = p->p->r;
  }
  o->v->v = v;
  return o;
}
ObjPtr clist_to_vector(ObjPtr p) { return vecnew(p, clength(p)); }
ObjPtr scm_vector_p(ObjPtr argl) {
  if (clength(argl) != 1) {
    return num_err("vector?", argl);
  }
  ObjPtr p = argl->p->l;
  if (err_p(p)) {
    return p;
  }
  return p->t == VEC ? true_ptr : false_ptr;
}
ObjPtr scm_vector_length(ObjPtr argl) {
  if (clength(argl) != 1) {
    return num_err("vector-length", argl);
  }
  ObjPtr p = argl->p->l;
  if (err_p(p)) {
    return p;
  }
  if (p->t == VEC) {
    ObjPtr out = onew(RATIONAL);
    mpq_init(out->q);
    mpq_set_ui(out->q, p->v->len, 1);
    return out;
  }
  return domain_err("vector-length", argl);
}
ObjPtr scm_list_to_vector(ObjPtr argl) {
  if (clength(argl) != 1) {
    return num_err("list->vector", argl);
  }
  ObjPtr p = argl->p->l;
  if (err_p(p)) {
    return p;
  }
  if (clist_p(p)) {
    return clist_to_vector(p);
  }
  return domain_err("list->vector", argl);
}
ObjPtr scm_vector_ref(ObjPtr argl) {
  if (clength(argl) != 2) {
    return num_err("vector-ref", argl);
  }
  ObjPtr p1 = argl->p->l;
  ObjPtr p2 = argl->p->r->p->l;
  if (err_p(p1)) {
    return p1;
  }
  if (err_p(p2)) {
    return p2;
  }
  if (p1->t == VEC && p2->t == RATIONAL &&
      mpz_cmp_ui(mpq_denref(p2->q), 1) == 0 &&
      mpz_cmp_ui(mpq_numref(p2->q), 0) >= 0) {
    size_t i = mpz_get_ui(mpq_numref(p2->q));
    if (i < p1->v->len) {
      return p1->v->v[i];
    }
  }
  return domain_err("vector-ref", argl);
}
ObjPtr scm_vector_set(ObjPtr argl) {
  if (clength(argl) != 3) {
    return num_err("vector-set!", argl);
  }
  ObjPtr p1 = argl->p->l;
  ObjPtr p2 = argl->p->r->p->l;
  ObjPtr p3 = argl->p->r->p->r->p->l;
  if (err_p(p1)) {
    return p1;
  }
  if (err_p(p2)) {
    return p2;
  }
  if (err_p(p3)) {
    return p3;
  }
  if (p1->t == VEC && p2->t == RATIONAL &&
      mpz_cmp_ui(mpq_denref(p2->q), 1) == 0 &&
      mpz_cmp_ui(mpq_numref(p2->q), 0) >= 0) {
    size_t i = mpz_get_ui(mpq_numref(p2->q));
    if (i < p1->v->len) {
      return p1->v->v[i] = p3;
    }
  }
  return domain_err("vector-set!", argl);
}

ObjPtr scm_vector_to_list(ObjPtr argl) {
  size_t len = clength(argl);
  if (len == 1) {
    ObjPtr p = argl->p->l;
    if (err_p(p)) {
      return p;
    }
    if (p->t != VEC) {
      return domain_err("vector->list", argl);
    }
    size_t len = p->v->len;
    ObjPtr *v = p->v->v;
    ObjPtr out = empty_ptr;
    for (size_t i = len; i > 0; i--) {
      out = pnew(v[i - 1], out);
    }
    return out;
  }
  if (len == 2) {
  }
  if (len == 3) {
  }
  return num_err("vector->list", argl);
}
/* vector end */
/* procedure */
ObjPtr procnew(char *name, fn_type fn) {
  ObjPtr p = onew(PROC);
  ProcPtr proc = GC_MALLOC(sizeof(Proc));
  proc->fn = fn;
  proc->name = GC_STRDUP(name);
  p->proc = proc;
  return p;
}
ObjPtr scm_procedure_p(ObjPtr argl) {
  if (clength(argl) != 1) {
    return num_err("procedure?", argl);
  }
  if (err_p(argl->p->l)) {
    return argl->p->l;
  }
  Type t = argl->p->l->t;
  return t == PROC || t == CPROC || t == PROC_APPLY ? true_ptr : false_ptr;
}
/* exceptions */
ObjPtr enew(ObjPtr m, ObjPtr o) {
  ObjPtr p = cpnew(ERR, m, o);
  return p;
}
ObjPtr fenew(ObjPtr m, ObjPtr o) {
  ObjPtr p = cpnew(FERR, m, o);
  return p;
}
void ewrite(ObjPtr p) {
  fprintf(cur_eport->port->fh, "ERROR: ");
  if (p->p->l != strempty_ptr) {
    cdisplay(p->p->l, cur_eport);
    fprintf(cur_eport->port->fh, " ");
  }
  for (ObjPtr p0 = p->p->r; p0 != empty_ptr; p0 = p0->p->r) {
    cwrite(p0->p->l, cur_eport);
    fprintf(cur_eport->port->fh, " ");
  }
}
bool err_p(ObjPtr p) {
  Type t = p->t;
  return t == ERR || t == FERR || t == RERR;
}
ObjPtr scm_raise(ObjPtr argl) {
  if (clength(argl) != 1) {
    return num_err("raise", argl);
  }
  ObjPtr p = argl->p->l;
  if (err_p(p)) {
    return p;
  }
  return enew(strempty_ptr, pnew(p, empty_ptr));
}
ObjPtr scm_error(ObjPtr argl) {
  if (argl == empty_ptr) {
    return num_err("error", argl);
  }
  if (err_p(argl->p->l)) {
    return argl->p->l;
  }
  for (ObjPtr p0 = argl->p->r; p0 != empty_ptr; p0 = p0->p->r) {
    if (err_p(p0->p->l)) {
      return p0->p->l;
    }
  }
  return enew(argl->p->l, argl->p->r);
}
ObjPtr scm_error_object_p(ObjPtr argl) {
  if (clength(argl) != 1) {
    return num_err("error-object?", argl);
  }
  return err_p(argl->p->l) ? true_ptr : false_ptr;
}
ObjPtr scm_error_object_message(ObjPtr argl) {
  if (clength(argl) != 1) {
    return num_err("error-object-message", argl);
  }
  if (err_p(argl->p->l)) {
    return argl->p->l->p->l;
  }
  return domain_err("error-object-message", argl);
}
ObjPtr scm_error_object_irritants(ObjPtr argl) {
  if (clength(argl) != 1) {
    return num_err("error-object-irritants", argl);
  }
  if (err_p(argl->p->l)) {
    return argl->p->l->p->r;
  }
  return domain_err("error-object-irritants", argl);
}
ObjPtr scm_read_error_p(ObjPtr argl) {
  if (clength(argl) != 1) {
    return num_err("read-error?", argl);
  }
  return argl->p->l->t == RERR ? true_ptr : false_ptr;
}
ObjPtr scm_file_error_p(ObjPtr argl) {
  if (clength(argl) != 1) {
    return num_err("file-error?", argl);
  }
  return argl->p->l->t == FERR ? true_ptr : false_ptr;
}
/* io */
ObjPtr portnew(Type t, char *name, FILE *fh) {
  ObjPtr p = onew(t);
  PortPtr port = GC_MALLOC(sizeof(Port));
  port->name = GC_STRDUP(name);
  port->fh = fh;
  p->port = port;
  return p;
}
void cwrite(ObjPtr p, ObjPtr port) {
  switch (p->t) {
  case EMPTY:
    fprintf(port->port->fh, "()");
    break;
  case PAIR: {
    fprintf(port->port->fh, "(");
    cwrite(p->p->l, port);
    ObjPtr p0;
    for (p0 = p; p0->p->r->t == PAIR; p0 = p0->p->r) {
      fprintf(port->port->fh, " ");
      cwrite(p0->p->r->p->l, port);
    }
    if (p0->p->r == empty_ptr) {
      fprintf(port->port->fh, ")");
      break;
    }
    fprintf(port->port->fh, " . ");
    cwrite(p0->p->r, port);
    fprintf(port->port->fh, ")");
    break;
  }
  case SYM:
    fprintf(port->port->fh, "%s", p->s);
    break;
  case SYMV: {
    ObjPtr s = utf8_to_scmstr(p->s);
    fprintf(port->port->fh, "|");
    for (ObjPtr p0 = s; p0 != strempty_ptr; p0 = p0->p->r) {
      ObjPtr c = p0->p->l;
      gunichar uc = c->uc;
      if (uc == '\a') {
        fprintf(port->port->fh, "\\a");
      } else if (uc == '\b') {
        fprintf(port->port->fh, "\\b");
      } else if (uc == '\t') {
        fprintf(port->port->fh, "\\t");
      } else if (uc == '\n') {
        fprintf(port->port->fh, "\\n");
      } else if (uc == '\r') {
        fprintf(port->port->fh, "\\r");
      } else if (uc == '|') {
        fprintf(port->port->fh, "\\|");
      } else if (uc == ' ') {
        fprintf(port->port->fh, " ");
      } else if (!g_unichar_isprint(uc) || uc == '\\') {
        fprintf(port->port->fh, "\\x%x;", uc);
      } else {
        char outbuf[6];
        int len = g_unichar_to_utf8(uc, outbuf);
        outbuf[len] = '\0';
        fprintf(port->port->fh, "%s", outbuf);
      }
    }
    fprintf(port->port->fh, "|");
    break;
  }
  case COMPLEX: {
    if (mpfr_zero_p(mpc_imagref(p->z))) {
      mpfr_fprintf(port->port->fh, "%.32Rf", mpc_realref(p->z));
    } else {
      mpfr_fprintf(port->port->fh, "%.16Rf%+.16Rfi", mpc_realref(p->z),
                   mpc_imagref(p->z));
    }
    break;
  }
  case RATIONAL:
    gmp_fprintf(port->port->fh, "%Qd", p->q);
    break;
  case PROC: {
    fprintf(port->port->fh, "#<primitive-procedure %s>", p->proc->name);
    break;
  }
  case CPROC: {
    fprintf(port->port->fh, "#<compiled-procedure %p>", p->p->l->ptr);
    break;
  }
  case PROC_APPLY:
    fprintf(port->port->fh, "#<primitive-procedure apply>");
    break;
  case CHAR: {
    gchar outbuf[6];
    gint len = g_unichar_to_utf8(p->uc, outbuf);
    outbuf[len] = '\0';
    fprintf(port->port->fh, "#\\%s", outbuf);
    break;
  }
  case STR: {
    fprintf(port->port->fh, "\"");
    for (ObjPtr p0 = p; p0 != strempty_ptr; p0 = p0->p->r) {
      gunichar uc = p0->p->l->uc;
      if (uc == '\a') {
        fprintf(port->port->fh, "\\a");
      } else if (uc == '\b') {
        fprintf(port->port->fh, "\\b");
      } else if (uc == '\t') {
        fprintf(port->port->fh, "\\t");
      } else if (uc == '\n') {
        fprintf(port->port->fh, "\\n");
      } else if (uc == '\r') {
        fprintf(port->port->fh, "\\r");
      } else if (!g_unichar_isprint(uc) || uc == '"' || uc == '\\') {
        fprintf(port->port->fh, "\\x%x;", uc);
      } else {
        gchar outbuf[6];
        gint len = g_unichar_to_utf8(uc, outbuf);
        outbuf[len] = '\0';
        fprintf(port->port->fh, "%s", outbuf);
      }
    }
    fprintf(port->port->fh, "\"");
    break;
  }
  case IPORT: {
    fprintf(port->port->fh, "#<input-port %s>", p->port->name);
    break;
  }
  case OPORT: {
    fprintf(port->port->fh, "#<output-port %s>", p->port->name);
    break;
  }
  case IPORT_CLOSED: {
    fprintf(port->port->fh, "#<input-port(closed) %s>", p->port->name);
    break;
  }
  case OPORT_CLOSED: {
    fprintf(port->port->fh, "#<output-port(closed) %s>", p->port->name);
    break;
  }
  case IBPORT: {
    fprintf(port->port->fh, "#<binary-input-port %s>", p->port->name);
    break;
  }
  case OBPORT: {
    fprintf(port->port->fh, "#<binary-output-port %s>", p->port->name);
    break;
  }
  case IBPORT_CLOSED: {
    fprintf(port->port->fh, "#<binary-input-port(closed) %s>", p->port->name);
    break;
  }
  case OBPORT_CLOSED: {
    fprintf(port->port->fh, "#<binary-output-port(closed) %s>", p->port->name);
    break;
  }
  case UNDEF:
    fprintf(port->port->fh, "#<unspecified>");
    break;
  case BOOLEAN_TRUE:
    fprintf(port->port->fh, "#true");
    break;
  case BOOLEAN_FALSE:
    fprintf(port->port->fh, "#false");
    break;
  case STREMPTY:
    fprintf(port->port->fh, "\"\"");
    break;
  case OEOF:
    fprintf(port->port->fh, "#<eof>");
  case CONT:
    break;
  case ERR:
    fprintf(port->port->fh, "#<error-object message: ");
    cwrite(p->p->l, port);
    fprintf(port->port->fh, " list: ");
    cwrite(p->p->r, port);
    fprintf(port->port->fh, ">");
    break;
  case RERR:
    fprintf(port->port->fh, "#<error-object(read) message: ");
    cwrite(p->p->l, port);
    fprintf(port->port->fh, " list: ");
    cwrite(p->p->r, port);
    fprintf(port->port->fh, ">");
    break;
  case FERR:
    fprintf(port->port->fh, "#<error-object(file) message: ");
    cwrite(p->p->l, port);
    fprintf(port->port->fh, " list: ");
    cwrite(p->p->r, port);
    fprintf(port->port->fh, ">");
    break;
  case VEC: {
    size_t len = p->v->len;
    ObjPtr *v = p->v->v;
    fprintf(port->port->fh, "#(");
    if (len != 0) {
      cdisplay(v[0], port);
      for (size_t i = 1; i < len; i++) {
        fprintf(port->port->fh, " ");
        cwrite(v[i], port);
      }
    }
    fprintf(port->port->fh, ")");
    break;
  }
  }
}
void cdisplay(ObjPtr p, ObjPtr port) {
  switch (p->t) {
  case EMPTY:
  case COMPLEX:
  case RATIONAL:
  case PROC:
  case CPROC:
  case PROC_APPLY:
  case IPORT:
  case OPORT:
  case IPORT_CLOSED:
  case OPORT_CLOSED:
  case IBPORT:
  case OBPORT:
  case IBPORT_CLOSED:
  case OBPORT_CLOSED:
  case UNDEF:
  case BOOLEAN_TRUE:
  case BOOLEAN_FALSE:
  case CONT:
  case SYM:
  case OEOF:
  case ERR:
  case RERR:
  case FERR:
    cwrite(p, port);
    break;
  case CHAR: {
    gchar outbuf[6];
    gint len = g_unichar_to_utf8(p->uc, outbuf);
    outbuf[len] = '\0';
    fprintf(port->port->fh, "%s", outbuf);
    break;
  }
  case STR: {
    for (ObjPtr p0 = p; p0 != strempty_ptr; p0 = p0->p->r) {
      cdisplay(p0->p->l, port);
    }
    break;
  }
  case STREMPTY:
    fprintf(port->port->fh, "");
    break;
  case PAIR: {
    fprintf(port->port->fh, "(");
    cdisplay(p->p->l, port);
    ObjPtr p0;
    for (p0 = p; p0->p->r->t == PAIR; p0 = p0->p->r) {
      fprintf(port->port->fh, " ");
      cdisplay(p0->p->r->p->l, port);
    }
    if (p0->p->r == empty_ptr) {
      fprintf(port->port->fh, ")");
      break;
    }
    fprintf(port->port->fh, " . ");
    cdisplay(p0->p->r, port);
    fprintf(port->port->fh, ")");
    break;
  }
  case SYMV:
    fprintf(port->port->fh, "%s", p->s);
    break;
  case VEC: {
    size_t len = p->v->len;
    ObjPtr *v = p->v->v;
    fprintf(port->port->fh, "#(");
    if (len != 0) {
      cdisplay(v[0], port);
      for (size_t i = 1; i < len; i++) {
        fprintf(port->port->fh, " ");
        cdisplay(v[i], port);
      }
    }
    fprintf(port->port->fh, ")");
    break;
  }
  }
}
static ObjPtr primitive_procedures = NULL;
ObjPtr primitive_procedure_names(ObjPtr p) {
  if (p == empty_ptr) {
    return empty_ptr;
  }
  return pnew(p->p->l->p->l, primitive_procedure_names(p->p->r));
}
ObjPtr primitive_procedure_objects(ObjPtr p) {
  if (p == empty_ptr) {
    return empty_ptr;
  }
  return pnew(p->p->l->p->r, primitive_procedure_objects(p->p->r));
}
ObjPtr setup_environment() {
  ObjPtr initial_env =
      extend_environment(primitive_procedure_names(primitive_procedures),
                         primitive_procedure_objects(primitive_procedures),
                         the_empty_environment_ptr);
  define_variable(symnew("apply"), apply_ptr, initial_env);
  return initial_env;
}
ObjPtr cprocnew(Ptr entry, ObjPtr env) {
  ObjPtr p = onew(CONT);
  p->ptr = entry;
  return cpnew(CPROC, p, env);
}
ObjPtr compiled_procedure_env(ObjPtr p) { return p->p->r; }
ObjPtr compiled_procedure_entry(ObjPtr p) { return p->p->l; }

ObjPtr scm_current_error_port(ObjPtr argl) {
  if (argl != empty_ptr) {
    return num_err("current-error-port", argl);
  }
  return cur_eport;
}
ObjPtr scm_current_input_port(ObjPtr argl) {
  if (argl != empty_ptr) {
    return num_err("current-input-port", argl);
  }
  return cur_iport;
}
ObjPtr scm_current_output_port(ObjPtr argl) {
  if (argl != empty_ptr) {
    return num_err("current-output-port", argl);
  }
  return cur_oport;
}
ObjPtr scm_flush_output_port(ObjPtr argl) {
  size_t len = clength(argl);
  if (len == 0) {
    fflush(cur_oport->port->fh);
  } else if (len == 1) {
    ObjPtr p = argl->p->l;
    if (err_p(p)) {
      return p;
    }
    if (p->t == OPORT) {
      fflush(p->port->fh);
    } else {
      return domain_err("flush-output-port", argl);
    }
  } else {
    return num_err("flush-output-port", argl);
  }
  return undef_ptr;
}
ObjPtr scm_textual_port_p(ObjPtr argl) {
  if (clength(argl) != 1) {
    return num_err("textual-port?", argl);
  }
  switch (argl->p->l->t) {
  case IPORT:
  case OPORT:
  case IPORT_CLOSED:
  case OPORT_CLOSED:
    return true_ptr;
  default:
    return false_ptr;
  }
}
ObjPtr scm_binary_port_p(ObjPtr argl) {
  if (clength(argl) != 1) {
    return num_err("binary-port?", argl);
  }
  switch (argl->p->l->t) {
  case IBPORT:
  case OBPORT:
  case IBPORT_CLOSED:
  case OBPORT_CLOSED:
    return true_ptr;
  default:
    return false_ptr;
  }
}

ObjPtr scm_write(ObjPtr argl) {
  ObjPtr p = NULL;
  ObjPtr port = NULL;
  if (clength(argl) == 1) {
    p = argl->p->l;
    /* if (err_p(p)) { */
    /*   return p; */
    /* } */
    port = cur_oport;
  } else if (clength(argl) == 2) {
    p = argl->p->l;
    ObjPtr p0 = argl->p->r->p->l;
    if (err_p(p0)) {
      return p0;
    }
    if (p0->t != OPORT) {
      return domain_err("write", argl);
    }
    port = p0;
  } else {
    return num_err("write", argl);
  }
  cwrite(p, port);
  return undef_ptr;
}
ObjPtr scm_display(ObjPtr argl) {
  ObjPtr p = NULL;
  ObjPtr port = NULL;
  if (clength(argl) == 1) {
    p = argl->p->l;
    /* if (err_p(p)) { */
    /*   return p; */
    /* } */
    port = cur_oport;
  } else if (clength(argl) == 2) {
    p = argl->p->l;
    ObjPtr p0 = argl->p->r->p->l;
    if (err_p(p0)) {
      return p0;
    }
    if (p0->t != OPORT) {
      return domain_err("display", argl);
    }
    port = p0;
  } else {
    return num_err("display", argl);
  }
  cdisplay(p, port);
  return undef_ptr;
}
ObjPtr scm_read_char(ObjPtr argl) {
  size_t len = clength(argl);
  if (len == 0) {
    gunichar c = getuc(cur_iport->port->fh);
    return c == EOF ? eof_ptr : cnewuc(c);
  }
  if (len == 1) {
    ObjPtr p = argl->p->l;
    if (err_p(p)) {
      return p;
    }
    if (p->t == IPORT) {
      gunichar c = getuc(p->port->fh);
      return cnewuc(c);
    }
    return domain_err("read-char", argl);
  }
  return num_err("read-char", argl);
}
ObjPtr scm_peek_char(ObjPtr argl) {
  size_t len = clength(argl);
  if (len == 0) {
    gunichar c = getuc(cur_iport->port->fh);
    if (c == EOF) {
      return eof_ptr;
    }
    char outbuf[6];
    gint len = g_unichar_to_utf8(c, outbuf);
    for (size_t i = len; i > 0; i--) {
      ungetc(outbuf[i - 1], cur_iport->port->fh);
    }
    return cnewuc(c);
  }
  if (len == 1) {
    ObjPtr p = argl->p->l;
    if (err_p(p)) {
      return p;
    }
    if (p->t == IPORT) {
      gunichar c = getuc(p->port->fh);
      if (c == EOF) {
        return eof_ptr;
      }
      char outbuf[6];
      gint len = g_unichar_to_utf8(c, outbuf);
      for (gint i = len; i > 0; i--) {
        ungetc(outbuf[i - 1], p->port->fh);
      }
      return cnewuc(c);
    }
    return domain_err("peek-char", argl);
  }
  return num_err("peek-char", argl);
}

#include <errno.h>
#include <string.h>
ObjPtr scm_open_binary_input_file(ObjPtr argl) {
  size_t len = clength(argl);
  if (len != 1) {
    return num_err("open-binary-input-file", argl);
  }
  ObjPtr p = argl->p->l;
  if (err_p(p)) {
    return p;
  }
  if (p->t != STR && p->t != STREMPTY) {
    return domain_err("open-binary-input-file", argl);
  }
  char *filename = cscmstr_to_utf8(p);
  FILE *fh = fopen(filename, "rb");
  if (fh == NULL) {
    return fenew(utf8_to_scmstr(strerror(errno)), p);
  }
  return portnew(IBPORT, filename, fh);
}
ObjPtr scm_open_binary_output_file(ObjPtr argl) {
  size_t len = clength(argl);
  if (len != 1) {
    return num_err("open-binary-input-file", argl);
  }
  ObjPtr p = argl->p->l;
  if (err_p(p)) {
    return p;
  }
  if (p->t != STR && p->t != STREMPTY) {
    return domain_err("open-binary-input-file", argl);
  }
  char *filename = cscmstr_to_utf8(p);
  FILE *fh = fopen(filename, "wb");
  if (fh == NULL) {
    return fenew(utf8_to_scmstr(strerror(errno)), p);
  }
  return portnew(OBPORT, filename, fh);
}
ObjPtr scm_open_input_file(ObjPtr argl) {
  size_t len = clength(argl);
  if (len != 1) {
    return num_err("open-input-file", argl);
  }
  ObjPtr p = argl->p->l;
  if (err_p(p)) {
    return p;
  }
  if (p->t != STR && p->t != STREMPTY) {
    return domain_err("open-input-file", argl);
  }
  char *filename = cscmstr_to_utf8(p);
  FILE *fh = fopen(filename, "r");
  if (fh == NULL) {
    return fenew(utf8_to_scmstr(strerror(errno)), p);
  }
  return portnew(IPORT, filename, fh);
}
ObjPtr scm_open_output_file(ObjPtr argl) {
  size_t len = clength(argl);
  if (len != 1) {
    return num_err("open-input-file", argl);
  }
  ObjPtr p = argl->p->l;
  if (err_p(p)) {
    return p;
  }

  if (p->t != STR && p->t != STREMPTY) {
    return domain_err("open-input-file", argl);
  }
  char *filename = cscmstr_to_utf8(p);
  FILE *fh = fopen(filename, "w");
  if (fh == NULL) {
    return fenew(utf8_to_scmstr(strerror(errno)), p);
  }
  return portnew(OPORT, filename, fh);
}
ObjPtr scm_input_port_open_p(ObjPtr argl) {
  if (clength(argl) != 1) {
    return num_err("input-port-open?", argl);
  }
  ObjPtr p = argl->p->l;
  if (err_p(p)) {
    return p;
  }
  switch (p->t) {
  case IPORT:
    return true_ptr;
  case OPORT:
  case IPORT_CLOSED:
  case OPORT_CLOSED:
    return false_ptr;
  default:
    return domain_err("input-port-open?", argl);
  }
}
ObjPtr scm_input_port_p(ObjPtr argl) {
  if (clength(argl) != 1) {
    return num_err("input-port?", argl);
  }
  ObjPtr p = argl->p->l;
  if (err_p(p)) {
    return p;
  }
  switch (p->t) {
  case IPORT:
  case IPORT_CLOSED:
    return true_ptr;
  default:
    return false_ptr;
  }
}
ObjPtr scm_output_port_p(ObjPtr argl) {
  if (clength(argl) != 1) {
    return num_err("output-port?", argl);
  }
  ObjPtr p = argl->p->l;
  if (err_p(p)) {
    return p;
  }
  switch (p->t) {
  case OPORT:
  case OPORT_CLOSED:
    return true_ptr;
  default:
    return false_ptr;
  }
}
ObjPtr scm_output_port_open_p(ObjPtr argl) {
  if (clength(argl) != 1) {
    return num_err("output-port-open?", argl);
  }
  ObjPtr p = argl->p->l;
  if (err_p(p)) {
    return p;
  }
  switch (p->t) {
  case OPORT:
    return true_ptr;
  case IPORT:
  case IPORT_CLOSED:
  case OPORT_CLOSED:
    return false_ptr;
  default:
    return domain_err("output-port-open?", argl);
  }
}
ObjPtr scm_close_port(ObjPtr argl) {
  if (clength(argl) != 1) {
    return num_err("close-port", argl);
  }
  ObjPtr p = argl->p->l;
  if (err_p(p)) {
    return p;
  }
  switch (p->t) {
  case IPORT:
    fclose(p->port->fh);
    p->t = IPORT_CLOSED;
    return undef_ptr;
  case OPORT:
    fclose(p->port->fh);
    p->t = OPORT_CLOSED;
    return undef_ptr;
  default:
    return domain_err("close-port", argl);
  }
}
extern FILE *yyin;
extern void yyrestart(FILE *fh);
ObjPtr scm_read(ObjPtr argl) {
  size_t len = clength(argl);
  if (len == 0) {
    return cread();
  }
  if (len == 1) {
    ObjPtr p = argl->p->l;
    if (err_p(p)) {
      return p;
    }
    if (p->t == IPORT) {
      yyrestart(p->port->fh);
      ObjPtr out = cread();
      yyrestart(cur_iport->port->fh);
      return out;
    }
    return domain_err("read", argl);
  }
  return num_err("read", argl);
}
ObjPtr scm_eof_object(ObjPtr argl) {
  if (argl != empty_ptr) {
    return num_err("eof-object", argl);
  }
  return eof_ptr;
}

ObjPtr scm_eof_object_p(ObjPtr argl) {
  if (clength(argl) != 1) {
    return num_err("eof-object?", argl);
  }
  return argl->p->l == eof_ptr ? true_ptr : false_ptr;
}
/* system */
ObjPtr scm_delete_file(ObjPtr argl) {
  if (clength(argl) != 1) {
    return num_err("delete-file", argl);
  }
  ObjPtr p = argl->p->l;
  if (err_p(p)) {
    return p;
  }
  if (p->t != STR || p->t != STREMPTY) {
    return domain_err("delete-file", argl);
  }
  char *s = cscmstr_to_utf8(p);
  int n = remove(s);
  if (n == 0) {
    return undef_ptr;
  }
  ObjPtr out = utf8_to_scmstr(strerror(errno));
  return fenew(out, p);
}
ObjPtr scm_file_exists_p(ObjPtr argl) {
  if (clength(argl) != 1) {
    return num_err("file-exists?", argl);
  }
  ObjPtr p = argl->p->l;
  if (err_p(p)) {
    return p;
  }
  if (p->t != STR || p->t != STREMPTY) {
    return domain_err("file-exists?", argl);
  }
  char *s = cscmstr_to_utf8(p);
  return g_file_test(s, G_FILE_TEST_EXISTS) ? true_ptr : false_ptr;
}
ObjPtr scm_argv = NULL;
ObjPtr scm_command_line(ObjPtr argl) {
  if (argl != empty_ptr) {
    return num_err("command-line", argl);
  }
  return scm_argv;
}
ObjPtr scm_exit(ObjPtr argl) {
  size_t len = clength(argl);
  if (len == 0) {
    exit(0);
  }
  if (len == 1) {
    exit(1);
  }
  return num_err("exit", argl);
}

ObjPtr scm_system(ObjPtr argl) {
  if (clength(argl) != 1) {
    return num_err("system", argl);
  }
  ObjPtr p = argl->p->l;
  if (err_p(p)) {
    return p;
  }
  if (p->t != STR && p->t != STREMPTY) {
    return domain_err("system", argl);
  }
  char *s = cscmstr_to_utf8(p);
  int n = system(s);
  ObjPtr out = onew(RATIONAL);
  mpq_init(out->q);
  mpq_set_si(out->q, n, 1);
  return out;
}

/* inexact library */
ObjPtr scm_exp(ObjPtr argl) {
  if (clength(argl) != 1) {
    return num_err("exp", argl);
  }
  ObjPtr p = argl->p->l;
  if (err_p(p)) {
    return p;
  }
  switch (p->t) {
  case COMPLEX: {
    ObjPtr out = onew(COMPLEX);
    mpc_init2(out->z, prec);
    mpc_exp(out->z, p->z, MPC_RNDNN);
    return out;
  }
  case RATIONAL: {
    mpfr_set_q(opfr1, p->q, MPFR_RNDN);
    mpc_set_fr(opc1, opfr1, MPC_RNDNN);
    ObjPtr out = onew(COMPLEX);
    mpc_init2(out->z, prec);
    mpc_exp(out->z, opc1, MPC_RNDNN);
    return out;
  }
  default:
    return domain_err("exp", argl);
  }
}
ObjPtr scm_log(ObjPtr argl) {
  size_t len = clength(argl);
  if (len == 1) {
    ObjPtr p = argl->p->l;
    if (err_p(p)) {
      return p;
    }
    switch (p->t) {
    case COMPLEX: {
      ObjPtr out = onew(COMPLEX);
      mpc_init2(out->z, prec);
      mpc_log(out->z, p->z, MPC_RNDNN);
      return out;
    }
    case RATIONAL: {
      mpfr_set_q(opfr1, p->q, MPFR_RNDN);
      mpc_set_fr(opc1, opfr1, MPC_RNDNN);
      ObjPtr out = onew(COMPLEX);
      mpc_init2(out->z, prec);
      mpc_log(out->z, opc1, MPC_RNDNN);
      return out;
    }
    default:
      return domain_err("log", argl);
    }
  }
  if (len == 2) {
  }
  return num_err("log", argl);
}
static void *allocate_function(size_t alloc_size) {
  return GC_MALLOC(alloc_size);
}
static void *realloc_func(void *ptr, size_t old_size, size_t new_size) {
  return GC_REALLOC(ptr, new_size);
}
static void free_function(void *ptr, size_t size) { /* GC_FREE(ptr); */
}
void init() {
  GC_INIT();

  mp_set_memory_functions(allocate_function, realloc_func, free_function);
  mpq_init(opq1);
  mpf_init(opf1);
  mpfr_init(opfr1);
  mpc_init2(opc1, prec);
  mpq_init(qzero);
  mpq_set_ui(qzero, 0, 1);

  symtab = g_hash_table_new(NULL, NULL);
  chunk = g_string_chunk_new(1024);
  quote_ptr = symnew("quote");

  stack = empty_ptr;
  Proc procs[] = {{"*", scm_mul},
                  {"+", scm_add},
                  {"=", scm_math_equal},
                  {"/", scm_div},
                  {"<", scm_lt},
                  {"binary-port?", scm_binary_port_p},
                  {"boolean?", scm_boolean_p},
                  {"car", scm_car},
                  {"cdr", scm_cdr},
                  {"ceiling", scm_ceiling},
                  {"char?", scm_char_p},
                  {"char->integer", scm_char_to_integer},
                  {"close-port", scm_close_port},
                  {"command-line", scm_command_line},
                  {"cons", scm_cons},
                  {"current-error-port", scm_current_error_port},
                  {"current-input-port", scm_current_input_port},
                  {"current-output-port", scm_current_output_port},
                  {"denominator", scm_denominator},
                  {"display", scm_display},
                  {"eof-object", scm_eof_object},
                  {"eof-object?", scm_eof_object_p},
                  {"eq?", scm_eq_p},
                  {"eqv?", scm_eqv_p},
                  {"error", scm_error},
                  {"error-object-irritants", scm_error_object_irritants},
                  {"error-object-message", scm_error_object_message},
                  {"error-object?", scm_error_object_p},
                  {"exact", scm_exact},
                  {"exact?", scm_exact_p},
                  {"file-error?", scm_file_error_p},
                  {"floor", scm_floor},
                  {"flush-output-port", scm_flush_output_port},
                  {"input-port-open?", scm_input_port_open_p},
                  {"input-port?", scm_input_port_p},
                  {"integer->char", scm_integer_to_char},
                  {"list->string", scm_list_to_string},
                  {"list->vector", scm_list_to_vector},
                  {"null?", scm_null_p},
                  {"number?", scm_number_p},
                  {"number->string", scm_number_to_string},
                  {"numerator", scm_numerator},
                  {"output-port-open?", scm_output_port_open_p},
                  {"output-port?", scm_output_port_p},
                  {"pair?", scm_pair_p},
                  {"peek-char", scm_peek_char},
                  {"procedure?", scm_procedure_p},
                  {"raise", scm_raise},
                  {"read-char", scm_read_char},
                  {"read-error?", scm_read_error_p},
                  {"round", scm_round},
                  {"set-car!", scm_set_car},
                  {"set-cdr!", scm_set_cdr},
                  {"string->list", scm_string_to_list},
                  {"string->symbol", scm_string_to_symbol},
                  {"string-set!", scm_string_set},
                  {"string?", scm_string_p},
                  {"symbol->string", scm_symbol_to_string},
                  {"symbol?", scm_symbol_p},
                  {"textual-port?", scm_textual_port_p},
                  {"truncate", scm_truncate},
                  {"vector->list", scm_vector_to_list},
                  {"vector-length", scm_vector_length},
                  {"vector-ref", scm_vector_ref},
                  {"vector-set!", scm_vector_set},
                  {"vector?", scm_vector_p},

                  /* case-lambda */

                  /* char library */
                  {"char-alphabetic?", scm_char_alphabetic_p},
                  {"char-downcase", scm_char_downcase},
                  {"char-foldcase", scm_char_foldcase},
                  {"char-lower-case?", scm_char_lower_case_p},
                  {"char-numeric?", scm_char_numeric_p},
                  {"char-upcase", scm_char_upcase},
                  {"char-upper-case?", scm_char_upper_case_p},
                  {"char-whitespace?", scm_char_whitespace_p},
                  {"digit-value", scm_digit_value},

                  /* complex library */
                  {"angle", scm_angle},
                  {"imag-part", scm_imag_part},
                  {"real-part", scm_real_part},

                  /* file library */
                  {"delete-file", scm_delete_file},
                  {"file-exists?", scm_file_exists_p},
                  {"open-binary-input-file", scm_open_binary_input_file},
                  {"open-binary-output-file", scm_open_binary_output_file},
                  {"open-input-file", scm_open_input_file},
                  {"open-output-file", scm_open_output_file},

                  /* inexact library */
                  {"exp", scm_exp},
                  {"infinite?", scm_infinite_p},
                  {"log", scm_log},
                  {"nan?", scm_nan_p},

                  {"read", scm_read},
                  {"system", scm_system},
                  {"write", scm_write},
                  {"exit", scm_exit},
                  {NULL, NULL}};

  primitive_procedures = empty_ptr;
  for (size_t i = 0; procs[i].name != NULL; i++) {
    ObjPtr p = pnew(symnew(procs[i].name), procnew(procs[i].name, procs[i].fn));
    primitive_procedures = pnew(p, primitive_procedures);
  }
  the_empty_environment_ptr = empty_ptr;

  iport = portnew(IPORT, "stdin", stdin);
  oport = portnew(OPORT, "stdout", stdout);
  eport = portnew(OPORT, "stderr", stderr);
  cur_iport = portnew(IPORT, "stdin", stdin);
  cur_oport = portnew(OPORT, "stdout", stdout);
  cur_eport = portnew(OPORT, "stderr", stderr);
}
