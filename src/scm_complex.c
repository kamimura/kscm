#include "scm_complex.h"

#include <stdlib.h> // strtod

Object complex_new(char *const real, char *const imag, int base) {
  char *endptr;
  double a = strtod(real, &endptr);
  double b = strtod(imag, &endptr);
  return (Object){.type = COMPLEX, .z = CMPLX(a, b)};
}

/* object.h */
static bool eqv_p(Object o1, Object o2) { return o1.z == o2.z; }
static void write(Object o, FILE *s) {
  if (isinf(creal(o.z))) {
    fprintf(s, "%+f.0", cimag(o.z));
  } else if (isnan(creal(o.z))) {
    fprintf(s, "+nan.0");
  } else {
    fprintf(s, "%f", creal(o.z));
  }
  if (cimag(o.z) != 0) {
    if (isinf(cimag(o.z)) || isnan(cimag(o.z))) {
      fprintf(s, "%+f.0", cimag(o.z));
    } else {
      fprintf(s, "%+f", cimag(o.z));
    }
    fprintf(s, "i");
  }
}

/* number.h */
static bool exact_p(Object o) { return false; }
static bool finite_p(Object o) {
  return !isinf(creal(o.z)) && !isinf(cimag(o.z)) && !isnan(creal(o.z)) &&
         !isnan(cimag(o.z));
}
static bool infinite_p(Object o) {
  return isinf(creal(o.z)) || isinf(cimag(o.z));
}
static bool nan_p(Object o) { return isnan(creal(o.z)) || isnan(cimag(o.z)); }
static bool negative_p(Object o) {
  if (cimag(o.z) == 0) {
    return creal(o.z) < 0 ? true : false;
  }
  fprintf(stderr, "ERROR: %s\n", __FUNCTION__);
  write(o, stderr);
  puts("");
  exit(1);
}
static bool lt(Object o1, Object o2) {
  if (cimag(o1.z) == 0 && cimag(o2.z) == 0) {
    return creal(o1.z) < creal(o2.z) ? true : false;
  }
  fprintf(stderr, "ERROR: %s\n", __FUNCTION__);
  puts("");
  exit(1);
}
static Object math_equal(Object o1, Object o2) {
  return o1.z == o2.z ? boolean_true : boolean_false;
}
static Object add(Object o1, Object o2) {
  return (Object){.type = COMPLEX, .z = o1.z + o2.z};
}
static Object mul(Object o1, Object o2) {
  return (Object){.type = COMPLEX, .z = o1.z * o2.z};
}
static Object sub(Object o1, Object o2) {
  return (Object){.type = COMPLEX, .z = o1.z - o2.z};
}
static Object complex_div(Object o1, Object o2) {
  return (Object){.type = COMPLEX, .z = o1.z / o2.z};
}
static Object apply_d_of_d(double (*fn)(double), Object o) {
  return (Object){.type = COMPLEX, .z = fn(creal(o.z))};
}
static Object complex_floor(Object o) { return apply_d_of_d(floor, o); }
static Object ceiling(Object o) { return apply_d_of_d(ceil, o); }
static Object truncate(Object o) { return apply_d_of_d(trunc, o); }
static Object complex_round(Object o) { return apply_d_of_d(round, o); }
static Object complex_sqrt(Object o) {
  return (Object){.type = COMPLEX, .z = csqrt(o.z)};
}
static Object exact(Object o) {
  Object out = {.type = RATIONAL};
  mpq_init(out.rational);
  mpq_set_d(out.rational, creal(o.z));
  return out;
}

void complex_init() {
  fn_obj_of_obj ks1[] = {object_eqv_p, object_eq_p, number_lt, NULL};
  fn_bool_of_obj_obj vs1[] = {eqv_p, eqv_p, lt, NULL};
  for (size_t i = 0; ks1[i] != NULL; i++) {
    put_bool_of_obj_obj(ks1[i], COMPLEX, COMPLEX, vs1[i]);
  }
  fn_obj_of_obj of_obj_file_ks[] = {object_write, NULL};
  fn_of_obj_file of_obj_file_vs[] = {write, NULL};
  for (size_t i = 0; of_obj_file_ks[i] != NULL; i++) {
    put_of_obj_file(of_obj_file_ks[i], COMPLEX, of_obj_file_vs[i]);
  }
  /* number.h */
  fn_obj_of_obj bool_of_obj_ks[] = {number_exact_p,    number_finite_p,
                                    number_infinite_p, number_nan_p,
                                    number_negative_p, NULL};
  fn_bool_of_obj bool_of_obj_vs[] = {exact_p, finite_p,   infinite_p,
                                     nan_p,   negative_p, NULL};
  for (size_t i = 0; bool_of_obj_ks[i] != NULL; i++) {
    put_bool_of_obj(bool_of_obj_ks[i], COMPLEX, bool_of_obj_vs[i]);
  }
  fn_obj_of_obj obj_of_obj_obj_ks[] = {
      number_math_equal, number_add, number_mul, number_sub, number_div, NULL};
  fn_obj_of_obj_obj obj_of_obj_obj_vs[] = {math_equal, add,         mul,
                                           sub,        complex_div, NULL};
  for (size_t i = 0; obj_of_obj_obj_ks[i] != NULL; i++) {
    put_obj_of_obj_obj(obj_of_obj_obj_ks[i], COMPLEX, COMPLEX,
                       obj_of_obj_obj_vs[i]);
  }
  fn_obj_of_obj obj_of_obj_ks[] = {
      number_floor, number_ceiling, number_truncate,
      number_round, number_sqrt,    number_exact,
      NULL};
  fn_obj_of_obj obj_of_obj_vs[] = {complex_floor, ceiling,      truncate,
                                   complex_round, complex_sqrt, exact,
                                   NULL};
  for (size_t i = 0; obj_of_obj_ks[i] != NULL; i++) {
    put_obj_of_obj(obj_of_obj_ks[i], COMPLEX, obj_of_obj_vs[i]);
  }
}
