#pragma once
/** \file  */
#include "object.h"

extern Object symbol_quote;
Object symbol_new(char const *s);
Object symbol_vertical_new(char const *s);

Object symbol_math_equal_p(Object args);

void symbol_init();
