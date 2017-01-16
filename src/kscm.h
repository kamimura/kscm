#pragma once
/** \file  */

void get_command_line(int argc, char *argv[]);
void init();

typedef struct Object Object;
typedef enum Type Type;
typedef Object (*fn_obj_of_obj)(Object);

#include <complex.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#include <glib.h>
#include <gmp.h>
#include <mpfr.h>

enum Type {
  NONE,
  UNDEF,
  COMPLEX,
  RATIONAL,
  BOOLEAN,
  EMPTY, /* 5 */
  PAIR,
  SYMBOL,
  SYMBOL_VERTICAL,
  CHAR,
  STRING, /* 10 */
  STRING_EMPTY,
  PROC_APPLY,
  PROC,
  PROC_COMPILED,
  PORT_INPUT_TEXT,
  PORT_INPUT_BIN,
  PORT_OUTPUT_TEXT,
  PORT_OUTPUT_BIN,
  PORT_ERROR_TEXT,
  VECTOR,
  BYTE, /* 20 */
  BYTEVECTOR,
  BYTEVECTOR_LENGTH,
  BYTES,
  EOF_OBJ,
  QUOTE,
  LAMBDA,
  IF, /* 25 */
  DEFINE,
  SET,
  BEGIN_OBJ,
  AND_OBJ,
  OR_OBJ,
  LOAD,
  LABEL,
};
struct Object {
  Type type;
  union {
    double complex z;
    mpq_t rational;
    bool boolean;
    size_t index;
    char *symbol;
    /* char *symbol_vertical; */
    uint8_t byte;
    size_t len;
    uint8_t *bytes;
    gunichar ch;
    fn_obj_of_obj proc;
    FILE *port;

    void *cont;
  };
};

Object object_copy(Object o);
void object_free(Object *o_ptr);

void object_write_stdout(Object o);

Object c_str_to_datum(char const *s);

extern Object env, val, cont, proc, argl;
extern Object empty, undef;

Object cons(Object o1, Object o2);
void save(Object o);
Object restore();

Object lookup_var_val(Object o1);
Object def_var_val(Object var);
Object set_var_val(Object var);
Object extend_environment(Object params);

Object make_compiled_procedure(void *label);
Object compiled_procedure_entry();
Object compiled_procedure_env();

Object apply_proc();
Object apply_argl();
