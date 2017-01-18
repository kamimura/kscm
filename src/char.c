#include "char.h"

Object char_new(char const *s) {
  return (Object){.type = CHAR, .ch = g_utf8_get_char(s)};
}
static bool eqv_p(Object o1, Object o2) { return o1.ch == o2.ch; }
static void write(Object o, FILE *s) {
  gunichar ch = o.ch;
  fprintf(s, "#\\");
  if (ch == 0x07) {
    fprintf(s, "alarm");
  } else if (ch == 0x08) {
    fprintf(s, "backspace");
  } else if (ch == 0x7f) {
    fprintf(s, "delete");
  } else if (ch == 0x1b) {
    fprintf(s, "escape");
  } else if (ch == 0x0a) {
    fprintf(s, "newline");
  } else if (ch == 0x00) {
    fprintf(s, "null");
  } else if (ch == 0x0d) {
    fprintf(s, "return");
  } else if (ch == 0x20) {
    fprintf(s, "space");
  } else if (ch == 0x09) {
    fprintf(s, "tab");
  } else if (g_unichar_isgraph(ch)) {
    char outbuf[7];
    int len = g_unichar_to_utf8(ch, outbuf);
    outbuf[len] = '\0';
    fprintf(s, "%s", outbuf);
  } else {
    fprintf(s, "x%x", ch);
  }
}
static void display(Object o, FILE *s) {
  gunichar ch = o.ch;
  char outbuf[7];
  int len = g_unichar_to_utf8(ch, outbuf);
  outbuf[len] = '\0';
  fprintf(s, "%s", outbuf);
}

static Object apply_bool_of_ch(gboolean (*fn)(gunichar), Object args) {
  return fn(carref(argl).ch) ? boolean_true : boolean_false;
}
static Object upper_case_p(Object args) {
  return apply_bool_of_ch(g_unichar_isupper, args);
}
static Object integer_to_char(Object args) {
  Object o = carref(args);
  gunichar ch = mpz_get_ui(mpq_numref(o.rational));
  return (Object){.type = CHAR, .ch = ch};
}
static Object apply_char_of_char(gunichar (*fn)(gunichar), Object args) {
  gunichar ch = fn(carref(args).ch);
  return (Object){.type = CHAR, .ch = ch};
}
static Object to_integer(Object args) {
  Object out = {.type = RATIONAL};
  mpq_init(out.rational);
  mpq_set_ui(out.rational, carref(argl).ch, 1);
  return out;
}
static Object le_p(Object args) {
  return carref(argl).ch <= carref(cdrref(argl)).ch ? boolean_true
                                                    : boolean_false;
}
static Object lt_p(Object args) {
  return carref(argl).ch < carref(cdrref(argl)).ch ? boolean_true
                                                   : boolean_false;
}
static Object math_equal_p(Object args) {
  return carref(argl).ch == carref(cdrref(argl)).ch ? boolean_true
                                                    : boolean_false;
}
static Object ge_p(Object args) {
  return carref(argl).ch >= carref(cdrref(argl)).ch ? boolean_true
                                                    : boolean_false;
}
static Object gt_p(Object args) {
  return carref(argl).ch > carref(cdrref(argl)).ch ? boolean_true
                                                   : boolean_false;
}
static Object write_char(Object args) {
  gunichar c = carref(argl).ch;
  FILE *port = carref(cdrref(argl)).port;
  char outbuf[7];
  gint len = g_unichar_to_utf8(c, outbuf);
  outbuf[len] = '\0';
  fprintf(port, "%s", outbuf);
  return undef;
}
static Object alphabetic_p(Object args) {
  return apply_bool_of_ch(g_unichar_isalpha, args);
}
#include <string.h> // strcmp
static gint casefold_cmp() {
  gunichar c1 = carref(argl).ch;
  gunichar c2 = carref(cdrref(argl)).ch;
  char outbuf1[7];
  char outbuf2[7];
  gint len1 = g_unichar_to_utf8(c1, outbuf1);
  gint len2 = g_unichar_to_utf8(c2, outbuf2);
  outbuf1[len1] = '\0';
  outbuf2[len2] = '\0';
  gchar *s1 = g_utf8_casefold(outbuf1, len1);
  gchar *s2 = g_utf8_casefold(outbuf2, len2);
  gint n = strcmp(s1, s2);
  g_free(s1);
  g_free(s2);
  return n;
}
static Object ci_le_p(Object args) {
  gint n = casefold_cmp();
  return n <= 0 ? boolean_true : boolean_false;
}
static Object ci_lt_p(Object args) {
  gint n = casefold_cmp();
  return n < 0 ? boolean_true : boolean_false;
}
static Object ci_eq_p(Object args) {
  gint n = casefold_cmp();
  return n == 0 ? boolean_true : boolean_false;
}
static Object ci_ge_p(Object args) {
  gint n = casefold_cmp();
  return n >= 0 ? boolean_true : boolean_false;
}
static Object ci_gt_p(Object args) {
  gint n = casefold_cmp();
  return n > 0 ? boolean_true : boolean_false;
}
static Object downcase(Object args) {
  return apply_char_of_char(g_unichar_tolower, args);
}
static Object foldcase(Object args) {
  gunichar c = carref(argl).ch;
  char outbuf[7];
  gint len = g_unichar_to_utf8(c, outbuf);
  gchar *s = g_utf8_casefold(outbuf, len);
  Object o = (Object){.type = CHAR, .ch = g_utf8_get_char(s)};
  g_free(s);
  return o;
}
static Object lower_case_p(Object args) {
  return apply_bool_of_ch(g_unichar_islower, args);
}
static Object numeric_p(Object args) {
  return apply_bool_of_ch(g_unichar_isalpha, args);
}
static Object upcase(Object args) {
  return apply_char_of_char(g_unichar_toupper, args);
}
static Object whitespace_p(Object args) {
  return apply_bool_of_ch(g_unichar_isspace, args);
}
static Object digit_value(Object args) {
  gunichar ch = carref(argl).ch;
  gint n = g_unichar_digit_value(ch);
  if (n == -1) {
    return boolean_false;
  }
  Object o = {.type = RATIONAL};
  mpq_init(o.rational);
  mpq_set_ui(o.rational, n, 1);
  return o;
}
#include "env.h"
#include "symbol.h"
void char_init() {
  fn_obj_of_obj ks1[] = {object_eqv_p, object_eq_p, NULL};
  fn_bool_of_obj_obj vs1[] = {eqv_p, eqv_p, NULL};
  for (size_t i = 0; ks1[i] != NULL; i++) {
    put_bool_of_obj_obj(ks1[i], CHAR, CHAR, vs1[i]);
  }
  fn_obj_of_obj of_obj_file_ks[] = {object_write, object_display, NULL};
  fn_of_obj_file of_obj_file_vs[] = {write, display, NULL};
  for (size_t i = 0; of_obj_file_ks[i] != NULL; i++) {
    put_of_obj_file(of_obj_file_ks[i], CHAR, of_obj_file_vs[i]);
  }

  char const *names[] = {"char-alphabetic?",
                         "char->integer",
                         "integer->char",
                         "c-char->integer",
                         "c-char<=?",
                         "c-char<?",
                         "c-char=?",
                         "c-char>=?",
                         "c-char>?",
                         "c-write-char",
                         "c-char-alphabetic?",
                         "c-char-ci<=?",
                         "c-char-ci<?",
                         "c-char-ci=?",
                         "c-char-ci>=?",
                         "c-char-ci>?",
                         "c-char-downcase",
                         "c-char-foldcase",
                         "c-char-lower-case?",
                         "c-char-numeric?",
                         "c-char-upcase",
                         "c-char-upper-case?",
                         "c-char-whitespace?",
                         "c-digit-value",
                         NULL};
  fn_obj_of_obj procs[] = {
      alphabetic_p, to_integer,   integer_to_char, to_integer,
      le_p,         lt_p,         math_equal_p,    ge_p,
      gt_p,         write_char,   alphabetic_p,    ci_le_p,
      ci_lt_p,      ci_eq_p,      ci_ge_p,         ci_gt_p,
      downcase,     foldcase,     lower_case_p,    numeric_p,
      upcase,       upper_case_p, whitespace_p,    digit_value,
      NULL};
  for (size_t i = 0; names[i] != NULL; i++) {
    val = (Object){.type = PROC, .proc = procs[i]};
    def_var_val(symbol_new(names[i]));
  }
  val = undef;
  def_var_val(symbol_new("undef"));
}
