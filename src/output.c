/** \file */
#include <kscm.h>
int main (int argc,char *argv[]){init();get_command_line(argc, argv);object_free(&val);val = make_compiled_procedure(&&entry886);goto after_lambda885;entry886:env = compiled_procedure_env();
                          env = extend_environment(c_str_to_datum("(|port| . ())"));object_free(&proc);proc = lookup_var_val(c_str_to_datum("|display|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|port|"));argl = cons(object_copy(val),empty);object_free(&val);val = c_str_to_datum("#\\newline");argl = cons(object_copy(val), argl);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch888;}object_free(&val);
                    val = compiled_procedure_entry(proc);
                    goto *val.cont;primitive_branch888:;object_free(&val);val = proc.proc(argl); goto *cont.cont;after_lambda885:;{Object t = def_var_val(c_str_to_datum("|newline|"));
                                   object_free(&val);val = t;}object_free(&val);val = make_compiled_procedure(&&entry870);goto after_lambda869;entry870:env = compiled_procedure_env();
                          env = extend_environment(c_str_to_datum("(|list| . (|port| . ()))"));save(cont);save(env);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|not|"));save(proc);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|null?|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|list|"));argl = cons(object_copy(val),empty);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch882;}cont.cont = &&after_call881;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch882:;object_free(&val);val = proc.proc(argl); after_call881:;argl = cons(object_copy(val),empty);object_free(&proc);proc =restore();if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch884;}cont.cont = &&after_call883;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch884:;object_free(&val);val = proc.proc(argl); after_call883:;object_free(&env);env =restore();object_free(&cont);cont =restore();if(val.type==BOOLEAN && !val.boolean){
                        goto false_branch872;}save(cont);save(env);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|display|"));save(proc);object_free(&val);val = lookup_var_val(c_str_to_datum("|port|"));argl = cons(object_copy(val),empty);save(argl);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|car|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|list|"));argl = cons(object_copy(val),empty);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch878;}cont.cont = &&after_call877;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch878:;object_free(&val);val = proc.proc(argl); after_call877:;object_free(&argl);argl =restore();argl = cons(object_copy(val), argl);object_free(&proc);proc =restore();if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch880;}cont.cont = &&after_call879;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch880:;object_free(&val);val = proc.proc(argl); after_call879:;object_free(&env);env =restore();object_free(&cont);cont =restore();object_free(&proc);proc = lookup_var_val(c_str_to_datum("|print-elements|"));save(cont);save(proc);object_free(&val);val = lookup_var_val(c_str_to_datum("|port|"));argl = cons(object_copy(val),empty);save(argl);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|cdr|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|list|"));argl = cons(object_copy(val),empty);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch874;}cont.cont = &&after_call873;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch874:;object_free(&val);val = proc.proc(argl); after_call873:;object_free(&argl);argl =restore();argl = cons(object_copy(val), argl);object_free(&proc);proc =restore();object_free(&cont);cont =restore();if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch876;}object_free(&val);
                    val = compiled_procedure_entry(proc);
                    goto *val.cont;primitive_branch876:;object_free(&val);val = proc.proc(argl); goto *cont.cont;false_branch872:;object_free(&val);val = undef;goto *cont.cont;after_lambda869:;{Object t = def_var_val(c_str_to_datum("|print-elements|"));
                                   object_free(&val);val = t;}object_free(&val);val = make_compiled_procedure(&&entry852);goto after_lambda851;entry852:env = compiled_procedure_env();
                          env = extend_environment(c_str_to_datum("(|code| . (|port| . ()))"));save(cont);save(env);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|display|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|port|"));argl = cons(object_copy(val),empty);object_free(&val);val = c_str_to_datum("|/** \\x5c;file */|");argl = cons(object_copy(val), argl);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch868;}cont.cont = &&after_call867;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch868:;object_free(&val);val = proc.proc(argl); after_call867:;object_free(&env);env =restore();object_free(&cont);cont =restore();save(cont);save(env);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|newline|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|port|"));argl = cons(object_copy(val),empty);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch866;}cont.cont = &&after_call865;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch866:;object_free(&val);val = proc.proc(argl); after_call865:;object_free(&env);env =restore();object_free(&cont);cont =restore();save(cont);save(env);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|display|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|port|"));argl = cons(object_copy(val),empty);object_free(&val);val = c_str_to_datum("|#include <kscm.h>|");argl = cons(object_copy(val), argl);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch864;}cont.cont = &&after_call863;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch864:;object_free(&val);val = proc.proc(argl); after_call863:;object_free(&env);env =restore();object_free(&cont);cont =restore();save(cont);save(env);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|newline|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|port|"));argl = cons(object_copy(val),empty);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch862;}cont.cont = &&after_call861;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch862:;object_free(&val);val = proc.proc(argl); after_call861:;object_free(&env);env =restore();object_free(&cont);cont =restore();save(cont);save(env);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|display|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|port|"));argl = cons(object_copy(val),empty);object_free(&val);val = c_str_to_datum("|int main (int argc,char *argv[]){init();get_command_line(argc, argv);|");argl = cons(object_copy(val), argl);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch860;}cont.cont = &&after_call859;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch860:;object_free(&val);val = proc.proc(argl); after_call859:;object_free(&env);env =restore();object_free(&cont);cont =restore();save(cont);save(env);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|print-elements|"));save(proc);object_free(&val);val = lookup_var_val(c_str_to_datum("|port|"));argl = cons(object_copy(val),empty);save(argl);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|c-caddr|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|code|"));argl = cons(object_copy(val),empty);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch856;}cont.cont = &&after_call855;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch856:;object_free(&val);val = proc.proc(argl); after_call855:;object_free(&argl);argl =restore();argl = cons(object_copy(val), argl);object_free(&proc);proc =restore();if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch858;}cont.cont = &&after_call857;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch858:;object_free(&val);val = proc.proc(argl); after_call857:;object_free(&env);env =restore();object_free(&cont);cont =restore();object_free(&proc);proc = lookup_var_val(c_str_to_datum("|display|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|port|"));argl = cons(object_copy(val),empty);object_free(&val);val = c_str_to_datum("|printf(\\x22;=> \\x22;);object_write_stdout(val);puts(\\x22;\\x22;);}|");argl = cons(object_copy(val), argl);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch854;}object_free(&val);
                    val = compiled_procedure_entry(proc);
                    goto *val.cont;primitive_branch854:;object_free(&val);val = proc.proc(argl); goto *cont.cont;after_lambda851:;{Object t = def_var_val(c_str_to_datum("|print-code|"));
                                   object_free(&val);val = t;}object_free(&val);val = c_str_to_datum("#false");if(val.type==BOOLEAN && !val.boolean){
                        goto false_branch850;}object_free(&val);val = c_str_to_datum("0");goto after_if849;false_branch850:;object_free(&val);val = undef;after_if849:;{Object t = def_var_val(c_str_to_datum("|undef|"));
                                   object_free(&val);val = t;}object_free(&val);val = make_compiled_procedure(&&entry838);goto after_lambda837;entry838:env = compiled_procedure_env();
                          env = extend_environment(c_str_to_datum("(|obj| . ())"));object_free(&proc);proc = lookup_var_val(c_str_to_datum("|c-append|"));save(cont);save(proc);object_free(&val);val = c_str_to_datum("(|)| . ())");argl = cons(object_copy(val),empty);save(env);save(argl);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|obj->c|"));save(proc);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|cdr|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|obj|"));argl = cons(object_copy(val),empty);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch840;}cont.cont = &&after_call839;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch840:;object_free(&val);val = proc.proc(argl); after_call839:;argl = cons(object_copy(val),empty);object_free(&proc);proc =restore();if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch842;}cont.cont = &&after_call841;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch842:;object_free(&val);val = proc.proc(argl); after_call841:;object_free(&argl);argl =restore();argl = cons(object_copy(val), argl);object_free(&env);env =restore();object_free(&val);val = c_str_to_datum("(| . | . ())");argl = cons(object_copy(val), argl);save(argl);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|obj->c|"));save(proc);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|car|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|obj|"));argl = cons(object_copy(val),empty);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch844;}cont.cont = &&after_call843;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch844:;object_free(&val);val = proc.proc(argl); after_call843:;argl = cons(object_copy(val),empty);object_free(&proc);proc =restore();if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch846;}cont.cont = &&after_call845;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch846:;object_free(&val);val = proc.proc(argl); after_call845:;object_free(&argl);argl =restore();argl = cons(object_copy(val), argl);object_free(&val);val = c_str_to_datum("(|(| . ())");argl = cons(object_copy(val), argl);object_free(&proc);proc =restore();object_free(&cont);cont =restore();if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch848;}object_free(&val);
                    val = compiled_procedure_entry(proc);
                    goto *val.cont;primitive_branch848:;object_free(&val);val = proc.proc(argl); goto *cont.cont;after_lambda837:;{Object t = def_var_val(c_str_to_datum("|pair->c|"));
                                   object_free(&val);val = t;}object_free(&val);val = make_compiled_procedure(&&entry796);goto after_lambda795;entry796:env = compiled_procedure_env();
                          env = extend_environment(c_str_to_datum("(|obj| . ())"));save(cont);save(env);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|number?|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|obj|"));argl = cons(object_copy(val),empty);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch836;}cont.cont = &&after_call835;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch836:;object_free(&val);val = proc.proc(argl); after_call835:;object_free(&env);env =restore();object_free(&cont);cont =restore();if(val.type==BOOLEAN && !val.boolean){
                        goto false_branch798;}object_free(&proc);proc = lookup_var_val(c_str_to_datum("|list|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|obj|"));argl = cons(object_copy(val),empty);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch834;}object_free(&val);
                    val = compiled_procedure_entry(proc);
                    goto *val.cont;primitive_branch834:;object_free(&val);val = proc.proc(argl); goto *cont.cont;false_branch798:;save(cont);save(env);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|string?|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|obj|"));argl = cons(object_copy(val),empty);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch832;}cont.cont = &&after_call831;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch832:;object_free(&val);val = proc.proc(argl); after_call831:;object_free(&env);env =restore();object_free(&cont);cont =restore();if(val.type==BOOLEAN && !val.boolean){
                        goto false_branch800;}object_free(&proc);proc = lookup_var_val(c_str_to_datum("|c-string->c|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|obj|"));argl = cons(object_copy(val),empty);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch830;}object_free(&val);
                    val = compiled_procedure_entry(proc);
                    goto *val.cont;primitive_branch830:;object_free(&val);val = proc.proc(argl); goto *cont.cont;false_branch800:;save(cont);save(env);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|symbol?|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|obj|"));argl = cons(object_copy(val),empty);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch828;}cont.cont = &&after_call827;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch828:;object_free(&val);val = proc.proc(argl); after_call827:;object_free(&env);env =restore();object_free(&cont);cont =restore();if(val.type==BOOLEAN && !val.boolean){
                        goto false_branch802;}object_free(&proc);proc = lookup_var_val(c_str_to_datum("|c-symbol->c|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|obj|"));argl = cons(object_copy(val),empty);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch826;}object_free(&val);
                    val = compiled_procedure_entry(proc);
                    goto *val.cont;primitive_branch826:;object_free(&val);val = proc.proc(argl); goto *cont.cont;false_branch802:;save(cont);save(env);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|pair?|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|obj|"));argl = cons(object_copy(val),empty);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch824;}cont.cont = &&after_call823;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch824:;object_free(&val);val = proc.proc(argl); after_call823:;object_free(&env);env =restore();object_free(&cont);cont =restore();if(val.type==BOOLEAN && !val.boolean){
                        goto false_branch804;}object_free(&proc);proc = lookup_var_val(c_str_to_datum("|pair->c|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|obj|"));argl = cons(object_copy(val),empty);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch822;}object_free(&val);
                    val = compiled_procedure_entry(proc);
                    goto *val.cont;primitive_branch822:;object_free(&val);val = proc.proc(argl); goto *cont.cont;false_branch804:;save(cont);save(env);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|null?|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|obj|"));argl = cons(object_copy(val),empty);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch820;}cont.cont = &&after_call819;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch820:;object_free(&val);val = proc.proc(argl); after_call819:;object_free(&env);env =restore();object_free(&cont);cont =restore();if(val.type==BOOLEAN && !val.boolean){
                        goto false_branch806;}object_free(&val);val = c_str_to_datum("(|()| . ())");goto *cont.cont;false_branch806:;save(cont);save(env);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|boolean?|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|obj|"));argl = cons(object_copy(val),empty);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch818;}cont.cont = &&after_call817;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch818:;object_free(&val);val = proc.proc(argl); after_call817:;object_free(&env);env =restore();object_free(&cont);cont =restore();if(val.type==BOOLEAN && !val.boolean){
                        goto false_branch808;}object_free(&proc);proc = lookup_var_val(c_str_to_datum("|list|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|obj|"));argl = cons(object_copy(val),empty);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch816;}object_free(&val);
                    val = compiled_procedure_entry(proc);
                    goto *val.cont;primitive_branch816:;object_free(&val);val = proc.proc(argl); goto *cont.cont;false_branch808:;save(cont);save(env);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|char?|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|obj|"));argl = cons(object_copy(val),empty);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch814;}cont.cont = &&after_call813;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch814:;object_free(&val);val = proc.proc(argl); after_call813:;object_free(&env);env =restore();object_free(&cont);cont =restore();if(val.type==BOOLEAN && !val.boolean){
                        goto false_branch810;}object_free(&proc);proc = lookup_var_val(c_str_to_datum("|c-char->c|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|obj|"));argl = cons(object_copy(val),empty);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch812;}object_free(&val);
                    val = compiled_procedure_entry(proc);
                    goto *val.cont;primitive_branch812:;object_free(&val);val = proc.proc(argl); goto *cont.cont;false_branch810:;object_free(&val);val = undef;goto *cont.cont;after_lambda795:;{Object t = def_var_val(c_str_to_datum("|obj->c|"));
                                   object_free(&val);val = t;}object_free(&val);val = make_compiled_procedure(&&entry782);goto after_lambda781;entry782:env = compiled_procedure_env();
                          env = extend_environment(c_str_to_datum("(|obj| . ())"));save(cont);save(env);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|eq?|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|undef|"));argl = cons(object_copy(val),empty);object_free(&val);val = lookup_var_val(c_str_to_datum("|obj|"));argl = cons(object_copy(val), argl);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch794;}cont.cont = &&after_call793;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch794:;object_free(&val);val = proc.proc(argl); after_call793:;object_free(&env);env =restore();object_free(&cont);cont =restore();if(val.type==BOOLEAN && !val.boolean){
                        goto false_branch784;}object_free(&val);val = c_str_to_datum("(|undef| . ())");goto *cont.cont;false_branch784:;save(cont);save(env);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|eof-object?|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|obj|"));argl = cons(object_copy(val),empty);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch792;}cont.cont = &&after_call791;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch792:;object_free(&val);val = proc.proc(argl); after_call791:;object_free(&env);env =restore();object_free(&cont);cont =restore();if(val.type==BOOLEAN && !val.boolean){
                        goto false_branch786;}object_free(&val);val = c_str_to_datum("(|eof_obj| . ())");goto *cont.cont;false_branch786:;object_free(&proc);proc = lookup_var_val(c_str_to_datum("|c-append|"));save(cont);save(proc);object_free(&val);val = c_str_to_datum("(|\\x22;)| . ())");argl = cons(object_copy(val),empty);save(argl);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|obj->c|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|obj|"));argl = cons(object_copy(val),empty);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch788;}cont.cont = &&after_call787;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch788:;object_free(&val);val = proc.proc(argl); after_call787:;object_free(&argl);argl =restore();argl = cons(object_copy(val), argl);object_free(&val);val = c_str_to_datum("(|c_str_to_datum(\\x22;| . ())");argl = cons(object_copy(val), argl);object_free(&proc);proc =restore();object_free(&cont);cont =restore();if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch790;}object_free(&val);
                    val = compiled_procedure_entry(proc);
                    goto *val.cont;primitive_branch790:;object_free(&val);val = proc.proc(argl); goto *cont.cont;after_lambda781:;{Object t = def_var_val(c_str_to_datum("|const|"));
                                   object_free(&val);val = t;}object_free(&val);val = make_compiled_procedure(&&entry766);goto after_lambda765;entry766:env = compiled_procedure_env();
                          env = extend_environment(c_str_to_datum("(|exp| . ())"));save(cont);save(env);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|symbol?|"));save(proc);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|c-cadr|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|exp|"));argl = cons(object_copy(val),empty);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch778;}cont.cont = &&after_call777;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch778:;object_free(&val);val = proc.proc(argl); after_call777:;argl = cons(object_copy(val),empty);object_free(&proc);proc =restore();if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch780;}cont.cont = &&after_call779;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch780:;object_free(&val);val = proc.proc(argl); after_call779:;object_free(&env);env =restore();object_free(&cont);cont =restore();if(val.type==BOOLEAN && !val.boolean){
                        goto false_branch768;}object_free(&proc);proc = lookup_var_val(c_str_to_datum("|c-caddr|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|exp|"));argl = cons(object_copy(val),empty);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch776;}object_free(&val);
                    val = compiled_procedure_entry(proc);
                    goto *val.cont;primitive_branch776:;object_free(&val);val = proc.proc(argl); goto *cont.cont;false_branch768:;object_free(&proc);proc = lookup_var_val(c_str_to_datum("|c-make-lambda|"));save(cont);save(proc);save(env);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|c-cddr|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|exp|"));argl = cons(object_copy(val),empty);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch770;}cont.cont = &&after_call769;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch770:;object_free(&val);val = proc.proc(argl); after_call769:;argl = cons(object_copy(val),empty);object_free(&env);env =restore();save(argl);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|c-cdadr|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|exp|"));argl = cons(object_copy(val),empty);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch772;}cont.cont = &&after_call771;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch772:;object_free(&val);val = proc.proc(argl); after_call771:;object_free(&argl);argl =restore();argl = cons(object_copy(val), argl);object_free(&proc);proc =restore();object_free(&cont);cont =restore();if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch774;}object_free(&val);
                    val = compiled_procedure_entry(proc);
                    goto *val.cont;primitive_branch774:;object_free(&val);val = proc.proc(argl); goto *cont.cont;after_lambda765:;{Object t = def_var_val(c_str_to_datum("|definition-value|"));
                                   object_free(&val);val = t;}object_free(&val);val = make_compiled_procedure(&&entry740);goto after_lambda739;entry740:env = compiled_procedure_env();
                          env = extend_environment(c_str_to_datum("(|exp| . ())"));save(cont);save(env);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|null?|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|exp|"));argl = cons(object_copy(val),empty);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch764;}cont.cont = &&after_call763;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch764:;object_free(&val);val = proc.proc(argl); after_call763:;object_free(&env);env =restore();object_free(&cont);cont =restore();if(val.type==BOOLEAN && !val.boolean){
                        goto false_branch742;}object_free(&val);val = c_str_to_datum("#true");goto *cont.cont;false_branch742:;object_free(&val);val = make_compiled_procedure(&&entry746);goto after_lambda745;entry746:env = compiled_procedure_env();
                          env = extend_environment(c_str_to_datum("(|o| . ())"));save(cont);save(env);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|null?|"));save(proc);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|cdr|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|o|"));argl = cons(object_copy(val),empty);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch760;}cont.cont = &&after_call759;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch760:;object_free(&val);val = proc.proc(argl); after_call759:;argl = cons(object_copy(val),empty);object_free(&proc);proc =restore();if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch762;}cont.cont = &&after_call761;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch762:;object_free(&val);val = proc.proc(argl); after_call761:;object_free(&env);env =restore();object_free(&cont);cont =restore();if(val.type==BOOLEAN && !val.boolean){
                        goto false_branch748;}object_free(&proc);proc = lookup_var_val(c_str_to_datum("|car|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|o|"));argl = cons(object_copy(val),empty);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch758;}object_free(&val);
                    val = compiled_procedure_entry(proc);
                    goto *val.cont;primitive_branch758:;object_free(&val);val = proc.proc(argl); goto *cont.cont;false_branch748:;object_free(&proc);proc = lookup_var_val(c_str_to_datum("|list|"));save(cont);save(proc);object_free(&val);val = c_str_to_datum("#false");argl = cons(object_copy(val),empty);save(env);save(argl);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|iter|"));save(proc);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|cdr|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|o|"));argl = cons(object_copy(val),empty);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch750;}cont.cont = &&after_call749;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch750:;object_free(&val);val = proc.proc(argl); after_call749:;argl = cons(object_copy(val),empty);object_free(&proc);proc =restore();if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch752;}cont.cont = &&after_call751;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch752:;object_free(&val);val = proc.proc(argl); after_call751:;object_free(&argl);argl =restore();argl = cons(object_copy(val), argl);object_free(&env);env =restore();save(argl);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|car|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|o|"));argl = cons(object_copy(val),empty);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch754;}cont.cont = &&after_call753;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch754:;object_free(&val);val = proc.proc(argl); after_call753:;object_free(&argl);argl =restore();argl = cons(object_copy(val), argl);object_free(&val);val = c_str_to_datum("|if|");argl = cons(object_copy(val), argl);object_free(&proc);proc =restore();object_free(&cont);cont =restore();if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch756;}object_free(&val);
                    val = compiled_procedure_entry(proc);
                    goto *val.cont;primitive_branch756:;object_free(&val);val = proc.proc(argl); goto *cont.cont;after_lambda745:;{Object t = def_var_val(c_str_to_datum("|iter|"));
                                   object_free(&val);val = t;}object_free(&proc);proc = lookup_var_val(c_str_to_datum("|iter|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|exp|"));argl = cons(object_copy(val),empty);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch744;}object_free(&val);
                    val = compiled_procedure_entry(proc);
                    goto *val.cont;primitive_branch744:;object_free(&val);val = proc.proc(argl); goto *cont.cont;after_lambda739:;{Object t = def_var_val(c_str_to_datum("|and->if|"));
                                   object_free(&val);val = t;}object_free(&val);val = make_compiled_procedure(&&entry724);goto after_lambda723;entry724:env = compiled_procedure_env();
                          env = extend_environment(c_str_to_datum("(|exp| . ())"));save(cont);save(env);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|null?|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|exp|"));argl = cons(object_copy(val),empty);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch738;}cont.cont = &&after_call737;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch738:;object_free(&val);val = proc.proc(argl); after_call737:;object_free(&env);env =restore();object_free(&cont);cont =restore();if(val.type==BOOLEAN && !val.boolean){
                        goto false_branch726;}object_free(&val);val = c_str_to_datum("#false");goto *cont.cont;false_branch726:;object_free(&proc);proc = lookup_var_val(c_str_to_datum("|list|"));save(cont);save(proc);save(env);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|cons|"));save(proc);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|cdr|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|exp|"));argl = cons(object_copy(val),empty);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch728;}cont.cont = &&after_call727;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch728:;object_free(&val);val = proc.proc(argl); after_call727:;argl = cons(object_copy(val),empty);object_free(&val);val = c_str_to_datum("|or|");argl = cons(object_copy(val), argl);object_free(&proc);proc =restore();if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch730;}cont.cont = &&after_call729;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch730:;object_free(&val);val = proc.proc(argl); after_call729:;argl = cons(object_copy(val),empty);object_free(&env);env =restore();save(env);save(argl);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|car|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|exp|"));argl = cons(object_copy(val),empty);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch732;}cont.cont = &&after_call731;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch732:;object_free(&val);val = proc.proc(argl); after_call731:;object_free(&argl);argl =restore();argl = cons(object_copy(val), argl);object_free(&env);env =restore();save(argl);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|car|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|exp|"));argl = cons(object_copy(val),empty);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch734;}cont.cont = &&after_call733;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch734:;object_free(&val);val = proc.proc(argl); after_call733:;object_free(&argl);argl =restore();argl = cons(object_copy(val), argl);object_free(&val);val = c_str_to_datum("|if|");argl = cons(object_copy(val), argl);object_free(&proc);proc =restore();object_free(&cont);cont =restore();if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch736;}object_free(&val);
                    val = compiled_procedure_entry(proc);
                    goto *val.cont;primitive_branch736:;object_free(&val);val = proc.proc(argl); goto *cont.cont;after_lambda723:;{Object t = def_var_val(c_str_to_datum("|or->if|"));
                                   object_free(&val);val = t;}save(env);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|open-output-file|"));object_free(&val);val = c_str_to_datum("\"compiler.log\"");argl = cons(object_copy(val),empty);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch722;}cont.cont = &&after_call721;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch722:;object_free(&val);val = proc.proc(argl); after_call721:;object_free(&env);env =restore();{Object t = def_var_val(c_str_to_datum("|log-port|"));
                                   object_free(&val);val = t;}object_free(&val);val = make_compiled_procedure(&&entry626);goto after_lambda625;entry626:env = compiled_procedure_env();
                          env = extend_environment(c_str_to_datum("(|exp| . (|target| . (|linkage| . ())))"));save(cont);save(env);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|display|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|log-port|"));argl = cons(object_copy(val),empty);object_free(&val);val = lookup_var_val(c_str_to_datum("|exp|"));argl = cons(object_copy(val), argl);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch720;}cont.cont = &&after_call719;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch720:;object_free(&val);val = proc.proc(argl); after_call719:;object_free(&env);env =restore();object_free(&cont);cont =restore();save(cont);save(env);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|newline|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|log-port|"));argl = cons(object_copy(val),empty);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch718;}cont.cont = &&after_call717;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch718:;object_free(&val);val = proc.proc(argl); after_call717:;object_free(&env);env =restore();object_free(&cont);cont =restore();save(cont);save(env);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|c-self-evaluating?|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|exp|"));argl = cons(object_copy(val),empty);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch716;}cont.cont = &&after_call715;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch716:;object_free(&val);val = proc.proc(argl); after_call715:;object_free(&env);env =restore();object_free(&cont);cont =restore();if(val.type==BOOLEAN && !val.boolean){
                        goto false_branch628;}object_free(&proc);proc = lookup_var_val(c_str_to_datum("|compile-self-evaluating|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|linkage|"));argl = cons(object_copy(val),empty);object_free(&val);val = lookup_var_val(c_str_to_datum("|target|"));argl = cons(object_copy(val), argl);object_free(&val);val = lookup_var_val(c_str_to_datum("|exp|"));argl = cons(object_copy(val), argl);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch714;}object_free(&val);
                    val = compiled_procedure_entry(proc);
                    goto *val.cont;primitive_branch714:;object_free(&val);val = proc.proc(argl); goto *cont.cont;false_branch628:;save(cont);save(env);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|symbol?|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|exp|"));argl = cons(object_copy(val),empty);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch712;}cont.cont = &&after_call711;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch712:;object_free(&val);val = proc.proc(argl); after_call711:;object_free(&env);env =restore();object_free(&cont);cont =restore();if(val.type==BOOLEAN && !val.boolean){
                        goto false_branch630;}object_free(&proc);proc = lookup_var_val(c_str_to_datum("|compile-variable|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|linkage|"));argl = cons(object_copy(val),empty);object_free(&val);val = lookup_var_val(c_str_to_datum("|target|"));argl = cons(object_copy(val), argl);object_free(&val);val = lookup_var_val(c_str_to_datum("|exp|"));argl = cons(object_copy(val), argl);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch710;}object_free(&val);
                    val = compiled_procedure_entry(proc);
                    goto *val.cont;primitive_branch710:;object_free(&val);val = proc.proc(argl); goto *cont.cont;false_branch630:;save(cont);save(env);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|pair?|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|exp|"));argl = cons(object_copy(val),empty);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch708;}cont.cont = &&after_call707;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch708:;object_free(&val);val = proc.proc(argl); after_call707:;object_free(&env);env =restore();object_free(&cont);cont =restore();if(val.type==BOOLEAN && !val.boolean){
                        goto false_branch632;}object_free(&proc);proc = make_compiled_procedure(&&entry638);goto after_lambda637;entry638:env = compiled_procedure_env();
                          env = extend_environment(c_str_to_datum("(|o| . ())"));save(cont);save(env);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|symbol?|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|o|"));argl = cons(object_copy(val),empty);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch704;}cont.cont = &&after_call703;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch704:;object_free(&val);val = proc.proc(argl); after_call703:;object_free(&env);env =restore();object_free(&cont);cont =restore();if(val.type==BOOLEAN && !val.boolean){
                        goto false_branch640;}save(cont);save(env);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|eq?|"));object_free(&val);val = c_str_to_datum("|quote|");argl = cons(object_copy(val),empty);object_free(&val);val = lookup_var_val(c_str_to_datum("|o|"));argl = cons(object_copy(val), argl);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch702;}cont.cont = &&after_call701;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch702:;object_free(&val);val = proc.proc(argl); after_call701:;object_free(&env);env =restore();object_free(&cont);cont =restore();if(val.type==BOOLEAN && !val.boolean){
                        goto false_branch644;}object_free(&proc);proc = lookup_var_val(c_str_to_datum("|compile-quoted|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|linkage|"));argl = cons(object_copy(val),empty);object_free(&val);val = lookup_var_val(c_str_to_datum("|target|"));argl = cons(object_copy(val), argl);object_free(&val);val = lookup_var_val(c_str_to_datum("|exp|"));argl = cons(object_copy(val), argl);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch700;}object_free(&val);
                    val = compiled_procedure_entry(proc);
                    goto *val.cont;primitive_branch700:;object_free(&val);val = proc.proc(argl); goto *cont.cont;false_branch644:;save(cont);save(env);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|eq?|"));object_free(&val);val = c_str_to_datum("|lambda|");argl = cons(object_copy(val),empty);object_free(&val);val = lookup_var_val(c_str_to_datum("|o|"));argl = cons(object_copy(val), argl);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch698;}cont.cont = &&after_call697;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch698:;object_free(&val);val = proc.proc(argl); after_call697:;object_free(&env);env =restore();object_free(&cont);cont =restore();if(val.type==BOOLEAN && !val.boolean){
                        goto false_branch646;}object_free(&proc);proc = lookup_var_val(c_str_to_datum("|compile-lambda|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|linkage|"));argl = cons(object_copy(val),empty);object_free(&val);val = lookup_var_val(c_str_to_datum("|target|"));argl = cons(object_copy(val), argl);object_free(&val);val = lookup_var_val(c_str_to_datum("|exp|"));argl = cons(object_copy(val), argl);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch696;}object_free(&val);
                    val = compiled_procedure_entry(proc);
                    goto *val.cont;primitive_branch696:;object_free(&val);val = proc.proc(argl); goto *cont.cont;false_branch646:;save(cont);save(env);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|eq?|"));object_free(&val);val = c_str_to_datum("|set!|");argl = cons(object_copy(val),empty);object_free(&val);val = lookup_var_val(c_str_to_datum("|o|"));argl = cons(object_copy(val), argl);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch694;}cont.cont = &&after_call693;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch694:;object_free(&val);val = proc.proc(argl); after_call693:;object_free(&env);env =restore();object_free(&cont);cont =restore();if(val.type==BOOLEAN && !val.boolean){
                        goto false_branch648;}object_free(&proc);proc = lookup_var_val(c_str_to_datum("|compile-assignment|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|linkage|"));argl = cons(object_copy(val),empty);object_free(&val);val = lookup_var_val(c_str_to_datum("|target|"));argl = cons(object_copy(val), argl);object_free(&val);val = lookup_var_val(c_str_to_datum("|exp|"));argl = cons(object_copy(val), argl);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch692;}object_free(&val);
                    val = compiled_procedure_entry(proc);
                    goto *val.cont;primitive_branch692:;object_free(&val);val = proc.proc(argl); goto *cont.cont;false_branch648:;save(cont);save(env);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|eq?|"));object_free(&val);val = c_str_to_datum("|define|");argl = cons(object_copy(val),empty);object_free(&val);val = lookup_var_val(c_str_to_datum("|o|"));argl = cons(object_copy(val), argl);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch690;}cont.cont = &&after_call689;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch690:;object_free(&val);val = proc.proc(argl); after_call689:;object_free(&env);env =restore();object_free(&cont);cont =restore();if(val.type==BOOLEAN && !val.boolean){
                        goto false_branch650;}object_free(&proc);proc = lookup_var_val(c_str_to_datum("|compile-definition|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|linkage|"));argl = cons(object_copy(val),empty);object_free(&val);val = lookup_var_val(c_str_to_datum("|target|"));argl = cons(object_copy(val), argl);object_free(&val);val = lookup_var_val(c_str_to_datum("|exp|"));argl = cons(object_copy(val), argl);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch688;}object_free(&val);
                    val = compiled_procedure_entry(proc);
                    goto *val.cont;primitive_branch688:;object_free(&val);val = proc.proc(argl); goto *cont.cont;false_branch650:;save(cont);save(env);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|eq?|"));object_free(&val);val = c_str_to_datum("|if|");argl = cons(object_copy(val),empty);object_free(&val);val = lookup_var_val(c_str_to_datum("|o|"));argl = cons(object_copy(val), argl);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch686;}cont.cont = &&after_call685;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch686:;object_free(&val);val = proc.proc(argl); after_call685:;object_free(&env);env =restore();object_free(&cont);cont =restore();if(val.type==BOOLEAN && !val.boolean){
                        goto false_branch652;}object_free(&proc);proc = lookup_var_val(c_str_to_datum("|compile-if|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|linkage|"));argl = cons(object_copy(val),empty);object_free(&val);val = lookup_var_val(c_str_to_datum("|target|"));argl = cons(object_copy(val), argl);object_free(&val);val = lookup_var_val(c_str_to_datum("|exp|"));argl = cons(object_copy(val), argl);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch684;}object_free(&val);
                    val = compiled_procedure_entry(proc);
                    goto *val.cont;primitive_branch684:;object_free(&val);val = proc.proc(argl); goto *cont.cont;false_branch652:;save(cont);save(env);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|eq?|"));object_free(&val);val = c_str_to_datum("|begin|");argl = cons(object_copy(val),empty);object_free(&val);val = lookup_var_val(c_str_to_datum("|o|"));argl = cons(object_copy(val), argl);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch682;}cont.cont = &&after_call681;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch682:;object_free(&val);val = proc.proc(argl); after_call681:;object_free(&env);env =restore();object_free(&cont);cont =restore();if(val.type==BOOLEAN && !val.boolean){
                        goto false_branch654;}object_free(&proc);proc = lookup_var_val(c_str_to_datum("|compile-sequence|"));save(cont);save(proc);object_free(&val);val = lookup_var_val(c_str_to_datum("|linkage|"));argl = cons(object_copy(val),empty);object_free(&val);val = lookup_var_val(c_str_to_datum("|target|"));argl = cons(object_copy(val), argl);save(argl);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|cdr|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|exp|"));argl = cons(object_copy(val),empty);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch678;}cont.cont = &&after_call677;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch678:;object_free(&val);val = proc.proc(argl); after_call677:;object_free(&argl);argl =restore();argl = cons(object_copy(val), argl);object_free(&proc);proc =restore();object_free(&cont);cont =restore();if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch680;}object_free(&val);
                    val = compiled_procedure_entry(proc);
                    goto *val.cont;primitive_branch680:;object_free(&val);val = proc.proc(argl); goto *cont.cont;false_branch654:;save(cont);save(env);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|eq?|"));object_free(&val);val = c_str_to_datum("|and|");argl = cons(object_copy(val),empty);object_free(&val);val = lookup_var_val(c_str_to_datum("|o|"));argl = cons(object_copy(val), argl);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch676;}cont.cont = &&after_call675;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch676:;object_free(&val);val = proc.proc(argl); after_call675:;object_free(&env);env =restore();object_free(&cont);cont =restore();if(val.type==BOOLEAN && !val.boolean){
                        goto false_branch656;}object_free(&proc);proc = lookup_var_val(c_str_to_datum("|compile|"));save(cont);save(proc);object_free(&val);val = lookup_var_val(c_str_to_datum("|linkage|"));argl = cons(object_copy(val),empty);object_free(&val);val = lookup_var_val(c_str_to_datum("|target|"));argl = cons(object_copy(val), argl);save(argl);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|and->if|"));save(proc);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|cdr|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|exp|"));argl = cons(object_copy(val),empty);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch670;}cont.cont = &&after_call669;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch670:;object_free(&val);val = proc.proc(argl); after_call669:;argl = cons(object_copy(val),empty);object_free(&proc);proc =restore();if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch672;}cont.cont = &&after_call671;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch672:;object_free(&val);val = proc.proc(argl); after_call671:;object_free(&argl);argl =restore();argl = cons(object_copy(val), argl);object_free(&proc);proc =restore();object_free(&cont);cont =restore();if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch674;}object_free(&val);
                    val = compiled_procedure_entry(proc);
                    goto *val.cont;primitive_branch674:;object_free(&val);val = proc.proc(argl); goto *cont.cont;false_branch656:;save(cont);save(env);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|eq?|"));object_free(&val);val = c_str_to_datum("|or|");argl = cons(object_copy(val),empty);object_free(&val);val = lookup_var_val(c_str_to_datum("|o|"));argl = cons(object_copy(val), argl);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch668;}cont.cont = &&after_call667;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch668:;object_free(&val);val = proc.proc(argl); after_call667:;object_free(&env);env =restore();object_free(&cont);cont =restore();if(val.type==BOOLEAN && !val.boolean){
                        goto false_branch658;}object_free(&proc);proc = lookup_var_val(c_str_to_datum("|compile|"));save(cont);save(proc);object_free(&val);val = lookup_var_val(c_str_to_datum("|linkage|"));argl = cons(object_copy(val),empty);object_free(&val);val = lookup_var_val(c_str_to_datum("|target|"));argl = cons(object_copy(val), argl);save(argl);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|or->if|"));save(proc);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|cdr|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|exp|"));argl = cons(object_copy(val),empty);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch662;}cont.cont = &&after_call661;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch662:;object_free(&val);val = proc.proc(argl); after_call661:;argl = cons(object_copy(val),empty);object_free(&proc);proc =restore();if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch664;}cont.cont = &&after_call663;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch664:;object_free(&val);val = proc.proc(argl); after_call663:;object_free(&argl);argl =restore();argl = cons(object_copy(val), argl);object_free(&proc);proc =restore();object_free(&cont);cont =restore();if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch666;}object_free(&val);
                    val = compiled_procedure_entry(proc);
                    goto *val.cont;primitive_branch666:;object_free(&val);val = proc.proc(argl); goto *cont.cont;false_branch658:;object_free(&proc);proc = lookup_var_val(c_str_to_datum("|compile-application|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|linkage|"));argl = cons(object_copy(val),empty);object_free(&val);val = lookup_var_val(c_str_to_datum("|target|"));argl = cons(object_copy(val), argl);object_free(&val);val = lookup_var_val(c_str_to_datum("|exp|"));argl = cons(object_copy(val), argl);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch660;}object_free(&val);
                    val = compiled_procedure_entry(proc);
                    goto *val.cont;primitive_branch660:;object_free(&val);val = proc.proc(argl); goto *cont.cont;false_branch640:;object_free(&proc);proc = lookup_var_val(c_str_to_datum("|compile-application|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|linkage|"));argl = cons(object_copy(val),empty);object_free(&val);val = lookup_var_val(c_str_to_datum("|target|"));argl = cons(object_copy(val), argl);object_free(&val);val = lookup_var_val(c_str_to_datum("|exp|"));argl = cons(object_copy(val), argl);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch642;}object_free(&val);
                    val = compiled_procedure_entry(proc);
                    goto *val.cont;primitive_branch642:;object_free(&val);val = proc.proc(argl); goto *cont.cont;after_lambda637:;save(cont);save(proc);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|car|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|exp|"));argl = cons(object_copy(val),empty);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch636;}cont.cont = &&after_call635;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch636:;object_free(&val);val = proc.proc(argl); after_call635:;argl = cons(object_copy(val),empty);object_free(&proc);proc =restore();object_free(&cont);cont =restore();if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch706;}object_free(&val);
                    val = compiled_procedure_entry(proc);
                    goto *val.cont;primitive_branch706:;object_free(&val);val = proc.proc(argl); goto *cont.cont;false_branch632:;object_free(&proc);proc = lookup_var_val(c_str_to_datum("|error|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|exp|"));argl = cons(object_copy(val),empty);object_free(&val);val = c_str_to_datum("|unknown expression type -- compile|");argl = cons(object_copy(val), argl);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch634;}object_free(&val);
                    val = compiled_procedure_entry(proc);
                    goto *val.cont;primitive_branch634:;object_free(&val);val = proc.proc(argl); goto *cont.cont;after_lambda625:;{Object t = def_var_val(c_str_to_datum("|compile|"));
                                   object_free(&val);val = t;}object_free(&val);val = make_compiled_procedure(&&entry608);goto after_lambda607;entry608:env = compiled_procedure_env();
                          env = extend_environment(c_str_to_datum("(|linkage| . ())"));save(cont);save(env);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|eq?|"));object_free(&val);val = c_str_to_datum("|return|");argl = cons(object_copy(val),empty);object_free(&val);val = lookup_var_val(c_str_to_datum("|linkage|"));argl = cons(object_copy(val), argl);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch624;}cont.cont = &&after_call623;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch624:;object_free(&val);val = proc.proc(argl); after_call623:;object_free(&env);env =restore();object_free(&cont);cont =restore();if(val.type==BOOLEAN && !val.boolean){
                        goto false_branch610;}object_free(&proc);proc = lookup_var_val(c_str_to_datum("|c-make-instruction-sequence|"));object_free(&val);val = c_str_to_datum("(|goto *cont.cont;| . ())");argl = cons(object_copy(val),empty);object_free(&val);val = c_str_to_datum("()");argl = cons(object_copy(val), argl);object_free(&val);val = c_str_to_datum("(|cont| . ())");argl = cons(object_copy(val), argl);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch622;}object_free(&val);
                    val = compiled_procedure_entry(proc);
                    goto *val.cont;primitive_branch622:;object_free(&val);val = proc.proc(argl); goto *cont.cont;false_branch610:;save(cont);save(env);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|eq?|"));object_free(&val);val = c_str_to_datum("|next|");argl = cons(object_copy(val),empty);object_free(&val);val = lookup_var_val(c_str_to_datum("|linkage|"));argl = cons(object_copy(val), argl);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch620;}cont.cont = &&after_call619;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch620:;object_free(&val);val = proc.proc(argl); after_call619:;object_free(&env);env =restore();object_free(&cont);cont =restore();if(val.type==BOOLEAN && !val.boolean){
                        goto false_branch612;}object_free(&proc);proc = lookup_var_val(c_str_to_datum("|c-empty-instruction-sequence|"));argl = empty;if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch618;}object_free(&val);
                    val = compiled_procedure_entry(proc);
                    goto *val.cont;primitive_branch618:;object_free(&val);val = proc.proc(argl); goto *cont.cont;false_branch612:;object_free(&proc);proc = lookup_var_val(c_str_to_datum("|c-make-instruction-sequence|"));save(cont);save(proc);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|list|"));object_free(&val);val = c_str_to_datum("|;|");argl = cons(object_copy(val),empty);object_free(&val);val = lookup_var_val(c_str_to_datum("|linkage|"));argl = cons(object_copy(val), argl);object_free(&val);val = c_str_to_datum("|goto |");argl = cons(object_copy(val), argl);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch614;}cont.cont = &&after_call613;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch614:;object_free(&val);val = proc.proc(argl); after_call613:;argl = cons(object_copy(val),empty);object_free(&val);val = c_str_to_datum("()");argl = cons(object_copy(val), argl);object_free(&val);val = c_str_to_datum("()");argl = cons(object_copy(val), argl);object_free(&proc);proc =restore();object_free(&cont);cont =restore();if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch616;}object_free(&val);
                    val = compiled_procedure_entry(proc);
                    goto *val.cont;primitive_branch616:;object_free(&val);val = proc.proc(argl); goto *cont.cont;after_lambda607:;{Object t = def_var_val(c_str_to_datum("|compile-linkage|"));
                                   object_free(&val);val = t;}object_free(&val);val = make_compiled_procedure(&&entry602);goto after_lambda601;entry602:env = compiled_procedure_env();
                          env = extend_environment(c_str_to_datum("(|linkage| . (|instruction-sequence| . ()))"));object_free(&proc);proc = lookup_var_val(c_str_to_datum("|preserving|"));save(cont);save(proc);save(env);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|compile-linkage|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|linkage|"));argl = cons(object_copy(val),empty);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch604;}cont.cont = &&after_call603;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch604:;object_free(&val);val = proc.proc(argl); after_call603:;argl = cons(object_copy(val),empty);object_free(&env);env =restore();object_free(&val);val = lookup_var_val(c_str_to_datum("|instruction-sequence|"));argl = cons(object_copy(val), argl);object_free(&val);val = c_str_to_datum("(|cont| . ())");argl = cons(object_copy(val), argl);object_free(&proc);proc =restore();object_free(&cont);cont =restore();if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch606;}object_free(&val);
                    val = compiled_procedure_entry(proc);
                    goto *val.cont;primitive_branch606:;object_free(&val);val = proc.proc(argl); goto *cont.cont;after_lambda601:;{Object t = def_var_val(c_str_to_datum("|end-with-linkage|"));
                                   object_free(&val);val = t;}object_free(&val);val = make_compiled_procedure(&&entry588);goto after_lambda587;entry588:env = compiled_procedure_env();
                          env = extend_environment(c_str_to_datum("(|exp| . (|target| . (|linkage| . ())))"));object_free(&proc);proc = lookup_var_val(c_str_to_datum("|end-with-linkage|"));save(cont);save(proc);save(env);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|c-make-instruction-sequence|"));save(proc);save(env);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|c-append|"));save(proc);object_free(&val);val = c_str_to_datum("(|;| . ())");argl = cons(object_copy(val),empty);save(env);save(argl);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|const|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|exp|"));argl = cons(object_copy(val),empty);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch590;}cont.cont = &&after_call589;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch590:;object_free(&val);val = proc.proc(argl); after_call589:;object_free(&argl);argl =restore();argl = cons(object_copy(val), argl);object_free(&env);env =restore();save(argl);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|list|"));object_free(&val);val = c_str_to_datum("| = |");argl = cons(object_copy(val),empty);object_free(&val);val = lookup_var_val(c_str_to_datum("|target|"));argl = cons(object_copy(val), argl);object_free(&val);val = c_str_to_datum("|);|");argl = cons(object_copy(val), argl);object_free(&val);val = lookup_var_val(c_str_to_datum("|target|"));argl = cons(object_copy(val), argl);object_free(&val);val = c_str_to_datum("|object_free(&|");argl = cons(object_copy(val), argl);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch592;}cont.cont = &&after_call591;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch592:;object_free(&val);val = proc.proc(argl); after_call591:;object_free(&argl);argl =restore();argl = cons(object_copy(val), argl);object_free(&proc);proc =restore();if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch594;}cont.cont = &&after_call593;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch594:;object_free(&val);val = proc.proc(argl); after_call593:;argl = cons(object_copy(val),empty);object_free(&env);env =restore();save(argl);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|list|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|target|"));argl = cons(object_copy(val),empty);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch596;}cont.cont = &&after_call595;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch596:;object_free(&val);val = proc.proc(argl); after_call595:;object_free(&argl);argl =restore();argl = cons(object_copy(val), argl);object_free(&val);val = c_str_to_datum("()");argl = cons(object_copy(val), argl);object_free(&proc);proc =restore();if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch598;}cont.cont = &&after_call597;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch598:;object_free(&val);val = proc.proc(argl); after_call597:;argl = cons(object_copy(val),empty);object_free(&env);env =restore();object_free(&val);val = lookup_var_val(c_str_to_datum("|linkage|"));argl = cons(object_copy(val), argl);object_free(&proc);proc =restore();object_free(&cont);cont =restore();if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch600;}object_free(&val);
                    val = compiled_procedure_entry(proc);
                    goto *val.cont;primitive_branch600:;object_free(&val);val = proc.proc(argl); goto *cont.cont;after_lambda587:;{Object t = def_var_val(c_str_to_datum("|compile-self-evaluating|"));
                                   object_free(&val);val = t;}object_free(&val);val = make_compiled_procedure(&&entry574);goto after_lambda573;entry574:env = compiled_procedure_env();
                          env = extend_environment(c_str_to_datum("(|exp| . (|target| . (|linkage| . ())))"));object_free(&proc);proc = lookup_var_val(c_str_to_datum("|end-with-linkage|"));save(cont);save(proc);save(env);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|c-make-instruction-sequence|"));save(proc);save(env);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|c-append|"));save(proc);object_free(&val);val = c_str_to_datum("(|\\x22;));| . ())");argl = cons(object_copy(val),empty);save(env);save(argl);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|c-symbol->c|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|exp|"));argl = cons(object_copy(val),empty);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch576;}cont.cont = &&after_call575;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch576:;object_free(&val);val = proc.proc(argl); after_call575:;object_free(&argl);argl =restore();argl = cons(object_copy(val), argl);object_free(&env);env =restore();save(argl);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|list|"));object_free(&val);val = c_str_to_datum("| = lookup_var_val(c_str_to_datum(\\x22;|");argl = cons(object_copy(val),empty);object_free(&val);val = lookup_var_val(c_str_to_datum("|target|"));argl = cons(object_copy(val), argl);object_free(&val);val = c_str_to_datum("|);|");argl = cons(object_copy(val), argl);object_free(&val);val = lookup_var_val(c_str_to_datum("|target|"));argl = cons(object_copy(val), argl);object_free(&val);val = c_str_to_datum("|object_free(&|");argl = cons(object_copy(val), argl);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch578;}cont.cont = &&after_call577;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch578:;object_free(&val);val = proc.proc(argl); after_call577:;object_free(&argl);argl =restore();argl = cons(object_copy(val), argl);object_free(&proc);proc =restore();if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch580;}cont.cont = &&after_call579;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch580:;object_free(&val);val = proc.proc(argl); after_call579:;argl = cons(object_copy(val),empty);object_free(&env);env =restore();save(argl);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|list|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|target|"));argl = cons(object_copy(val),empty);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch582;}cont.cont = &&after_call581;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch582:;object_free(&val);val = proc.proc(argl); after_call581:;object_free(&argl);argl =restore();argl = cons(object_copy(val), argl);object_free(&val);val = c_str_to_datum("(|env| . ())");argl = cons(object_copy(val), argl);object_free(&proc);proc =restore();if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch584;}cont.cont = &&after_call583;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch584:;object_free(&val);val = proc.proc(argl); after_call583:;argl = cons(object_copy(val),empty);object_free(&env);env =restore();object_free(&val);val = lookup_var_val(c_str_to_datum("|linkage|"));argl = cons(object_copy(val), argl);object_free(&proc);proc =restore();object_free(&cont);cont =restore();if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch586;}object_free(&val);
                    val = compiled_procedure_entry(proc);
                    goto *val.cont;primitive_branch586:;object_free(&val);val = proc.proc(argl); goto *cont.cont;after_lambda573:;{Object t = def_var_val(c_str_to_datum("|compile-variable|"));
                                   object_free(&val);val = t;}object_free(&val);val = make_compiled_procedure(&&entry558);goto after_lambda557;entry558:env = compiled_procedure_env();
                          env = extend_environment(c_str_to_datum("(|exp| . (|target| . (|linkage| . ())))"));object_free(&proc);proc = lookup_var_val(c_str_to_datum("|end-with-linkage|"));save(cont);save(proc);save(env);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|c-make-instruction-sequence|"));save(proc);save(env);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|c-append|"));save(proc);object_free(&val);val = c_str_to_datum("(|;| . ())");argl = cons(object_copy(val),empty);save(env);save(argl);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|const|"));save(proc);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|c-cadr|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|exp|"));argl = cons(object_copy(val),empty);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch560;}cont.cont = &&after_call559;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch560:;object_free(&val);val = proc.proc(argl); after_call559:;argl = cons(object_copy(val),empty);object_free(&proc);proc =restore();if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch562;}cont.cont = &&after_call561;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch562:;object_free(&val);val = proc.proc(argl); after_call561:;object_free(&argl);argl =restore();argl = cons(object_copy(val), argl);object_free(&env);env =restore();save(argl);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|list|"));object_free(&val);val = c_str_to_datum("| = |");argl = cons(object_copy(val),empty);object_free(&val);val = lookup_var_val(c_str_to_datum("|target|"));argl = cons(object_copy(val), argl);object_free(&val);val = c_str_to_datum("|);|");argl = cons(object_copy(val), argl);object_free(&val);val = lookup_var_val(c_str_to_datum("|target|"));argl = cons(object_copy(val), argl);object_free(&val);val = c_str_to_datum("|object_free(&|");argl = cons(object_copy(val), argl);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch564;}cont.cont = &&after_call563;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch564:;object_free(&val);val = proc.proc(argl); after_call563:;object_free(&argl);argl =restore();argl = cons(object_copy(val), argl);object_free(&proc);proc =restore();if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch566;}cont.cont = &&after_call565;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch566:;object_free(&val);val = proc.proc(argl); after_call565:;argl = cons(object_copy(val),empty);object_free(&env);env =restore();save(argl);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|list|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|target|"));argl = cons(object_copy(val),empty);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch568;}cont.cont = &&after_call567;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch568:;object_free(&val);val = proc.proc(argl); after_call567:;object_free(&argl);argl =restore();argl = cons(object_copy(val), argl);object_free(&val);val = c_str_to_datum("()");argl = cons(object_copy(val), argl);object_free(&proc);proc =restore();if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch570;}cont.cont = &&after_call569;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch570:;object_free(&val);val = proc.proc(argl); after_call569:;argl = cons(object_copy(val),empty);object_free(&env);env =restore();object_free(&val);val = lookup_var_val(c_str_to_datum("|linkage|"));argl = cons(object_copy(val), argl);object_free(&proc);proc =restore();object_free(&cont);cont =restore();if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch572;}object_free(&val);
                    val = compiled_procedure_entry(proc);
                    goto *val.cont;primitive_branch572:;object_free(&val);val = proc.proc(argl); goto *cont.cont;after_lambda557:;{Object t = def_var_val(c_str_to_datum("|compile-quoted|"));
                                   object_free(&val);val = t;}object_free(&val);val = make_compiled_procedure(&&entry532);goto after_lambda531;entry532:env = compiled_procedure_env();
                          env = extend_environment(c_str_to_datum("(|exp| . (|target| . (|linkage| . ())))"));object_free(&proc);proc = make_compiled_procedure(&&entry540);goto after_lambda539;entry540:env = compiled_procedure_env();
                          env = extend_environment(c_str_to_datum("(|var| . (|get-value-code| . ()))"));object_free(&proc);proc = lookup_var_val(c_str_to_datum("|end-with-linkage|"));save(cont);save(proc);save(env);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|preserving|"));save(proc);save(env);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|c-make-instruction-sequence|"));save(proc);save(env);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|c-append|"));save(proc);save(env);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|list|"));object_free(&val);val = c_str_to_datum("| = t;}|");argl = cons(object_copy(val),empty);object_free(&val);val = lookup_var_val(c_str_to_datum("|target|"));argl = cons(object_copy(val), argl);object_free(&val);val = c_str_to_datum("|);|");argl = cons(object_copy(val), argl);object_free(&val);val = lookup_var_val(c_str_to_datum("|target|"));argl = cons(object_copy(val), argl);object_free(&val);val = c_str_to_datum("|\\x22;));\\n                                   object_free(&|");argl = cons(object_copy(val), argl);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch542;}cont.cont = &&after_call541;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch542:;object_free(&val);val = proc.proc(argl); after_call541:;argl = cons(object_copy(val),empty);object_free(&env);env =restore();save(argl);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|c-symbol->c|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|var|"));argl = cons(object_copy(val),empty);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch544;}cont.cont = &&after_call543;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch544:;object_free(&val);val = proc.proc(argl); after_call543:;object_free(&argl);argl =restore();argl = cons(object_copy(val), argl);object_free(&val);val = c_str_to_datum("(|{Object t = set_var_val(c_str_to_datum(\\x22;| . ())");argl = cons(object_copy(val), argl);object_free(&proc);proc =restore();if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch546;}cont.cont = &&after_call545;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch546:;object_free(&val);val = proc.proc(argl); after_call545:;argl = cons(object_copy(val),empty);object_free(&env);env =restore();save(argl);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|list|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|target|"));argl = cons(object_copy(val),empty);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch548;}cont.cont = &&after_call547;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch548:;object_free(&val);val = proc.proc(argl); after_call547:;object_free(&argl);argl =restore();argl = cons(object_copy(val), argl);object_free(&val);val = c_str_to_datum("(|env| . (|val| . ()))");argl = cons(object_copy(val), argl);object_free(&proc);proc =restore();if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch550;}cont.cont = &&after_call549;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch550:;object_free(&val);val = proc.proc(argl); after_call549:;argl = cons(object_copy(val),empty);object_free(&env);env =restore();object_free(&val);val = lookup_var_val(c_str_to_datum("|get-value-code|"));argl = cons(object_copy(val), argl);object_free(&val);val = c_str_to_datum("(|env| . ())");argl = cons(object_copy(val), argl);object_free(&proc);proc =restore();if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch552;}cont.cont = &&after_call551;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch552:;object_free(&val);val = proc.proc(argl); after_call551:;argl = cons(object_copy(val),empty);object_free(&env);env =restore();object_free(&val);val = lookup_var_val(c_str_to_datum("|linkage|"));argl = cons(object_copy(val), argl);object_free(&proc);proc =restore();object_free(&cont);cont =restore();if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch554;}object_free(&val);
                    val = compiled_procedure_entry(proc);
                    goto *val.cont;primitive_branch554:;object_free(&val);val = proc.proc(argl); goto *cont.cont;after_lambda539:;save(cont);save(proc);save(env);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|compile|"));save(proc);object_free(&val);val = c_str_to_datum("|next|");argl = cons(object_copy(val),empty);object_free(&val);val = c_str_to_datum("|val|");argl = cons(object_copy(val), argl);save(argl);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|c-caddr|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|exp|"));argl = cons(object_copy(val),empty);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch534;}cont.cont = &&after_call533;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch534:;object_free(&val);val = proc.proc(argl); after_call533:;object_free(&argl);argl =restore();argl = cons(object_copy(val), argl);object_free(&proc);proc =restore();if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch536;}cont.cont = &&after_call535;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch536:;object_free(&val);val = proc.proc(argl); after_call535:;argl = cons(object_copy(val),empty);object_free(&env);env =restore();save(argl);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|c-cadr|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|exp|"));argl = cons(object_copy(val),empty);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch538;}cont.cont = &&after_call537;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch538:;object_free(&val);val = proc.proc(argl); after_call537:;object_free(&argl);argl =restore();argl = cons(object_copy(val), argl);object_free(&proc);proc =restore();object_free(&cont);cont =restore();if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch556;}object_free(&val);
                    val = compiled_procedure_entry(proc);
                    goto *val.cont;primitive_branch556:;object_free(&val);val = proc.proc(argl); goto *cont.cont;after_lambda531:;{Object t = def_var_val(c_str_to_datum("|compile-assignment|"));
                                   object_free(&val);val = t;}object_free(&val);val = make_compiled_procedure(&&entry506);goto after_lambda505;entry506:env = compiled_procedure_env();
                          env = extend_environment(c_str_to_datum("(|exp| . (|target| . (|linkage| . ())))"));object_free(&proc);proc = make_compiled_procedure(&&entry514);goto after_lambda513;entry514:env = compiled_procedure_env();
                          env = extend_environment(c_str_to_datum("(|var| . (|get-value-code| . ()))"));object_free(&proc);proc = lookup_var_val(c_str_to_datum("|end-with-linkage|"));save(cont);save(proc);save(env);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|preserving|"));save(proc);save(env);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|c-make-instruction-sequence|"));save(proc);save(env);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|c-append|"));save(proc);save(env);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|list|"));object_free(&val);val = c_str_to_datum("| = t;}|");argl = cons(object_copy(val),empty);object_free(&val);val = lookup_var_val(c_str_to_datum("|target|"));argl = cons(object_copy(val), argl);object_free(&val);val = c_str_to_datum("|);|");argl = cons(object_copy(val), argl);object_free(&val);val = lookup_var_val(c_str_to_datum("|target|"));argl = cons(object_copy(val), argl);object_free(&val);val = c_str_to_datum("|\\x22;));\\n                                   object_free(&|");argl = cons(object_copy(val), argl);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch516;}cont.cont = &&after_call515;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch516:;object_free(&val);val = proc.proc(argl); after_call515:;argl = cons(object_copy(val),empty);object_free(&env);env =restore();save(argl);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|c-symbol->c|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|var|"));argl = cons(object_copy(val),empty);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch518;}cont.cont = &&after_call517;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch518:;object_free(&val);val = proc.proc(argl); after_call517:;object_free(&argl);argl =restore();argl = cons(object_copy(val), argl);object_free(&val);val = c_str_to_datum("(|{Object t = def_var_val(c_str_to_datum(\\x22;| . ())");argl = cons(object_copy(val), argl);object_free(&proc);proc =restore();if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch520;}cont.cont = &&after_call519;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch520:;object_free(&val);val = proc.proc(argl); after_call519:;argl = cons(object_copy(val),empty);object_free(&env);env =restore();save(argl);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|list|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|target|"));argl = cons(object_copy(val),empty);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch522;}cont.cont = &&after_call521;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch522:;object_free(&val);val = proc.proc(argl); after_call521:;object_free(&argl);argl =restore();argl = cons(object_copy(val), argl);object_free(&val);val = c_str_to_datum("(|env| . (|val| . ()))");argl = cons(object_copy(val), argl);object_free(&proc);proc =restore();if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch524;}cont.cont = &&after_call523;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch524:;object_free(&val);val = proc.proc(argl); after_call523:;argl = cons(object_copy(val),empty);object_free(&env);env =restore();object_free(&val);val = lookup_var_val(c_str_to_datum("|get-value-code|"));argl = cons(object_copy(val), argl);object_free(&val);val = c_str_to_datum("(|env| . ())");argl = cons(object_copy(val), argl);object_free(&proc);proc =restore();if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch526;}cont.cont = &&after_call525;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch526:;object_free(&val);val = proc.proc(argl); after_call525:;argl = cons(object_copy(val),empty);object_free(&env);env =restore();object_free(&val);val = lookup_var_val(c_str_to_datum("|linkage|"));argl = cons(object_copy(val), argl);object_free(&proc);proc =restore();object_free(&cont);cont =restore();if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch528;}object_free(&val);
                    val = compiled_procedure_entry(proc);
                    goto *val.cont;primitive_branch528:;object_free(&val);val = proc.proc(argl); goto *cont.cont;after_lambda513:;save(cont);save(proc);save(env);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|compile|"));save(proc);object_free(&val);val = c_str_to_datum("|next|");argl = cons(object_copy(val),empty);object_free(&val);val = c_str_to_datum("|val|");argl = cons(object_copy(val), argl);save(argl);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|definition-value|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|exp|"));argl = cons(object_copy(val),empty);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch508;}cont.cont = &&after_call507;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch508:;object_free(&val);val = proc.proc(argl); after_call507:;object_free(&argl);argl =restore();argl = cons(object_copy(val), argl);object_free(&proc);proc =restore();if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch510;}cont.cont = &&after_call509;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch510:;object_free(&val);val = proc.proc(argl); after_call509:;argl = cons(object_copy(val),empty);object_free(&env);env =restore();save(argl);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|c-definition-variable|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|exp|"));argl = cons(object_copy(val),empty);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch512;}cont.cont = &&after_call511;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch512:;object_free(&val);val = proc.proc(argl); after_call511:;object_free(&argl);argl =restore();argl = cons(object_copy(val), argl);object_free(&proc);proc =restore();object_free(&cont);cont =restore();if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch530;}object_free(&val);
                    val = compiled_procedure_entry(proc);
                    goto *val.cont;primitive_branch530:;object_free(&val);val = proc.proc(argl); goto *cont.cont;after_lambda505:;{Object t = def_var_val(c_str_to_datum("|compile-definition|"));
                                   object_free(&val);val = t;}object_free(&val);val = make_compiled_procedure(&&entry446);goto after_lambda445;entry446:env = compiled_procedure_env();
                          env = extend_environment(c_str_to_datum("(|exp| . (|target| . (|linkage| . ())))"));object_free(&proc);proc = make_compiled_procedure(&&entry452);goto after_lambda451;entry452:env = compiled_procedure_env();
                          env = extend_environment(c_str_to_datum("(|f-branch| . (|after-if| . ()))"));object_free(&proc);proc = make_compiled_procedure(&&entry458);goto after_lambda457;entry458:env = compiled_procedure_env();
                          env = extend_environment(c_str_to_datum("(|consequent-linkage| . ())"));object_free(&proc);proc = make_compiled_procedure(&&entry472);goto after_lambda471;entry472:env = compiled_procedure_env();
                          env = extend_environment(c_str_to_datum("(|p-code| . (|c-code| . (|a-code| . ())))"));object_free(&proc);proc = lookup_var_val(c_str_to_datum("|preserving|"));save(cont);save(proc);save(env);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|append-instruction-sequences|"));save(proc);save(env);save(env);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|eq?|"));object_free(&val);val = c_str_to_datum("|next|");argl = cons(object_copy(val),empty);object_free(&val);val = lookup_var_val(c_str_to_datum("|linkage|"));argl = cons(object_copy(val), argl);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch482;}cont.cont = &&after_call481;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch482:;object_free(&val);val = proc.proc(argl); after_call481:;object_free(&env);env =restore();if(val.type==BOOLEAN && !val.boolean){
                        goto false_branch474;}object_free(&proc);proc = lookup_var_val(c_str_to_datum("|c-make-instruction-sequence|"));save(proc);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|list|"));object_free(&val);val = c_str_to_datum("|:;|");argl = cons(object_copy(val),empty);object_free(&val);val = lookup_var_val(c_str_to_datum("|after-if|"));argl = cons(object_copy(val), argl);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch478;}cont.cont = &&after_call477;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch478:;object_free(&val);val = proc.proc(argl); after_call477:;argl = cons(object_copy(val),empty);object_free(&val);val = c_str_to_datum("()");argl = cons(object_copy(val), argl);object_free(&val);val = c_str_to_datum("()");argl = cons(object_copy(val), argl);object_free(&proc);proc =restore();if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch480;}cont.cont = &&after_if473;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch480:;object_free(&val);val = proc.proc(argl); goto after_if473;false_branch474:;object_free(&proc);proc = lookup_var_val(c_str_to_datum("|c-empty-instruction-sequence|"));argl = empty;if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch476;}cont.cont = &&after_call475;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch476:;object_free(&val);val = proc.proc(argl); after_call475:;after_if473:;argl = cons(object_copy(val),empty);object_free(&env);env =restore();save(env);save(argl);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|parallel-instruction-sequences|"));save(proc);save(env);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|append-instruction-sequences|"));save(proc);object_free(&val);val = lookup_var_val(c_str_to_datum("|a-code|"));argl = cons(object_copy(val),empty);save(argl);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|c-make-instruction-sequence|"));save(proc);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|list|"));object_free(&val);val = c_str_to_datum("|:;|");argl = cons(object_copy(val),empty);object_free(&val);val = lookup_var_val(c_str_to_datum("|f-branch|"));argl = cons(object_copy(val), argl);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch484;}cont.cont = &&after_call483;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch484:;object_free(&val);val = proc.proc(argl); after_call483:;argl = cons(object_copy(val),empty);object_free(&val);val = c_str_to_datum("()");argl = cons(object_copy(val), argl);object_free(&val);val = c_str_to_datum("()");argl = cons(object_copy(val), argl);object_free(&proc);proc =restore();if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch486;}cont.cont = &&after_call485;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch486:;object_free(&val);val = proc.proc(argl); after_call485:;object_free(&argl);argl =restore();argl = cons(object_copy(val), argl);object_free(&proc);proc =restore();if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch488;}cont.cont = &&after_call487;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch488:;object_free(&val);val = proc.proc(argl); after_call487:;argl = cons(object_copy(val),empty);object_free(&env);env =restore();object_free(&val);val = lookup_var_val(c_str_to_datum("|c-code|"));argl = cons(object_copy(val), argl);object_free(&proc);proc =restore();if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch490;}cont.cont = &&after_call489;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch490:;object_free(&val);val = proc.proc(argl); after_call489:;object_free(&argl);argl =restore();argl = cons(object_copy(val), argl);object_free(&env);env =restore();save(argl);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|c-make-instruction-sequence|"));save(proc);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|list|"));object_free(&val);val = c_str_to_datum("|;}|");argl = cons(object_copy(val),empty);object_free(&val);val = lookup_var_val(c_str_to_datum("|f-branch|"));argl = cons(object_copy(val), argl);object_free(&val);val = c_str_to_datum("|if(val.type==BOOLEAN && !val.boolean){\\n                        goto |");argl = cons(object_copy(val), argl);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch492;}cont.cont = &&after_call491;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch492:;object_free(&val);val = proc.proc(argl); after_call491:;argl = cons(object_copy(val),empty);object_free(&val);val = c_str_to_datum("()");argl = cons(object_copy(val), argl);object_free(&val);val = c_str_to_datum("(|val| . ())");argl = cons(object_copy(val), argl);object_free(&proc);proc =restore();if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch494;}cont.cont = &&after_call493;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch494:;object_free(&val);val = proc.proc(argl); after_call493:;object_free(&argl);argl =restore();argl = cons(object_copy(val), argl);object_free(&proc);proc =restore();if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch496;}cont.cont = &&after_call495;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch496:;object_free(&val);val = proc.proc(argl); after_call495:;argl = cons(object_copy(val),empty);object_free(&env);env =restore();object_free(&val);val = lookup_var_val(c_str_to_datum("|p-code|"));argl = cons(object_copy(val), argl);object_free(&val);val = c_str_to_datum("(|env| . (|cont| . ()))");argl = cons(object_copy(val), argl);object_free(&proc);proc =restore();object_free(&cont);cont =restore();if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch498;}object_free(&val);
                    val = compiled_procedure_entry(proc);
                    goto *val.cont;primitive_branch498:;object_free(&val);val = proc.proc(argl); goto *cont.cont;after_lambda471:;save(cont);save(proc);save(env);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|compile|"));save(proc);object_free(&val);val = lookup_var_val(c_str_to_datum("|linkage|"));argl = cons(object_copy(val),empty);object_free(&val);val = lookup_var_val(c_str_to_datum("|target|"));argl = cons(object_copy(val), argl);save(argl);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|c-if-alternative|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|exp|"));argl = cons(object_copy(val),empty);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch460;}cont.cont = &&after_call459;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch460:;object_free(&val);val = proc.proc(argl); after_call459:;object_free(&argl);argl =restore();argl = cons(object_copy(val), argl);object_free(&proc);proc =restore();if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch462;}cont.cont = &&after_call461;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch462:;object_free(&val);val = proc.proc(argl); after_call461:;argl = cons(object_copy(val),empty);object_free(&env);env =restore();save(env);save(argl);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|compile|"));save(proc);object_free(&val);val = lookup_var_val(c_str_to_datum("|consequent-linkage|"));argl = cons(object_copy(val),empty);object_free(&val);val = lookup_var_val(c_str_to_datum("|target|"));argl = cons(object_copy(val), argl);save(argl);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|c-caddr|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|exp|"));argl = cons(object_copy(val),empty);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch464;}cont.cont = &&after_call463;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch464:;object_free(&val);val = proc.proc(argl); after_call463:;object_free(&argl);argl =restore();argl = cons(object_copy(val), argl);object_free(&proc);proc =restore();if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch466;}cont.cont = &&after_call465;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch466:;object_free(&val);val = proc.proc(argl); after_call465:;object_free(&argl);argl =restore();argl = cons(object_copy(val), argl);object_free(&env);env =restore();save(argl);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|compile|"));save(proc);object_free(&val);val = c_str_to_datum("|next|");argl = cons(object_copy(val),empty);object_free(&val);val = c_str_to_datum("|val|");argl = cons(object_copy(val), argl);save(argl);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|c-cadr|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|exp|"));argl = cons(object_copy(val),empty);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch468;}cont.cont = &&after_call467;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch468:;object_free(&val);val = proc.proc(argl); after_call467:;object_free(&argl);argl =restore();argl = cons(object_copy(val), argl);object_free(&proc);proc =restore();if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch470;}cont.cont = &&after_call469;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch470:;object_free(&val);val = proc.proc(argl); after_call469:;object_free(&argl);argl =restore();argl = cons(object_copy(val), argl);object_free(&proc);proc =restore();object_free(&cont);cont =restore();if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch500;}object_free(&val);
                    val = compiled_procedure_entry(proc);
                    goto *val.cont;primitive_branch500:;object_free(&val);val = proc.proc(argl); goto *cont.cont;after_lambda457:;save(cont);save(proc);save(env);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|eq?|"));object_free(&val);val = c_str_to_datum("|next|");argl = cons(object_copy(val),empty);object_free(&val);val = lookup_var_val(c_str_to_datum("|linkage|"));argl = cons(object_copy(val), argl);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch456;}cont.cont = &&after_call455;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch456:;object_free(&val);val = proc.proc(argl); after_call455:;object_free(&env);env =restore();if(val.type==BOOLEAN && !val.boolean){
                        goto false_branch454;}object_free(&val);val = lookup_var_val(c_str_to_datum("|after-if|"));goto after_if453;false_branch454:;object_free(&val);val = lookup_var_val(c_str_to_datum("|linkage|"));after_if453:;argl = cons(object_copy(val),empty);object_free(&proc);proc =restore();object_free(&cont);cont =restore();if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch502;}object_free(&val);
                    val = compiled_procedure_entry(proc);
                    goto *val.cont;primitive_branch502:;object_free(&val);val = proc.proc(argl); goto *cont.cont;after_lambda451:;save(cont);save(proc);save(env);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|make-label|"));object_free(&val);val = c_str_to_datum("|after_if|");argl = cons(object_copy(val),empty);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch448;}cont.cont = &&after_call447;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch448:;object_free(&val);val = proc.proc(argl); after_call447:;argl = cons(object_copy(val),empty);object_free(&env);env =restore();save(argl);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|make-label|"));object_free(&val);val = c_str_to_datum("|false_branch|");argl = cons(object_copy(val),empty);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch450;}cont.cont = &&after_call449;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch450:;object_free(&val);val = proc.proc(argl); after_call449:;object_free(&argl);argl =restore();argl = cons(object_copy(val), argl);object_free(&proc);proc =restore();object_free(&cont);cont =restore();if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch504;}object_free(&val);
                    val = compiled_procedure_entry(proc);
                    goto *val.cont;primitive_branch504:;object_free(&val);val = proc.proc(argl); goto *cont.cont;after_lambda445:;{Object t = def_var_val(c_str_to_datum("|compile-if|"));
                                   object_free(&val);val = t;}object_free(&val);val = make_compiled_procedure(&&entry424);goto after_lambda423;entry424:env = compiled_procedure_env();
                          env = extend_environment(c_str_to_datum("(|seq| . (|target| . (|linkage| . ())))"));save(cont);save(env);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|null?|"));save(proc);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|cdr|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|seq|"));argl = cons(object_copy(val),empty);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch442;}cont.cont = &&after_call441;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch442:;object_free(&val);val = proc.proc(argl); after_call441:;argl = cons(object_copy(val),empty);object_free(&proc);proc =restore();if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch444;}cont.cont = &&after_call443;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch444:;object_free(&val);val = proc.proc(argl); after_call443:;object_free(&env);env =restore();object_free(&cont);cont =restore();if(val.type==BOOLEAN && !val.boolean){
                        goto false_branch426;}object_free(&proc);proc = lookup_var_val(c_str_to_datum("|compile|"));save(cont);save(proc);object_free(&val);val = lookup_var_val(c_str_to_datum("|linkage|"));argl = cons(object_copy(val),empty);object_free(&val);val = lookup_var_val(c_str_to_datum("|target|"));argl = cons(object_copy(val), argl);save(argl);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|car|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|seq|"));argl = cons(object_copy(val),empty);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch438;}cont.cont = &&after_call437;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch438:;object_free(&val);val = proc.proc(argl); after_call437:;object_free(&argl);argl =restore();argl = cons(object_copy(val), argl);object_free(&proc);proc =restore();object_free(&cont);cont =restore();if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch440;}object_free(&val);
                    val = compiled_procedure_entry(proc);
                    goto *val.cont;primitive_branch440:;object_free(&val);val = proc.proc(argl); goto *cont.cont;false_branch426:;object_free(&proc);proc = lookup_var_val(c_str_to_datum("|preserving|"));save(cont);save(proc);save(env);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|compile-sequence|"));save(proc);object_free(&val);val = lookup_var_val(c_str_to_datum("|linkage|"));argl = cons(object_copy(val),empty);object_free(&val);val = lookup_var_val(c_str_to_datum("|target|"));argl = cons(object_copy(val), argl);save(argl);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|cdr|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|seq|"));argl = cons(object_copy(val),empty);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch428;}cont.cont = &&after_call427;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch428:;object_free(&val);val = proc.proc(argl); after_call427:;object_free(&argl);argl =restore();argl = cons(object_copy(val), argl);object_free(&proc);proc =restore();if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch430;}cont.cont = &&after_call429;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch430:;object_free(&val);val = proc.proc(argl); after_call429:;argl = cons(object_copy(val),empty);object_free(&env);env =restore();save(argl);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|compile|"));save(proc);object_free(&val);val = c_str_to_datum("|next|");argl = cons(object_copy(val),empty);object_free(&val);val = lookup_var_val(c_str_to_datum("|target|"));argl = cons(object_copy(val), argl);save(argl);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|car|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|seq|"));argl = cons(object_copy(val),empty);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch432;}cont.cont = &&after_call431;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch432:;object_free(&val);val = proc.proc(argl); after_call431:;object_free(&argl);argl =restore();argl = cons(object_copy(val), argl);object_free(&proc);proc =restore();if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch434;}cont.cont = &&after_call433;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch434:;object_free(&val);val = proc.proc(argl); after_call433:;object_free(&argl);argl =restore();argl = cons(object_copy(val), argl);object_free(&val);val = c_str_to_datum("(|env| . (|cont| . ()))");argl = cons(object_copy(val), argl);object_free(&proc);proc =restore();object_free(&cont);cont =restore();if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch436;}object_free(&val);
                    val = compiled_procedure_entry(proc);
                    goto *val.cont;primitive_branch436:;object_free(&val);val = proc.proc(argl); goto *cont.cont;after_lambda423:;{Object t = def_var_val(c_str_to_datum("|compile-sequence|"));
                                   object_free(&val);val = t;}object_free(&val);val = make_compiled_procedure(&&entry382);goto after_lambda381;entry382:env = compiled_procedure_env();
                          env = extend_environment(c_str_to_datum("(|exp| . (|target| . (|linkage| . ())))"));object_free(&proc);proc = make_compiled_procedure(&&entry388);goto after_lambda387;entry388:env = compiled_procedure_env();
                          env = extend_environment(c_str_to_datum("(|proc-entry| . (|after-lambda| . ()))"));object_free(&proc);proc = make_compiled_procedure(&&entry394);goto after_lambda393;entry394:env = compiled_procedure_env();
                          env = extend_environment(c_str_to_datum("(|lambda-linkage| . ())"));object_free(&proc);proc = lookup_var_val(c_str_to_datum("|append-instruction-sequences|"));save(cont);save(proc);save(env);save(env);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|eq?|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|after-lambda|"));argl = cons(object_copy(val),empty);object_free(&val);val = lookup_var_val(c_str_to_datum("|lambda-linkage|"));argl = cons(object_copy(val), argl);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch404;}cont.cont = &&after_call403;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch404:;object_free(&val);val = proc.proc(argl); after_call403:;object_free(&env);env =restore();if(val.type==BOOLEAN && !val.boolean){
                        goto false_branch396;}object_free(&proc);proc = lookup_var_val(c_str_to_datum("|c-make-instruction-sequence|"));save(proc);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|list|"));object_free(&val);val = c_str_to_datum("|:;|");argl = cons(object_copy(val),empty);object_free(&val);val = lookup_var_val(c_str_to_datum("|after-lambda|"));argl = cons(object_copy(val), argl);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch400;}cont.cont = &&after_call399;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch400:;object_free(&val);val = proc.proc(argl); after_call399:;argl = cons(object_copy(val),empty);object_free(&val);val = c_str_to_datum("()");argl = cons(object_copy(val), argl);object_free(&val);val = c_str_to_datum("()");argl = cons(object_copy(val), argl);object_free(&proc);proc =restore();if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch402;}cont.cont = &&after_if395;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch402:;object_free(&val);val = proc.proc(argl); goto after_if395;false_branch396:;object_free(&proc);proc = lookup_var_val(c_str_to_datum("|c-empty-instruction-sequence|"));argl = empty;if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch398;}cont.cont = &&after_call397;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch398:;object_free(&val);val = proc.proc(argl); after_call397:;after_if395:;argl = cons(object_copy(val),empty);object_free(&env);env =restore();save(argl);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|tack-on-instruction-sequence|"));save(proc);save(env);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|compile-lambda-body|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|proc-entry|"));argl = cons(object_copy(val),empty);object_free(&val);val = lookup_var_val(c_str_to_datum("|exp|"));argl = cons(object_copy(val), argl);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch406;}cont.cont = &&after_call405;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch406:;object_free(&val);val = proc.proc(argl); after_call405:;argl = cons(object_copy(val),empty);object_free(&env);env =restore();save(argl);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|end-with-linkage|"));save(proc);save(env);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|c-make-instruction-sequence|"));save(proc);save(env);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|list|"));object_free(&val);val = c_str_to_datum("|);|");argl = cons(object_copy(val),empty);object_free(&val);val = lookup_var_val(c_str_to_datum("|proc-entry|"));argl = cons(object_copy(val), argl);object_free(&val);val = c_str_to_datum("| = make_compiled_procedure(&&|");argl = cons(object_copy(val), argl);object_free(&val);val = lookup_var_val(c_str_to_datum("|target|"));argl = cons(object_copy(val), argl);object_free(&val);val = c_str_to_datum("|);|");argl = cons(object_copy(val), argl);object_free(&val);val = lookup_var_val(c_str_to_datum("|target|"));argl = cons(object_copy(val), argl);object_free(&val);val = c_str_to_datum("|object_free(&|");argl = cons(object_copy(val), argl);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch408;}cont.cont = &&after_call407;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch408:;object_free(&val);val = proc.proc(argl); after_call407:;argl = cons(object_copy(val),empty);object_free(&env);env =restore();save(argl);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|list|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|target|"));argl = cons(object_copy(val),empty);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch410;}cont.cont = &&after_call409;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch410:;object_free(&val);val = proc.proc(argl); after_call409:;object_free(&argl);argl =restore();argl = cons(object_copy(val), argl);object_free(&val);val = c_str_to_datum("(|env| . ())");argl = cons(object_copy(val), argl);object_free(&proc);proc =restore();if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch412;}cont.cont = &&after_call411;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch412:;object_free(&val);val = proc.proc(argl); after_call411:;argl = cons(object_copy(val),empty);object_free(&env);env =restore();object_free(&val);val = lookup_var_val(c_str_to_datum("|lambda-linkage|"));argl = cons(object_copy(val), argl);object_free(&proc);proc =restore();if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch414;}cont.cont = &&after_call413;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch414:;object_free(&val);val = proc.proc(argl); after_call413:;object_free(&argl);argl =restore();argl = cons(object_copy(val), argl);object_free(&proc);proc =restore();if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch416;}cont.cont = &&after_call415;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch416:;object_free(&val);val = proc.proc(argl); after_call415:;object_free(&argl);argl =restore();argl = cons(object_copy(val), argl);object_free(&proc);proc =restore();object_free(&cont);cont =restore();if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch418;}object_free(&val);
                    val = compiled_procedure_entry(proc);
                    goto *val.cont;primitive_branch418:;object_free(&val);val = proc.proc(argl); goto *cont.cont;after_lambda393:;save(cont);save(proc);save(env);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|eq?|"));object_free(&val);val = c_str_to_datum("|next|");argl = cons(object_copy(val),empty);object_free(&val);val = lookup_var_val(c_str_to_datum("|linkage|"));argl = cons(object_copy(val), argl);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch392;}cont.cont = &&after_call391;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch392:;object_free(&val);val = proc.proc(argl); after_call391:;object_free(&env);env =restore();if(val.type==BOOLEAN && !val.boolean){
                        goto false_branch390;}object_free(&val);val = lookup_var_val(c_str_to_datum("|after-lambda|"));goto after_if389;false_branch390:;object_free(&val);val = lookup_var_val(c_str_to_datum("|linkage|"));after_if389:;argl = cons(object_copy(val),empty);object_free(&proc);proc =restore();object_free(&cont);cont =restore();if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch420;}object_free(&val);
                    val = compiled_procedure_entry(proc);
                    goto *val.cont;primitive_branch420:;object_free(&val);val = proc.proc(argl); goto *cont.cont;after_lambda387:;save(cont);save(proc);save(env);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|make-label|"));object_free(&val);val = c_str_to_datum("|after_lambda|");argl = cons(object_copy(val),empty);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch384;}cont.cont = &&after_call383;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch384:;object_free(&val);val = proc.proc(argl); after_call383:;argl = cons(object_copy(val),empty);object_free(&env);env =restore();save(argl);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|make-label|"));object_free(&val);val = c_str_to_datum("|entry|");argl = cons(object_copy(val),empty);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch386;}cont.cont = &&after_call385;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch386:;object_free(&val);val = proc.proc(argl); after_call385:;object_free(&argl);argl =restore();argl = cons(object_copy(val), argl);object_free(&proc);proc =restore();object_free(&cont);cont =restore();if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch422;}object_free(&val);
                    val = compiled_procedure_entry(proc);
                    goto *val.cont;primitive_branch422:;object_free(&val);val = proc.proc(argl); goto *cont.cont;after_lambda381:;{Object t = def_var_val(c_str_to_datum("|compile-lambda|"));
                                   object_free(&val);val = t;}object_free(&val);val = make_compiled_procedure(&&entry360);goto after_lambda359;entry360:env = compiled_procedure_env();
                          env = extend_environment(c_str_to_datum("(|exp| . (|proc-entry| . ()))"));object_free(&proc);proc = make_compiled_procedure(&&entry364);goto after_lambda363;entry364:env = compiled_procedure_env();
                          env = extend_environment(c_str_to_datum("(|formals| . ())"));object_free(&proc);proc = lookup_var_val(c_str_to_datum("|append-instruction-sequences|"));save(cont);save(proc);save(env);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|compile-sequence|"));save(proc);object_free(&val);val = c_str_to_datum("|return|");argl = cons(object_copy(val),empty);object_free(&val);val = c_str_to_datum("|val|");argl = cons(object_copy(val), argl);save(argl);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|c-cddr|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|exp|"));argl = cons(object_copy(val),empty);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch366;}cont.cont = &&after_call365;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch366:;object_free(&val);val = proc.proc(argl); after_call365:;object_free(&argl);argl =restore();argl = cons(object_copy(val), argl);object_free(&proc);proc =restore();if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch368;}cont.cont = &&after_call367;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch368:;object_free(&val);val = proc.proc(argl); after_call367:;argl = cons(object_copy(val),empty);object_free(&env);env =restore();save(argl);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|c-make-instruction-sequence|"));save(proc);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|c-append|"));save(proc);object_free(&val);val = c_str_to_datum("(|);| . ())");argl = cons(object_copy(val),empty);save(env);save(argl);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|const|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|formals|"));argl = cons(object_copy(val),empty);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch370;}cont.cont = &&after_call369;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch370:;object_free(&val);val = proc.proc(argl); after_call369:;object_free(&argl);argl =restore();argl = cons(object_copy(val), argl);object_free(&env);env =restore();save(argl);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|list|"));object_free(&val);val = c_str_to_datum("|:env = compiled_procedure_env();\\n                          env = extend_environment(|");argl = cons(object_copy(val),empty);object_free(&val);val = lookup_var_val(c_str_to_datum("|proc-entry|"));argl = cons(object_copy(val), argl);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch372;}cont.cont = &&after_call371;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch372:;object_free(&val);val = proc.proc(argl); after_call371:;object_free(&argl);argl =restore();argl = cons(object_copy(val), argl);object_free(&proc);proc =restore();if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch374;}cont.cont = &&after_call373;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch374:;object_free(&val);val = proc.proc(argl); after_call373:;argl = cons(object_copy(val),empty);object_free(&val);val = c_str_to_datum("(|env| . ())");argl = cons(object_copy(val), argl);object_free(&val);val = c_str_to_datum("(|env| . (|proc| . (|argl| . ())))");argl = cons(object_copy(val), argl);object_free(&proc);proc =restore();if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch376;}cont.cont = &&after_call375;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch376:;object_free(&val);val = proc.proc(argl); after_call375:;object_free(&argl);argl =restore();argl = cons(object_copy(val), argl);object_free(&proc);proc =restore();object_free(&cont);cont =restore();if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch378;}object_free(&val);
                    val = compiled_procedure_entry(proc);
                    goto *val.cont;primitive_branch378:;object_free(&val);val = proc.proc(argl); goto *cont.cont;after_lambda363:;save(cont);save(proc);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|c-cadr|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|exp|"));argl = cons(object_copy(val),empty);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch362;}cont.cont = &&after_call361;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch362:;object_free(&val);val = proc.proc(argl); after_call361:;argl = cons(object_copy(val),empty);object_free(&proc);proc =restore();object_free(&cont);cont =restore();if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch380;}object_free(&val);
                    val = compiled_procedure_entry(proc);
                    goto *val.cont;primitive_branch380:;object_free(&val);val = proc.proc(argl); goto *cont.cont;after_lambda359:;{Object t = def_var_val(c_str_to_datum("|compile-lambda-body|"));
                                   object_free(&val);val = t;}object_free(&val);val = make_compiled_procedure(&&entry318);goto after_lambda317;entry318:env = compiled_procedure_env();
                          env = extend_environment(c_str_to_datum("(|exp| . (|target| . (|linkage| . ())))"));object_free(&val);val = make_compiled_procedure(&&entry344);goto after_lambda343;entry344:env = compiled_procedure_env();
                          env = extend_environment(c_str_to_datum("(|proc| . (|lst| . ()))"));save(cont);save(env);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|null?|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|lst|"));argl = cons(object_copy(val),empty);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch358;}cont.cont = &&after_call357;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch358:;object_free(&val);val = proc.proc(argl); after_call357:;object_free(&env);env =restore();object_free(&cont);cont =restore();if(val.type==BOOLEAN && !val.boolean){
                        goto false_branch346;}object_free(&val);val = c_str_to_datum("()");goto *cont.cont;false_branch346:;object_free(&proc);proc = lookup_var_val(c_str_to_datum("|cons|"));save(cont);save(proc);save(env);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|iter|"));save(proc);save(env);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|cdr|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|lst|"));argl = cons(object_copy(val),empty);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch348;}cont.cont = &&after_call347;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch348:;object_free(&val);val = proc.proc(argl); after_call347:;argl = cons(object_copy(val),empty);object_free(&env);env =restore();object_free(&val);val = lookup_var_val(c_str_to_datum("|proc|"));argl = cons(object_copy(val), argl);object_free(&proc);proc =restore();if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch350;}cont.cont = &&after_call349;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch350:;object_free(&val);val = proc.proc(argl); after_call349:;argl = cons(object_copy(val),empty);object_free(&env);env =restore();save(argl);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|proc|"));save(proc);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|car|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|lst|"));argl = cons(object_copy(val),empty);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch352;}cont.cont = &&after_call351;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch352:;object_free(&val);val = proc.proc(argl); after_call351:;argl = cons(object_copy(val),empty);object_free(&proc);proc =restore();if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch354;}cont.cont = &&after_call353;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch354:;object_free(&val);val = proc.proc(argl); after_call353:;object_free(&argl);argl =restore();argl = cons(object_copy(val), argl);object_free(&proc);proc =restore();object_free(&cont);cont =restore();if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch356;}object_free(&val);
                    val = compiled_procedure_entry(proc);
                    goto *val.cont;primitive_branch356:;object_free(&val);val = proc.proc(argl); goto *cont.cont;after_lambda343:;{Object t = def_var_val(c_str_to_datum("|iter|"));
                                   object_free(&val);val = t;}object_free(&proc);proc = make_compiled_procedure(&&entry332);goto after_lambda331;entry332:env = compiled_procedure_env();
                          env = extend_environment(c_str_to_datum("(|proc-code| . (|operand-codes| . ()))"));object_free(&proc);proc = lookup_var_val(c_str_to_datum("|preserving|"));save(cont);save(proc);save(env);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|preserving|"));save(proc);save(env);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|compile-procedure-call|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|linkage|"));argl = cons(object_copy(val),empty);object_free(&val);val = lookup_var_val(c_str_to_datum("|target|"));argl = cons(object_copy(val), argl);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch334;}cont.cont = &&after_call333;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch334:;object_free(&val);val = proc.proc(argl); after_call333:;argl = cons(object_copy(val),empty);object_free(&env);env =restore();save(argl);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|construct-arglist|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|operand-codes|"));argl = cons(object_copy(val),empty);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch336;}cont.cont = &&after_call335;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch336:;object_free(&val);val = proc.proc(argl); after_call335:;object_free(&argl);argl =restore();argl = cons(object_copy(val), argl);object_free(&val);val = c_str_to_datum("(|proc| . (|cont| . ()))");argl = cons(object_copy(val), argl);object_free(&proc);proc =restore();if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch338;}cont.cont = &&after_call337;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch338:;object_free(&val);val = proc.proc(argl); after_call337:;argl = cons(object_copy(val),empty);object_free(&env);env =restore();object_free(&val);val = lookup_var_val(c_str_to_datum("|proc-code|"));argl = cons(object_copy(val), argl);object_free(&val);val = c_str_to_datum("(|env| . (|cont| . ()))");argl = cons(object_copy(val), argl);object_free(&proc);proc =restore();object_free(&cont);cont =restore();if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch340;}object_free(&val);
                    val = compiled_procedure_entry(proc);
                    goto *val.cont;primitive_branch340:;object_free(&val);val = proc.proc(argl); goto *cont.cont;after_lambda331:;save(cont);save(proc);save(env);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|iter|"));save(proc);save(env);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|cdr|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|exp|"));argl = cons(object_copy(val),empty);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch320;}cont.cont = &&after_call319;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch320:;object_free(&val);val = proc.proc(argl); after_call319:;argl = cons(object_copy(val),empty);object_free(&env);env =restore();object_free(&val);val = make_compiled_procedure(&&entry322);goto after_lambda321;entry322:env = compiled_procedure_env();
                          env = extend_environment(c_str_to_datum("(|operand| . ())"));object_free(&proc);proc = lookup_var_val(c_str_to_datum("|compile|"));object_free(&val);val = c_str_to_datum("|next|");argl = cons(object_copy(val),empty);object_free(&val);val = c_str_to_datum("|val|");argl = cons(object_copy(val), argl);object_free(&val);val = lookup_var_val(c_str_to_datum("|operand|"));argl = cons(object_copy(val), argl);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch324;}object_free(&val);
                    val = compiled_procedure_entry(proc);
                    goto *val.cont;primitive_branch324:;object_free(&val);val = proc.proc(argl); goto *cont.cont;after_lambda321:;argl = cons(object_copy(val), argl);object_free(&proc);proc =restore();if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch326;}cont.cont = &&after_call325;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch326:;object_free(&val);val = proc.proc(argl); after_call325:;argl = cons(object_copy(val),empty);object_free(&env);env =restore();save(argl);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|compile|"));save(proc);object_free(&val);val = c_str_to_datum("|next|");argl = cons(object_copy(val),empty);object_free(&val);val = c_str_to_datum("|proc|");argl = cons(object_copy(val), argl);save(argl);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|car|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|exp|"));argl = cons(object_copy(val),empty);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch328;}cont.cont = &&after_call327;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch328:;object_free(&val);val = proc.proc(argl); after_call327:;object_free(&argl);argl =restore();argl = cons(object_copy(val), argl);object_free(&proc);proc =restore();if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch330;}cont.cont = &&after_call329;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch330:;object_free(&val);val = proc.proc(argl); after_call329:;object_free(&argl);argl =restore();argl = cons(object_copy(val), argl);object_free(&proc);proc =restore();object_free(&cont);cont =restore();if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch342;}object_free(&val);
                    val = compiled_procedure_entry(proc);
                    goto *val.cont;primitive_branch342:;object_free(&val);val = proc.proc(argl); goto *cont.cont;after_lambda317:;{Object t = def_var_val(c_str_to_datum("|compile-application|"));
                                   object_free(&val);val = t;}object_free(&val);val = make_compiled_procedure(&&entry282);goto after_lambda281;entry282:env = compiled_procedure_env();
                          env = extend_environment(c_str_to_datum("(|operand-codes| . ())"));object_free(&proc);proc = make_compiled_procedure(&&entry286);goto after_lambda285;entry286:env = compiled_procedure_env();
                          env = extend_environment(c_str_to_datum("(|operand-codes| . ())"));save(cont);save(env);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|null?|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|operand-codes|"));argl = cons(object_copy(val),empty);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch314;}cont.cont = &&after_call313;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch314:;object_free(&val);val = proc.proc(argl); after_call313:;object_free(&env);env =restore();object_free(&cont);cont =restore();if(val.type==BOOLEAN && !val.boolean){
                        goto false_branch288;}object_free(&proc);proc = lookup_var_val(c_str_to_datum("|c-make-instruction-sequence|"));object_free(&val);val = c_str_to_datum("(|argl = empty;| . ())");argl = cons(object_copy(val),empty);object_free(&val);val = c_str_to_datum("(|argl| . ())");argl = cons(object_copy(val), argl);object_free(&val);val = c_str_to_datum("()");argl = cons(object_copy(val), argl);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch312;}object_free(&val);
                    val = compiled_procedure_entry(proc);
                    goto *val.cont;primitive_branch312:;object_free(&val);val = proc.proc(argl); goto *cont.cont;false_branch288:;object_free(&proc);proc = make_compiled_procedure(&&entry296);goto after_lambda295;entry296:env = compiled_procedure_env();
                          env = extend_environment(c_str_to_datum("(|code-to-get-last-arg| . ())"));save(cont);save(env);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|null?|"));save(proc);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|cdr|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|operand-codes|"));argl = cons(object_copy(val),empty);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch306;}cont.cont = &&after_call305;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch306:;object_free(&val);val = proc.proc(argl); after_call305:;argl = cons(object_copy(val),empty);object_free(&proc);proc =restore();if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch308;}cont.cont = &&after_call307;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch308:;object_free(&val);val = proc.proc(argl); after_call307:;object_free(&env);env =restore();object_free(&cont);cont =restore();if(val.type==BOOLEAN && !val.boolean){
                        goto false_branch298;}object_free(&val);val = lookup_var_val(c_str_to_datum("|code-to-get-last-arg|"));goto *cont.cont;false_branch298:;object_free(&proc);proc = lookup_var_val(c_str_to_datum("|preserving|"));save(cont);save(proc);save(env);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|code-to-get-rest-args|"));save(proc);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|cdr|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|operand-codes|"));argl = cons(object_copy(val),empty);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch300;}cont.cont = &&after_call299;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch300:;object_free(&val);val = proc.proc(argl); after_call299:;argl = cons(object_copy(val),empty);object_free(&proc);proc =restore();if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch302;}cont.cont = &&after_call301;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch302:;object_free(&val);val = proc.proc(argl); after_call301:;argl = cons(object_copy(val),empty);object_free(&env);env =restore();object_free(&val);val = lookup_var_val(c_str_to_datum("|code-to-get-last-arg|"));argl = cons(object_copy(val), argl);object_free(&val);val = c_str_to_datum("(|env| . ())");argl = cons(object_copy(val), argl);object_free(&proc);proc =restore();object_free(&cont);cont =restore();if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch304;}object_free(&val);
                    val = compiled_procedure_entry(proc);
                    goto *val.cont;primitive_branch304:;object_free(&val);val = proc.proc(argl); goto *cont.cont;after_lambda295:;save(cont);save(proc);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|append-instruction-sequences|"));save(proc);save(env);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|c-make-instruction-sequence|"));object_free(&val);val = c_str_to_datum("(|argl = cons(object_copy(val),empty);| . ())");argl = cons(object_copy(val),empty);object_free(&val);val = c_str_to_datum("(|argl| . ())");argl = cons(object_copy(val), argl);object_free(&val);val = c_str_to_datum("(|val| . ())");argl = cons(object_copy(val), argl);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch290;}cont.cont = &&after_call289;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch290:;object_free(&val);val = proc.proc(argl); after_call289:;argl = cons(object_copy(val),empty);object_free(&env);env =restore();save(argl);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|car|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|operand-codes|"));argl = cons(object_copy(val),empty);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch292;}cont.cont = &&after_call291;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch292:;object_free(&val);val = proc.proc(argl); after_call291:;object_free(&argl);argl =restore();argl = cons(object_copy(val), argl);object_free(&proc);proc =restore();if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch294;}cont.cont = &&after_call293;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch294:;object_free(&val);val = proc.proc(argl); after_call293:;argl = cons(object_copy(val),empty);object_free(&proc);proc =restore();object_free(&cont);cont =restore();if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch310;}object_free(&val);
                    val = compiled_procedure_entry(proc);
                    goto *val.cont;primitive_branch310:;object_free(&val);val = proc.proc(argl); goto *cont.cont;after_lambda285:;save(cont);save(proc);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|c-reverse|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|operand-codes|"));argl = cons(object_copy(val),empty);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch284;}cont.cont = &&after_call283;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch284:;object_free(&val);val = proc.proc(argl); after_call283:;argl = cons(object_copy(val),empty);object_free(&proc);proc =restore();object_free(&cont);cont =restore();if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch316;}object_free(&val);
                    val = compiled_procedure_entry(proc);
                    goto *val.cont;primitive_branch316:;object_free(&val);val = proc.proc(argl); goto *cont.cont;after_lambda281:;{Object t = def_var_val(c_str_to_datum("|construct-arglist|"));
                                   object_free(&val);val = t;}object_free(&val);val = make_compiled_procedure(&&entry258);goto after_lambda257;entry258:env = compiled_procedure_env();
                          env = extend_environment(c_str_to_datum("(|operand-codes| . ())"));object_free(&proc);proc = make_compiled_procedure(&&entry266);goto after_lambda265;entry266:env = compiled_procedure_env();
                          env = extend_environment(c_str_to_datum("(|code-for-next-arg| . ())"));save(cont);save(env);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|null?|"));save(proc);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|cdr|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|operand-codes|"));argl = cons(object_copy(val),empty);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch276;}cont.cont = &&after_call275;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch276:;object_free(&val);val = proc.proc(argl); after_call275:;argl = cons(object_copy(val),empty);object_free(&proc);proc =restore();if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch278;}cont.cont = &&after_call277;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch278:;object_free(&val);val = proc.proc(argl); after_call277:;object_free(&env);env =restore();object_free(&cont);cont =restore();if(val.type==BOOLEAN && !val.boolean){
                        goto false_branch268;}object_free(&val);val = lookup_var_val(c_str_to_datum("|code-for-next-arg|"));goto *cont.cont;false_branch268:;object_free(&proc);proc = lookup_var_val(c_str_to_datum("|preserving|"));save(cont);save(proc);save(env);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|code-to-get-rest-args|"));save(proc);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|cdr|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|operand-codes|"));argl = cons(object_copy(val),empty);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch270;}cont.cont = &&after_call269;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch270:;object_free(&val);val = proc.proc(argl); after_call269:;argl = cons(object_copy(val),empty);object_free(&proc);proc =restore();if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch272;}cont.cont = &&after_call271;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch272:;object_free(&val);val = proc.proc(argl); after_call271:;argl = cons(object_copy(val),empty);object_free(&env);env =restore();object_free(&val);val = lookup_var_val(c_str_to_datum("|code-for-next-arg|"));argl = cons(object_copy(val), argl);object_free(&val);val = c_str_to_datum("(|env| . ())");argl = cons(object_copy(val), argl);object_free(&proc);proc =restore();object_free(&cont);cont =restore();if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch274;}object_free(&val);
                    val = compiled_procedure_entry(proc);
                    goto *val.cont;primitive_branch274:;object_free(&val);val = proc.proc(argl); goto *cont.cont;after_lambda265:;save(cont);save(proc);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|preserving|"));save(proc);save(env);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|c-make-instruction-sequence|"));object_free(&val);val = c_str_to_datum("(|argl = cons(object_copy(val), argl);| . ())");argl = cons(object_copy(val),empty);object_free(&val);val = c_str_to_datum("(|argl| . ())");argl = cons(object_copy(val), argl);object_free(&val);val = c_str_to_datum("(|val| . (|argl| . ()))");argl = cons(object_copy(val), argl);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch260;}cont.cont = &&after_call259;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch260:;object_free(&val);val = proc.proc(argl); after_call259:;argl = cons(object_copy(val),empty);object_free(&env);env =restore();save(argl);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|car|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|operand-codes|"));argl = cons(object_copy(val),empty);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch262;}cont.cont = &&after_call261;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch262:;object_free(&val);val = proc.proc(argl); after_call261:;object_free(&argl);argl =restore();argl = cons(object_copy(val), argl);object_free(&val);val = c_str_to_datum("(|argl| . ())");argl = cons(object_copy(val), argl);object_free(&proc);proc =restore();if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch264;}cont.cont = &&after_call263;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch264:;object_free(&val);val = proc.proc(argl); after_call263:;argl = cons(object_copy(val),empty);object_free(&proc);proc =restore();object_free(&cont);cont =restore();if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch280;}object_free(&val);
                    val = compiled_procedure_entry(proc);
                    goto *val.cont;primitive_branch280:;object_free(&val);val = proc.proc(argl); goto *cont.cont;after_lambda257:;{Object t = def_var_val(c_str_to_datum("|code-to-get-rest-args|"));
                                   object_free(&val);val = t;}object_free(&val);val = make_compiled_procedure(&&entry206);goto after_lambda205;entry206:env = compiled_procedure_env();
                          env = extend_environment(c_str_to_datum("(|target| . (|linkage| . ()))"));object_free(&proc);proc = make_compiled_procedure(&&entry212);goto after_lambda211;entry212:env = compiled_procedure_env();
                          env = extend_environment(c_str_to_datum("(|primitive-branch| . (|after-call| . ()))"));object_free(&proc);proc = make_compiled_procedure(&&entry218);goto after_lambda217;entry218:env = compiled_procedure_env();
                          env = extend_environment(c_str_to_datum("(|compiled-linkage| . ())"));object_free(&proc);proc = lookup_var_val(c_str_to_datum("|append-instruction-sequences|"));save(cont);save(proc);save(env);save(env);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|eq?|"));object_free(&val);val = c_str_to_datum("|next|");argl = cons(object_copy(val),empty);object_free(&val);val = lookup_var_val(c_str_to_datum("|linkage|"));argl = cons(object_copy(val), argl);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch228;}cont.cont = &&after_call227;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch228:;object_free(&val);val = proc.proc(argl); after_call227:;object_free(&env);env =restore();if(val.type==BOOLEAN && !val.boolean){
                        goto false_branch220;}object_free(&proc);proc = lookup_var_val(c_str_to_datum("|c-make-instruction-sequence|"));save(proc);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|list|"));object_free(&val);val = c_str_to_datum("|:;|");argl = cons(object_copy(val),empty);object_free(&val);val = lookup_var_val(c_str_to_datum("|after-call|"));argl = cons(object_copy(val), argl);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch224;}cont.cont = &&after_call223;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch224:;object_free(&val);val = proc.proc(argl); after_call223:;argl = cons(object_copy(val),empty);object_free(&val);val = c_str_to_datum("()");argl = cons(object_copy(val), argl);object_free(&val);val = c_str_to_datum("()");argl = cons(object_copy(val), argl);object_free(&proc);proc =restore();if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch226;}cont.cont = &&after_if219;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch226:;object_free(&val);val = proc.proc(argl); goto after_if219;false_branch220:;object_free(&proc);proc = lookup_var_val(c_str_to_datum("|c-empty-instruction-sequence|"));argl = empty;if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch222;}cont.cont = &&after_call221;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch222:;object_free(&val);val = proc.proc(argl); after_call221:;after_if219:;argl = cons(object_copy(val),empty);object_free(&env);env =restore();save(env);save(argl);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|parallel-instruction-sequences|"));save(proc);save(env);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|append-instruction-sequences|"));save(proc);save(env);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|end-with-linkage|"));save(proc);save(env);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|c-make-instruction-sequence|"));save(proc);save(env);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|list|"));object_free(&val);val = c_str_to_datum("| = proc.proc(argl); |");argl = cons(object_copy(val),empty);object_free(&val);val = lookup_var_val(c_str_to_datum("|target|"));argl = cons(object_copy(val), argl);object_free(&val);val = c_str_to_datum("|);|");argl = cons(object_copy(val), argl);object_free(&val);val = lookup_var_val(c_str_to_datum("|target|"));argl = cons(object_copy(val), argl);object_free(&val);val = c_str_to_datum("|object_free(&|");argl = cons(object_copy(val), argl);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch230;}cont.cont = &&after_call229;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch230:;object_free(&val);val = proc.proc(argl); after_call229:;argl = cons(object_copy(val),empty);object_free(&env);env =restore();save(argl);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|list|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|target|"));argl = cons(object_copy(val),empty);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch232;}cont.cont = &&after_call231;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch232:;object_free(&val);val = proc.proc(argl); after_call231:;object_free(&argl);argl =restore();argl = cons(object_copy(val), argl);object_free(&val);val = c_str_to_datum("(|proc| . (|argl| . ()))");argl = cons(object_copy(val), argl);object_free(&proc);proc =restore();if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch234;}cont.cont = &&after_call233;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch234:;object_free(&val);val = proc.proc(argl); after_call233:;argl = cons(object_copy(val),empty);object_free(&env);env =restore();object_free(&val);val = lookup_var_val(c_str_to_datum("|linkage|"));argl = cons(object_copy(val), argl);object_free(&proc);proc =restore();if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch236;}cont.cont = &&after_call235;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch236:;object_free(&val);val = proc.proc(argl); after_call235:;argl = cons(object_copy(val),empty);object_free(&env);env =restore();save(argl);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|c-make-instruction-sequence|"));save(proc);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|list|"));object_free(&val);val = c_str_to_datum("|:;|");argl = cons(object_copy(val),empty);object_free(&val);val = lookup_var_val(c_str_to_datum("|primitive-branch|"));argl = cons(object_copy(val), argl);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch238;}cont.cont = &&after_call237;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch238:;object_free(&val);val = proc.proc(argl); after_call237:;argl = cons(object_copy(val),empty);object_free(&val);val = c_str_to_datum("()");argl = cons(object_copy(val), argl);object_free(&val);val = c_str_to_datum("()");argl = cons(object_copy(val), argl);object_free(&proc);proc =restore();if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch240;}cont.cont = &&after_call239;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch240:;object_free(&val);val = proc.proc(argl); after_call239:;object_free(&argl);argl =restore();argl = cons(object_copy(val), argl);object_free(&proc);proc =restore();if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch242;}cont.cont = &&after_call241;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch242:;object_free(&val);val = proc.proc(argl); after_call241:;argl = cons(object_copy(val),empty);object_free(&env);env =restore();save(argl);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|compile-proc-appl|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|compiled-linkage|"));argl = cons(object_copy(val),empty);object_free(&val);val = lookup_var_val(c_str_to_datum("|target|"));argl = cons(object_copy(val), argl);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch244;}cont.cont = &&after_call243;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch244:;object_free(&val);val = proc.proc(argl); after_call243:;object_free(&argl);argl =restore();argl = cons(object_copy(val), argl);object_free(&proc);proc =restore();if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch246;}cont.cont = &&after_call245;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch246:;object_free(&val);val = proc.proc(argl); after_call245:;object_free(&argl);argl =restore();argl = cons(object_copy(val), argl);object_free(&env);env =restore();save(argl);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|c-make-instruction-sequence|"));save(proc);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|list|"));object_free(&val);val = c_str_to_datum("|;}|");argl = cons(object_copy(val),empty);object_free(&val);val = lookup_var_val(c_str_to_datum("|primitive-branch|"));argl = cons(object_copy(val), argl);object_free(&val);val = c_str_to_datum("|if (proc.type == PROC_APPLY) {\\n                     proc = apply_proc();\\n                     argl = apply_argl();\\n                   }\\n                   if (proc.type == PROC) { goto |");argl = cons(object_copy(val), argl);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch248;}cont.cont = &&after_call247;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch248:;object_free(&val);val = proc.proc(argl); after_call247:;argl = cons(object_copy(val),empty);object_free(&val);val = c_str_to_datum("()");argl = cons(object_copy(val), argl);object_free(&val);val = c_str_to_datum("(|proc| . ())");argl = cons(object_copy(val), argl);object_free(&proc);proc =restore();if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch250;}cont.cont = &&after_call249;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch250:;object_free(&val);val = proc.proc(argl); after_call249:;object_free(&argl);argl =restore();argl = cons(object_copy(val), argl);object_free(&proc);proc =restore();object_free(&cont);cont =restore();if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch252;}object_free(&val);
                    val = compiled_procedure_entry(proc);
                    goto *val.cont;primitive_branch252:;object_free(&val);val = proc.proc(argl); goto *cont.cont;after_lambda217:;save(cont);save(proc);save(env);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|eq?|"));object_free(&val);val = c_str_to_datum("|next|");argl = cons(object_copy(val),empty);object_free(&val);val = lookup_var_val(c_str_to_datum("|linkage|"));argl = cons(object_copy(val), argl);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch216;}cont.cont = &&after_call215;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch216:;object_free(&val);val = proc.proc(argl); after_call215:;object_free(&env);env =restore();if(val.type==BOOLEAN && !val.boolean){
                        goto false_branch214;}object_free(&val);val = lookup_var_val(c_str_to_datum("|after-call|"));goto after_if213;false_branch214:;object_free(&val);val = lookup_var_val(c_str_to_datum("|linkage|"));after_if213:;argl = cons(object_copy(val),empty);object_free(&proc);proc =restore();object_free(&cont);cont =restore();if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch254;}object_free(&val);
                    val = compiled_procedure_entry(proc);
                    goto *val.cont;primitive_branch254:;object_free(&val);val = proc.proc(argl); goto *cont.cont;after_lambda211:;save(cont);save(proc);save(env);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|make-label|"));object_free(&val);val = c_str_to_datum("|after_call|");argl = cons(object_copy(val),empty);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch208;}cont.cont = &&after_call207;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch208:;object_free(&val);val = proc.proc(argl); after_call207:;argl = cons(object_copy(val),empty);object_free(&env);env =restore();save(argl);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|make-label|"));object_free(&val);val = c_str_to_datum("|primitive_branch|");argl = cons(object_copy(val),empty);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch210;}cont.cont = &&after_call209;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch210:;object_free(&val);val = proc.proc(argl); after_call209:;object_free(&argl);argl =restore();argl = cons(object_copy(val), argl);object_free(&proc);proc =restore();object_free(&cont);cont =restore();if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch256;}object_free(&val);
                    val = compiled_procedure_entry(proc);
                    goto *val.cont;primitive_branch256:;object_free(&val);val = proc.proc(argl); goto *cont.cont;after_lambda205:;{Object t = def_var_val(c_str_to_datum("|compile-procedure-call|"));
                                   object_free(&val);val = t;}object_free(&val);val = make_compiled_procedure(&&entry146);goto after_lambda145;entry146:env = compiled_procedure_env();
                          env = extend_environment(c_str_to_datum("(|target| . (|linkage| . ()))"));save(cont);save(env);save(env);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|eq?|"));object_free(&val);val = c_str_to_datum("|val|");argl = cons(object_copy(val),empty);object_free(&val);val = lookup_var_val(c_str_to_datum("|target|"));argl = cons(object_copy(val), argl);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch204;}cont.cont = &&after_call203;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch204:;object_free(&val);val = proc.proc(argl); after_call203:;object_free(&env);env =restore();if(val.type==BOOLEAN && !val.boolean){
                        goto false_branch198;}object_free(&proc);proc = lookup_var_val(c_str_to_datum("|not|"));save(proc);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|eq?|"));object_free(&val);val = c_str_to_datum("|return|");argl = cons(object_copy(val),empty);object_free(&val);val = lookup_var_val(c_str_to_datum("|linkage|"));argl = cons(object_copy(val), argl);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch200;}cont.cont = &&after_call199;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch200:;object_free(&val);val = proc.proc(argl); after_call199:;argl = cons(object_copy(val),empty);object_free(&proc);proc =restore();if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch202;}cont.cont = &&after_if197;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch202:;object_free(&val);val = proc.proc(argl); goto after_if197;false_branch198:;object_free(&val);val = c_str_to_datum("#false");after_if197:;object_free(&env);env =restore();object_free(&cont);cont =restore();if(val.type==BOOLEAN && !val.boolean){
                        goto false_branch148;}object_free(&proc);proc = lookup_var_val(c_str_to_datum("|c-make-instruction-sequence|"));save(cont);save(proc);save(env);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|list|"));object_free(&val);val = c_str_to_datum("|;\\n                 object_free(&val);\\n                 val = compiled_procedure_entry(proc);\\n                 goto *val.cont;|");argl = cons(object_copy(val),empty);object_free(&val);val = lookup_var_val(c_str_to_datum("|linkage|"));argl = cons(object_copy(val), argl);object_free(&val);val = c_str_to_datum("|cont.cont = &&|");argl = cons(object_copy(val), argl);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch194;}cont.cont = &&after_call193;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch194:;object_free(&val);val = proc.proc(argl); after_call193:;argl = cons(object_copy(val),empty);object_free(&env);env =restore();object_free(&val);val = lookup_var_val(c_str_to_datum("|all-regs|"));argl = cons(object_copy(val), argl);object_free(&val);val = c_str_to_datum("(|proc| . ())");argl = cons(object_copy(val), argl);object_free(&proc);proc =restore();object_free(&cont);cont =restore();if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch196;}object_free(&val);
                    val = compiled_procedure_entry(proc);
                    goto *val.cont;primitive_branch196:;object_free(&val);val = proc.proc(argl); goto *cont.cont;false_branch148:;save(cont);save(env);save(env);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|not|"));save(proc);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|eq?|"));object_free(&val);val = c_str_to_datum("|val|");argl = cons(object_copy(val),empty);object_free(&val);val = lookup_var_val(c_str_to_datum("|target|"));argl = cons(object_copy(val), argl);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch190;}cont.cont = &&after_call189;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch190:;object_free(&val);val = proc.proc(argl); after_call189:;argl = cons(object_copy(val),empty);object_free(&proc);proc =restore();if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch192;}cont.cont = &&after_call191;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch192:;object_free(&val);val = proc.proc(argl); after_call191:;object_free(&env);env =restore();if(val.type==BOOLEAN && !val.boolean){
                        goto false_branch184;}object_free(&proc);proc = lookup_var_val(c_str_to_datum("|not|"));save(proc);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|eq?|"));object_free(&val);val = c_str_to_datum("|return|");argl = cons(object_copy(val),empty);object_free(&val);val = lookup_var_val(c_str_to_datum("|linkage|"));argl = cons(object_copy(val), argl);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch186;}cont.cont = &&after_call185;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch186:;object_free(&val);val = proc.proc(argl); after_call185:;argl = cons(object_copy(val),empty);object_free(&proc);proc =restore();if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch188;}cont.cont = &&after_if183;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch188:;object_free(&val);val = proc.proc(argl); goto after_if183;false_branch184:;object_free(&val);val = c_str_to_datum("#false");after_if183:;object_free(&env);env =restore();object_free(&cont);cont =restore();if(val.type==BOOLEAN && !val.boolean){
                        goto false_branch150;}object_free(&proc);proc = make_compiled_procedure(&&entry176);goto after_lambda175;entry176:env = compiled_procedure_env();
                          env = extend_environment(c_str_to_datum("(|proc-return| . ())"));object_free(&proc);proc = lookup_var_val(c_str_to_datum("|c-make-instruction-sequence|"));save(cont);save(proc);save(env);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|list|"));object_free(&val);val = c_str_to_datum("|;|");argl = cons(object_copy(val),empty);object_free(&val);val = lookup_var_val(c_str_to_datum("|linkage|"));argl = cons(object_copy(val), argl);object_free(&val);val = c_str_to_datum("| = val; val.type = NONE;\\n                        goto |");argl = cons(object_copy(val), argl);object_free(&val);val = lookup_var_val(c_str_to_datum("|target|"));argl = cons(object_copy(val), argl);object_free(&val);val = c_str_to_datum("|);|");argl = cons(object_copy(val), argl);object_free(&val);val = lookup_var_val(c_str_to_datum("|target|"));argl = cons(object_copy(val), argl);object_free(&val);val = c_str_to_datum("|:\\n                        object_free(&|");argl = cons(object_copy(val), argl);object_free(&val);val = lookup_var_val(c_str_to_datum("|proc-return|"));argl = cons(object_copy(val), argl);object_free(&val);val = c_str_to_datum("|;\\n                        object_free(&val);\\n                        val = compiled_procedure_entry(proc);\\n                        goto *val.cont;|");argl = cons(object_copy(val), argl);object_free(&val);val = lookup_var_val(c_str_to_datum("|proc-return|"));argl = cons(object_copy(val), argl);object_free(&val);val = c_str_to_datum("|cont.cont = &&|");argl = cons(object_copy(val), argl);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch178;}cont.cont = &&after_call177;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch178:;object_free(&val);val = proc.proc(argl); after_call177:;argl = cons(object_copy(val),empty);object_free(&env);env =restore();object_free(&val);val = lookup_var_val(c_str_to_datum("|all-regs|"));argl = cons(object_copy(val), argl);object_free(&val);val = c_str_to_datum("(|proc| . ())");argl = cons(object_copy(val), argl);object_free(&proc);proc =restore();object_free(&cont);cont =restore();if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch180;}object_free(&val);
                    val = compiled_procedure_entry(proc);
                    goto *val.cont;primitive_branch180:;object_free(&val);val = proc.proc(argl); goto *cont.cont;after_lambda175:;save(cont);save(proc);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|make-label|"));object_free(&val);val = c_str_to_datum("|proc_return|");argl = cons(object_copy(val),empty);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch174;}cont.cont = &&after_call173;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch174:;object_free(&val);val = proc.proc(argl); after_call173:;argl = cons(object_copy(val),empty);object_free(&proc);proc =restore();object_free(&cont);cont =restore();if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch182;}object_free(&val);
                    val = compiled_procedure_entry(proc);
                    goto *val.cont;primitive_branch182:;object_free(&val);val = proc.proc(argl); goto *cont.cont;false_branch150:;save(cont);save(env);save(env);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|eq?|"));object_free(&val);val = c_str_to_datum("|val|");argl = cons(object_copy(val),empty);object_free(&val);val = lookup_var_val(c_str_to_datum("|target|"));argl = cons(object_copy(val), argl);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch172;}cont.cont = &&after_call171;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch172:;object_free(&val);val = proc.proc(argl); after_call171:;object_free(&env);env =restore();if(val.type==BOOLEAN && !val.boolean){
                        goto false_branch168;}object_free(&proc);proc = lookup_var_val(c_str_to_datum("|eq?|"));object_free(&val);val = c_str_to_datum("|return|");argl = cons(object_copy(val),empty);object_free(&val);val = lookup_var_val(c_str_to_datum("|linkage|"));argl = cons(object_copy(val), argl);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch170;}cont.cont = &&after_if167;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch170:;object_free(&val);val = proc.proc(argl); goto after_if167;false_branch168:;object_free(&val);val = c_str_to_datum("#false");after_if167:;object_free(&env);env =restore();object_free(&cont);cont =restore();if(val.type==BOOLEAN && !val.boolean){
                        goto false_branch152;}object_free(&proc);proc = lookup_var_val(c_str_to_datum("|c-make-instruction-sequence|"));object_free(&val);val = c_str_to_datum("(|object_free(&val);\\n                    val = compiled_procedure_entry(proc);\\n                    goto *val.cont;| . ())");argl = cons(object_copy(val),empty);object_free(&val);val = lookup_var_val(c_str_to_datum("|all-regs|"));argl = cons(object_copy(val), argl);object_free(&val);val = c_str_to_datum("(|proc| . (|cont| . ()))");argl = cons(object_copy(val), argl);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch166;}object_free(&val);
                    val = compiled_procedure_entry(proc);
                    goto *val.cont;primitive_branch166:;object_free(&val);val = proc.proc(argl); goto *cont.cont;false_branch152:;save(cont);save(env);save(env);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|not|"));save(proc);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|eq?|"));object_free(&val);val = c_str_to_datum("|val|");argl = cons(object_copy(val),empty);object_free(&val);val = lookup_var_val(c_str_to_datum("|target|"));argl = cons(object_copy(val), argl);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch162;}cont.cont = &&after_call161;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch162:;object_free(&val);val = proc.proc(argl); after_call161:;argl = cons(object_copy(val),empty);object_free(&proc);proc =restore();if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch164;}cont.cont = &&after_call163;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch164:;object_free(&val);val = proc.proc(argl); after_call163:;object_free(&env);env =restore();if(val.type==BOOLEAN && !val.boolean){
                        goto false_branch158;}object_free(&proc);proc = lookup_var_val(c_str_to_datum("|eq?|"));object_free(&val);val = c_str_to_datum("|return|");argl = cons(object_copy(val),empty);object_free(&val);val = lookup_var_val(c_str_to_datum("|linkage|"));argl = cons(object_copy(val), argl);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch160;}cont.cont = &&after_if157;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch160:;object_free(&val);val = proc.proc(argl); goto after_if157;false_branch158:;object_free(&val);val = c_str_to_datum("#false");after_if157:;object_free(&env);env =restore();object_free(&cont);cont =restore();if(val.type==BOOLEAN && !val.boolean){
                        goto false_branch154;}object_free(&proc);proc = lookup_var_val(c_str_to_datum("|error|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|target|"));argl = cons(object_copy(val),empty);object_free(&val);val = c_str_to_datum("|return linkage, target not val -- compile|");argl = cons(object_copy(val), argl);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch156;}object_free(&val);
                    val = compiled_procedure_entry(proc);
                    goto *val.cont;primitive_branch156:;object_free(&val);val = proc.proc(argl); goto *cont.cont;false_branch154:;object_free(&val);val = undef;goto *cont.cont;after_lambda145:;{Object t = def_var_val(c_str_to_datum("|compile-proc-appl|"));
                                   object_free(&val);val = t;}object_free(&val);val = c_str_to_datum("(|env| . (|proc| . (|val| . (|argl| . (|cont| . ())))))");{Object t = def_var_val(c_str_to_datum("|all-regs|"));
                                   object_free(&val);val = t;}object_free(&val);val = make_compiled_procedure(&&entry100);goto after_lambda99;entry100:env = compiled_procedure_env();
                          env = extend_environment(c_str_to_datum("|seqs|"));object_free(&val);val = make_compiled_procedure(&&entry120);goto after_lambda119;entry120:env = compiled_procedure_env();
                          env = extend_environment(c_str_to_datum("(|seq1| . (|seq2| . ()))"));object_free(&proc);proc = lookup_var_val(c_str_to_datum("|c-make-instruction-sequence|"));save(cont);save(proc);save(env);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|c-append|"));save(proc);save(env);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|c-statements|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|seq2|"));argl = cons(object_copy(val),empty);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch122;}cont.cont = &&after_call121;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch122:;object_free(&val);val = proc.proc(argl); after_call121:;argl = cons(object_copy(val),empty);object_free(&env);env =restore();save(argl);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|c-statements|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|seq1|"));argl = cons(object_copy(val),empty);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch124;}cont.cont = &&after_call123;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch124:;object_free(&val);val = proc.proc(argl); after_call123:;object_free(&argl);argl =restore();argl = cons(object_copy(val), argl);object_free(&proc);proc =restore();if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch126;}cont.cont = &&after_call125;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch126:;object_free(&val);val = proc.proc(argl); after_call125:;argl = cons(object_copy(val),empty);object_free(&env);env =restore();save(env);save(argl);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|c-list-union|"));save(proc);save(env);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|c-registers-modified|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|seq2|"));argl = cons(object_copy(val),empty);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch128;}cont.cont = &&after_call127;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch128:;object_free(&val);val = proc.proc(argl); after_call127:;argl = cons(object_copy(val),empty);object_free(&env);env =restore();save(argl);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|c-registers-modified|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|seq1|"));argl = cons(object_copy(val),empty);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch130;}cont.cont = &&after_call129;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch130:;object_free(&val);val = proc.proc(argl); after_call129:;object_free(&argl);argl =restore();argl = cons(object_copy(val), argl);object_free(&proc);proc =restore();if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch132;}cont.cont = &&after_call131;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch132:;object_free(&val);val = proc.proc(argl); after_call131:;object_free(&argl);argl =restore();argl = cons(object_copy(val), argl);object_free(&env);env =restore();save(argl);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|c-list-union|"));save(proc);save(env);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|c-list-difference|"));save(proc);save(env);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|c-registers-modified|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|seq1|"));argl = cons(object_copy(val),empty);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch134;}cont.cont = &&after_call133;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch134:;object_free(&val);val = proc.proc(argl); after_call133:;argl = cons(object_copy(val),empty);object_free(&env);env =restore();save(argl);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|c-registers-needed|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|seq2|"));argl = cons(object_copy(val),empty);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch136;}cont.cont = &&after_call135;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch136:;object_free(&val);val = proc.proc(argl); after_call135:;object_free(&argl);argl =restore();argl = cons(object_copy(val), argl);object_free(&proc);proc =restore();if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch138;}cont.cont = &&after_call137;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch138:;object_free(&val);val = proc.proc(argl); after_call137:;argl = cons(object_copy(val),empty);object_free(&env);env =restore();save(argl);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|c-registers-needed|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|seq1|"));argl = cons(object_copy(val),empty);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch140;}cont.cont = &&after_call139;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch140:;object_free(&val);val = proc.proc(argl); after_call139:;object_free(&argl);argl =restore();argl = cons(object_copy(val), argl);object_free(&proc);proc =restore();if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch142;}cont.cont = &&after_call141;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch142:;object_free(&val);val = proc.proc(argl); after_call141:;object_free(&argl);argl =restore();argl = cons(object_copy(val), argl);object_free(&proc);proc =restore();object_free(&cont);cont =restore();if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch144;}object_free(&val);
                    val = compiled_procedure_entry(proc);
                    goto *val.cont;primitive_branch144:;object_free(&val);val = proc.proc(argl); goto *cont.cont;after_lambda119:;{Object t = def_var_val(c_str_to_datum("|append-2-sequences|"));
                                   object_free(&val);val = t;}object_free(&val);val = make_compiled_procedure(&&entry104);goto after_lambda103;entry104:env = compiled_procedure_env();
                          env = extend_environment(c_str_to_datum("(|seqs| . ())"));save(cont);save(env);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|null?|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|seqs|"));argl = cons(object_copy(val),empty);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch118;}cont.cont = &&after_call117;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch118:;object_free(&val);val = proc.proc(argl); after_call117:;object_free(&env);env =restore();object_free(&cont);cont =restore();if(val.type==BOOLEAN && !val.boolean){
                        goto false_branch106;}object_free(&proc);proc = lookup_var_val(c_str_to_datum("|c-empty-instruction-sequence|"));argl = empty;if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch116;}object_free(&val);
                    val = compiled_procedure_entry(proc);
                    goto *val.cont;primitive_branch116:;object_free(&val);val = proc.proc(argl); goto *cont.cont;false_branch106:;object_free(&proc);proc = lookup_var_val(c_str_to_datum("|append-2-sequences|"));save(cont);save(proc);save(env);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|append-seq-list|"));save(proc);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|cdr|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|seqs|"));argl = cons(object_copy(val),empty);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch108;}cont.cont = &&after_call107;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch108:;object_free(&val);val = proc.proc(argl); after_call107:;argl = cons(object_copy(val),empty);object_free(&proc);proc =restore();if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch110;}cont.cont = &&after_call109;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch110:;object_free(&val);val = proc.proc(argl); after_call109:;argl = cons(object_copy(val),empty);object_free(&env);env =restore();save(argl);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|car|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|seqs|"));argl = cons(object_copy(val),empty);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch112;}cont.cont = &&after_call111;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch112:;object_free(&val);val = proc.proc(argl); after_call111:;object_free(&argl);argl =restore();argl = cons(object_copy(val), argl);object_free(&proc);proc =restore();object_free(&cont);cont =restore();if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch114;}object_free(&val);
                    val = compiled_procedure_entry(proc);
                    goto *val.cont;primitive_branch114:;object_free(&val);val = proc.proc(argl); goto *cont.cont;after_lambda103:;{Object t = def_var_val(c_str_to_datum("|append-seq-list|"));
                                   object_free(&val);val = t;}object_free(&proc);proc = lookup_var_val(c_str_to_datum("|append-seq-list|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|seqs|"));argl = cons(object_copy(val),empty);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch102;}object_free(&val);
                    val = compiled_procedure_entry(proc);
                    goto *val.cont;primitive_branch102:;object_free(&val);val = proc.proc(argl); goto *cont.cont;after_lambda99:;{Object t = def_var_val(c_str_to_datum("|append-instruction-sequences|"));
                                   object_free(&val);val = t;}object_free(&val);val = make_compiled_procedure(&&entry48);goto after_lambda47;entry48:env = compiled_procedure_env();
                          env = extend_environment(c_str_to_datum("(|regs| . (|seq1| . (|seq2| . ())))"));save(cont);save(env);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|null?|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|regs|"));argl = cons(object_copy(val),empty);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch98;}cont.cont = &&after_call97;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch98:;object_free(&val);val = proc.proc(argl); after_call97:;object_free(&env);env =restore();object_free(&cont);cont =restore();if(val.type==BOOLEAN && !val.boolean){
                        goto false_branch50;}object_free(&proc);proc = lookup_var_val(c_str_to_datum("|append-instruction-sequences|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|seq2|"));argl = cons(object_copy(val),empty);object_free(&val);val = lookup_var_val(c_str_to_datum("|seq1|"));argl = cons(object_copy(val), argl);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch96;}object_free(&val);
                    val = compiled_procedure_entry(proc);
                    goto *val.cont;primitive_branch96:;object_free(&val);val = proc.proc(argl); goto *cont.cont;false_branch50:;object_free(&proc);proc = make_compiled_procedure(&&entry54);goto after_lambda53;entry54:env = compiled_procedure_env();
                          env = extend_environment(c_str_to_datum("(|first-reg| . ())"));save(cont);save(env);save(env);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|c-needs-register?|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|first-reg|"));argl = cons(object_copy(val),empty);object_free(&val);val = lookup_var_val(c_str_to_datum("|seq2|"));argl = cons(object_copy(val), argl);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch92;}cont.cont = &&after_call91;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch92:;object_free(&val);val = proc.proc(argl); after_call91:;object_free(&env);env =restore();if(val.type==BOOLEAN && !val.boolean){
                        goto false_branch88;}object_free(&proc);proc = lookup_var_val(c_str_to_datum("|c-modifies-register?|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|first-reg|"));argl = cons(object_copy(val),empty);object_free(&val);val = lookup_var_val(c_str_to_datum("|seq1|"));argl = cons(object_copy(val), argl);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch90;}cont.cont = &&after_if87;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch90:;object_free(&val);val = proc.proc(argl); goto after_if87;false_branch88:;object_free(&val);val = c_str_to_datum("#false");after_if87:;object_free(&env);env =restore();object_free(&cont);cont =restore();if(val.type==BOOLEAN && !val.boolean){
                        goto false_branch56;}object_free(&proc);proc = lookup_var_val(c_str_to_datum("|preserving|"));save(cont);save(proc);object_free(&val);val = lookup_var_val(c_str_to_datum("|seq2|"));argl = cons(object_copy(val),empty);save(env);save(argl);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|c-make-instruction-sequence|"));save(proc);save(env);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|c-append|"));save(proc);save(env);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|list|"));object_free(&val);val = c_str_to_datum("| =restore();|");argl = cons(object_copy(val),empty);object_free(&val);val = lookup_var_val(c_str_to_datum("|first-reg|"));argl = cons(object_copy(val), argl);object_free(&val);val = c_str_to_datum("|);|");argl = cons(object_copy(val), argl);object_free(&val);val = lookup_var_val(c_str_to_datum("|first-reg|"));argl = cons(object_copy(val), argl);object_free(&val);val = c_str_to_datum("|object_free(&|");argl = cons(object_copy(val), argl);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch62;}cont.cont = &&after_call61;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch62:;object_free(&val);val = proc.proc(argl); after_call61:;argl = cons(object_copy(val),empty);object_free(&env);env =restore();save(env);save(argl);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|c-statements|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|seq1|"));argl = cons(object_copy(val),empty);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch64;}cont.cont = &&after_call63;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch64:;object_free(&val);val = proc.proc(argl); after_call63:;object_free(&argl);argl =restore();argl = cons(object_copy(val), argl);object_free(&env);env =restore();save(argl);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|list|"));object_free(&val);val = c_str_to_datum("|);|");argl = cons(object_copy(val),empty);object_free(&val);val = lookup_var_val(c_str_to_datum("|first-reg|"));argl = cons(object_copy(val), argl);object_free(&val);val = c_str_to_datum("|save(|");argl = cons(object_copy(val), argl);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch66;}cont.cont = &&after_call65;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch66:;object_free(&val);val = proc.proc(argl); after_call65:;object_free(&argl);argl =restore();argl = cons(object_copy(val), argl);object_free(&proc);proc =restore();if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch68;}cont.cont = &&after_call67;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch68:;object_free(&val);val = proc.proc(argl); after_call67:;argl = cons(object_copy(val),empty);object_free(&env);env =restore();save(env);save(argl);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|c-list-difference|"));save(proc);save(env);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|list|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|first-reg|"));argl = cons(object_copy(val),empty);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch70;}cont.cont = &&after_call69;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch70:;object_free(&val);val = proc.proc(argl); after_call69:;argl = cons(object_copy(val),empty);object_free(&env);env =restore();save(argl);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|c-registers-modified|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|seq1|"));argl = cons(object_copy(val),empty);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch72;}cont.cont = &&after_call71;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch72:;object_free(&val);val = proc.proc(argl); after_call71:;object_free(&argl);argl =restore();argl = cons(object_copy(val), argl);object_free(&proc);proc =restore();if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch74;}cont.cont = &&after_call73;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch74:;object_free(&val);val = proc.proc(argl); after_call73:;object_free(&argl);argl =restore();argl = cons(object_copy(val), argl);object_free(&env);env =restore();save(argl);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|c-list-union|"));save(proc);save(env);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|c-registers-needed|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|seq1|"));argl = cons(object_copy(val),empty);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch76;}cont.cont = &&after_call75;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch76:;object_free(&val);val = proc.proc(argl); after_call75:;argl = cons(object_copy(val),empty);object_free(&env);env =restore();save(argl);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|list|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|first-reg|"));argl = cons(object_copy(val),empty);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch78;}cont.cont = &&after_call77;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch78:;object_free(&val);val = proc.proc(argl); after_call77:;object_free(&argl);argl =restore();argl = cons(object_copy(val), argl);object_free(&proc);proc =restore();if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch80;}cont.cont = &&after_call79;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch80:;object_free(&val);val = proc.proc(argl); after_call79:;object_free(&argl);argl =restore();argl = cons(object_copy(val), argl);object_free(&proc);proc =restore();if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch82;}cont.cont = &&after_call81;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch82:;object_free(&val);val = proc.proc(argl); after_call81:;object_free(&argl);argl =restore();argl = cons(object_copy(val), argl);object_free(&env);env =restore();save(argl);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|cdr|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|regs|"));argl = cons(object_copy(val),empty);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch84;}cont.cont = &&after_call83;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch84:;object_free(&val);val = proc.proc(argl); after_call83:;object_free(&argl);argl =restore();argl = cons(object_copy(val), argl);object_free(&proc);proc =restore();object_free(&cont);cont =restore();if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch86;}object_free(&val);
                    val = compiled_procedure_entry(proc);
                    goto *val.cont;primitive_branch86:;object_free(&val);val = proc.proc(argl); goto *cont.cont;false_branch56:;object_free(&proc);proc = lookup_var_val(c_str_to_datum("|preserving|"));save(cont);save(proc);object_free(&val);val = lookup_var_val(c_str_to_datum("|seq2|"));argl = cons(object_copy(val),empty);object_free(&val);val = lookup_var_val(c_str_to_datum("|seq1|"));argl = cons(object_copy(val), argl);save(argl);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|cdr|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|regs|"));argl = cons(object_copy(val),empty);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch58;}cont.cont = &&after_call57;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch58:;object_free(&val);val = proc.proc(argl); after_call57:;object_free(&argl);argl =restore();argl = cons(object_copy(val), argl);object_free(&proc);proc =restore();object_free(&cont);cont =restore();if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch60;}object_free(&val);
                    val = compiled_procedure_entry(proc);
                    goto *val.cont;primitive_branch60:;object_free(&val);val = proc.proc(argl); goto *cont.cont;after_lambda53:;save(cont);save(proc);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|car|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|regs|"));argl = cons(object_copy(val),empty);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch52;}cont.cont = &&after_call51;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch52:;object_free(&val);val = proc.proc(argl); after_call51:;argl = cons(object_copy(val),empty);object_free(&proc);proc =restore();object_free(&cont);cont =restore();if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch94;}object_free(&val);
                    val = compiled_procedure_entry(proc);
                    goto *val.cont;primitive_branch94:;object_free(&val);val = proc.proc(argl); goto *cont.cont;after_lambda47:;{Object t = def_var_val(c_str_to_datum("|preserving|"));
                                   object_free(&val);val = t;}object_free(&val);val = make_compiled_procedure(&&entry34);goto after_lambda33;entry34:env = compiled_procedure_env();
                          env = extend_environment(c_str_to_datum("(|seq| . (|body-seq| . ()))"));object_free(&proc);proc = lookup_var_val(c_str_to_datum("|c-make-instruction-sequence|"));save(cont);save(proc);save(env);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|c-append|"));save(proc);save(env);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|c-statements|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|body-seq|"));argl = cons(object_copy(val),empty);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch36;}cont.cont = &&after_call35;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch36:;object_free(&val);val = proc.proc(argl); after_call35:;argl = cons(object_copy(val),empty);object_free(&env);env =restore();save(argl);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|c-statements|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|seq|"));argl = cons(object_copy(val),empty);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch38;}cont.cont = &&after_call37;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch38:;object_free(&val);val = proc.proc(argl); after_call37:;object_free(&argl);argl =restore();argl = cons(object_copy(val), argl);object_free(&proc);proc =restore();if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch40;}cont.cont = &&after_call39;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch40:;object_free(&val);val = proc.proc(argl); after_call39:;argl = cons(object_copy(val),empty);object_free(&env);env =restore();save(env);save(argl);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|c-registers-modified|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|seq|"));argl = cons(object_copy(val),empty);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch42;}cont.cont = &&after_call41;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch42:;object_free(&val);val = proc.proc(argl); after_call41:;object_free(&argl);argl =restore();argl = cons(object_copy(val), argl);object_free(&env);env =restore();save(argl);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|c-registers-needed|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|seq|"));argl = cons(object_copy(val),empty);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch44;}cont.cont = &&after_call43;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch44:;object_free(&val);val = proc.proc(argl); after_call43:;object_free(&argl);argl =restore();argl = cons(object_copy(val), argl);object_free(&proc);proc =restore();object_free(&cont);cont =restore();if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch46;}object_free(&val);
                    val = compiled_procedure_entry(proc);
                    goto *val.cont;primitive_branch46:;object_free(&val);val = proc.proc(argl); goto *cont.cont;after_lambda33:;{Object t = def_var_val(c_str_to_datum("|tack-on-instruction-sequence|"));
                                   object_free(&val);val = t;}object_free(&val);val = make_compiled_procedure(&&entry12);goto after_lambda11;entry12:env = compiled_procedure_env();
                          env = extend_environment(c_str_to_datum("(|seq1| . (|seq2| . ()))"));object_free(&proc);proc = lookup_var_val(c_str_to_datum("|c-make-instruction-sequence|"));save(cont);save(proc);save(env);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|c-append|"));save(proc);save(env);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|c-statements|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|seq2|"));argl = cons(object_copy(val),empty);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch14;}cont.cont = &&after_call13;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch14:;object_free(&val);val = proc.proc(argl); after_call13:;argl = cons(object_copy(val),empty);object_free(&env);env =restore();save(argl);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|c-statements|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|seq1|"));argl = cons(object_copy(val),empty);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch16;}cont.cont = &&after_call15;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch16:;object_free(&val);val = proc.proc(argl); after_call15:;object_free(&argl);argl =restore();argl = cons(object_copy(val), argl);object_free(&proc);proc =restore();if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch18;}cont.cont = &&after_call17;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch18:;object_free(&val);val = proc.proc(argl); after_call17:;argl = cons(object_copy(val),empty);object_free(&env);env =restore();save(env);save(argl);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|c-list-union|"));save(proc);save(env);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|c-registers-modified|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|seq2|"));argl = cons(object_copy(val),empty);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch20;}cont.cont = &&after_call19;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch20:;object_free(&val);val = proc.proc(argl); after_call19:;argl = cons(object_copy(val),empty);object_free(&env);env =restore();save(argl);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|c-registers-modified|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|seq1|"));argl = cons(object_copy(val),empty);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch22;}cont.cont = &&after_call21;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch22:;object_free(&val);val = proc.proc(argl); after_call21:;object_free(&argl);argl =restore();argl = cons(object_copy(val), argl);object_free(&proc);proc =restore();if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch24;}cont.cont = &&after_call23;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch24:;object_free(&val);val = proc.proc(argl); after_call23:;object_free(&argl);argl =restore();argl = cons(object_copy(val), argl);object_free(&env);env =restore();save(argl);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|c-list-union|"));save(proc);save(env);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|c-registers-needed|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|seq2|"));argl = cons(object_copy(val),empty);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch26;}cont.cont = &&after_call25;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch26:;object_free(&val);val = proc.proc(argl); after_call25:;argl = cons(object_copy(val),empty);object_free(&env);env =restore();save(argl);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|c-registers-needed|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|seq1|"));argl = cons(object_copy(val),empty);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch28;}cont.cont = &&after_call27;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch28:;object_free(&val);val = proc.proc(argl); after_call27:;object_free(&argl);argl =restore();argl = cons(object_copy(val), argl);object_free(&proc);proc =restore();if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch30;}cont.cont = &&after_call29;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch30:;object_free(&val);val = proc.proc(argl); after_call29:;object_free(&argl);argl =restore();argl = cons(object_copy(val), argl);object_free(&proc);proc =restore();object_free(&cont);cont =restore();if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch32;}object_free(&val);
                    val = compiled_procedure_entry(proc);
                    goto *val.cont;primitive_branch32:;object_free(&val);val = proc.proc(argl); goto *cont.cont;after_lambda11:;{Object t = def_var_val(c_str_to_datum("|parallel-instruction-sequences|"));
                                   object_free(&val);val = t;}save(env);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|open-input-file|"));object_free(&val);val = c_str_to_datum("\"input.scm\"");argl = cons(object_copy(val),empty);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch10;}cont.cont = &&after_call9;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch10:;object_free(&val);val = proc.proc(argl); after_call9:;object_free(&env);env =restore();{Object t = def_var_val(c_str_to_datum("|input-file|"));
                                   object_free(&val);val = t;}save(env);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|open-output-file|"));object_free(&val);val = c_str_to_datum("\"output.c\"");argl = cons(object_copy(val),empty);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch8;}cont.cont = &&after_call7;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch8:;object_free(&val);val = proc.proc(argl); after_call7:;object_free(&env);env =restore();{Object t = def_var_val(c_str_to_datum("|output-file|"));
                                   object_free(&val);val = t;}save(env);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|read|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|input-file|"));argl = cons(object_copy(val),empty);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch6;}cont.cont = &&after_call5;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch6:;object_free(&val);val = proc.proc(argl); after_call5:;object_free(&env);env =restore();{Object t = def_var_val(c_str_to_datum("|data|"));
                                   object_free(&val);val = t;}save(env);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|compile|"));object_free(&val);val = c_str_to_datum("|next|");argl = cons(object_copy(val),empty);object_free(&val);val = c_str_to_datum("|val|");argl = cons(object_copy(val), argl);object_free(&val);val = lookup_var_val(c_str_to_datum("|data|"));argl = cons(object_copy(val), argl);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch4;}cont.cont = &&after_call3;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch4:;object_free(&val);val = proc.proc(argl); after_call3:;object_free(&env);env =restore();{Object t = def_var_val(c_str_to_datum("|code|"));
                                   object_free(&val);val = t;}object_free(&proc);proc = lookup_var_val(c_str_to_datum("|print-code|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|output-file|"));argl = cons(object_copy(val),empty);object_free(&val);val = lookup_var_val(c_str_to_datum("|code|"));argl = cons(object_copy(val), argl);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch2;}cont.cont = &&after_call1;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch2:;object_free(&val);val = proc.proc(argl); after_call1:;object_free(&val);val = c_str_to_datum("|compiled|");printf("=> ");object_write_stdout(val);puts("");}