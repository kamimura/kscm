#include "init.h"

static Object c_char_to_c(Object args) {
  Object o = carref(argl);
  gunichar c = o.ch;
  if (c == '"') {
    return cons(symbol_vertical_new("#\\x5c;\\x5c;x22"), empty);
  }
  if (c == '\\') {
    return cons(symbol_vertical_new("#\\x5c;\\x5c;x5c"), empty);
  }
  if (c == 0x07) {
    return cons(symbol_vertical_new("#\\x5c;\\x5c;alarm"), empty);
  }
  if (c == 0x08) {
    return cons(symbol_vertical_new("#\\x5c;\\x5c;backspace"), empty);
  }
  if (c == 0x1b) {
    return cons(symbol_vertical_new("#\\x5c;\\x5c;escape"), empty);
  }
  if (c == 0x0a) {
    return cons(symbol_vertical_new("#\\x5c;\\x5c;newline"), empty);
  }
  if (c == 0x00) {
    return cons(symbol_vertical_new("#\\x5c;\\x5c;null"), empty);
  }
  if (c == 0x0d) {
    return cons(symbol_vertical_new("#\\x5c;\\x5c;return"), empty);
  }
  if (c == 0x20) {
    return cons(symbol_vertical_new("#\\x5c;\\x5c;space"), empty);
  }
  if (c == 0x09) {
    return cons(symbol_vertical_new("#\\x5c;\\x5c;tab"), empty);
  }
  return cons(symbol_vertical_new("#\\x5c;#\\x5c;"), cons(o, empty));
}
static Object c_self_evaluating_p(Object args) {
  Type t = carref(args).type;
  return (t == BOOLEAN || t == COMPLEX || t == RATIONAL || t == CHAR ||
          t == STRING || t == STRING_EMPTY || t == PROC || t == PROC_COMPILED ||
          t == VECTOR || t == EOF_OBJ || t == UNDEF)
             ? boolean_true
             : boolean_false;
}
static Object c_if_alternative(Object args) {
  Object o = carref(argl);
  Object t = cdrref(cdrref(cdrref(o)));
  if (t.type == EMPTY) {
    return undef;
  }
  return car(t);
}
static Object c_definition_variable(Object args) {
  Object o = carref(argl);
  Object t = carref(cdrref(o));
  if (t.type == PAIR) {
    return carref(t);
  }
  return t;
}
static Object c_list_union(Object args) {
  Object out = carref(argl);
  Object o = carref(cdrref(argl));
  for (; o.type != EMPTY; o = cdrref(o)) {
    Object s = carref(o);
    Object t = out;
    for (; t.type != EMPTY; t = cdrref(t)) {
      if (s.symbol == carref(t).symbol) {
        break;
      }
    }
    if (t.type == EMPTY) {
      out = cons(s, out);
    }
  }
  return out;
}
static Object c_list_difference(Object args) {
  Object o1 = carref(argl);
  Object o2 = carref(cdrref(argl));
  Object out = empty;
  for (; o1.type != EMPTY; o1 = cdrref(o1)) {
    Object s1 = carref(o1);
    Object t = o2;
    for (; t.type != EMPTY; t = cdrref(t)) {
      Object s2 = carref(t);
      if (s1.symbol == s2.symbol) {
        break;
      }
    }
    if (t.type == EMPTY) {
      out = cons(s1, out);
    }
  }
  return out;
}
static Object c_symbol_memq(Object args) {
  Object o1 = carref(args);
  Object o2 = carref(cdrref(args));
  char *sym = o1.symbol;
  for (Object t = o2; t.type != EMPTY; t = cdrref(t)) {
    if (sym == carref(t).symbol) {
      return t;
    }
  }
  return boolean_false;
}
static Object symbol_lambda;
static Object c_make_lambda(Object args) {
  Object o1 = carref(argl);
  Object o2 = carref(cdrref(argl));
  argl = cons(o1, o2);
  return cons(symbol_lambda, argl);
}
static Object x_make_instruction_sequence(Object args) { return argl; }
static Object c_empty_instruction_sequence(Object args) {
  argl = cons(empty, argl);
  argl = cons(empty, argl);
  argl = cons(empty, argl);
  return argl;
}
static Object c_registers_needed(Object args) {
  Object o = carref(argl);
  if (o.type == SYMBOL || o.type == SYMBOL_VERTICAL) {
    return empty;
  }
  return carref(o);
}
static Object c_registers_modified(Object args) {
  Object o = carref(argl);
  if (o.type == SYMBOL || o.type == SYMBOL_VERTICAL) {
    return empty;
  }
  return carref(cdrref(o));
}
static Object c_statements(Object args) {
  Object o = carref(argl);
  if (o.type == SYMBOL || o.type == SYMBOL_VERTICAL) {
    return argl;
  }
  return carref(cdrref(cdrref(o)));
}
static Object c_needs_register_p(Object args) {
  Object o1 = carref(argl);
  if (o1.type == SYMBOL || o1.type == SYMBOL_VERTICAL) {
    return boolean_false;
  }
  o1 = carref(o1);
  Object o2 = carref(cdrref(argl));
  char *sym = o2.symbol;
  for (; o1.type != EMPTY; o1 = cdrref(o1)) {
    if (sym == carref(o1).symbol) {
      return o1;
    }
  }
  return boolean_false;
}
static Object c_modifies_register_p(Object args) {
  Object o1 = carref(argl);
  if (o1.type == SYMBOL || o1.type == SYMBOL_VERTICAL) {
    return boolean_false;
  }
  o1 = carref(cdrref(o1));
  Object o2 = carref(cdrref(argl));
  char *sym = o2.symbol;
  for (; o1.type != EMPTY; o1 = cdrref(o1)) {
    if (sym == carref(o1).symbol) {
      return o1;
    }
  }
  return boolean_false;
}
void init() {
  memory_init();
  env_init();
  symbol_init();
  object_init();
  empty_init();
  pair_init();
  vector_init();
  proc_init();
  proc_compiled_init();
  bytevector_init();
  number_init();
  complex_init();
  rational_init();
  boolean_init();
  char_init();
  string_init();
  syntax_init();
  port_init();
  undef_init();
  eof_init();
  system_init();

  /* add env */
  char const *names[] = {"read",
                         "c-char->c",
                         "c-self-evaluating?",
                         "c-if-alternative",
                         "c-definition-variable",
                         "c-list-union",
                         "c-list-difference",
                         "c-symbol-memq",
                         "c-make-lambda",
                         "c-make-instruction-sequence",
                         "c-empty-instruction-sequence",
                         "c-registers-needed",
                         "c-registers-modified",
                         "c-statements",
                         "c-needs-register?",
                         "c-modifies-register?",
                         NULL};
  fn_obj_of_obj procs[] = {object_read,
                           c_char_to_c,
                           c_self_evaluating_p,
                           c_if_alternative,
                           c_definition_variable,
                           c_list_union,
                           c_list_difference,
                           c_symbol_memq,
                           c_make_lambda,
                           x_make_instruction_sequence,
                           c_empty_instruction_sequence,
                           c_registers_needed,
                           c_registers_modified,
                           c_statements,
                           c_needs_register_p,
                           c_modifies_register_p,
                           NULL};
  for (size_t i = 0; names[i] != NULL; i++) {
    val = (Object){.type = PROC, .proc = procs[i]};
    def_var_val(symbol_new(names[i]));
    val.type = NONE;
  }
  symbol_lambda = symbol_new("lambda");
}
