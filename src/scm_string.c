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
  size_t k = mpz_get_ui(mpq_numref(carref(argl).rational));
  argl = carref(cdrref(argl));
  Object out = (Object){.type = STRING_EMPTY};
  for (size_t i = 0; i < k; i++) {
    out = string_cons(argl, out);
  }
  return out;
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

static Object list_to_string(Object args) {
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
static Object string_to_list(Object args) {
  size_t start = mpz_get_ui(mpq_numref(carref(cdrref(argl)).rational));
  size_t end = mpz_get_ui(mpq_numref(carref(cdrref(cdrref(argl))).rational));
  Object o = empty;
  size_t i = 0;
  for (argl = carref(argl); i != end; argl = cdrref(argl)) {
    if (start <= i) {
      o = cons(carref(argl), o);
    }
    i++;
  }
  argl = o;
  o = empty;
  for (; argl.type != EMPTY; argl = cdrref(argl)) {
    o = cons(carref(argl), o);
  }
  return o;
}
static Object string_length(Object args) {
  size_t len = 0;
  for (Object o = carref(argl); o.type != STRING_EMPTY; o = cdrref(o)) {
    len++;
  }
  Object out = {.type = RATIONAL};
  mpq_init(out.rational);
  mpq_set_ui(out.rational, len, 1);
  return out;
}
static Object string_to_number(Object args) {
  size_t radix = mpz_get_ui(mpq_numref(carref(cdrref(argl)).rational));
  Object o = carref(argl);
  if (o.type != STRING_EMPTY && carref(o).ch == '#' &&
      cdrref(o).type != STRING_EMPTY) {
    gunichar ch = carref(cdrref(o)).ch;
    if (ch == 'b' || ch == 'B') {
      radix = 2;
      o = cdrref(cdrref(o));
    } else if (ch == 'o' || ch == 'O') {
      radix = 8;
      o = cdrref(cdrref(o));
    } else if (ch == 'd' || ch == 'D') {
      radix = 10;
      o = cdrref(cdrref(o));
    } else if (ch == 'x' || ch == 'X') {
      radix = 16;
      o = cdrref(cdrref(o));
    }
  }
  size_t len = 0;
  for (; o.type != STRING_EMPTY; o = cdrref(o)) {
    len++;
  }
  if (radix != 10) {
    len += 2;
  }
  gunichar str[len];
  size_t i = 0;
  if (radix == 2) {
    str[i] = '#';
    i++;
    str[i] = 'b';
    i++;
  } else if (radix == 8) {
    str[i] = '#';
    i++;
    str[i] = 'o';
    i++;
  } else if (radix == 16) {
    str[i] = '#';
    i++;
    str[i] = 'x';
    i++;
  }
  for (Object o = carref(argl); o.type != STRING_EMPTY; o = cdrref(o)) {
    str[i] = carref(o).ch;
    i++;
  }
  gchar *s = g_ucs4_to_utf8(str, len, NULL, NULL, NULL);
  Object out = c_str_to_datum(s);
  g_free(s);
  if (out.type == COMPLEX || out.type == RATIONAL) {
    return out;
  }
  object_free(&out);
  return boolean_false;
}
static Object string_to_symbol(Object args) {
  size_t len = 0;
  for (Object o = carref(argl); o.type != STRING_EMPTY; o = cdrref(o)) {
    len++;
  }
  gunichar str[len];
  size_t i = 0;
  for (Object o = carref(argl); o.type != STRING_EMPTY; o = cdrref(o)) {
    str[i] = carref(o).ch;
    i++;
  }
  gchar *s = g_ucs4_to_utf8(str, len, NULL, NULL, NULL);
  Object out = symbol_new(s);
  out.type = SYMBOL_VERTICAL;
  g_free(s);
  return out;
}
static Object string_to_utf8(Object args) {
  size_t start = mpz_get_ui(mpq_numref(carref(cdrref(argl)).rational));
  size_t end = mpz_get_ui(mpq_numref(carref(cdrref(cdrref(argl))).rational));
  size_t len = end - start;
  gunichar str[len];
  size_t i = 0;
  size_t j = 0;
  for (Object o = carref(argl); j != end; o = cdrref(o)) {
    if (start <= j) {
      str[i] = carref(o).ch;
      i++;
    }
    j++;
  }
  glong items_written;
  uint8_t *bytes =
      (uint8_t *)g_ucs4_to_utf8(str, len, NULL, &items_written, NULL);
  Object out = cons((Object){.type = BYTEVECTOR_LENGTH, .len = items_written},
                    (Object){.type = BYTES, .bytes = bytes});
  out.type = BYTEVECTOR;
  return out;
}
static Object string_ref(Object args) {
  Object o = carref(argl);
  size_t k = mpz_get_ui(mpq_numref(carref(cdrref(argl)).rational));
  for (size_t i = 0; i < k; i++) {
    o = cdrref(o);
  }
  return carref(o);
}
static Object string_set(Object args) {
  Object s = carref(argl);
  size_t k = mpz_get_ui(mpq_numref(carref(cdrref(argl)).rational));
  Object c = carref(cdrref(cdrref(argl)));
  Object o = s;
  for (size_t i = 0; i < k; i++) {
    o = cdrref(o);
  }
  set_car(o, c);
  return undef;
}
static Object le_p(Object args) {
  Object s1 = carref(argl);
  Object s2 = carref(cdrref(argl));
  for (;;) {
    if (s1.type == STRING_EMPTY) {
      return boolean_true;
    }
    if (s2.type == STRING_EMPTY) {
      return boolean_false;
    }
    if (carref(s1).ch < carref(s2).ch) {
      return boolean_true;
    }
    if (carref(s1).ch == carref(s2).ch) {
      s1 = cdrref(s1);
      s2 = cdrref(s2);
    } else {
      return boolean_false;
    }
  }
}
static Object lt_p(Object args) {
  Object s1 = carref(argl);
  Object s2 = carref(cdrref(argl));
  for (;;) {
    if (s1.type == STRING_EMPTY && s2.type == STRING_EMPTY) {
      return boolean_false;
    }
    if (s1.type == STRING_EMPTY) {
      return boolean_true;
    }
    if (s2.type == STRING_EMPTY) {
      return boolean_false;
    }
    if (carref(s1).ch < carref(s2).ch) {
      return boolean_true;
    }
    if (carref(s1).ch == carref(s2).ch) {
      s1 = cdrref(s1);
      s2 = cdrref(s2);
    } else {
      return boolean_false;
    }
  }
}
static Object math_equal_p(Object args) {
  Object s1 = carref(argl);
  Object s2 = carref(cdrref(argl));
  for (;;) {
    if (s1.type == STRING_EMPTY && s2.type == STRING_EMPTY) {
      return boolean_true;
    }
    if (s1.type == STRING_EMPTY || s2.type != STRING_EMPTY) {
      return boolean_false;
    }
    if (s2.type == STRING_EMPTY) {
      return boolean_false;
    }
    if (carref(s1).ch == carref(s2).ch) {
      s1 = cdrref(s1);
      s2 = cdrref(s2);
    } else {
      return boolean_false;
    }
  }
}
static Object ge_p(Object args) {
  Object s1 = carref(argl);
  Object s2 = carref(cdrref(argl));
  for (;;) {
    if (s2.type == STRING_EMPTY) {
      return boolean_true;
    }
    if (s1.type == STRING_EMPTY) {
      return boolean_false;
    }
    if (carref(s1).ch > carref(s2).ch) {
      return boolean_true;
    }
    if (carref(s1).ch == carref(s2).ch) {
      s1 = cdrref(s1);
      s2 = cdrref(s2);
    } else {
      return boolean_false;
    }
  }
}
static Object gt_p(Object args) {
  Object s1 = carref(argl);
  Object s2 = carref(cdrref(argl));
  if (s1.type == STRING_EMPTY && s2.type == STRING_EMPTY) {
    return boolean_false;
  }
  for (;;) {
    if (s1.type == STRING_EMPTY && s2.type == STRING_EMPTY) {
      return boolean_false;
    }
    if (s2.type == STRING_EMPTY) {
      return boolean_true;
    }
    if (s1.type == STRING_EMPTY) {
      return boolean_false;
    }
    if (carref(s1).ch > carref(s2).ch) {
      return boolean_true;
    }
    if (carref(s1).ch == carref(s2).ch) {
      s1 = cdrref(s1);
      s2 = cdrref(s2);
    } else {
      return boolean_false;
    }
  }
}
static Object write_string(Object args) {
  Object s = carref(argl);
  FILE *port = carref(cdrref(argl)).port;
  size_t start = mpz_get_ui(mpq_numref(carref(cdrref(cdrref(argl))).rational));
  size_t end =
      mpz_get_ui(mpq_numref(carref(cdrref(cdrref(cdrref(argl)))).rational));
  for (size_t i = 0; i < start; i++) {
    s = cdrref(s);
  }
  for (size_t i = start; i < end; i++) {
    gunichar c = carref(s).ch;
    char outbuf[7];
    gint len = g_unichar_to_utf8(c, outbuf);
    outbuf[len] = '\0';
    fprintf(port, "%s", outbuf);
    s = cdrref(s);
  }
  return undef;
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

  char const *names[] = {"make-string",      "string-length",
                         "string-ref",       "string-set!",
                         "c-list->string",   "c-make-string",
                         "c-string->list",   "c-string->number",
                         "c-string->symbol", "c-string->utf8",
                         "c-string-length",  "c-string-ref",
                         "c-string-set!",    "c-string<=?",
                         "c-string<?",       "c-string=?",
                         "c-string>=?",      "c-string>?",
                         "c-write-string",   NULL};
  fn_obj_of_obj procs[] = {make_string,
                           length,
                           string_ref,
                           string_set,
                           list_to_string,
                           make_string,
                           string_to_list,
                           string_to_number,
                           string_to_symbol,
                           string_to_utf8,
                           string_length,
                           string_ref,
                           string_set,
                           le_p,
                           lt_p,
                           math_equal_p,
                           ge_p,
                           gt_p,
                           write_string,
                           NULL};
  for (size_t i = 0; names[i] != NULL; i++) {
    val = (Object){.type = PROC, .proc = procs[i]};
    def_var_val(symbol_new(names[i]));
  }
}
