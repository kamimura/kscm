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
  return fn(carref(args).ch) ? boolean_true : boolean_false;
}
static Object alphabetic_p(Object args) {
  return apply_bool_of_ch(g_unichar_isalpha, args);
}
static Object numeric_p(Object args) {
  return apply_bool_of_ch(g_unichar_isalpha, args);
}
static Object whitespace_p(Object args) {
  return apply_bool_of_ch(g_unichar_isspace, args);
}
static Object upper_case_p(Object args) {
  return apply_bool_of_ch(g_unichar_isupper, args);
}
static Object lower_case_p(Object args) {
  return apply_bool_of_ch(g_unichar_islower, args);
}
static Object digit_value(Object args) {
  gunichar ch = carref(args).ch;
  gint n = g_unichar_digit_value(ch);
  if (n == -1) {
    return boolean_false;
  }
  Object o = {.type = RATIONAL};
  mpq_init(o.rational);
  mpq_set_ui(o.rational, n, 1);
  return o;
}
static Object to_integer(Object args) {
  gunichar ch = carref(args).ch;
  Object o = {.type = RATIONAL};
  mpq_init(o.rational);
  mpq_set_ui(o.rational, ch, 1);
  return o;
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
static Object upcase(Object args) {
  return apply_char_of_char(g_unichar_toupper, args);
}
static Object downcase(Object args) {
  return apply_char_of_char(g_unichar_tolower, args);
}
static Object foldcase(Object args) {
  gunichar c = carref(args).ch;
  char outbuf[6];
  gint len = g_unichar_to_utf8(c, outbuf);
  gchar *s = g_utf8_casefold(outbuf, len);
  Object o = (Object){.type = CHAR, .ch = g_utf8_get_char(s)};
  g_free(s);
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

  /* add env */
  char const *names[] = {
      "char-alphabetic?", "char-numeric?",    "char-whitespace?",
      "char-upper-case?", "char-lower-case?", "digit-value",
      "char->integer",    "integer->char",    "char-upcase",
      "char-downcase",    "char-foldcase",    NULL};
  fn_obj_of_obj procs[] = {alphabetic_p, numeric_p,       whitespace_p,
                           upper_case_p, lower_case_p,    digit_value,
                           to_integer,   integer_to_char, upcase,
                           downcase,     foldcase,        NULL};
  for (size_t i = 0; names[i] != NULL; i++) {
    val = (Object){.type = PROC, .proc = procs[i]};
    def_var_val(symbol_new(names[i]));
  }
  val = undef;
  def_var_val(symbol_new("undef"));
}
