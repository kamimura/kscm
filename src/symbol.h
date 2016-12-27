#pragma once
/** \file  */
#include "object.h"

extern Object symbol_quote;
Object symbol_new(char const *s);
Object symbol_vertical_new(char const *s);

Object symbol_math_equal_p(Object args);

extern Object symbol_to_string(Object args);
extern Object string_to_symbol(Object args);

void symbol_init();
