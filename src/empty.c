#include "empty.h"

static bool eqv_p(Object o1, Object o2) { return true; }
static void write(Object o, FILE *s) { fprintf(s, "()"); }
void empty_init() {
  fn_obj_of_obj ks1[] = {object_eqv_p, object_eq_p, NULL};
  fn_bool_of_obj_obj vs1[] = {eqv_p, eqv_p, NULL};
  for (size_t i = 0; ks1[i] != NULL; i++) {
    put_bool_of_obj_obj(ks1[i], EMPTY, EMPTY, vs1[i]);
  }
  fn_obj_of_obj of_obj_file_ks[] = {object_write, object_display, NULL};
  fn_of_obj_file of_obj_file_vs[] = {write, write, NULL};
  for (size_t i = 0; of_obj_file_ks[i] != NULL; i++) {
    put_of_obj_file(of_obj_file_ks[i], EMPTY, of_obj_file_vs[i]);
  }

  /* add env */
  char const *names[] = {NULL};
  fn_obj_of_obj procs[] = {NULL};
  for (size_t i = 0; names[i] != NULL; i++) {
    val = (Object){.type = PROC, .proc = procs[i]};
    def_var_val(symbol_new(names[i]));
  }
}
