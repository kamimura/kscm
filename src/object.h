#pragma once
/** \file  */

#include "kscm.h"

typedef bool (*fn_bool_of_obj)(Object);
typedef bool (*fn_bool_of_obj_obj)(Object, Object);
typedef Object (*fn_obj_of_obj_obj)(Object, Object);
typedef void (*fn_of_obj_file)(Object, FILE *);
typedef void (*fn_of_obj_ptr)(Object *o_ptr);
typedef void (*fn_of_obj_obj)(Object, Object);

#include "boolean.h" // boolean_true, boolean_false
#include "memory.h"

#include "env.h"    // def_var_val
#include "symbol.h" // symbol_new

extern Object eof_obj;
extern Object none;
extern FILE *cur_input;
extern FILE *cur_output;

fn_bool_of_obj get_bool_of_obj(fn_obj_of_obj k1, Object k2);
fn_bool_of_obj_obj get_bool_of_obj_obj(fn_obj_of_obj k1, Object k2, Object k3);

void put_bool_of_obj_obj(fn_obj_of_obj k1, Type k2, Type k3,
                         fn_bool_of_obj_obj v);
void put_bool_of_obj(fn_obj_of_obj k1, Type k2, fn_bool_of_obj v);

void put_obj_of_obj_obj(fn_obj_of_obj k1, Type k2, Type k3,
                        fn_obj_of_obj_obj v);
fn_obj_of_obj_obj get_obj_of_obj_obj(fn_obj_of_obj k1, Object k2, Object k3);
void put_of_obj_file(fn_obj_of_obj k1, Type k2, fn_of_obj_file v);

void put_obj_of_obj(fn_obj_of_obj k1, Type k2, fn_obj_of_obj);
fn_obj_of_obj get_obj_of_obj(fn_obj_of_obj k1, Object k2);

void put_of_obj_ptr(fn_of_obj_ptr k1, Type k2, fn_of_obj_ptr v);

Object object_eqv_p(Object args);
Object object_eq_p(Object args);

/*  Numbers */
Object object_integer_p(Object args);

Object object_write(Object args);
extern FILE *yyout;
Object object_display(Object args);
Object object_symbol_p(Object args);

void object_writeln_stdout(Object o);
void object_write_stderr(Object o);

void object_init();

size_t argl_length();
void argl_length_error(const char *s);
void check_argl_length(const char *s, size_t len);

void check_argl_type(const char *s, Object o, Type t);
void argl_type_error(const char *s);
