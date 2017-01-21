#include "number.h"

/* mpfr_prec_t prec = 53; */
mpfr_prec_t prec = 128;

static Object apply_bool_of_obj(fn_obj_of_obj fn, Object args) {
  Object o = carref(args);
  fn_bool_of_obj fn0 = get_bool_of_obj(fn, o);
  if (!fn0) {
    fprintf(stderr, "%s: %s type: %d %p\n", __FILE__, __FUNCTION__, o.type, fn);
    object_write_stdout(args);
    puts("");
    exit(1);
  }
  return fn0(o) ? boolean_true : boolean_false;
}
Object number_exact_p(Object args) {
  return apply_bool_of_obj(number_exact_p, args);
}
Object number_finite_p(Object args) {
  return apply_bool_of_obj(number_finite_p, args);
}
Object number_infinite_p(Object args) {
  return apply_bool_of_obj(number_finite_p, args);
}
Object number_nan_p(Object args) {
  return apply_bool_of_obj(number_nan_p, args);
}
Object number_lt(Object args) {
  Object o1 = carref(args);
  Object o2 = carref(cdrref(args));
  fn_bool_of_obj_obj fn = get_bool_of_obj_obj(number_lt, o1, o2);
  if (fn == NULL) {
    fprintf(stderr, "%s: %s type: %d %d func:%p\n", __FILE__, __FUNCTION__,
            o1.type, o2.type, fn);
    object_write_stdout(args);
    puts("");
    exit(1);
  }
  return fn(o1, o2) ? boolean_true : boolean_false;
}
static Object apply_obj_of_obj_obj(fn_obj_of_obj fn, Object args) {
  Object o1 = carref(args);
  Object o2 = carref(cdrref(args));
  fn_obj_of_obj_obj fn0 = get_obj_of_obj_obj(fn, o1, o2);
  if (fn0 == NULL) {
    fprintf(stderr, "apply_obj_of_obj_obj\n");
    exit(1);
  }
  return fn0(o1, o2);
}
Object number_math_equal(Object args) {
  return apply_obj_of_obj_obj(number_math_equal, args);
}
Object number_add(Object args) {
  return apply_obj_of_obj_obj(number_add, args);
}
Object number_mul(Object args) {
  return apply_obj_of_obj_obj(number_mul, args);
}
Object number_sub(Object args) {
  return apply_obj_of_obj_obj(number_sub, args);
}
Object number_div(Object args) {
  return apply_obj_of_obj_obj(number_div, args);
}
Object number_gcd(Object args) {
  return apply_obj_of_obj_obj(number_gcd, args);
}
static Object apply_obj_of_obj(fn_obj_of_obj fn, Object args) {
  Object o = carref(argl);
  fn_obj_of_obj fn0 = get_obj_of_obj(fn, o);
  return fn0(o);
}

Object number_numerator(Object args) {
  return apply_obj_of_obj(number_numerator, args);
}
Object number_denominator(Object args) {
  return apply_obj_of_obj(number_denominator, args);
}
Object number_ceiling(Object args) {
  return apply_obj_of_obj(number_ceiling, args);
}

Object number_sqrt(Object args) { return apply_obj_of_obj(number_sqrt, args); }
Object number_even_p(Object args) {
  return apply_obj_of_obj(number_even_p, args);
}
Object number_exact(Object args) {
  return apply_obj_of_obj(number_exact, args);
}
Object number_expt(Object args) {
  return apply_obj_of_obj_obj(number_expt, args);
}
Object number_floor(Object args) {
  return apply_obj_of_obj(number_floor, args);
}
Object number_inexact(Object args) {
  return apply_obj_of_obj(number_inexact, args);
}
Object number_to_char(Object args) {
  return apply_obj_of_obj(number_to_char, args);
}
Object number_lcm(Object args) {
  return apply_obj_of_obj_obj(number_lcm, args);
}
Object number_negative_p(Object args) {
  return apply_obj_of_obj(number_negative_p, args);
}
Object number_odd_p(Object args) {
  return apply_obj_of_obj(number_odd_p, args);
}
Object number_positive_p(Object args) {
  return apply_obj_of_obj(number_positive_p, args);
}
Object number_round(Object args) {
  return apply_obj_of_obj(number_round, args);
}
Object number_square(Object args) {
  return apply_obj_of_obj(number_square, args);
}
Object number_truncate(Object args) {
  return apply_obj_of_obj(number_truncate, args);
}
/* complex library */
Object number_angle(Object args) {
  return apply_obj_of_obj(number_angle, args);
}
Object number_imag_part(Object args) {
  return apply_obj_of_obj(number_imag_part, args);
}
Object number_magnitude(Object args) {
  return apply_obj_of_obj(number_magnitude, args);
}
Object number_make_polar(Object args) {
  return apply_obj_of_obj_obj(number_make_polar, args);
}
Object number_make_rectangular(Object args) {
  return apply_obj_of_obj_obj(number_make_rectangular, args);
}
Object number_real_part(Object args) {
  return apply_obj_of_obj(number_real_part, args);
}

#include "env.h"
#include "symbol.h" // symbol_new
void number_init() {
  char const *names[] = {"+",
                         "-",
                         "<",
                         "number->string",
                         "=",
                         "c-=",
                         "c-+",
                         "c-*",
                         "c--",
                         "c-<",
                         "c-/",
                         "inexact",
                         "exact?",
                         "c-ceiling",
                         "c-denominator",
                         "c-even?",
                         "c-exact",
                         "c-exact?",
                         "c-expt",
                         "c-floor",
                         "c-gcd",
                         "c-inexact",
                         "c-integer->char",
                         "c-lcm",
                         "c-negative?",
                         "c-number->string",
                         "c-numerator",
                         "c-odd?",
                         "c-positive?",
                         "c-round",
                         "c-square",
                         "c-truncate",
                         "c-angle",
                         "c-imag-part",
                         "c-magnitude",
                         "c-make-polar",
                         "c-make-rectangular",
                         "c-real-part",
                         NULL};
  fn_obj_of_obj procs[] = {number_add,
                           number_sub,
                           number_lt,
                           number_to_string,
                           number_math_equal,
                           number_math_equal,
                           number_add,
                           number_mul,
                           number_sub,
                           number_lt,
                           number_div,
                           number_inexact,
                           number_exact_p,
                           number_ceiling,
                           number_denominator,
                           number_even_p,
                           number_exact,
                           number_exact_p,
                           number_expt,
                           number_floor,
                           number_gcd,
                           number_inexact,
                           number_to_char,
                           number_lcm,
                           number_negative_p,
                           number_to_string,
                           number_numerator,
                           number_odd_p,
                           number_positive_p,
                           number_round,
                           number_square,
                           number_truncate,
                           number_angle,
                           number_imag_part,
                           number_magnitude,
                           number_make_polar,
                           number_make_rectangular,
                           number_real_part,
                           NULL};
  for (size_t i = 0; names[i] != NULL; i++) {
    val = (Object){.type = PROC, .proc = procs[i]};
    def_var_val(symbol_new(names[i]));
  }
}
