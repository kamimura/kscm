#include "pair.h"

static bool eqv_p(Object o1, Object o2) { return o1.index == o2.index; }

static Object c_cons(Object args) {
  Object o = cons(car(argl), car(cdrref(argl)));
  o.type = PAIR;
  return o;
}
static Object pair_cons(Object args) {
  check_argl_length("cons", 2);
  Object o = cons(car(args), car(cdrref(argl)));
  o.type = PAIR;
  return o;
}
static Object apply_obj_of_obj(fn_obj_of_obj fn, char const *s) {
  check_argl_length(s, 1);
  check_argl_type(s, carref(argl), PAIR);
  return fn(carref(argl));
}
static Object pair_car(Object args) { return apply_obj_of_obj(car, "car"); }
static Object pair_cdr(Object args) { return apply_obj_of_obj(cdr, "cdr"); }
static Object apply_of_obj_obj(fn_of_obj_obj fn, Object args) {
  Object o1 = carref(args);
  Object o2 = car(cdrref(args));
  fn(o1, o2);
  return undef;
}
static Object length(Object args) {
  Object o = carref(args);
  size_t len = 0;
  for (; o.type != EMPTY; len++) {
    o = cdrref(o);
  }
  Object out = {.type = RATIONAL};
  mpq_init(out.rational);
  mpz_set_ui(mpq_numref(out.rational), len);
  mpz_set_ui(mpq_denref(out.rational), 1);
  return out;
}
static Object list(Object args) { return args; }
static Object pair_set_car(Object args) {
  return apply_of_obj_obj(set_car, args);
}
static Object pair_set_cdr(Object args) {
  return apply_of_obj_obj(set_cdr, args);
}
static Object index(Object args) {
  Object out = {.type = RATIONAL};
  mpq_init(out.rational);
  mpq_set_ui(out.rational, carref(args).index, 1);
  return out;
}
/* for compiler */
static Object c_cadr(Object args) {
  Object o = carref(args);
  return car(cdrref(o));
}
static Object c_cddr(Object args) {
  Object o = carref(args);
  return cdr(cdrref(o));
}
static Object c_caddr(Object args) {
  Object o = carref(args);
  return car(cdrref(cdrref(o)));
}
static Object c_cdddr(Object args) {
  Object o = carref(args);
  return cdr(cdrref(cdrref(o)));
}
static Object c_caadr(Object args) {
  Object o = carref(args);
  return car(carref(cdrref(o)));
}
static Object c_cdadr(Object args) {
  Object o = carref(args);
  return cdr(carref(cdrref(o)));
}
static Object c_cadddr(Object args) {
  Object o = carref(args);
  return car(cdrref(cdrref(cdrref(o))));
}
static Object c_reverse(Object args) {
  Object o = empty;
  for (argl = carref(argl); argl.type != EMPTY; argl = cdrref(argl)) {
    o = cons(car(argl), o);
  }
  return o;
}
static Object c_append(Object args) {
  Object o = empty;
  for (; argl.type != EMPTY; argl = cdrref(argl)) {
    Object t = carref(argl);
    for (; t.type != EMPTY; t = cdrref(t)) {
      o = cons(car(t), o);
    }
  }
  argl = o;
  o = empty;
  for (; argl.type != EMPTY; argl = cdrref(argl)) {
    o = cons(car(argl), o);
  }
  return o;
}
static Object c_car(Object args) { return car(carref(argl)); }
static Object c_cdr(Object args) { return cdr(carref(argl)); }
#include "env.h"    // def_var_val
#include "symbol.h" // symbol_new
void pair_init() {
  fn_obj_of_obj ks1[] = {object_eqv_p, object_eq_p, NULL};
  fn_bool_of_obj_obj vs1[] = {eqv_p, eqv_p, NULL};
  for (size_t i = 0; ks1[i] != NULL; i++) {
    put_bool_of_obj_obj(ks1[i], PAIR, PAIR, vs1[i]);
  }

  char const *names[] = {
      "cons",     "car",       "cdr",      "list",    "c-index", "set-car!",
      "set-cdr!", "length",    "c-cons",   "c-car",   "c-cdr",   "c-length",
      "c-cadr",   "c-cddr",    "c-caddr",  "c-caadr", "c-cdadr", "c-cdddr",
      "c-cadddr", "c-reverse", "c-append", NULL};
  fn_obj_of_obj procs[] = {
      pair_cons,    pair_car,  pair_cdr, list,    index,   pair_set_car,
      pair_set_cdr, length,    c_cons,   c_car,   c_cdr,   length,
      c_cadr,       c_cddr,    c_caddr,  c_caadr, c_cdadr, c_cdddr,
      c_cadddr,     c_reverse, c_append, NULL};
  for (size_t i = 0; names[i] != NULL; i++) {
    val = (Object){.type = PROC, .proc = procs[i]};
    def_var_val(symbol_new(names[i]));
  }
}
