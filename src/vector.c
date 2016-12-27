#include "vector.h"

static bool eqv_p(Object o1, Object o2) { return o1.index == o2.index; }
void vector_init() {
  fn_obj_of_obj ks1[] = {object_eqv_p, object_eq_p, NULL};
  fn_bool_of_obj_obj vs1[] = {eqv_p, eqv_p, NULL};
  for (size_t i = 0; ks1[i] != NULL; i++) {
    put_bool_of_obj_obj(ks1[i], VECTOR, VECTOR, vs1[i]);
  }
}
