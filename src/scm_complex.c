#include "scm_complex.h"

static mpf_t opf1, opf2;
Object complex_new(char const *real, char const *imag, int base) {
  mpf_set_str(opf1, real, base);
  mpf_set_str(opf2, imag, base);
  Object out = {.type = COMPLEX};
  mpc_init2(out.z, prec);
  mpc_set_f_f(out.z, opf1, opf2, MPC_RNDNN);
  return out;
}
static Object copy(Object o) {
  Object out = {.type = COMPLEX};
  mpc_init2(out.z, prec);
  mpc_set(out.z, o.z, MPC_RNDNN);
  return out;
}
static void complex_free(Object *ptr) { mpc_clear(ptr->z); }
/* object.h */
static bool eqv_p(Object o1, Object o2) { return mpc_cmp(o1.z, o2.z) == 0; }
static mpfr_t opfr1, opfr2;
static void write(Object o, FILE *s) {
  if (mpfr_inf_p(mpc_realref(o.z))) {
    fprintf(s, "%cinf.0", mpfr_sgn(mpc_realref(o.z)) > 0 ? '+' : '-');
  } else if (mpfr_nan_p(mpc_realref(o.z))) {
    fprintf(s, "+nan.0");
  } else {
    mpfr_get_f(opf1, mpc_realref(o.z), MPFR_RNDN);
    gmp_fprintf(s, "%.*Fg", prec, opf1);
    mpfr_round(opfr1, mpc_realref(o.z));
    if (mpfr_equal_p(opfr1, mpc_realref(o.z))) {
      fprintf(s, ".0");
    }
  }
  if (!mpfr_zero_p(mpc_imagref(o.z))) {
    if (mpfr_inf_p(mpc_imagref(o.z))) {
      fprintf(s, "%cinf.0", mpfr_sgn(mpc_imagref(o.z)) > 0 ? '+' : '-');
    } else if (mpfr_nan_p(mpc_imagref(o.z))) {
      fprintf(s, "+nan.0");
    } else {
      mpfr_get_f(opf1, mpc_imagref(o.z), MPFR_RNDN);
      gmp_fprintf(s, "%+.*Fg", prec, opf1);
      mpfr_round(opfr1, mpc_imagref(o.z));
      if (mpfr_equal_p(opfr1, mpc_imagref(o.z))) {
        fprintf(s, ".0");
      }
    }
    fprintf(s, "i");
  }
}

/* number.h */
static bool integer_p(Object o) {
  if (mpfr_zero_p(mpc_imagref(o.z))) {
    mpfr_round(opfr1, mpc_realref(o.z));
    return mpfr_equal_p(opfr1, mpc_realref(o.z));
  }
  return false;
}
static bool exact_p(Object o) { return false; }
static bool finite_p(Object o) {
  return !mpfr_inf_p(mpc_realref(o.z)) && !mpfr_inf_p(mpc_imagref(o.z)) &&
         !mpfr_nan_p(mpc_realref(o.z)) && !mpfr_nan_p(mpc_imagref(o.z));
}
static bool infinite_p(Object o) {
  return mpfr_inf_p(mpc_realref(o.z)) || mpfr_inf_p(mpc_imagref(o.z));
}
static bool nan_p(Object o) {
  return mpfr_nan_p(mpc_realref(o.z)) || mpfr_nan_p(mpc_imagref(o.z));
}
static bool lt(Object o1, Object o2) {
  return mpfr_less_p(mpc_realref(o1.z), mpc_realref(o2.z));
}
static Object math_equal(Object o1, Object o2) {
  return mpc_cmp(o1.z, o2.z) == 0 ? boolean_true : boolean_false;
}
static Object add(Object o1, Object o2) {
  Object out = {.type = COMPLEX};
  mpc_init2(out.z, prec);
  mpc_add(out.z, o1.z, o2.z, MPC_RNDNN);
  return out;
}
static Object mul(Object o1, Object o2) {
  Object out = {.type = COMPLEX};
  mpc_init2(out.z, prec);
  mpc_mul(out.z, o1.z, o2.z, MPC_RNDNN);
  return out;
}
static Object sub(Object o1, Object o2) {
  Object out = {.type = COMPLEX};
  mpc_init2(out.z, prec);
  mpc_sub(out.z, o1.z, o2.z, MPC_RNDNN);
  return out;
}
static Object complex_div(Object o1, Object o2) {
  Object out = {.type = COMPLEX};
  mpc_init2(out.z, prec);
  mpc_div(out.z, o1.z, o2.z, MPC_RNDNN);
  return out;
}
static Object complex_floor(Object o) {
  Object out = {.type = COMPLEX};
  mpc_init2(out.z, prec);
  mpfr_floor(opfr1, mpc_realref(o.z));
  mpc_set_fr(out.z, opfr1, MPC_RNDNN);
  return out;
}
static Object ceiling(Object o) {
  Object out = {.type = COMPLEX};
  mpc_init2(out.z, prec);
  mpfr_ceil(opfr1, mpc_realref(o.z));
  mpc_set_fr(out.z, opfr1, MPC_RNDNN);
  return out;
}
static Object truncate(Object o) {
  Object out = {.type = COMPLEX};
  mpc_init2(out.z, prec);
  mpfr_trunc(opfr1, mpc_realref(o.z));
  mpc_set_fr(out.z, opfr1, MPC_RNDNN);
  return out;
}
static Object complex_round(Object o) {
  Object out = {.type = COMPLEX};
  mpc_init2(out.z, prec);
  mpfr_round(opfr1, mpc_realref(o.z));
  mpc_set_fr(out.z, opfr1, MPC_RNDNN);
  return out;
}
static Object complex_sqrt(Object o) {
  Object out = {.type = COMPLEX};
  mpc_init2(out.z, prec);
  mpc_sqrt(out.z, o.z, MPC_RNDNN);
  return out;
}
static Object inexact(Object o) { return copy(o); }

static Object even_p(Object o) {
  mpfr_div_ui(opfr1, mpc_realref(o.z), 2, MPFR_RNDN);
  return mpfr_zero_p(opfr1) ? boolean_true : boolean_false;
}
static Object exact(Object o) {
  Object out = {.type = RATIONAL};
  mpq_init(out.rational);
  mpfr_get_f(opf1, mpc_realref(o.z), MPFR_RNDN);
  mpq_set_f(out.rational, opf1);
  return out;
}
static Object expt(Object o1, Object o2) {
  Object out = {.type = COMPLEX};
  mpc_init2(out.z, prec);
  mpc_pow(out.z, o1.z, o2.z, MPC_RNDNN);
  return out;
}
static Object to_char(Object o) {
  return (Object){.type = CHAR, .ch = mpfr_get_ui(mpc_realref(o.z), MPFR_RNDN)};
}
static Object negative_p(Object o) {
  return mpfr_sgn(mpc_realref(o.z)) < 0 ? boolean_true : boolean_false;
}

static Object odd_p(Object o) {
  mpfr_div_ui(opfr1, mpc_realref(o.z), 2, MPFR_RNDN);
  return mpfr_zero_p(opfr1) ? boolean_false : boolean_true;
}
static Object positive_p(Object o) {
  return mpfr_sgn(mpc_realref(o.z)) > 0 ? boolean_true : boolean_false;
}
static Object square(Object o) {
  Object out = {.type = COMPLEX};
  mpc_init2(out.z, prec);
  mpc_pow_ui(out.z, o.z, 2, MPC_RNDNN);
  return out;
}
static Object angle(Object o) {
  Object out = {.type = COMPLEX};
  mpc_init2(out.z, prec);
  mpc_arg(opfr1, o.z, MPFR_RNDN);
  mpc_set_fr(out.z, opfr1, MPC_RNDNN);
  return out;
}
static Object imag_part(Object o) {
  Object out = {.type = COMPLEX};
  mpc_init2(out.z, prec);
  mpc_set_fr(out.z, mpc_imagref(o.z), MPC_RNDNN);
  return out;
}
static Object magnitude(Object o) {
  Object out = {.type = COMPLEX};
  mpc_init2(out.z, prec);
  mpc_abs(opfr1, o.z, MPFR_RNDN);
  mpc_set_fr(out.z, opfr1, MPC_RNDNN);
  return out;
}
static Object make_polar(Object o1, Object o2) {
  mpfr_cos(opfr1, mpc_realref(o1.z), MPFR_RNDN);
  mpfr_sin(opfr2, mpc_realref(o2.z), MPFR_RNDN);
  Object out = {.type = COMPLEX};
  mpc_init2(out.z, prec);
  mpc_set_fr_fr(out.z, opfr1, opfr2, MPC_RNDNN);
  return out;
}
static Object make_rectangular(Object o1, Object o2) {
  Object out = {.type = COMPLEX};
  mpc_init2(out.z, prec);
  mpc_set_fr_fr(out.z, mpc_realref(o1.z), mpc_realref(o2.z), MPC_RNDNN);
  return out;
}
static Object real_part(Object o) {
  Object out = {.type = COMPLEX};
  mpc_init2(out.z, prec);
  mpc_set_fr(out.z, mpc_realref(o.z), MPC_RNDNN);
  return out;
}

void complex_init() {
  fn_of_obj_ptr of_obj_ptr_ks[] = {object_free, NULL};
  fn_of_obj_ptr of_obj_ptr_vs[] = {complex_free, NULL};
  for (size_t i = 0; of_obj_ptr_ks[i] != NULL; i++) {
    put_of_obj_ptr(of_obj_ptr_ks[i], COMPLEX, of_obj_ptr_vs[i]);
  }
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
  fn_obj_of_obj bool_of_obj_ks[] = {object_integer_p, number_exact_p,
                                    number_finite_p,  number_infinite_p,
                                    number_nan_p,     NULL};
  fn_bool_of_obj bool_of_obj_vs[] = {integer_p,  exact_p, finite_p,
                                     infinite_p, nan_p,   NULL};
  for (size_t i = 0; bool_of_obj_ks[i] != NULL; i++) {
    put_bool_of_obj(bool_of_obj_ks[i], COMPLEX, bool_of_obj_vs[i]);
  }
  fn_obj_of_obj obj_of_obj_obj_ks[] = {number_math_equal,
                                       number_add,
                                       number_mul,
                                       number_sub,
                                       number_div,
                                       number_expt,
                                       number_make_polar,
                                       number_make_rectangular,
                                       NULL};
  fn_obj_of_obj_obj obj_of_obj_obj_vs[] = {
      math_equal,       add, mul, sub, complex_div, expt, make_polar,
      make_rectangular, NULL};
  for (size_t i = 0; obj_of_obj_obj_ks[i] != NULL; i++) {
    put_obj_of_obj_obj(obj_of_obj_obj_ks[i], COMPLEX, COMPLEX,
                       obj_of_obj_obj_vs[i]);
  }
  fn_obj_of_obj obj_of_obj_ks[] = {object_copy,
                                   number_ceiling,
                                   number_inexact,
                                   number_even_p,
                                   number_exact,
                                   number_floor,
                                   number_to_char,
                                   number_negative_p,
                                   number_odd_p,
                                   number_positive_p,
                                   number_round,
                                   number_square,
                                   number_truncate,
                                   number_sqrt,
                                   number_angle,
                                   number_imag_part,
                                   number_magnitude,
                                   number_real_part,
                                   NULL};
  fn_obj_of_obj obj_of_obj_vs[] = {
      copy,          ceiling,   inexact,    even_p,       exact,
      complex_floor, to_char,   negative_p, odd_p,        positive_p,
      complex_round, square,    truncate,   complex_sqrt, angle,
      imag_part,     magnitude, real_part,  NULL};
  for (size_t i = 0; obj_of_obj_ks[i] != NULL; i++) {
    put_obj_of_obj(obj_of_obj_ks[i], COMPLEX, obj_of_obj_vs[i]);
  }
  mpf_inits(opf1, opf2, NULL);
  mpfr_inits(opfr1, opfr2, NULL);
}
