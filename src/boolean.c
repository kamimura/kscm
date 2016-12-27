#include "boolean.h"

Object const boolean_true = {.type = BOOLEAN, .boolean = true};
Object const boolean_false = {.type = BOOLEAN, .boolean = false};

static bool eq_p(Object o1, Object o2) { return o1.boolean == o2.boolean; }
static void write(Object o, FILE *stream) {
  fprintf(stream, o.boolean ? "#true" : "#false");
}
void boolean_init() {
  fn_obj_of_obj ks1[] = {object_eqv_p, object_eq_p, NULL};
  fn_bool_of_obj_obj vs1[] = {eq_p, eq_p, NULL};
  for (size_t i = 0; ks1[i] != NULL; i++) {
    put_bool_of_obj_obj(ks1[i], BOOLEAN, BOOLEAN, vs1[i]);
  }
  fn_obj_of_obj of_obj_file_ks[] = {object_write, NULL};
  fn_of_obj_file of_obj_file_vs[] = {write, NULL};
  for (size_t i = 0; of_obj_file_ks[i] != NULL; i++) {
    put_of_obj_file(of_obj_file_ks[i], BOOLEAN, of_obj_file_vs[i]);
  }
}
