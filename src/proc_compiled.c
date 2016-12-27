#include "proc_compiled.h"

Object make_compiled_procedure(void *label) {
  Object out = cons((Object){.type = LABEL, .cont = label}, env);
  out.type = PROC_COMPILED;
  return out;
}
Object compiled_procedure_env() { return cdrref(proc); }
Object compiled_procedure_entry(Object proc) { return carref(proc); }
static bool eqv_p(Object o1, Object o2) { return o1.index == o2.index; }
static void write(Object o, FILE *s) {
  fprintf(s, "#<compound procedure: %p>", carref(o).cont);
}
void proc_compiled_init() {
  fn_obj_of_obj of_obj_file_ks[] = {object_write, NULL};
  fn_of_obj_file of_obj_file_vs[] = {write, NULL};
  for (size_t i = 0; of_obj_file_ks[i] != NULL; i++) {
    put_of_obj_file(of_obj_file_ks[i], PROC_COMPILED, of_obj_file_vs[i]);
  }
  fn_obj_of_obj ks1[] = {object_eqv_p, object_eq_p, NULL};
  fn_bool_of_obj_obj vs1[] = {eqv_p, eqv_p, NULL};
  for (size_t i = 0; ks1[i] != NULL; i++) {
    put_bool_of_obj_obj(ks1[i], PROC_COMPILED, PROC_COMPILED, vs1[i]);
  }
}
