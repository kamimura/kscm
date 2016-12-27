#include "symbol.h"

#include <string.h> // strdup

Object symbol_quote;
static GHashTable *tb = NULL;
Object symbol_new(char const *s) {
  if (tb == NULL) {
    tb = g_hash_table_new(g_str_hash, g_str_equal);
  }
  char *s0 = g_hash_table_lookup(tb, s);
  if (s0 == NULL) {
    s0 = strdup(s);
    g_hash_table_insert(tb, s0, s0);
  }
  return (Object){.type = SYMBOL, .symbol = s0};
}
Object symbol_vertical_new(char const *s) {
  glong items_written;
  gunichar *ucs = g_utf8_to_ucs4(s, -1, NULL, &items_written, NULL);
  gunichar ucs_new[items_written + 1];
  size_t j = 0;
  for (size_t i = 0; i < items_written; i++) {
    if (ucs[i] == '\\') {
      i++;
      if (ucs[i] == 'x') {
        ucs_new[j] = 0;
        i++;
        for (; ucs[i] != ';'; i++) {
          ucs_new[j] *= 16;
          ucs_new[j] += g_unichar_xdigit_value(ucs[i]);
        }
      } else if (ucs[i] == '|') {
        ucs_new[j] = '|';
      } else if (ucs[i] == 'a') {
        ucs_new[j] = '\a';
      } else if (ucs[i] == 'b') {
        ucs_new[j] = '\b';
      } else if (ucs[i] == 't') {
        ucs_new[j] = '\t';
      } else if (ucs[i] == 'n') {
        ucs_new[j] = '\n';
      } else if (ucs[i] == 'r') {
        ucs_new[j] = '\r';
      }
    } else {
      ucs_new[j] = ucs[i];
    }
    j++;
  }
  ucs_new[j] = '\0';
  g_free(ucs);
  char *s0 = g_ucs4_to_utf8(ucs_new, -1, NULL, NULL, NULL);
  if (tb == NULL) {
    tb = g_hash_table_new(g_str_hash, g_str_equal);
  }
  char *s1 = g_hash_table_lookup(tb, s0);
  if (!s1) {
    g_hash_table_insert(tb, s0, s0);
    return (Object){.type = SYMBOL_VERTICAL, .symbol = s0};
  }
  g_free(s0);
  return (Object){.type = SYMBOL_VERTICAL, .symbol = s1};
}
static bool eqv_p(Object o1, Object o2) { return o1.symbol == o2.symbol; }
Object symbol_math_equal_p(Object args) {
  Object o1 = carref(args);
  Object o2 = carref(cdrref(args));
  return o1.symbol == o2.symbol ? boolean_true : boolean_false;
}

static void write(Object o, FILE *stream) { fprintf(stream, "%s", o.symbol); }
static void vertical_write(Object o, FILE *stream) {
  fprintf(stream, "|");
  glong items_written;
  gunichar *ucs = g_utf8_to_ucs4(o.symbol, -1, NULL, &items_written, NULL);
  for (size_t i = 0; i < items_written; i++) {
    gunichar ch = ucs[i];
    if (ch == 0x5c) {
      fprintf(stream, "\\x5c;");
    } else if (ch == '|') {
      fprintf(stream, "\\|");
    } else if (ch == 0x07) {
      fprintf(stream, "\\a");
    } else if (ch == 0x08) {
      fprintf(stream, "\\b");
    } else if (ch == 0x0a) {
      fprintf(stream, "\\n");
    } else if (ch == 0x0d) {
      fprintf(stream, "\\r");
    } else if (ch == 0x09) {
      fprintf(stream, "\\t");
    } else if (g_unichar_isgraph(ch)) {
      char outbuf[7];
      int len = g_unichar_to_utf8(ch, outbuf);
      outbuf[len] = '\0';
      fprintf(stream, "%s", outbuf);
    } else {
      fprintf(stream, "\\x%x;", ch);
    }
  }
  fprintf(stream, "|");
  g_free(ucs);
}

Object c_symbol_to_c(Object args) {
  Object o = carref(args);
  glong items_written;
  gunichar *ucs = g_utf8_to_ucs4(o.symbol, -1, NULL, &items_written, NULL);
  gunichar ucs_new[items_written * 6 + 3];
  size_t i = 0;
  ucs_new[0] = '|';
  size_t j = 1;
  for (; i < items_written; i++) {
    gunichar c = ucs[i];
    if (c == '"') {
      ucs_new[j] = '\\';
      ucs_new[j + 1] = '\\';
      ucs_new[j + 2] = 'x';
      ucs_new[j + 3] = '2';
      ucs_new[j + 4] = '2';
      ucs_new[j + 5] = ';';
      j += 5;
    } else if (c == '\0') {
      ucs_new[j] = '\\';
      ucs_new[j + 1] = '\\';
      ucs_new[j + 2] = 'x';
      ucs_new[j + 3] = '0';
      ucs_new[j + 4] = ';';
      j += 4;
    } else if (c == '\\') {
      ucs_new[j] = '\\';
      ucs_new[j + 1] = '\\';
      ucs_new[j + 2] = 'x';
      ucs_new[j + 3] = '5';
      ucs_new[j + 4] = 'c';
      ucs_new[j + 5] = ';';
      j += 5;
    } else if (c == '|') {
      ucs_new[j] = '\\';
      ucs_new[j + 1] = '\\';
      ucs_new[j + 2] = 'x';
      ucs_new[j + 3] = '7';
      ucs_new[j + 4] = 'c';
      ucs_new[j + 5] = ';';
      j += 5;
    } else if (c == '\a') {
      ucs_new[j] = '\\';
      ucs_new[j + 1] = '\\';
      ucs_new[j + 2] = 'a';
      j += 2;
    } else if (c == '\b') {
      ucs_new[j] = '\\';
      ucs_new[j + 1] = '\\';
      ucs_new[j + 2] = 'b';
      j += 2;
    } else if (c == '\t') {
      ucs_new[j] = '\\';
      ucs_new[j + 1] = '\\';
      ucs_new[j + 2] = 't';
      j += 2;
    } else if (c == '\n') {
      ucs_new[j] = '\\';
      ucs_new[j + 1] = '\\';
      ucs_new[j + 2] = 'n';
      j += 2;
    } else if (c == '\r') {
      ucs_new[j] = '\\';
      ucs_new[j + 1] = '\\';
      ucs_new[j + 2] = 'r';
      j += 2;
    } else {
      ucs_new[j] = c;
    }
    j++;
  }
  g_free(ucs);
  ucs_new[j] = '|';
  gchar *s = g_ucs4_to_utf8(ucs_new, j + 1, NULL, NULL, NULL);
  if (!tb) {
    tb = g_hash_table_new(g_str_hash, g_str_equal);
  }
  char *s0 = g_hash_table_lookup(tb, s);
  if (s0) {
    g_free(s);
    return cons((Object){.type = SYMBOL_VERTICAL, .symbol = s0}, empty);
  }
  g_hash_table_insert(tb, s, s);
  return cons((Object){.type = SYMBOL_VERTICAL, .symbol = s}, empty);
}
static Object c_string_to_c(Object args) {
  Object o = carref(args);
  size_t len = 0;
  for (Object t = o; t.type != STRING_EMPTY; t = cdrref(t)) {
    len++;
  }
  gunichar ucs[len * 6 + 5];
  ucs[0] = '\\';
  ucs[1] = '"';
  size_t i = 2;
  for (Object t = o; t.type != STRING_EMPTY; t = cdrref(t)) {
    gunichar c = carref(t).ch;
    if (c == '"') {
      ucs[i] = '\\';
      ucs[i + 1] = '\\';
      ucs[i + 2] = 'x';
      ucs[i + 3] = '2';
      ucs[i + 4] = '2';
      ucs[i + 5] = ';';
      i += 5;
    } else if (c == '\0') {
      ucs[i] = '\\';
      ucs[i + 1] = '\\';
      ucs[i + 2] = 'x';
      ucs[i + 3] = '0';
      ucs[i + 4] = ';';
      i += 4;
    } else if (c == '\\') {
      ucs[i] = '\\';
      ucs[i + 1] = '\\';
      ucs[i + 2] = 'x';
      ucs[i + 3] = '5';
      ucs[i + 4] = 'c';
      ucs[i + 5] = ';';
      i += 5;
    } else if (c == '\a') {
      ucs[i] = '\\';
      ucs[i + 1] = '\\';
      ucs[i + 2] = 'a';
      i += 2;
    } else if (c == '\b') {
      ucs[i] = '\\';
      ucs[i + 1] = '\\';
      ucs[i + 2] = 'b';
      i += 2;
    } else if (c == '\t') {
      ucs[i] = '\\';
      ucs[i + 1] = '\\';
      ucs[i + 2] = 't';
      i += 2;
    } else if (c == '\n') {
      ucs[i] = '\\';
      ucs[i + 1] = '\\';
      ucs[i + 2] = 'n';
      i += 2;
    } else if (c == '\r') {
      ucs[i] = '\\';
      ucs[i + 1] = '\\';
      ucs[i + 2] = 'r';
      i += 2;
    } else {
      ucs[i] = c;
    }
    i++;
  }
  ucs[i] = '\\';
  ucs[i + 1] = '"';
  gchar *s = g_ucs4_to_utf8(ucs, i + 2, NULL, NULL, NULL);
  if (!tb) {
    tb = g_hash_table_new(g_str_hash, g_str_equal);
  }
  char *s0 = g_hash_table_lookup(tb, s);
  if (s0) {
    g_free(s);
    return cons((Object){.type = SYMBOL_VERTICAL, .symbol = s0}, empty);
  }
  g_hash_table_insert(tb, s, s);
  return cons((Object){.type = SYMBOL_VERTICAL, .symbol = s}, empty);
}
void symbol_init() {
  fn_obj_of_obj ks1[] = {object_eqv_p, object_eq_p, NULL};
  fn_bool_of_obj_obj vs1[] = {eqv_p, eqv_p, NULL};
  for (size_t i = 0; ks1[i] != NULL; i++) {
    put_bool_of_obj_obj(ks1[i], SYMBOL, SYMBOL, vs1[i]);
    put_bool_of_obj_obj(ks1[i], SYMBOL_VERTICAL, SYMBOL_VERTICAL, vs1[i]);
    put_bool_of_obj_obj(ks1[i], SYMBOL, SYMBOL_VERTICAL, vs1[i]);
    put_bool_of_obj_obj(ks1[i], SYMBOL_VERTICAL, SYMBOL, vs1[i]);
  }
  fn_obj_of_obj of_obj_file_ks[] = {object_write, object_display, NULL};
  fn_of_obj_file of_obj_file_vs1[] = {write, write, NULL};
  fn_of_obj_file of_obj_file_vs2[] = {vertical_write, write, NULL};
  for (size_t i = 0; of_obj_file_ks[i] != NULL; i++) {
    put_of_obj_file(of_obj_file_ks[i], SYMBOL, of_obj_file_vs1[i]);
    put_of_obj_file(of_obj_file_ks[i], SYMBOL_VERTICAL, of_obj_file_vs2[i]);
  }
  char const *names[] = {"symbol->string", "string->symbol", "c-symbol->c",
                         "c-string->c", NULL};
  fn_obj_of_obj procs[] = {symbol_to_string, string_to_symbol, c_symbol_to_c,
                           c_string_to_c, NULL};
  for (size_t i = 0; names[i] != NULL; i++) {
    val = (Object){.type = PROC, .proc = procs[i]};
    def_var_val(symbol_new(names[i]));
  }
  symbol_quote = symbol_new("quote");
}
