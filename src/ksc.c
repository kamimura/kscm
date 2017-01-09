/** \file */
#include <kscm.h>
int main(int argc, char *argv[]) {
  init();
  get_command_line(argc, argv);
  object_free(&val);
  val = make_compiled_procedure(&&entry942);
  goto after_lambda941;
entry942:
  env = compiled_procedure_env();
  env = extend_environment(c_str_to_datum("(|port| . ())"));
  object_free(&proc);
  proc = lookup_var_val(c_str_to_datum("|display|"));
  object_free(&val);
  val = lookup_var_val(c_str_to_datum("|port|"));
  argl = cons(object_copy(val), empty);
  object_free(&val);
  val = c_str_to_datum("#\\newline");
  argl = cons(object_copy(val), argl);
  if (proc.type == PROC_APPLY) {
    proc = apply_proc();
    argl = apply_argl();
  }
  if (proc.type == PROC) {
    goto primitive_branch944;
  }
  object_free(&val);
  val = compiled_procedure_entry(proc);
  goto *val.cont;
primitive_branch944:;
  object_free(&val);
  val = proc.proc(argl);
  goto *cont.cont;
after_lambda941:;
  {
    Object t = def_var_val(c_str_to_datum("|newline|"));
    object_free(&val);
    val = t;
  }
  object_free(&val);
  val = make_compiled_procedure(&&entry926);
  goto after_lambda925;
entry926:
  env = compiled_procedure_env();
  env = extend_environment(c_str_to_datum("(|list| . (|port| . ()))"));
  save(cont);
  save(env);
  object_free(&proc);
  proc = lookup_var_val(c_str_to_datum("|not|"));
  save(proc);
  object_free(&proc);
  proc = lookup_var_val(c_str_to_datum("|null?|"));
  object_free(&val);
  val = lookup_var_val(c_str_to_datum("|list|"));
  argl = cons(object_copy(val), empty);
  if (proc.type == PROC_APPLY) {
    proc = apply_proc();
    argl = apply_argl();
  }
  if (proc.type == PROC) {
    goto primitive_branch938;
  }
  cont.cont = &&after_call937;
  object_free(&val);
  val = compiled_procedure_entry(proc);
  goto *val.cont;
primitive_branch938:;
  object_free(&val);
  val = proc.proc(argl);
after_call937:;
  argl = cons(object_copy(val), empty);
  object_free(&proc);
  proc = restore();
  if (proc.type == PROC_APPLY) {
    proc = apply_proc();
    argl = apply_argl();
  }
  if (proc.type == PROC) {
    goto primitive_branch940;
  }
  cont.cont = &&after_call939;
  object_free(&val);
  val = compiled_procedure_entry(proc);
  goto *val.cont;
primitive_branch940:;
  object_free(&val);
  val = proc.proc(argl);
after_call939:;
  object_free(&env);
  env = restore();
  object_free(&cont);
  cont = restore();
  if (val.type == BOOLEAN && !val.boolean) {
    goto false_branch928;
  }
  save(cont);
  save(env);
  object_free(&proc);
  proc = lookup_var_val(c_str_to_datum("|display|"));
  save(proc);
  object_free(&val);
  val = lookup_var_val(c_str_to_datum("|port|"));
  argl = cons(object_copy(val), empty);
  save(argl);
  object_free(&proc);
  proc = lookup_var_val(c_str_to_datum("|car|"));
  object_free(&val);
  val = lookup_var_val(c_str_to_datum("|list|"));
  argl = cons(object_copy(val), empty);
  if (proc.type == PROC_APPLY) {
    proc = apply_proc();
    argl = apply_argl();
  }
  if (proc.type == PROC) {
    goto primitive_branch934;
  }
  cont.cont = &&after_call933;
  object_free(&val);
  val = compiled_procedure_entry(proc);
  goto *val.cont;
primitive_branch934:;
  object_free(&val);
  val = proc.proc(argl);
after_call933:;
  object_free(&argl);
  argl = restore();
  argl = cons(object_copy(val), argl);
  object_free(&proc);
  proc = restore();
  if (proc.type == PROC_APPLY) {
    proc = apply_proc();
    argl = apply_argl();
  }
  if (proc.type == PROC) {
    goto primitive_branch936;
  }
  cont.cont = &&after_call935;
  object_free(&val);
  val = compiled_procedure_entry(proc);
  goto *val.cont;
primitive_branch936:;
  object_free(&val);
  val = proc.proc(argl);
after_call935:;
  object_free(&env);
  env = restore();
  object_free(&cont);
  cont = restore();
  object_free(&proc);
  proc = lookup_var_val(c_str_to_datum("|print-elements|"));
  save(cont);
  save(proc);
  object_free(&val);
  val = lookup_var_val(c_str_to_datum("|port|"));
  argl = cons(object_copy(val), empty);
  save(argl);
  object_free(&proc);
  proc = lookup_var_val(c_str_to_datum("|cdr|"));
  object_free(&val);
  val = lookup_var_val(c_str_to_datum("|list|"));
  argl = cons(object_copy(val), empty);
  if (proc.type == PROC_APPLY) {
    proc = apply_proc();
    argl = apply_argl();
  }
  if (proc.type == PROC) {
    goto primitive_branch930;
  }
  cont.cont = &&after_call929;
  object_free(&val);
  val = compiled_procedure_entry(proc);
  goto *val.cont;
primitive_branch930:;
  object_free(&val);
  val = proc.proc(argl);
after_call929:;
  object_free(&argl);
  argl = restore();
  argl = cons(object_copy(val), argl);
  object_free(&proc);
  proc = restore();
  object_free(&cont);
  cont = restore();
  if (proc.type == PROC_APPLY) {
    proc = apply_proc();
    argl = apply_argl();
  }
  if (proc.type == PROC) {
    goto primitive_branch932;
  }
  object_free(&val);
  val = compiled_procedure_entry(proc);
  goto *val.cont;
primitive_branch932:;
  object_free(&val);
  val = proc.proc(argl);
  goto *cont.cont;
false_branch928:;
  object_free(&val);
  val = undef;
  goto *cont.cont;
after_lambda925:;
  {
    Object t = def_var_val(c_str_to_datum("|print-elements|"));
    object_free(&val);
    val = t;
  }
  object_free(&val);
  val = make_compiled_procedure(&&entry908);
  goto after_lambda907;
entry908:
  env = compiled_procedure_env();
  env = extend_environment(c_str_to_datum("(|code| . (|port| . ()))"));
  save(cont);
  save(env);
  object_free(&proc);
  proc = lookup_var_val(c_str_to_datum("|display|"));
  object_free(&val);
  val = lookup_var_val(c_str_to_datum("|port|"));
  argl = cons(object_copy(val), empty);
  object_free(&val);
  val = c_str_to_datum("|/** \\x5c;file */|");
  argl = cons(object_copy(val), argl);
  if (proc.type == PROC_APPLY) {
    proc = apply_proc();
    argl = apply_argl();
  }
  if (proc.type == PROC) {
    goto primitive_branch924;
  }
  cont.cont = &&after_call923;
  object_free(&val);
  val = compiled_procedure_entry(proc);
  goto *val.cont;
primitive_branch924:;
  object_free(&val);
  val = proc.proc(argl);
after_call923:;
  object_free(&env);
  env = restore();
  object_free(&cont);
  cont = restore();
  save(cont);
  save(env);
  object_free(&proc);
  proc = lookup_var_val(c_str_to_datum("|newline|"));
  object_free(&val);
  val = lookup_var_val(c_str_to_datum("|port|"));
  argl = cons(object_copy(val), empty);
  if (proc.type == PROC_APPLY) {
    proc = apply_proc();
    argl = apply_argl();
  }
  if (proc.type == PROC) {
    goto primitive_branch922;
  }
  cont.cont = &&after_call921;
  object_free(&val);
  val = compiled_procedure_entry(proc);
  goto *val.cont;
primitive_branch922:;
  object_free(&val);
  val = proc.proc(argl);
after_call921:;
  object_free(&env);
  env = restore();
  object_free(&cont);
  cont = restore();
  save(cont);
  save(env);
  object_free(&proc);
  proc = lookup_var_val(c_str_to_datum("|display|"));
  object_free(&val);
  val = lookup_var_val(c_str_to_datum("|port|"));
  argl = cons(object_copy(val), empty);
  object_free(&val);
  val = c_str_to_datum("|#include <kscm.h>|");
  argl = cons(object_copy(val), argl);
  if (proc.type == PROC_APPLY) {
    proc = apply_proc();
    argl = apply_argl();
  }
  if (proc.type == PROC) {
    goto primitive_branch920;
  }
  cont.cont = &&after_call919;
  object_free(&val);
  val = compiled_procedure_entry(proc);
  goto *val.cont;
primitive_branch920:;
  object_free(&val);
  val = proc.proc(argl);
after_call919:;
  object_free(&env);
  env = restore();
  object_free(&cont);
  cont = restore();
  save(cont);
  save(env);
  object_free(&proc);
  proc = lookup_var_val(c_str_to_datum("|newline|"));
  object_free(&val);
  val = lookup_var_val(c_str_to_datum("|port|"));
  argl = cons(object_copy(val), empty);
  if (proc.type == PROC_APPLY) {
    proc = apply_proc();
    argl = apply_argl();
  }
  if (proc.type == PROC) {
    goto primitive_branch918;
  }
  cont.cont = &&after_call917;
  object_free(&val);
  val = compiled_procedure_entry(proc);
  goto *val.cont;
primitive_branch918:;
  object_free(&val);
  val = proc.proc(argl);
after_call917:;
  object_free(&env);
  env = restore();
  object_free(&cont);
  cont = restore();
  save(cont);
  save(env);
  object_free(&proc);
  proc = lookup_var_val(c_str_to_datum("|display|"));
  object_free(&val);
  val = lookup_var_val(c_str_to_datum("|port|"));
  argl = cons(object_copy(val), empty);
  object_free(&val);
  val = c_str_to_datum("|int main (int argc,char "
                       "*argv[]){init();get_command_line(argc, argv);|");
  argl = cons(object_copy(val), argl);
  if (proc.type == PROC_APPLY) {
    proc = apply_proc();
    argl = apply_argl();
  }
  if (proc.type == PROC) {
    goto primitive_branch916;
  }
  cont.cont = &&after_call915;
  object_free(&val);
  val = compiled_procedure_entry(proc);
  goto *val.cont;
primitive_branch916:;
  object_free(&val);
  val = proc.proc(argl);
after_call915:;
  object_free(&env);
  env = restore();
  object_free(&cont);
  cont = restore();
  save(cont);
  save(env);
  object_free(&proc);
  proc = lookup_var_val(c_str_to_datum("|print-elements|"));
  save(proc);
  object_free(&val);
  val = lookup_var_val(c_str_to_datum("|port|"));
  argl = cons(object_copy(val), empty);
  save(argl);
  object_free(&proc);
  proc = lookup_var_val(c_str_to_datum("|c-caddr|"));
  object_free(&val);
  val = lookup_var_val(c_str_to_datum("|code|"));
  argl = cons(object_copy(val), empty);
  if (proc.type == PROC_APPLY) {
    proc = apply_proc();
    argl = apply_argl();
  }
  if (proc.type == PROC) {
    goto primitive_branch912;
  }
  cont.cont = &&after_call911;
  object_free(&val);
  val = compiled_procedure_entry(proc);
  goto *val.cont;
primitive_branch912:;
  object_free(&val);
  val = proc.proc(argl);
after_call911:;
  object_free(&argl);
  argl = restore();
  argl = cons(object_copy(val), argl);
  object_free(&proc);
  proc = restore();
  if (proc.type == PROC_APPLY) {
    proc = apply_proc();
    argl = apply_argl();
  }
  if (proc.type == PROC) {
    goto primitive_branch914;
  }
  cont.cont = &&after_call913;
  object_free(&val);
  val = compiled_procedure_entry(proc);
  goto *val.cont;
primitive_branch914:;
  object_free(&val);
  val = proc.proc(argl);
after_call913:;
  object_free(&env);
  env = restore();
  object_free(&cont);
  cont = restore();
  object_free(&proc);
  proc = lookup_var_val(c_str_to_datum("|display|"));
  object_free(&val);
  val = lookup_var_val(c_str_to_datum("|port|"));
  argl = cons(object_copy(val), empty);
  object_free(&val);
  val =
      c_str_to_datum("|printf(\\x22;=> "
                     "\\x22;);object_write_stdout(val);puts(\\x22;\\x22;);}|");
  argl = cons(object_copy(val), argl);
  if (proc.type == PROC_APPLY) {
    proc = apply_proc();
    argl = apply_argl();
  }
  if (proc.type == PROC) {
    goto primitive_branch910;
  }
  object_free(&val);
  val = compiled_procedure_entry(proc);
  goto *val.cont;
primitive_branch910:;
  object_free(&val);
  val = proc.proc(argl);
  goto *cont.cont;
after_lambda907:;
  {
    Object t = def_var_val(c_str_to_datum("|print-code|"));
    object_free(&val);
    val = t;
  }
  object_free(&val);
  val = c_str_to_datum("#false");
  if (val.type == BOOLEAN && !val.boolean) {
    goto false_branch906;
  }
  object_free(&val);
  val = c_str_to_datum("0");
  goto after_if905;
false_branch906:;
  object_free(&val);
  val = undef;
after_if905:;
  {
    Object t = def_var_val(c_str_to_datum("|undef|"));
    object_free(&val);
    val = t;
  }
  object_free(&val);
  val = make_compiled_procedure(&&entry894);
  goto after_lambda893;
entry894:
  env = compiled_procedure_env();
  env = extend_environment(c_str_to_datum("(|obj| . ())"));
  object_free(&proc);
  proc = lookup_var_val(c_str_to_datum("|c-append|"));
  save(cont);
  save(proc);
  object_free(&val);
  val = c_str_to_datum("(|)| . ())");
  argl = cons(object_copy(val), empty);
  save(env);
  save(argl);
  object_free(&proc);
  proc = lookup_var_val(c_str_to_datum("|obj->c|"));
  save(proc);
  object_free(&proc);
  proc = lookup_var_val(c_str_to_datum("|cdr|"));
  object_free(&val);
  val = lookup_var_val(c_str_to_datum("|obj|"));
  argl = cons(object_copy(val), empty);
  if (proc.type == PROC_APPLY) {
    proc = apply_proc();
    argl = apply_argl();
  }
  if (proc.type == PROC) {
    goto primitive_branch896;
  }
  cont.cont = &&after_call895;
  object_free(&val);
  val = compiled_procedure_entry(proc);
  goto *val.cont;
primitive_branch896:;
  object_free(&val);
  val = proc.proc(argl);
after_call895:;
  argl = cons(object_copy(val), empty);
  object_free(&proc);
  proc = restore();
  if (proc.type == PROC_APPLY) {
    proc = apply_proc();
    argl = apply_argl();
  }
  if (proc.type == PROC) {
    goto primitive_branch898;
  }
  cont.cont = &&after_call897;
  object_free(&val);
  val = compiled_procedure_entry(proc);
  goto *val.cont;
primitive_branch898:;
  object_free(&val);
  val = proc.proc(argl);
after_call897:;
  object_free(&argl);
  argl = restore();
  argl = cons(object_copy(val), argl);
  object_free(&env);
  env = restore();
  object_free(&val);
  val = c_str_to_datum("(| . | . ())");
  argl = cons(object_copy(val), argl);
  save(argl);
  object_free(&proc);
  proc = lookup_var_val(c_str_to_datum("|obj->c|"));
  save(proc);
  object_free(&proc);
  proc = lookup_var_val(c_str_to_datum("|car|"));
  object_free(&val);
  val = lookup_var_val(c_str_to_datum("|obj|"));
  argl = cons(object_copy(val), empty);
  if (proc.type == PROC_APPLY) {
    proc = apply_proc();
    argl = apply_argl();
  }
  if (proc.type == PROC) {
    goto primitive_branch900;
  }
  cont.cont = &&after_call899;
  object_free(&val);
  val = compiled_procedure_entry(proc);
  goto *val.cont;
primitive_branch900:;
  object_free(&val);
  val = proc.proc(argl);
after_call899:;
  argl = cons(object_copy(val), empty);
  object_free(&proc);
  proc = restore();
  if (proc.type == PROC_APPLY) {
    proc = apply_proc();
    argl = apply_argl();
  }
  if (proc.type == PROC) {
    goto primitive_branch902;
  }
  cont.cont = &&after_call901;
  object_free(&val);
  val = compiled_procedure_entry(proc);
  goto *val.cont;
primitive_branch902:;
  object_free(&val);
  val = proc.proc(argl);
after_call901:;
  object_free(&argl);
  argl = restore();
  argl = cons(object_copy(val), argl);
  object_free(&val);
  val = c_str_to_datum("(|(| . ())");
  argl = cons(object_copy(val), argl);
  object_free(&proc);
  proc = restore();
  object_free(&cont);
  cont = restore();
  if (proc.type == PROC_APPLY) {
    proc = apply_proc();
    argl = apply_argl();
  }
  if (proc.type == PROC) {
    goto primitive_branch904;
  }
  object_free(&val);
  val = compiled_procedure_entry(proc);
  goto *val.cont;
primitive_branch904:;
  object_free(&val);
  val = proc.proc(argl);
  goto *cont.cont;
after_lambda893:;
  {
    Object t = def_var_val(c_str_to_datum("|pair->c|"));
    object_free(&val);
    val = t;
  }
  object_free(&val);
  val = make_compiled_procedure(&&entry852);
  goto after_lambda851;
entry852:
  env = compiled_procedure_env();
  env = extend_environment(c_str_to_datum("(|obj| . ())"));
  save(cont);
  save(env);
  object_free(&proc);
  proc = lookup_var_val(c_str_to_datum("|number?|"));
  object_free(&val);
  val = lookup_var_val(c_str_to_datum("|obj|"));
  argl = cons(object_copy(val), empty);
  if (proc.type == PROC_APPLY) {
    proc = apply_proc();
    argl = apply_argl();
  }
  if (proc.type == PROC) {
    goto primitive_branch892;
  }
  cont.cont = &&after_call891;
  object_free(&val);
  val = compiled_procedure_entry(proc);
  goto *val.cont;
primitive_branch892:;
  object_free(&val);
  val = proc.proc(argl);
after_call891:;
  object_free(&env);
  env = restore();
  object_free(&cont);
  cont = restore();
  if (val.type == BOOLEAN && !val.boolean) {
    goto false_branch854;
  }
  object_free(&proc);
  proc = lookup_var_val(c_str_to_datum("|list|"));
  object_free(&val);
  val = lookup_var_val(c_str_to_datum("|obj|"));
  argl = cons(object_copy(val), empty);
  if (proc.type == PROC_APPLY) {
    proc = apply_proc();
    argl = apply_argl();
  }
  if (proc.type == PROC) {
    goto primitive_branch890;
  }
  object_free(&val);
  val = compiled_procedure_entry(proc);
  goto *val.cont;
primitive_branch890:;
  object_free(&val);
  val = proc.proc(argl);
  goto *cont.cont;
false_branch854:;
  save(cont);
  save(env);
  object_free(&proc);
  proc = lookup_var_val(c_str_to_datum("|string?|"));
  object_free(&val);
  val = lookup_var_val(c_str_to_datum("|obj|"));
  argl = cons(object_copy(val), empty);
  if (proc.type == PROC_APPLY) {
    proc = apply_proc();
    argl = apply_argl();
  }
  if (proc.type == PROC) {
    goto primitive_branch888;
  }
  cont.cont = &&after_call887;
  object_free(&val);
  val = compiled_procedure_entry(proc);
  goto *val.cont;
primitive_branch888:;
  object_free(&val);
  val = proc.proc(argl);
after_call887:;
  object_free(&env);
  env = restore();
  object_free(&cont);
  cont = restore();
  if (val.type == BOOLEAN && !val.boolean) {
    goto false_branch856;
  }
  object_free(&proc);
  proc = lookup_var_val(c_str_to_datum("|c-string->c|"));
  object_free(&val);
  val = lookup_var_val(c_str_to_datum("|obj|"));
  argl = cons(object_copy(val), empty);
  if (proc.type == PROC_APPLY) {
    proc = apply_proc();
    argl = apply_argl();
  }
  if (proc.type == PROC) {
    goto primitive_branch886;
  }
  object_free(&val);
  val = compiled_procedure_entry(proc);
  goto *val.cont;
primitive_branch886:;
  object_free(&val);
  val = proc.proc(argl);
  goto *cont.cont;
false_branch856:;
  save(cont);
  save(env);
  object_free(&proc);
  proc = lookup_var_val(c_str_to_datum("|symbol?|"));
  object_free(&val);
  val = lookup_var_val(c_str_to_datum("|obj|"));
  argl = cons(object_copy(val), empty);
  if (proc.type == PROC_APPLY) {
    proc = apply_proc();
    argl = apply_argl();
  }
  if (proc.type == PROC) {
    goto primitive_branch884;
  }
  cont.cont = &&after_call883;
  object_free(&val);
  val = compiled_procedure_entry(proc);
  goto *val.cont;
primitive_branch884:;
  object_free(&val);
  val = proc.proc(argl);
after_call883:;
  object_free(&env);
  env = restore();
  object_free(&cont);
  cont = restore();
  if (val.type == BOOLEAN && !val.boolean) {
    goto false_branch858;
  }
  object_free(&proc);
  proc = lookup_var_val(c_str_to_datum("|c-symbol->c|"));
  object_free(&val);
  val = lookup_var_val(c_str_to_datum("|obj|"));
  argl = cons(object_copy(val), empty);
  if (proc.type == PROC_APPLY) {
    proc = apply_proc();
    argl = apply_argl();
  }
  if (proc.type == PROC) {
    goto primitive_branch882;
  }
  object_free(&val);
  val = compiled_procedure_entry(proc);
  goto *val.cont;
primitive_branch882:;
  object_free(&val);
  val = proc.proc(argl);
  goto *cont.cont;
false_branch858:;
  save(cont);
  save(env);
  object_free(&proc);
  proc = lookup_var_val(c_str_to_datum("|pair?|"));
  object_free(&val);
  val = lookup_var_val(c_str_to_datum("|obj|"));
  argl = cons(object_copy(val), empty);
  if (proc.type == PROC_APPLY) {
    proc = apply_proc();
    argl = apply_argl();
  }
  if (proc.type == PROC) {
    goto primitive_branch880;
  }
  cont.cont = &&after_call879;
  object_free(&val);
  val = compiled_procedure_entry(proc);
  goto *val.cont;
primitive_branch880:;
  object_free(&val);
  val = proc.proc(argl);
after_call879:;
  object_free(&env);
  env = restore();
  object_free(&cont);
  cont = restore();
  if (val.type == BOOLEAN && !val.boolean) {
    goto false_branch860;
  }
  object_free(&proc);
  proc = lookup_var_val(c_str_to_datum("|pair->c|"));
  object_free(&val);
  val = lookup_var_val(c_str_to_datum("|obj|"));
  argl = cons(object_copy(val), empty);
  if (proc.type == PROC_APPLY) {
    proc = apply_proc();
    argl = apply_argl();
  }
  if (proc.type == PROC) {
    goto primitive_branch878;
  }
  object_free(&val);
  val = compiled_procedure_entry(proc);
  goto *val.cont;
primitive_branch878:;
  object_free(&val);
  val = proc.proc(argl);
  goto *cont.cont;
false_branch860:;
  save(cont);
  save(env);
  object_free(&proc);
  proc = lookup_var_val(c_str_to_datum("|null?|"));
  object_free(&val);
  val = lookup_var_val(c_str_to_datum("|obj|"));
  argl = cons(object_copy(val), empty);
  if (proc.type == PROC_APPLY) {
    proc = apply_proc();
    argl = apply_argl();
  }
  if (proc.type == PROC) {
    goto primitive_branch876;
  }
  cont.cont = &&after_call875;
  object_free(&val);
  val = compiled_procedure_entry(proc);
  goto *val.cont;
primitive_branch876:;
  object_free(&val);
  val = proc.proc(argl);
after_call875:;
  object_free(&env);
  env = restore();
  object_free(&cont);
  cont = restore();
  if (val.type == BOOLEAN && !val.boolean) {
    goto false_branch862;
  }
  object_free(&val);
  val = c_str_to_datum("(|()| . ())");
  goto *cont.cont;
false_branch862:;
  save(cont);
  save(env);
  object_free(&proc);
  proc = lookup_var_val(c_str_to_datum("|boolean?|"));
  object_free(&val);
  val = lookup_var_val(c_str_to_datum("|obj|"));
  argl = cons(object_copy(val), empty);
  if (proc.type == PROC_APPLY) {
    proc = apply_proc();
    argl = apply_argl();
  }
  if (proc.type == PROC) {
    goto primitive_branch874;
  }
  cont.cont = &&after_call873;
  object_free(&val);
  val = compiled_procedure_entry(proc);
  goto *val.cont;
primitive_branch874:;
  object_free(&val);
  val = proc.proc(argl);
after_call873:;
  object_free(&env);
  env = restore();
  object_free(&cont);
  cont = restore();
  if (val.type == BOOLEAN && !val.boolean) {
    goto false_branch864;
  }
  object_free(&proc);
  proc = lookup_var_val(c_str_to_datum("|list|"));
  object_free(&val);
  val = lookup_var_val(c_str_to_datum("|obj|"));
  argl = cons(object_copy(val), empty);
  if (proc.type == PROC_APPLY) {
    proc = apply_proc();
    argl = apply_argl();
  }
  if (proc.type == PROC) {
    goto primitive_branch872;
  }
  object_free(&val);
  val = compiled_procedure_entry(proc);
  goto *val.cont;
primitive_branch872:;
  object_free(&val);
  val = proc.proc(argl);
  goto *cont.cont;
false_branch864:;
  save(cont);
  save(env);
  object_free(&proc);
  proc = lookup_var_val(c_str_to_datum("|char?|"));
  object_free(&val);
  val = lookup_var_val(c_str_to_datum("|obj|"));
  argl = cons(object_copy(val), empty);
  if (proc.type == PROC_APPLY) {
    proc = apply_proc();
    argl = apply_argl();
  }
  if (proc.type == PROC) {
    goto primitive_branch870;
  }
  cont.cont = &&after_call869;
  object_free(&val);
  val = compiled_procedure_entry(proc);
  goto *val.cont;
primitive_branch870:;
  object_free(&val);
  val = proc.proc(argl);
after_call869:;
  object_free(&env);
  env = restore();
  object_free(&cont);
  cont = restore();
  if (val.type == BOOLEAN && !val.boolean) {
    goto false_branch866;
  }
  object_free(&proc);
  proc = lookup_var_val(c_str_to_datum("|c-char->c|"));
  object_free(&val);
  val = lookup_var_val(c_str_to_datum("|obj|"));
  argl = cons(object_copy(val), empty);
  if (proc.type == PROC_APPLY) {
    proc = apply_proc();
    argl = apply_argl();
  }
  if (proc.type == PROC) {
    goto primitive_branch868;
  }
  object_free(&val);
  val = compiled_procedure_entry(proc);
  goto *val.cont;
primitive_branch868:;
  object_free(&val);
  val = proc.proc(argl);
  goto *cont.cont;
false_branch866:;
  object_free(&val);
  val = undef;
  goto *cont.cont;
after_lambda851:;
  {
    Object t = def_var_val(c_str_to_datum("|obj->c|"));
    object_free(&val);
    val = t;
  }
  object_free(&val);
  val = make_compiled_procedure(&&entry838);
  goto after_lambda837;
entry838:
  env = compiled_procedure_env();
  env = extend_environment(c_str_to_datum("(|obj| . ())"));
  save(cont);
  save(env);
  object_free(&proc);
  proc = lookup_var_val(c_str_to_datum("|eq?|"));
  object_free(&val);
  val = lookup_var_val(c_str_to_datum("|undef|"));
  argl = cons(object_copy(val), empty);
  object_free(&val);
  val = lookup_var_val(c_str_to_datum("|obj|"));
  argl = cons(object_copy(val), argl);
  if (proc.type == PROC_APPLY) {
    proc = apply_proc();
    argl = apply_argl();
  }
  if (proc.type == PROC) {
    goto primitive_branch850;
  }
  cont.cont = &&after_call849;
  object_free(&val);
  val = compiled_procedure_entry(proc);
  goto *val.cont;
primitive_branch850:;
  object_free(&val);
  val = proc.proc(argl);
after_call849:;
  object_free(&env);
  env = restore();
  object_free(&cont);
  cont = restore();
  if (val.type == BOOLEAN && !val.boolean) {
    goto false_branch840;
  }
  object_free(&val);
  val = c_str_to_datum("(|undef| . ())");
  goto *cont.cont;
false_branch840:;
  save(cont);
  save(env);
  object_free(&proc);
  proc = lookup_var_val(c_str_to_datum("|eof-object?|"));
  object_free(&val);
  val = lookup_var_val(c_str_to_datum("|obj|"));
  argl = cons(object_copy(val), empty);
  if (proc.type == PROC_APPLY) {
    proc = apply_proc();
    argl = apply_argl();
  }
  if (proc.type == PROC) {
    goto primitive_branch848;
  }
  cont.cont = &&after_call847;
  object_free(&val);
  val = compiled_procedure_entry(proc);
  goto *val.cont;
primitive_branch848:;
  object_free(&val);
  val = proc.proc(argl);
after_call847:;
  object_free(&env);
  env = restore();
  object_free(&cont);
  cont = restore();
  if (val.type == BOOLEAN && !val.boolean) {
    goto false_branch842;
  }
  object_free(&val);
  val = c_str_to_datum("(|eof_obj| . ())");
  goto *cont.cont;
false_branch842:;
  object_free(&proc);
  proc = lookup_var_val(c_str_to_datum("|c-append|"));
  save(cont);
  save(proc);
  object_free(&val);
  val = c_str_to_datum("(|\\x22;)| . ())");
  argl = cons(object_copy(val), empty);
  save(argl);
  object_free(&proc);
  proc = lookup_var_val(c_str_to_datum("|obj->c|"));
  object_free(&val);
  val = lookup_var_val(c_str_to_datum("|obj|"));
  argl = cons(object_copy(val), empty);
  if (proc.type == PROC_APPLY) {
    proc = apply_proc();
    argl = apply_argl();
  }
  if (proc.type == PROC) {
    goto primitive_branch844;
  }
  cont.cont = &&after_call843;
  object_free(&val);
  val = compiled_procedure_entry(proc);
  goto *val.cont;
primitive_branch844:;
  object_free(&val);
  val = proc.proc(argl);
after_call843:;
  object_free(&argl);
  argl = restore();
  argl = cons(object_copy(val), argl);
  object_free(&val);
  val = c_str_to_datum("(|c_str_to_datum(\\x22;| . ())");
  argl = cons(object_copy(val), argl);
  object_free(&proc);
  proc = restore();
  object_free(&cont);
  cont = restore();
  if (proc.type == PROC_APPLY) {
    proc = apply_proc();
    argl = apply_argl();
  }
  if (proc.type == PROC) {
    goto primitive_branch846;
  }
  object_free(&val);
  val = compiled_procedure_entry(proc);
  goto *val.cont;
primitive_branch846:;
  object_free(&val);
  val = proc.proc(argl);
  goto *cont.cont;
after_lambda837:;
  {
    Object t = def_var_val(c_str_to_datum("|const|"));
    object_free(&val);
    val = t;
  }
  object_free(&val);
  val = make_compiled_procedure(&&entry822);
  goto after_lambda821;
entry822:
  env = compiled_procedure_env();
  env = extend_environment(c_str_to_datum("(|exp| . ())"));
  save(cont);
  save(env);
  object_free(&proc);
  proc = lookup_var_val(c_str_to_datum("|symbol?|"));
  save(proc);
  object_free(&proc);
  proc = lookup_var_val(c_str_to_datum("|c-cadr|"));
  object_free(&val);
  val = lookup_var_val(c_str_to_datum("|exp|"));
  argl = cons(object_copy(val), empty);
  if (proc.type == PROC_APPLY) {
    proc = apply_proc();
    argl = apply_argl();
  }
  if (proc.type == PROC) {
    goto primitive_branch834;
  }
  cont.cont = &&after_call833;
  object_free(&val);
  val = compiled_procedure_entry(proc);
  goto *val.cont;
primitive_branch834:;
  object_free(&val);
  val = proc.proc(argl);
after_call833:;
  argl = cons(object_copy(val), empty);
  object_free(&proc);
  proc = restore();
  if (proc.type == PROC_APPLY) {
    proc = apply_proc();
    argl = apply_argl();
  }
  if (proc.type == PROC) {
    goto primitive_branch836;
  }
  cont.cont = &&after_call835;
  object_free(&val);
  val = compiled_procedure_entry(proc);
  goto *val.cont;
primitive_branch836:;
  object_free(&val);
  val = proc.proc(argl);
after_call835:;
  object_free(&env);
  env = restore();
  object_free(&cont);
  cont = restore();
  if (val.type == BOOLEAN && !val.boolean) {
    goto false_branch824;
  }
  object_free(&proc);
  proc = lookup_var_val(c_str_to_datum("|c-caddr|"));
  object_free(&val);
  val = lookup_var_val(c_str_to_datum("|exp|"));
  argl = cons(object_copy(val), empty);
  if (proc.type == PROC_APPLY) {
    proc = apply_proc();
    argl = apply_argl();
  }
  if (proc.type == PROC) {
    goto primitive_branch832;
  }
  object_free(&val);
  val = compiled_procedure_entry(proc);
  goto *val.cont;
primitive_branch832:;
  object_free(&val);
  val = proc.proc(argl);
  goto *cont.cont;
false_branch824:;
  object_free(&proc);
  proc = lookup_var_val(c_str_to_datum("|c-make-lambda|"));
  save(cont);
  save(proc);
  save(env);
  object_free(&proc);
  proc = lookup_var_val(c_str_to_datum("|c-cddr|"));
  object_free(&val);
  val = lookup_var_val(c_str_to_datum("|exp|"));
  argl = cons(object_copy(val), empty);
  if (proc.type == PROC_APPLY) {
    proc = apply_proc();
    argl = apply_argl();
  }
  if (proc.type == PROC) {
    goto primitive_branch826;
  }
  cont.cont = &&after_call825;
  object_free(&val);
  val = compiled_procedure_entry(proc);
  goto *val.cont;
primitive_branch826:;
  object_free(&val);
  val = proc.proc(argl);
after_call825:;
  argl = cons(object_copy(val), empty);
  object_free(&env);
  env = restore();
  save(argl);
  object_free(&proc);
  proc = lookup_var_val(c_str_to_datum("|c-cdadr|"));
  object_free(&val);
  val = lookup_var_val(c_str_to_datum("|exp|"));
  argl = cons(object_copy(val), empty);
  if (proc.type == PROC_APPLY) {
    proc = apply_proc();
    argl = apply_argl();
  }
  if (proc.type == PROC) {
    goto primitive_branch828;
  }
  cont.cont = &&after_call827;
  object_free(&val);
  val = compiled_procedure_entry(proc);
  goto *val.cont;
primitive_branch828:;
  object_free(&val);
  val = proc.proc(argl);
after_call827:;
  object_free(&argl);
  argl = restore();
  argl = cons(object_copy(val), argl);
  object_free(&proc);
  proc = restore();
  object_free(&cont);
  cont = restore();
  if (proc.type == PROC_APPLY) {
    proc = apply_proc();
    argl = apply_argl();
  }
  if (proc.type == PROC) {
    goto primitive_branch830;
  }
  object_free(&val);
  val = compiled_procedure_entry(proc);
  goto *val.cont;
primitive_branch830:;
  object_free(&val);
  val = proc.proc(argl);
  goto *cont.cont;
after_lambda821:;
  {
    Object t = def_var_val(c_str_to_datum("|definition-value|"));
    object_free(&val);
    val = t;
  }
  object_free(&val);
  val = make_compiled_procedure(&&entry796);
  goto after_lambda795;
entry796:
  env = compiled_procedure_env();
  env = extend_environment(c_str_to_datum("(|exp| . ())"));
  save(cont);
  save(env);
  object_free(&proc);
  proc = lookup_var_val(c_str_to_datum("|null?|"));
  object_free(&val);
  val = lookup_var_val(c_str_to_datum("|exp|"));
  argl = cons(object_copy(val), empty);
  if (proc.type == PROC_APPLY) {
    proc = apply_proc();
    argl = apply_argl();
  }
  if (proc.type == PROC) {
    goto primitive_branch820;
  }
  cont.cont = &&after_call819;
  object_free(&val);
  val = compiled_procedure_entry(proc);
  goto *val.cont;
primitive_branch820:;
  object_free(&val);
  val = proc.proc(argl);
after_call819:;
  object_free(&env);
  env = restore();
  object_free(&cont);
  cont = restore();
  if (val.type == BOOLEAN && !val.boolean) {
    goto false_branch798;
  }
  object_free(&val);
  val = c_str_to_datum("#true");
  goto *cont.cont;
false_branch798:;
  object_free(&val);
  val = make_compiled_procedure(&&entry802);
  goto after_lambda801;
entry802:
  env = compiled_procedure_env();
  env = extend_environment(c_str_to_datum("(|o| . ())"));
  save(cont);
  save(env);
  object_free(&proc);
  proc = lookup_var_val(c_str_to_datum("|null?|"));
  save(proc);
  object_free(&proc);
  proc = lookup_var_val(c_str_to_datum("|cdr|"));
  object_free(&val);
  val = lookup_var_val(c_str_to_datum("|o|"));
  argl = cons(object_copy(val), empty);
  if (proc.type == PROC_APPLY) {
    proc = apply_proc();
    argl = apply_argl();
  }
  if (proc.type == PROC) {
    goto primitive_branch816;
  }
  cont.cont = &&after_call815;
  object_free(&val);
  val = compiled_procedure_entry(proc);
  goto *val.cont;
primitive_branch816:;
  object_free(&val);
  val = proc.proc(argl);
after_call815:;
  argl = cons(object_copy(val), empty);
  object_free(&proc);
  proc = restore();
  if (proc.type == PROC_APPLY) {
    proc = apply_proc();
    argl = apply_argl();
  }
  if (proc.type == PROC) {
    goto primitive_branch818;
  }
  cont.cont = &&after_call817;
  object_free(&val);
  val = compiled_procedure_entry(proc);
  goto *val.cont;
primitive_branch818:;
  object_free(&val);
  val = proc.proc(argl);
after_call817:;
  object_free(&env);
  env = restore();
  object_free(&cont);
  cont = restore();
  if (val.type == BOOLEAN && !val.boolean) {
    goto false_branch804;
  }
  object_free(&proc);
  proc = lookup_var_val(c_str_to_datum("|car|"));
  object_free(&val);
  val = lookup_var_val(c_str_to_datum("|o|"));
  argl = cons(object_copy(val), empty);
  if (proc.type == PROC_APPLY) {
    proc = apply_proc();
    argl = apply_argl();
  }
  if (proc.type == PROC) {
    goto primitive_branch814;
  }
  object_free(&val);
  val = compiled_procedure_entry(proc);
  goto *val.cont;
primitive_branch814:;
  object_free(&val);
  val = proc.proc(argl);
  goto *cont.cont;
false_branch804:;
  object_free(&proc);
  proc = lookup_var_val(c_str_to_datum("|list|"));
  save(cont);
  save(proc);
  object_free(&val);
  val = c_str_to_datum("#false");
  argl = cons(object_copy(val), empty);
  save(env);
  save(argl);
  object_free(&proc);
  proc = lookup_var_val(c_str_to_datum("|iter|"));
  save(proc);
  object_free(&proc);
  proc = lookup_var_val(c_str_to_datum("|cdr|"));
  object_free(&val);
  val = lookup_var_val(c_str_to_datum("|o|"));
  argl = cons(object_copy(val), empty);
  if (proc.type == PROC_APPLY) {
    proc = apply_proc();
    argl = apply_argl();
  }
  if (proc.type == PROC) {
    goto primitive_branch806;
  }
  cont.cont = &&after_call805;
  object_free(&val);
  val = compiled_procedure_entry(proc);
  goto *val.cont;
primitive_branch806:;
  object_free(&val);
  val = proc.proc(argl);
after_call805:;
  argl = cons(object_copy(val), empty);
  object_free(&proc);
  proc = restore();
  if (proc.type == PROC_APPLY) {
    proc = apply_proc();
    argl = apply_argl();
  }
  if (proc.type == PROC) {
    goto primitive_branch808;
  }
  cont.cont = &&after_call807;
  object_free(&val);
  val = compiled_procedure_entry(proc);
  goto *val.cont;
primitive_branch808:;
  object_free(&val);
  val = proc.proc(argl);
after_call807:;
  object_free(&argl);
  argl = restore();
  argl = cons(object_copy(val), argl);
  object_free(&env);
  env = restore();
  save(argl);
  object_free(&proc);
  proc = lookup_var_val(c_str_to_datum("|car|"));
  object_free(&val);
  val = lookup_var_val(c_str_to_datum("|o|"));
  argl = cons(object_copy(val), empty);
  if (proc.type == PROC_APPLY) {
    proc = apply_proc();
    argl = apply_argl();
  }
  if (proc.type == PROC) {
    goto primitive_branch810;
  }
  cont.cont = &&after_call809;
  object_free(&val);
  val = compiled_procedure_entry(proc);
  goto *val.cont;
primitive_branch810:;
  object_free(&val);
  val = proc.proc(argl);
after_call809:;
  object_free(&argl);
  argl = restore();
  argl = cons(object_copy(val), argl);
  object_free(&val);
  val = c_str_to_datum("|if|");
  argl = cons(object_copy(val), argl);
  object_free(&proc);
  proc = restore();
  object_free(&cont);
  cont = restore();
  if (proc.type == PROC_APPLY) {
    proc = apply_proc();
    argl = apply_argl();
  }
  if (proc.type == PROC) {
    goto primitive_branch812;
  }
  object_free(&val);
  val = compiled_procedure_entry(proc);
  goto *val.cont;
primitive_branch812:;
  object_free(&val);
  val = proc.proc(argl);
  goto *cont.cont;
after_lambda801:;
  {
    Object t = def_var_val(c_str_to_datum("|iter|"));
    object_free(&val);
    val = t;
  }
  object_free(&proc);
  proc = lookup_var_val(c_str_to_datum("|iter|"));
  object_free(&val);
  val = lookup_var_val(c_str_to_datum("|exp|"));
  argl = cons(object_copy(val), empty);
  if (proc.type == PROC_APPLY) {
    proc = apply_proc();
    argl = apply_argl();
  }
  if (proc.type == PROC) {
    goto primitive_branch800;
  }
  object_free(&val);
  val = compiled_procedure_entry(proc);
  goto *val.cont;
primitive_branch800:;
  object_free(&val);
  val = proc.proc(argl);
  goto *cont.cont;
after_lambda795:;
  {
    Object t = def_var_val(c_str_to_datum("|and->if|"));
    object_free(&val);
    val = t;
  }
  object_free(&val);
  val = make_compiled_procedure(&&entry780);
  goto after_lambda779;
entry780:
  env = compiled_procedure_env();
  env = extend_environment(c_str_to_datum("(|exp| . ())"));
  save(cont);
  save(env);
  object_free(&proc);
  proc = lookup_var_val(c_str_to_datum("|null?|"));
  object_free(&val);
  val = lookup_var_val(c_str_to_datum("|exp|"));
  argl = cons(object_copy(val), empty);
  if (proc.type == PROC_APPLY) {
    proc = apply_proc();
    argl = apply_argl();
  }
  if (proc.type == PROC) {
    goto primitive_branch794;
  }
  cont.cont = &&after_call793;
  object_free(&val);
  val = compiled_procedure_entry(proc);
  goto *val.cont;
primitive_branch794:;
  object_free(&val);
  val = proc.proc(argl);
after_call793:;
  object_free(&env);
  env = restore();
  object_free(&cont);
  cont = restore();
  if (val.type == BOOLEAN && !val.boolean) {
    goto false_branch782;
  }
  object_free(&val);
  val = c_str_to_datum("#false");
  goto *cont.cont;
false_branch782:;
  object_free(&proc);
  proc = lookup_var_val(c_str_to_datum("|list|"));
  save(cont);
  save(proc);
  save(env);
  object_free(&proc);
  proc = lookup_var_val(c_str_to_datum("|cons|"));
  save(proc);
  object_free(&proc);
  proc = lookup_var_val(c_str_to_datum("|cdr|"));
  object_free(&val);
  val = lookup_var_val(c_str_to_datum("|exp|"));
  argl = cons(object_copy(val), empty);
  if (proc.type == PROC_APPLY) {
    proc = apply_proc();
    argl = apply_argl();
  }
  if (proc.type == PROC) {
    goto primitive_branch784;
  }
  cont.cont = &&after_call783;
  object_free(&val);
  val = compiled_procedure_entry(proc);
  goto *val.cont;
primitive_branch784:;
  object_free(&val);
  val = proc.proc(argl);
after_call783:;
  argl = cons(object_copy(val), empty);
  object_free(&val);
  val = c_str_to_datum("|or|");
  argl = cons(object_copy(val), argl);
  object_free(&proc);
  proc = restore();
  if (proc.type == PROC_APPLY) {
    proc = apply_proc();
    argl = apply_argl();
  }
  if (proc.type == PROC) {
    goto primitive_branch786;
  }
  cont.cont = &&after_call785;
  object_free(&val);
  val = compiled_procedure_entry(proc);
  goto *val.cont;
primitive_branch786:;
  object_free(&val);
  val = proc.proc(argl);
after_call785:;
  argl = cons(object_copy(val), empty);
  object_free(&env);
  env = restore();
  save(env);
  save(argl);
  object_free(&proc);
  proc = lookup_var_val(c_str_to_datum("|car|"));
  object_free(&val);
  val = lookup_var_val(c_str_to_datum("|exp|"));
  argl = cons(object_copy(val), empty);
  if (proc.type == PROC_APPLY) {
    proc = apply_proc();
    argl = apply_argl();
  }
  if (proc.type == PROC) {
    goto primitive_branch788;
  }
  cont.cont = &&after_call787;
  object_free(&val);
  val = compiled_procedure_entry(proc);
  goto *val.cont;
primitive_branch788:;
  object_free(&val);
  val = proc.proc(argl);
after_call787:;
  object_free(&argl);
  argl = restore();
  argl = cons(object_copy(val), argl);
  object_free(&env);
  env = restore();
  save(argl);
  object_free(&proc);
  proc = lookup_var_val(c_str_to_datum("|car|"));
  object_free(&val);
  val = lookup_var_val(c_str_to_datum("|exp|"));
  argl = cons(object_copy(val), empty);
  if (proc.type == PROC_APPLY) {
    proc = apply_proc();
    argl = apply_argl();
  }
  if (proc.type == PROC) {
    goto primitive_branch790;
  }
  cont.cont = &&after_call789;
  object_free(&val);
  val = compiled_procedure_entry(proc);
  goto *val.cont;
primitive_branch790:;
  object_free(&val);
  val = proc.proc(argl);
after_call789:;
  object_free(&argl);
  argl = restore();
  argl = cons(object_copy(val), argl);
  object_free(&val);
  val = c_str_to_datum("|if|");
  argl = cons(object_copy(val), argl);
  object_free(&proc);
  proc = restore();
  object_free(&cont);
  cont = restore();
  if (proc.type == PROC_APPLY) {
    proc = apply_proc();
    argl = apply_argl();
  }
  if (proc.type == PROC) {
    goto primitive_branch792;
  }
  object_free(&val);
  val = compiled_procedure_entry(proc);
  goto *val.cont;
primitive_branch792:;
  object_free(&val);
  val = proc.proc(argl);
  goto *cont.cont;
after_lambda779:;
  {
    Object t = def_var_val(c_str_to_datum("|or->if|"));
    object_free(&val);
    val = t;
  }
  save(env);
  object_free(&proc);
  proc = lookup_var_val(c_str_to_datum("|open-output-file|"));
  object_free(&val);
  val = c_str_to_datum("\"compiler.log\"");
  argl = cons(object_copy(val), empty);
  if (proc.type == PROC_APPLY) {
    proc = apply_proc();
    argl = apply_argl();
  }
  if (proc.type == PROC) {
    goto primitive_branch778;
  }
  cont.cont = &&after_call777;
  object_free(&val);
  val = compiled_procedure_entry(proc);
  goto *val.cont;
primitive_branch778:;
  object_free(&val);
  val = proc.proc(argl);
after_call777:;
  object_free(&env);
  env = restore();
  {
    Object t = def_var_val(c_str_to_datum("|log-port|"));
    object_free(&val);
    val = t;
  }
  object_free(&val);
  val = make_compiled_procedure(&&entry670);
  goto after_lambda669;
entry670:
  env = compiled_procedure_env();
  env = extend_environment(
      c_str_to_datum("(|exp| . (|target| . (|linkage| . ())))"));
  save(cont);
  save(env);
  object_free(&proc);
  proc = lookup_var_val(c_str_to_datum("|display|"));
  object_free(&val);
  val = lookup_var_val(c_str_to_datum("|log-port|"));
  argl = cons(object_copy(val), empty);
  object_free(&val);
  val = lookup_var_val(c_str_to_datum("|exp|"));
  argl = cons(object_copy(val), argl);
  if (proc.type == PROC_APPLY) {
    proc = apply_proc();
    argl = apply_argl();
  }
  if (proc.type == PROC) {
    goto primitive_branch776;
  }
  cont.cont = &&after_call775;
  object_free(&val);
  val = compiled_procedure_entry(proc);
  goto *val.cont;
primitive_branch776:;
  object_free(&val);
  val = proc.proc(argl);
after_call775:;
  object_free(&env);
  env = restore();
  object_free(&cont);
  cont = restore();
  save(cont);
  save(env);
  object_free(&proc);
  proc = lookup_var_val(c_str_to_datum("|newline|"));
  object_free(&val);
  val = lookup_var_val(c_str_to_datum("|log-port|"));
  argl = cons(object_copy(val), empty);
  if (proc.type == PROC_APPLY) {
    proc = apply_proc();
    argl = apply_argl();
  }
  if (proc.type == PROC) {
    goto primitive_branch774;
  }
  cont.cont = &&after_call773;
  object_free(&val);
  val = compiled_procedure_entry(proc);
  goto *val.cont;
primitive_branch774:;
  object_free(&val);
  val = proc.proc(argl);
after_call773:;
  object_free(&env);
  env = restore();
  object_free(&cont);
  cont = restore();
  save(cont);
  save(env);
  object_free(&proc);
  proc = lookup_var_val(c_str_to_datum("|c-self-evaluating?|"));
  object_free(&val);
  val = lookup_var_val(c_str_to_datum("|exp|"));
  argl = cons(object_copy(val), empty);
  if (proc.type == PROC_APPLY) {
    proc = apply_proc();
    argl = apply_argl();
  }
  if (proc.type == PROC) {
    goto primitive_branch772;
  }
  cont.cont = &&after_call771;
  object_free(&val);
  val = compiled_procedure_entry(proc);
  goto *val.cont;
primitive_branch772:;
  object_free(&val);
  val = proc.proc(argl);
after_call771:;
  object_free(&env);
  env = restore();
  object_free(&cont);
  cont = restore();
  if (val.type == BOOLEAN && !val.boolean) {
    goto false_branch672;
  }
  object_free(&proc);
  proc = lookup_var_val(c_str_to_datum("|compile-self-evaluating|"));
  object_free(&val);
  val = lookup_var_val(c_str_to_datum("|linkage|"));
  argl = cons(object_copy(val), empty);
  object_free(&val);
  val = lookup_var_val(c_str_to_datum("|target|"));
  argl = cons(object_copy(val), argl);
  object_free(&val);
  val = lookup_var_val(c_str_to_datum("|exp|"));
  argl = cons(object_copy(val), argl);
  if (proc.type == PROC_APPLY) {
    proc = apply_proc();
    argl = apply_argl();
  }
  if (proc.type == PROC) {
    goto primitive_branch770;
  }
  object_free(&val);
  val = compiled_procedure_entry(proc);
  goto *val.cont;
primitive_branch770:;
  object_free(&val);
  val = proc.proc(argl);
  goto *cont.cont;
false_branch672:;
  save(cont);
  save(env);
  object_free(&proc);
  proc = lookup_var_val(c_str_to_datum("|symbol?|"));
  object_free(&val);
  val = lookup_var_val(c_str_to_datum("|exp|"));
  argl = cons(object_copy(val), empty);
  if (proc.type == PROC_APPLY) {
    proc = apply_proc();
    argl = apply_argl();
  }
  if (proc.type == PROC) {
    goto primitive_branch768;
  }
  cont.cont = &&after_call767;
  object_free(&val);
  val = compiled_procedure_entry(proc);
  goto *val.cont;
primitive_branch768:;
  object_free(&val);
  val = proc.proc(argl);
after_call767:;
  object_free(&env);
  env = restore();
  object_free(&cont);
  cont = restore();
  if (val.type == BOOLEAN && !val.boolean) {
    goto false_branch674;
  }
  object_free(&proc);
  proc = lookup_var_val(c_str_to_datum("|compile-variable|"));
  object_free(&val);
  val = lookup_var_val(c_str_to_datum("|linkage|"));
  argl = cons(object_copy(val), empty);
  object_free(&val);
  val = lookup_var_val(c_str_to_datum("|target|"));
  argl = cons(object_copy(val), argl);
  object_free(&val);
  val = lookup_var_val(c_str_to_datum("|exp|"));
  argl = cons(object_copy(val), argl);
  if (proc.type == PROC_APPLY) {
    proc = apply_proc();
    argl = apply_argl();
  }
  if (proc.type == PROC) {
    goto primitive_branch766;
  }
  object_free(&val);
  val = compiled_procedure_entry(proc);
  goto *val.cont;
primitive_branch766:;
  object_free(&val);
  val = proc.proc(argl);
  goto *cont.cont;
false_branch674:;
  save(cont);
  save(env);
  object_free(&proc);
  proc = lookup_var_val(c_str_to_datum("|pair?|"));
  object_free(&val);
  val = lookup_var_val(c_str_to_datum("|exp|"));
  argl = cons(object_copy(val), empty);
  if (proc.type == PROC_APPLY) {
    proc = apply_proc();
    argl = apply_argl();
  }
  if (proc.type == PROC) {
    goto primitive_branch764;
  }
  cont.cont = &&after_call763;
  object_free(&val);
  val = compiled_procedure_entry(proc);
  goto *val.cont;
primitive_branch764:;
  object_free(&val);
  val = proc.proc(argl);
after_call763:;
  object_free(&env);
  env = restore();
  object_free(&cont);
  cont = restore();
  if (val.type == BOOLEAN && !val.boolean) {
    goto false_branch676;
  }
  object_free(&proc);
  proc = make_compiled_procedure(&&entry682);
  goto after_lambda681;
entry682:
  env = compiled_procedure_env();
  env = extend_environment(c_str_to_datum("(|o| . ())"));
  save(cont);
  save(env);
  object_free(&proc);
  proc = lookup_var_val(c_str_to_datum("|symbol?|"));
  object_free(&val);
  val = lookup_var_val(c_str_to_datum("|o|"));
  argl = cons(object_copy(val), empty);
  if (proc.type == PROC_APPLY) {
    proc = apply_proc();
    argl = apply_argl();
  }
  if (proc.type == PROC) {
    goto primitive_branch760;
  }
  cont.cont = &&after_call759;
  object_free(&val);
  val = compiled_procedure_entry(proc);
  goto *val.cont;
primitive_branch760:;
  object_free(&val);
  val = proc.proc(argl);
after_call759:;
  object_free(&env);
  env = restore();
  object_free(&cont);
  cont = restore();
  if (val.type == BOOLEAN && !val.boolean) {
    goto false_branch684;
  }
  save(cont);
  save(env);
  object_free(&proc);
  proc = lookup_var_val(c_str_to_datum("|eq?|"));
  object_free(&val);
  val = c_str_to_datum("|quote|");
  argl = cons(object_copy(val), empty);
  object_free(&val);
  val = lookup_var_val(c_str_to_datum("|o|"));
  argl = cons(object_copy(val), argl);
  if (proc.type == PROC_APPLY) {
    proc = apply_proc();
    argl = apply_argl();
  }
  if (proc.type == PROC) {
    goto primitive_branch758;
  }
  cont.cont = &&after_call757;
  object_free(&val);
  val = compiled_procedure_entry(proc);
  goto *val.cont;
primitive_branch758:;
  object_free(&val);
  val = proc.proc(argl);
after_call757:;
  object_free(&env);
  env = restore();
  object_free(&cont);
  cont = restore();
  if (val.type == BOOLEAN && !val.boolean) {
    goto false_branch688;
  }
  object_free(&proc);
  proc = lookup_var_val(c_str_to_datum("|compile-quoted|"));
  object_free(&val);
  val = lookup_var_val(c_str_to_datum("|linkage|"));
  argl = cons(object_copy(val), empty);
  object_free(&val);
  val = lookup_var_val(c_str_to_datum("|target|"));
  argl = cons(object_copy(val), argl);
  object_free(&val);
  val = lookup_var_val(c_str_to_datum("|exp|"));
  argl = cons(object_copy(val), argl);
  if (proc.type == PROC_APPLY) {
    proc = apply_proc();
    argl = apply_argl();
  }
  if (proc.type == PROC) {
    goto primitive_branch756;
  }
  object_free(&val);
  val = compiled_procedure_entry(proc);
  goto *val.cont;
primitive_branch756:;
  object_free(&val);
  val = proc.proc(argl);
  goto *cont.cont;
false_branch688:;
  save(cont);
  save(env);
  object_free(&proc);
  proc = lookup_var_val(c_str_to_datum("|eq?|"));
  object_free(&val);
  val = c_str_to_datum("|lambda|");
  argl = cons(object_copy(val), empty);
  object_free(&val);
  val = lookup_var_val(c_str_to_datum("|o|"));
  argl = cons(object_copy(val), argl);
  if (proc.type == PROC_APPLY) {
    proc = apply_proc();
    argl = apply_argl();
  }
  if (proc.type == PROC) {
    goto primitive_branch754;
  }
  cont.cont = &&after_call753;
  object_free(&val);
  val = compiled_procedure_entry(proc);
  goto *val.cont;
primitive_branch754:;
  object_free(&val);
  val = proc.proc(argl);
after_call753:;
  object_free(&env);
  env = restore();
  object_free(&cont);
  cont = restore();
  if (val.type == BOOLEAN && !val.boolean) {
    goto false_branch690;
  }
  object_free(&proc);
  proc = lookup_var_val(c_str_to_datum("|compile-lambda|"));
  object_free(&val);
  val = lookup_var_val(c_str_to_datum("|linkage|"));
  argl = cons(object_copy(val), empty);
  object_free(&val);
  val = lookup_var_val(c_str_to_datum("|target|"));
  argl = cons(object_copy(val), argl);
  object_free(&val);
  val = lookup_var_val(c_str_to_datum("|exp|"));
  argl = cons(object_copy(val), argl);
  if (proc.type == PROC_APPLY) {
    proc = apply_proc();
    argl = apply_argl();
  }
  if (proc.type == PROC) {
    goto primitive_branch752;
  }
  object_free(&val);
  val = compiled_procedure_entry(proc);
  goto *val.cont;
primitive_branch752:;
  object_free(&val);
  val = proc.proc(argl);
  goto *cont.cont;
false_branch690:;
  save(cont);
  save(env);
  object_free(&proc);
  proc = lookup_var_val(c_str_to_datum("|eq?|"));
  object_free(&val);
  val = c_str_to_datum("|set!|");
  argl = cons(object_copy(val), empty);
  object_free(&val);
  val = lookup_var_val(c_str_to_datum("|o|"));
  argl = cons(object_copy(val), argl);
  if (proc.type == PROC_APPLY) {
    proc = apply_proc();
    argl = apply_argl();
  }
  if (proc.type == PROC) {
    goto primitive_branch750;
  }
  cont.cont = &&after_call749;
  object_free(&val);
  val = compiled_procedure_entry(proc);
  goto *val.cont;
primitive_branch750:;
  object_free(&val);
  val = proc.proc(argl);
after_call749:;
  object_free(&env);
  env = restore();
  object_free(&cont);
  cont = restore();
  if (val.type == BOOLEAN && !val.boolean) {
    goto false_branch692;
  }
  object_free(&proc);
  proc = lookup_var_val(c_str_to_datum("|compile-assignment|"));
  object_free(&val);
  val = lookup_var_val(c_str_to_datum("|linkage|"));
  argl = cons(object_copy(val), empty);
  object_free(&val);
  val = lookup_var_val(c_str_to_datum("|target|"));
  argl = cons(object_copy(val), argl);
  object_free(&val);
  val = lookup_var_val(c_str_to_datum("|exp|"));
  argl = cons(object_copy(val), argl);
  if (proc.type == PROC_APPLY) {
    proc = apply_proc();
    argl = apply_argl();
  }
  if (proc.type == PROC) {
    goto primitive_branch748;
  }
  object_free(&val);
  val = compiled_procedure_entry(proc);
  goto *val.cont;
primitive_branch748:;
  object_free(&val);
  val = proc.proc(argl);
  goto *cont.cont;
false_branch692:;
  save(cont);
  save(env);
  object_free(&proc);
  proc = lookup_var_val(c_str_to_datum("|eq?|"));
  object_free(&val);
  val = c_str_to_datum("|define|");
  argl = cons(object_copy(val), empty);
  object_free(&val);
  val = lookup_var_val(c_str_to_datum("|o|"));
  argl = cons(object_copy(val), argl);
  if (proc.type == PROC_APPLY) {
    proc = apply_proc();
    argl = apply_argl();
  }
  if (proc.type == PROC) {
    goto primitive_branch746;
  }
  cont.cont = &&after_call745;
  object_free(&val);
  val = compiled_procedure_entry(proc);
  goto *val.cont;
primitive_branch746:;
  object_free(&val);
  val = proc.proc(argl);
after_call745:;
  object_free(&env);
  env = restore();
  object_free(&cont);
  cont = restore();
  if (val.type == BOOLEAN && !val.boolean) {
    goto false_branch694;
  }
  object_free(&proc);
  proc = lookup_var_val(c_str_to_datum("|compile-definition|"));
  object_free(&val);
  val = lookup_var_val(c_str_to_datum("|linkage|"));
  argl = cons(object_copy(val), empty);
  object_free(&val);
  val = lookup_var_val(c_str_to_datum("|target|"));
  argl = cons(object_copy(val), argl);
  object_free(&val);
  val = lookup_var_val(c_str_to_datum("|exp|"));
  argl = cons(object_copy(val), argl);
  if (proc.type == PROC_APPLY) {
    proc = apply_proc();
    argl = apply_argl();
  }
  if (proc.type == PROC) {
    goto primitive_branch744;
  }
  object_free(&val);
  val = compiled_procedure_entry(proc);
  goto *val.cont;
primitive_branch744:;
  object_free(&val);
  val = proc.proc(argl);
  goto *cont.cont;
false_branch694:;
  save(cont);
  save(env);
  object_free(&proc);
  proc = lookup_var_val(c_str_to_datum("|eq?|"));
  object_free(&val);
  val = c_str_to_datum("|if|");
  argl = cons(object_copy(val), empty);
  object_free(&val);
  val = lookup_var_val(c_str_to_datum("|o|"));
  argl = cons(object_copy(val), argl);
  if (proc.type == PROC_APPLY) {
    proc = apply_proc();
    argl = apply_argl();
  }
  if (proc.type == PROC) {
    goto primitive_branch742;
  }
  cont.cont = &&after_call741;
  object_free(&val);
  val = compiled_procedure_entry(proc);
  goto *val.cont;
primitive_branch742:;
  object_free(&val);
  val = proc.proc(argl);
after_call741:;
  object_free(&env);
  env = restore();
  object_free(&cont);
  cont = restore();
  if (val.type == BOOLEAN && !val.boolean) {
    goto false_branch696;
  }
  object_free(&proc);
  proc = lookup_var_val(c_str_to_datum("|compile-if|"));
  object_free(&val);
  val = lookup_var_val(c_str_to_datum("|linkage|"));
  argl = cons(object_copy(val), empty);
  object_free(&val);
  val = lookup_var_val(c_str_to_datum("|target|"));
  argl = cons(object_copy(val), argl);
  object_free(&val);
  val = lookup_var_val(c_str_to_datum("|exp|"));
  argl = cons(object_copy(val), argl);
  if (proc.type == PROC_APPLY) {
    proc = apply_proc();
    argl = apply_argl();
  }
  if (proc.type == PROC) {
    goto primitive_branch740;
  }
  object_free(&val);
  val = compiled_procedure_entry(proc);
  goto *val.cont;
primitive_branch740:;
  object_free(&val);
  val = proc.proc(argl);
  goto *cont.cont;
false_branch696:;
  save(cont);
  save(env);
  object_free(&proc);
  proc = lookup_var_val(c_str_to_datum("|eq?|"));
  object_free(&val);
  val = c_str_to_datum("|begin|");
  argl = cons(object_copy(val), empty);
  object_free(&val);
  val = lookup_var_val(c_str_to_datum("|o|"));
  argl = cons(object_copy(val), argl);
  if (proc.type == PROC_APPLY) {
    proc = apply_proc();
    argl = apply_argl();
  }
  if (proc.type == PROC) {
    goto primitive_branch738;
  }
  cont.cont = &&after_call737;
  object_free(&val);
  val = compiled_procedure_entry(proc);
  goto *val.cont;
primitive_branch738:;
  object_free(&val);
  val = proc.proc(argl);
after_call737:;
  object_free(&env);
  env = restore();
  object_free(&cont);
  cont = restore();
  if (val.type == BOOLEAN && !val.boolean) {
    goto false_branch698;
  }
  object_free(&proc);
  proc = lookup_var_val(c_str_to_datum("|compile-sequence|"));
  save(cont);
  save(proc);
  object_free(&val);
  val = lookup_var_val(c_str_to_datum("|linkage|"));
  argl = cons(object_copy(val), empty);
  object_free(&val);
  val = lookup_var_val(c_str_to_datum("|target|"));
  argl = cons(object_copy(val), argl);
  save(argl);
  object_free(&proc);
  proc = lookup_var_val(c_str_to_datum("|cdr|"));
  object_free(&val);
  val = lookup_var_val(c_str_to_datum("|exp|"));
  argl = cons(object_copy(val), empty);
  if (proc.type == PROC_APPLY) {
    proc = apply_proc();
    argl = apply_argl();
  }
  if (proc.type == PROC) {
    goto primitive_branch734;
  }
  cont.cont = &&after_call733;
  object_free(&val);
  val = compiled_procedure_entry(proc);
  goto *val.cont;
primitive_branch734:;
  object_free(&val);
  val = proc.proc(argl);
after_call733:;
  object_free(&argl);
  argl = restore();
  argl = cons(object_copy(val), argl);
  object_free(&proc);
  proc = restore();
  object_free(&cont);
  cont = restore();
  if (proc.type == PROC_APPLY) {
    proc = apply_proc();
    argl = apply_argl();
  }
  if (proc.type == PROC) {
    goto primitive_branch736;
  }
  object_free(&val);
  val = compiled_procedure_entry(proc);
  goto *val.cont;
primitive_branch736:;
  object_free(&val);
  val = proc.proc(argl);
  goto *cont.cont;
false_branch698:;
  save(cont);
  save(env);
  object_free(&proc);
  proc = lookup_var_val(c_str_to_datum("|eq?|"));
  object_free(&val);
  val = c_str_to_datum("|and|");
  argl = cons(object_copy(val), empty);
  object_free(&val);
  val = lookup_var_val(c_str_to_datum("|o|"));
  argl = cons(object_copy(val), argl);
  if (proc.type == PROC_APPLY) {
    proc = apply_proc();
    argl = apply_argl();
  }
  if (proc.type == PROC) {
    goto primitive_branch732;
  }
  cont.cont = &&after_call731;
  object_free(&val);
  val = compiled_procedure_entry(proc);
  goto *val.cont;
primitive_branch732:;
  object_free(&val);
  val = proc.proc(argl);
after_call731:;
  object_free(&env);
  env = restore();
  object_free(&cont);
  cont = restore();
  if (val.type == BOOLEAN && !val.boolean) {
    goto false_branch700;
  }
  object_free(&proc);
  proc = lookup_var_val(c_str_to_datum("|compile|"));
  save(cont);
  save(proc);
  object_free(&val);
  val = lookup_var_val(c_str_to_datum("|linkage|"));
  argl = cons(object_copy(val), empty);
  object_free(&val);
  val = lookup_var_val(c_str_to_datum("|target|"));
  argl = cons(object_copy(val), argl);
  save(argl);
  object_free(&proc);
  proc = lookup_var_val(c_str_to_datum("|and->if|"));
  save(proc);
  object_free(&proc);
  proc = lookup_var_val(c_str_to_datum("|cdr|"));
  object_free(&val);
  val = lookup_var_val(c_str_to_datum("|exp|"));
  argl = cons(object_copy(val), empty);
  if (proc.type == PROC_APPLY) {
    proc = apply_proc();
    argl = apply_argl();
  }
  if (proc.type == PROC) {
    goto primitive_branch726;
  }
  cont.cont = &&after_call725;
  object_free(&val);
  val = compiled_procedure_entry(proc);
  goto *val.cont;
primitive_branch726:;
  object_free(&val);
  val = proc.proc(argl);
after_call725:;
  argl = cons(object_copy(val), empty);
  object_free(&proc);
  proc = restore();
  if (proc.type == PROC_APPLY) {
    proc = apply_proc();
    argl = apply_argl();
  }
  if (proc.type == PROC) {
    goto primitive_branch728;
  }
  cont.cont = &&after_call727;
  object_free(&val);
  val = compiled_procedure_entry(proc);
  goto *val.cont;
primitive_branch728:;
  object_free(&val);
  val = proc.proc(argl);
after_call727:;
  object_free(&argl);
  argl = restore();
  argl = cons(object_copy(val), argl);
  object_free(&proc);
  proc = restore();
  object_free(&cont);
  cont = restore();
  if (proc.type == PROC_APPLY) {
    proc = apply_proc();
    argl = apply_argl();
  }
  if (proc.type == PROC) {
    goto primitive_branch730;
  }
  object_free(&val);
  val = compiled_procedure_entry(proc);
  goto *val.cont;
primitive_branch730:;
  object_free(&val);
  val = proc.proc(argl);
  goto *cont.cont;
false_branch700:;
  save(cont);
  save(env);
  object_free(&proc);
  proc = lookup_var_val(c_str_to_datum("|eq?|"));
  object_free(&val);
  val = c_str_to_datum("|or|");
  argl = cons(object_copy(val), empty);
  object_free(&val);
  val = lookup_var_val(c_str_to_datum("|o|"));
  argl = cons(object_copy(val), argl);
  if (proc.type == PROC_APPLY) {
    proc = apply_proc();
    argl = apply_argl();
  }
  if (proc.type == PROC) {
    goto primitive_branch724;
  }
  cont.cont = &&after_call723;
  object_free(&val);
  val = compiled_procedure_entry(proc);
  goto *val.cont;
primitive_branch724:;
  object_free(&val);
  val = proc.proc(argl);
after_call723:;
  object_free(&env);
  env = restore();
  object_free(&cont);
  cont = restore();
  if (val.type == BOOLEAN && !val.boolean) {
    goto false_branch702;
  }
  object_free(&proc);
  proc = lookup_var_val(c_str_to_datum("|compile|"));
  save(cont);
  save(proc);
  object_free(&val);
  val = lookup_var_val(c_str_to_datum("|linkage|"));
  argl = cons(object_copy(val), empty);
  object_free(&val);
  val = lookup_var_val(c_str_to_datum("|target|"));
  argl = cons(object_copy(val), argl);
  save(argl);
  object_free(&proc);
  proc = lookup_var_val(c_str_to_datum("|or->if|"));
  save(proc);
  object_free(&proc);
  proc = lookup_var_val(c_str_to_datum("|cdr|"));
  object_free(&val);
  val = lookup_var_val(c_str_to_datum("|exp|"));
  argl = cons(object_copy(val), empty);
  if (proc.type == PROC_APPLY) {
    proc = apply_proc();
    argl = apply_argl();
  }
  if (proc.type == PROC) {
    goto primitive_branch718;
  }
  cont.cont = &&after_call717;
  object_free(&val);
  val = compiled_procedure_entry(proc);
  goto *val.cont;
primitive_branch718:;
  object_free(&val);
  val = proc.proc(argl);
after_call717:;
  argl = cons(object_copy(val), empty);
  object_free(&proc);
  proc = restore();
  if (proc.type == PROC_APPLY) {
    proc = apply_proc();
    argl = apply_argl();
  }
  if (proc.type == PROC) {
    goto primitive_branch720;
  }
  cont.cont = &&after_call719;
  object_free(&val);
  val = compiled_procedure_entry(proc);
  goto *val.cont;
primitive_branch720:;
  object_free(&val);
  val = proc.proc(argl);
after_call719:;
  object_free(&argl);
  argl = restore();
  argl = cons(object_copy(val), argl);
  object_free(&proc);
  proc = restore();
  object_free(&cont);
  cont = restore();
  if (proc.type == PROC_APPLY) {
    proc = apply_proc();
    argl = apply_argl();
  }
  if (proc.type == PROC) {
    goto primitive_branch722;
  }
  object_free(&val);
  val = compiled_procedure_entry(proc);
  goto *val.cont;
primitive_branch722:;
  object_free(&val);
  val = proc.proc(argl);
  goto *cont.cont;
false_branch702:;
  save(cont);
  save(env);
  object_free(&proc);
  proc = lookup_var_val(c_str_to_datum("|eq?|"));
  object_free(&val);
  val = c_str_to_datum("|load|");
  argl = cons(object_copy(val), empty);
  object_free(&val);
  val = lookup_var_val(c_str_to_datum("|o|"));
  argl = cons(object_copy(val), argl);
  if (proc.type == PROC_APPLY) {
    proc = apply_proc();
    argl = apply_argl();
  }
  if (proc.type == PROC) {
    goto primitive_branch716;
  }
  cont.cont = &&after_call715;
  object_free(&val);
  val = compiled_procedure_entry(proc);
  goto *val.cont;
primitive_branch716:;
  object_free(&val);
  val = proc.proc(argl);
after_call715:;
  object_free(&env);
  env = restore();
  object_free(&cont);
  cont = restore();
  if (val.type == BOOLEAN && !val.boolean) {
    goto false_branch704;
  }
  object_free(&proc);
  proc = lookup_var_val(c_str_to_datum("|compile|"));
  save(cont);
  save(proc);
  object_free(&val);
  val = lookup_var_val(c_str_to_datum("|linkage|"));
  argl = cons(object_copy(val), empty);
  object_free(&val);
  val = lookup_var_val(c_str_to_datum("|target|"));
  argl = cons(object_copy(val), argl);
  save(argl);
  object_free(&proc);
  proc = lookup_var_val(c_str_to_datum("|read|"));
  save(proc);
  object_free(&proc);
  proc = lookup_var_val(c_str_to_datum("|open-input-file|"));
  save(proc);
  object_free(&proc);
  proc = lookup_var_val(c_str_to_datum("|c-cadr|"));
  object_free(&val);
  val = lookup_var_val(c_str_to_datum("|exp|"));
  argl = cons(object_copy(val), empty);
  if (proc.type == PROC_APPLY) {
    proc = apply_proc();
    argl = apply_argl();
  }
  if (proc.type == PROC) {
    goto primitive_branch708;
  }
  cont.cont = &&after_call707;
  object_free(&val);
  val = compiled_procedure_entry(proc);
  goto *val.cont;
primitive_branch708:;
  object_free(&val);
  val = proc.proc(argl);
after_call707:;
  argl = cons(object_copy(val), empty);
  object_free(&proc);
  proc = restore();
  if (proc.type == PROC_APPLY) {
    proc = apply_proc();
    argl = apply_argl();
  }
  if (proc.type == PROC) {
    goto primitive_branch710;
  }
  cont.cont = &&after_call709;
  object_free(&val);
  val = compiled_procedure_entry(proc);
  goto *val.cont;
primitive_branch710:;
  object_free(&val);
  val = proc.proc(argl);
after_call709:;
  argl = cons(object_copy(val), empty);
  object_free(&proc);
  proc = restore();
  if (proc.type == PROC_APPLY) {
    proc = apply_proc();
    argl = apply_argl();
  }
  if (proc.type == PROC) {
    goto primitive_branch712;
  }
  cont.cont = &&after_call711;
  object_free(&val);
  val = compiled_procedure_entry(proc);
  goto *val.cont;
primitive_branch712:;
  object_free(&val);
  val = proc.proc(argl);
after_call711:;
  object_free(&argl);
  argl = restore();
  argl = cons(object_copy(val), argl);
  object_free(&proc);
  proc = restore();
  object_free(&cont);
  cont = restore();
  if (proc.type == PROC_APPLY) {
    proc = apply_proc();
    argl = apply_argl();
  }
  if (proc.type == PROC) {
    goto primitive_branch714;
  }
  object_free(&val);
  val = compiled_procedure_entry(proc);
  goto *val.cont;
primitive_branch714:;
  object_free(&val);
  val = proc.proc(argl);
  goto *cont.cont;
false_branch704:;
  object_free(&proc);
  proc = lookup_var_val(c_str_to_datum("|compile-application|"));
  object_free(&val);
  val = lookup_var_val(c_str_to_datum("|linkage|"));
  argl = cons(object_copy(val), empty);
  object_free(&val);
  val = lookup_var_val(c_str_to_datum("|target|"));
  argl = cons(object_copy(val), argl);
  object_free(&val);
  val = lookup_var_val(c_str_to_datum("|exp|"));
  argl = cons(object_copy(val), argl);
  if (proc.type == PROC_APPLY) {
    proc = apply_proc();
    argl = apply_argl();
  }
  if (proc.type == PROC) {
    goto primitive_branch706;
  }
  object_free(&val);
  val = compiled_procedure_entry(proc);
  goto *val.cont;
primitive_branch706:;
  object_free(&val);
  val = proc.proc(argl);
  goto *cont.cont;
false_branch684:;
  object_free(&proc);
  proc = lookup_var_val(c_str_to_datum("|compile-application|"));
  object_free(&val);
  val = lookup_var_val(c_str_to_datum("|linkage|"));
  argl = cons(object_copy(val), empty);
  object_free(&val);
  val = lookup_var_val(c_str_to_datum("|target|"));
  argl = cons(object_copy(val), argl);
  object_free(&val);
  val = lookup_var_val(c_str_to_datum("|exp|"));
  argl = cons(object_copy(val), argl);
  if (proc.type == PROC_APPLY) {
    proc = apply_proc();
    argl = apply_argl();
  }
  if (proc.type == PROC) {
    goto primitive_branch686;
  }
  object_free(&val);
  val = compiled_procedure_entry(proc);
  goto *val.cont;
primitive_branch686:;
  object_free(&val);
  val = proc.proc(argl);
  goto *cont.cont;
after_lambda681:;
  save(cont);
  save(proc);
  object_free(&proc);
  proc = lookup_var_val(c_str_to_datum("|car|"));
  object_free(&val);
  val = lookup_var_val(c_str_to_datum("|exp|"));
  argl = cons(object_copy(val), empty);
  if (proc.type == PROC_APPLY) {
    proc = apply_proc();
    argl = apply_argl();
  }
  if (proc.type == PROC) {
    goto primitive_branch680;
  }
  cont.cont = &&after_call679;
  object_free(&val);
  val = compiled_procedure_entry(proc);
  goto *val.cont;
primitive_branch680:;
  object_free(&val);
  val = proc.proc(argl);
after_call679:;
  argl = cons(object_copy(val), empty);
  object_free(&proc);
  proc = restore();
  object_free(&cont);
  cont = restore();
  if (proc.type == PROC_APPLY) {
    proc = apply_proc();
    argl = apply_argl();
  }
  if (proc.type == PROC) {
    goto primitive_branch762;
  }
  object_free(&val);
  val = compiled_procedure_entry(proc);
  goto *val.cont;
primitive_branch762:;
  object_free(&val);
  val = proc.proc(argl);
  goto *cont.cont;
false_branch676:;
  object_free(&proc);
  proc = lookup_var_val(c_str_to_datum("|error|"));
  object_free(&val);
  val = lookup_var_val(c_str_to_datum("|exp|"));
  argl = cons(object_copy(val), empty);
  object_free(&val);
  val = c_str_to_datum("|unknown expression type -- compile|");
  argl = cons(object_copy(val), argl);
  if (proc.type == PROC_APPLY) {
    proc = apply_proc();
    argl = apply_argl();
  }
  if (proc.type == PROC) {
    goto primitive_branch678;
  }
  object_free(&val);
  val = compiled_procedure_entry(proc);
  goto *val.cont;
primitive_branch678:;
  object_free(&val);
  val = proc.proc(argl);
  goto *cont.cont;
after_lambda669:;
  {
    Object t = def_var_val(c_str_to_datum("|compile|"));
    object_free(&val);
    val = t;
  }
  object_free(&val);
  val = make_compiled_procedure(&&entry652);
  goto after_lambda651;
entry652:
  env = compiled_procedure_env();
  env = extend_environment(c_str_to_datum("(|linkage| . ())"));
  save(cont);
  save(env);
  object_free(&proc);
  proc = lookup_var_val(c_str_to_datum("|eq?|"));
  object_free(&val);
  val = c_str_to_datum("|return|");
  argl = cons(object_copy(val), empty);
  object_free(&val);
  val = lookup_var_val(c_str_to_datum("|linkage|"));
  argl = cons(object_copy(val), argl);
  if (proc.type == PROC_APPLY) {
    proc = apply_proc();
    argl = apply_argl();
  }
  if (proc.type == PROC) {
    goto primitive_branch668;
  }
  cont.cont = &&after_call667;
  object_free(&val);
  val = compiled_procedure_entry(proc);
  goto *val.cont;
primitive_branch668:;
  object_free(&val);
  val = proc.proc(argl);
after_call667:;
  object_free(&env);
  env = restore();
  object_free(&cont);
  cont = restore();
  if (val.type == BOOLEAN && !val.boolean) {
    goto false_branch654;
  }
  object_free(&proc);
  proc = lookup_var_val(c_str_to_datum("|c-make-instruction-sequence|"));
  object_free(&val);
  val = c_str_to_datum("(|goto *cont.cont;| . ())");
  argl = cons(object_copy(val), empty);
  object_free(&val);
  val = c_str_to_datum("()");
  argl = cons(object_copy(val), argl);
  object_free(&val);
  val = c_str_to_datum("(|cont| . ())");
  argl = cons(object_copy(val), argl);
  if (proc.type == PROC_APPLY) {
    proc = apply_proc();
    argl = apply_argl();
  }
  if (proc.type == PROC) {
    goto primitive_branch666;
  }
  object_free(&val);
  val = compiled_procedure_entry(proc);
  goto *val.cont;
primitive_branch666:;
  object_free(&val);
  val = proc.proc(argl);
  goto *cont.cont;
false_branch654:;
  save(cont);
  save(env);
  object_free(&proc);
  proc = lookup_var_val(c_str_to_datum("|eq?|"));
  object_free(&val);
  val = c_str_to_datum("|next|");
  argl = cons(object_copy(val), empty);
  object_free(&val);
  val = lookup_var_val(c_str_to_datum("|linkage|"));
  argl = cons(object_copy(val), argl);
  if (proc.type == PROC_APPLY) {
    proc = apply_proc();
    argl = apply_argl();
  }
  if (proc.type == PROC) {
    goto primitive_branch664;
  }
  cont.cont = &&after_call663;
  object_free(&val);
  val = compiled_procedure_entry(proc);
  goto *val.cont;
primitive_branch664:;
  object_free(&val);
  val = proc.proc(argl);
after_call663:;
  object_free(&env);
  env = restore();
  object_free(&cont);
  cont = restore();
  if (val.type == BOOLEAN && !val.boolean) {
    goto false_branch656;
  }
  object_free(&proc);
  proc = lookup_var_val(c_str_to_datum("|c-empty-instruction-sequence|"));
  argl = empty;
  if (proc.type == PROC_APPLY) {
    proc = apply_proc();
    argl = apply_argl();
  }
  if (proc.type == PROC) {
    goto primitive_branch662;
  }
  object_free(&val);
  val = compiled_procedure_entry(proc);
  goto *val.cont;
primitive_branch662:;
  object_free(&val);
  val = proc.proc(argl);
  goto *cont.cont;
false_branch656:;
  object_free(&proc);
  proc = lookup_var_val(c_str_to_datum("|c-make-instruction-sequence|"));
  save(cont);
  save(proc);
  object_free(&proc);
  proc = lookup_var_val(c_str_to_datum("|list|"));
  object_free(&val);
  val = c_str_to_datum("|;|");
  argl = cons(object_copy(val), empty);
  object_free(&val);
  val = lookup_var_val(c_str_to_datum("|linkage|"));
  argl = cons(object_copy(val), argl);
  object_free(&val);
  val = c_str_to_datum("|goto |");
  argl = cons(object_copy(val), argl);
  if (proc.type == PROC_APPLY) {
    proc = apply_proc();
    argl = apply_argl();
  }
  if (proc.type == PROC) {
    goto primitive_branch658;
  }
  cont.cont = &&after_call657;
  object_free(&val);
  val = compiled_procedure_entry(proc);
  goto *val.cont;
primitive_branch658:;
  object_free(&val);
  val = proc.proc(argl);
after_call657:;
  argl = cons(object_copy(val), empty);
  object_free(&val);
  val = c_str_to_datum("()");
  argl = cons(object_copy(val), argl);
  object_free(&val);
  val = c_str_to_datum("()");
  argl = cons(object_copy(val), argl);
  object_free(&proc);
  proc = restore();
  object_free(&cont);
  cont = restore();
  if (proc.type == PROC_APPLY) {
    proc = apply_proc();
    argl = apply_argl();
  }
  if (proc.type == PROC) {
    goto primitive_branch660;
  }
  object_free(&val);
  val = compiled_procedure_entry(proc);
  goto *val.cont;
primitive_branch660:;
  object_free(&val);
  val = proc.proc(argl);
  goto *cont.cont;
after_lambda651:;
  {
    Object t = def_var_val(c_str_to_datum("|compile-linkage|"));
    object_free(&val);
    val = t;
  }
  object_free(&val);
  val = make_compiled_procedure(&&entry646);
  goto after_lambda645;
entry646:
  env = compiled_procedure_env();
  env = extend_environment(
      c_str_to_datum("(|linkage| . (|instruction-sequence| . ()))"));
  object_free(&proc);
  proc = lookup_var_val(c_str_to_datum("|preserving|"));
  save(cont);
  save(proc);
  save(env);
  object_free(&proc);
  proc = lookup_var_val(c_str_to_datum("|compile-linkage|"));
  object_free(&val);
  val = lookup_var_val(c_str_to_datum("|linkage|"));
  argl = cons(object_copy(val), empty);
  if (proc.type == PROC_APPLY) {
    proc = apply_proc();
    argl = apply_argl();
  }
  if (proc.type == PROC) {
    goto primitive_branch648;
  }
  cont.cont = &&after_call647;
  object_free(&val);
  val = compiled_procedure_entry(proc);
  goto *val.cont;
primitive_branch648:;
  object_free(&val);
  val = proc.proc(argl);
after_call647:;
  argl = cons(object_copy(val), empty);
  object_free(&env);
  env = restore();
  object_free(&val);
  val = lookup_var_val(c_str_to_datum("|instruction-sequence|"));
  argl = cons(object_copy(val), argl);
  object_free(&val);
  val = c_str_to_datum("(|cont| . ())");
  argl = cons(object_copy(val), argl);
  object_free(&proc);
  proc = restore();
  object_free(&cont);
  cont = restore();
  if (proc.type == PROC_APPLY) {
    proc = apply_proc();
    argl = apply_argl();
  }
  if (proc.type == PROC) {
    goto primitive_branch650;
  }
  object_free(&val);
  val = compiled_procedure_entry(proc);
  goto *val.cont;
primitive_branch650:;
  object_free(&val);
  val = proc.proc(argl);
  goto *cont.cont;
after_lambda645:;
  {
    Object t = def_var_val(c_str_to_datum("|end-with-linkage|"));
    object_free(&val);
    val = t;
  }
  object_free(&val);
  val = make_compiled_procedure(&&entry632);
  goto after_lambda631;
entry632:
  env = compiled_procedure_env();
  env = extend_environment(
      c_str_to_datum("(|exp| . (|target| . (|linkage| . ())))"));
  object_free(&proc);
  proc = lookup_var_val(c_str_to_datum("|end-with-linkage|"));
  save(cont);
  save(proc);
  save(env);
  object_free(&proc);
  proc = lookup_var_val(c_str_to_datum("|c-make-instruction-sequence|"));
  save(proc);
  save(env);
  object_free(&proc);
  proc = lookup_var_val(c_str_to_datum("|c-append|"));
  save(proc);
  object_free(&val);
  val = c_str_to_datum("(|;| . ())");
  argl = cons(object_copy(val), empty);
  save(env);
  save(argl);
  object_free(&proc);
  proc = lookup_var_val(c_str_to_datum("|const|"));
  object_free(&val);
  val = lookup_var_val(c_str_to_datum("|exp|"));
  argl = cons(object_copy(val), empty);
  if (proc.type == PROC_APPLY) {
    proc = apply_proc();
    argl = apply_argl();
  }
  if (proc.type == PROC) {
    goto primitive_branch634;
  }
  cont.cont = &&after_call633;
  object_free(&val);
  val = compiled_procedure_entry(proc);
  goto *val.cont;
primitive_branch634:;
  object_free(&val);
  val = proc.proc(argl);
after_call633:;
  object_free(&argl);
  argl = restore();
  argl = cons(object_copy(val), argl);
  object_free(&env);
  env = restore();
  save(argl);
  object_free(&proc);
  proc = lookup_var_val(c_str_to_datum("|list|"));
  object_free(&val);
  val = c_str_to_datum("| = |");
  argl = cons(object_copy(val), empty);
  object_free(&val);
  val = lookup_var_val(c_str_to_datum("|target|"));
  argl = cons(object_copy(val), argl);
  object_free(&val);
  val = c_str_to_datum("|);|");
  argl = cons(object_copy(val), argl);
  object_free(&val);
  val = lookup_var_val(c_str_to_datum("|target|"));
  argl = cons(object_copy(val), argl);
  object_free(&val);
  val = c_str_to_datum("|object_free(&|");
  argl = cons(object_copy(val), argl);
  if (proc.type == PROC_APPLY) {
    proc = apply_proc();
    argl = apply_argl();
  }
  if (proc.type == PROC) {
    goto primitive_branch636;
  }
  cont.cont = &&after_call635;
  object_free(&val);
  val = compiled_procedure_entry(proc);
  goto *val.cont;
primitive_branch636:;
  object_free(&val);
  val = proc.proc(argl);
after_call635:;
  object_free(&argl);
  argl = restore();
  argl = cons(object_copy(val), argl);
  object_free(&proc);
  proc = restore();
  if (proc.type == PROC_APPLY) {
    proc = apply_proc();
    argl = apply_argl();
  }
  if (proc.type == PROC) {
    goto primitive_branch638;
  }
  cont.cont = &&after_call637;
  object_free(&val);
  val = compiled_procedure_entry(proc);
  goto *val.cont;
primitive_branch638:;
  object_free(&val);
  val = proc.proc(argl);
after_call637:;
  argl = cons(object_copy(val), empty);
  object_free(&env);
  env = restore();
  save(argl);
  object_free(&proc);
  proc = lookup_var_val(c_str_to_datum("|list|"));
  object_free(&val);
  val = lookup_var_val(c_str_to_datum("|target|"));
  argl = cons(object_copy(val), empty);
  if (proc.type == PROC_APPLY) {
    proc = apply_proc();
    argl = apply_argl();
  }
  if (proc.type == PROC) {
    goto primitive_branch640;
  }
  cont.cont = &&after_call639;
  object_free(&val);
  val = compiled_procedure_entry(proc);
  goto *val.cont;
primitive_branch640:;
  object_free(&val);
  val = proc.proc(argl);
after_call639:;
  object_free(&argl);
  argl = restore();
  argl = cons(object_copy(val), argl);
  object_free(&val);
  val = c_str_to_datum("()");
  argl = cons(object_copy(val), argl);
  object_free(&proc);
  proc = restore();
  if (proc.type == PROC_APPLY) {
    proc = apply_proc();
    argl = apply_argl();
  }
  if (proc.type == PROC) {
    goto primitive_branch642;
  }
  cont.cont = &&after_call641;
  object_free(&val);
  val = compiled_procedure_entry(proc);
  goto *val.cont;
primitive_branch642:;
  object_free(&val);
  val = proc.proc(argl);
after_call641:;
  argl = cons(object_copy(val), empty);
  object_free(&env);
  env = restore();
  object_free(&val);
  val = lookup_var_val(c_str_to_datum("|linkage|"));
  argl = cons(object_copy(val), argl);
  object_free(&proc);
  proc = restore();
  object_free(&cont);
  cont = restore();
  if (proc.type == PROC_APPLY) {
    proc = apply_proc();
    argl = apply_argl();
  }
  if (proc.type == PROC) {
    goto primitive_branch644;
  }
  object_free(&val);
  val = compiled_procedure_entry(proc);
  goto *val.cont;
primitive_branch644:;
  object_free(&val);
  val = proc.proc(argl);
  goto *cont.cont;
after_lambda631:;
  {
    Object t = def_var_val(c_str_to_datum("|compile-self-evaluating|"));
    object_free(&val);
    val = t;
  }
  object_free(&val);
  val = make_compiled_procedure(&&entry618);
  goto after_lambda617;
entry618:
  env = compiled_procedure_env();
  env = extend_environment(
      c_str_to_datum("(|exp| . (|target| . (|linkage| . ())))"));
  object_free(&proc);
  proc = lookup_var_val(c_str_to_datum("|end-with-linkage|"));
  save(cont);
  save(proc);
  save(env);
  object_free(&proc);
  proc = lookup_var_val(c_str_to_datum("|c-make-instruction-sequence|"));
  save(proc);
  save(env);
  object_free(&proc);
  proc = lookup_var_val(c_str_to_datum("|c-append|"));
  save(proc);
  object_free(&val);
  val = c_str_to_datum("(|\\x22;));| . ())");
  argl = cons(object_copy(val), empty);
  save(env);
  save(argl);
  object_free(&proc);
  proc = lookup_var_val(c_str_to_datum("|c-symbol->c|"));
  object_free(&val);
  val = lookup_var_val(c_str_to_datum("|exp|"));
  argl = cons(object_copy(val), empty);
  if (proc.type == PROC_APPLY) {
    proc = apply_proc();
    argl = apply_argl();
  }
  if (proc.type == PROC) {
    goto primitive_branch620;
  }
  cont.cont = &&after_call619;
  object_free(&val);
  val = compiled_procedure_entry(proc);
  goto *val.cont;
primitive_branch620:;
  object_free(&val);
  val = proc.proc(argl);
after_call619:;
  object_free(&argl);
  argl = restore();
  argl = cons(object_copy(val), argl);
  object_free(&env);
  env = restore();
  save(argl);
  object_free(&proc);
  proc = lookup_var_val(c_str_to_datum("|list|"));
  object_free(&val);
  val = c_str_to_datum("| = lookup_var_val(c_str_to_datum(\\x22;|");
  argl = cons(object_copy(val), empty);
  object_free(&val);
  val = lookup_var_val(c_str_to_datum("|target|"));
  argl = cons(object_copy(val), argl);
  object_free(&val);
  val = c_str_to_datum("|);|");
  argl = cons(object_copy(val), argl);
  object_free(&val);
  val = lookup_var_val(c_str_to_datum("|target|"));
  argl = cons(object_copy(val), argl);
  object_free(&val);
  val = c_str_to_datum("|object_free(&|");
  argl = cons(object_copy(val), argl);
  if (proc.type == PROC_APPLY) {
    proc = apply_proc();
    argl = apply_argl();
  }
  if (proc.type == PROC) {
    goto primitive_branch622;
  }
  cont.cont = &&after_call621;
  object_free(&val);
  val = compiled_procedure_entry(proc);
  goto *val.cont;
primitive_branch622:;
  object_free(&val);
  val = proc.proc(argl);
after_call621:;
  object_free(&argl);
  argl = restore();
  argl = cons(object_copy(val), argl);
  object_free(&proc);
  proc = restore();
  if (proc.type == PROC_APPLY) {
    proc = apply_proc();
    argl = apply_argl();
  }
  if (proc.type == PROC) {
    goto primitive_branch624;
  }
  cont.cont = &&after_call623;
  object_free(&val);
  val = compiled_procedure_entry(proc);
  goto *val.cont;
primitive_branch624:;
  object_free(&val);
  val = proc.proc(argl);
after_call623:;
  argl = cons(object_copy(val), empty);
  object_free(&env);
  env = restore();
  save(argl);
  object_free(&proc);
  proc = lookup_var_val(c_str_to_datum("|list|"));
  object_free(&val);
  val = lookup_var_val(c_str_to_datum("|target|"));
  argl = cons(object_copy(val), empty);
  if (proc.type == PROC_APPLY) {
    proc = apply_proc();
    argl = apply_argl();
  }
  if (proc.type == PROC) {
    goto primitive_branch626;
  }
  cont.cont = &&after_call625;
  object_free(&val);
  val = compiled_procedure_entry(proc);
  goto *val.cont;
primitive_branch626:;
  object_free(&val);
  val = proc.proc(argl);
after_call625:;
  object_free(&argl);
  argl = restore();
  argl = cons(object_copy(val), argl);
  object_free(&val);
  val = c_str_to_datum("(|env| . ())");
  argl = cons(object_copy(val), argl);
  object_free(&proc);
  proc = restore();
  if (proc.type == PROC_APPLY) {
    proc = apply_proc();
    argl = apply_argl();
  }
  if (proc.type == PROC) {
    goto primitive_branch628;
  }
  cont.cont = &&after_call627;
  object_free(&val);
  val = compiled_procedure_entry(proc);
  goto *val.cont;
primitive_branch628:;
  object_free(&val);
  val = proc.proc(argl);
after_call627:;
  argl = cons(object_copy(val), empty);
  object_free(&env);
  env = restore();
  object_free(&val);
  val = lookup_var_val(c_str_to_datum("|linkage|"));
  argl = cons(object_copy(val), argl);
  object_free(&proc);
  proc = restore();
  object_free(&cont);
  cont = restore();
  if (proc.type == PROC_APPLY) {
    proc = apply_proc();
    argl = apply_argl();
  }
  if (proc.type == PROC) {
    goto primitive_branch630;
  }
  object_free(&val);
  val = compiled_procedure_entry(proc);
  goto *val.cont;
primitive_branch630:;
  object_free(&val);
  val = proc.proc(argl);
  goto *cont.cont;
after_lambda617:;
  {
    Object t = def_var_val(c_str_to_datum("|compile-variable|"));
    object_free(&val);
    val = t;
  }
  object_free(&val);
  val = make_compiled_procedure(&&entry602);
  goto after_lambda601;
entry602:
  env = compiled_procedure_env();
  env = extend_environment(
      c_str_to_datum("(|exp| . (|target| . (|linkage| . ())))"));
  object_free(&proc);
  proc = lookup_var_val(c_str_to_datum("|end-with-linkage|"));
  save(cont);
  save(proc);
  save(env);
  object_free(&proc);
  proc = lookup_var_val(c_str_to_datum("|c-make-instruction-sequence|"));
  save(proc);
  save(env);
  object_free(&proc);
  proc = lookup_var_val(c_str_to_datum("|c-append|"));
  save(proc);
  object_free(&val);
  val = c_str_to_datum("(|;| . ())");
  argl = cons(object_copy(val), empty);
  save(env);
  save(argl);
  object_free(&proc);
  proc = lookup_var_val(c_str_to_datum("|const|"));
  save(proc);
  object_free(&proc);
  proc = lookup_var_val(c_str_to_datum("|c-cadr|"));
  object_free(&val);
  val = lookup_var_val(c_str_to_datum("|exp|"));
  argl = cons(object_copy(val), empty);
  if (proc.type == PROC_APPLY) {
    proc = apply_proc();
    argl = apply_argl();
  }
  if (proc.type == PROC) {
    goto primitive_branch604;
  }
  cont.cont = &&after_call603;
  object_free(&val);
  val = compiled_procedure_entry(proc);
  goto *val.cont;
primitive_branch604:;
  object_free(&val);
  val = proc.proc(argl);
after_call603:;
  argl = cons(object_copy(val), empty);
  object_free(&proc);
  proc = restore();
  if (proc.type == PROC_APPLY) {
    proc = apply_proc();
    argl = apply_argl();
  }
  if (proc.type == PROC) {
    goto primitive_branch606;
  }
  cont.cont = &&after_call605;
  object_free(&val);
  val = compiled_procedure_entry(proc);
  goto *val.cont;
primitive_branch606:;
  object_free(&val);
  val = proc.proc(argl);
after_call605:;
  object_free(&argl);
  argl = restore();
  argl = cons(object_copy(val), argl);
  object_free(&env);
  env = restore();
  save(argl);
  object_free(&proc);
  proc = lookup_var_val(c_str_to_datum("|list|"));
  object_free(&val);
  val = c_str_to_datum("| = |");
  argl = cons(object_copy(val), empty);
  object_free(&val);
  val = lookup_var_val(c_str_to_datum("|target|"));
  argl = cons(object_copy(val), argl);
  object_free(&val);
  val = c_str_to_datum("|);|");
  argl = cons(object_copy(val), argl);
  object_free(&val);
  val = lookup_var_val(c_str_to_datum("|target|"));
  argl = cons(object_copy(val), argl);
  object_free(&val);
  val = c_str_to_datum("|object_free(&|");
  argl = cons(object_copy(val), argl);
  if (proc.type == PROC_APPLY) {
    proc = apply_proc();
    argl = apply_argl();
  }
  if (proc.type == PROC) {
    goto primitive_branch608;
  }
  cont.cont = &&after_call607;
  object_free(&val);
  val = compiled_procedure_entry(proc);
  goto *val.cont;
primitive_branch608:;
  object_free(&val);
  val = proc.proc(argl);
after_call607:;
  object_free(&argl);
  argl = restore();
  argl = cons(object_copy(val), argl);
  object_free(&proc);
  proc = restore();
  if (proc.type == PROC_APPLY) {
    proc = apply_proc();
    argl = apply_argl();
  }
  if (proc.type == PROC) {
    goto primitive_branch610;
  }
  cont.cont = &&after_call609;
  object_free(&val);
  val = compiled_procedure_entry(proc);
  goto *val.cont;
primitive_branch610:;
  object_free(&val);
  val = proc.proc(argl);
after_call609:;
  argl = cons(object_copy(val), empty);
  object_free(&env);
  env = restore();
  save(argl);
  object_free(&proc);
  proc = lookup_var_val(c_str_to_datum("|list|"));
  object_free(&val);
  val = lookup_var_val(c_str_to_datum("|target|"));
  argl = cons(object_copy(val), empty);
  if (proc.type == PROC_APPLY) {
    proc = apply_proc();
    argl = apply_argl();
  }
  if (proc.type == PROC) {
    goto primitive_branch612;
  }
  cont.cont = &&after_call611;
  object_free(&val);
  val = compiled_procedure_entry(proc);
  goto *val.cont;
primitive_branch612:;
  object_free(&val);
  val = proc.proc(argl);
after_call611:;
  object_free(&argl);
  argl = restore();
  argl = cons(object_copy(val), argl);
  object_free(&val);
  val = c_str_to_datum("()");
  argl = cons(object_copy(val), argl);
  object_free(&proc);
  proc = restore();
  if (proc.type == PROC_APPLY) {
    proc = apply_proc();
    argl = apply_argl();
  }
  if (proc.type == PROC) {
    goto primitive_branch614;
  }
  cont.cont = &&after_call613;
  object_free(&val);
  val = compiled_procedure_entry(proc);
  goto *val.cont;
primitive_branch614:;
  object_free(&val);
  val = proc.proc(argl);
after_call613:;
  argl = cons(object_copy(val), empty);
  object_free(&env);
  env = restore();
  object_free(&val);
  val = lookup_var_val(c_str_to_datum("|linkage|"));
  argl = cons(object_copy(val), argl);
  object_free(&proc);
  proc = restore();
  object_free(&cont);
  cont = restore();
  if (proc.type == PROC_APPLY) {
    proc = apply_proc();
    argl = apply_argl();
  }
  if (proc.type == PROC) {
    goto primitive_branch616;
  }
  object_free(&val);
  val = compiled_procedure_entry(proc);
  goto *val.cont;
primitive_branch616:;
  object_free(&val);
  val = proc.proc(argl);
  goto *cont.cont;
after_lambda601:;
  {
    Object t = def_var_val(c_str_to_datum("|compile-quoted|"));
    object_free(&val);
    val = t;
  }
  object_free(&val);
  val = make_compiled_procedure(&&entry576);
  goto after_lambda575;
entry576:
  env = compiled_procedure_env();
  env = extend_environment(
      c_str_to_datum("(|exp| . (|target| . (|linkage| . ())))"));
  object_free(&proc);
  proc = make_compiled_procedure(&&entry584);
  goto after_lambda583;
entry584:
  env = compiled_procedure_env();
  env = extend_environment(c_str_to_datum("(|var| . (|get-value-code| . ()))"));
  object_free(&proc);
  proc = lookup_var_val(c_str_to_datum("|end-with-linkage|"));
  save(cont);
  save(proc);
  save(env);
  object_free(&proc);
  proc = lookup_var_val(c_str_to_datum("|preserving|"));
  save(proc);
  save(env);
  object_free(&proc);
  proc = lookup_var_val(c_str_to_datum("|c-make-instruction-sequence|"));
  save(proc);
  save(env);
  object_free(&proc);
  proc = lookup_var_val(c_str_to_datum("|c-append|"));
  save(proc);
  save(env);
  object_free(&proc);
  proc = lookup_var_val(c_str_to_datum("|list|"));
  object_free(&val);
  val = c_str_to_datum("| = t;}|");
  argl = cons(object_copy(val), empty);
  object_free(&val);
  val = lookup_var_val(c_str_to_datum("|target|"));
  argl = cons(object_copy(val), argl);
  object_free(&val);
  val = c_str_to_datum("|);|");
  argl = cons(object_copy(val), argl);
  object_free(&val);
  val = lookup_var_val(c_str_to_datum("|target|"));
  argl = cons(object_copy(val), argl);
  object_free(&val);
  val = c_str_to_datum(
      "|\\x22;));\\n                                   object_free(&|");
  argl = cons(object_copy(val), argl);
  if (proc.type == PROC_APPLY) {
    proc = apply_proc();
    argl = apply_argl();
  }
  if (proc.type == PROC) {
    goto primitive_branch586;
  }
  cont.cont = &&after_call585;
  object_free(&val);
  val = compiled_procedure_entry(proc);
  goto *val.cont;
primitive_branch586:;
  object_free(&val);
  val = proc.proc(argl);
after_call585:;
  argl = cons(object_copy(val), empty);
  object_free(&env);
  env = restore();
  save(argl);
  object_free(&proc);
  proc = lookup_var_val(c_str_to_datum("|c-symbol->c|"));
  object_free(&val);
  val = lookup_var_val(c_str_to_datum("|var|"));
  argl = cons(object_copy(val), empty);
  if (proc.type == PROC_APPLY) {
    proc = apply_proc();
    argl = apply_argl();
  }
  if (proc.type == PROC) {
    goto primitive_branch588;
  }
  cont.cont = &&after_call587;
  object_free(&val);
  val = compiled_procedure_entry(proc);
  goto *val.cont;
primitive_branch588:;
  object_free(&val);
  val = proc.proc(argl);
after_call587:;
  object_free(&argl);
  argl = restore();
  argl = cons(object_copy(val), argl);
  object_free(&val);
  val =
      c_str_to_datum("(|{Object t = set_var_val(c_str_to_datum(\\x22;| . ())");
  argl = cons(object_copy(val), argl);
  object_free(&proc);
  proc = restore();
  if (proc.type == PROC_APPLY) {
    proc = apply_proc();
    argl = apply_argl();
  }
  if (proc.type == PROC) {
    goto primitive_branch590;
  }
  cont.cont = &&after_call589;
  object_free(&val);
  val = compiled_procedure_entry(proc);
  goto *val.cont;
primitive_branch590:;
  object_free(&val);
  val = proc.proc(argl);
after_call589:;
  argl = cons(object_copy(val), empty);
  object_free(&env);
  env = restore();
  save(argl);
  object_free(&proc);
  proc = lookup_var_val(c_str_to_datum("|list|"));
  object_free(&val);
  val = lookup_var_val(c_str_to_datum("|target|"));
  argl = cons(object_copy(val), empty);
  if (proc.type == PROC_APPLY) {
    proc = apply_proc();
    argl = apply_argl();
  }
  if (proc.type == PROC) {
    goto primitive_branch592;
  }
  cont.cont = &&after_call591;
  object_free(&val);
  val = compiled_procedure_entry(proc);
  goto *val.cont;
primitive_branch592:;
  object_free(&val);
  val = proc.proc(argl);
after_call591:;
  object_free(&argl);
  argl = restore();
  argl = cons(object_copy(val), argl);
  object_free(&val);
  val = c_str_to_datum("(|env| . (|val| . ()))");
  argl = cons(object_copy(val), argl);
  object_free(&proc);
  proc = restore();
  if (proc.type == PROC_APPLY) {
    proc = apply_proc();
    argl = apply_argl();
  }
  if (proc.type == PROC) {
    goto primitive_branch594;
  }
  cont.cont = &&after_call593;
  object_free(&val);
  val = compiled_procedure_entry(proc);
  goto *val.cont;
primitive_branch594:;
  object_free(&val);
  val = proc.proc(argl);
after_call593:;
  argl = cons(object_copy(val), empty);
  object_free(&env);
  env = restore();
  object_free(&val);
  val = lookup_var_val(c_str_to_datum("|get-value-code|"));
  argl = cons(object_copy(val), argl);
  object_free(&val);
  val = c_str_to_datum("(|env| . ())");
  argl = cons(object_copy(val), argl);
  object_free(&proc);
  proc = restore();
  if (proc.type == PROC_APPLY) {
    proc = apply_proc();
    argl = apply_argl();
  }
  if (proc.type == PROC) {
    goto primitive_branch596;
  }
  cont.cont = &&after_call595;
  object_free(&val);
  val = compiled_procedure_entry(proc);
  goto *val.cont;
primitive_branch596:;
  object_free(&val);
  val = proc.proc(argl);
after_call595:;
  argl = cons(object_copy(val), empty);
  object_free(&env);
  env = restore();
  object_free(&val);
  val = lookup_var_val(c_str_to_datum("|linkage|"));
  argl = cons(object_copy(val), argl);
  object_free(&proc);
  proc = restore();
  object_free(&cont);
  cont = restore();
  if (proc.type == PROC_APPLY) {
    proc = apply_proc();
    argl = apply_argl();
  }
  if (proc.type == PROC) {
    goto primitive_branch598;
  }
  object_free(&val);
  val = compiled_procedure_entry(proc);
  goto *val.cont;
primitive_branch598:;
  object_free(&val);
  val = proc.proc(argl);
  goto *cont.cont;
after_lambda583:;
  save(cont);
  save(proc);
  save(env);
  object_free(&proc);
  proc = lookup_var_val(c_str_to_datum("|compile|"));
  save(proc);
  object_free(&val);
  val = c_str_to_datum("|next|");
  argl = cons(object_copy(val), empty);
  object_free(&val);
  val = c_str_to_datum("|val|");
  argl = cons(object_copy(val), argl);
  save(argl);
  object_free(&proc);
  proc = lookup_var_val(c_str_to_datum("|c-caddr|"));
  object_free(&val);
  val = lookup_var_val(c_str_to_datum("|exp|"));
  argl = cons(object_copy(val), empty);
  if (proc.type == PROC_APPLY) {
    proc = apply_proc();
    argl = apply_argl();
  }
  if (proc.type == PROC) {
    goto primitive_branch578;
  }
  cont.cont = &&after_call577;
  object_free(&val);
  val = compiled_procedure_entry(proc);
  goto *val.cont;
primitive_branch578:;
  object_free(&val);
  val = proc.proc(argl);
after_call577:;
  object_free(&argl);
  argl = restore();
  argl = cons(object_copy(val), argl);
  object_free(&proc);
  proc = restore();
  if (proc.type == PROC_APPLY) {
    proc = apply_proc();
    argl = apply_argl();
  }
  if (proc.type == PROC) {
    goto primitive_branch580;
  }
  cont.cont = &&after_call579;
  object_free(&val);
  val = compiled_procedure_entry(proc);
  goto *val.cont;
primitive_branch580:;
  object_free(&val);
  val = proc.proc(argl);
after_call579:;
  argl = cons(object_copy(val), empty);
  object_free(&env);
  env = restore();
  save(argl);
  object_free(&proc);
  proc = lookup_var_val(c_str_to_datum("|c-cadr|"));
  object_free(&val);
  val = lookup_var_val(c_str_to_datum("|exp|"));
  argl = cons(object_copy(val), empty);
  if (proc.type == PROC_APPLY) {
    proc = apply_proc();
    argl = apply_argl();
  }
  if (proc.type == PROC) {
    goto primitive_branch582;
  }
  cont.cont = &&after_call581;
  object_free(&val);
  val = compiled_procedure_entry(proc);
  goto *val.cont;
primitive_branch582:;
  object_free(&val);
  val = proc.proc(argl);
after_call581:;
  object_free(&argl);
  argl = restore();
  argl = cons(object_copy(val), argl);
  object_free(&proc);
  proc = restore();
  object_free(&cont);
  cont = restore();
  if (proc.type == PROC_APPLY) {
    proc = apply_proc();
    argl = apply_argl();
  }
  if (proc.type == PROC) {
    goto primitive_branch600;
  }
  object_free(&val);
  val = compiled_procedure_entry(proc);
  goto *val.cont;
primitive_branch600:;
  object_free(&val);
  val = proc.proc(argl);
  goto *cont.cont;
after_lambda575:;
  {
    Object t = def_var_val(c_str_to_datum("|compile-assignment|"));
    object_free(&val);
    val = t;
  }
  object_free(&val);
  val = make_compiled_procedure(&&entry550);
  goto after_lambda549;
entry550:
  env = compiled_procedure_env();
  env = extend_environment(
      c_str_to_datum("(|exp| . (|target| . (|linkage| . ())))"));
  object_free(&proc);
  proc = make_compiled_procedure(&&entry558);
  goto after_lambda557;
entry558:
  env = compiled_procedure_env();
  env = extend_environment(c_str_to_datum("(|var| . (|get-value-code| . ()))"));
  object_free(&proc);
  proc = lookup_var_val(c_str_to_datum("|end-with-linkage|"));
  save(cont);
  save(proc);
  save(env);
  object_free(&proc);
  proc = lookup_var_val(c_str_to_datum("|preserving|"));
  save(proc);
  save(env);
  object_free(&proc);
  proc = lookup_var_val(c_str_to_datum("|c-make-instruction-sequence|"));
  save(proc);
  save(env);
  object_free(&proc);
  proc = lookup_var_val(c_str_to_datum("|c-append|"));
  save(proc);
  save(env);
  object_free(&proc);
  proc = lookup_var_val(c_str_to_datum("|list|"));
  object_free(&val);
  val = c_str_to_datum("| = t;}|");
  argl = cons(object_copy(val), empty);
  object_free(&val);
  val = lookup_var_val(c_str_to_datum("|target|"));
  argl = cons(object_copy(val), argl);
  object_free(&val);
  val = c_str_to_datum("|);|");
  argl = cons(object_copy(val), argl);
  object_free(&val);
  val = lookup_var_val(c_str_to_datum("|target|"));
  argl = cons(object_copy(val), argl);
  object_free(&val);
  val = c_str_to_datum(
      "|\\x22;));\\n                                   object_free(&|");
  argl = cons(object_copy(val), argl);
  if (proc.type == PROC_APPLY) {
    proc = apply_proc();
    argl = apply_argl();
  }
  if (proc.type == PROC) {
    goto primitive_branch560;
  }
  cont.cont = &&after_call559;
  object_free(&val);
  val = compiled_procedure_entry(proc);
  goto *val.cont;
primitive_branch560:;
  object_free(&val);
  val = proc.proc(argl);
after_call559:;
  argl = cons(object_copy(val), empty);
  object_free(&env);
  env = restore();
  save(argl);
  object_free(&proc);
  proc = lookup_var_val(c_str_to_datum("|c-symbol->c|"));
  object_free(&val);
  val = lookup_var_val(c_str_to_datum("|var|"));
  argl = cons(object_copy(val), empty);
  if (proc.type == PROC_APPLY) {
    proc = apply_proc();
    argl = apply_argl();
  }
  if (proc.type == PROC) {
    goto primitive_branch562;
  }
  cont.cont = &&after_call561;
  object_free(&val);
  val = compiled_procedure_entry(proc);
  goto *val.cont;
primitive_branch562:;
  object_free(&val);
  val = proc.proc(argl);
after_call561:;
  object_free(&argl);
  argl = restore();
  argl = cons(object_copy(val), argl);
  object_free(&val);
  val =
      c_str_to_datum("(|{Object t = def_var_val(c_str_to_datum(\\x22;| . ())");
  argl = cons(object_copy(val), argl);
  object_free(&proc);
  proc = restore();
  if (proc.type == PROC_APPLY) {
    proc = apply_proc();
    argl = apply_argl();
  }
  if (proc.type == PROC) {
    goto primitive_branch564;
  }
  cont.cont = &&after_call563;
  object_free(&val);
  val = compiled_procedure_entry(proc);
  goto *val.cont;
primitive_branch564:;
  object_free(&val);
  val = proc.proc(argl);
after_call563:;
  argl = cons(object_copy(val), empty);
  object_free(&env);
  env = restore();
  save(argl);
  object_free(&proc);
  proc = lookup_var_val(c_str_to_datum("|list|"));
  object_free(&val);
  val = lookup_var_val(c_str_to_datum("|target|"));
  argl = cons(object_copy(val), empty);
  if (proc.type == PROC_APPLY) {
    proc = apply_proc();
    argl = apply_argl();
  }
  if (proc.type == PROC) {
    goto primitive_branch566;
  }
  cont.cont = &&after_call565;
  object_free(&val);
  val = compiled_procedure_entry(proc);
  goto *val.cont;
primitive_branch566:;
  object_free(&val);
  val = proc.proc(argl);
after_call565:;
  object_free(&argl);
  argl = restore();
  argl = cons(object_copy(val), argl);
  object_free(&val);
  val = c_str_to_datum("(|env| . (|val| . ()))");
  argl = cons(object_copy(val), argl);
  object_free(&proc);
  proc = restore();
  if (proc.type == PROC_APPLY) {
    proc = apply_proc();
    argl = apply_argl();
  }
  if (proc.type == PROC) {
    goto primitive_branch568;
  }
  cont.cont = &&after_call567;
  object_free(&val);
  val = compiled_procedure_entry(proc);
  goto *val.cont;
primitive_branch568:;
  object_free(&val);
  val = proc.proc(argl);
after_call567:;
  argl = cons(object_copy(val), empty);
  object_free(&env);
  env = restore();
  object_free(&val);
  val = lookup_var_val(c_str_to_datum("|get-value-code|"));
  argl = cons(object_copy(val), argl);
  object_free(&val);
  val = c_str_to_datum("(|env| . ())");
  argl = cons(object_copy(val), argl);
  object_free(&proc);
  proc = restore();
  if (proc.type == PROC_APPLY) {
    proc = apply_proc();
    argl = apply_argl();
  }
  if (proc.type == PROC) {
    goto primitive_branch570;
  }
  cont.cont = &&after_call569;
  object_free(&val);
  val = compiled_procedure_entry(proc);
  goto *val.cont;
primitive_branch570:;
  object_free(&val);
  val = proc.proc(argl);
after_call569:;
  argl = cons(object_copy(val), empty);
  object_free(&env);
  env = restore();
  object_free(&val);
  val = lookup_var_val(c_str_to_datum("|linkage|"));
  argl = cons(object_copy(val), argl);
  object_free(&proc);
  proc = restore();
  object_free(&cont);
  cont = restore();
  if (proc.type == PROC_APPLY) {
    proc = apply_proc();
    argl = apply_argl();
  }
  if (proc.type == PROC) {
    goto primitive_branch572;
  }
  object_free(&val);
  val = compiled_procedure_entry(proc);
  goto *val.cont;
primitive_branch572:;
  object_free(&val);
  val = proc.proc(argl);
  goto *cont.cont;
after_lambda557:;
  save(cont);
  save(proc);
  save(env);
  object_free(&proc);
  proc = lookup_var_val(c_str_to_datum("|compile|"));
  save(proc);
  object_free(&val);
  val = c_str_to_datum("|next|");
  argl = cons(object_copy(val), empty);
  object_free(&val);
  val = c_str_to_datum("|val|");
  argl = cons(object_copy(val), argl);
  save(argl);
  object_free(&proc);
  proc = lookup_var_val(c_str_to_datum("|definition-value|"));
  object_free(&val);
  val = lookup_var_val(c_str_to_datum("|exp|"));
  argl = cons(object_copy(val), empty);
  if (proc.type == PROC_APPLY) {
    proc = apply_proc();
    argl = apply_argl();
  }
  if (proc.type == PROC) {
    goto primitive_branch552;
  }
  cont.cont = &&after_call551;
  object_free(&val);
  val = compiled_procedure_entry(proc);
  goto *val.cont;
primitive_branch552:;
  object_free(&val);
  val = proc.proc(argl);
after_call551:;
  object_free(&argl);
  argl = restore();
  argl = cons(object_copy(val), argl);
  object_free(&proc);
  proc = restore();
  if (proc.type == PROC_APPLY) {
    proc = apply_proc();
    argl = apply_argl();
  }
  if (proc.type == PROC) {
    goto primitive_branch554;
  }
  cont.cont = &&after_call553;
  object_free(&val);
  val = compiled_procedure_entry(proc);
  goto *val.cont;
primitive_branch554:;
  object_free(&val);
  val = proc.proc(argl);
after_call553:;
  argl = cons(object_copy(val), empty);
  object_free(&env);
  env = restore();
  save(argl);
  object_free(&proc);
  proc = lookup_var_val(c_str_to_datum("|c-definition-variable|"));
  object_free(&val);
  val = lookup_var_val(c_str_to_datum("|exp|"));
  argl = cons(object_copy(val), empty);
  if (proc.type == PROC_APPLY) {
    proc = apply_proc();
    argl = apply_argl();
  }
  if (proc.type == PROC) {
    goto primitive_branch556;
  }
  cont.cont = &&after_call555;
  object_free(&val);
  val = compiled_procedure_entry(proc);
  goto *val.cont;
primitive_branch556:;
  object_free(&val);
  val = proc.proc(argl);
after_call555:;
  object_free(&argl);
  argl = restore();
  argl = cons(object_copy(val), argl);
  object_free(&proc);
  proc = restore();
  object_free(&cont);
  cont = restore();
  if (proc.type == PROC_APPLY) {
    proc = apply_proc();
    argl = apply_argl();
  }
  if (proc.type == PROC) {
    goto primitive_branch574;
  }
  object_free(&val);
  val = compiled_procedure_entry(proc);
  goto *val.cont;
primitive_branch574:;
  object_free(&val);
  val = proc.proc(argl);
  goto *cont.cont;
after_lambda549:;
  {
    Object t = def_var_val(c_str_to_datum("|compile-definition|"));
    object_free(&val);
    val = t;
  }
  object_free(&val);
  val = make_compiled_procedure(&&entry490);
  goto after_lambda489;
entry490:
  env = compiled_procedure_env();
  env = extend_environment(
      c_str_to_datum("(|exp| . (|target| . (|linkage| . ())))"));
  object_free(&proc);
  proc = make_compiled_procedure(&&entry496);
  goto after_lambda495;
entry496:
  env = compiled_procedure_env();
  env = extend_environment(c_str_to_datum("(|f-branch| . (|after-if| . ()))"));
  object_free(&proc);
  proc = make_compiled_procedure(&&entry502);
  goto after_lambda501;
entry502:
  env = compiled_procedure_env();
  env = extend_environment(c_str_to_datum("(|consequent-linkage| . ())"));
  object_free(&proc);
  proc = make_compiled_procedure(&&entry516);
  goto after_lambda515;
entry516:
  env = compiled_procedure_env();
  env = extend_environment(
      c_str_to_datum("(|p-code| . (|c-code| . (|a-code| . ())))"));
  object_free(&proc);
  proc = lookup_var_val(c_str_to_datum("|preserving|"));
  save(cont);
  save(proc);
  save(env);
  object_free(&proc);
  proc = lookup_var_val(c_str_to_datum("|append-instruction-sequences|"));
  save(proc);
  save(env);
  save(env);
  object_free(&proc);
  proc = lookup_var_val(c_str_to_datum("|eq?|"));
  object_free(&val);
  val = c_str_to_datum("|next|");
  argl = cons(object_copy(val), empty);
  object_free(&val);
  val = lookup_var_val(c_str_to_datum("|linkage|"));
  argl = cons(object_copy(val), argl);
  if (proc.type == PROC_APPLY) {
    proc = apply_proc();
    argl = apply_argl();
  }
  if (proc.type == PROC) {
    goto primitive_branch526;
  }
  cont.cont = &&after_call525;
  object_free(&val);
  val = compiled_procedure_entry(proc);
  goto *val.cont;
primitive_branch526:;
  object_free(&val);
  val = proc.proc(argl);
after_call525:;
  object_free(&env);
  env = restore();
  if (val.type == BOOLEAN && !val.boolean) {
    goto false_branch518;
  }
  object_free(&proc);
  proc = lookup_var_val(c_str_to_datum("|c-make-instruction-sequence|"));
  save(proc);
  object_free(&proc);
  proc = lookup_var_val(c_str_to_datum("|list|"));
  object_free(&val);
  val = c_str_to_datum("|:;|");
  argl = cons(object_copy(val), empty);
  object_free(&val);
  val = lookup_var_val(c_str_to_datum("|after-if|"));
  argl = cons(object_copy(val), argl);
  if (proc.type == PROC_APPLY) {
    proc = apply_proc();
    argl = apply_argl();
  }
  if (proc.type == PROC) {
    goto primitive_branch522;
  }
  cont.cont = &&after_call521;
  object_free(&val);
  val = compiled_procedure_entry(proc);
  goto *val.cont;
primitive_branch522:;
  object_free(&val);
  val = proc.proc(argl);
after_call521:;
  argl = cons(object_copy(val), empty);
  object_free(&val);
  val = c_str_to_datum("()");
  argl = cons(object_copy(val), argl);
  object_free(&val);
  val = c_str_to_datum("()");
  argl = cons(object_copy(val), argl);
  object_free(&proc);
  proc = restore();
  if (proc.type == PROC_APPLY) {
    proc = apply_proc();
    argl = apply_argl();
  }
  if (proc.type == PROC) {
    goto primitive_branch524;
  }
  cont.cont = &&after_if517;
  object_free(&val);
  val = compiled_procedure_entry(proc);
  goto *val.cont;
primitive_branch524:;
  object_free(&val);
  val = proc.proc(argl);
  goto after_if517;
false_branch518:;
  object_free(&proc);
  proc = lookup_var_val(c_str_to_datum("|c-empty-instruction-sequence|"));
  argl = empty;
  if (proc.type == PROC_APPLY) {
    proc = apply_proc();
    argl = apply_argl();
  }
  if (proc.type == PROC) {
    goto primitive_branch520;
  }
  cont.cont = &&after_call519;
  object_free(&val);
  val = compiled_procedure_entry(proc);
  goto *val.cont;
primitive_branch520:;
  object_free(&val);
  val = proc.proc(argl);
after_call519:;
after_if517:;
  argl = cons(object_copy(val), empty);
  object_free(&env);
  env = restore();
  save(env);
  save(argl);
  object_free(&proc);
  proc = lookup_var_val(c_str_to_datum("|parallel-instruction-sequences|"));
  save(proc);
  save(env);
  object_free(&proc);
  proc = lookup_var_val(c_str_to_datum("|append-instruction-sequences|"));
  save(proc);
  object_free(&val);
  val = lookup_var_val(c_str_to_datum("|a-code|"));
  argl = cons(object_copy(val), empty);
  save(argl);
  object_free(&proc);
  proc = lookup_var_val(c_str_to_datum("|c-make-instruction-sequence|"));
  save(proc);
  object_free(&proc);
  proc = lookup_var_val(c_str_to_datum("|list|"));
  object_free(&val);
  val = c_str_to_datum("|:;|");
  argl = cons(object_copy(val), empty);
  object_free(&val);
  val = lookup_var_val(c_str_to_datum("|f-branch|"));
  argl = cons(object_copy(val), argl);
  if (proc.type == PROC_APPLY) {
    proc = apply_proc();
    argl = apply_argl();
  }
  if (proc.type == PROC) {
    goto primitive_branch528;
  }
  cont.cont = &&after_call527;
  object_free(&val);
  val = compiled_procedure_entry(proc);
  goto *val.cont;
primitive_branch528:;
  object_free(&val);
  val = proc.proc(argl);
after_call527:;
  argl = cons(object_copy(val), empty);
  object_free(&val);
  val = c_str_to_datum("()");
  argl = cons(object_copy(val), argl);
  object_free(&val);
  val = c_str_to_datum("()");
  argl = cons(object_copy(val), argl);
  object_free(&proc);
  proc = restore();
  if (proc.type == PROC_APPLY) {
    proc = apply_proc();
    argl = apply_argl();
  }
  if (proc.type == PROC) {
    goto primitive_branch530;
  }
  cont.cont = &&after_call529;
  object_free(&val);
  val = compiled_procedure_entry(proc);
  goto *val.cont;
primitive_branch530:;
  object_free(&val);
  val = proc.proc(argl);
after_call529:;
  object_free(&argl);
  argl = restore();
  argl = cons(object_copy(val), argl);
  object_free(&proc);
  proc = restore();
  if (proc.type == PROC_APPLY) {
    proc = apply_proc();
    argl = apply_argl();
  }
  if (proc.type == PROC) {
    goto primitive_branch532;
  }
  cont.cont = &&after_call531;
  object_free(&val);
  val = compiled_procedure_entry(proc);
  goto *val.cont;
primitive_branch532:;
  object_free(&val);
  val = proc.proc(argl);
after_call531:;
  argl = cons(object_copy(val), empty);
  object_free(&env);
  env = restore();
  object_free(&val);
  val = lookup_var_val(c_str_to_datum("|c-code|"));
  argl = cons(object_copy(val), argl);
  object_free(&proc);
  proc = restore();
  if (proc.type == PROC_APPLY) {
    proc = apply_proc();
    argl = apply_argl();
  }
  if (proc.type == PROC) {
    goto primitive_branch534;
  }
  cont.cont = &&after_call533;
  object_free(&val);
  val = compiled_procedure_entry(proc);
  goto *val.cont;
primitive_branch534:;
  object_free(&val);
  val = proc.proc(argl);
after_call533:;
  object_free(&argl);
  argl = restore();
  argl = cons(object_copy(val), argl);
  object_free(&env);
  env = restore();
  save(argl);
  object_free(&proc);
  proc = lookup_var_val(c_str_to_datum("|c-make-instruction-sequence|"));
  save(proc);
  object_free(&proc);
  proc = lookup_var_val(c_str_to_datum("|list|"));
  object_free(&val);
  val = c_str_to_datum("|;}|");
  argl = cons(object_copy(val), empty);
  object_free(&val);
  val = lookup_var_val(c_str_to_datum("|f-branch|"));
  argl = cons(object_copy(val), argl);
  object_free(&val);
  val = c_str_to_datum("|if(val.type==BOOLEAN && !val.boolean){\\n             "
                       "           goto |");
  argl = cons(object_copy(val), argl);
  if (proc.type == PROC_APPLY) {
    proc = apply_proc();
    argl = apply_argl();
  }
  if (proc.type == PROC) {
    goto primitive_branch536;
  }
  cont.cont = &&after_call535;
  object_free(&val);
  val = compiled_procedure_entry(proc);
  goto *val.cont;
primitive_branch536:;
  object_free(&val);
  val = proc.proc(argl);
after_call535:;
  argl = cons(object_copy(val), empty);
  object_free(&val);
  val = c_str_to_datum("()");
  argl = cons(object_copy(val), argl);
  object_free(&val);
  val = c_str_to_datum("(|val| . ())");
  argl = cons(object_copy(val), argl);
  object_free(&proc);
  proc = restore();
  if (proc.type == PROC_APPLY) {
    proc = apply_proc();
    argl = apply_argl();
  }
  if (proc.type == PROC) {
    goto primitive_branch538;
  }
  cont.cont = &&after_call537;
  object_free(&val);
  val = compiled_procedure_entry(proc);
  goto *val.cont;
primitive_branch538:;
  object_free(&val);
  val = proc.proc(argl);
after_call537:;
  object_free(&argl);
  argl = restore();
  argl = cons(object_copy(val), argl);
  object_free(&proc);
  proc = restore();
  if (proc.type == PROC_APPLY) {
    proc = apply_proc();
    argl = apply_argl();
  }
  if (proc.type == PROC) {
    goto primitive_branch540;
  }
  cont.cont = &&after_call539;
  object_free(&val);
  val = compiled_procedure_entry(proc);
  goto *val.cont;
primitive_branch540:;
  object_free(&val);
  val = proc.proc(argl);
after_call539:;
  argl = cons(object_copy(val), empty);
  object_free(&env);
  env = restore();
  object_free(&val);
  val = lookup_var_val(c_str_to_datum("|p-code|"));
  argl = cons(object_copy(val), argl);
  object_free(&val);
  val = c_str_to_datum("(|env| . (|cont| . ()))");
  argl = cons(object_copy(val), argl);
  object_free(&proc);
  proc = restore();
  object_free(&cont);
  cont = restore();
  if (proc.type == PROC_APPLY) {
    proc = apply_proc();
    argl = apply_argl();
  }
  if (proc.type == PROC) {
    goto primitive_branch542;
  }
  object_free(&val);
  val = compiled_procedure_entry(proc);
  goto *val.cont;
primitive_branch542:;
  object_free(&val);
  val = proc.proc(argl);
  goto *cont.cont;
after_lambda515:;
  save(cont);
  save(proc);
  save(env);
  object_free(&proc);
  proc = lookup_var_val(c_str_to_datum("|compile|"));
  save(proc);
  object_free(&val);
  val = lookup_var_val(c_str_to_datum("|linkage|"));
  argl = cons(object_copy(val), empty);
  object_free(&val);
  val = lookup_var_val(c_str_to_datum("|target|"));
  argl = cons(object_copy(val), argl);
  save(argl);
  object_free(&proc);
  proc = lookup_var_val(c_str_to_datum("|c-if-alternative|"));
  object_free(&val);
  val = lookup_var_val(c_str_to_datum("|exp|"));
  argl = cons(object_copy(val), empty);
  if (proc.type == PROC_APPLY) {
    proc = apply_proc();
    argl = apply_argl();
  }
  if (proc.type == PROC) {
    goto primitive_branch504;
  }
  cont.cont = &&after_call503;
  object_free(&val);
  val = compiled_procedure_entry(proc);
  goto *val.cont;
primitive_branch504:;
  object_free(&val);
  val = proc.proc(argl);
after_call503:;
  object_free(&argl);
  argl = restore();
  argl = cons(object_copy(val), argl);
  object_free(&proc);
  proc = restore();
  if (proc.type == PROC_APPLY) {
    proc = apply_proc();
    argl = apply_argl();
  }
  if (proc.type == PROC) {
    goto primitive_branch506;
  }
  cont.cont = &&after_call505;
  object_free(&val);
  val = compiled_procedure_entry(proc);
  goto *val.cont;
primitive_branch506:;
  object_free(&val);
  val = proc.proc(argl);
after_call505:;
  argl = cons(object_copy(val), empty);
  object_free(&env);
  env = restore();
  save(env);
  save(argl);
  object_free(&proc);
  proc = lookup_var_val(c_str_to_datum("|compile|"));
  save(proc);
  object_free(&val);
  val = lookup_var_val(c_str_to_datum("|consequent-linkage|"));
  argl = cons(object_copy(val), empty);
  object_free(&val);
  val = lookup_var_val(c_str_to_datum("|target|"));
  argl = cons(object_copy(val), argl);
  save(argl);
  object_free(&proc);
  proc = lookup_var_val(c_str_to_datum("|c-caddr|"));
  object_free(&val);
  val = lookup_var_val(c_str_to_datum("|exp|"));
  argl = cons(object_copy(val), empty);
  if (proc.type == PROC_APPLY) {
    proc = apply_proc();
    argl = apply_argl();
  }
  if (proc.type == PROC) {
    goto primitive_branch508;
  }
  cont.cont = &&after_call507;
  object_free(&val);
  val = compiled_procedure_entry(proc);
  goto *val.cont;
primitive_branch508:;
  object_free(&val);
  val = proc.proc(argl);
after_call507:;
  object_free(&argl);
  argl = restore();
  argl = cons(object_copy(val), argl);
  object_free(&proc);
  proc = restore();
  if (proc.type == PROC_APPLY) {
    proc = apply_proc();
    argl = apply_argl();
  }
  if (proc.type == PROC) {
    goto primitive_branch510;
  }
  cont.cont = &&after_call509;
  object_free(&val);
  val = compiled_procedure_entry(proc);
  goto *val.cont;
primitive_branch510:;
  object_free(&val);
  val = proc.proc(argl);
after_call509:;
  object_free(&argl);
  argl = restore();
  argl = cons(object_copy(val), argl);
  object_free(&env);
  env = restore();
  save(argl);
  object_free(&proc);
  proc = lookup_var_val(c_str_to_datum("|compile|"));
  save(proc);
  object_free(&val);
  val = c_str_to_datum("|next|");
  argl = cons(object_copy(val), empty);
  object_free(&val);
  val = c_str_to_datum("|val|");
  argl = cons(object_copy(val), argl);
  save(argl);
  object_free(&proc);
  proc = lookup_var_val(c_str_to_datum("|c-cadr|"));
  object_free(&val);
  val = lookup_var_val(c_str_to_datum("|exp|"));
  argl = cons(object_copy(val), empty);
  if (proc.type == PROC_APPLY) {
    proc = apply_proc();
    argl = apply_argl();
  }
  if (proc.type == PROC) {
    goto primitive_branch512;
  }
  cont.cont = &&after_call511;
  object_free(&val);
  val = compiled_procedure_entry(proc);
  goto *val.cont;
primitive_branch512:;
  object_free(&val);
  val = proc.proc(argl);
after_call511:;
  object_free(&argl);
  argl = restore();
  argl = cons(object_copy(val), argl);
  object_free(&proc);
  proc = restore();
  if (proc.type == PROC_APPLY) {
    proc = apply_proc();
    argl = apply_argl();
  }
  if (proc.type == PROC) {
    goto primitive_branch514;
  }
  cont.cont = &&after_call513;
  object_free(&val);
  val = compiled_procedure_entry(proc);
  goto *val.cont;
primitive_branch514:;
  object_free(&val);
  val = proc.proc(argl);
after_call513:;
  object_free(&argl);
  argl = restore();
  argl = cons(object_copy(val), argl);
  object_free(&proc);
  proc = restore();
  object_free(&cont);
  cont = restore();
  if (proc.type == PROC_APPLY) {
    proc = apply_proc();
    argl = apply_argl();
  }
  if (proc.type == PROC) {
    goto primitive_branch544;
  }
  object_free(&val);
  val = compiled_procedure_entry(proc);
  goto *val.cont;
primitive_branch544:;
  object_free(&val);
  val = proc.proc(argl);
  goto *cont.cont;
after_lambda501:;
  save(cont);
  save(proc);
  save(env);
  object_free(&proc);
  proc = lookup_var_val(c_str_to_datum("|eq?|"));
  object_free(&val);
  val = c_str_to_datum("|next|");
  argl = cons(object_copy(val), empty);
  object_free(&val);
  val = lookup_var_val(c_str_to_datum("|linkage|"));
  argl = cons(object_copy(val), argl);
  if (proc.type == PROC_APPLY) {
    proc = apply_proc();
    argl = apply_argl();
  }
  if (proc.type == PROC) {
    goto primitive_branch500;
  }
  cont.cont = &&after_call499;
  object_free(&val);
  val = compiled_procedure_entry(proc);
  goto *val.cont;
primitive_branch500:;
  object_free(&val);
  val = proc.proc(argl);
after_call499:;
  object_free(&env);
  env = restore();
  if (val.type == BOOLEAN && !val.boolean) {
    goto false_branch498;
  }
  object_free(&val);
  val = lookup_var_val(c_str_to_datum("|after-if|"));
  goto after_if497;
false_branch498:;
  object_free(&val);
  val = lookup_var_val(c_str_to_datum("|linkage|"));
after_if497:;
  argl = cons(object_copy(val), empty);
  object_free(&proc);
  proc = restore();
  object_free(&cont);
  cont = restore();
  if (proc.type == PROC_APPLY) {
    proc = apply_proc();
    argl = apply_argl();
  }
  if (proc.type == PROC) {
    goto primitive_branch546;
  }
  object_free(&val);
  val = compiled_procedure_entry(proc);
  goto *val.cont;
primitive_branch546:;
  object_free(&val);
  val = proc.proc(argl);
  goto *cont.cont;
after_lambda495:;
  save(cont);
  save(proc);
  save(env);
  object_free(&proc);
  proc = lookup_var_val(c_str_to_datum("|make-label|"));
  object_free(&val);
  val = c_str_to_datum("|after_if|");
  argl = cons(object_copy(val), empty);
  if (proc.type == PROC_APPLY) {
    proc = apply_proc();
    argl = apply_argl();
  }
  if (proc.type == PROC) {
    goto primitive_branch492;
  }
  cont.cont = &&after_call491;
  object_free(&val);
  val = compiled_procedure_entry(proc);
  goto *val.cont;
primitive_branch492:;
  object_free(&val);
  val = proc.proc(argl);
after_call491:;
  argl = cons(object_copy(val), empty);
  object_free(&env);
  env = restore();
  save(argl);
  object_free(&proc);
  proc = lookup_var_val(c_str_to_datum("|make-label|"));
  object_free(&val);
  val = c_str_to_datum("|false_branch|");
  argl = cons(object_copy(val), empty);
  if (proc.type == PROC_APPLY) {
    proc = apply_proc();
    argl = apply_argl();
  }
  if (proc.type == PROC) {
    goto primitive_branch494;
  }
  cont.cont = &&after_call493;
  object_free(&val);
  val = compiled_procedure_entry(proc);
  goto *val.cont;
primitive_branch494:;
  object_free(&val);
  val = proc.proc(argl);
after_call493:;
  object_free(&argl);
  argl = restore();
  argl = cons(object_copy(val), argl);
  object_free(&proc);
  proc = restore();
  object_free(&cont);
  cont = restore();
  if (proc.type == PROC_APPLY) {
    proc = apply_proc();
    argl = apply_argl();
  }
  if (proc.type == PROC) {
    goto primitive_branch548;
  }
  object_free(&val);
  val = compiled_procedure_entry(proc);
  goto *val.cont;
primitive_branch548:;
  object_free(&val);
  val = proc.proc(argl);
  goto *cont.cont;
after_lambda489:;
  {
    Object t = def_var_val(c_str_to_datum("|compile-if|"));
    object_free(&val);
    val = t;
  }
  object_free(&val);
  val = make_compiled_procedure(&&entry468);
  goto after_lambda467;
entry468:
  env = compiled_procedure_env();
  env = extend_environment(
      c_str_to_datum("(|seq| . (|target| . (|linkage| . ())))"));
  save(cont);
  save(env);
  object_free(&proc);
  proc = lookup_var_val(c_str_to_datum("|null?|"));
  save(proc);
  object_free(&proc);
  proc = lookup_var_val(c_str_to_datum("|cdr|"));
  object_free(&val);
  val = lookup_var_val(c_str_to_datum("|seq|"));
  argl = cons(object_copy(val), empty);
  if (proc.type == PROC_APPLY) {
    proc = apply_proc();
    argl = apply_argl();
  }
  if (proc.type == PROC) {
    goto primitive_branch486;
  }
  cont.cont = &&after_call485;
  object_free(&val);
  val = compiled_procedure_entry(proc);
  goto *val.cont;
primitive_branch486:;
  object_free(&val);
  val = proc.proc(argl);
after_call485:;
  argl = cons(object_copy(val), empty);
  object_free(&proc);
  proc = restore();
  if (proc.type == PROC_APPLY) {
    proc = apply_proc();
    argl = apply_argl();
  }
  if (proc.type == PROC) {
    goto primitive_branch488;
  }
  cont.cont = &&after_call487;
  object_free(&val);
  val = compiled_procedure_entry(proc);
  goto *val.cont;
primitive_branch488:;
  object_free(&val);
  val = proc.proc(argl);
after_call487:;
  object_free(&env);
  env = restore();
  object_free(&cont);
  cont = restore();
  if (val.type == BOOLEAN && !val.boolean) {
    goto false_branch470;
  }
  object_free(&proc);
  proc = lookup_var_val(c_str_to_datum("|compile|"));
  save(cont);
  save(proc);
  object_free(&val);
  val = lookup_var_val(c_str_to_datum("|linkage|"));
  argl = cons(object_copy(val), empty);
  object_free(&val);
  val = lookup_var_val(c_str_to_datum("|target|"));
  argl = cons(object_copy(val), argl);
  save(argl);
  object_free(&proc);
  proc = lookup_var_val(c_str_to_datum("|car|"));
  object_free(&val);
  val = lookup_var_val(c_str_to_datum("|seq|"));
  argl = cons(object_copy(val), empty);
  if (proc.type == PROC_APPLY) {
    proc = apply_proc();
    argl = apply_argl();
  }
  if (proc.type == PROC) {
    goto primitive_branch482;
  }
  cont.cont = &&after_call481;
  object_free(&val);
  val = compiled_procedure_entry(proc);
  goto *val.cont;
primitive_branch482:;
  object_free(&val);
  val = proc.proc(argl);
after_call481:;
  object_free(&argl);
  argl = restore();
  argl = cons(object_copy(val), argl);
  object_free(&proc);
  proc = restore();
  object_free(&cont);
  cont = restore();
  if (proc.type == PROC_APPLY) {
    proc = apply_proc();
    argl = apply_argl();
  }
  if (proc.type == PROC) {
    goto primitive_branch484;
  }
  object_free(&val);
  val = compiled_procedure_entry(proc);
  goto *val.cont;
primitive_branch484:;
  object_free(&val);
  val = proc.proc(argl);
  goto *cont.cont;
false_branch470:;
  object_free(&proc);
  proc = lookup_var_val(c_str_to_datum("|preserving|"));
  save(cont);
  save(proc);
  save(env);
  object_free(&proc);
  proc = lookup_var_val(c_str_to_datum("|compile-sequence|"));
  save(proc);
  object_free(&val);
  val = lookup_var_val(c_str_to_datum("|linkage|"));
  argl = cons(object_copy(val), empty);
  object_free(&val);
  val = lookup_var_val(c_str_to_datum("|target|"));
  argl = cons(object_copy(val), argl);
  save(argl);
  object_free(&proc);
  proc = lookup_var_val(c_str_to_datum("|cdr|"));
  object_free(&val);
  val = lookup_var_val(c_str_to_datum("|seq|"));
  argl = cons(object_copy(val), empty);
  if (proc.type == PROC_APPLY) {
    proc = apply_proc();
    argl = apply_argl();
  }
  if (proc.type == PROC) {
    goto primitive_branch472;
  }
  cont.cont = &&after_call471;
  object_free(&val);
  val = compiled_procedure_entry(proc);
  goto *val.cont;
primitive_branch472:;
  object_free(&val);
  val = proc.proc(argl);
after_call471:;
  object_free(&argl);
  argl = restore();
  argl = cons(object_copy(val), argl);
  object_free(&proc);
  proc = restore();
  if (proc.type == PROC_APPLY) {
    proc = apply_proc();
    argl = apply_argl();
  }
  if (proc.type == PROC) {
    goto primitive_branch474;
  }
  cont.cont = &&after_call473;
  object_free(&val);
  val = compiled_procedure_entry(proc);
  goto *val.cont;
primitive_branch474:;
  object_free(&val);
  val = proc.proc(argl);
after_call473:;
  argl = cons(object_copy(val), empty);
  object_free(&env);
  env = restore();
  save(argl);
  object_free(&proc);
  proc = lookup_var_val(c_str_to_datum("|compile|"));
  save(proc);
  object_free(&val);
  val = c_str_to_datum("|next|");
  argl = cons(object_copy(val), empty);
  object_free(&val);
  val = lookup_var_val(c_str_to_datum("|target|"));
  argl = cons(object_copy(val), argl);
  save(argl);
  object_free(&proc);
  proc = lookup_var_val(c_str_to_datum("|car|"));
  object_free(&val);
  val = lookup_var_val(c_str_to_datum("|seq|"));
  argl = cons(object_copy(val), empty);
  if (proc.type == PROC_APPLY) {
    proc = apply_proc();
    argl = apply_argl();
  }
  if (proc.type == PROC) {
    goto primitive_branch476;
  }
  cont.cont = &&after_call475;
  object_free(&val);
  val = compiled_procedure_entry(proc);
  goto *val.cont;
primitive_branch476:;
  object_free(&val);
  val = proc.proc(argl);
after_call475:;
  object_free(&argl);
  argl = restore();
  argl = cons(object_copy(val), argl);
  object_free(&proc);
  proc = restore();
  if (proc.type == PROC_APPLY) {
    proc = apply_proc();
    argl = apply_argl();
  }
  if (proc.type == PROC) {
    goto primitive_branch478;
  }
  cont.cont = &&after_call477;
  object_free(&val);
  val = compiled_procedure_entry(proc);
  goto *val.cont;
primitive_branch478:;
  object_free(&val);
  val = proc.proc(argl);
after_call477:;
  object_free(&argl);
  argl = restore();
  argl = cons(object_copy(val), argl);
  object_free(&val);
  val = c_str_to_datum("(|env| . (|cont| . ()))");
  argl = cons(object_copy(val), argl);
  object_free(&proc);
  proc = restore();
  object_free(&cont);
  cont = restore();
  if (proc.type == PROC_APPLY) {
    proc = apply_proc();
    argl = apply_argl();
  }
  if (proc.type == PROC) {
    goto primitive_branch480;
  }
  object_free(&val);
  val = compiled_procedure_entry(proc);
  goto *val.cont;
primitive_branch480:;
  object_free(&val);
  val = proc.proc(argl);
  goto *cont.cont;
after_lambda467:;
  {
    Object t = def_var_val(c_str_to_datum("|compile-sequence|"));
    object_free(&val);
    val = t;
  }
  object_free(&val);
  val = make_compiled_procedure(&&entry426);
  goto after_lambda425;
entry426:
  env = compiled_procedure_env();
  env = extend_environment(
      c_str_to_datum("(|exp| . (|target| . (|linkage| . ())))"));
  object_free(&proc);
  proc = make_compiled_procedure(&&entry432);
  goto after_lambda431;
entry432:
  env = compiled_procedure_env();
  env = extend_environment(
      c_str_to_datum("(|proc-entry| . (|after-lambda| . ()))"));
  object_free(&proc);
  proc = make_compiled_procedure(&&entry438);
  goto after_lambda437;
entry438:
  env = compiled_procedure_env();
  env = extend_environment(c_str_to_datum("(|lambda-linkage| . ())"));
  object_free(&proc);
  proc = lookup_var_val(c_str_to_datum("|append-instruction-sequences|"));
  save(cont);
  save(proc);
  save(env);
  save(env);
  object_free(&proc);
  proc = lookup_var_val(c_str_to_datum("|eq?|"));
  object_free(&val);
  val = lookup_var_val(c_str_to_datum("|after-lambda|"));
  argl = cons(object_copy(val), empty);
  object_free(&val);
  val = lookup_var_val(c_str_to_datum("|lambda-linkage|"));
  argl = cons(object_copy(val), argl);
  if (proc.type == PROC_APPLY) {
    proc = apply_proc();
    argl = apply_argl();
  }
  if (proc.type == PROC) {
    goto primitive_branch448;
  }
  cont.cont = &&after_call447;
  object_free(&val);
  val = compiled_procedure_entry(proc);
  goto *val.cont;
primitive_branch448:;
  object_free(&val);
  val = proc.proc(argl);
after_call447:;
  object_free(&env);
  env = restore();
  if (val.type == BOOLEAN && !val.boolean) {
    goto false_branch440;
  }
  object_free(&proc);
  proc = lookup_var_val(c_str_to_datum("|c-make-instruction-sequence|"));
  save(proc);
  object_free(&proc);
  proc = lookup_var_val(c_str_to_datum("|list|"));
  object_free(&val);
  val = c_str_to_datum("|:;|");
  argl = cons(object_copy(val), empty);
  object_free(&val);
  val = lookup_var_val(c_str_to_datum("|after-lambda|"));
  argl = cons(object_copy(val), argl);
  if (proc.type == PROC_APPLY) {
    proc = apply_proc();
    argl = apply_argl();
  }
  if (proc.type == PROC) {
    goto primitive_branch444;
  }
  cont.cont = &&after_call443;
  object_free(&val);
  val = compiled_procedure_entry(proc);
  goto *val.cont;
primitive_branch444:;
  object_free(&val);
  val = proc.proc(argl);
after_call443:;
  argl = cons(object_copy(val), empty);
  object_free(&val);
  val = c_str_to_datum("()");
  argl = cons(object_copy(val), argl);
  object_free(&val);
  val = c_str_to_datum("()");
  argl = cons(object_copy(val), argl);
  object_free(&proc);
  proc = restore();
  if (proc.type == PROC_APPLY) {
    proc = apply_proc();
    argl = apply_argl();
  }
  if (proc.type == PROC) {
    goto primitive_branch446;
  }
  cont.cont = &&after_if439;
  object_free(&val);
  val = compiled_procedure_entry(proc);
  goto *val.cont;
primitive_branch446:;
  object_free(&val);
  val = proc.proc(argl);
  goto after_if439;
false_branch440:;
  object_free(&proc);
  proc = lookup_var_val(c_str_to_datum("|c-empty-instruction-sequence|"));
  argl = empty;
  if (proc.type == PROC_APPLY) {
    proc = apply_proc();
    argl = apply_argl();
  }
  if (proc.type == PROC) {
    goto primitive_branch442;
  }
  cont.cont = &&after_call441;
  object_free(&val);
  val = compiled_procedure_entry(proc);
  goto *val.cont;
primitive_branch442:;
  object_free(&val);
  val = proc.proc(argl);
after_call441:;
after_if439:;
  argl = cons(object_copy(val), empty);
  object_free(&env);
  env = restore();
  save(argl);
  object_free(&proc);
  proc = lookup_var_val(c_str_to_datum("|tack-on-instruction-sequence|"));
  save(proc);
  save(env);
  object_free(&proc);
  proc = lookup_var_val(c_str_to_datum("|compile-lambda-body|"));
  object_free(&val);
  val = lookup_var_val(c_str_to_datum("|proc-entry|"));
  argl = cons(object_copy(val), empty);
  object_free(&val);
  val = lookup_var_val(c_str_to_datum("|exp|"));
  argl = cons(object_copy(val), argl);
  if (proc.type == PROC_APPLY) {
    proc = apply_proc();
    argl = apply_argl();
  }
  if (proc.type == PROC) {
    goto primitive_branch450;
  }
  cont.cont = &&after_call449;
  object_free(&val);
  val = compiled_procedure_entry(proc);
  goto *val.cont;
primitive_branch450:;
  object_free(&val);
  val = proc.proc(argl);
after_call449:;
  argl = cons(object_copy(val), empty);
  object_free(&env);
  env = restore();
  save(argl);
  object_free(&proc);
  proc = lookup_var_val(c_str_to_datum("|end-with-linkage|"));
  save(proc);
  save(env);
  object_free(&proc);
  proc = lookup_var_val(c_str_to_datum("|c-make-instruction-sequence|"));
  save(proc);
  save(env);
  object_free(&proc);
  proc = lookup_var_val(c_str_to_datum("|list|"));
  object_free(&val);
  val = c_str_to_datum("|);|");
  argl = cons(object_copy(val), empty);
  object_free(&val);
  val = lookup_var_val(c_str_to_datum("|proc-entry|"));
  argl = cons(object_copy(val), argl);
  object_free(&val);
  val = c_str_to_datum("| = make_compiled_procedure(&&|");
  argl = cons(object_copy(val), argl);
  object_free(&val);
  val = lookup_var_val(c_str_to_datum("|target|"));
  argl = cons(object_copy(val), argl);
  object_free(&val);
  val = c_str_to_datum("|);|");
  argl = cons(object_copy(val), argl);
  object_free(&val);
  val = lookup_var_val(c_str_to_datum("|target|"));
  argl = cons(object_copy(val), argl);
  object_free(&val);
  val = c_str_to_datum("|object_free(&|");
  argl = cons(object_copy(val), argl);
  if (proc.type == PROC_APPLY) {
    proc = apply_proc();
    argl = apply_argl();
  }
  if (proc.type == PROC) {
    goto primitive_branch452;
  }
  cont.cont = &&after_call451;
  object_free(&val);
  val = compiled_procedure_entry(proc);
  goto *val.cont;
primitive_branch452:;
  object_free(&val);
  val = proc.proc(argl);
after_call451:;
  argl = cons(object_copy(val), empty);
  object_free(&env);
  env = restore();
  save(argl);
  object_free(&proc);
  proc = lookup_var_val(c_str_to_datum("|list|"));
  object_free(&val);
  val = lookup_var_val(c_str_to_datum("|target|"));
  argl = cons(object_copy(val), empty);
  if (proc.type == PROC_APPLY) {
    proc = apply_proc();
    argl = apply_argl();
  }
  if (proc.type == PROC) {
    goto primitive_branch454;
  }
  cont.cont = &&after_call453;
  object_free(&val);
  val = compiled_procedure_entry(proc);
  goto *val.cont;
primitive_branch454:;
  object_free(&val);
  val = proc.proc(argl);
after_call453:;
  object_free(&argl);
  argl = restore();
  argl = cons(object_copy(val), argl);
  object_free(&val);
  val = c_str_to_datum("(|env| . ())");
  argl = cons(object_copy(val), argl);
  object_free(&proc);
  proc = restore();
  if (proc.type == PROC_APPLY) {
    proc = apply_proc();
    argl = apply_argl();
  }
  if (proc.type == PROC) {
    goto primitive_branch456;
  }
  cont.cont = &&after_call455;
  object_free(&val);
  val = compiled_procedure_entry(proc);
  goto *val.cont;
primitive_branch456:;
  object_free(&val);
  val = proc.proc(argl);
after_call455:;
  argl = cons(object_copy(val), empty);
  object_free(&env);
  env = restore();
  object_free(&val);
  val = lookup_var_val(c_str_to_datum("|lambda-linkage|"));
  argl = cons(object_copy(val), argl);
  object_free(&proc);
  proc = restore();
  if (proc.type == PROC_APPLY) {
    proc = apply_proc();
    argl = apply_argl();
  }
  if (proc.type == PROC) {
    goto primitive_branch458;
  }
  cont.cont = &&after_call457;
  object_free(&val);
  val = compiled_procedure_entry(proc);
  goto *val.cont;
primitive_branch458:;
  object_free(&val);
  val = proc.proc(argl);
after_call457:;
  object_free(&argl);
  argl = restore();
  argl = cons(object_copy(val), argl);
  object_free(&proc);
  proc = restore();
  if (proc.type == PROC_APPLY) {
    proc = apply_proc();
    argl = apply_argl();
  }
  if (proc.type == PROC) {
    goto primitive_branch460;
  }
  cont.cont = &&after_call459;
  object_free(&val);
  val = compiled_procedure_entry(proc);
  goto *val.cont;
primitive_branch460:;
  object_free(&val);
  val = proc.proc(argl);
after_call459:;
  object_free(&argl);
  argl = restore();
  argl = cons(object_copy(val), argl);
  object_free(&proc);
  proc = restore();
  object_free(&cont);
  cont = restore();
  if (proc.type == PROC_APPLY) {
    proc = apply_proc();
    argl = apply_argl();
  }
  if (proc.type == PROC) {
    goto primitive_branch462;
  }
  object_free(&val);
  val = compiled_procedure_entry(proc);
  goto *val.cont;
primitive_branch462:;
  object_free(&val);
  val = proc.proc(argl);
  goto *cont.cont;
after_lambda437:;
  save(cont);
  save(proc);
  save(env);
  object_free(&proc);
  proc = lookup_var_val(c_str_to_datum("|eq?|"));
  object_free(&val);
  val = c_str_to_datum("|next|");
  argl = cons(object_copy(val), empty);
  object_free(&val);
  val = lookup_var_val(c_str_to_datum("|linkage|"));
  argl = cons(object_copy(val), argl);
  if (proc.type == PROC_APPLY) {
    proc = apply_proc();
    argl = apply_argl();
  }
  if (proc.type == PROC) {
    goto primitive_branch436;
  }
  cont.cont = &&after_call435;
  object_free(&val);
  val = compiled_procedure_entry(proc);
  goto *val.cont;
primitive_branch436:;
  object_free(&val);
  val = proc.proc(argl);
after_call435:;
  object_free(&env);
  env = restore();
  if (val.type == BOOLEAN && !val.boolean) {
    goto false_branch434;
  }
  object_free(&val);
  val = lookup_var_val(c_str_to_datum("|after-lambda|"));
  goto after_if433;
false_branch434:;
  object_free(&val);
  val = lookup_var_val(c_str_to_datum("|linkage|"));
after_if433:;
  argl = cons(object_copy(val), empty);
  object_free(&proc);
  proc = restore();
  object_free(&cont);
  cont = restore();
  if (proc.type == PROC_APPLY) {
    proc = apply_proc();
    argl = apply_argl();
  }
  if (proc.type == PROC) {
    goto primitive_branch464;
  }
  object_free(&val);
  val = compiled_procedure_entry(proc);
  goto *val.cont;
primitive_branch464:;
  object_free(&val);
  val = proc.proc(argl);
  goto *cont.cont;
after_lambda431:;
  save(cont);
  save(proc);
  save(env);
  object_free(&proc);
  proc = lookup_var_val(c_str_to_datum("|make-label|"));
  object_free(&val);
  val = c_str_to_datum("|after_lambda|");
  argl = cons(object_copy(val), empty);
  if (proc.type == PROC_APPLY) {
    proc = apply_proc();
    argl = apply_argl();
  }
  if (proc.type == PROC) {
    goto primitive_branch428;
  }
  cont.cont = &&after_call427;
  object_free(&val);
  val = compiled_procedure_entry(proc);
  goto *val.cont;
primitive_branch428:;
  object_free(&val);
  val = proc.proc(argl);
after_call427:;
  argl = cons(object_copy(val), empty);
  object_free(&env);
  env = restore();
  save(argl);
  object_free(&proc);
  proc = lookup_var_val(c_str_to_datum("|make-label|"));
  object_free(&val);
  val = c_str_to_datum("|entry|");
  argl = cons(object_copy(val), empty);
  if (proc.type == PROC_APPLY) {
    proc = apply_proc();
    argl = apply_argl();
  }
  if (proc.type == PROC) {
    goto primitive_branch430;
  }
  cont.cont = &&after_call429;
  object_free(&val);
  val = compiled_procedure_entry(proc);
  goto *val.cont;
primitive_branch430:;
  object_free(&val);
  val = proc.proc(argl);
after_call429:;
  object_free(&argl);
  argl = restore();
  argl = cons(object_copy(val), argl);
  object_free(&proc);
  proc = restore();
  object_free(&cont);
  cont = restore();
  if (proc.type == PROC_APPLY) {
    proc = apply_proc();
    argl = apply_argl();
  }
  if (proc.type == PROC) {
    goto primitive_branch466;
  }
  object_free(&val);
  val = compiled_procedure_entry(proc);
  goto *val.cont;
primitive_branch466:;
  object_free(&val);
  val = proc.proc(argl);
  goto *cont.cont;
after_lambda425:;
  {
    Object t = def_var_val(c_str_to_datum("|compile-lambda|"));
    object_free(&val);
    val = t;
  }
  object_free(&val);
  val = make_compiled_procedure(&&entry404);
  goto after_lambda403;
entry404:
  env = compiled_procedure_env();
  env = extend_environment(c_str_to_datum("(|exp| . (|proc-entry| . ()))"));
  object_free(&proc);
  proc = make_compiled_procedure(&&entry408);
  goto after_lambda407;
entry408:
  env = compiled_procedure_env();
  env = extend_environment(c_str_to_datum("(|formals| . ())"));
  object_free(&proc);
  proc = lookup_var_val(c_str_to_datum("|append-instruction-sequences|"));
  save(cont);
  save(proc);
  save(env);
  object_free(&proc);
  proc = lookup_var_val(c_str_to_datum("|compile-sequence|"));
  save(proc);
  object_free(&val);
  val = c_str_to_datum("|return|");
  argl = cons(object_copy(val), empty);
  object_free(&val);
  val = c_str_to_datum("|val|");
  argl = cons(object_copy(val), argl);
  save(argl);
  object_free(&proc);
  proc = lookup_var_val(c_str_to_datum("|c-cddr|"));
  object_free(&val);
  val = lookup_var_val(c_str_to_datum("|exp|"));
  argl = cons(object_copy(val), empty);
  if (proc.type == PROC_APPLY) {
    proc = apply_proc();
    argl = apply_argl();
  }
  if (proc.type == PROC) {
    goto primitive_branch410;
  }
  cont.cont = &&after_call409;
  object_free(&val);
  val = compiled_procedure_entry(proc);
  goto *val.cont;
primitive_branch410:;
  object_free(&val);
  val = proc.proc(argl);
after_call409:;
  object_free(&argl);
  argl = restore();
  argl = cons(object_copy(val), argl);
  object_free(&proc);
  proc = restore();
  if (proc.type == PROC_APPLY) {
    proc = apply_proc();
    argl = apply_argl();
  }
  if (proc.type == PROC) {
    goto primitive_branch412;
  }
  cont.cont = &&after_call411;
  object_free(&val);
  val = compiled_procedure_entry(proc);
  goto *val.cont;
primitive_branch412:;
  object_free(&val);
  val = proc.proc(argl);
after_call411:;
  argl = cons(object_copy(val), empty);
  object_free(&env);
  env = restore();
  save(argl);
  object_free(&proc);
  proc = lookup_var_val(c_str_to_datum("|c-make-instruction-sequence|"));
  save(proc);
  object_free(&proc);
  proc = lookup_var_val(c_str_to_datum("|c-append|"));
  save(proc);
  object_free(&val);
  val = c_str_to_datum("(|);| . ())");
  argl = cons(object_copy(val), empty);
  save(env);
  save(argl);
  object_free(&proc);
  proc = lookup_var_val(c_str_to_datum("|const|"));
  object_free(&val);
  val = lookup_var_val(c_str_to_datum("|formals|"));
  argl = cons(object_copy(val), empty);
  if (proc.type == PROC_APPLY) {
    proc = apply_proc();
    argl = apply_argl();
  }
  if (proc.type == PROC) {
    goto primitive_branch414;
  }
  cont.cont = &&after_call413;
  object_free(&val);
  val = compiled_procedure_entry(proc);
  goto *val.cont;
primitive_branch414:;
  object_free(&val);
  val = proc.proc(argl);
after_call413:;
  object_free(&argl);
  argl = restore();
  argl = cons(object_copy(val), argl);
  object_free(&env);
  env = restore();
  save(argl);
  object_free(&proc);
  proc = lookup_var_val(c_str_to_datum("|list|"));
  object_free(&val);
  val = c_str_to_datum("|:env = compiled_procedure_env();\\n                   "
                       "       env = extend_environment(|");
  argl = cons(object_copy(val), empty);
  object_free(&val);
  val = lookup_var_val(c_str_to_datum("|proc-entry|"));
  argl = cons(object_copy(val), argl);
  if (proc.type == PROC_APPLY) {
    proc = apply_proc();
    argl = apply_argl();
  }
  if (proc.type == PROC) {
    goto primitive_branch416;
  }
  cont.cont = &&after_call415;
  object_free(&val);
  val = compiled_procedure_entry(proc);
  goto *val.cont;
primitive_branch416:;
  object_free(&val);
  val = proc.proc(argl);
after_call415:;
  object_free(&argl);
  argl = restore();
  argl = cons(object_copy(val), argl);
  object_free(&proc);
  proc = restore();
  if (proc.type == PROC_APPLY) {
    proc = apply_proc();
    argl = apply_argl();
  }
  if (proc.type == PROC) {
    goto primitive_branch418;
  }
  cont.cont = &&after_call417;
  object_free(&val);
  val = compiled_procedure_entry(proc);
  goto *val.cont;
primitive_branch418:;
  object_free(&val);
  val = proc.proc(argl);
after_call417:;
  argl = cons(object_copy(val), empty);
  object_free(&val);
  val = c_str_to_datum("(|env| . ())");
  argl = cons(object_copy(val), argl);
  object_free(&val);
  val = c_str_to_datum("(|env| . (|proc| . (|argl| . ())))");
  argl = cons(object_copy(val), argl);
  object_free(&proc);
  proc = restore();
  if (proc.type == PROC_APPLY) {
    proc = apply_proc();
    argl = apply_argl();
  }
  if (proc.type == PROC) {
    goto primitive_branch420;
  }
  cont.cont = &&after_call419;
  object_free(&val);
  val = compiled_procedure_entry(proc);
  goto *val.cont;
primitive_branch420:;
  object_free(&val);
  val = proc.proc(argl);
after_call419:;
  object_free(&argl);
  argl = restore();
  argl = cons(object_copy(val), argl);
  object_free(&proc);
  proc = restore();
  object_free(&cont);
  cont = restore();
  if (proc.type == PROC_APPLY) {
    proc = apply_proc();
    argl = apply_argl();
  }
  if (proc.type == PROC) {
    goto primitive_branch422;
  }
  object_free(&val);
  val = compiled_procedure_entry(proc);
  goto *val.cont;
primitive_branch422:;
  object_free(&val);
  val = proc.proc(argl);
  goto *cont.cont;
after_lambda407:;
  save(cont);
  save(proc);
  object_free(&proc);
  proc = lookup_var_val(c_str_to_datum("|c-cadr|"));
  object_free(&val);
  val = lookup_var_val(c_str_to_datum("|exp|"));
  argl = cons(object_copy(val), empty);
  if (proc.type == PROC_APPLY) {
    proc = apply_proc();
    argl = apply_argl();
  }
  if (proc.type == PROC) {
    goto primitive_branch406;
  }
  cont.cont = &&after_call405;
  object_free(&val);
  val = compiled_procedure_entry(proc);
  goto *val.cont;
primitive_branch406:;
  object_free(&val);
  val = proc.proc(argl);
after_call405:;
  argl = cons(object_copy(val), empty);
  object_free(&proc);
  proc = restore();
  object_free(&cont);
  cont = restore();
  if (proc.type == PROC_APPLY) {
    proc = apply_proc();
    argl = apply_argl();
  }
  if (proc.type == PROC) {
    goto primitive_branch424;
  }
  object_free(&val);
  val = compiled_procedure_entry(proc);
  goto *val.cont;
primitive_branch424:;
  object_free(&val);
  val = proc.proc(argl);
  goto *cont.cont;
after_lambda403:;
  {
    Object t = def_var_val(c_str_to_datum("|compile-lambda-body|"));
    object_free(&val);
    val = t;
  }
  object_free(&val);
  val = make_compiled_procedure(&&entry362);
  goto after_lambda361;
entry362:
  env = compiled_procedure_env();
  env = extend_environment(
      c_str_to_datum("(|exp| . (|target| . (|linkage| . ())))"));
  object_free(&val);
  val = make_compiled_procedure(&&entry388);
  goto after_lambda387;
entry388:
  env = compiled_procedure_env();
  env = extend_environment(c_str_to_datum("(|proc| . (|lst| . ()))"));
  save(cont);
  save(env);
  object_free(&proc);
  proc = lookup_var_val(c_str_to_datum("|null?|"));
  object_free(&val);
  val = lookup_var_val(c_str_to_datum("|lst|"));
  argl = cons(object_copy(val), empty);
  if (proc.type == PROC_APPLY) {
    proc = apply_proc();
    argl = apply_argl();
  }
  if (proc.type == PROC) {
    goto primitive_branch402;
  }
  cont.cont = &&after_call401;
  object_free(&val);
  val = compiled_procedure_entry(proc);
  goto *val.cont;
primitive_branch402:;
  object_free(&val);
  val = proc.proc(argl);
after_call401:;
  object_free(&env);
  env = restore();
  object_free(&cont);
  cont = restore();
  if (val.type == BOOLEAN && !val.boolean) {
    goto false_branch390;
  }
  object_free(&val);
  val = c_str_to_datum("()");
  goto *cont.cont;
false_branch390:;
  object_free(&proc);
  proc = lookup_var_val(c_str_to_datum("|cons|"));
  save(cont);
  save(proc);
  save(env);
  object_free(&proc);
  proc = lookup_var_val(c_str_to_datum("|iter|"));
  save(proc);
  save(env);
  object_free(&proc);
  proc = lookup_var_val(c_str_to_datum("|cdr|"));
  object_free(&val);
  val = lookup_var_val(c_str_to_datum("|lst|"));
  argl = cons(object_copy(val), empty);
  if (proc.type == PROC_APPLY) {
    proc = apply_proc();
    argl = apply_argl();
  }
  if (proc.type == PROC) {
    goto primitive_branch392;
  }
  cont.cont = &&after_call391;
  object_free(&val);
  val = compiled_procedure_entry(proc);
  goto *val.cont;
primitive_branch392:;
  object_free(&val);
  val = proc.proc(argl);
after_call391:;
  argl = cons(object_copy(val), empty);
  object_free(&env);
  env = restore();
  object_free(&val);
  val = lookup_var_val(c_str_to_datum("|proc|"));
  argl = cons(object_copy(val), argl);
  object_free(&proc);
  proc = restore();
  if (proc.type == PROC_APPLY) {
    proc = apply_proc();
    argl = apply_argl();
  }
  if (proc.type == PROC) {
    goto primitive_branch394;
  }
  cont.cont = &&after_call393;
  object_free(&val);
  val = compiled_procedure_entry(proc);
  goto *val.cont;
primitive_branch394:;
  object_free(&val);
  val = proc.proc(argl);
after_call393:;
  argl = cons(object_copy(val), empty);
  object_free(&env);
  env = restore();
  save(argl);
  object_free(&proc);
  proc = lookup_var_val(c_str_to_datum("|proc|"));
  save(proc);
  object_free(&proc);
  proc = lookup_var_val(c_str_to_datum("|car|"));
  object_free(&val);
  val = lookup_var_val(c_str_to_datum("|lst|"));
  argl = cons(object_copy(val), empty);
  if (proc.type == PROC_APPLY) {
    proc = apply_proc();
    argl = apply_argl();
  }
  if (proc.type == PROC) {
    goto primitive_branch396;
  }
  cont.cont = &&after_call395;
  object_free(&val);
  val = compiled_procedure_entry(proc);
  goto *val.cont;
primitive_branch396:;
  object_free(&val);
  val = proc.proc(argl);
after_call395:;
  argl = cons(object_copy(val), empty);
  object_free(&proc);
  proc = restore();
  if (proc.type == PROC_APPLY) {
    proc = apply_proc();
    argl = apply_argl();
  }
  if (proc.type == PROC) {
    goto primitive_branch398;
  }
  cont.cont = &&after_call397;
  object_free(&val);
  val = compiled_procedure_entry(proc);
  goto *val.cont;
primitive_branch398:;
  object_free(&val);
  val = proc.proc(argl);
after_call397:;
  object_free(&argl);
  argl = restore();
  argl = cons(object_copy(val), argl);
  object_free(&proc);
  proc = restore();
  object_free(&cont);
  cont = restore();
  if (proc.type == PROC_APPLY) {
    proc = apply_proc();
    argl = apply_argl();
  }
  if (proc.type == PROC) {
    goto primitive_branch400;
  }
  object_free(&val);
  val = compiled_procedure_entry(proc);
  goto *val.cont;
primitive_branch400:;
  object_free(&val);
  val = proc.proc(argl);
  goto *cont.cont;
after_lambda387:;
  {
    Object t = def_var_val(c_str_to_datum("|iter|"));
    object_free(&val);
    val = t;
  }
  object_free(&proc);
  proc = make_compiled_procedure(&&entry376);
  goto after_lambda375;
entry376:
  env = compiled_procedure_env();
  env = extend_environment(
      c_str_to_datum("(|proc-code| . (|operand-codes| . ()))"));
  object_free(&proc);
  proc = lookup_var_val(c_str_to_datum("|preserving|"));
  save(cont);
  save(proc);
  save(env);
  object_free(&proc);
  proc = lookup_var_val(c_str_to_datum("|preserving|"));
  save(proc);
  save(env);
  object_free(&proc);
  proc = lookup_var_val(c_str_to_datum("|compile-procedure-call|"));
  object_free(&val);
  val = lookup_var_val(c_str_to_datum("|linkage|"));
  argl = cons(object_copy(val), empty);
  object_free(&val);
  val = lookup_var_val(c_str_to_datum("|target|"));
  argl = cons(object_copy(val), argl);
  if (proc.type == PROC_APPLY) {
    proc = apply_proc();
    argl = apply_argl();
  }
  if (proc.type == PROC) {
    goto primitive_branch378;
  }
  cont.cont = &&after_call377;
  object_free(&val);
  val = compiled_procedure_entry(proc);
  goto *val.cont;
primitive_branch378:;
  object_free(&val);
  val = proc.proc(argl);
after_call377:;
  argl = cons(object_copy(val), empty);
  object_free(&env);
  env = restore();
  save(argl);
  object_free(&proc);
  proc = lookup_var_val(c_str_to_datum("|construct-arglist|"));
  object_free(&val);
  val = lookup_var_val(c_str_to_datum("|operand-codes|"));
  argl = cons(object_copy(val), empty);
  if (proc.type == PROC_APPLY) {
    proc = apply_proc();
    argl = apply_argl();
  }
  if (proc.type == PROC) {
    goto primitive_branch380;
  }
  cont.cont = &&after_call379;
  object_free(&val);
  val = compiled_procedure_entry(proc);
  goto *val.cont;
primitive_branch380:;
  object_free(&val);
  val = proc.proc(argl);
after_call379:;
  object_free(&argl);
  argl = restore();
  argl = cons(object_copy(val), argl);
  object_free(&val);
  val = c_str_to_datum("(|proc| . (|cont| . ()))");
  argl = cons(object_copy(val), argl);
  object_free(&proc);
  proc = restore();
  if (proc.type == PROC_APPLY) {
    proc = apply_proc();
    argl = apply_argl();
  }
  if (proc.type == PROC) {
    goto primitive_branch382;
  }
  cont.cont = &&after_call381;
  object_free(&val);
  val = compiled_procedure_entry(proc);
  goto *val.cont;
primitive_branch382:;
  object_free(&val);
  val = proc.proc(argl);
after_call381:;
  argl = cons(object_copy(val), empty);
  object_free(&env);
  env = restore();
  object_free(&val);
  val = lookup_var_val(c_str_to_datum("|proc-code|"));
  argl = cons(object_copy(val), argl);
  object_free(&val);
  val = c_str_to_datum("(|env| . (|cont| . ()))");
  argl = cons(object_copy(val), argl);
  object_free(&proc);
  proc = restore();
  object_free(&cont);
  cont = restore();
  if (proc.type == PROC_APPLY) {
    proc = apply_proc();
    argl = apply_argl();
  }
  if (proc.type == PROC) {
    goto primitive_branch384;
  }
  object_free(&val);
  val = compiled_procedure_entry(proc);
  goto *val.cont;
primitive_branch384:;
  object_free(&val);
  val = proc.proc(argl);
  goto *cont.cont;
after_lambda375:;
  save(cont);
  save(proc);
  save(env);
  object_free(&proc);
  proc = lookup_var_val(c_str_to_datum("|iter|"));
  save(proc);
  save(env);
  object_free(&proc);
  proc = lookup_var_val(c_str_to_datum("|cdr|"));
  object_free(&val);
  val = lookup_var_val(c_str_to_datum("|exp|"));
  argl = cons(object_copy(val), empty);
  if (proc.type == PROC_APPLY) {
    proc = apply_proc();
    argl = apply_argl();
  }
  if (proc.type == PROC) {
    goto primitive_branch364;
  }
  cont.cont = &&after_call363;
  object_free(&val);
  val = compiled_procedure_entry(proc);
  goto *val.cont;
primitive_branch364:;
  object_free(&val);
  val = proc.proc(argl);
after_call363:;
  argl = cons(object_copy(val), empty);
  object_free(&env);
  env = restore();
  object_free(&val);
  val = make_compiled_procedure(&&entry366);
  goto after_lambda365;
entry366:
  env = compiled_procedure_env();
  env = extend_environment(c_str_to_datum("(|operand| . ())"));
  object_free(&proc);
  proc = lookup_var_val(c_str_to_datum("|compile|"));
  object_free(&val);
  val = c_str_to_datum("|next|");
  argl = cons(object_copy(val), empty);
  object_free(&val);
  val = c_str_to_datum("|val|");
  argl = cons(object_copy(val), argl);
  object_free(&val);
  val = lookup_var_val(c_str_to_datum("|operand|"));
  argl = cons(object_copy(val), argl);
  if (proc.type == PROC_APPLY) {
    proc = apply_proc();
    argl = apply_argl();
  }
  if (proc.type == PROC) {
    goto primitive_branch368;
  }
  object_free(&val);
  val = compiled_procedure_entry(proc);
  goto *val.cont;
primitive_branch368:;
  object_free(&val);
  val = proc.proc(argl);
  goto *cont.cont;
after_lambda365:;
  argl = cons(object_copy(val), argl);
  object_free(&proc);
  proc = restore();
  if (proc.type == PROC_APPLY) {
    proc = apply_proc();
    argl = apply_argl();
  }
  if (proc.type == PROC) {
    goto primitive_branch370;
  }
  cont.cont = &&after_call369;
  object_free(&val);
  val = compiled_procedure_entry(proc);
  goto *val.cont;
primitive_branch370:;
  object_free(&val);
  val = proc.proc(argl);
after_call369:;
  argl = cons(object_copy(val), empty);
  object_free(&env);
  env = restore();
  save(argl);
  object_free(&proc);
  proc = lookup_var_val(c_str_to_datum("|compile|"));
  save(proc);
  object_free(&val);
  val = c_str_to_datum("|next|");
  argl = cons(object_copy(val), empty);
  object_free(&val);
  val = c_str_to_datum("|proc|");
  argl = cons(object_copy(val), argl);
  save(argl);
  object_free(&proc);
  proc = lookup_var_val(c_str_to_datum("|car|"));
  object_free(&val);
  val = lookup_var_val(c_str_to_datum("|exp|"));
  argl = cons(object_copy(val), empty);
  if (proc.type == PROC_APPLY) {
    proc = apply_proc();
    argl = apply_argl();
  }
  if (proc.type == PROC) {
    goto primitive_branch372;
  }
  cont.cont = &&after_call371;
  object_free(&val);
  val = compiled_procedure_entry(proc);
  goto *val.cont;
primitive_branch372:;
  object_free(&val);
  val = proc.proc(argl);
after_call371:;
  object_free(&argl);
  argl = restore();
  argl = cons(object_copy(val), argl);
  object_free(&proc);
  proc = restore();
  if (proc.type == PROC_APPLY) {
    proc = apply_proc();
    argl = apply_argl();
  }
  if (proc.type == PROC) {
    goto primitive_branch374;
  }
  cont.cont = &&after_call373;
  object_free(&val);
  val = compiled_procedure_entry(proc);
  goto *val.cont;
primitive_branch374:;
  object_free(&val);
  val = proc.proc(argl);
after_call373:;
  object_free(&argl);
  argl = restore();
  argl = cons(object_copy(val), argl);
  object_free(&proc);
  proc = restore();
  object_free(&cont);
  cont = restore();
  if (proc.type == PROC_APPLY) {
    proc = apply_proc();
    argl = apply_argl();
  }
  if (proc.type == PROC) {
    goto primitive_branch386;
  }
  object_free(&val);
  val = compiled_procedure_entry(proc);
  goto *val.cont;
primitive_branch386:;
  object_free(&val);
  val = proc.proc(argl);
  goto *cont.cont;
after_lambda361:;
  {
    Object t = def_var_val(c_str_to_datum("|compile-application|"));
    object_free(&val);
    val = t;
  }
  object_free(&val);
  val = make_compiled_procedure(&&entry326);
  goto after_lambda325;
entry326:
  env = compiled_procedure_env();
  env = extend_environment(c_str_to_datum("(|operand-codes| . ())"));
  object_free(&proc);
  proc = make_compiled_procedure(&&entry330);
  goto after_lambda329;
entry330:
  env = compiled_procedure_env();
  env = extend_environment(c_str_to_datum("(|operand-codes| . ())"));
  save(cont);
  save(env);
  object_free(&proc);
  proc = lookup_var_val(c_str_to_datum("|null?|"));
  object_free(&val);
  val = lookup_var_val(c_str_to_datum("|operand-codes|"));
  argl = cons(object_copy(val), empty);
  if (proc.type == PROC_APPLY) {
    proc = apply_proc();
    argl = apply_argl();
  }
  if (proc.type == PROC) {
    goto primitive_branch358;
  }
  cont.cont = &&after_call357;
  object_free(&val);
  val = compiled_procedure_entry(proc);
  goto *val.cont;
primitive_branch358:;
  object_free(&val);
  val = proc.proc(argl);
after_call357:;
  object_free(&env);
  env = restore();
  object_free(&cont);
  cont = restore();
  if (val.type == BOOLEAN && !val.boolean) {
    goto false_branch332;
  }
  object_free(&proc);
  proc = lookup_var_val(c_str_to_datum("|c-make-instruction-sequence|"));
  object_free(&val);
  val = c_str_to_datum("(|argl = empty;| . ())");
  argl = cons(object_copy(val), empty);
  object_free(&val);
  val = c_str_to_datum("(|argl| . ())");
  argl = cons(object_copy(val), argl);
  object_free(&val);
  val = c_str_to_datum("()");
  argl = cons(object_copy(val), argl);
  if (proc.type == PROC_APPLY) {
    proc = apply_proc();
    argl = apply_argl();
  }
  if (proc.type == PROC) {
    goto primitive_branch356;
  }
  object_free(&val);
  val = compiled_procedure_entry(proc);
  goto *val.cont;
primitive_branch356:;
  object_free(&val);
  val = proc.proc(argl);
  goto *cont.cont;
false_branch332:;
  object_free(&proc);
  proc = make_compiled_procedure(&&entry340);
  goto after_lambda339;
entry340:
  env = compiled_procedure_env();
  env = extend_environment(c_str_to_datum("(|code-to-get-last-arg| . ())"));
  save(cont);
  save(env);
  object_free(&proc);
  proc = lookup_var_val(c_str_to_datum("|null?|"));
  save(proc);
  object_free(&proc);
  proc = lookup_var_val(c_str_to_datum("|cdr|"));
  object_free(&val);
  val = lookup_var_val(c_str_to_datum("|operand-codes|"));
  argl = cons(object_copy(val), empty);
  if (proc.type == PROC_APPLY) {
    proc = apply_proc();
    argl = apply_argl();
  }
  if (proc.type == PROC) {
    goto primitive_branch350;
  }
  cont.cont = &&after_call349;
  object_free(&val);
  val = compiled_procedure_entry(proc);
  goto *val.cont;
primitive_branch350:;
  object_free(&val);
  val = proc.proc(argl);
after_call349:;
  argl = cons(object_copy(val), empty);
  object_free(&proc);
  proc = restore();
  if (proc.type == PROC_APPLY) {
    proc = apply_proc();
    argl = apply_argl();
  }
  if (proc.type == PROC) {
    goto primitive_branch352;
  }
  cont.cont = &&after_call351;
  object_free(&val);
  val = compiled_procedure_entry(proc);
  goto *val.cont;
primitive_branch352:;
  object_free(&val);
  val = proc.proc(argl);
after_call351:;
  object_free(&env);
  env = restore();
  object_free(&cont);
  cont = restore();
  if (val.type == BOOLEAN && !val.boolean) {
    goto false_branch342;
  }
  object_free(&val);
  val = lookup_var_val(c_str_to_datum("|code-to-get-last-arg|"));
  goto *cont.cont;
false_branch342:;
  object_free(&proc);
  proc = lookup_var_val(c_str_to_datum("|preserving|"));
  save(cont);
  save(proc);
  save(env);
  object_free(&proc);
  proc = lookup_var_val(c_str_to_datum("|code-to-get-rest-args|"));
  save(proc);
  object_free(&proc);
  proc = lookup_var_val(c_str_to_datum("|cdr|"));
  object_free(&val);
  val = lookup_var_val(c_str_to_datum("|operand-codes|"));
  argl = cons(object_copy(val), empty);
  if (proc.type == PROC_APPLY) {
    proc = apply_proc();
    argl = apply_argl();
  }
  if (proc.type == PROC) {
    goto primitive_branch344;
  }
  cont.cont = &&after_call343;
  object_free(&val);
  val = compiled_procedure_entry(proc);
  goto *val.cont;
primitive_branch344:;
  object_free(&val);
  val = proc.proc(argl);
after_call343:;
  argl = cons(object_copy(val), empty);
  object_free(&proc);
  proc = restore();
  if (proc.type == PROC_APPLY) {
    proc = apply_proc();
    argl = apply_argl();
  }
  if (proc.type == PROC) {
    goto primitive_branch346;
  }
  cont.cont = &&after_call345;
  object_free(&val);
  val = compiled_procedure_entry(proc);
  goto *val.cont;
primitive_branch346:;
  object_free(&val);
  val = proc.proc(argl);
after_call345:;
  argl = cons(object_copy(val), empty);
  object_free(&env);
  env = restore();
  object_free(&val);
  val = lookup_var_val(c_str_to_datum("|code-to-get-last-arg|"));
  argl = cons(object_copy(val), argl);
  object_free(&val);
  val = c_str_to_datum("(|env| . ())");
  argl = cons(object_copy(val), argl);
  object_free(&proc);
  proc = restore();
  object_free(&cont);
  cont = restore();
  if (proc.type == PROC_APPLY) {
    proc = apply_proc();
    argl = apply_argl();
  }
  if (proc.type == PROC) {
    goto primitive_branch348;
  }
  object_free(&val);
  val = compiled_procedure_entry(proc);
  goto *val.cont;
primitive_branch348:;
  object_free(&val);
  val = proc.proc(argl);
  goto *cont.cont;
after_lambda339:;
  save(cont);
  save(proc);
  object_free(&proc);
  proc = lookup_var_val(c_str_to_datum("|append-instruction-sequences|"));
  save(proc);
  save(env);
  object_free(&proc);
  proc = lookup_var_val(c_str_to_datum("|c-make-instruction-sequence|"));
  object_free(&val);
  val = c_str_to_datum("(|argl = cons(object_copy(val),empty);| . ())");
  argl = cons(object_copy(val), empty);
  object_free(&val);
  val = c_str_to_datum("(|argl| . ())");
  argl = cons(object_copy(val), argl);
  object_free(&val);
  val = c_str_to_datum("(|val| . ())");
  argl = cons(object_copy(val), argl);
  if (proc.type == PROC_APPLY) {
    proc = apply_proc();
    argl = apply_argl();
  }
  if (proc.type == PROC) {
    goto primitive_branch334;
  }
  cont.cont = &&after_call333;
  object_free(&val);
  val = compiled_procedure_entry(proc);
  goto *val.cont;
primitive_branch334:;
  object_free(&val);
  val = proc.proc(argl);
after_call333:;
  argl = cons(object_copy(val), empty);
  object_free(&env);
  env = restore();
  save(argl);
  object_free(&proc);
  proc = lookup_var_val(c_str_to_datum("|car|"));
  object_free(&val);
  val = lookup_var_val(c_str_to_datum("|operand-codes|"));
  argl = cons(object_copy(val), empty);
  if (proc.type == PROC_APPLY) {
    proc = apply_proc();
    argl = apply_argl();
  }
  if (proc.type == PROC) {
    goto primitive_branch336;
  }
  cont.cont = &&after_call335;
  object_free(&val);
  val = compiled_procedure_entry(proc);
  goto *val.cont;
primitive_branch336:;
  object_free(&val);
  val = proc.proc(argl);
after_call335:;
  object_free(&argl);
  argl = restore();
  argl = cons(object_copy(val), argl);
  object_free(&proc);
  proc = restore();
  if (proc.type == PROC_APPLY) {
    proc = apply_proc();
    argl = apply_argl();
  }
  if (proc.type == PROC) {
    goto primitive_branch338;
  }
  cont.cont = &&after_call337;
  object_free(&val);
  val = compiled_procedure_entry(proc);
  goto *val.cont;
primitive_branch338:;
  object_free(&val);
  val = proc.proc(argl);
after_call337:;
  argl = cons(object_copy(val), empty);
  object_free(&proc);
  proc = restore();
  object_free(&cont);
  cont = restore();
  if (proc.type == PROC_APPLY) {
    proc = apply_proc();
    argl = apply_argl();
  }
  if (proc.type == PROC) {
    goto primitive_branch354;
  }
  object_free(&val);
  val = compiled_procedure_entry(proc);
  goto *val.cont;
primitive_branch354:;
  object_free(&val);
  val = proc.proc(argl);
  goto *cont.cont;
after_lambda329:;
  save(cont);
  save(proc);
  object_free(&proc);
  proc = lookup_var_val(c_str_to_datum("|c-reverse|"));
  object_free(&val);
  val = lookup_var_val(c_str_to_datum("|operand-codes|"));
  argl = cons(object_copy(val), empty);
  if (proc.type == PROC_APPLY) {
    proc = apply_proc();
    argl = apply_argl();
  }
  if (proc.type == PROC) {
    goto primitive_branch328;
  }
  cont.cont = &&after_call327;
  object_free(&val);
  val = compiled_procedure_entry(proc);
  goto *val.cont;
primitive_branch328:;
  object_free(&val);
  val = proc.proc(argl);
after_call327:;
  argl = cons(object_copy(val), empty);
  object_free(&proc);
  proc = restore();
  object_free(&cont);
  cont = restore();
  if (proc.type == PROC_APPLY) {
    proc = apply_proc();
    argl = apply_argl();
  }
  if (proc.type == PROC) {
    goto primitive_branch360;
  }
  object_free(&val);
  val = compiled_procedure_entry(proc);
  goto *val.cont;
primitive_branch360:;
  object_free(&val);
  val = proc.proc(argl);
  goto *cont.cont;
after_lambda325:;
  {
    Object t = def_var_val(c_str_to_datum("|construct-arglist|"));
    object_free(&val);
    val = t;
  }
  object_free(&val);
  val = make_compiled_procedure(&&entry302);
  goto after_lambda301;
entry302:
  env = compiled_procedure_env();
  env = extend_environment(c_str_to_datum("(|operand-codes| . ())"));
  object_free(&proc);
  proc = make_compiled_procedure(&&entry310);
  goto after_lambda309;
entry310:
  env = compiled_procedure_env();
  env = extend_environment(c_str_to_datum("(|code-for-next-arg| . ())"));
  save(cont);
  save(env);
  object_free(&proc);
  proc = lookup_var_val(c_str_to_datum("|null?|"));
  save(proc);
  object_free(&proc);
  proc = lookup_var_val(c_str_to_datum("|cdr|"));
  object_free(&val);
  val = lookup_var_val(c_str_to_datum("|operand-codes|"));
  argl = cons(object_copy(val), empty);
  if (proc.type == PROC_APPLY) {
    proc = apply_proc();
    argl = apply_argl();
  }
  if (proc.type == PROC) {
    goto primitive_branch320;
  }
  cont.cont = &&after_call319;
  object_free(&val);
  val = compiled_procedure_entry(proc);
  goto *val.cont;
primitive_branch320:;
  object_free(&val);
  val = proc.proc(argl);
after_call319:;
  argl = cons(object_copy(val), empty);
  object_free(&proc);
  proc = restore();
  if (proc.type == PROC_APPLY) {
    proc = apply_proc();
    argl = apply_argl();
  }
  if (proc.type == PROC) {
    goto primitive_branch322;
  }
  cont.cont = &&after_call321;
  object_free(&val);
  val = compiled_procedure_entry(proc);
  goto *val.cont;
primitive_branch322:;
  object_free(&val);
  val = proc.proc(argl);
after_call321:;
  object_free(&env);
  env = restore();
  object_free(&cont);
  cont = restore();
  if (val.type == BOOLEAN && !val.boolean) {
    goto false_branch312;
  }
  object_free(&val);
  val = lookup_var_val(c_str_to_datum("|code-for-next-arg|"));
  goto *cont.cont;
false_branch312:;
  object_free(&proc);
  proc = lookup_var_val(c_str_to_datum("|preserving|"));
  save(cont);
  save(proc);
  save(env);
  object_free(&proc);
  proc = lookup_var_val(c_str_to_datum("|code-to-get-rest-args|"));
  save(proc);
  object_free(&proc);
  proc = lookup_var_val(c_str_to_datum("|cdr|"));
  object_free(&val);
  val = lookup_var_val(c_str_to_datum("|operand-codes|"));
  argl = cons(object_copy(val), empty);
  if (proc.type == PROC_APPLY) {
    proc = apply_proc();
    argl = apply_argl();
  }
  if (proc.type == PROC) {
    goto primitive_branch314;
  }
  cont.cont = &&after_call313;
  object_free(&val);
  val = compiled_procedure_entry(proc);
  goto *val.cont;
primitive_branch314:;
  object_free(&val);
  val = proc.proc(argl);
after_call313:;
  argl = cons(object_copy(val), empty);
  object_free(&proc);
  proc = restore();
  if (proc.type == PROC_APPLY) {
    proc = apply_proc();
    argl = apply_argl();
  }
  if (proc.type == PROC) {
    goto primitive_branch316;
  }
  cont.cont = &&after_call315;
  object_free(&val);
  val = compiled_procedure_entry(proc);
  goto *val.cont;
primitive_branch316:;
  object_free(&val);
  val = proc.proc(argl);
after_call315:;
  argl = cons(object_copy(val), empty);
  object_free(&env);
  env = restore();
  object_free(&val);
  val = lookup_var_val(c_str_to_datum("|code-for-next-arg|"));
  argl = cons(object_copy(val), argl);
  object_free(&val);
  val = c_str_to_datum("(|env| . ())");
  argl = cons(object_copy(val), argl);
  object_free(&proc);
  proc = restore();
  object_free(&cont);
  cont = restore();
  if (proc.type == PROC_APPLY) {
    proc = apply_proc();
    argl = apply_argl();
  }
  if (proc.type == PROC) {
    goto primitive_branch318;
  }
  object_free(&val);
  val = compiled_procedure_entry(proc);
  goto *val.cont;
primitive_branch318:;
  object_free(&val);
  val = proc.proc(argl);
  goto *cont.cont;
after_lambda309:;
  save(cont);
  save(proc);
  object_free(&proc);
  proc = lookup_var_val(c_str_to_datum("|preserving|"));
  save(proc);
  save(env);
  object_free(&proc);
  proc = lookup_var_val(c_str_to_datum("|c-make-instruction-sequence|"));
  object_free(&val);
  val = c_str_to_datum("(|argl = cons(object_copy(val), argl);| . ())");
  argl = cons(object_copy(val), empty);
  object_free(&val);
  val = c_str_to_datum("(|argl| . ())");
  argl = cons(object_copy(val), argl);
  object_free(&val);
  val = c_str_to_datum("(|val| . (|argl| . ()))");
  argl = cons(object_copy(val), argl);
  if (proc.type == PROC_APPLY) {
    proc = apply_proc();
    argl = apply_argl();
  }
  if (proc.type == PROC) {
    goto primitive_branch304;
  }
  cont.cont = &&after_call303;
  object_free(&val);
  val = compiled_procedure_entry(proc);
  goto *val.cont;
primitive_branch304:;
  object_free(&val);
  val = proc.proc(argl);
after_call303:;
  argl = cons(object_copy(val), empty);
  object_free(&env);
  env = restore();
  save(argl);
  object_free(&proc);
  proc = lookup_var_val(c_str_to_datum("|car|"));
  object_free(&val);
  val = lookup_var_val(c_str_to_datum("|operand-codes|"));
  argl = cons(object_copy(val), empty);
  if (proc.type == PROC_APPLY) {
    proc = apply_proc();
    argl = apply_argl();
  }
  if (proc.type == PROC) {
    goto primitive_branch306;
  }
  cont.cont = &&after_call305;
  object_free(&val);
  val = compiled_procedure_entry(proc);
  goto *val.cont;
primitive_branch306:;
  object_free(&val);
  val = proc.proc(argl);
after_call305:;
  object_free(&argl);
  argl = restore();
  argl = cons(object_copy(val), argl);
  object_free(&val);
  val = c_str_to_datum("(|argl| . ())");
  argl = cons(object_copy(val), argl);
  object_free(&proc);
  proc = restore();
  if (proc.type == PROC_APPLY) {
    proc = apply_proc();
    argl = apply_argl();
  }
  if (proc.type == PROC) {
    goto primitive_branch308;
  }
  cont.cont = &&after_call307;
  object_free(&val);
  val = compiled_procedure_entry(proc);
  goto *val.cont;
primitive_branch308:;
  object_free(&val);
  val = proc.proc(argl);
after_call307:;
  argl = cons(object_copy(val), empty);
  object_free(&proc);
  proc = restore();
  object_free(&cont);
  cont = restore();
  if (proc.type == PROC_APPLY) {
    proc = apply_proc();
    argl = apply_argl();
  }
  if (proc.type == PROC) {
    goto primitive_branch324;
  }
  object_free(&val);
  val = compiled_procedure_entry(proc);
  goto *val.cont;
primitive_branch324:;
  object_free(&val);
  val = proc.proc(argl);
  goto *cont.cont;
after_lambda301:;
  {
    Object t = def_var_val(c_str_to_datum("|code-to-get-rest-args|"));
    object_free(&val);
    val = t;
  }
  object_free(&val);
  val = make_compiled_procedure(&&entry250);
  goto after_lambda249;
entry250:
  env = compiled_procedure_env();
  env = extend_environment(c_str_to_datum("(|target| . (|linkage| . ()))"));
  object_free(&proc);
  proc = make_compiled_procedure(&&entry256);
  goto after_lambda255;
entry256:
  env = compiled_procedure_env();
  env = extend_environment(
      c_str_to_datum("(|primitive-branch| . (|after-call| . ()))"));
  object_free(&proc);
  proc = make_compiled_procedure(&&entry262);
  goto after_lambda261;
entry262:
  env = compiled_procedure_env();
  env = extend_environment(c_str_to_datum("(|compiled-linkage| . ())"));
  object_free(&proc);
  proc = lookup_var_val(c_str_to_datum("|append-instruction-sequences|"));
  save(cont);
  save(proc);
  save(env);
  save(env);
  object_free(&proc);
  proc = lookup_var_val(c_str_to_datum("|eq?|"));
  object_free(&val);
  val = c_str_to_datum("|next|");
  argl = cons(object_copy(val), empty);
  object_free(&val);
  val = lookup_var_val(c_str_to_datum("|linkage|"));
  argl = cons(object_copy(val), argl);
  if (proc.type == PROC_APPLY) {
    proc = apply_proc();
    argl = apply_argl();
  }
  if (proc.type == PROC) {
    goto primitive_branch272;
  }
  cont.cont = &&after_call271;
  object_free(&val);
  val = compiled_procedure_entry(proc);
  goto *val.cont;
primitive_branch272:;
  object_free(&val);
  val = proc.proc(argl);
after_call271:;
  object_free(&env);
  env = restore();
  if (val.type == BOOLEAN && !val.boolean) {
    goto false_branch264;
  }
  object_free(&proc);
  proc = lookup_var_val(c_str_to_datum("|c-make-instruction-sequence|"));
  save(proc);
  object_free(&proc);
  proc = lookup_var_val(c_str_to_datum("|list|"));
  object_free(&val);
  val = c_str_to_datum("|:;|");
  argl = cons(object_copy(val), empty);
  object_free(&val);
  val = lookup_var_val(c_str_to_datum("|after-call|"));
  argl = cons(object_copy(val), argl);
  if (proc.type == PROC_APPLY) {
    proc = apply_proc();
    argl = apply_argl();
  }
  if (proc.type == PROC) {
    goto primitive_branch268;
  }
  cont.cont = &&after_call267;
  object_free(&val);
  val = compiled_procedure_entry(proc);
  goto *val.cont;
primitive_branch268:;
  object_free(&val);
  val = proc.proc(argl);
after_call267:;
  argl = cons(object_copy(val), empty);
  object_free(&val);
  val = c_str_to_datum("()");
  argl = cons(object_copy(val), argl);
  object_free(&val);
  val = c_str_to_datum("()");
  argl = cons(object_copy(val), argl);
  object_free(&proc);
  proc = restore();
  if (proc.type == PROC_APPLY) {
    proc = apply_proc();
    argl = apply_argl();
  }
  if (proc.type == PROC) {
    goto primitive_branch270;
  }
  cont.cont = &&after_if263;
  object_free(&val);
  val = compiled_procedure_entry(proc);
  goto *val.cont;
primitive_branch270:;
  object_free(&val);
  val = proc.proc(argl);
  goto after_if263;
false_branch264:;
  object_free(&proc);
  proc = lookup_var_val(c_str_to_datum("|c-empty-instruction-sequence|"));
  argl = empty;
  if (proc.type == PROC_APPLY) {
    proc = apply_proc();
    argl = apply_argl();
  }
  if (proc.type == PROC) {
    goto primitive_branch266;
  }
  cont.cont = &&after_call265;
  object_free(&val);
  val = compiled_procedure_entry(proc);
  goto *val.cont;
primitive_branch266:;
  object_free(&val);
  val = proc.proc(argl);
after_call265:;
after_if263:;
  argl = cons(object_copy(val), empty);
  object_free(&env);
  env = restore();
  save(env);
  save(argl);
  object_free(&proc);
  proc = lookup_var_val(c_str_to_datum("|parallel-instruction-sequences|"));
  save(proc);
  save(env);
  object_free(&proc);
  proc = lookup_var_val(c_str_to_datum("|append-instruction-sequences|"));
  save(proc);
  save(env);
  object_free(&proc);
  proc = lookup_var_val(c_str_to_datum("|end-with-linkage|"));
  save(proc);
  save(env);
  object_free(&proc);
  proc = lookup_var_val(c_str_to_datum("|c-make-instruction-sequence|"));
  save(proc);
  save(env);
  object_free(&proc);
  proc = lookup_var_val(c_str_to_datum("|list|"));
  object_free(&val);
  val = c_str_to_datum("| = proc.proc(argl); |");
  argl = cons(object_copy(val), empty);
  object_free(&val);
  val = lookup_var_val(c_str_to_datum("|target|"));
  argl = cons(object_copy(val), argl);
  object_free(&val);
  val = c_str_to_datum("|);|");
  argl = cons(object_copy(val), argl);
  object_free(&val);
  val = lookup_var_val(c_str_to_datum("|target|"));
  argl = cons(object_copy(val), argl);
  object_free(&val);
  val = c_str_to_datum("|object_free(&|");
  argl = cons(object_copy(val), argl);
  if (proc.type == PROC_APPLY) {
    proc = apply_proc();
    argl = apply_argl();
  }
  if (proc.type == PROC) {
    goto primitive_branch274;
  }
  cont.cont = &&after_call273;
  object_free(&val);
  val = compiled_procedure_entry(proc);
  goto *val.cont;
primitive_branch274:;
  object_free(&val);
  val = proc.proc(argl);
after_call273:;
  argl = cons(object_copy(val), empty);
  object_free(&env);
  env = restore();
  save(argl);
  object_free(&proc);
  proc = lookup_var_val(c_str_to_datum("|list|"));
  object_free(&val);
  val = lookup_var_val(c_str_to_datum("|target|"));
  argl = cons(object_copy(val), empty);
  if (proc.type == PROC_APPLY) {
    proc = apply_proc();
    argl = apply_argl();
  }
  if (proc.type == PROC) {
    goto primitive_branch276;
  }
  cont.cont = &&after_call275;
  object_free(&val);
  val = compiled_procedure_entry(proc);
  goto *val.cont;
primitive_branch276:;
  object_free(&val);
  val = proc.proc(argl);
after_call275:;
  object_free(&argl);
  argl = restore();
  argl = cons(object_copy(val), argl);
  object_free(&val);
  val = c_str_to_datum("(|proc| . (|argl| . ()))");
  argl = cons(object_copy(val), argl);
  object_free(&proc);
  proc = restore();
  if (proc.type == PROC_APPLY) {
    proc = apply_proc();
    argl = apply_argl();
  }
  if (proc.type == PROC) {
    goto primitive_branch278;
  }
  cont.cont = &&after_call277;
  object_free(&val);
  val = compiled_procedure_entry(proc);
  goto *val.cont;
primitive_branch278:;
  object_free(&val);
  val = proc.proc(argl);
after_call277:;
  argl = cons(object_copy(val), empty);
  object_free(&env);
  env = restore();
  object_free(&val);
  val = lookup_var_val(c_str_to_datum("|linkage|"));
  argl = cons(object_copy(val), argl);
  object_free(&proc);
  proc = restore();
  if (proc.type == PROC_APPLY) {
    proc = apply_proc();
    argl = apply_argl();
  }
  if (proc.type == PROC) {
    goto primitive_branch280;
  }
  cont.cont = &&after_call279;
  object_free(&val);
  val = compiled_procedure_entry(proc);
  goto *val.cont;
primitive_branch280:;
  object_free(&val);
  val = proc.proc(argl);
after_call279:;
  argl = cons(object_copy(val), empty);
  object_free(&env);
  env = restore();
  save(argl);
  object_free(&proc);
  proc = lookup_var_val(c_str_to_datum("|c-make-instruction-sequence|"));
  save(proc);
  object_free(&proc);
  proc = lookup_var_val(c_str_to_datum("|list|"));
  object_free(&val);
  val = c_str_to_datum("|:;|");
  argl = cons(object_copy(val), empty);
  object_free(&val);
  val = lookup_var_val(c_str_to_datum("|primitive-branch|"));
  argl = cons(object_copy(val), argl);
  if (proc.type == PROC_APPLY) {
    proc = apply_proc();
    argl = apply_argl();
  }
  if (proc.type == PROC) {
    goto primitive_branch282;
  }
  cont.cont = &&after_call281;
  object_free(&val);
  val = compiled_procedure_entry(proc);
  goto *val.cont;
primitive_branch282:;
  object_free(&val);
  val = proc.proc(argl);
after_call281:;
  argl = cons(object_copy(val), empty);
  object_free(&val);
  val = c_str_to_datum("()");
  argl = cons(object_copy(val), argl);
  object_free(&val);
  val = c_str_to_datum("()");
  argl = cons(object_copy(val), argl);
  object_free(&proc);
  proc = restore();
  if (proc.type == PROC_APPLY) {
    proc = apply_proc();
    argl = apply_argl();
  }
  if (proc.type == PROC) {
    goto primitive_branch284;
  }
  cont.cont = &&after_call283;
  object_free(&val);
  val = compiled_procedure_entry(proc);
  goto *val.cont;
primitive_branch284:;
  object_free(&val);
  val = proc.proc(argl);
after_call283:;
  object_free(&argl);
  argl = restore();
  argl = cons(object_copy(val), argl);
  object_free(&proc);
  proc = restore();
  if (proc.type == PROC_APPLY) {
    proc = apply_proc();
    argl = apply_argl();
  }
  if (proc.type == PROC) {
    goto primitive_branch286;
  }
  cont.cont = &&after_call285;
  object_free(&val);
  val = compiled_procedure_entry(proc);
  goto *val.cont;
primitive_branch286:;
  object_free(&val);
  val = proc.proc(argl);
after_call285:;
  argl = cons(object_copy(val), empty);
  object_free(&env);
  env = restore();
  save(argl);
  object_free(&proc);
  proc = lookup_var_val(c_str_to_datum("|compile-proc-appl|"));
  object_free(&val);
  val = lookup_var_val(c_str_to_datum("|compiled-linkage|"));
  argl = cons(object_copy(val), empty);
  object_free(&val);
  val = lookup_var_val(c_str_to_datum("|target|"));
  argl = cons(object_copy(val), argl);
  if (proc.type == PROC_APPLY) {
    proc = apply_proc();
    argl = apply_argl();
  }
  if (proc.type == PROC) {
    goto primitive_branch288;
  }
  cont.cont = &&after_call287;
  object_free(&val);
  val = compiled_procedure_entry(proc);
  goto *val.cont;
primitive_branch288:;
  object_free(&val);
  val = proc.proc(argl);
after_call287:;
  object_free(&argl);
  argl = restore();
  argl = cons(object_copy(val), argl);
  object_free(&proc);
  proc = restore();
  if (proc.type == PROC_APPLY) {
    proc = apply_proc();
    argl = apply_argl();
  }
  if (proc.type == PROC) {
    goto primitive_branch290;
  }
  cont.cont = &&after_call289;
  object_free(&val);
  val = compiled_procedure_entry(proc);
  goto *val.cont;
primitive_branch290:;
  object_free(&val);
  val = proc.proc(argl);
after_call289:;
  object_free(&argl);
  argl = restore();
  argl = cons(object_copy(val), argl);
  object_free(&env);
  env = restore();
  save(argl);
  object_free(&proc);
  proc = lookup_var_val(c_str_to_datum("|c-make-instruction-sequence|"));
  save(proc);
  object_free(&proc);
  proc = lookup_var_val(c_str_to_datum("|list|"));
  object_free(&val);
  val = c_str_to_datum("|;}|");
  argl = cons(object_copy(val), empty);
  object_free(&val);
  val = lookup_var_val(c_str_to_datum("|primitive-branch|"));
  argl = cons(object_copy(val), argl);
  object_free(&val);
  val = c_str_to_datum("|if (proc.type == PROC_APPLY) {\\n                     "
                       "proc = apply_proc();\\n                     argl = "
                       "apply_argl();\\n                   }\\n                "
                       "   if (proc.type == PROC) { goto |");
  argl = cons(object_copy(val), argl);
  if (proc.type == PROC_APPLY) {
    proc = apply_proc();
    argl = apply_argl();
  }
  if (proc.type == PROC) {
    goto primitive_branch292;
  }
  cont.cont = &&after_call291;
  object_free(&val);
  val = compiled_procedure_entry(proc);
  goto *val.cont;
primitive_branch292:;
  object_free(&val);
  val = proc.proc(argl);
after_call291:;
  argl = cons(object_copy(val), empty);
  object_free(&val);
  val = c_str_to_datum("()");
  argl = cons(object_copy(val), argl);
  object_free(&val);
  val = c_str_to_datum("(|proc| . ())");
  argl = cons(object_copy(val), argl);
  object_free(&proc);
  proc = restore();
  if (proc.type == PROC_APPLY) {
    proc = apply_proc();
    argl = apply_argl();
  }
  if (proc.type == PROC) {
    goto primitive_branch294;
  }
  cont.cont = &&after_call293;
  object_free(&val);
  val = compiled_procedure_entry(proc);
  goto *val.cont;
primitive_branch294:;
  object_free(&val);
  val = proc.proc(argl);
after_call293:;
  object_free(&argl);
  argl = restore();
  argl = cons(object_copy(val), argl);
  object_free(&proc);
  proc = restore();
  object_free(&cont);
  cont = restore();
  if (proc.type == PROC_APPLY) {
    proc = apply_proc();
    argl = apply_argl();
  }
  if (proc.type == PROC) {
    goto primitive_branch296;
  }
  object_free(&val);
  val = compiled_procedure_entry(proc);
  goto *val.cont;
primitive_branch296:;
  object_free(&val);
  val = proc.proc(argl);
  goto *cont.cont;
after_lambda261:;
  save(cont);
  save(proc);
  save(env);
  object_free(&proc);
  proc = lookup_var_val(c_str_to_datum("|eq?|"));
  object_free(&val);
  val = c_str_to_datum("|next|");
  argl = cons(object_copy(val), empty);
  object_free(&val);
  val = lookup_var_val(c_str_to_datum("|linkage|"));
  argl = cons(object_copy(val), argl);
  if (proc.type == PROC_APPLY) {
    proc = apply_proc();
    argl = apply_argl();
  }
  if (proc.type == PROC) {
    goto primitive_branch260;
  }
  cont.cont = &&after_call259;
  object_free(&val);
  val = compiled_procedure_entry(proc);
  goto *val.cont;
primitive_branch260:;
  object_free(&val);
  val = proc.proc(argl);
after_call259:;
  object_free(&env);
  env = restore();
  if (val.type == BOOLEAN && !val.boolean) {
    goto false_branch258;
  }
  object_free(&val);
  val = lookup_var_val(c_str_to_datum("|after-call|"));
  goto after_if257;
false_branch258:;
  object_free(&val);
  val = lookup_var_val(c_str_to_datum("|linkage|"));
after_if257:;
  argl = cons(object_copy(val), empty);
  object_free(&proc);
  proc = restore();
  object_free(&cont);
  cont = restore();
  if (proc.type == PROC_APPLY) {
    proc = apply_proc();
    argl = apply_argl();
  }
  if (proc.type == PROC) {
    goto primitive_branch298;
  }
  object_free(&val);
  val = compiled_procedure_entry(proc);
  goto *val.cont;
primitive_branch298:;
  object_free(&val);
  val = proc.proc(argl);
  goto *cont.cont;
after_lambda255:;
  save(cont);
  save(proc);
  save(env);
  object_free(&proc);
  proc = lookup_var_val(c_str_to_datum("|make-label|"));
  object_free(&val);
  val = c_str_to_datum("|after_call|");
  argl = cons(object_copy(val), empty);
  if (proc.type == PROC_APPLY) {
    proc = apply_proc();
    argl = apply_argl();
  }
  if (proc.type == PROC) {
    goto primitive_branch252;
  }
  cont.cont = &&after_call251;
  object_free(&val);
  val = compiled_procedure_entry(proc);
  goto *val.cont;
primitive_branch252:;
  object_free(&val);
  val = proc.proc(argl);
after_call251:;
  argl = cons(object_copy(val), empty);
  object_free(&env);
  env = restore();
  save(argl);
  object_free(&proc);
  proc = lookup_var_val(c_str_to_datum("|make-label|"));
  object_free(&val);
  val = c_str_to_datum("|primitive_branch|");
  argl = cons(object_copy(val), empty);
  if (proc.type == PROC_APPLY) {
    proc = apply_proc();
    argl = apply_argl();
  }
  if (proc.type == PROC) {
    goto primitive_branch254;
  }
  cont.cont = &&after_call253;
  object_free(&val);
  val = compiled_procedure_entry(proc);
  goto *val.cont;
primitive_branch254:;
  object_free(&val);
  val = proc.proc(argl);
after_call253:;
  object_free(&argl);
  argl = restore();
  argl = cons(object_copy(val), argl);
  object_free(&proc);
  proc = restore();
  object_free(&cont);
  cont = restore();
  if (proc.type == PROC_APPLY) {
    proc = apply_proc();
    argl = apply_argl();
  }
  if (proc.type == PROC) {
    goto primitive_branch300;
  }
  object_free(&val);
  val = compiled_procedure_entry(proc);
  goto *val.cont;
primitive_branch300:;
  object_free(&val);
  val = proc.proc(argl);
  goto *cont.cont;
after_lambda249:;
  {
    Object t = def_var_val(c_str_to_datum("|compile-procedure-call|"));
    object_free(&val);
    val = t;
  }
  object_free(&val);
  val = make_compiled_procedure(&&entry190);
  goto after_lambda189;
entry190:
  env = compiled_procedure_env();
  env = extend_environment(c_str_to_datum("(|target| . (|linkage| . ()))"));
  save(cont);
  save(env);
  save(env);
  object_free(&proc);
  proc = lookup_var_val(c_str_to_datum("|eq?|"));
  object_free(&val);
  val = c_str_to_datum("|val|");
  argl = cons(object_copy(val), empty);
  object_free(&val);
  val = lookup_var_val(c_str_to_datum("|target|"));
  argl = cons(object_copy(val), argl);
  if (proc.type == PROC_APPLY) {
    proc = apply_proc();
    argl = apply_argl();
  }
  if (proc.type == PROC) {
    goto primitive_branch248;
  }
  cont.cont = &&after_call247;
  object_free(&val);
  val = compiled_procedure_entry(proc);
  goto *val.cont;
primitive_branch248:;
  object_free(&val);
  val = proc.proc(argl);
after_call247:;
  object_free(&env);
  env = restore();
  if (val.type == BOOLEAN && !val.boolean) {
    goto false_branch242;
  }
  object_free(&proc);
  proc = lookup_var_val(c_str_to_datum("|not|"));
  save(proc);
  object_free(&proc);
  proc = lookup_var_val(c_str_to_datum("|eq?|"));
  object_free(&val);
  val = c_str_to_datum("|return|");
  argl = cons(object_copy(val), empty);
  object_free(&val);
  val = lookup_var_val(c_str_to_datum("|linkage|"));
  argl = cons(object_copy(val), argl);
  if (proc.type == PROC_APPLY) {
    proc = apply_proc();
    argl = apply_argl();
  }
  if (proc.type == PROC) {
    goto primitive_branch244;
  }
  cont.cont = &&after_call243;
  object_free(&val);
  val = compiled_procedure_entry(proc);
  goto *val.cont;
primitive_branch244:;
  object_free(&val);
  val = proc.proc(argl);
after_call243:;
  argl = cons(object_copy(val), empty);
  object_free(&proc);
  proc = restore();
  if (proc.type == PROC_APPLY) {
    proc = apply_proc();
    argl = apply_argl();
  }
  if (proc.type == PROC) {
    goto primitive_branch246;
  }
  cont.cont = &&after_if241;
  object_free(&val);
  val = compiled_procedure_entry(proc);
  goto *val.cont;
primitive_branch246:;
  object_free(&val);
  val = proc.proc(argl);
  goto after_if241;
false_branch242:;
  object_free(&val);
  val = c_str_to_datum("#false");
after_if241:;
  object_free(&env);
  env = restore();
  object_free(&cont);
  cont = restore();
  if (val.type == BOOLEAN && !val.boolean) {
    goto false_branch192;
  }
  object_free(&proc);
  proc = lookup_var_val(c_str_to_datum("|c-make-instruction-sequence|"));
  save(cont);
  save(proc);
  save(env);
  object_free(&proc);
  proc = lookup_var_val(c_str_to_datum("|list|"));
  object_free(&val);
  val = c_str_to_datum("|;\\n                 object_free(&val);\\n            "
                       "     val = compiled_procedure_entry(proc);\\n          "
                       "       goto *val.cont;|");
  argl = cons(object_copy(val), empty);
  object_free(&val);
  val = lookup_var_val(c_str_to_datum("|linkage|"));
  argl = cons(object_copy(val), argl);
  object_free(&val);
  val = c_str_to_datum("|cont.cont = &&|");
  argl = cons(object_copy(val), argl);
  if (proc.type == PROC_APPLY) {
    proc = apply_proc();
    argl = apply_argl();
  }
  if (proc.type == PROC) {
    goto primitive_branch238;
  }
  cont.cont = &&after_call237;
  object_free(&val);
  val = compiled_procedure_entry(proc);
  goto *val.cont;
primitive_branch238:;
  object_free(&val);
  val = proc.proc(argl);
after_call237:;
  argl = cons(object_copy(val), empty);
  object_free(&env);
  env = restore();
  object_free(&val);
  val = lookup_var_val(c_str_to_datum("|all-regs|"));
  argl = cons(object_copy(val), argl);
  object_free(&val);
  val = c_str_to_datum("(|proc| . ())");
  argl = cons(object_copy(val), argl);
  object_free(&proc);
  proc = restore();
  object_free(&cont);
  cont = restore();
  if (proc.type == PROC_APPLY) {
    proc = apply_proc();
    argl = apply_argl();
  }
  if (proc.type == PROC) {
    goto primitive_branch240;
  }
  object_free(&val);
  val = compiled_procedure_entry(proc);
  goto *val.cont;
primitive_branch240:;
  object_free(&val);
  val = proc.proc(argl);
  goto *cont.cont;
false_branch192:;
  save(cont);
  save(env);
  save(env);
  object_free(&proc);
  proc = lookup_var_val(c_str_to_datum("|not|"));
  save(proc);
  object_free(&proc);
  proc = lookup_var_val(c_str_to_datum("|eq?|"));
  object_free(&val);
  val = c_str_to_datum("|val|");
  argl = cons(object_copy(val), empty);
  object_free(&val);
  val = lookup_var_val(c_str_to_datum("|target|"));
  argl = cons(object_copy(val), argl);
  if (proc.type == PROC_APPLY) {
    proc = apply_proc();
    argl = apply_argl();
  }
  if (proc.type == PROC) {
    goto primitive_branch234;
  }
  cont.cont = &&after_call233;
  object_free(&val);
  val = compiled_procedure_entry(proc);
  goto *val.cont;
primitive_branch234:;
  object_free(&val);
  val = proc.proc(argl);
after_call233:;
  argl = cons(object_copy(val), empty);
  object_free(&proc);
  proc = restore();
  if (proc.type == PROC_APPLY) {
    proc = apply_proc();
    argl = apply_argl();
  }
  if (proc.type == PROC) {
    goto primitive_branch236;
  }
  cont.cont = &&after_call235;
  object_free(&val);
  val = compiled_procedure_entry(proc);
  goto *val.cont;
primitive_branch236:;
  object_free(&val);
  val = proc.proc(argl);
after_call235:;
  object_free(&env);
  env = restore();
  if (val.type == BOOLEAN && !val.boolean) {
    goto false_branch228;
  }
  object_free(&proc);
  proc = lookup_var_val(c_str_to_datum("|not|"));
  save(proc);
  object_free(&proc);
  proc = lookup_var_val(c_str_to_datum("|eq?|"));
  object_free(&val);
  val = c_str_to_datum("|return|");
  argl = cons(object_copy(val), empty);
  object_free(&val);
  val = lookup_var_val(c_str_to_datum("|linkage|"));
  argl = cons(object_copy(val), argl);
  if (proc.type == PROC_APPLY) {
    proc = apply_proc();
    argl = apply_argl();
  }
  if (proc.type == PROC) {
    goto primitive_branch230;
  }
  cont.cont = &&after_call229;
  object_free(&val);
  val = compiled_procedure_entry(proc);
  goto *val.cont;
primitive_branch230:;
  object_free(&val);
  val = proc.proc(argl);
after_call229:;
  argl = cons(object_copy(val), empty);
  object_free(&proc);
  proc = restore();
  if (proc.type == PROC_APPLY) {
    proc = apply_proc();
    argl = apply_argl();
  }
  if (proc.type == PROC) {
    goto primitive_branch232;
  }
  cont.cont = &&after_if227;
  object_free(&val);
  val = compiled_procedure_entry(proc);
  goto *val.cont;
primitive_branch232:;
  object_free(&val);
  val = proc.proc(argl);
  goto after_if227;
false_branch228:;
  object_free(&val);
  val = c_str_to_datum("#false");
after_if227:;
  object_free(&env);
  env = restore();
  object_free(&cont);
  cont = restore();
  if (val.type == BOOLEAN && !val.boolean) {
    goto false_branch194;
  }
  object_free(&proc);
  proc = make_compiled_procedure(&&entry220);
  goto after_lambda219;
entry220:
  env = compiled_procedure_env();
  env = extend_environment(c_str_to_datum("(|proc-return| . ())"));
  object_free(&proc);
  proc = lookup_var_val(c_str_to_datum("|c-make-instruction-sequence|"));
  save(cont);
  save(proc);
  save(env);
  object_free(&proc);
  proc = lookup_var_val(c_str_to_datum("|list|"));
  object_free(&val);
  val = c_str_to_datum("|;|");
  argl = cons(object_copy(val), empty);
  object_free(&val);
  val = lookup_var_val(c_str_to_datum("|linkage|"));
  argl = cons(object_copy(val), argl);
  object_free(&val);
  val = c_str_to_datum(
      "| = val; val.type = NONE;\\n                        goto |");
  argl = cons(object_copy(val), argl);
  object_free(&val);
  val = lookup_var_val(c_str_to_datum("|target|"));
  argl = cons(object_copy(val), argl);
  object_free(&val);
  val = c_str_to_datum("|);|");
  argl = cons(object_copy(val), argl);
  object_free(&val);
  val = lookup_var_val(c_str_to_datum("|target|"));
  argl = cons(object_copy(val), argl);
  object_free(&val);
  val = c_str_to_datum("|:\\n                        object_free(&|");
  argl = cons(object_copy(val), argl);
  object_free(&val);
  val = lookup_var_val(c_str_to_datum("|proc-return|"));
  argl = cons(object_copy(val), argl);
  object_free(&val);
  val = c_str_to_datum("|;\\n                        object_free(&val);\\n     "
                       "                   val = "
                       "compiled_procedure_entry(proc);\\n                     "
                       "   goto *val.cont;|");
  argl = cons(object_copy(val), argl);
  object_free(&val);
  val = lookup_var_val(c_str_to_datum("|proc-return|"));
  argl = cons(object_copy(val), argl);
  object_free(&val);
  val = c_str_to_datum("|cont.cont = &&|");
  argl = cons(object_copy(val), argl);
  if (proc.type == PROC_APPLY) {
    proc = apply_proc();
    argl = apply_argl();
  }
  if (proc.type == PROC) {
    goto primitive_branch222;
  }
  cont.cont = &&after_call221;
  object_free(&val);
  val = compiled_procedure_entry(proc);
  goto *val.cont;
primitive_branch222:;
  object_free(&val);
  val = proc.proc(argl);
after_call221:;
  argl = cons(object_copy(val), empty);
  object_free(&env);
  env = restore();
  object_free(&val);
  val = lookup_var_val(c_str_to_datum("|all-regs|"));
  argl = cons(object_copy(val), argl);
  object_free(&val);
  val = c_str_to_datum("(|proc| . ())");
  argl = cons(object_copy(val), argl);
  object_free(&proc);
  proc = restore();
  object_free(&cont);
  cont = restore();
  if (proc.type == PROC_APPLY) {
    proc = apply_proc();
    argl = apply_argl();
  }
  if (proc.type == PROC) {
    goto primitive_branch224;
  }
  object_free(&val);
  val = compiled_procedure_entry(proc);
  goto *val.cont;
primitive_branch224:;
  object_free(&val);
  val = proc.proc(argl);
  goto *cont.cont;
after_lambda219:;
  save(cont);
  save(proc);
  object_free(&proc);
  proc = lookup_var_val(c_str_to_datum("|make-label|"));
  object_free(&val);
  val = c_str_to_datum("|proc_return|");
  argl = cons(object_copy(val), empty);
  if (proc.type == PROC_APPLY) {
    proc = apply_proc();
    argl = apply_argl();
  }
  if (proc.type == PROC) {
    goto primitive_branch218;
  }
  cont.cont = &&after_call217;
  object_free(&val);
  val = compiled_procedure_entry(proc);
  goto *val.cont;
primitive_branch218:;
  object_free(&val);
  val = proc.proc(argl);
after_call217:;
  argl = cons(object_copy(val), empty);
  object_free(&proc);
  proc = restore();
  object_free(&cont);
  cont = restore();
  if (proc.type == PROC_APPLY) {
    proc = apply_proc();
    argl = apply_argl();
  }
  if (proc.type == PROC) {
    goto primitive_branch226;
  }
  object_free(&val);
  val = compiled_procedure_entry(proc);
  goto *val.cont;
primitive_branch226:;
  object_free(&val);
  val = proc.proc(argl);
  goto *cont.cont;
false_branch194:;
  save(cont);
  save(env);
  save(env);
  object_free(&proc);
  proc = lookup_var_val(c_str_to_datum("|eq?|"));
  object_free(&val);
  val = c_str_to_datum("|val|");
  argl = cons(object_copy(val), empty);
  object_free(&val);
  val = lookup_var_val(c_str_to_datum("|target|"));
  argl = cons(object_copy(val), argl);
  if (proc.type == PROC_APPLY) {
    proc = apply_proc();
    argl = apply_argl();
  }
  if (proc.type == PROC) {
    goto primitive_branch216;
  }
  cont.cont = &&after_call215;
  object_free(&val);
  val = compiled_procedure_entry(proc);
  goto *val.cont;
primitive_branch216:;
  object_free(&val);
  val = proc.proc(argl);
after_call215:;
  object_free(&env);
  env = restore();
  if (val.type == BOOLEAN && !val.boolean) {
    goto false_branch212;
  }
  object_free(&proc);
  proc = lookup_var_val(c_str_to_datum("|eq?|"));
  object_free(&val);
  val = c_str_to_datum("|return|");
  argl = cons(object_copy(val), empty);
  object_free(&val);
  val = lookup_var_val(c_str_to_datum("|linkage|"));
  argl = cons(object_copy(val), argl);
  if (proc.type == PROC_APPLY) {
    proc = apply_proc();
    argl = apply_argl();
  }
  if (proc.type == PROC) {
    goto primitive_branch214;
  }
  cont.cont = &&after_if211;
  object_free(&val);
  val = compiled_procedure_entry(proc);
  goto *val.cont;
primitive_branch214:;
  object_free(&val);
  val = proc.proc(argl);
  goto after_if211;
false_branch212:;
  object_free(&val);
  val = c_str_to_datum("#false");
after_if211:;
  object_free(&env);
  env = restore();
  object_free(&cont);
  cont = restore();
  if (val.type == BOOLEAN && !val.boolean) {
    goto false_branch196;
  }
  object_free(&proc);
  proc = lookup_var_val(c_str_to_datum("|c-make-instruction-sequence|"));
  object_free(&val);
  val = c_str_to_datum("(|object_free(&val);\\n                    val = "
                       "compiled_procedure_entry(proc);\\n                    "
                       "goto *val.cont;| . ())");
  argl = cons(object_copy(val), empty);
  object_free(&val);
  val = lookup_var_val(c_str_to_datum("|all-regs|"));
  argl = cons(object_copy(val), argl);
  object_free(&val);
  val = c_str_to_datum("(|proc| . (|cont| . ()))");
  argl = cons(object_copy(val), argl);
  if (proc.type == PROC_APPLY) {
    proc = apply_proc();
    argl = apply_argl();
  }
  if (proc.type == PROC) {
    goto primitive_branch210;
  }
  object_free(&val);
  val = compiled_procedure_entry(proc);
  goto *val.cont;
primitive_branch210:;
  object_free(&val);
  val = proc.proc(argl);
  goto *cont.cont;
false_branch196:;
  save(cont);
  save(env);
  save(env);
  object_free(&proc);
  proc = lookup_var_val(c_str_to_datum("|not|"));
  save(proc);
  object_free(&proc);
  proc = lookup_var_val(c_str_to_datum("|eq?|"));
  object_free(&val);
  val = c_str_to_datum("|val|");
  argl = cons(object_copy(val), empty);
  object_free(&val);
  val = lookup_var_val(c_str_to_datum("|target|"));
  argl = cons(object_copy(val), argl);
  if (proc.type == PROC_APPLY) {
    proc = apply_proc();
    argl = apply_argl();
  }
  if (proc.type == PROC) {
    goto primitive_branch206;
  }
  cont.cont = &&after_call205;
  object_free(&val);
  val = compiled_procedure_entry(proc);
  goto *val.cont;
primitive_branch206:;
  object_free(&val);
  val = proc.proc(argl);
after_call205:;
  argl = cons(object_copy(val), empty);
  object_free(&proc);
  proc = restore();
  if (proc.type == PROC_APPLY) {
    proc = apply_proc();
    argl = apply_argl();
  }
  if (proc.type == PROC) {
    goto primitive_branch208;
  }
  cont.cont = &&after_call207;
  object_free(&val);
  val = compiled_procedure_entry(proc);
  goto *val.cont;
primitive_branch208:;
  object_free(&val);
  val = proc.proc(argl);
after_call207:;
  object_free(&env);
  env = restore();
  if (val.type == BOOLEAN && !val.boolean) {
    goto false_branch202;
  }
  object_free(&proc);
  proc = lookup_var_val(c_str_to_datum("|eq?|"));
  object_free(&val);
  val = c_str_to_datum("|return|");
  argl = cons(object_copy(val), empty);
  object_free(&val);
  val = lookup_var_val(c_str_to_datum("|linkage|"));
  argl = cons(object_copy(val), argl);
  if (proc.type == PROC_APPLY) {
    proc = apply_proc();
    argl = apply_argl();
  }
  if (proc.type == PROC) {
    goto primitive_branch204;
  }
  cont.cont = &&after_if201;
  object_free(&val);
  val = compiled_procedure_entry(proc);
  goto *val.cont;
primitive_branch204:;
  object_free(&val);
  val = proc.proc(argl);
  goto after_if201;
false_branch202:;
  object_free(&val);
  val = c_str_to_datum("#false");
after_if201:;
  object_free(&env);
  env = restore();
  object_free(&cont);
  cont = restore();
  if (val.type == BOOLEAN && !val.boolean) {
    goto false_branch198;
  }
  object_free(&proc);
  proc = lookup_var_val(c_str_to_datum("|error|"));
  object_free(&val);
  val = lookup_var_val(c_str_to_datum("|target|"));
  argl = cons(object_copy(val), empty);
  object_free(&val);
  val = c_str_to_datum("|return linkage, target not val -- compile|");
  argl = cons(object_copy(val), argl);
  if (proc.type == PROC_APPLY) {
    proc = apply_proc();
    argl = apply_argl();
  }
  if (proc.type == PROC) {
    goto primitive_branch200;
  }
  object_free(&val);
  val = compiled_procedure_entry(proc);
  goto *val.cont;
primitive_branch200:;
  object_free(&val);
  val = proc.proc(argl);
  goto *cont.cont;
false_branch198:;
  object_free(&val);
  val = undef;
  goto *cont.cont;
after_lambda189:;
  {
    Object t = def_var_val(c_str_to_datum("|compile-proc-appl|"));
    object_free(&val);
    val = t;
  }
  object_free(&val);
  val =
      c_str_to_datum("(|env| . (|proc| . (|val| . (|argl| . (|cont| . ())))))");
  {
    Object t = def_var_val(c_str_to_datum("|all-regs|"));
    object_free(&val);
    val = t;
  }
  object_free(&val);
  val = make_compiled_procedure(&&entry144);
  goto after_lambda143;
entry144:
  env = compiled_procedure_env();
  env = extend_environment(c_str_to_datum("|seqs|"));
  object_free(&val);
  val = make_compiled_procedure(&&entry164);
  goto after_lambda163;
entry164:
  env = compiled_procedure_env();
  env = extend_environment(c_str_to_datum("(|seq1| . (|seq2| . ()))"));
  object_free(&proc);
  proc = lookup_var_val(c_str_to_datum("|c-make-instruction-sequence|"));
  save(cont);
  save(proc);
  save(env);
  object_free(&proc);
  proc = lookup_var_val(c_str_to_datum("|c-append|"));
  save(proc);
  save(env);
  object_free(&proc);
  proc = lookup_var_val(c_str_to_datum("|c-statements|"));
  object_free(&val);
  val = lookup_var_val(c_str_to_datum("|seq2|"));
  argl = cons(object_copy(val), empty);
  if (proc.type == PROC_APPLY) {
    proc = apply_proc();
    argl = apply_argl();
  }
  if (proc.type == PROC) {
    goto primitive_branch166;
  }
  cont.cont = &&after_call165;
  object_free(&val);
  val = compiled_procedure_entry(proc);
  goto *val.cont;
primitive_branch166:;
  object_free(&val);
  val = proc.proc(argl);
after_call165:;
  argl = cons(object_copy(val), empty);
  object_free(&env);
  env = restore();
  save(argl);
  object_free(&proc);
  proc = lookup_var_val(c_str_to_datum("|c-statements|"));
  object_free(&val);
  val = lookup_var_val(c_str_to_datum("|seq1|"));
  argl = cons(object_copy(val), empty);
  if (proc.type == PROC_APPLY) {
    proc = apply_proc();
    argl = apply_argl();
  }
  if (proc.type == PROC) {
    goto primitive_branch168;
  }
  cont.cont = &&after_call167;
  object_free(&val);
  val = compiled_procedure_entry(proc);
  goto *val.cont;
primitive_branch168:;
  object_free(&val);
  val = proc.proc(argl);
after_call167:;
  object_free(&argl);
  argl = restore();
  argl = cons(object_copy(val), argl);
  object_free(&proc);
  proc = restore();
  if (proc.type == PROC_APPLY) {
    proc = apply_proc();
    argl = apply_argl();
  }
  if (proc.type == PROC) {
    goto primitive_branch170;
  }
  cont.cont = &&after_call169;
  object_free(&val);
  val = compiled_procedure_entry(proc);
  goto *val.cont;
primitive_branch170:;
  object_free(&val);
  val = proc.proc(argl);
after_call169:;
  argl = cons(object_copy(val), empty);
  object_free(&env);
  env = restore();
  save(env);
  save(argl);
  object_free(&proc);
  proc = lookup_var_val(c_str_to_datum("|c-list-union|"));
  save(proc);
  save(env);
  object_free(&proc);
  proc = lookup_var_val(c_str_to_datum("|c-registers-modified|"));
  object_free(&val);
  val = lookup_var_val(c_str_to_datum("|seq2|"));
  argl = cons(object_copy(val), empty);
  if (proc.type == PROC_APPLY) {
    proc = apply_proc();
    argl = apply_argl();
  }
  if (proc.type == PROC) {
    goto primitive_branch172;
  }
  cont.cont = &&after_call171;
  object_free(&val);
  val = compiled_procedure_entry(proc);
  goto *val.cont;
primitive_branch172:;
  object_free(&val);
  val = proc.proc(argl);
after_call171:;
  argl = cons(object_copy(val), empty);
  object_free(&env);
  env = restore();
  save(argl);
  object_free(&proc);
  proc = lookup_var_val(c_str_to_datum("|c-registers-modified|"));
  object_free(&val);
  val = lookup_var_val(c_str_to_datum("|seq1|"));
  argl = cons(object_copy(val), empty);
  if (proc.type == PROC_APPLY) {
    proc = apply_proc();
    argl = apply_argl();
  }
  if (proc.type == PROC) {
    goto primitive_branch174;
  }
  cont.cont = &&after_call173;
  object_free(&val);
  val = compiled_procedure_entry(proc);
  goto *val.cont;
primitive_branch174:;
  object_free(&val);
  val = proc.proc(argl);
after_call173:;
  object_free(&argl);
  argl = restore();
  argl = cons(object_copy(val), argl);
  object_free(&proc);
  proc = restore();
  if (proc.type == PROC_APPLY) {
    proc = apply_proc();
    argl = apply_argl();
  }
  if (proc.type == PROC) {
    goto primitive_branch176;
  }
  cont.cont = &&after_call175;
  object_free(&val);
  val = compiled_procedure_entry(proc);
  goto *val.cont;
primitive_branch176:;
  object_free(&val);
  val = proc.proc(argl);
after_call175:;
  object_free(&argl);
  argl = restore();
  argl = cons(object_copy(val), argl);
  object_free(&env);
  env = restore();
  save(argl);
  object_free(&proc);
  proc = lookup_var_val(c_str_to_datum("|c-list-union|"));
  save(proc);
  save(env);
  object_free(&proc);
  proc = lookup_var_val(c_str_to_datum("|c-list-difference|"));
  save(proc);
  save(env);
  object_free(&proc);
  proc = lookup_var_val(c_str_to_datum("|c-registers-modified|"));
  object_free(&val);
  val = lookup_var_val(c_str_to_datum("|seq1|"));
  argl = cons(object_copy(val), empty);
  if (proc.type == PROC_APPLY) {
    proc = apply_proc();
    argl = apply_argl();
  }
  if (proc.type == PROC) {
    goto primitive_branch178;
  }
  cont.cont = &&after_call177;
  object_free(&val);
  val = compiled_procedure_entry(proc);
  goto *val.cont;
primitive_branch178:;
  object_free(&val);
  val = proc.proc(argl);
after_call177:;
  argl = cons(object_copy(val), empty);
  object_free(&env);
  env = restore();
  save(argl);
  object_free(&proc);
  proc = lookup_var_val(c_str_to_datum("|c-registers-needed|"));
  object_free(&val);
  val = lookup_var_val(c_str_to_datum("|seq2|"));
  argl = cons(object_copy(val), empty);
  if (proc.type == PROC_APPLY) {
    proc = apply_proc();
    argl = apply_argl();
  }
  if (proc.type == PROC) {
    goto primitive_branch180;
  }
  cont.cont = &&after_call179;
  object_free(&val);
  val = compiled_procedure_entry(proc);
  goto *val.cont;
primitive_branch180:;
  object_free(&val);
  val = proc.proc(argl);
after_call179:;
  object_free(&argl);
  argl = restore();
  argl = cons(object_copy(val), argl);
  object_free(&proc);
  proc = restore();
  if (proc.type == PROC_APPLY) {
    proc = apply_proc();
    argl = apply_argl();
  }
  if (proc.type == PROC) {
    goto primitive_branch182;
  }
  cont.cont = &&after_call181;
  object_free(&val);
  val = compiled_procedure_entry(proc);
  goto *val.cont;
primitive_branch182:;
  object_free(&val);
  val = proc.proc(argl);
after_call181:;
  argl = cons(object_copy(val), empty);
  object_free(&env);
  env = restore();
  save(argl);
  object_free(&proc);
  proc = lookup_var_val(c_str_to_datum("|c-registers-needed|"));
  object_free(&val);
  val = lookup_var_val(c_str_to_datum("|seq1|"));
  argl = cons(object_copy(val), empty);
  if (proc.type == PROC_APPLY) {
    proc = apply_proc();
    argl = apply_argl();
  }
  if (proc.type == PROC) {
    goto primitive_branch184;
  }
  cont.cont = &&after_call183;
  object_free(&val);
  val = compiled_procedure_entry(proc);
  goto *val.cont;
primitive_branch184:;
  object_free(&val);
  val = proc.proc(argl);
after_call183:;
  object_free(&argl);
  argl = restore();
  argl = cons(object_copy(val), argl);
  object_free(&proc);
  proc = restore();
  if (proc.type == PROC_APPLY) {
    proc = apply_proc();
    argl = apply_argl();
  }
  if (proc.type == PROC) {
    goto primitive_branch186;
  }
  cont.cont = &&after_call185;
  object_free(&val);
  val = compiled_procedure_entry(proc);
  goto *val.cont;
primitive_branch186:;
  object_free(&val);
  val = proc.proc(argl);
after_call185:;
  object_free(&argl);
  argl = restore();
  argl = cons(object_copy(val), argl);
  object_free(&proc);
  proc = restore();
  object_free(&cont);
  cont = restore();
  if (proc.type == PROC_APPLY) {
    proc = apply_proc();
    argl = apply_argl();
  }
  if (proc.type == PROC) {
    goto primitive_branch188;
  }
  object_free(&val);
  val = compiled_procedure_entry(proc);
  goto *val.cont;
primitive_branch188:;
  object_free(&val);
  val = proc.proc(argl);
  goto *cont.cont;
after_lambda163:;
  {
    Object t = def_var_val(c_str_to_datum("|append-2-sequences|"));
    object_free(&val);
    val = t;
  }
  object_free(&val);
  val = make_compiled_procedure(&&entry148);
  goto after_lambda147;
entry148:
  env = compiled_procedure_env();
  env = extend_environment(c_str_to_datum("(|seqs| . ())"));
  save(cont);
  save(env);
  object_free(&proc);
  proc = lookup_var_val(c_str_to_datum("|null?|"));
  object_free(&val);
  val = lookup_var_val(c_str_to_datum("|seqs|"));
  argl = cons(object_copy(val), empty);
  if (proc.type == PROC_APPLY) {
    proc = apply_proc();
    argl = apply_argl();
  }
  if (proc.type == PROC) {
    goto primitive_branch162;
  }
  cont.cont = &&after_call161;
  object_free(&val);
  val = compiled_procedure_entry(proc);
  goto *val.cont;
primitive_branch162:;
  object_free(&val);
  val = proc.proc(argl);
after_call161:;
  object_free(&env);
  env = restore();
  object_free(&cont);
  cont = restore();
  if (val.type == BOOLEAN && !val.boolean) {
    goto false_branch150;
  }
  object_free(&proc);
  proc = lookup_var_val(c_str_to_datum("|c-empty-instruction-sequence|"));
  argl = empty;
  if (proc.type == PROC_APPLY) {
    proc = apply_proc();
    argl = apply_argl();
  }
  if (proc.type == PROC) {
    goto primitive_branch160;
  }
  object_free(&val);
  val = compiled_procedure_entry(proc);
  goto *val.cont;
primitive_branch160:;
  object_free(&val);
  val = proc.proc(argl);
  goto *cont.cont;
false_branch150:;
  object_free(&proc);
  proc = lookup_var_val(c_str_to_datum("|append-2-sequences|"));
  save(cont);
  save(proc);
  save(env);
  object_free(&proc);
  proc = lookup_var_val(c_str_to_datum("|append-seq-list|"));
  save(proc);
  object_free(&proc);
  proc = lookup_var_val(c_str_to_datum("|cdr|"));
  object_free(&val);
  val = lookup_var_val(c_str_to_datum("|seqs|"));
  argl = cons(object_copy(val), empty);
  if (proc.type == PROC_APPLY) {
    proc = apply_proc();
    argl = apply_argl();
  }
  if (proc.type == PROC) {
    goto primitive_branch152;
  }
  cont.cont = &&after_call151;
  object_free(&val);
  val = compiled_procedure_entry(proc);
  goto *val.cont;
primitive_branch152:;
  object_free(&val);
  val = proc.proc(argl);
after_call151:;
  argl = cons(object_copy(val), empty);
  object_free(&proc);
  proc = restore();
  if (proc.type == PROC_APPLY) {
    proc = apply_proc();
    argl = apply_argl();
  }
  if (proc.type == PROC) {
    goto primitive_branch154;
  }
  cont.cont = &&after_call153;
  object_free(&val);
  val = compiled_procedure_entry(proc);
  goto *val.cont;
primitive_branch154:;
  object_free(&val);
  val = proc.proc(argl);
after_call153:;
  argl = cons(object_copy(val), empty);
  object_free(&env);
  env = restore();
  save(argl);
  object_free(&proc);
  proc = lookup_var_val(c_str_to_datum("|car|"));
  object_free(&val);
  val = lookup_var_val(c_str_to_datum("|seqs|"));
  argl = cons(object_copy(val), empty);
  if (proc.type == PROC_APPLY) {
    proc = apply_proc();
    argl = apply_argl();
  }
  if (proc.type == PROC) {
    goto primitive_branch156;
  }
  cont.cont = &&after_call155;
  object_free(&val);
  val = compiled_procedure_entry(proc);
  goto *val.cont;
primitive_branch156:;
  object_free(&val);
  val = proc.proc(argl);
after_call155:;
  object_free(&argl);
  argl = restore();
  argl = cons(object_copy(val), argl);
  object_free(&proc);
  proc = restore();
  object_free(&cont);
  cont = restore();
  if (proc.type == PROC_APPLY) {
    proc = apply_proc();
    argl = apply_argl();
  }
  if (proc.type == PROC) {
    goto primitive_branch158;
  }
  object_free(&val);
  val = compiled_procedure_entry(proc);
  goto *val.cont;
primitive_branch158:;
  object_free(&val);
  val = proc.proc(argl);
  goto *cont.cont;
after_lambda147:;
  {
    Object t = def_var_val(c_str_to_datum("|append-seq-list|"));
    object_free(&val);
    val = t;
  }
  object_free(&proc);
  proc = lookup_var_val(c_str_to_datum("|append-seq-list|"));
  object_free(&val);
  val = lookup_var_val(c_str_to_datum("|seqs|"));
  argl = cons(object_copy(val), empty);
  if (proc.type == PROC_APPLY) {
    proc = apply_proc();
    argl = apply_argl();
  }
  if (proc.type == PROC) {
    goto primitive_branch146;
  }
  object_free(&val);
  val = compiled_procedure_entry(proc);
  goto *val.cont;
primitive_branch146:;
  object_free(&val);
  val = proc.proc(argl);
  goto *cont.cont;
after_lambda143:;
  {
    Object t = def_var_val(c_str_to_datum("|append-instruction-sequences|"));
    object_free(&val);
    val = t;
  }
  object_free(&val);
  val = make_compiled_procedure(&&entry92);
  goto after_lambda91;
entry92:
  env = compiled_procedure_env();
  env =
      extend_environment(c_str_to_datum("(|regs| . (|seq1| . (|seq2| . ())))"));
  save(cont);
  save(env);
  object_free(&proc);
  proc = lookup_var_val(c_str_to_datum("|null?|"));
  object_free(&val);
  val = lookup_var_val(c_str_to_datum("|regs|"));
  argl = cons(object_copy(val), empty);
  if (proc.type == PROC_APPLY) {
    proc = apply_proc();
    argl = apply_argl();
  }
  if (proc.type == PROC) {
    goto primitive_branch142;
  }
  cont.cont = &&after_call141;
  object_free(&val);
  val = compiled_procedure_entry(proc);
  goto *val.cont;
primitive_branch142:;
  object_free(&val);
  val = proc.proc(argl);
after_call141:;
  object_free(&env);
  env = restore();
  object_free(&cont);
  cont = restore();
  if (val.type == BOOLEAN && !val.boolean) {
    goto false_branch94;
  }
  object_free(&proc);
  proc = lookup_var_val(c_str_to_datum("|append-instruction-sequences|"));
  object_free(&val);
  val = lookup_var_val(c_str_to_datum("|seq2|"));
  argl = cons(object_copy(val), empty);
  object_free(&val);
  val = lookup_var_val(c_str_to_datum("|seq1|"));
  argl = cons(object_copy(val), argl);
  if (proc.type == PROC_APPLY) {
    proc = apply_proc();
    argl = apply_argl();
  }
  if (proc.type == PROC) {
    goto primitive_branch140;
  }
  object_free(&val);
  val = compiled_procedure_entry(proc);
  goto *val.cont;
primitive_branch140:;
  object_free(&val);
  val = proc.proc(argl);
  goto *cont.cont;
false_branch94:;
  object_free(&proc);
  proc = make_compiled_procedure(&&entry98);
  goto after_lambda97;
entry98:
  env = compiled_procedure_env();
  env = extend_environment(c_str_to_datum("(|first-reg| . ())"));
  save(cont);
  save(env);
  save(env);
  object_free(&proc);
  proc = lookup_var_val(c_str_to_datum("|c-needs-register?|"));
  object_free(&val);
  val = lookup_var_val(c_str_to_datum("|first-reg|"));
  argl = cons(object_copy(val), empty);
  object_free(&val);
  val = lookup_var_val(c_str_to_datum("|seq2|"));
  argl = cons(object_copy(val), argl);
  if (proc.type == PROC_APPLY) {
    proc = apply_proc();
    argl = apply_argl();
  }
  if (proc.type == PROC) {
    goto primitive_branch136;
  }
  cont.cont = &&after_call135;
  object_free(&val);
  val = compiled_procedure_entry(proc);
  goto *val.cont;
primitive_branch136:;
  object_free(&val);
  val = proc.proc(argl);
after_call135:;
  object_free(&env);
  env = restore();
  if (val.type == BOOLEAN && !val.boolean) {
    goto false_branch132;
  }
  object_free(&proc);
  proc = lookup_var_val(c_str_to_datum("|c-modifies-register?|"));
  object_free(&val);
  val = lookup_var_val(c_str_to_datum("|first-reg|"));
  argl = cons(object_copy(val), empty);
  object_free(&val);
  val = lookup_var_val(c_str_to_datum("|seq1|"));
  argl = cons(object_copy(val), argl);
  if (proc.type == PROC_APPLY) {
    proc = apply_proc();
    argl = apply_argl();
  }
  if (proc.type == PROC) {
    goto primitive_branch134;
  }
  cont.cont = &&after_if131;
  object_free(&val);
  val = compiled_procedure_entry(proc);
  goto *val.cont;
primitive_branch134:;
  object_free(&val);
  val = proc.proc(argl);
  goto after_if131;
false_branch132:;
  object_free(&val);
  val = c_str_to_datum("#false");
after_if131:;
  object_free(&env);
  env = restore();
  object_free(&cont);
  cont = restore();
  if (val.type == BOOLEAN && !val.boolean) {
    goto false_branch100;
  }
  object_free(&proc);
  proc = lookup_var_val(c_str_to_datum("|preserving|"));
  save(cont);
  save(proc);
  object_free(&val);
  val = lookup_var_val(c_str_to_datum("|seq2|"));
  argl = cons(object_copy(val), empty);
  save(env);
  save(argl);
  object_free(&proc);
  proc = lookup_var_val(c_str_to_datum("|c-make-instruction-sequence|"));
  save(proc);
  save(env);
  object_free(&proc);
  proc = lookup_var_val(c_str_to_datum("|c-append|"));
  save(proc);
  save(env);
  object_free(&proc);
  proc = lookup_var_val(c_str_to_datum("|list|"));
  object_free(&val);
  val = c_str_to_datum("| =restore();|");
  argl = cons(object_copy(val), empty);
  object_free(&val);
  val = lookup_var_val(c_str_to_datum("|first-reg|"));
  argl = cons(object_copy(val), argl);
  object_free(&val);
  val = c_str_to_datum("|);|");
  argl = cons(object_copy(val), argl);
  object_free(&val);
  val = lookup_var_val(c_str_to_datum("|first-reg|"));
  argl = cons(object_copy(val), argl);
  object_free(&val);
  val = c_str_to_datum("|object_free(&|");
  argl = cons(object_copy(val), argl);
  if (proc.type == PROC_APPLY) {
    proc = apply_proc();
    argl = apply_argl();
  }
  if (proc.type == PROC) {
    goto primitive_branch106;
  }
  cont.cont = &&after_call105;
  object_free(&val);
  val = compiled_procedure_entry(proc);
  goto *val.cont;
primitive_branch106:;
  object_free(&val);
  val = proc.proc(argl);
after_call105:;
  argl = cons(object_copy(val), empty);
  object_free(&env);
  env = restore();
  save(env);
  save(argl);
  object_free(&proc);
  proc = lookup_var_val(c_str_to_datum("|c-statements|"));
  object_free(&val);
  val = lookup_var_val(c_str_to_datum("|seq1|"));
  argl = cons(object_copy(val), empty);
  if (proc.type == PROC_APPLY) {
    proc = apply_proc();
    argl = apply_argl();
  }
  if (proc.type == PROC) {
    goto primitive_branch108;
  }
  cont.cont = &&after_call107;
  object_free(&val);
  val = compiled_procedure_entry(proc);
  goto *val.cont;
primitive_branch108:;
  object_free(&val);
  val = proc.proc(argl);
after_call107:;
  object_free(&argl);
  argl = restore();
  argl = cons(object_copy(val), argl);
  object_free(&env);
  env = restore();
  save(argl);
  object_free(&proc);
  proc = lookup_var_val(c_str_to_datum("|list|"));
  object_free(&val);
  val = c_str_to_datum("|);|");
  argl = cons(object_copy(val), empty);
  object_free(&val);
  val = lookup_var_val(c_str_to_datum("|first-reg|"));
  argl = cons(object_copy(val), argl);
  object_free(&val);
  val = c_str_to_datum("|save(|");
  argl = cons(object_copy(val), argl);
  if (proc.type == PROC_APPLY) {
    proc = apply_proc();
    argl = apply_argl();
  }
  if (proc.type == PROC) {
    goto primitive_branch110;
  }
  cont.cont = &&after_call109;
  object_free(&val);
  val = compiled_procedure_entry(proc);
  goto *val.cont;
primitive_branch110:;
  object_free(&val);
  val = proc.proc(argl);
after_call109:;
  object_free(&argl);
  argl = restore();
  argl = cons(object_copy(val), argl);
  object_free(&proc);
  proc = restore();
  if (proc.type == PROC_APPLY) {
    proc = apply_proc();
    argl = apply_argl();
  }
  if (proc.type == PROC) {
    goto primitive_branch112;
  }
  cont.cont = &&after_call111;
  object_free(&val);
  val = compiled_procedure_entry(proc);
  goto *val.cont;
primitive_branch112:;
  object_free(&val);
  val = proc.proc(argl);
after_call111:;
  argl = cons(object_copy(val), empty);
  object_free(&env);
  env = restore();
  save(env);
  save(argl);
  object_free(&proc);
  proc = lookup_var_val(c_str_to_datum("|c-list-difference|"));
  save(proc);
  save(env);
  object_free(&proc);
  proc = lookup_var_val(c_str_to_datum("|list|"));
  object_free(&val);
  val = lookup_var_val(c_str_to_datum("|first-reg|"));
  argl = cons(object_copy(val), empty);
  if (proc.type == PROC_APPLY) {
    proc = apply_proc();
    argl = apply_argl();
  }
  if (proc.type == PROC) {
    goto primitive_branch114;
  }
  cont.cont = &&after_call113;
  object_free(&val);
  val = compiled_procedure_entry(proc);
  goto *val.cont;
primitive_branch114:;
  object_free(&val);
  val = proc.proc(argl);
after_call113:;
  argl = cons(object_copy(val), empty);
  object_free(&env);
  env = restore();
  save(argl);
  object_free(&proc);
  proc = lookup_var_val(c_str_to_datum("|c-registers-modified|"));
  object_free(&val);
  val = lookup_var_val(c_str_to_datum("|seq1|"));
  argl = cons(object_copy(val), empty);
  if (proc.type == PROC_APPLY) {
    proc = apply_proc();
    argl = apply_argl();
  }
  if (proc.type == PROC) {
    goto primitive_branch116;
  }
  cont.cont = &&after_call115;
  object_free(&val);
  val = compiled_procedure_entry(proc);
  goto *val.cont;
primitive_branch116:;
  object_free(&val);
  val = proc.proc(argl);
after_call115:;
  object_free(&argl);
  argl = restore();
  argl = cons(object_copy(val), argl);
  object_free(&proc);
  proc = restore();
  if (proc.type == PROC_APPLY) {
    proc = apply_proc();
    argl = apply_argl();
  }
  if (proc.type == PROC) {
    goto primitive_branch118;
  }
  cont.cont = &&after_call117;
  object_free(&val);
  val = compiled_procedure_entry(proc);
  goto *val.cont;
primitive_branch118:;
  object_free(&val);
  val = proc.proc(argl);
after_call117:;
  object_free(&argl);
  argl = restore();
  argl = cons(object_copy(val), argl);
  object_free(&env);
  env = restore();
  save(argl);
  object_free(&proc);
  proc = lookup_var_val(c_str_to_datum("|c-list-union|"));
  save(proc);
  save(env);
  object_free(&proc);
  proc = lookup_var_val(c_str_to_datum("|c-registers-needed|"));
  object_free(&val);
  val = lookup_var_val(c_str_to_datum("|seq1|"));
  argl = cons(object_copy(val), empty);
  if (proc.type == PROC_APPLY) {
    proc = apply_proc();
    argl = apply_argl();
  }
  if (proc.type == PROC) {
    goto primitive_branch120;
  }
  cont.cont = &&after_call119;
  object_free(&val);
  val = compiled_procedure_entry(proc);
  goto *val.cont;
primitive_branch120:;
  object_free(&val);
  val = proc.proc(argl);
after_call119:;
  argl = cons(object_copy(val), empty);
  object_free(&env);
  env = restore();
  save(argl);
  object_free(&proc);
  proc = lookup_var_val(c_str_to_datum("|list|"));
  object_free(&val);
  val = lookup_var_val(c_str_to_datum("|first-reg|"));
  argl = cons(object_copy(val), empty);
  if (proc.type == PROC_APPLY) {
    proc = apply_proc();
    argl = apply_argl();
  }
  if (proc.type == PROC) {
    goto primitive_branch122;
  }
  cont.cont = &&after_call121;
  object_free(&val);
  val = compiled_procedure_entry(proc);
  goto *val.cont;
primitive_branch122:;
  object_free(&val);
  val = proc.proc(argl);
after_call121:;
  object_free(&argl);
  argl = restore();
  argl = cons(object_copy(val), argl);
  object_free(&proc);
  proc = restore();
  if (proc.type == PROC_APPLY) {
    proc = apply_proc();
    argl = apply_argl();
  }
  if (proc.type == PROC) {
    goto primitive_branch124;
  }
  cont.cont = &&after_call123;
  object_free(&val);
  val = compiled_procedure_entry(proc);
  goto *val.cont;
primitive_branch124:;
  object_free(&val);
  val = proc.proc(argl);
after_call123:;
  object_free(&argl);
  argl = restore();
  argl = cons(object_copy(val), argl);
  object_free(&proc);
  proc = restore();
  if (proc.type == PROC_APPLY) {
    proc = apply_proc();
    argl = apply_argl();
  }
  if (proc.type == PROC) {
    goto primitive_branch126;
  }
  cont.cont = &&after_call125;
  object_free(&val);
  val = compiled_procedure_entry(proc);
  goto *val.cont;
primitive_branch126:;
  object_free(&val);
  val = proc.proc(argl);
after_call125:;
  object_free(&argl);
  argl = restore();
  argl = cons(object_copy(val), argl);
  object_free(&env);
  env = restore();
  save(argl);
  object_free(&proc);
  proc = lookup_var_val(c_str_to_datum("|cdr|"));
  object_free(&val);
  val = lookup_var_val(c_str_to_datum("|regs|"));
  argl = cons(object_copy(val), empty);
  if (proc.type == PROC_APPLY) {
    proc = apply_proc();
    argl = apply_argl();
  }
  if (proc.type == PROC) {
    goto primitive_branch128;
  }
  cont.cont = &&after_call127;
  object_free(&val);
  val = compiled_procedure_entry(proc);
  goto *val.cont;
primitive_branch128:;
  object_free(&val);
  val = proc.proc(argl);
after_call127:;
  object_free(&argl);
  argl = restore();
  argl = cons(object_copy(val), argl);
  object_free(&proc);
  proc = restore();
  object_free(&cont);
  cont = restore();
  if (proc.type == PROC_APPLY) {
    proc = apply_proc();
    argl = apply_argl();
  }
  if (proc.type == PROC) {
    goto primitive_branch130;
  }
  object_free(&val);
  val = compiled_procedure_entry(proc);
  goto *val.cont;
primitive_branch130:;
  object_free(&val);
  val = proc.proc(argl);
  goto *cont.cont;
false_branch100:;
  object_free(&proc);
  proc = lookup_var_val(c_str_to_datum("|preserving|"));
  save(cont);
  save(proc);
  object_free(&val);
  val = lookup_var_val(c_str_to_datum("|seq2|"));
  argl = cons(object_copy(val), empty);
  object_free(&val);
  val = lookup_var_val(c_str_to_datum("|seq1|"));
  argl = cons(object_copy(val), argl);
  save(argl);
  object_free(&proc);
  proc = lookup_var_val(c_str_to_datum("|cdr|"));
  object_free(&val);
  val = lookup_var_val(c_str_to_datum("|regs|"));
  argl = cons(object_copy(val), empty);
  if (proc.type == PROC_APPLY) {
    proc = apply_proc();
    argl = apply_argl();
  }
  if (proc.type == PROC) {
    goto primitive_branch102;
  }
  cont.cont = &&after_call101;
  object_free(&val);
  val = compiled_procedure_entry(proc);
  goto *val.cont;
primitive_branch102:;
  object_free(&val);
  val = proc.proc(argl);
after_call101:;
  object_free(&argl);
  argl = restore();
  argl = cons(object_copy(val), argl);
  object_free(&proc);
  proc = restore();
  object_free(&cont);
  cont = restore();
  if (proc.type == PROC_APPLY) {
    proc = apply_proc();
    argl = apply_argl();
  }
  if (proc.type == PROC) {
    goto primitive_branch104;
  }
  object_free(&val);
  val = compiled_procedure_entry(proc);
  goto *val.cont;
primitive_branch104:;
  object_free(&val);
  val = proc.proc(argl);
  goto *cont.cont;
after_lambda97:;
  save(cont);
  save(proc);
  object_free(&proc);
  proc = lookup_var_val(c_str_to_datum("|car|"));
  object_free(&val);
  val = lookup_var_val(c_str_to_datum("|regs|"));
  argl = cons(object_copy(val), empty);
  if (proc.type == PROC_APPLY) {
    proc = apply_proc();
    argl = apply_argl();
  }
  if (proc.type == PROC) {
    goto primitive_branch96;
  }
  cont.cont = &&after_call95;
  object_free(&val);
  val = compiled_procedure_entry(proc);
  goto *val.cont;
primitive_branch96:;
  object_free(&val);
  val = proc.proc(argl);
after_call95:;
  argl = cons(object_copy(val), empty);
  object_free(&proc);
  proc = restore();
  object_free(&cont);
  cont = restore();
  if (proc.type == PROC_APPLY) {
    proc = apply_proc();
    argl = apply_argl();
  }
  if (proc.type == PROC) {
    goto primitive_branch138;
  }
  object_free(&val);
  val = compiled_procedure_entry(proc);
  goto *val.cont;
primitive_branch138:;
  object_free(&val);
  val = proc.proc(argl);
  goto *cont.cont;
after_lambda91:;
  {
    Object t = def_var_val(c_str_to_datum("|preserving|"));
    object_free(&val);
    val = t;
  }
  object_free(&val);
  val = make_compiled_procedure(&&entry78);
  goto after_lambda77;
entry78:
  env = compiled_procedure_env();
  env = extend_environment(c_str_to_datum("(|seq| . (|body-seq| . ()))"));
  object_free(&proc);
  proc = lookup_var_val(c_str_to_datum("|c-make-instruction-sequence|"));
  save(cont);
  save(proc);
  save(env);
  object_free(&proc);
  proc = lookup_var_val(c_str_to_datum("|c-append|"));
  save(proc);
  save(env);
  object_free(&proc);
  proc = lookup_var_val(c_str_to_datum("|c-statements|"));
  object_free(&val);
  val = lookup_var_val(c_str_to_datum("|body-seq|"));
  argl = cons(object_copy(val), empty);
  if (proc.type == PROC_APPLY) {
    proc = apply_proc();
    argl = apply_argl();
  }
  if (proc.type == PROC) {
    goto primitive_branch80;
  }
  cont.cont = &&after_call79;
  object_free(&val);
  val = compiled_procedure_entry(proc);
  goto *val.cont;
primitive_branch80:;
  object_free(&val);
  val = proc.proc(argl);
after_call79:;
  argl = cons(object_copy(val), empty);
  object_free(&env);
  env = restore();
  save(argl);
  object_free(&proc);
  proc = lookup_var_val(c_str_to_datum("|c-statements|"));
  object_free(&val);
  val = lookup_var_val(c_str_to_datum("|seq|"));
  argl = cons(object_copy(val), empty);
  if (proc.type == PROC_APPLY) {
    proc = apply_proc();
    argl = apply_argl();
  }
  if (proc.type == PROC) {
    goto primitive_branch82;
  }
  cont.cont = &&after_call81;
  object_free(&val);
  val = compiled_procedure_entry(proc);
  goto *val.cont;
primitive_branch82:;
  object_free(&val);
  val = proc.proc(argl);
after_call81:;
  object_free(&argl);
  argl = restore();
  argl = cons(object_copy(val), argl);
  object_free(&proc);
  proc = restore();
  if (proc.type == PROC_APPLY) {
    proc = apply_proc();
    argl = apply_argl();
  }
  if (proc.type == PROC) {
    goto primitive_branch84;
  }
  cont.cont = &&after_call83;
  object_free(&val);
  val = compiled_procedure_entry(proc);
  goto *val.cont;
primitive_branch84:;
  object_free(&val);
  val = proc.proc(argl);
after_call83:;
  argl = cons(object_copy(val), empty);
  object_free(&env);
  env = restore();
  save(env);
  save(argl);
  object_free(&proc);
  proc = lookup_var_val(c_str_to_datum("|c-registers-modified|"));
  object_free(&val);
  val = lookup_var_val(c_str_to_datum("|seq|"));
  argl = cons(object_copy(val), empty);
  if (proc.type == PROC_APPLY) {
    proc = apply_proc();
    argl = apply_argl();
  }
  if (proc.type == PROC) {
    goto primitive_branch86;
  }
  cont.cont = &&after_call85;
  object_free(&val);
  val = compiled_procedure_entry(proc);
  goto *val.cont;
primitive_branch86:;
  object_free(&val);
  val = proc.proc(argl);
after_call85:;
  object_free(&argl);
  argl = restore();
  argl = cons(object_copy(val), argl);
  object_free(&env);
  env = restore();
  save(argl);
  object_free(&proc);
  proc = lookup_var_val(c_str_to_datum("|c-registers-needed|"));
  object_free(&val);
  val = lookup_var_val(c_str_to_datum("|seq|"));
  argl = cons(object_copy(val), empty);
  if (proc.type == PROC_APPLY) {
    proc = apply_proc();
    argl = apply_argl();
  }
  if (proc.type == PROC) {
    goto primitive_branch88;
  }
  cont.cont = &&after_call87;
  object_free(&val);
  val = compiled_procedure_entry(proc);
  goto *val.cont;
primitive_branch88:;
  object_free(&val);
  val = proc.proc(argl);
after_call87:;
  object_free(&argl);
  argl = restore();
  argl = cons(object_copy(val), argl);
  object_free(&proc);
  proc = restore();
  object_free(&cont);
  cont = restore();
  if (proc.type == PROC_APPLY) {
    proc = apply_proc();
    argl = apply_argl();
  }
  if (proc.type == PROC) {
    goto primitive_branch90;
  }
  object_free(&val);
  val = compiled_procedure_entry(proc);
  goto *val.cont;
primitive_branch90:;
  object_free(&val);
  val = proc.proc(argl);
  goto *cont.cont;
after_lambda77:;
  {
    Object t = def_var_val(c_str_to_datum("|tack-on-instruction-sequence|"));
    object_free(&val);
    val = t;
  }
  object_free(&val);
  val = make_compiled_procedure(&&entry56);
  goto after_lambda55;
entry56:
  env = compiled_procedure_env();
  env = extend_environment(c_str_to_datum("(|seq1| . (|seq2| . ()))"));
  object_free(&proc);
  proc = lookup_var_val(c_str_to_datum("|c-make-instruction-sequence|"));
  save(cont);
  save(proc);
  save(env);
  object_free(&proc);
  proc = lookup_var_val(c_str_to_datum("|c-append|"));
  save(proc);
  save(env);
  object_free(&proc);
  proc = lookup_var_val(c_str_to_datum("|c-statements|"));
  object_free(&val);
  val = lookup_var_val(c_str_to_datum("|seq2|"));
  argl = cons(object_copy(val), empty);
  if (proc.type == PROC_APPLY) {
    proc = apply_proc();
    argl = apply_argl();
  }
  if (proc.type == PROC) {
    goto primitive_branch58;
  }
  cont.cont = &&after_call57;
  object_free(&val);
  val = compiled_procedure_entry(proc);
  goto *val.cont;
primitive_branch58:;
  object_free(&val);
  val = proc.proc(argl);
after_call57:;
  argl = cons(object_copy(val), empty);
  object_free(&env);
  env = restore();
  save(argl);
  object_free(&proc);
  proc = lookup_var_val(c_str_to_datum("|c-statements|"));
  object_free(&val);
  val = lookup_var_val(c_str_to_datum("|seq1|"));
  argl = cons(object_copy(val), empty);
  if (proc.type == PROC_APPLY) {
    proc = apply_proc();
    argl = apply_argl();
  }
  if (proc.type == PROC) {
    goto primitive_branch60;
  }
  cont.cont = &&after_call59;
  object_free(&val);
  val = compiled_procedure_entry(proc);
  goto *val.cont;
primitive_branch60:;
  object_free(&val);
  val = proc.proc(argl);
after_call59:;
  object_free(&argl);
  argl = restore();
  argl = cons(object_copy(val), argl);
  object_free(&proc);
  proc = restore();
  if (proc.type == PROC_APPLY) {
    proc = apply_proc();
    argl = apply_argl();
  }
  if (proc.type == PROC) {
    goto primitive_branch62;
  }
  cont.cont = &&after_call61;
  object_free(&val);
  val = compiled_procedure_entry(proc);
  goto *val.cont;
primitive_branch62:;
  object_free(&val);
  val = proc.proc(argl);
after_call61:;
  argl = cons(object_copy(val), empty);
  object_free(&env);
  env = restore();
  save(env);
  save(argl);
  object_free(&proc);
  proc = lookup_var_val(c_str_to_datum("|c-list-union|"));
  save(proc);
  save(env);
  object_free(&proc);
  proc = lookup_var_val(c_str_to_datum("|c-registers-modified|"));
  object_free(&val);
  val = lookup_var_val(c_str_to_datum("|seq2|"));
  argl = cons(object_copy(val), empty);
  if (proc.type == PROC_APPLY) {
    proc = apply_proc();
    argl = apply_argl();
  }
  if (proc.type == PROC) {
    goto primitive_branch64;
  }
  cont.cont = &&after_call63;
  object_free(&val);
  val = compiled_procedure_entry(proc);
  goto *val.cont;
primitive_branch64:;
  object_free(&val);
  val = proc.proc(argl);
after_call63:;
  argl = cons(object_copy(val), empty);
  object_free(&env);
  env = restore();
  save(argl);
  object_free(&proc);
  proc = lookup_var_val(c_str_to_datum("|c-registers-modified|"));
  object_free(&val);
  val = lookup_var_val(c_str_to_datum("|seq1|"));
  argl = cons(object_copy(val), empty);
  if (proc.type == PROC_APPLY) {
    proc = apply_proc();
    argl = apply_argl();
  }
  if (proc.type == PROC) {
    goto primitive_branch66;
  }
  cont.cont = &&after_call65;
  object_free(&val);
  val = compiled_procedure_entry(proc);
  goto *val.cont;
primitive_branch66:;
  object_free(&val);
  val = proc.proc(argl);
after_call65:;
  object_free(&argl);
  argl = restore();
  argl = cons(object_copy(val), argl);
  object_free(&proc);
  proc = restore();
  if (proc.type == PROC_APPLY) {
    proc = apply_proc();
    argl = apply_argl();
  }
  if (proc.type == PROC) {
    goto primitive_branch68;
  }
  cont.cont = &&after_call67;
  object_free(&val);
  val = compiled_procedure_entry(proc);
  goto *val.cont;
primitive_branch68:;
  object_free(&val);
  val = proc.proc(argl);
after_call67:;
  object_free(&argl);
  argl = restore();
  argl = cons(object_copy(val), argl);
  object_free(&env);
  env = restore();
  save(argl);
  object_free(&proc);
  proc = lookup_var_val(c_str_to_datum("|c-list-union|"));
  save(proc);
  save(env);
  object_free(&proc);
  proc = lookup_var_val(c_str_to_datum("|c-registers-needed|"));
  object_free(&val);
  val = lookup_var_val(c_str_to_datum("|seq2|"));
  argl = cons(object_copy(val), empty);
  if (proc.type == PROC_APPLY) {
    proc = apply_proc();
    argl = apply_argl();
  }
  if (proc.type == PROC) {
    goto primitive_branch70;
  }
  cont.cont = &&after_call69;
  object_free(&val);
  val = compiled_procedure_entry(proc);
  goto *val.cont;
primitive_branch70:;
  object_free(&val);
  val = proc.proc(argl);
after_call69:;
  argl = cons(object_copy(val), empty);
  object_free(&env);
  env = restore();
  save(argl);
  object_free(&proc);
  proc = lookup_var_val(c_str_to_datum("|c-registers-needed|"));
  object_free(&val);
  val = lookup_var_val(c_str_to_datum("|seq1|"));
  argl = cons(object_copy(val), empty);
  if (proc.type == PROC_APPLY) {
    proc = apply_proc();
    argl = apply_argl();
  }
  if (proc.type == PROC) {
    goto primitive_branch72;
  }
  cont.cont = &&after_call71;
  object_free(&val);
  val = compiled_procedure_entry(proc);
  goto *val.cont;
primitive_branch72:;
  object_free(&val);
  val = proc.proc(argl);
after_call71:;
  object_free(&argl);
  argl = restore();
  argl = cons(object_copy(val), argl);
  object_free(&proc);
  proc = restore();
  if (proc.type == PROC_APPLY) {
    proc = apply_proc();
    argl = apply_argl();
  }
  if (proc.type == PROC) {
    goto primitive_branch74;
  }
  cont.cont = &&after_call73;
  object_free(&val);
  val = compiled_procedure_entry(proc);
  goto *val.cont;
primitive_branch74:;
  object_free(&val);
  val = proc.proc(argl);
after_call73:;
  object_free(&argl);
  argl = restore();
  argl = cons(object_copy(val), argl);
  object_free(&proc);
  proc = restore();
  object_free(&cont);
  cont = restore();
  if (proc.type == PROC_APPLY) {
    proc = apply_proc();
    argl = apply_argl();
  }
  if (proc.type == PROC) {
    goto primitive_branch76;
  }
  object_free(&val);
  val = compiled_procedure_entry(proc);
  goto *val.cont;
primitive_branch76:;
  object_free(&val);
  val = proc.proc(argl);
  goto *cont.cont;
after_lambda55:;
  {
    Object t = def_var_val(c_str_to_datum("|parallel-instruction-sequences|"));
    object_free(&val);
    val = t;
  }
  save(env);
  object_free(&proc);
  proc = lookup_var_val(c_str_to_datum("|command-line|"));
  argl = empty;
  if (proc.type == PROC_APPLY) {
    proc = apply_proc();
    argl = apply_argl();
  }
  if (proc.type == PROC) {
    goto primitive_branch54;
  }
  cont.cont = &&after_call53;
  object_free(&val);
  val = compiled_procedure_entry(proc);
  goto *val.cont;
primitive_branch54:;
  object_free(&val);
  val = proc.proc(argl);
after_call53:;
  object_free(&env);
  env = restore();
  {
    Object t = def_var_val(c_str_to_datum("|argv|"));
    object_free(&val);
    val = t;
  }
  save(env);
  object_free(&proc);
  proc = lookup_var_val(c_str_to_datum("|c-=|"));
  save(proc);
  object_free(&val);
  val = c_str_to_datum("2");
  argl = cons(object_copy(val), empty);
  save(argl);
  object_free(&proc);
  proc = lookup_var_val(c_str_to_datum("|length|"));
  object_free(&val);
  val = lookup_var_val(c_str_to_datum("|argv|"));
  argl = cons(object_copy(val), empty);
  if (proc.type == PROC_APPLY) {
    proc = apply_proc();
    argl = apply_argl();
  }
  if (proc.type == PROC) {
    goto primitive_branch50;
  }
  cont.cont = &&after_call49;
  object_free(&val);
  val = compiled_procedure_entry(proc);
  goto *val.cont;
primitive_branch50:;
  object_free(&val);
  val = proc.proc(argl);
after_call49:;
  object_free(&argl);
  argl = restore();
  argl = cons(object_copy(val), argl);
  object_free(&proc);
  proc = restore();
  if (proc.type == PROC_APPLY) {
    proc = apply_proc();
    argl = apply_argl();
  }
  if (proc.type == PROC) {
    goto primitive_branch52;
  }
  cont.cont = &&after_call51;
  object_free(&val);
  val = compiled_procedure_entry(proc);
  goto *val.cont;
primitive_branch52:;
  object_free(&val);
  val = proc.proc(argl);
after_call51:;
  object_free(&env);
  env = restore();
  if (val.type == BOOLEAN && !val.boolean) {
    goto false_branch2;
  }
  save(env);
  object_free(&proc);
  proc = lookup_var_val(c_str_to_datum("|c-cadr|"));
  object_free(&val);
  val = lookup_var_val(c_str_to_datum("|argv|"));
  argl = cons(object_copy(val), empty);
  if (proc.type == PROC_APPLY) {
    proc = apply_proc();
    argl = apply_argl();
  }
  if (proc.type == PROC) {
    goto primitive_branch48;
  }
  cont.cont = &&after_call47;
  object_free(&val);
  val = compiled_procedure_entry(proc);
  goto *val.cont;
primitive_branch48:;
  object_free(&val);
  val = proc.proc(argl);
after_call47:;
  object_free(&env);
  env = restore();
  {
    Object t = def_var_val(c_str_to_datum("|target|"));
    object_free(&val);
    val = t;
  }
  save(env);
  object_free(&proc);
  proc = lookup_var_val(c_str_to_datum("|c-list->string|"));
  save(proc);
  object_free(&proc);
  proc = lookup_var_val(c_str_to_datum("|c-append|"));
  save(proc);
  save(env);
  object_free(&proc);
  proc = lookup_var_val(c_str_to_datum("|c-string->list|"));
  object_free(&val);
  val = c_str_to_datum("\".scm\"");
  argl = cons(object_copy(val), empty);
  if (proc.type == PROC_APPLY) {
    proc = apply_proc();
    argl = apply_argl();
  }
  if (proc.type == PROC) {
    goto primitive_branch40;
  }
  cont.cont = &&after_call39;
  object_free(&val);
  val = compiled_procedure_entry(proc);
  goto *val.cont;
primitive_branch40:;
  object_free(&val);
  val = proc.proc(argl);
after_call39:;
  argl = cons(object_copy(val), empty);
  object_free(&env);
  env = restore();
  save(argl);
  object_free(&proc);
  proc = lookup_var_val(c_str_to_datum("|c-string->list|"));
  object_free(&val);
  val = lookup_var_val(c_str_to_datum("|target|"));
  argl = cons(object_copy(val), empty);
  if (proc.type == PROC_APPLY) {
    proc = apply_proc();
    argl = apply_argl();
  }
  if (proc.type == PROC) {
    goto primitive_branch42;
  }
  cont.cont = &&after_call41;
  object_free(&val);
  val = compiled_procedure_entry(proc);
  goto *val.cont;
primitive_branch42:;
  object_free(&val);
  val = proc.proc(argl);
after_call41:;
  object_free(&argl);
  argl = restore();
  argl = cons(object_copy(val), argl);
  object_free(&proc);
  proc = restore();
  if (proc.type == PROC_APPLY) {
    proc = apply_proc();
    argl = apply_argl();
  }
  if (proc.type == PROC) {
    goto primitive_branch44;
  }
  cont.cont = &&after_call43;
  object_free(&val);
  val = compiled_procedure_entry(proc);
  goto *val.cont;
primitive_branch44:;
  object_free(&val);
  val = proc.proc(argl);
after_call43:;
  argl = cons(object_copy(val), empty);
  object_free(&proc);
  proc = restore();
  if (proc.type == PROC_APPLY) {
    proc = apply_proc();
    argl = apply_argl();
  }
  if (proc.type == PROC) {
    goto primitive_branch46;
  }
  cont.cont = &&after_call45;
  object_free(&val);
  val = compiled_procedure_entry(proc);
  goto *val.cont;
primitive_branch46:;
  object_free(&val);
  val = proc.proc(argl);
after_call45:;
  object_free(&env);
  env = restore();
  {
    Object t = def_var_val(c_str_to_datum("|input-filename|"));
    object_free(&val);
    val = t;
  }
  save(env);
  object_free(&proc);
  proc = lookup_var_val(c_str_to_datum("|c-list->string|"));
  save(proc);
  object_free(&proc);
  proc = lookup_var_val(c_str_to_datum("|c-append|"));
  save(proc);
  save(env);
  object_free(&proc);
  proc = lookup_var_val(c_str_to_datum("|c-string->list|"));
  object_free(&val);
  val = c_str_to_datum("\".c\"");
  argl = cons(object_copy(val), empty);
  if (proc.type == PROC_APPLY) {
    proc = apply_proc();
    argl = apply_argl();
  }
  if (proc.type == PROC) {
    goto primitive_branch32;
  }
  cont.cont = &&after_call31;
  object_free(&val);
  val = compiled_procedure_entry(proc);
  goto *val.cont;
primitive_branch32:;
  object_free(&val);
  val = proc.proc(argl);
after_call31:;
  argl = cons(object_copy(val), empty);
  object_free(&env);
  env = restore();
  save(argl);
  object_free(&proc);
  proc = lookup_var_val(c_str_to_datum("|c-string->list|"));
  object_free(&val);
  val = lookup_var_val(c_str_to_datum("|target|"));
  argl = cons(object_copy(val), empty);
  if (proc.type == PROC_APPLY) {
    proc = apply_proc();
    argl = apply_argl();
  }
  if (proc.type == PROC) {
    goto primitive_branch34;
  }
  cont.cont = &&after_call33;
  object_free(&val);
  val = compiled_procedure_entry(proc);
  goto *val.cont;
primitive_branch34:;
  object_free(&val);
  val = proc.proc(argl);
after_call33:;
  object_free(&argl);
  argl = restore();
  argl = cons(object_copy(val), argl);
  object_free(&proc);
  proc = restore();
  if (proc.type == PROC_APPLY) {
    proc = apply_proc();
    argl = apply_argl();
  }
  if (proc.type == PROC) {
    goto primitive_branch36;
  }
  cont.cont = &&after_call35;
  object_free(&val);
  val = compiled_procedure_entry(proc);
  goto *val.cont;
primitive_branch36:;
  object_free(&val);
  val = proc.proc(argl);
after_call35:;
  argl = cons(object_copy(val), empty);
  object_free(&proc);
  proc = restore();
  if (proc.type == PROC_APPLY) {
    proc = apply_proc();
    argl = apply_argl();
  }
  if (proc.type == PROC) {
    goto primitive_branch38;
  }
  cont.cont = &&after_call37;
  object_free(&val);
  val = compiled_procedure_entry(proc);
  goto *val.cont;
primitive_branch38:;
  object_free(&val);
  val = proc.proc(argl);
after_call37:;
  object_free(&env);
  env = restore();
  {
    Object t = def_var_val(c_str_to_datum("|output-filename|"));
    object_free(&val);
    val = t;
  }
  save(env);
  object_free(&proc);
  proc = lookup_var_val(c_str_to_datum("|open-input-file|"));
  object_free(&val);
  val = lookup_var_val(c_str_to_datum("|input-filename|"));
  argl = cons(object_copy(val), empty);
  if (proc.type == PROC_APPLY) {
    proc = apply_proc();
    argl = apply_argl();
  }
  if (proc.type == PROC) {
    goto primitive_branch30;
  }
  cont.cont = &&after_call29;
  object_free(&val);
  val = compiled_procedure_entry(proc);
  goto *val.cont;
primitive_branch30:;
  object_free(&val);
  val = proc.proc(argl);
after_call29:;
  object_free(&env);
  env = restore();
  {
    Object t = def_var_val(c_str_to_datum("|input-file|"));
    object_free(&val);
    val = t;
  }
  save(env);
  object_free(&proc);
  proc = lookup_var_val(c_str_to_datum("|open-output-file|"));
  object_free(&val);
  val = lookup_var_val(c_str_to_datum("|output-filename|"));
  argl = cons(object_copy(val), empty);
  if (proc.type == PROC_APPLY) {
    proc = apply_proc();
    argl = apply_argl();
  }
  if (proc.type == PROC) {
    goto primitive_branch28;
  }
  cont.cont = &&after_call27;
  object_free(&val);
  val = compiled_procedure_entry(proc);
  goto *val.cont;
primitive_branch28:;
  object_free(&val);
  val = proc.proc(argl);
after_call27:;
  object_free(&env);
  env = restore();
  {
    Object t = def_var_val(c_str_to_datum("|output-file|"));
    object_free(&val);
    val = t;
  }
  save(env);
  object_free(&proc);
  proc = lookup_var_val(c_str_to_datum("|read|"));
  object_free(&val);
  val = lookup_var_val(c_str_to_datum("|input-file|"));
  argl = cons(object_copy(val), empty);
  if (proc.type == PROC_APPLY) {
    proc = apply_proc();
    argl = apply_argl();
  }
  if (proc.type == PROC) {
    goto primitive_branch26;
  }
  cont.cont = &&after_call25;
  object_free(&val);
  val = compiled_procedure_entry(proc);
  goto *val.cont;
primitive_branch26:;
  object_free(&val);
  val = proc.proc(argl);
after_call25:;
  object_free(&env);
  env = restore();
  {
    Object t = def_var_val(c_str_to_datum("|data|"));
    object_free(&val);
    val = t;
  }
  save(env);
  object_free(&proc);
  proc = lookup_var_val(c_str_to_datum("|compile|"));
  object_free(&val);
  val = c_str_to_datum("|next|");
  argl = cons(object_copy(val), empty);
  object_free(&val);
  val = c_str_to_datum("|val|");
  argl = cons(object_copy(val), argl);
  object_free(&val);
  val = lookup_var_val(c_str_to_datum("|data|"));
  argl = cons(object_copy(val), argl);
  if (proc.type == PROC_APPLY) {
    proc = apply_proc();
    argl = apply_argl();
  }
  if (proc.type == PROC) {
    goto primitive_branch24;
  }
  cont.cont = &&after_call23;
  object_free(&val);
  val = compiled_procedure_entry(proc);
  goto *val.cont;
primitive_branch24:;
  object_free(&val);
  val = proc.proc(argl);
after_call23:;
  object_free(&env);
  env = restore();
  {
    Object t = def_var_val(c_str_to_datum("|code|"));
    object_free(&val);
    val = t;
  }
  save(env);
  object_free(&proc);
  proc = lookup_var_val(c_str_to_datum("|print-code|"));
  object_free(&val);
  val = lookup_var_val(c_str_to_datum("|output-file|"));
  argl = cons(object_copy(val), empty);
  object_free(&val);
  val = lookup_var_val(c_str_to_datum("|code|"));
  argl = cons(object_copy(val), argl);
  if (proc.type == PROC_APPLY) {
    proc = apply_proc();
    argl = apply_argl();
  }
  if (proc.type == PROC) {
    goto primitive_branch22;
  }
  cont.cont = &&after_call21;
  object_free(&val);
  val = compiled_procedure_entry(proc);
  goto *val.cont;
primitive_branch22:;
  object_free(&val);
  val = proc.proc(argl);
after_call21:;
  object_free(&env);
  env = restore();
  save(env);
  object_free(&proc);
  proc = lookup_var_val(c_str_to_datum("|c-list->string|"));
  save(proc);
  object_free(&proc);
  proc = lookup_var_val(c_str_to_datum("|c-append|"));
  save(proc);
  save(env);
  object_free(&proc);
  proc = lookup_var_val(c_str_to_datum("|c-string->list|"));
  object_free(&val);
  val = lookup_var_val(c_str_to_datum("|target|"));
  argl = cons(object_copy(val), empty);
  if (proc.type == PROC_APPLY) {
    proc = apply_proc();
    argl = apply_argl();
  }
  if (proc.type == PROC) {
    goto primitive_branch10;
  }
  cont.cont = &&after_call9;
  object_free(&val);
  val = compiled_procedure_entry(proc);
  goto *val.cont;
primitive_branch10:;
  object_free(&val);
  val = proc.proc(argl);
after_call9:;
  argl = cons(object_copy(val), empty);
  object_free(&env);
  env = restore();
  save(env);
  save(argl);
  object_free(&proc);
  proc = lookup_var_val(c_str_to_datum("|c-string->list|"));
  object_free(&val);
  val = c_str_to_datum("\" -o \"");
  argl = cons(object_copy(val), empty);
  if (proc.type == PROC_APPLY) {
    proc = apply_proc();
    argl = apply_argl();
  }
  if (proc.type == PROC) {
    goto primitive_branch12;
  }
  cont.cont = &&after_call11;
  object_free(&val);
  val = compiled_procedure_entry(proc);
  goto *val.cont;
primitive_branch12:;
  object_free(&val);
  val = proc.proc(argl);
after_call11:;
  object_free(&argl);
  argl = restore();
  argl = cons(object_copy(val), argl);
  object_free(&env);
  env = restore();
  save(env);
  save(argl);
  object_free(&proc);
  proc = lookup_var_val(c_str_to_datum("|c-string->list|"));
  object_free(&val);
  val = lookup_var_val(c_str_to_datum("|output-filename|"));
  argl = cons(object_copy(val), empty);
  if (proc.type == PROC_APPLY) {
    proc = apply_proc();
    argl = apply_argl();
  }
  if (proc.type == PROC) {
    goto primitive_branch14;
  }
  cont.cont = &&after_call13;
  object_free(&val);
  val = compiled_procedure_entry(proc);
  goto *val.cont;
primitive_branch14:;
  object_free(&val);
  val = proc.proc(argl);
after_call13:;
  object_free(&argl);
  argl = restore();
  argl = cons(object_copy(val), argl);
  object_free(&env);
  env = restore();
  save(argl);
  object_free(&proc);
  proc = lookup_var_val(c_str_to_datum("|c-string->list|"));
  object_free(&val);
  val =
      c_str_to_datum("\"cc -g -Wall -Werror -O3 `pkg-config --cflags glib-2.0` "
                     "-I./ `pkg-config --libs glib-2.0` -L/opt/local/lib -lgmp "
                     "-lmpfr -lmpc -lfl -L./ -lkscm \"");
  argl = cons(object_copy(val), empty);
  if (proc.type == PROC_APPLY) {
    proc = apply_proc();
    argl = apply_argl();
  }
  if (proc.type == PROC) {
    goto primitive_branch16;
  }
  cont.cont = &&after_call15;
  object_free(&val);
  val = compiled_procedure_entry(proc);
  goto *val.cont;
primitive_branch16:;
  object_free(&val);
  val = proc.proc(argl);
after_call15:;
  object_free(&argl);
  argl = restore();
  argl = cons(object_copy(val), argl);
  object_free(&proc);
  proc = restore();
  if (proc.type == PROC_APPLY) {
    proc = apply_proc();
    argl = apply_argl();
  }
  if (proc.type == PROC) {
    goto primitive_branch18;
  }
  cont.cont = &&after_call17;
  object_free(&val);
  val = compiled_procedure_entry(proc);
  goto *val.cont;
primitive_branch18:;
  object_free(&val);
  val = proc.proc(argl);
after_call17:;
  argl = cons(object_copy(val), empty);
  object_free(&proc);
  proc = restore();
  if (proc.type == PROC_APPLY) {
    proc = apply_proc();
    argl = apply_argl();
  }
  if (proc.type == PROC) {
    goto primitive_branch20;
  }
  cont.cont = &&after_call19;
  object_free(&val);
  val = compiled_procedure_entry(proc);
  goto *val.cont;
primitive_branch20:;
  object_free(&val);
  val = proc.proc(argl);
after_call19:;
  object_free(&env);
  env = restore();
  {
    Object t = def_var_val(c_str_to_datum("|command|"));
    object_free(&val);
    val = t;
  }
  save(env);
  object_free(&proc);
  proc = lookup_var_val(c_str_to_datum("|flush-output-port|"));
  object_free(&val);
  val = lookup_var_val(c_str_to_datum("|output-file|"));
  argl = cons(object_copy(val), empty);
  if (proc.type == PROC_APPLY) {
    proc = apply_proc();
    argl = apply_argl();
  }
  if (proc.type == PROC) {
    goto primitive_branch8;
  }
  cont.cont = &&after_call7;
  object_free(&val);
  val = compiled_procedure_entry(proc);
  goto *val.cont;
primitive_branch8:;
  object_free(&val);
  val = proc.proc(argl);
after_call7:;
  object_free(&env);
  env = restore();
  object_free(&proc);
  proc = lookup_var_val(c_str_to_datum("|run-shell-command|"));
  object_free(&val);
  val = lookup_var_val(c_str_to_datum("|command|"));
  argl = cons(object_copy(val), empty);
  if (proc.type == PROC_APPLY) {
    proc = apply_proc();
    argl = apply_argl();
  }
  if (proc.type == PROC) {
    goto primitive_branch6;
  }
  cont.cont = &&after_call5;
  object_free(&val);
  val = compiled_procedure_entry(proc);
  goto *val.cont;
primitive_branch6:;
  object_free(&val);
  val = proc.proc(argl);
after_call5:;
  object_free(&val);
  val = c_str_to_datum("|compiled|");
  goto after_if1;
false_branch2:;
  object_free(&proc);
  proc = lookup_var_val(c_str_to_datum("|error|"));
  object_free(&val);
  val = c_str_to_datum("\"usage: ksc <output>\"");
  argl = cons(object_copy(val), empty);
  if (proc.type == PROC_APPLY) {
    proc = apply_proc();
    argl = apply_argl();
  }
  if (proc.type == PROC) {
    goto primitive_branch4;
  }
  cont.cont = &&after_call3;
  object_free(&val);
  val = compiled_procedure_entry(proc);
  goto *val.cont;
primitive_branch4:;
  object_free(&val);
  val = proc.proc(argl);
after_call3:;
after_if1:;
  printf("=> ");
  object_write_stdout(val);
  puts("");
}