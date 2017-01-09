#include "rational.h"

Object rational_new(char const *s, int base) {
  Object o = {.type = RATIONAL};
  mpq_init(o.rational);
  mpq_set_str(o.rational, s, base);
  mpq_canonicalize(o.rational);
  return o;
}
Object rational_copy(Object o) {
  Object out = {.type = RATIONAL};
  mpq_init(out.rational);
  mpq_set(out.rational, o.rational);
  return out;
}
static void rational_free(Object *o_ptr) { mpq_clear(o_ptr->rational); }

static bool eqv_p(Object o1, Object o2) {
  return mpq_equal(o1.rational, o2.rational);
}
static bool exact_p(Object o) { return true; }
static bool integer_p(Object o) {
  return mpz_cmp_ui(mpq_denref(o.rational), 1) == 0;
}
static bool finite_p(Object o) { return true; }
static bool infinite_p(Object o) { return false; }
static bool nan_p(Object o) { return false; }
static bool negative_p(Object o) {
  return mpq_sgn(o.rational) < 0 ? true : false;
}
static Object math_equal(Object o1, Object o2) {
  return mpq_equal(o1.rational, o2.rational) ? boolean_true : boolean_false;
}
static bool lt(Object o1, Object o2) {
  return mpq_cmp(o1.rational, o2.rational) < 0 ? true : false;
}
static Object apply_void_mp_mp_mp(void (*fn)(mpq_ptr, mpq_srcptr, mpq_srcptr),
                                  Object o1, Object o2) {
  Object o = {.type = RATIONAL};
  mpq_init(o.rational);
  fn(o.rational, o1.rational, o2.rational);
  return o;
}
static Object add(Object o1, Object o2) {
  return apply_void_mp_mp_mp(mpq_add, o1, o2);
}
static Object mul(Object o1, Object o2) {
  return apply_void_mp_mp_mp(mpq_mul, o1, o2);
}
static Object sub(Object o1, Object o2) {
  return apply_void_mp_mp_mp(mpq_sub, o1, o2);
}
static Object rational_div(Object o1, Object o2) {
  return apply_void_mp_mp_mp(mpq_div, o1, o2);
}
static Object gcd(Object o1, Object o2) {
  Object o = {.type = RATIONAL};
  mpq_init(o.rational);
  mpz_gcd(mpq_numref(o.rational), mpq_numref(o1.rational),
          mpq_numref(o2.rational));
  mpz_set_ui(mpq_denref(o.rational), 1);
  return o;
}
static Object lcm(Object o1, Object o2) {
  Object o = {.type = RATIONAL};
  mpq_init(o.rational);
  mpz_lcm(mpq_numref(o.rational), mpq_numref(o1.rational),
          mpq_numref(o2.rational));
  mpz_set_ui(mpq_denref(o.rational), 1);
  return o;
}

static Object numerator(Object o) {
  Object out = {.type = RATIONAL};
  mpq_init(out.rational);
  mpq_set_z(out.rational, mpq_numref(o.rational));
  return o;
}
static Object denominator(Object o) {
  Object out = {.type = RATIONAL};
  mpq_init(out.rational);
  mpq_set_z(out.rational, mpq_denref(o.rational));
  return o;
}
static Object rational_floor(Object o) {
  Object out = {.type = RATIONAL};
  mpq_init(out.rational);
  mpz_fdiv_q(mpq_numref(out.rational), mpq_numref(o.rational),
             mpq_denref(o.rational));
  mpz_set_ui(mpq_denref(out.rational), 1);
  return o;
}
static Object ceiling(Object o) {
  Object out = {.type = RATIONAL};
  mpq_init(out.rational);
  mpz_cdiv_q(mpq_numref(out.rational), mpq_numref(o.rational),
             mpq_denref(o.rational));
  mpz_set_ui(mpq_denref(out.rational), 1);
  return o;
}
static Object truncate(Object o) {
  Object out = {.type = RATIONAL};
  mpq_init(out.rational);
  mpz_tdiv_q(mpq_numref(out.rational), mpq_numref(o.rational),
             mpq_denref(o.rational));
  mpz_set_ui(mpq_denref(out.rational), 1);
  return o;
}
static Object rational_round(Object o) {
  double d = round(mpq_get_d(o.rational));
  Object out = {.type = RATIONAL};
  mpq_init(out.rational);
  mpq_set_d(out.rational, d);
  return out;
}
static Object to_complex(Object o) {
  return (Object){.type = COMPLEX, .z = mpq_get_d(o.rational)};
}
static Object inexact(Object o) {
  return (Object){.type = COMPLEX, .z = mpq_get_d(o.rational)};
}
static Object rational_sqrt(Object o) {
  if (mpz_perfect_square_p(mpq_numref(o.rational)) &&
      mpz_perfect_square_p(mpq_denref(o.rational))) {
    Object out = {.type = RATIONAL};
    mpq_init(out.rational);
    mpz_sqrt(mpq_numref(out.rational), mpq_numref(o.rational));
    mpz_sqrt(mpq_denref(out.rational), mpq_denref(o.rational));
    return out;
  }
  Object o0 = to_complex(o);
  fn_obj_of_obj fn = get_obj_of_obj(number_sqrt, o0);
  Object out = fn(o0);
  rational_free(&o0);
  return out;
}
static void write(Object o, FILE *port) { mpq_out_str(port, 10, o.rational); }
void rational_init() {
  fn_obj_of_obj ks1[] = {object_eqv_p, object_eq_p, number_lt, NULL};
  fn_bool_of_obj_obj vs1[] = {eqv_p, eqv_p, lt, NULL};
  for (size_t i = 0; ks1[i] != NULL; i++) {
    put_bool_of_obj_obj(ks1[i], RATIONAL, RATIONAL, vs1[i]);
  }

  fn_obj_of_obj bool_of_obj_ks[] = {object_integer_p,
                                    number_exact_p,
                                    number_finite_p,
                                    number_infinite_p,
                                    number_nan_p,
                                    number_negative_p,
                                    NULL};

  fn_bool_of_obj bool_of_obj_vs[] = {
      integer_p, exact_p, finite_p, infinite_p, nan_p, negative_p, NULL};
  for (size_t i = 0; bool_of_obj_ks[i] != NULL; i++) {
    put_bool_of_obj(bool_of_obj_ks[i], RATIONAL, bool_of_obj_vs[i]);
  }
  fn_obj_of_obj obj_of_obj_obj_ks[] = {
      number_math_equal, number_add, number_mul, number_sub,
      number_div,        number_gcd, number_lcm, NULL};
  fn_obj_of_obj_obj obj_of_obj_obj_vs[] = {math_equal,   add, mul, sub,
                                           rational_div, gcd, lcm, NULL};
  for (size_t i = 0; obj_of_obj_obj_ks[i] != NULL; i++) {
    put_obj_of_obj_obj(obj_of_obj_obj_ks[i], RATIONAL, RATIONAL,
                       obj_of_obj_obj_vs[i]);
  }
  fn_obj_of_obj of_obj_file_ks[] = {object_write, NULL};
  fn_of_obj_file of_obj_file_vs[] = {write, NULL};
  for (size_t i = 0; of_obj_file_ks[i] != NULL; i++) {
    put_of_obj_file(of_obj_file_ks[i], RATIONAL, of_obj_file_vs[i]);
  }
  fn_obj_of_obj obj_of_obj_ks[] = {object_copy,        number_numerator,
                                   number_denominator, number_floor,
                                   number_ceiling,     number_truncate,
                                   number_round,       number_sqrt,
                                   number_inexact,     NULL};
  fn_obj_of_obj obj_of_obj_vs[] = {
      rational_copy, numerator,      denominator,   rational_floor, ceiling,
      truncate,      rational_round, rational_sqrt, inexact,        NULL};
  for (size_t i = 0; obj_of_obj_ks[i] != NULL; i++) {
    put_obj_of_obj(obj_of_obj_ks[i], RATIONAL, obj_of_obj_vs[i]);
  }
  fn_of_obj_ptr of_obj_ptr_ks[] = {object_free, NULL};
  fn_of_obj_ptr of_obj_ptr_vs[] = {rational_free, NULL};
  for (size_t i = 0; of_obj_ptr_ks[i] != NULL; i++) {
    put_of_obj_ptr(of_obj_ptr_ks[i], RATIONAL, of_obj_ptr_vs[i]);
  }
}
