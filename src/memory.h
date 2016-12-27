#pragma once
/** \file  */
#include "object.h"

Object cons(Object o1, Object o2);
Object carref(Object o);
Object cdrref(Object o);
Object car(Object o);
Object cdr(Object o);
void set_car(Object o1, Object o2);
void set_cdr(Object o1, Object o2);

extern Object yacc_obj, cmd_line_list;

void memory_init();
