#include "object.h"

Object undef = {.type = UNDEF};
Object empty = {.type = EMPTY};
Object eof_obj = {.type = EOF_OBJ};
Object none = {.type = NONE};

static GHashTable *tb_bool_of_obj = NULL;
void put_bool_of_obj(fn_obj_of_obj k1, Type k2, fn_bool_of_obj v) {
  if (tb_bool_of_obj == NULL) {
    tb_bool_of_obj = g_hash_table_new(NULL, NULL);
  }
  GHashTable *t = g_hash_table_lookup(tb_bool_of_obj, k1);
  if (t == NULL) {
    t = g_hash_table_new(NULL, NULL);
    g_hash_table_insert(tb_bool_of_obj, k1, t);
    /* g_hash_table_insert(tb_bool_of_obj, GINT_TO_POINTER(k2), t); */
  }
  g_hash_table_insert(t, GINT_TO_POINTER(k2), v);
}
fn_bool_of_obj get_bool_of_obj(fn_obj_of_obj k1, Object k2) {
  if (tb_bool_of_obj == NULL) {
    return NULL;
  }
  GHashTable *t = g_hash_table_lookup(tb_bool_of_obj, k1);
  if (t == NULL) {
    return NULL;
  }
  return g_hash_table_lookup(t, GINT_TO_POINTER(k2.type));
}

static GHashTable *tb_bool_of_obj_obj = NULL;
void put_bool_of_obj_obj(fn_obj_of_obj k1, Type k2, Type k3,
                         fn_bool_of_obj_obj v) {
  if (tb_bool_of_obj_obj == NULL) {
    tb_bool_of_obj_obj = g_hash_table_new(NULL, NULL);
  }
  GHashTable *t1 = g_hash_table_lookup(tb_bool_of_obj_obj, k1);
  if (t1 == NULL) {
    t1 = g_hash_table_new(NULL, NULL);
    g_hash_table_insert(tb_bool_of_obj_obj, k1, t1);
    /* g_hash_table_insert(tb_bool_of_obj_obj, GINT_TO_POINTER(k1), t1); */
  }
  GHashTable *t2 = g_hash_table_lookup(t1, GINT_TO_POINTER(k2));
  if (t2 == NULL) {
    t2 = g_hash_table_new(NULL, NULL);
    g_hash_table_insert(t1, GINT_TO_POINTER(k2), t2);
  }
  g_hash_table_insert(t2, GINT_TO_POINTER(k3), v);
}
fn_bool_of_obj_obj get_bool_of_obj_obj(fn_obj_of_obj k1, Object k2, Object k3) {
  if (tb_bool_of_obj_obj == NULL) {
    return NULL;
  }
  GHashTable *t1 = g_hash_table_lookup(tb_bool_of_obj_obj, k1);
  if (t1 == NULL) {
    return NULL;
  }
  GHashTable *t2 = g_hash_table_lookup(t1, GINT_TO_POINTER(k2.type));
  if (t2 == NULL) {
    return NULL;
  }
  return g_hash_table_lookup(t2, GINT_TO_POINTER(k3.type));
}
static GHashTable *tb_obj_of_obj_obj = NULL;
void put_obj_of_obj_obj(fn_obj_of_obj k1, Type k2, Type k3,
                        fn_obj_of_obj_obj v) {
  if (tb_obj_of_obj_obj == NULL) {
    tb_obj_of_obj_obj = g_hash_table_new(NULL, NULL);
  }
  GHashTable *t1 = g_hash_table_lookup(tb_obj_of_obj_obj, k1);
  if (t1 == NULL) {
    t1 = g_hash_table_new(NULL, NULL);
    g_hash_table_insert(tb_obj_of_obj_obj, k1, t1);
    /* g_hash_table_insert(tb_obj_of_obj_obj, GINT_TO_POINTER(k1), t1); */
  }
  GHashTable *t2 = g_hash_table_lookup(t1, GINT_TO_POINTER(k2));
  if (t2 == NULL) {
    t2 = g_hash_table_new(NULL, NULL);
    g_hash_table_insert(t1, GINT_TO_POINTER(k2), t2);
  }
  g_hash_table_insert(t2, GINT_TO_POINTER(k3), v);
}
fn_obj_of_obj_obj get_obj_of_obj_obj(fn_obj_of_obj k1, Object k2, Object k3) {
  if (tb_obj_of_obj_obj == NULL) {
    return NULL;
  }
  GHashTable *t1 = g_hash_table_lookup(tb_obj_of_obj_obj, k1);
  if (t1 == NULL) {
    return NULL;
  }
  GHashTable *t2 = g_hash_table_lookup(t1, GINT_TO_POINTER(k2.type));
  if (t2 == NULL) {
    return NULL;
  }
  return g_hash_table_lookup(t2, GINT_TO_POINTER(k3.type));
}
static GHashTable *tb_of_obj_file = NULL;
void put_of_obj_file(fn_obj_of_obj k1, Type k2, fn_of_obj_file v) {
  if (tb_of_obj_file == NULL) {
    tb_of_obj_file = g_hash_table_new(NULL, NULL);
  }
  GHashTable *t = g_hash_table_lookup(tb_of_obj_file, k1);
  if (t == NULL) {
    t = g_hash_table_new(NULL, NULL);
    g_hash_table_insert(tb_of_obj_file, k1, t);
  }
  g_hash_table_insert(t, GINT_TO_POINTER(k2), v);
}
fn_of_obj_file get_of_obj_file(fn_obj_of_obj k1, Object k2) {
  if (tb_of_obj_file == NULL) {
    fprintf(stderr, "get_of_obj_file1: type: %d\n", k2.type);
    exit(1);
  }
  GHashTable *t = g_hash_table_lookup(tb_of_obj_file, k1);
  if (t == NULL) {
    fprintf(stderr, "get_of_obj_file2: type: %d\n", k2.type);
    exit(1);
  }
  return g_hash_table_lookup(t, GINT_TO_POINTER(k2.type));
}
static GHashTable *tb_obj_of_obj = NULL;
void put_obj_of_obj(fn_obj_of_obj k1, Type k2, fn_obj_of_obj v) {
  if (tb_obj_of_obj == NULL) {
    tb_obj_of_obj = g_hash_table_new(NULL, NULL);
  }
  GHashTable *t = g_hash_table_lookup(tb_obj_of_obj, k1);
  /* GHashTable *t = g_hash_table_lookup(tb_obj_of_obj, GINT_TO_POINTER(k1)); */
  if (t == NULL) {
    t = g_hash_table_new(NULL, NULL);
    g_hash_table_insert(tb_obj_of_obj, k1, t);
    /* g_hash_table_insert(tb_obj_of_obj, GINT_TO_POINTER(k1), t); */
  }
  g_hash_table_insert(t, GINT_TO_POINTER(k2), v);
}
fn_obj_of_obj get_obj_of_obj(fn_obj_of_obj k1, Object k2) {
  if (tb_obj_of_obj == NULL) {
    return NULL;
  }
  GHashTable *t = g_hash_table_lookup(tb_obj_of_obj, k1);
  if (t == NULL) {
    return NULL;
  }
  return g_hash_table_lookup(t, GINT_TO_POINTER(k2.type));
}

static GHashTable *tb_of_obj_ptr = NULL;
void put_of_obj_ptr(fn_of_obj_ptr k1, Type k2, fn_of_obj_ptr v) {
  if (tb_of_obj_ptr == NULL) {
    tb_of_obj_ptr = g_hash_table_new(NULL, NULL);
  }
  GHashTable *t = g_hash_table_lookup(tb_of_obj_ptr, k1);
  if (t == NULL) {
    t = g_hash_table_new(NULL, NULL);
    g_hash_table_insert(tb_of_obj_ptr, GINT_TO_POINTER(k2), t);
  }
  g_hash_table_insert(t, GINT_TO_POINTER(k2), v);
}
fn_of_obj_ptr get_of_obj_ptr(fn_of_obj_ptr k1, Object *k2) {
  if (tb_of_obj_ptr == NULL) {
    return NULL;
  }
  GHashTable *t = g_hash_table_lookup(tb_of_obj_ptr, k1);
  if (t == NULL) {
    return NULL;
  }
  return g_hash_table_lookup(t, GINT_TO_POINTER(k2->type));
}

Object object_copy(Object o) {
  fn_obj_of_obj fn = get_obj_of_obj(object_copy, o);
  if (!fn) {
    return o;
  }
  return fn(o);
}
void object_free(Object *o_ptr) {
  fn_of_obj_ptr fn = get_of_obj_ptr(object_free, o_ptr);
  if (fn) {
    fn(o_ptr);
  }
  o_ptr->type = NONE;
}

static Object apply_bool_of_obj_obj(fn_obj_of_obj fn, Object args) {
  Object o1 = carref(args);
  Object o2 = carref(cdrref(args));
  fn_bool_of_obj_obj fn0 = get_bool_of_obj_obj(fn, o1, o2);
  if (!fn0) {
    return boolean_false;
  }
  return fn0(o1, o2) ? boolean_true : boolean_false;
}
Object object_eqv_p(Object args) {
  return apply_bool_of_obj_obj(object_eqv_p, args);
}
Object object_eq_p(Object args) {
  return apply_bool_of_obj_obj(object_eq_p, args);
}
static Object complex_p(Object args) {
  Type t = carref(argl).type;
  return t == COMPLEX || t == RATIONAL || t == BYTE ? boolean_true
                                                    : boolean_false;
}
Object object_integer_p(Object args) {
  Object o = carref(argl);
  fn_bool_of_obj fn = get_bool_of_obj(object_integer_p, o);
  if (fn) {
    return fn(o) ? boolean_true : boolean_false;
  }
  return boolean_false;
}
static Object boolean_p(Object args) {
  return carref(args).type == BOOLEAN ? boolean_true : boolean_false;
}
static Object c_boolean_p(Object args) {
  return carref(args).type == BOOLEAN ? boolean_true : boolean_false;
}
static Object symbol_p(Object args) {
  Type t = carref(argl).type;
  return t == SYMBOL || t == SYMBOL_VERTICAL ? boolean_true : boolean_false;
}
static Object not(Object args) {
  return carref(args).type == BOOLEAN && carref(args).boolean == false
             ? boolean_true
             : boolean_false;
}
/* Pair */
static Object null_p(Object args) {
  return carref(args).type == EMPTY ? boolean_true : boolean_false;
}
/* Characters */
static Object char_p(Object args) {
  Type t = carref(argl).type;
  return t == CHAR ? boolean_true : boolean_false;
}
/* Vectors */
static Object vector_p(Object args) {
  return carref(args).type == VECTOR ? boolean_true : boolean_false;
}
/* Bytevectors  */
static Object bytevector_p(Object args) {
  return carref(args).type == BYTEVECTOR ? boolean_true : boolean_false;
}

/* Control features */
static Object procedure_p(Object args) {
  Type t = carref(argl).type;
  return t == PROC_APPLY || t == PROC || t == PROC_COMPILED ? boolean_true
                                                            : boolean_false;
}
/* Input and output */
static Object input_port_p(Object args) {
  Type t = carref(argl).type;
  return t == PORT_INPUT_TEXT || t == PORT_INPUT_BIN ? boolean_true
                                                     : boolean_false;
}
static Object output_port_p(Object args) {
  Type t = carref(argl).type;
  return t == PORT_OUTPUT_TEXT || t == PORT_OUTPUT_BIN ? boolean_true
                                                       : boolean_false;
}
static Object binary_port_p(Object args) {
  Type t = carref(argl).type;
  return t == PORT_INPUT_BIN || t == PORT_OUTPUT_BIN ? boolean_true
                                                     : boolean_false;
}
static Object eof_object_p(Object args) {
  return carref(argl).type == EOF_OBJ ? boolean_true : boolean_false;
}
/* 6.11 Exceptions */
static void c_write(FILE *s, Object o) {
  if (o.type == PAIR) {
    fprintf(s, "(");
    c_write(s, carref(o));
    if (cdrref(o).type == EMPTY) {
      fprintf(s, ")");
    } else if (cdrref(o).type == PAIR) {
      for (;;) {
        fprintf(s, " ");
        o = cdrref(o);
        c_write(s, carref(o));
        if (cdrref(o).type == EMPTY) {
          fprintf(s, ")");
          break;
        }
        if (cdrref(o).type != PAIR) {
          fprintf(s, " . ");
          c_write(s, cdrref(o));
          fprintf(s, ")");
          break;
        }
      }
    } else {
      fprintf(s, " . ");
      c_write(s, cdrref(o));
      fprintf(s, ")");
    }
  } else {
    fn_of_obj_file fn = get_of_obj_file(object_write, o);
    if (!fn) {
      fprintf(stderr, "error: %s %s (type %d)\n", __FILE__, __FUNCTION__,
              o.type);
      exit(1);
    }
    fn(o, s);
  }
}
static Object error(Object args) {
  fprintf(stderr, "Error:");
  for (; args.type != EMPTY;) {
    fprintf(stderr, " ");
    Object o = carref(args);
    fn_of_obj_file fn = get_of_obj_file(object_display, o);
    if (!fn) {
      c_write(stderr, o);
    } else {
      fn(o, stderr);
    }

    args = cdrref(args);
  }
  fprintf(stderr, "\n");
  exit(1);
}

extern FILE *cur_output;
Object object_write(Object args) {
  size_t len = argl_length();
  if (len == 1) {
    Object o1 = carref(argl);
    c_write(cur_output, o1);
    return undef;
  }
  if (len == 2) {
    Object o1 = carref(args);
    Object o2 = carref(cdrref(args));
    FILE *t = cur_output;
    cur_output = o2.port;
    c_write(o2.port, o1);
    cur_output = t;
    return undef;
  }
  argl_length_error("write");
  return undef;
}
Object object_display(Object args) {
  size_t len = argl_length();
  if (len == 1) {
    Object o1 = carref(argl);
    fn_of_obj_file fn = get_of_obj_file(object_display, o1);
    if (!fn) {
      return object_write(argl);
    }
    fn(o1, cur_output);
    return undef;
  }
  if (len == 2) {
    Object o1 = carref(argl);
    Object o2 = carref(cdrref(argl));
    fn_of_obj_file fn = get_of_obj_file(object_display, o1);
    if (!fn) {
      return object_write(argl);
    }
    FILE *t = cur_output;
    cur_output = o2.port;
    fn(o1, o2.port);
    cur_output = t;
    return undef;
  }
  argl_length_error("display");
  return undef;
}
void object_write_stdout(Object o) { c_write(stdout, o); }
void object_write_stderr(Object o) { c_write(stderr, o); }
void object_writeln_stdout(Object o) {
  object_write_stdout(o);
  puts("");
}
static Object object_newline(Object args) {
  fprintf(carref(argl).port, "\n");
  return undef;
}
static Object list_p(Object args) {
  Object o = carref(argl);
  if (o.type == EMPTY) {
    return boolean_true;
  }
  if (o.type == PAIR) {
    for (; o.type == PAIR; o = cdrref(o)) {
    }
    return o.type == EMPTY ? boolean_true : boolean_false;
  }
  return boolean_false;
}
static Object pair_p(Object args) {
  return carref(args).type == PAIR ? boolean_true : boolean_false;
}
static Object port_p(Object args) {
  Type t = carref(argl).type;
  return t == PORT_INPUT_TEXT || t == PORT_INPUT_BIN || t == PORT_OUTPUT_TEXT ||
                 t == PORT_OUTPUT_BIN || t == PORT_ERROR_TEXT
             ? boolean_true
             : boolean_false;
}

static Object real_p(Object args) {
  Type t = carref(argl).type;
  if (t == COMPLEX) {
    return cimag(carref(argl).z) == 0 ? boolean_true : boolean_false;
  }
  if (t == RATIONAL) {
    return boolean_true;
  }
  return boolean_false;
}
static Object string_p(Object args) {
  Type t = carref(argl).type;
  return t == STRING || t == STRING_EMPTY ? boolean_true : boolean_false;
}

static Object textual_port_p(Object args) {
  Type t = carref(argl).type;
  return t == PORT_INPUT_TEXT || t == PORT_OUTPUT_TEXT ? boolean_true
                                                       : boolean_false;
}

void object_init() {
  char const *names[] = {"eqv?",
                         "eq?",
                         "number?",
                         "complex?",
                         "boolean?",
                         "pair?",
                         "null?",
                         "char?",
                         "string?",
                         "vector?",
                         "bytevector?",
                         "procedure?",
                         "error",
                         "input-port?",
                         "output-port?",
                         "textual-port?",
                         "binary-port?",
                         "not",
                         "write",
                         "display",
                         "newline",
                         "c-null?",
                         "eof-object?",
                         "c-procedure?",
                         "c-binary-port?",
                         "c-boolean?",
                         "c-eq?",
                         "c-bytevector?",
                         "c-char?",
                         "c-complex?",
                         "c-input-port?",
                         "c-eof-object?",
                         "c-eq?",
                         "c-eqv?",
                         "c-integer?",
                         "c-list?",
                         "c-newline",
                         "c-pair?",
                         "c-vector?",
                         "c-number?",
                         "c-output-port?",
                         "c-port?",
                         "c-real?",
                         "c-string?",
                         "c-symbol?",
                         "c-textual-port?",
                         NULL};
  fn_obj_of_obj procs[] = {object_eqv_p,
                           object_eq_p,
                           complex_p,
                           complex_p,
                           boolean_p,
                           pair_p,
                           null_p,
                           char_p,
                           string_p,
                           vector_p,
                           bytevector_p,
                           procedure_p,
                           error,
                           input_port_p,
                           output_port_p,
                           textual_port_p,
                           binary_port_p,
                           not,
                           object_write,
                           object_display,
                           object_newline,
                           null_p,
                           eof_object_p,
                           procedure_p,
                           binary_port_p,
                           c_boolean_p,
                           object_eq_p,
                           bytevector_p,
                           char_p,
                           complex_p,
                           input_port_p,
                           eof_object_p,
                           object_eq_p,
                           object_eqv_p,
                           object_integer_p,
                           list_p,
                           object_newline,
                           pair_p,
                           vector_p,
                           complex_p,
                           output_port_p,
                           port_p,

                           real_p,
                           string_p,
                           symbol_p,
                           textual_port_p,
                           NULL};
  for (size_t i = 0; names[i] != NULL; i++) {
    val = (Object){.type = PROC, .proc = procs[i]};
    def_var_val(symbol_new(names[i]));
  }
}

size_t argl_length() {
  size_t len = 0;
  for (Object t = argl; t.type != EMPTY; t = cdrref(t)) {
    len++;
  }
  return len;
}

void argl_length_error(const char *s) {
  fprintf(stderr, "Error: (%s) wrong number of arguments -- ", s);
  c_write(stderr, argl);
  fprintf(stderr, "\n");
  exit(1);
}
void check_argl_length(const char *s, size_t len) {
  if (argl_length() != len) {
    argl_length_error(s);
  }
}

void argl_type_error(const char *s) {
  fprintf(stderr, "Error: (%s) wrong type of arguments -- ", s);
  c_write(stderr, argl);
  fprintf(stderr, "\n");
  exit(1);
}
void check_argl_type(const char *s, Object o, Type t) {
  if (o.type != t) {
    argl_type_error(s);
  }
}
