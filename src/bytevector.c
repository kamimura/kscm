#include "bytevector.h"

Object bytevector_new(Object byte_list) {
  size_t len = 0;
  for (Object o = byte_list; o.type != EMPTY; o = cdrref(o)) {
    len++;
  }
  uint8_t *s = malloc(sizeof(uint8_t) * (len + 1));
  for (size_t i = 0; i < len; i++) {
    s[i] = carref(byte_list).byte;
    byte_list = cdrref(byte_list);
  }
  s[len] = '\0';
  return (Object){.type = BYTEVECTOR, .bytevector = s};
}
static void bytevector_free(Object *o_ptr) { g_free(o_ptr->bytevector); }
static bool eqv_p(Object o1, Object o2) {
  return o1.bytevector == o2.bytevector;
}
void bytevector_init() {
  fn_obj_of_obj ks1[] = {object_eqv_p, object_eq_p, NULL};
  fn_bool_of_obj_obj vs1[] = {eqv_p, eqv_p, NULL};
  for (size_t i = 0; ks1[i] != NULL; i++) {
    put_bool_of_obj_obj(ks1[i], BYTEVECTOR, BYTEVECTOR, vs1[i]);
  }
  fn_of_obj_ptr of_obj_ptr_ks[] = {object_free, NULL};
  fn_of_obj_ptr of_obj_ptr_vs[] = {bytevector_free, NULL};
  for (size_t i = 0; of_obj_ptr_ks[i] != NULL; i++) {
    put_of_obj_ptr(of_obj_ptr_ks[i], RATIONAL, of_obj_ptr_vs[i]);
  }
}
