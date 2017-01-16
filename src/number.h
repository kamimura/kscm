#pragma once
/** \file  */
#include "object.h"
extern fn_obj_of_obj bool_of_obj_ks[];
extern fn_obj_of_obj obj_of_obj_obj_ks[];
extern fn_obj_of_obj obj_of_obj_ks[];

Object number_exact_p(Object args);
Object number_finite_p(Object args);
Object number_infinite_p(Object args);
Object number_nan_p(Object args);
Object number_lt(Object args);
Object number_math_equal(Object args);
Object number_add(Object args);
Object number_mul(Object args);
Object number_sub(Object args);
Object number_div(Object args);
Object number_gcd(Object args);
Object number_lcm(Object args);
Object number_mul(Object args);
Object number_gcd(Object args);
Object number_abs(Object args);
Object number_inexact(Object args);
Object number_negative_p(Object args);
Object number_numerator(Object args);
Object number_denominator(Object args);
Object number_floor(Object args);
Object number_ceiling(Object args);
Object number_sqrt(Object args);
Object number_even_p(Object args);
Object number_exact(Object args);
Object number_expt(Object args);
Object number_to_char(Object args);
Object number_odd_p(Object args);
Object number_positive_p(Object args);
Object number_round(Object args);
Object number_square(Object args);
Object number_truncate(Object args);

extern Object number_to_string(Object args);
void number_init();
