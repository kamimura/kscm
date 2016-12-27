#include "byte.h"

Object byte_new(char const *s) {
  return (Object){.type = BYTE, .byte = atoi(s)};
}

static bool eqv_p(Object o1, Object o2) { return o1.byte == o2.byte; }
void byte_init() {
  fn_obj_of_obj ks1[] = {object_eqv_p, object_eq_p, NULL};
  fn_bool_of_obj_obj vs1[] = {eqv_p, eqv_p, NULL};
  for (size_t i = 0; ks1[i] != NULL; i++) {
    put_bool_of_obj_obj(ks1[i], PAIR, PAIR, vs1[i]);
  }
}
