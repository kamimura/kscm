#include "eof.h"

static bool eqv_p(Object o1, Object o2) { return true; }
static void write(Object o, FILE *s) { fprintf(s, "#<end-of-file>"); }
static Object eof_object(Object args) { return (Object){.type = EOF_OBJ}; }
void eof_init() {
  fn_obj_of_obj ks1[] = {object_eqv_p, object_eq_p, NULL};
  fn_bool_of_obj_obj vs1[] = {eqv_p, eqv_p, NULL};
  for (size_t i = 0; ks1[i] != NULL; i++) {
    put_bool_of_obj_obj(ks1[i], EOF_OBJ, EOF_OBJ, vs1[i]);
  }
  fn_obj_of_obj of_obj_file_ks[] = {object_write, object_display, NULL};
  fn_of_obj_file of_obj_file_vs[] = {write, write, NULL};
  for (size_t i = 0; of_obj_file_ks[i] != NULL; i++) {
    put_of_obj_file(of_obj_file_ks[i], EOF_OBJ, of_obj_file_vs[i]);
  }

  char const *names[] = {"eof-object", NULL};
  fn_obj_of_obj procs[] = {eof_object, NULL};
  for (size_t i = 0; names[i] != NULL; i++) {
    val = (Object){.type = PROC, .proc = procs[i]};
    def_var_val(symbol_new(names[i]));
  }
}
