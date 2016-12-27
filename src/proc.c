#include "proc.h"

static bool eqv_p(Object o1, Object o2) { return o1.proc == o2.proc; }
static void write(Object o, FILE *s) { fprintf(s, "#<procedure: %p>", o.proc); }

static Object make_label(Object args) {
  static size_t i = 0;
  i++;
  Object o = carref(args);
  char *s;
  asprintf(&s, "%s%ld", o.symbol, i);
  return symbol_new(s);
}

static bool apply_eqv_p(Object o1, Object o2) { return true; }
static void apply_write(Object o, FILE *s) {
  fprintf(s, "#<procedure: apply>");
}

void proc_init() {
  fn_obj_of_obj of_obj_file_ks[] = {object_write, NULL};
  fn_of_obj_file of_obj_file_vs[] = {write, NULL};
  for (size_t i = 0; of_obj_file_ks[i] != NULL; i++) {
    put_of_obj_file(of_obj_file_ks[i], PROC, of_obj_file_vs[i]);
  }
  fn_obj_of_obj ks1[] = {object_eqv_p, object_eq_p, NULL};
  fn_bool_of_obj_obj vs1[] = {eqv_p, eqv_p, NULL};
  for (size_t i = 0; ks1[i] != NULL; i++) {
    put_bool_of_obj_obj(ks1[i], PROC, PROC, vs1[i]);
  }
  char const *names[] = {"make-label", NULL};
  fn_obj_of_obj procs[] = {make_label, NULL};
  for (size_t i = 0; names[i] != NULL; i++) {
    val = (Object){.type = PROC, .proc = procs[i]};
    def_var_val(symbol_new(names[i]));
  }

  fn_of_obj_file of_obj_file_vs1[] = {apply_write, NULL};
  for (size_t i = 0; of_obj_file_ks[i] != NULL; i++) {
    put_of_obj_file(of_obj_file_ks[i], PROC_APPLY, of_obj_file_vs1[i]);
  }
  fn_bool_of_obj_obj vs2[] = {apply_eqv_p, apply_eqv_p, NULL};
  for (size_t i = 0; ks1[i] != NULL; i++) {
    put_bool_of_obj_obj(ks1[i], PROC_APPLY, PROC_APPLY, vs2[i]);
  }
  val = (Object){.type = PROC_APPLY};
  def_var_val(symbol_new("c-apply"));
}

Object apply_proc() { return carref(argl); }
Object apply_argl() { return carref(cdrref(argl)); }
