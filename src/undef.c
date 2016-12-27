#include "undef.h"

static bool eqv_p(Object o1, Object o2) { return true; }
static bool eq_p(Object o1, Object o2) { return true; }
static void write(Object o, FILE *s) { fprintf(s, "#<undefined>"); }
void undef_init() {
  fn_obj_of_obj bool_of_obj_obj_ks[] = {object_eqv_p, object_eq_p, NULL};
  fn_bool_of_obj_obj bool_of_obj_obj_vs[] = {eqv_p, eq_p, NULL};
  for (size_t i = 0; bool_of_obj_obj_ks[i] != NULL; i++) {
    put_bool_of_obj_obj(bool_of_obj_obj_ks[i], UNDEF, UNDEF,
                        bool_of_obj_obj_vs[i]);
  }
  fn_obj_of_obj of_obj_file_ks[] = {object_write, NULL};
  fn_of_obj_file of_obj_file_vs[] = {write, NULL};
  for (size_t i = 0; of_obj_file_ks[i] != NULL; i++) {
    put_of_obj_file(of_obj_file_ks[i], UNDEF, of_obj_file_vs[i]);
  }
}
