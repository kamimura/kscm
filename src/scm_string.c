#include "scm_string.h"

Object string_cons(Object o1, Object o2) {
  if (o1.type != CHAR) {
    fprintf(stderr, "%s: %s: %d\n", __FILE__, __FUNCTION__, __LINE__);
    exit(1);
  }
  if (o2.type != STRING && o2.type != STRING_EMPTY) {
    fprintf(stderr, "%s: %s: %d\n", __FILE__, __FUNCTION__, __LINE__);
    exit(1);
  }
  Object o = cons(o1, o2);
  o.type = STRING;
  return o;
}

static bool eqv_p(Object o1, Object o2) { return o1.index == o2.index; }

static Object make_string(Object args) {
  Object k = carref(args);
  Object c = carref(cdrref(args));
  size_t m = mpz_get_ui(mpq_numref(k.rational));
  Object o = (Object){.type = STRING_EMPTY};
  for (size_t i = 0; i < m; i++) {
    o = string_cons(c, o);
  }
  return o;
}
static Object length(Object args) {
  Object o = carref(args);
  size_t i = 0;
  for (; o.type != STRING_EMPTY; o = cdrref(o)) {
    i++;
  }
  Object out = {.type = RATIONAL};
  mpq_init(out.rational);
  mpq_set_ui(out.rational, i, 1);
  return out;
}
static Object string_ref(Object args) {
  Object s = carref(args);
  if (s.type == STRING_EMPTY) {
    fprintf(stderr, "%s: STRING_EMPTY\n", __FUNCTION__);
    exit(1);
  }
  if (s.type != STRING) {
    fprintf(stderr, "%s: STRING\n", __FUNCTION__);
    object_write_stdout(s);
    puts("");
    exit(1);
  }
  Object k = carref(cdrref(args));
  size_t n = mpz_get_ui(mpq_numref(k.rational));
  for (size_t i = 0; i < n; i++) {
    s = cdrref(s);
  }
  if (carref(s).type != CHAR) {
    fprintf(stderr, "%s: CHAR:\n", __FUNCTION__);
    fprintf(stderr, "type: %d\n", carref(s).type);
    object_writeln_stdout(carref(s));
    fprintf(stderr, "type: %d\n", s.type);
    object_writeln_stdout(s);
    object_writeln_stdout(args);
    puts("");
    exit(1);
  }
  return carref(s);
}
static Object string_set(Object args) {
  Object s = carref(args);
  Object k = carref(cdrref(args));
  Object c = carref(cdrref(cdrref(args)));

  size_t n = mpz_get_ui(mpq_numref(k.rational));
  Object o = s;
  for (size_t i = 0; i < n; i++) {
    o = cdrref(o);
  }
  set_car(o, c);
  return undef;
}
static void write(Object o, FILE *s) {
  fprintf(s, "\"");
  for (Object o0 = o; o0.type != STRING_EMPTY; o0 = cdrref(o0)) {
    gunichar ch = carref(o0).ch;
    if (ch == 0x07) {
      fprintf(s, "\\a");
    } else if (ch == 0x08) {
      fprintf(s, "\\b");
    } else if (ch == 0x0a) {
      fprintf(s, "\\n");
    } else if (ch == 0x0d) {
      fprintf(s, "\\r");
    } else if (ch == 0x09) {
      fprintf(s, "\\t");
    } else if (ch == 0x22) {
      fprintf(s, "\\\"");
    } else if (g_unichar_isprint(ch)) {
      char outbuf[7];
      int len = g_unichar_to_utf8(ch, outbuf);
      outbuf[len] = '\0';
      fprintf(s, "%s", outbuf);
    } else {
      fprintf(s, "\\x%04x;", ch);
    }
  }
  fprintf(s, "\"");
}
static void empty_write(Object o, FILE *s) { fprintf(s, "\"\""); }
static void display(Object o, FILE *s) {
  for (Object o0 = o; o0.type != STRING_EMPTY; o0 = cdrref(o0)) {
    gunichar ch = carref(o0).ch;
    char outbuf[7];
    int len = g_unichar_to_utf8(ch, outbuf);
    outbuf[len] = '\0';
    fprintf(s, "%s", outbuf);
  }
}
static void empty_display(Object o, FILE *s) { fprintf(s, ""); }

/* for compiler */
static Object c_list_to_string(Object args) {
  Object o = empty;
  for (argl = carref(argl); argl.type != EMPTY; argl = cdrref(argl)) {
    o = cons(carref(argl), o);
  }
  argl = o;
  o = (Object){.type = STRING_EMPTY};
  for (; argl.type != EMPTY; argl = cdrref(argl)) {
    o = string_cons(carref(argl), o);
  }
  return o;
}
static Object c_string_to_list(Object args) {
  Object o = empty;
  for (argl = carref(argl); argl.type != STRING_EMPTY; argl = cdrref(argl)) {
    o = cons(carref(argl), o);
  }
  argl = o;
  o = empty;
  for (; argl.type != EMPTY; argl = cdrref(argl)) {
    o = cons(carref(argl), o);
  }
  return o;
}
#include "env.h"    // def_var_val
#include "symbol.h" // symbol_new
void string_init() {
  fn_obj_of_obj bool_of_obj_obj_ks[] = {object_eqv_p, object_eq_p, NULL};
  fn_bool_of_obj_obj bool_of_obj_obj_vs[] = {eqv_p, eqv_p, NULL};
  for (size_t i = 0; bool_of_obj_obj_ks[i] != NULL; i++) {
    put_bool_of_obj_obj(bool_of_obj_obj_ks[i], STRING, STRING,
                        bool_of_obj_obj_vs[i]);
  }
  fn_obj_of_obj of_obj_file_ks[] = {object_write, object_display, NULL};
  fn_of_obj_file of_obj_file_vs[] = {write, display, NULL};
  for (size_t i = 0; of_obj_file_ks[i] != NULL; i++) {
    put_of_obj_file(of_obj_file_ks[i], STRING, of_obj_file_vs[i]);
  }

  fn_obj_of_obj of_obj_file_ks1[] = {object_write, object_display, NULL};
  fn_of_obj_file of_obj_file_vs1[] = {empty_write, empty_display, NULL};
  for (size_t i = 0; of_obj_file_ks1[i] != NULL; i++) {
    put_of_obj_file(of_obj_file_ks1[i], STRING_EMPTY, of_obj_file_vs1[i]);
  }

  char const *names[] = {"make-string", "string-length",  "string-ref",
                         "string-set!", "c-list->string", "c-string->list",
                         NULL};
  fn_obj_of_obj procs[] = {make_string, length,           string_ref,
                           string_set,  c_list_to_string, c_string_to_list,
                           NULL};
  for (size_t i = 0; names[i] != NULL; i++) {
    val = (Object){.type = PROC, .proc = procs[i]};
    def_var_val(symbol_new(names[i]));
  }
}

Object symbol_to_string(Object args) {
  Object o = carref(args);
  glong items_written = 0;
  gunichar *s = g_utf8_to_ucs4(o.symbol, -1, NULL, &items_written, NULL);
  Object out = (Object){.type = STRING_EMPTY};
  for (size_t i = items_written; i != 0; i--) {
    out = string_cons((Object){.type = CHAR, .ch = s[i - 1]}, out);
  }
  g_free(s);
  return out;
}
