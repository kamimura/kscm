/** \file */
#include <kscm.h>
int main (int argc,char *argv[]){init();get_command_line(argc, argv);object_free(&proc);proc = make_compiled_procedure(&&entry2);goto after_lambda1;entry2:env = compiled_procedure_env();
                          env = extend_environment(c_str_to_datum("()"));object_free(&val);val = make_compiled_procedure(&&entry875);goto after_lambda874;entry875:env = compiled_procedure_env();
                          env = extend_environment(c_str_to_datum("(|exp| . (|env| . ()))"));save(cont);save(env);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|analyze|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|exp|"));argl = cons(object_copy(val),empty);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch877;}cont.cont = &&proc_return878;
                        object_free(&val);
                        val = compiled_procedure_entry(proc);
                        goto *val.cont;proc_return878:
                        object_free(&proc);proc = val; val.type = NONE;
                        goto after_call876;primitive_branch877:;object_free(&proc);proc = proc.proc(argl); after_call876:;object_free(&env);env =restore();object_free(&cont);cont =restore();object_free(&val);val = lookup_var_val(c_str_to_datum("|env|"));argl = cons(object_copy(val),empty);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch880;}object_free(&val);
                    val = compiled_procedure_entry(proc);
                    goto *val.cont;primitive_branch880:;object_free(&val);val = proc.proc(argl); goto *cont.cont;after_lambda874:;{Object t = def_var_val(c_str_to_datum("|eval|"));
                                   object_free(&val);val = t;}object_free(&val);val = make_compiled_procedure(&&entry809);goto after_lambda808;entry809:env = compiled_procedure_env();
                          env = extend_environment(c_str_to_datum("(|exp| . ())"));save(cont);save(env);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|eof-object?|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|exp|"));argl = cons(object_copy(val),empty);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch873;}cont.cont = &&after_call872;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch873:;object_free(&val);val = proc.proc(argl); after_call872:;object_free(&env);env =restore();object_free(&cont);cont =restore();if(val.type==BOOLEAN && !val.boolean){
                        goto false_branch811;}object_free(&proc);proc = lookup_var_val(c_str_to_datum("|exit|"));argl = empty;if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch871;}object_free(&val);
                    val = compiled_procedure_entry(proc);
                    goto *val.cont;primitive_branch871:;object_free(&val);val = proc.proc(argl); goto *cont.cont;false_branch811:;save(cont);save(env);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|self-evaluating?|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|exp|"));argl = cons(object_copy(val),empty);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch869;}cont.cont = &&after_call868;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch869:;object_free(&val);val = proc.proc(argl); after_call868:;object_free(&env);env =restore();object_free(&cont);cont =restore();if(val.type==BOOLEAN && !val.boolean){
                        goto false_branch813;}object_free(&proc);proc = lookup_var_val(c_str_to_datum("|analyze-self-evaluating|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|exp|"));argl = cons(object_copy(val),empty);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch867;}object_free(&val);
                    val = compiled_procedure_entry(proc);
                    goto *val.cont;primitive_branch867:;object_free(&val);val = proc.proc(argl); goto *cont.cont;false_branch813:;save(cont);save(env);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|variable?|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|exp|"));argl = cons(object_copy(val),empty);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch865;}cont.cont = &&after_call864;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch865:;object_free(&val);val = proc.proc(argl); after_call864:;object_free(&env);env =restore();object_free(&cont);cont =restore();if(val.type==BOOLEAN && !val.boolean){
                        goto false_branch815;}object_free(&proc);proc = lookup_var_val(c_str_to_datum("|analyze-variable|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|exp|"));argl = cons(object_copy(val),empty);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch863;}object_free(&val);
                    val = compiled_procedure_entry(proc);
                    goto *val.cont;primitive_branch863:;object_free(&val);val = proc.proc(argl); goto *cont.cont;false_branch815:;save(cont);save(env);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|quoted?|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|exp|"));argl = cons(object_copy(val),empty);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch861;}cont.cont = &&after_call860;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch861:;object_free(&val);val = proc.proc(argl); after_call860:;object_free(&env);env =restore();object_free(&cont);cont =restore();if(val.type==BOOLEAN && !val.boolean){
                        goto false_branch817;}object_free(&proc);proc = lookup_var_val(c_str_to_datum("|analyze-quoted|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|exp|"));argl = cons(object_copy(val),empty);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch859;}object_free(&val);
                    val = compiled_procedure_entry(proc);
                    goto *val.cont;primitive_branch859:;object_free(&val);val = proc.proc(argl); goto *cont.cont;false_branch817:;save(cont);save(env);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|lambda?|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|exp|"));argl = cons(object_copy(val),empty);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch857;}cont.cont = &&after_call856;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch857:;object_free(&val);val = proc.proc(argl); after_call856:;object_free(&env);env =restore();object_free(&cont);cont =restore();if(val.type==BOOLEAN && !val.boolean){
                        goto false_branch819;}object_free(&proc);proc = lookup_var_val(c_str_to_datum("|analyze-lambda|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|exp|"));argl = cons(object_copy(val),empty);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch855;}object_free(&val);
                    val = compiled_procedure_entry(proc);
                    goto *val.cont;primitive_branch855:;object_free(&val);val = proc.proc(argl); goto *cont.cont;false_branch819:;save(cont);save(env);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|definition?|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|exp|"));argl = cons(object_copy(val),empty);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch853;}cont.cont = &&after_call852;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch853:;object_free(&val);val = proc.proc(argl); after_call852:;object_free(&env);env =restore();object_free(&cont);cont =restore();if(val.type==BOOLEAN && !val.boolean){
                        goto false_branch821;}object_free(&proc);proc = lookup_var_val(c_str_to_datum("|analyze-definition|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|exp|"));argl = cons(object_copy(val),empty);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch851;}object_free(&val);
                    val = compiled_procedure_entry(proc);
                    goto *val.cont;primitive_branch851:;object_free(&val);val = proc.proc(argl); goto *cont.cont;false_branch821:;save(cont);save(env);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|assignment?|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|exp|"));argl = cons(object_copy(val),empty);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch849;}cont.cont = &&after_call848;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch849:;object_free(&val);val = proc.proc(argl); after_call848:;object_free(&env);env =restore();object_free(&cont);cont =restore();if(val.type==BOOLEAN && !val.boolean){
                        goto false_branch823;}object_free(&proc);proc = lookup_var_val(c_str_to_datum("|analyze-assignment|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|exp|"));argl = cons(object_copy(val),empty);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch847;}object_free(&val);
                    val = compiled_procedure_entry(proc);
                    goto *val.cont;primitive_branch847:;object_free(&val);val = proc.proc(argl); goto *cont.cont;false_branch823:;save(cont);save(env);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|if?|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|exp|"));argl = cons(object_copy(val),empty);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch845;}cont.cont = &&after_call844;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch845:;object_free(&val);val = proc.proc(argl); after_call844:;object_free(&env);env =restore();object_free(&cont);cont =restore();if(val.type==BOOLEAN && !val.boolean){
                        goto false_branch825;}object_free(&proc);proc = lookup_var_val(c_str_to_datum("|analyze-if|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|exp|"));argl = cons(object_copy(val),empty);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch843;}object_free(&val);
                    val = compiled_procedure_entry(proc);
                    goto *val.cont;primitive_branch843:;object_free(&val);val = proc.proc(argl); goto *cont.cont;false_branch825:;save(cont);save(env);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|begin?|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|exp|"));argl = cons(object_copy(val),empty);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch841;}cont.cont = &&after_call840;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch841:;object_free(&val);val = proc.proc(argl); after_call840:;object_free(&env);env =restore();object_free(&cont);cont =restore();if(val.type==BOOLEAN && !val.boolean){
                        goto false_branch827;}object_free(&proc);proc = lookup_var_val(c_str_to_datum("|analyze-sequence|"));save(cont);save(proc);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|begin-actions|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|exp|"));argl = cons(object_copy(val),empty);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch837;}cont.cont = &&after_call836;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch837:;object_free(&val);val = proc.proc(argl); after_call836:;argl = cons(object_copy(val),empty);object_free(&proc);proc =restore();object_free(&cont);cont =restore();if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch839;}object_free(&val);
                    val = compiled_procedure_entry(proc);
                    goto *val.cont;primitive_branch839:;object_free(&val);val = proc.proc(argl); goto *cont.cont;false_branch827:;save(cont);save(env);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|application?|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|exp|"));argl = cons(object_copy(val),empty);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch835;}cont.cont = &&after_call834;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch835:;object_free(&val);val = proc.proc(argl); after_call834:;object_free(&env);env =restore();object_free(&cont);cont =restore();if(val.type==BOOLEAN && !val.boolean){
                        goto false_branch829;}object_free(&proc);proc = lookup_var_val(c_str_to_datum("|analyze-application|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|exp|"));argl = cons(object_copy(val),empty);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch833;}object_free(&val);
                    val = compiled_procedure_entry(proc);
                    goto *val.cont;primitive_branch833:;object_free(&val);val = proc.proc(argl); goto *cont.cont;false_branch829:;object_free(&proc);proc = lookup_var_val(c_str_to_datum("|error|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|exp|"));argl = cons(object_copy(val),empty);object_free(&val);val = c_str_to_datum("\"unknown expression type -- analyze\"");argl = cons(object_copy(val), argl);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch831;}object_free(&val);
                    val = compiled_procedure_entry(proc);
                    goto *val.cont;primitive_branch831:;object_free(&val);val = proc.proc(argl); goto *cont.cont;after_lambda808:;{Object t = def_var_val(c_str_to_datum("|analyze|"));
                                   object_free(&val);val = t;}object_free(&val);val = make_compiled_procedure(&&entry805);goto after_lambda804;entry805:env = compiled_procedure_env();
                          env = extend_environment(c_str_to_datum("(|exp| . ())"));object_free(&val);val = make_compiled_procedure(&&entry807);goto *cont.cont;entry807:env = compiled_procedure_env();
                          env = extend_environment(c_str_to_datum("(|env| . ())"));object_free(&val);val = lookup_var_val(c_str_to_datum("|exp|"));goto *cont.cont;after_lambda804:;{Object t = def_var_val(c_str_to_datum("|analyze-self-evaluating|"));
                                   object_free(&val);val = t;}object_free(&val);val = make_compiled_procedure(&&entry799);goto after_lambda798;entry799:env = compiled_procedure_env();
                          env = extend_environment(c_str_to_datum("(|exp| . ())"));object_free(&val);val = make_compiled_procedure(&&entry801);goto *cont.cont;entry801:env = compiled_procedure_env();
                          env = extend_environment(c_str_to_datum("(|env| . ())"));object_free(&proc);proc = lookup_var_val(c_str_to_datum("|lookup-variable-value|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|env|"));argl = cons(object_copy(val),empty);object_free(&val);val = lookup_var_val(c_str_to_datum("|exp|"));argl = cons(object_copy(val), argl);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch803;}object_free(&val);
                    val = compiled_procedure_entry(proc);
                    goto *val.cont;primitive_branch803:;object_free(&val);val = proc.proc(argl); goto *cont.cont;after_lambda798:;{Object t = def_var_val(c_str_to_datum("|analyze-variable|"));
                                   object_free(&val);val = t;}object_free(&val);val = make_compiled_procedure(&&entry789);goto after_lambda788;entry789:env = compiled_procedure_env();
                          env = extend_environment(c_str_to_datum("(|exp| . ())"));object_free(&proc);proc = make_compiled_procedure(&&entry793);goto after_lambda792;entry793:env = compiled_procedure_env();
                          env = extend_environment(c_str_to_datum("(|qval| . ())"));object_free(&val);val = make_compiled_procedure(&&entry795);goto *cont.cont;entry795:env = compiled_procedure_env();
                          env = extend_environment(c_str_to_datum("(|env| . ())"));object_free(&val);val = lookup_var_val(c_str_to_datum("|qval|"));goto *cont.cont;after_lambda792:;save(cont);save(proc);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|text-of-quotation|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|exp|"));argl = cons(object_copy(val),empty);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch791;}cont.cont = &&after_call790;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch791:;object_free(&val);val = proc.proc(argl); after_call790:;argl = cons(object_copy(val),empty);object_free(&proc);proc =restore();object_free(&cont);cont =restore();if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch797;}object_free(&val);
                    val = compiled_procedure_entry(proc);
                    goto *val.cont;primitive_branch797:;object_free(&val);val = proc.proc(argl); goto *cont.cont;after_lambda788:;{Object t = def_var_val(c_str_to_datum("|analyze-quoted|"));
                                   object_free(&val);val = t;}object_free(&val);val = make_compiled_procedure(&&entry773);goto after_lambda772;entry773:env = compiled_procedure_env();
                          env = extend_environment(c_str_to_datum("(|exp| . ())"));object_free(&proc);proc = make_compiled_procedure(&&entry781);goto after_lambda780;entry781:env = compiled_procedure_env();
                          env = extend_environment(c_str_to_datum("(|vars| . (|bproc| . ()))"));object_free(&val);val = make_compiled_procedure(&&entry783);goto *cont.cont;entry783:env = compiled_procedure_env();
                          env = extend_environment(c_str_to_datum("(|env| . ())"));object_free(&proc);proc = lookup_var_val(c_str_to_datum("|make-procedure|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|env|"));argl = cons(object_copy(val),empty);object_free(&val);val = lookup_var_val(c_str_to_datum("|bproc|"));argl = cons(object_copy(val), argl);object_free(&val);val = lookup_var_val(c_str_to_datum("|vars|"));argl = cons(object_copy(val), argl);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch785;}object_free(&val);
                    val = compiled_procedure_entry(proc);
                    goto *val.cont;primitive_branch785:;object_free(&val);val = proc.proc(argl); goto *cont.cont;after_lambda780:;save(cont);save(proc);save(env);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|analyze-sequence|"));save(proc);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|lambda-body|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|exp|"));argl = cons(object_copy(val),empty);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch775;}cont.cont = &&after_call774;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch775:;object_free(&val);val = proc.proc(argl); after_call774:;argl = cons(object_copy(val),empty);object_free(&proc);proc =restore();if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch777;}cont.cont = &&after_call776;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch777:;object_free(&val);val = proc.proc(argl); after_call776:;argl = cons(object_copy(val),empty);object_free(&env);env =restore();save(argl);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|lambda-parameters|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|exp|"));argl = cons(object_copy(val),empty);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch779;}cont.cont = &&after_call778;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch779:;object_free(&val);val = proc.proc(argl); after_call778:;object_free(&argl);argl =restore();argl = cons(object_copy(val), argl);object_free(&proc);proc =restore();object_free(&cont);cont =restore();if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch787;}object_free(&val);
                    val = compiled_procedure_entry(proc);
                    goto *val.cont;primitive_branch787:;object_free(&val);val = proc.proc(argl); goto *cont.cont;after_lambda772:;{Object t = def_var_val(c_str_to_datum("|analyze-lambda|"));
                                   object_free(&val);val = t;}object_free(&val);val = make_compiled_procedure(&&entry755);goto after_lambda754;entry755:env = compiled_procedure_env();
                          env = extend_environment(c_str_to_datum("(|exp| . ())"));object_free(&proc);proc = make_compiled_procedure(&&entry763);goto after_lambda762;entry763:env = compiled_procedure_env();
                          env = extend_environment(c_str_to_datum("(|var| . (|vproc| . ()))"));object_free(&val);val = make_compiled_procedure(&&entry765);goto *cont.cont;entry765:env = compiled_procedure_env();
                          env = extend_environment(c_str_to_datum("(|env| . ())"));object_free(&proc);proc = lookup_var_val(c_str_to_datum("|define-variable!|"));save(cont);save(proc);object_free(&val);val = lookup_var_val(c_str_to_datum("|env|"));argl = cons(object_copy(val),empty);save(env);save(argl);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|vproc|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|env|"));argl = cons(object_copy(val),empty);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch767;}cont.cont = &&after_call766;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch767:;object_free(&val);val = proc.proc(argl); after_call766:;object_free(&argl);argl =restore();argl = cons(object_copy(val), argl);object_free(&env);env =restore();object_free(&val);val = lookup_var_val(c_str_to_datum("|var|"));argl = cons(object_copy(val), argl);object_free(&proc);proc =restore();object_free(&cont);cont =restore();if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch769;}object_free(&val);
                    val = compiled_procedure_entry(proc);
                    goto *val.cont;primitive_branch769:;object_free(&val);val = proc.proc(argl); goto *cont.cont;after_lambda762:;save(cont);save(proc);save(env);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|analyze|"));save(proc);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|definition-value|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|exp|"));argl = cons(object_copy(val),empty);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch757;}cont.cont = &&after_call756;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch757:;object_free(&val);val = proc.proc(argl); after_call756:;argl = cons(object_copy(val),empty);object_free(&proc);proc =restore();if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch759;}cont.cont = &&after_call758;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch759:;object_free(&val);val = proc.proc(argl); after_call758:;argl = cons(object_copy(val),empty);object_free(&env);env =restore();save(argl);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|definition-variable|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|exp|"));argl = cons(object_copy(val),empty);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch761;}cont.cont = &&after_call760;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch761:;object_free(&val);val = proc.proc(argl); after_call760:;object_free(&argl);argl =restore();argl = cons(object_copy(val), argl);object_free(&proc);proc =restore();object_free(&cont);cont =restore();if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch771;}object_free(&val);
                    val = compiled_procedure_entry(proc);
                    goto *val.cont;primitive_branch771:;object_free(&val);val = proc.proc(argl); goto *cont.cont;after_lambda754:;{Object t = def_var_val(c_str_to_datum("|analyze-definition|"));
                                   object_free(&val);val = t;}object_free(&val);val = make_compiled_procedure(&&entry737);goto after_lambda736;entry737:env = compiled_procedure_env();
                          env = extend_environment(c_str_to_datum("(|exp| . ())"));object_free(&proc);proc = make_compiled_procedure(&&entry745);goto after_lambda744;entry745:env = compiled_procedure_env();
                          env = extend_environment(c_str_to_datum("(|var| . (|vproc| . ()))"));object_free(&val);val = make_compiled_procedure(&&entry747);goto *cont.cont;entry747:env = compiled_procedure_env();
                          env = extend_environment(c_str_to_datum("(|env| . ())"));object_free(&proc);proc = lookup_var_val(c_str_to_datum("|set-variable-value!|"));save(cont);save(proc);object_free(&val);val = lookup_var_val(c_str_to_datum("|env|"));argl = cons(object_copy(val),empty);save(env);save(argl);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|vproc|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|env|"));argl = cons(object_copy(val),empty);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch749;}cont.cont = &&after_call748;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch749:;object_free(&val);val = proc.proc(argl); after_call748:;object_free(&argl);argl =restore();argl = cons(object_copy(val), argl);object_free(&env);env =restore();object_free(&val);val = lookup_var_val(c_str_to_datum("|var|"));argl = cons(object_copy(val), argl);object_free(&proc);proc =restore();object_free(&cont);cont =restore();if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch751;}object_free(&val);
                    val = compiled_procedure_entry(proc);
                    goto *val.cont;primitive_branch751:;object_free(&val);val = proc.proc(argl); goto *cont.cont;after_lambda744:;save(cont);save(proc);save(env);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|analyze|"));save(proc);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|assignment-value|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|exp|"));argl = cons(object_copy(val),empty);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch739;}cont.cont = &&after_call738;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch739:;object_free(&val);val = proc.proc(argl); after_call738:;argl = cons(object_copy(val),empty);object_free(&proc);proc =restore();if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch741;}cont.cont = &&after_call740;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch741:;object_free(&val);val = proc.proc(argl); after_call740:;argl = cons(object_copy(val),empty);object_free(&env);env =restore();save(argl);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|assignment-variable|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|exp|"));argl = cons(object_copy(val),empty);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch743;}cont.cont = &&after_call742;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch743:;object_free(&val);val = proc.proc(argl); after_call742:;object_free(&argl);argl =restore();argl = cons(object_copy(val), argl);object_free(&proc);proc =restore();object_free(&cont);cont =restore();if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch753;}object_free(&val);
                    val = compiled_procedure_entry(proc);
                    goto *val.cont;primitive_branch753:;object_free(&val);val = proc.proc(argl); goto *cont.cont;after_lambda736:;{Object t = def_var_val(c_str_to_datum("|analyze-assignment|"));
                                   object_free(&val);val = t;}object_free(&val);val = make_compiled_procedure(&&entry709);goto after_lambda708;entry709:env = compiled_procedure_env();
                          env = extend_environment(c_str_to_datum("(|exp| . ())"));object_free(&proc);proc = make_compiled_procedure(&&entry723);goto after_lambda722;entry723:env = compiled_procedure_env();
                          env = extend_environment(c_str_to_datum("(|pproc| . (|cproc| . (|aproc| . ())))"));object_free(&val);val = make_compiled_procedure(&&entry725);goto *cont.cont;entry725:env = compiled_procedure_env();
                          env = extend_environment(c_str_to_datum("(|env| . ())"));save(cont);save(env);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|pproc|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|env|"));argl = cons(object_copy(val),empty);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch733;}cont.cont = &&after_call732;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch733:;object_free(&val);val = proc.proc(argl); after_call732:;object_free(&env);env =restore();object_free(&cont);cont =restore();if(val.type==BOOLEAN && !val.boolean){
                        goto false_branch727;}object_free(&proc);proc = lookup_var_val(c_str_to_datum("|cproc|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|env|"));argl = cons(object_copy(val),empty);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch731;}object_free(&val);
                    val = compiled_procedure_entry(proc);
                    goto *val.cont;primitive_branch731:;object_free(&val);val = proc.proc(argl); goto *cont.cont;false_branch727:;object_free(&proc);proc = lookup_var_val(c_str_to_datum("|aproc|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|env|"));argl = cons(object_copy(val),empty);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch729;}object_free(&val);
                    val = compiled_procedure_entry(proc);
                    goto *val.cont;primitive_branch729:;object_free(&val);val = proc.proc(argl); goto *cont.cont;after_lambda722:;save(cont);save(proc);save(env);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|analyze|"));save(proc);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|if-alternative|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|exp|"));argl = cons(object_copy(val),empty);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch711;}cont.cont = &&after_call710;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch711:;object_free(&val);val = proc.proc(argl); after_call710:;argl = cons(object_copy(val),empty);object_free(&proc);proc =restore();if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch713;}cont.cont = &&after_call712;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch713:;object_free(&val);val = proc.proc(argl); after_call712:;argl = cons(object_copy(val),empty);object_free(&env);env =restore();save(env);save(argl);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|analyze|"));save(proc);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|if-consequent|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|exp|"));argl = cons(object_copy(val),empty);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch715;}cont.cont = &&after_call714;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch715:;object_free(&val);val = proc.proc(argl); after_call714:;argl = cons(object_copy(val),empty);object_free(&proc);proc =restore();if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch717;}cont.cont = &&after_call716;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch717:;object_free(&val);val = proc.proc(argl); after_call716:;object_free(&argl);argl =restore();argl = cons(object_copy(val), argl);object_free(&env);env =restore();save(argl);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|analyze|"));save(proc);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|if-predicate|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|exp|"));argl = cons(object_copy(val),empty);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch719;}cont.cont = &&after_call718;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch719:;object_free(&val);val = proc.proc(argl); after_call718:;argl = cons(object_copy(val),empty);object_free(&proc);proc =restore();if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch721;}cont.cont = &&after_call720;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch721:;object_free(&val);val = proc.proc(argl); after_call720:;object_free(&argl);argl =restore();argl = cons(object_copy(val), argl);object_free(&proc);proc =restore();object_free(&cont);cont =restore();if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch735;}object_free(&val);
                    val = compiled_procedure_entry(proc);
                    goto *val.cont;primitive_branch735:;object_free(&val);val = proc.proc(argl); goto *cont.cont;after_lambda708:;{Object t = def_var_val(c_str_to_datum("|analyze-if|"));
                                   object_free(&val);val = t;}object_free(&val);val = make_compiled_procedure(&&entry693);goto after_lambda692;entry693:env = compiled_procedure_env();
                          env = extend_environment(c_str_to_datum("(|proc| . (|list| . ()))"));save(cont);save(env);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|null?|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|list|"));argl = cons(object_copy(val),empty);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch707;}cont.cont = &&after_call706;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch707:;object_free(&val);val = proc.proc(argl); after_call706:;object_free(&env);env =restore();object_free(&cont);cont =restore();if(val.type==BOOLEAN && !val.boolean){
                        goto false_branch695;}object_free(&val);val = c_str_to_datum("()");goto *cont.cont;false_branch695:;object_free(&proc);proc = lookup_var_val(c_str_to_datum("|cons|"));save(cont);save(proc);save(env);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|map|"));save(proc);save(env);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|cdr|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|list|"));argl = cons(object_copy(val),empty);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch697;}cont.cont = &&after_call696;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch697:;object_free(&val);val = proc.proc(argl); after_call696:;argl = cons(object_copy(val),empty);object_free(&env);env =restore();object_free(&val);val = lookup_var_val(c_str_to_datum("|proc|"));argl = cons(object_copy(val), argl);object_free(&proc);proc =restore();if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch699;}cont.cont = &&after_call698;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch699:;object_free(&val);val = proc.proc(argl); after_call698:;argl = cons(object_copy(val),empty);object_free(&env);env =restore();save(argl);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|proc|"));save(proc);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|car|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|list|"));argl = cons(object_copy(val),empty);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch701;}cont.cont = &&after_call700;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch701:;object_free(&val);val = proc.proc(argl); after_call700:;argl = cons(object_copy(val),empty);object_free(&proc);proc =restore();if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch703;}cont.cont = &&after_call702;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch703:;object_free(&val);val = proc.proc(argl); after_call702:;object_free(&argl);argl =restore();argl = cons(object_copy(val), argl);object_free(&proc);proc =restore();object_free(&cont);cont =restore();if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch705;}object_free(&val);
                    val = compiled_procedure_entry(proc);
                    goto *val.cont;primitive_branch705:;object_free(&val);val = proc.proc(argl); goto *cont.cont;after_lambda692:;{Object t = def_var_val(c_str_to_datum("|map|"));
                                   object_free(&val);val = t;}object_free(&val);val = make_compiled_procedure(&&entry651);goto after_lambda650;entry651:env = compiled_procedure_env();
                          env = extend_environment(c_str_to_datum("(|exps| . ())"));object_free(&val);val = make_compiled_procedure(&&entry685);goto after_lambda684;entry685:env = compiled_procedure_env();
                          env = extend_environment(c_str_to_datum("(|proc1| . (|proc2| . ()))"));object_free(&val);val = make_compiled_procedure(&&entry687);goto *cont.cont;entry687:env = compiled_procedure_env();
                          env = extend_environment(c_str_to_datum("(|env| . ())"));save(cont);save(env);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|proc1|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|env|"));argl = cons(object_copy(val),empty);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch691;}cont.cont = &&after_call690;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch691:;object_free(&val);val = proc.proc(argl); after_call690:;object_free(&env);env =restore();object_free(&cont);cont =restore();object_free(&proc);proc = lookup_var_val(c_str_to_datum("|proc2|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|env|"));argl = cons(object_copy(val),empty);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch689;}object_free(&val);
                    val = compiled_procedure_entry(proc);
                    goto *val.cont;primitive_branch689:;object_free(&val);val = proc.proc(argl); goto *cont.cont;after_lambda684:;{Object t = def_var_val(c_str_to_datum("|sequentially|"));
                                   object_free(&val);val = t;}object_free(&val);val = make_compiled_procedure(&&entry671);goto after_lambda670;entry671:env = compiled_procedure_env();
                          env = extend_environment(c_str_to_datum("(|first-proc| . (|rest-procs| . ()))"));save(cont);save(env);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|null?|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|rest-procs|"));argl = cons(object_copy(val),empty);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch683;}cont.cont = &&after_call682;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch683:;object_free(&val);val = proc.proc(argl); after_call682:;object_free(&env);env =restore();object_free(&cont);cont =restore();if(val.type==BOOLEAN && !val.boolean){
                        goto false_branch673;}object_free(&val);val = lookup_var_val(c_str_to_datum("|first-proc|"));goto *cont.cont;false_branch673:;object_free(&proc);proc = lookup_var_val(c_str_to_datum("|loop|"));save(cont);save(proc);save(env);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|cdr|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|rest-procs|"));argl = cons(object_copy(val),empty);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch675;}cont.cont = &&after_call674;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch675:;object_free(&val);val = proc.proc(argl); after_call674:;argl = cons(object_copy(val),empty);object_free(&env);env =restore();save(argl);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|sequentially|"));save(proc);save(env);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|car|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|rest-procs|"));argl = cons(object_copy(val),empty);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch677;}cont.cont = &&after_call676;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch677:;object_free(&val);val = proc.proc(argl); after_call676:;argl = cons(object_copy(val),empty);object_free(&env);env =restore();object_free(&val);val = lookup_var_val(c_str_to_datum("|first-proc|"));argl = cons(object_copy(val), argl);object_free(&proc);proc =restore();if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch679;}cont.cont = &&after_call678;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch679:;object_free(&val);val = proc.proc(argl); after_call678:;object_free(&argl);argl =restore();argl = cons(object_copy(val), argl);object_free(&proc);proc =restore();object_free(&cont);cont =restore();if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch681;}object_free(&val);
                    val = compiled_procedure_entry(proc);
                    goto *val.cont;primitive_branch681:;object_free(&val);val = proc.proc(argl); goto *cont.cont;after_lambda670:;{Object t = def_var_val(c_str_to_datum("|loop|"));
                                   object_free(&val);val = t;}object_free(&proc);proc = make_compiled_procedure(&&entry655);goto after_lambda654;entry655:env = compiled_procedure_env();
                          env = extend_environment(c_str_to_datum("(|procs| . ())"));save(cont);save(env);save(env);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|null?|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|procs|"));argl = cons(object_copy(val),empty);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch667;}cont.cont = &&after_call666;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch667:;object_free(&val);val = proc.proc(argl); after_call666:;object_free(&env);env =restore();if(val.type==BOOLEAN && !val.boolean){
                        goto false_branch663;}object_free(&proc);proc = lookup_var_val(c_str_to_datum("|error|"));object_free(&val);val = c_str_to_datum("\"empty sequence -- analyze\"");argl = cons(object_copy(val),empty);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch665;}cont.cont = &&after_if662;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch665:;object_free(&val);val = proc.proc(argl); goto after_if662;false_branch663:;object_free(&val);val = undef;after_if662:;object_free(&env);env =restore();object_free(&cont);cont =restore();object_free(&proc);proc = lookup_var_val(c_str_to_datum("|loop|"));save(cont);save(proc);save(env);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|cdr|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|procs|"));argl = cons(object_copy(val),empty);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch657;}cont.cont = &&after_call656;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch657:;object_free(&val);val = proc.proc(argl); after_call656:;argl = cons(object_copy(val),empty);object_free(&env);env =restore();save(argl);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|car|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|procs|"));argl = cons(object_copy(val),empty);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch659;}cont.cont = &&after_call658;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch659:;object_free(&val);val = proc.proc(argl); after_call658:;object_free(&argl);argl =restore();argl = cons(object_copy(val), argl);object_free(&proc);proc =restore();object_free(&cont);cont =restore();if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch661;}object_free(&val);
                    val = compiled_procedure_entry(proc);
                    goto *val.cont;primitive_branch661:;object_free(&val);val = proc.proc(argl); goto *cont.cont;after_lambda654:;save(cont);save(proc);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|map|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|exps|"));argl = cons(object_copy(val),empty);object_free(&val);val = lookup_var_val(c_str_to_datum("|analyze|"));argl = cons(object_copy(val), argl);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch653;}cont.cont = &&after_call652;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch653:;object_free(&val);val = proc.proc(argl); after_call652:;argl = cons(object_copy(val),empty);object_free(&proc);proc =restore();object_free(&cont);cont =restore();if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch669;}object_free(&val);
                    val = compiled_procedure_entry(proc);
                    goto *val.cont;primitive_branch669:;object_free(&val);val = proc.proc(argl); goto *cont.cont;after_lambda650:;{Object t = def_var_val(c_str_to_datum("|analyze-sequence|"));
                                   object_free(&val);val = t;}object_free(&val);val = make_compiled_procedure(&&entry625);goto after_lambda624;entry625:env = compiled_procedure_env();
                          env = extend_environment(c_str_to_datum("(|exp| . ())"));object_free(&proc);proc = make_compiled_procedure(&&entry635);goto after_lambda634;entry635:env = compiled_procedure_env();
                          env = extend_environment(c_str_to_datum("(|pproc| . (|aprocs| . ()))"));object_free(&val);val = make_compiled_procedure(&&entry637);goto *cont.cont;entry637:env = compiled_procedure_env();
                          env = extend_environment(c_str_to_datum("(|env| . ())"));object_free(&proc);proc = lookup_var_val(c_str_to_datum("|execute-application|"));save(cont);save(proc);save(env);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|map|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|aprocs|"));argl = cons(object_copy(val),empty);object_free(&val);val = make_compiled_procedure(&&entry639);goto after_lambda638;entry639:env = compiled_procedure_env();
                          env = extend_environment(c_str_to_datum("(|aproc| . ())"));object_free(&proc);proc = lookup_var_val(c_str_to_datum("|aproc|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|env|"));argl = cons(object_copy(val),empty);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch641;}object_free(&val);
                    val = compiled_procedure_entry(proc);
                    goto *val.cont;primitive_branch641:;object_free(&val);val = proc.proc(argl); goto *cont.cont;after_lambda638:;argl = cons(object_copy(val), argl);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch643;}cont.cont = &&after_call642;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch643:;object_free(&val);val = proc.proc(argl); after_call642:;argl = cons(object_copy(val),empty);object_free(&env);env =restore();save(argl);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|pproc|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|env|"));argl = cons(object_copy(val),empty);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch645;}cont.cont = &&after_call644;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch645:;object_free(&val);val = proc.proc(argl); after_call644:;object_free(&argl);argl =restore();argl = cons(object_copy(val), argl);object_free(&proc);proc =restore();object_free(&cont);cont =restore();if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch647;}object_free(&val);
                    val = compiled_procedure_entry(proc);
                    goto *val.cont;primitive_branch647:;object_free(&val);val = proc.proc(argl); goto *cont.cont;after_lambda634:;save(cont);save(proc);save(env);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|map|"));save(proc);save(env);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|operands|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|exp|"));argl = cons(object_copy(val),empty);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch627;}cont.cont = &&after_call626;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch627:;object_free(&val);val = proc.proc(argl); after_call626:;argl = cons(object_copy(val),empty);object_free(&env);env =restore();object_free(&val);val = lookup_var_val(c_str_to_datum("|analyze|"));argl = cons(object_copy(val), argl);object_free(&proc);proc =restore();if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch629;}cont.cont = &&after_call628;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch629:;object_free(&val);val = proc.proc(argl); after_call628:;argl = cons(object_copy(val),empty);object_free(&env);env =restore();save(argl);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|analyze|"));save(proc);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|operator|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|exp|"));argl = cons(object_copy(val),empty);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch631;}cont.cont = &&after_call630;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch631:;object_free(&val);val = proc.proc(argl); after_call630:;argl = cons(object_copy(val),empty);object_free(&proc);proc =restore();if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch633;}cont.cont = &&after_call632;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch633:;object_free(&val);val = proc.proc(argl); after_call632:;object_free(&argl);argl =restore();argl = cons(object_copy(val), argl);object_free(&proc);proc =restore();object_free(&cont);cont =restore();if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch649;}object_free(&val);
                    val = compiled_procedure_entry(proc);
                    goto *val.cont;primitive_branch649:;object_free(&val);val = proc.proc(argl); goto *cont.cont;after_lambda624:;{Object t = def_var_val(c_str_to_datum("|analyze-application|"));
                                   object_free(&val);val = t;}object_free(&val);val = make_compiled_procedure(&&entry598);goto after_lambda597;entry598:env = compiled_procedure_env();
                          env = extend_environment(c_str_to_datum("(|proc| . (|args| . ()))"));save(cont);save(env);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|primitive-procedure?|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|proc|"));argl = cons(object_copy(val),empty);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch623;}cont.cont = &&after_call622;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch623:;object_free(&val);val = proc.proc(argl); after_call622:;object_free(&env);env =restore();object_free(&cont);cont =restore();if(val.type==BOOLEAN && !val.boolean){
                        goto false_branch600;}object_free(&proc);proc = lookup_var_val(c_str_to_datum("|c-apply|"));save(cont);save(proc);object_free(&val);val = lookup_var_val(c_str_to_datum("|args|"));argl = cons(object_copy(val),empty);save(argl);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|primitive-implementation|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|proc|"));argl = cons(object_copy(val),empty);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch619;}cont.cont = &&after_call618;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch619:;object_free(&val);val = proc.proc(argl); after_call618:;object_free(&argl);argl =restore();argl = cons(object_copy(val), argl);object_free(&proc);proc =restore();object_free(&cont);cont =restore();if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch621;}object_free(&val);
                    val = compiled_procedure_entry(proc);
                    goto *val.cont;primitive_branch621:;object_free(&val);val = proc.proc(argl); goto *cont.cont;false_branch600:;save(cont);save(env);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|compound-procedure?|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|proc|"));argl = cons(object_copy(val),empty);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch617;}cont.cont = &&after_call616;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch617:;object_free(&val);val = proc.proc(argl); after_call616:;object_free(&env);env =restore();object_free(&cont);cont =restore();if(val.type==BOOLEAN && !val.boolean){
                        goto false_branch602;}save(cont);save(env);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|procedure-body|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|proc|"));argl = cons(object_copy(val),empty);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch612;}cont.cont = &&proc_return613;
                        object_free(&val);
                        val = compiled_procedure_entry(proc);
                        goto *val.cont;proc_return613:
                        object_free(&proc);proc = val; val.type = NONE;
                        goto after_call611;primitive_branch612:;object_free(&proc);proc = proc.proc(argl); after_call611:;object_free(&env);env =restore();object_free(&cont);cont =restore();save(cont);save(proc);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|extend-environment|"));save(proc);save(env);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|procedure-environment|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|proc|"));argl = cons(object_copy(val),empty);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch606;}cont.cont = &&after_call605;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch606:;object_free(&val);val = proc.proc(argl); after_call605:;argl = cons(object_copy(val),empty);object_free(&env);env =restore();object_free(&val);val = lookup_var_val(c_str_to_datum("|args|"));argl = cons(object_copy(val), argl);save(argl);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|procedure-parameters|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|proc|"));argl = cons(object_copy(val),empty);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch608;}cont.cont = &&after_call607;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch608:;object_free(&val);val = proc.proc(argl); after_call607:;object_free(&argl);argl =restore();argl = cons(object_copy(val), argl);object_free(&proc);proc =restore();if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch610;}cont.cont = &&after_call609;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch610:;object_free(&val);val = proc.proc(argl); after_call609:;argl = cons(object_copy(val),empty);object_free(&proc);proc =restore();object_free(&cont);cont =restore();if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch615;}object_free(&val);
                    val = compiled_procedure_entry(proc);
                    goto *val.cont;primitive_branch615:;object_free(&val);val = proc.proc(argl); goto *cont.cont;false_branch602:;object_free(&proc);proc = lookup_var_val(c_str_to_datum("|error|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|proc|"));argl = cons(object_copy(val),empty);object_free(&val);val = c_str_to_datum("\"unknown procedure type -- execute-application\"");argl = cons(object_copy(val), argl);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch604;}object_free(&val);
                    val = compiled_procedure_entry(proc);
                    goto *val.cont;primitive_branch604:;object_free(&val);val = proc.proc(argl); goto *cont.cont;after_lambda597:;{Object t = def_var_val(c_str_to_datum("|execute-application|"));
                                   object_free(&val);val = t;}object_free(&val);val = make_compiled_procedure(&&entry544);goto after_lambda543;entry544:env = compiled_procedure_env();
                          env = extend_environment(c_str_to_datum("(|exp| . ())"));save(cont);save(env);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|boolean?|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|exp|"));argl = cons(object_copy(val),empty);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch596;}cont.cont = &&after_call595;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch596:;object_free(&val);val = proc.proc(argl); after_call595:;object_free(&env);env =restore();object_free(&cont);cont =restore();if(val.type==BOOLEAN && !val.boolean){
                        goto false_branch546;}object_free(&proc);proc = lookup_var_val(c_str_to_datum("|boolean?|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|exp|"));argl = cons(object_copy(val),empty);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch594;}object_free(&val);
                    val = compiled_procedure_entry(proc);
                    goto *val.cont;primitive_branch594:;object_free(&val);val = proc.proc(argl); goto *cont.cont;false_branch546:;save(cont);save(env);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|number?|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|exp|"));argl = cons(object_copy(val),empty);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch592;}cont.cont = &&after_call591;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch592:;object_free(&val);val = proc.proc(argl); after_call591:;object_free(&env);env =restore();object_free(&cont);cont =restore();if(val.type==BOOLEAN && !val.boolean){
                        goto false_branch548;}object_free(&proc);proc = lookup_var_val(c_str_to_datum("|number?|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|exp|"));argl = cons(object_copy(val),empty);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch590;}object_free(&val);
                    val = compiled_procedure_entry(proc);
                    goto *val.cont;primitive_branch590:;object_free(&val);val = proc.proc(argl); goto *cont.cont;false_branch548:;save(cont);save(env);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|vector?|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|exp|"));argl = cons(object_copy(val),empty);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch588;}cont.cont = &&after_call587;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch588:;object_free(&val);val = proc.proc(argl); after_call587:;object_free(&env);env =restore();object_free(&cont);cont =restore();if(val.type==BOOLEAN && !val.boolean){
                        goto false_branch550;}object_free(&proc);proc = lookup_var_val(c_str_to_datum("|vector?|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|exp|"));argl = cons(object_copy(val),empty);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch586;}object_free(&val);
                    val = compiled_procedure_entry(proc);
                    goto *val.cont;primitive_branch586:;object_free(&val);val = proc.proc(argl); goto *cont.cont;false_branch550:;save(cont);save(env);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|char?|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|exp|"));argl = cons(object_copy(val),empty);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch584;}cont.cont = &&after_call583;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch584:;object_free(&val);val = proc.proc(argl); after_call583:;object_free(&env);env =restore();object_free(&cont);cont =restore();if(val.type==BOOLEAN && !val.boolean){
                        goto false_branch552;}object_free(&proc);proc = lookup_var_val(c_str_to_datum("|char?|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|exp|"));argl = cons(object_copy(val),empty);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch582;}object_free(&val);
                    val = compiled_procedure_entry(proc);
                    goto *val.cont;primitive_branch582:;object_free(&val);val = proc.proc(argl); goto *cont.cont;false_branch552:;save(cont);save(env);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|string?|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|exp|"));argl = cons(object_copy(val),empty);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch580;}cont.cont = &&after_call579;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch580:;object_free(&val);val = proc.proc(argl); after_call579:;object_free(&env);env =restore();object_free(&cont);cont =restore();if(val.type==BOOLEAN && !val.boolean){
                        goto false_branch554;}object_free(&proc);proc = lookup_var_val(c_str_to_datum("|string?|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|exp|"));argl = cons(object_copy(val),empty);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch578;}object_free(&val);
                    val = compiled_procedure_entry(proc);
                    goto *val.cont;primitive_branch578:;object_free(&val);val = proc.proc(argl); goto *cont.cont;false_branch554:;save(cont);save(env);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|bytevector?|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|exp|"));argl = cons(object_copy(val),empty);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch576;}cont.cont = &&after_call575;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch576:;object_free(&val);val = proc.proc(argl); after_call575:;object_free(&env);env =restore();object_free(&cont);cont =restore();if(val.type==BOOLEAN && !val.boolean){
                        goto false_branch556;}object_free(&proc);proc = lookup_var_val(c_str_to_datum("|bytevector?|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|exp|"));argl = cons(object_copy(val),empty);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch574;}object_free(&val);
                    val = compiled_procedure_entry(proc);
                    goto *val.cont;primitive_branch574:;object_free(&val);val = proc.proc(argl); goto *cont.cont;false_branch556:;save(cont);save(env);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|procedure?|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|exp|"));argl = cons(object_copy(val),empty);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch572;}cont.cont = &&after_call571;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch572:;object_free(&val);val = proc.proc(argl); after_call571:;object_free(&env);env =restore();object_free(&cont);cont =restore();if(val.type==BOOLEAN && !val.boolean){
                        goto false_branch558;}object_free(&proc);proc = lookup_var_val(c_str_to_datum("|procedure?|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|exp|"));argl = cons(object_copy(val),empty);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch570;}object_free(&val);
                    val = compiled_procedure_entry(proc);
                    goto *val.cont;primitive_branch570:;object_free(&val);val = proc.proc(argl); goto *cont.cont;false_branch558:;save(cont);save(env);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|eq?|"));object_free(&val);val = c_str_to_datum("#false");if(val.type==BOOLEAN && !val.boolean){
                        goto false_branch566;}object_free(&val);val = c_str_to_datum("()");goto after_if565;false_branch566:;object_free(&val);val = undef;after_if565:;argl = cons(object_copy(val),empty);object_free(&val);val = lookup_var_val(c_str_to_datum("|exp|"));argl = cons(object_copy(val), argl);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch568;}cont.cont = &&after_call567;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch568:;object_free(&val);val = proc.proc(argl); after_call567:;object_free(&env);env =restore();object_free(&cont);cont =restore();if(val.type==BOOLEAN && !val.boolean){
                        goto false_branch560;}object_free(&proc);proc = lookup_var_val(c_str_to_datum("|eq?|"));object_free(&val);val = c_str_to_datum("#false");if(val.type==BOOLEAN && !val.boolean){
                        goto false_branch562;}object_free(&val);val = c_str_to_datum("()");goto after_if561;false_branch562:;object_free(&val);val = undef;after_if561:;argl = cons(object_copy(val),empty);object_free(&val);val = lookup_var_val(c_str_to_datum("|exp|"));argl = cons(object_copy(val), argl);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch564;}object_free(&val);
                    val = compiled_procedure_entry(proc);
                    goto *val.cont;primitive_branch564:;object_free(&val);val = proc.proc(argl); goto *cont.cont;false_branch560:;object_free(&val);val = c_str_to_datum("#false");goto *cont.cont;after_lambda543:;{Object t = def_var_val(c_str_to_datum("|self-evaluating?|"));
                                   object_free(&val);val = t;}object_free(&val);val = make_compiled_procedure(&&entry540);goto after_lambda539;entry540:env = compiled_procedure_env();
                          env = extend_environment(c_str_to_datum("(|exp| . ())"));object_free(&proc);proc = lookup_var_val(c_str_to_datum("|symbol?|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|exp|"));argl = cons(object_copy(val),empty);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch542;}object_free(&val);
                    val = compiled_procedure_entry(proc);
                    goto *val.cont;primitive_branch542:;object_free(&val);val = proc.proc(argl); goto *cont.cont;after_lambda539:;{Object t = def_var_val(c_str_to_datum("|variable?|"));
                                   object_free(&val);val = t;}object_free(&val);val = make_compiled_procedure(&&entry536);goto after_lambda535;entry536:env = compiled_procedure_env();
                          env = extend_environment(c_str_to_datum("(|exp| . ())"));object_free(&proc);proc = lookup_var_val(c_str_to_datum("|tagged-list?|"));object_free(&val);val = c_str_to_datum("|quote|");argl = cons(object_copy(val),empty);object_free(&val);val = lookup_var_val(c_str_to_datum("|exp|"));argl = cons(object_copy(val), argl);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch538;}object_free(&val);
                    val = compiled_procedure_entry(proc);
                    goto *val.cont;primitive_branch538:;object_free(&val);val = proc.proc(argl); goto *cont.cont;after_lambda535:;{Object t = def_var_val(c_str_to_datum("|quoted?|"));
                                   object_free(&val);val = t;}object_free(&val);val = make_compiled_procedure(&&entry530);goto after_lambda529;entry530:env = compiled_procedure_env();
                          env = extend_environment(c_str_to_datum("(|exp| . ())"));object_free(&proc);proc = lookup_var_val(c_str_to_datum("|car|"));save(cont);save(proc);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|cdr|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|exp|"));argl = cons(object_copy(val),empty);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch532;}cont.cont = &&after_call531;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch532:;object_free(&val);val = proc.proc(argl); after_call531:;argl = cons(object_copy(val),empty);object_free(&proc);proc =restore();object_free(&cont);cont =restore();if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch534;}object_free(&val);
                    val = compiled_procedure_entry(proc);
                    goto *val.cont;primitive_branch534:;object_free(&val);val = proc.proc(argl); goto *cont.cont;after_lambda529:;{Object t = def_var_val(c_str_to_datum("|text-of-quotation|"));
                                   object_free(&val);val = t;}object_free(&val);val = make_compiled_procedure(&&entry520);goto after_lambda519;entry520:env = compiled_procedure_env();
                          env = extend_environment(c_str_to_datum("(|exp| . (|tag| . ()))"));save(cont);save(env);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|pair?|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|exp|"));argl = cons(object_copy(val),empty);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch528;}cont.cont = &&after_call527;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch528:;object_free(&val);val = proc.proc(argl); after_call527:;object_free(&env);env =restore();object_free(&cont);cont =restore();if(val.type==BOOLEAN && !val.boolean){
                        goto false_branch522;}object_free(&proc);proc = lookup_var_val(c_str_to_datum("|eq?|"));save(cont);save(proc);object_free(&val);val = lookup_var_val(c_str_to_datum("|tag|"));argl = cons(object_copy(val),empty);save(argl);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|car|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|exp|"));argl = cons(object_copy(val),empty);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch524;}cont.cont = &&after_call523;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch524:;object_free(&val);val = proc.proc(argl); after_call523:;object_free(&argl);argl =restore();argl = cons(object_copy(val), argl);object_free(&proc);proc =restore();object_free(&cont);cont =restore();if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch526;}object_free(&val);
                    val = compiled_procedure_entry(proc);
                    goto *val.cont;primitive_branch526:;object_free(&val);val = proc.proc(argl); goto *cont.cont;false_branch522:;object_free(&val);val = c_str_to_datum("#false");goto *cont.cont;after_lambda519:;{Object t = def_var_val(c_str_to_datum("|tagged-list?|"));
                                   object_free(&val);val = t;}object_free(&val);val = make_compiled_procedure(&&entry516);goto after_lambda515;entry516:env = compiled_procedure_env();
                          env = extend_environment(c_str_to_datum("(|exp| . ())"));object_free(&proc);proc = lookup_var_val(c_str_to_datum("|tagged-list?|"));object_free(&val);val = c_str_to_datum("|lambda|");argl = cons(object_copy(val),empty);object_free(&val);val = lookup_var_val(c_str_to_datum("|exp|"));argl = cons(object_copy(val), argl);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch518;}object_free(&val);
                    val = compiled_procedure_entry(proc);
                    goto *val.cont;primitive_branch518:;object_free(&val);val = proc.proc(argl); goto *cont.cont;after_lambda515:;{Object t = def_var_val(c_str_to_datum("|lambda?|"));
                                   object_free(&val);val = t;}object_free(&val);val = make_compiled_procedure(&&entry510);goto after_lambda509;entry510:env = compiled_procedure_env();
                          env = extend_environment(c_str_to_datum("(|exp| . ())"));object_free(&proc);proc = lookup_var_val(c_str_to_datum("|car|"));save(cont);save(proc);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|cdr|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|exp|"));argl = cons(object_copy(val),empty);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch512;}cont.cont = &&after_call511;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch512:;object_free(&val);val = proc.proc(argl); after_call511:;argl = cons(object_copy(val),empty);object_free(&proc);proc =restore();object_free(&cont);cont =restore();if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch514;}object_free(&val);
                    val = compiled_procedure_entry(proc);
                    goto *val.cont;primitive_branch514:;object_free(&val);val = proc.proc(argl); goto *cont.cont;after_lambda509:;{Object t = def_var_val(c_str_to_datum("|lambda-parameters|"));
                                   object_free(&val);val = t;}object_free(&val);val = make_compiled_procedure(&&entry504);goto after_lambda503;entry504:env = compiled_procedure_env();
                          env = extend_environment(c_str_to_datum("(|exp| . ())"));object_free(&proc);proc = lookup_var_val(c_str_to_datum("|cdr|"));save(cont);save(proc);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|cdr|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|exp|"));argl = cons(object_copy(val),empty);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch506;}cont.cont = &&after_call505;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch506:;object_free(&val);val = proc.proc(argl); after_call505:;argl = cons(object_copy(val),empty);object_free(&proc);proc =restore();object_free(&cont);cont =restore();if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch508;}object_free(&val);
                    val = compiled_procedure_entry(proc);
                    goto *val.cont;primitive_branch508:;object_free(&val);val = proc.proc(argl); goto *cont.cont;after_lambda503:;{Object t = def_var_val(c_str_to_datum("|lambda-body|"));
                                   object_free(&val);val = t;}object_free(&val);val = make_compiled_procedure(&&entry498);goto after_lambda497;entry498:env = compiled_procedure_env();
                          env = extend_environment(c_str_to_datum("(|parameters| . (|body| . ()))"));object_free(&proc);proc = lookup_var_val(c_str_to_datum("|cons|"));save(cont);save(proc);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|cons|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|body|"));argl = cons(object_copy(val),empty);object_free(&val);val = lookup_var_val(c_str_to_datum("|parameters|"));argl = cons(object_copy(val), argl);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch500;}cont.cont = &&after_call499;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch500:;object_free(&val);val = proc.proc(argl); after_call499:;argl = cons(object_copy(val),empty);object_free(&val);val = c_str_to_datum("|lambda|");argl = cons(object_copy(val), argl);object_free(&proc);proc =restore();object_free(&cont);cont =restore();if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch502;}object_free(&val);
                    val = compiled_procedure_entry(proc);
                    goto *val.cont;primitive_branch502:;object_free(&val);val = proc.proc(argl); goto *cont.cont;after_lambda497:;{Object t = def_var_val(c_str_to_datum("|make-lambda|"));
                                   object_free(&val);val = t;}object_free(&val);val = make_compiled_procedure(&&entry494);goto after_lambda493;entry494:env = compiled_procedure_env();
                          env = extend_environment(c_str_to_datum("(|exp| . ())"));object_free(&proc);proc = lookup_var_val(c_str_to_datum("|tagged-list?|"));object_free(&val);val = c_str_to_datum("|if|");argl = cons(object_copy(val),empty);object_free(&val);val = lookup_var_val(c_str_to_datum("|exp|"));argl = cons(object_copy(val), argl);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch496;}object_free(&val);
                    val = compiled_procedure_entry(proc);
                    goto *val.cont;primitive_branch496:;object_free(&val);val = proc.proc(argl); goto *cont.cont;after_lambda493:;{Object t = def_var_val(c_str_to_datum("|if?|"));
                                   object_free(&val);val = t;}object_free(&val);val = make_compiled_procedure(&&entry488);goto after_lambda487;entry488:env = compiled_procedure_env();
                          env = extend_environment(c_str_to_datum("(|exp| . ())"));object_free(&proc);proc = lookup_var_val(c_str_to_datum("|car|"));save(cont);save(proc);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|cdr|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|exp|"));argl = cons(object_copy(val),empty);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch490;}cont.cont = &&after_call489;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch490:;object_free(&val);val = proc.proc(argl); after_call489:;argl = cons(object_copy(val),empty);object_free(&proc);proc =restore();object_free(&cont);cont =restore();if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch492;}object_free(&val);
                    val = compiled_procedure_entry(proc);
                    goto *val.cont;primitive_branch492:;object_free(&val);val = proc.proc(argl); goto *cont.cont;after_lambda487:;{Object t = def_var_val(c_str_to_datum("|if-predicate|"));
                                   object_free(&val);val = t;}object_free(&val);val = make_compiled_procedure(&&entry480);goto after_lambda479;entry480:env = compiled_procedure_env();
                          env = extend_environment(c_str_to_datum("(|exp| . ())"));object_free(&proc);proc = lookup_var_val(c_str_to_datum("|car|"));save(cont);save(proc);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|cdr|"));save(proc);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|cdr|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|exp|"));argl = cons(object_copy(val),empty);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch482;}cont.cont = &&after_call481;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch482:;object_free(&val);val = proc.proc(argl); after_call481:;argl = cons(object_copy(val),empty);object_free(&proc);proc =restore();if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch484;}cont.cont = &&after_call483;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch484:;object_free(&val);val = proc.proc(argl); after_call483:;argl = cons(object_copy(val),empty);object_free(&proc);proc =restore();object_free(&cont);cont =restore();if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch486;}object_free(&val);
                    val = compiled_procedure_entry(proc);
                    goto *val.cont;primitive_branch486:;object_free(&val);val = proc.proc(argl); goto *cont.cont;after_lambda479:;{Object t = def_var_val(c_str_to_datum("|if-consequent|"));
                                   object_free(&val);val = t;}object_free(&val);val = make_compiled_procedure(&&entry458);goto after_lambda457;entry458:env = compiled_procedure_env();
                          env = extend_environment(c_str_to_datum("(|exp| . ())"));save(cont);save(env);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|not|"));save(proc);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|null?|"));save(proc);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|cdr|"));save(proc);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|cdr|"));save(proc);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|cdr|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|exp|"));argl = cons(object_copy(val),empty);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch470;}cont.cont = &&after_call469;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch470:;object_free(&val);val = proc.proc(argl); after_call469:;argl = cons(object_copy(val),empty);object_free(&proc);proc =restore();if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch472;}cont.cont = &&after_call471;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch472:;object_free(&val);val = proc.proc(argl); after_call471:;argl = cons(object_copy(val),empty);object_free(&proc);proc =restore();if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch474;}cont.cont = &&after_call473;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch474:;object_free(&val);val = proc.proc(argl); after_call473:;argl = cons(object_copy(val),empty);object_free(&proc);proc =restore();if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch476;}cont.cont = &&after_call475;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch476:;object_free(&val);val = proc.proc(argl); after_call475:;argl = cons(object_copy(val),empty);object_free(&proc);proc =restore();if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch478;}cont.cont = &&after_call477;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch478:;object_free(&val);val = proc.proc(argl); after_call477:;object_free(&env);env =restore();object_free(&cont);cont =restore();if(val.type==BOOLEAN && !val.boolean){
                        goto false_branch460;}object_free(&proc);proc = lookup_var_val(c_str_to_datum("|car|"));save(cont);save(proc);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|cdr|"));save(proc);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|cdr|"));save(proc);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|cdr|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|exp|"));argl = cons(object_copy(val),empty);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch462;}cont.cont = &&after_call461;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch462:;object_free(&val);val = proc.proc(argl); after_call461:;argl = cons(object_copy(val),empty);object_free(&proc);proc =restore();if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch464;}cont.cont = &&after_call463;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch464:;object_free(&val);val = proc.proc(argl); after_call463:;argl = cons(object_copy(val),empty);object_free(&proc);proc =restore();if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch466;}cont.cont = &&after_call465;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch466:;object_free(&val);val = proc.proc(argl); after_call465:;argl = cons(object_copy(val),empty);object_free(&proc);proc =restore();object_free(&cont);cont =restore();if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch468;}object_free(&val);
                    val = compiled_procedure_entry(proc);
                    goto *val.cont;primitive_branch468:;object_free(&val);val = proc.proc(argl); goto *cont.cont;false_branch460:;object_free(&val);val = undef;goto *cont.cont;after_lambda457:;{Object t = def_var_val(c_str_to_datum("|if-alternative|"));
                                   object_free(&val);val = t;}object_free(&val);val = make_compiled_procedure(&&entry454);goto after_lambda453;entry454:env = compiled_procedure_env();
                          env = extend_environment(c_str_to_datum("(|exp| . ())"));object_free(&proc);proc = lookup_var_val(c_str_to_datum("|tagged-list?|"));object_free(&val);val = c_str_to_datum("|begin|");argl = cons(object_copy(val),empty);object_free(&val);val = lookup_var_val(c_str_to_datum("|exp|"));argl = cons(object_copy(val), argl);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch456;}object_free(&val);
                    val = compiled_procedure_entry(proc);
                    goto *val.cont;primitive_branch456:;object_free(&val);val = proc.proc(argl); goto *cont.cont;after_lambda453:;{Object t = def_var_val(c_str_to_datum("|begin?|"));
                                   object_free(&val);val = t;}object_free(&val);val = make_compiled_procedure(&&entry450);goto after_lambda449;entry450:env = compiled_procedure_env();
                          env = extend_environment(c_str_to_datum("(|exp| . ())"));object_free(&proc);proc = lookup_var_val(c_str_to_datum("|cdr|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|exp|"));argl = cons(object_copy(val),empty);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch452;}object_free(&val);
                    val = compiled_procedure_entry(proc);
                    goto *val.cont;primitive_branch452:;object_free(&val);val = proc.proc(argl); goto *cont.cont;after_lambda449:;{Object t = def_var_val(c_str_to_datum("|begin-actions|"));
                                   object_free(&val);val = t;}object_free(&val);val = make_compiled_procedure(&&entry446);goto after_lambda445;entry446:env = compiled_procedure_env();
                          env = extend_environment(c_str_to_datum("(|exp| . ())"));object_free(&proc);proc = lookup_var_val(c_str_to_datum("|pair?|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|exp|"));argl = cons(object_copy(val),empty);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch448;}object_free(&val);
                    val = compiled_procedure_entry(proc);
                    goto *val.cont;primitive_branch448:;object_free(&val);val = proc.proc(argl); goto *cont.cont;after_lambda445:;{Object t = def_var_val(c_str_to_datum("|application?|"));
                                   object_free(&val);val = t;}object_free(&val);val = make_compiled_procedure(&&entry442);goto after_lambda441;entry442:env = compiled_procedure_env();
                          env = extend_environment(c_str_to_datum("(|exp| . ())"));object_free(&proc);proc = lookup_var_val(c_str_to_datum("|car|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|exp|"));argl = cons(object_copy(val),empty);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch444;}object_free(&val);
                    val = compiled_procedure_entry(proc);
                    goto *val.cont;primitive_branch444:;object_free(&val);val = proc.proc(argl); goto *cont.cont;after_lambda441:;{Object t = def_var_val(c_str_to_datum("|operator|"));
                                   object_free(&val);val = t;}object_free(&val);val = make_compiled_procedure(&&entry438);goto after_lambda437;entry438:env = compiled_procedure_env();
                          env = extend_environment(c_str_to_datum("(|exp| . ())"));object_free(&proc);proc = lookup_var_val(c_str_to_datum("|cdr|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|exp|"));argl = cons(object_copy(val),empty);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch440;}object_free(&val);
                    val = compiled_procedure_entry(proc);
                    goto *val.cont;primitive_branch440:;object_free(&val);val = proc.proc(argl); goto *cont.cont;after_lambda437:;{Object t = def_var_val(c_str_to_datum("|operands|"));
                                   object_free(&val);val = t;}object_free(&val);val = make_compiled_procedure(&&entry434);goto after_lambda433;entry434:env = compiled_procedure_env();
                          env = extend_environment(c_str_to_datum("(|exp| . ())"));object_free(&proc);proc = lookup_var_val(c_str_to_datum("|tagged-list?|"));object_free(&val);val = c_str_to_datum("|define|");argl = cons(object_copy(val),empty);object_free(&val);val = lookup_var_val(c_str_to_datum("|exp|"));argl = cons(object_copy(val), argl);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch436;}object_free(&val);
                    val = compiled_procedure_entry(proc);
                    goto *val.cont;primitive_branch436:;object_free(&val);val = proc.proc(argl); goto *cont.cont;after_lambda433:;{Object t = def_var_val(c_str_to_datum("|definition?|"));
                                   object_free(&val);val = t;}object_free(&val);val = make_compiled_procedure(&&entry414);goto after_lambda413;entry414:env = compiled_procedure_env();
                          env = extend_environment(c_str_to_datum("(|exp| . ())"));save(cont);save(env);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|symbol?|"));save(proc);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|car|"));save(proc);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|cdr|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|exp|"));argl = cons(object_copy(val),empty);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch428;}cont.cont = &&after_call427;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch428:;object_free(&val);val = proc.proc(argl); after_call427:;argl = cons(object_copy(val),empty);object_free(&proc);proc =restore();if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch430;}cont.cont = &&after_call429;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch430:;object_free(&val);val = proc.proc(argl); after_call429:;argl = cons(object_copy(val),empty);object_free(&proc);proc =restore();if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch432;}cont.cont = &&after_call431;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch432:;object_free(&val);val = proc.proc(argl); after_call431:;object_free(&env);env =restore();object_free(&cont);cont =restore();if(val.type==BOOLEAN && !val.boolean){
                        goto false_branch416;}object_free(&proc);proc = lookup_var_val(c_str_to_datum("|car|"));save(cont);save(proc);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|cdr|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|exp|"));argl = cons(object_copy(val),empty);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch424;}cont.cont = &&after_call423;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch424:;object_free(&val);val = proc.proc(argl); after_call423:;argl = cons(object_copy(val),empty);object_free(&proc);proc =restore();object_free(&cont);cont =restore();if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch426;}object_free(&val);
                    val = compiled_procedure_entry(proc);
                    goto *val.cont;primitive_branch426:;object_free(&val);val = proc.proc(argl); goto *cont.cont;false_branch416:;object_free(&proc);proc = lookup_var_val(c_str_to_datum("|car|"));save(cont);save(proc);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|car|"));save(proc);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|cdr|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|exp|"));argl = cons(object_copy(val),empty);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch418;}cont.cont = &&after_call417;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch418:;object_free(&val);val = proc.proc(argl); after_call417:;argl = cons(object_copy(val),empty);object_free(&proc);proc =restore();if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch420;}cont.cont = &&after_call419;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch420:;object_free(&val);val = proc.proc(argl); after_call419:;argl = cons(object_copy(val),empty);object_free(&proc);proc =restore();object_free(&cont);cont =restore();if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch422;}object_free(&val);
                    val = compiled_procedure_entry(proc);
                    goto *val.cont;primitive_branch422:;object_free(&val);val = proc.proc(argl); goto *cont.cont;after_lambda413:;{Object t = def_var_val(c_str_to_datum("|definition-variable|"));
                                   object_free(&val);val = t;}object_free(&val);val = make_compiled_procedure(&&entry386);goto after_lambda385;entry386:env = compiled_procedure_env();
                          env = extend_environment(c_str_to_datum("(|exp| . ())"));save(cont);save(env);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|symbol?|"));save(proc);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|car|"));save(proc);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|cdr|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|exp|"));argl = cons(object_copy(val),empty);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch408;}cont.cont = &&after_call407;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch408:;object_free(&val);val = proc.proc(argl); after_call407:;argl = cons(object_copy(val),empty);object_free(&proc);proc =restore();if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch410;}cont.cont = &&after_call409;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch410:;object_free(&val);val = proc.proc(argl); after_call409:;argl = cons(object_copy(val),empty);object_free(&proc);proc =restore();if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch412;}cont.cont = &&after_call411;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch412:;object_free(&val);val = proc.proc(argl); after_call411:;object_free(&env);env =restore();object_free(&cont);cont =restore();if(val.type==BOOLEAN && !val.boolean){
                        goto false_branch388;}object_free(&proc);proc = lookup_var_val(c_str_to_datum("|car|"));save(cont);save(proc);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|cdr|"));save(proc);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|cdr|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|exp|"));argl = cons(object_copy(val),empty);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch402;}cont.cont = &&after_call401;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch402:;object_free(&val);val = proc.proc(argl); after_call401:;argl = cons(object_copy(val),empty);object_free(&proc);proc =restore();if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch404;}cont.cont = &&after_call403;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch404:;object_free(&val);val = proc.proc(argl); after_call403:;argl = cons(object_copy(val),empty);object_free(&proc);proc =restore();object_free(&cont);cont =restore();if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch406;}object_free(&val);
                    val = compiled_procedure_entry(proc);
                    goto *val.cont;primitive_branch406:;object_free(&val);val = proc.proc(argl); goto *cont.cont;false_branch388:;object_free(&proc);proc = lookup_var_val(c_str_to_datum("|make-lambda|"));save(cont);save(proc);save(env);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|cdr|"));save(proc);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|cdr|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|exp|"));argl = cons(object_copy(val),empty);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch390;}cont.cont = &&after_call389;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch390:;object_free(&val);val = proc.proc(argl); after_call389:;argl = cons(object_copy(val),empty);object_free(&proc);proc =restore();if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch392;}cont.cont = &&after_call391;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch392:;object_free(&val);val = proc.proc(argl); after_call391:;argl = cons(object_copy(val),empty);object_free(&env);env =restore();save(argl);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|cdr|"));save(proc);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|car|"));save(proc);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|cdr|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|exp|"));argl = cons(object_copy(val),empty);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch394;}cont.cont = &&after_call393;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch394:;object_free(&val);val = proc.proc(argl); after_call393:;argl = cons(object_copy(val),empty);object_free(&proc);proc =restore();if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch396;}cont.cont = &&after_call395;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch396:;object_free(&val);val = proc.proc(argl); after_call395:;argl = cons(object_copy(val),empty);object_free(&proc);proc =restore();if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch398;}cont.cont = &&after_call397;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch398:;object_free(&val);val = proc.proc(argl); after_call397:;object_free(&argl);argl =restore();argl = cons(object_copy(val), argl);object_free(&proc);proc =restore();object_free(&cont);cont =restore();if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch400;}object_free(&val);
                    val = compiled_procedure_entry(proc);
                    goto *val.cont;primitive_branch400:;object_free(&val);val = proc.proc(argl); goto *cont.cont;after_lambda385:;{Object t = def_var_val(c_str_to_datum("|definition-value|"));
                                   object_free(&val);val = t;}object_free(&val);val = make_compiled_procedure(&&entry382);goto after_lambda381;entry382:env = compiled_procedure_env();
                          env = extend_environment(c_str_to_datum("(|exp| . ())"));object_free(&proc);proc = lookup_var_val(c_str_to_datum("|tagged-list?|"));object_free(&val);val = c_str_to_datum("|set!|");argl = cons(object_copy(val),empty);object_free(&val);val = lookup_var_val(c_str_to_datum("|exp|"));argl = cons(object_copy(val), argl);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch384;}object_free(&val);
                    val = compiled_procedure_entry(proc);
                    goto *val.cont;primitive_branch384:;object_free(&val);val = proc.proc(argl); goto *cont.cont;after_lambda381:;{Object t = def_var_val(c_str_to_datum("|assignment?|"));
                                   object_free(&val);val = t;}object_free(&val);val = make_compiled_procedure(&&entry376);goto after_lambda375;entry376:env = compiled_procedure_env();
                          env = extend_environment(c_str_to_datum("(|exp| . ())"));object_free(&proc);proc = lookup_var_val(c_str_to_datum("|car|"));save(cont);save(proc);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|cdr|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|exp|"));argl = cons(object_copy(val),empty);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch378;}cont.cont = &&after_call377;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch378:;object_free(&val);val = proc.proc(argl); after_call377:;argl = cons(object_copy(val),empty);object_free(&proc);proc =restore();object_free(&cont);cont =restore();if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch380;}object_free(&val);
                    val = compiled_procedure_entry(proc);
                    goto *val.cont;primitive_branch380:;object_free(&val);val = proc.proc(argl); goto *cont.cont;after_lambda375:;{Object t = def_var_val(c_str_to_datum("|assignment-variable|"));
                                   object_free(&val);val = t;}object_free(&val);val = make_compiled_procedure(&&entry368);goto after_lambda367;entry368:env = compiled_procedure_env();
                          env = extend_environment(c_str_to_datum("(|exp| . ())"));object_free(&proc);proc = lookup_var_val(c_str_to_datum("|car|"));save(cont);save(proc);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|cdr|"));save(proc);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|cdr|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|exp|"));argl = cons(object_copy(val),empty);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch370;}cont.cont = &&after_call369;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch370:;object_free(&val);val = proc.proc(argl); after_call369:;argl = cons(object_copy(val),empty);object_free(&proc);proc =restore();if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch372;}cont.cont = &&after_call371;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch372:;object_free(&val);val = proc.proc(argl); after_call371:;argl = cons(object_copy(val),empty);object_free(&proc);proc =restore();object_free(&cont);cont =restore();if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch374;}object_free(&val);
                    val = compiled_procedure_entry(proc);
                    goto *val.cont;primitive_branch374:;object_free(&val);val = proc.proc(argl); goto *cont.cont;after_lambda367:;{Object t = def_var_val(c_str_to_datum("|assignment-value|"));
                                   object_free(&val);val = t;}object_free(&val);val = make_compiled_procedure(&&entry364);goto after_lambda363;entry364:env = compiled_procedure_env();
                          env = extend_environment(c_str_to_datum("(|env| . ())"));object_free(&proc);proc = lookup_var_val(c_str_to_datum("|car|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|env|"));argl = cons(object_copy(val),empty);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch366;}object_free(&val);
                    val = compiled_procedure_entry(proc);
                    goto *val.cont;primitive_branch366:;object_free(&val);val = proc.proc(argl); goto *cont.cont;after_lambda363:;{Object t = def_var_val(c_str_to_datum("|first-frame|"));
                                   object_free(&val);val = t;}object_free(&val);val = c_str_to_datum("()");{Object t = def_var_val(c_str_to_datum("|the-empty-environment|"));
                                   object_free(&val);val = t;}object_free(&val);val = make_compiled_procedure(&&entry360);goto after_lambda359;entry360:env = compiled_procedure_env();
                          env = extend_environment(c_str_to_datum("(|variables| . (|values| . ()))"));object_free(&proc);proc = lookup_var_val(c_str_to_datum("|cons|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|values|"));argl = cons(object_copy(val),empty);object_free(&val);val = lookup_var_val(c_str_to_datum("|variables|"));argl = cons(object_copy(val), argl);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch362;}object_free(&val);
                    val = compiled_procedure_entry(proc);
                    goto *val.cont;primitive_branch362:;object_free(&val);val = proc.proc(argl); goto *cont.cont;after_lambda359:;{Object t = def_var_val(c_str_to_datum("|make-frame|"));
                                   object_free(&val);val = t;}object_free(&val);val = make_compiled_procedure(&&entry356);goto after_lambda355;entry356:env = compiled_procedure_env();
                          env = extend_environment(c_str_to_datum("(|frame| . ())"));object_free(&proc);proc = lookup_var_val(c_str_to_datum("|car|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|frame|"));argl = cons(object_copy(val),empty);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch358;}object_free(&val);
                    val = compiled_procedure_entry(proc);
                    goto *val.cont;primitive_branch358:;object_free(&val);val = proc.proc(argl); goto *cont.cont;after_lambda355:;{Object t = def_var_val(c_str_to_datum("|frame-variables|"));
                                   object_free(&val);val = t;}object_free(&val);val = make_compiled_procedure(&&entry352);goto after_lambda351;entry352:env = compiled_procedure_env();
                          env = extend_environment(c_str_to_datum("(|frame| . ())"));object_free(&proc);proc = lookup_var_val(c_str_to_datum("|cdr|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|frame|"));argl = cons(object_copy(val),empty);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch354;}object_free(&val);
                    val = compiled_procedure_entry(proc);
                    goto *val.cont;primitive_branch354:;object_free(&val);val = proc.proc(argl); goto *cont.cont;after_lambda351:;{Object t = def_var_val(c_str_to_datum("|frame-values|"));
                                   object_free(&val);val = t;}object_free(&val);val = make_compiled_procedure(&&entry338);goto after_lambda337;entry338:env = compiled_procedure_env();
                          env = extend_environment(c_str_to_datum("(|var| . (|val| . (|frame| . ())))"));save(cont);save(env);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|set-car!|"));save(proc);save(env);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|cons|"));save(proc);save(env);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|car|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|frame|"));argl = cons(object_copy(val),empty);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch346;}cont.cont = &&after_call345;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch346:;object_free(&val);val = proc.proc(argl); after_call345:;argl = cons(object_copy(val),empty);object_free(&env);env =restore();object_free(&val);val = lookup_var_val(c_str_to_datum("|var|"));argl = cons(object_copy(val), argl);object_free(&proc);proc =restore();if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch348;}cont.cont = &&after_call347;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch348:;object_free(&val);val = proc.proc(argl); after_call347:;argl = cons(object_copy(val),empty);object_free(&env);env =restore();object_free(&val);val = lookup_var_val(c_str_to_datum("|frame|"));argl = cons(object_copy(val), argl);object_free(&proc);proc =restore();if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch350;}cont.cont = &&after_call349;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch350:;object_free(&val);val = proc.proc(argl); after_call349:;object_free(&env);env =restore();object_free(&cont);cont =restore();object_free(&proc);proc = lookup_var_val(c_str_to_datum("|set-cdr!|"));save(cont);save(proc);save(env);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|cons|"));save(proc);save(env);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|cdr|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|frame|"));argl = cons(object_copy(val),empty);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch340;}cont.cont = &&after_call339;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch340:;object_free(&val);val = proc.proc(argl); after_call339:;argl = cons(object_copy(val),empty);object_free(&env);env =restore();object_free(&val);val = lookup_var_val(c_str_to_datum("|val|"));argl = cons(object_copy(val), argl);object_free(&proc);proc =restore();if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch342;}cont.cont = &&after_call341;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch342:;object_free(&val);val = proc.proc(argl); after_call341:;argl = cons(object_copy(val),empty);object_free(&env);env =restore();object_free(&val);val = lookup_var_val(c_str_to_datum("|frame|"));argl = cons(object_copy(val), argl);object_free(&proc);proc =restore();object_free(&cont);cont =restore();if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch344;}object_free(&val);
                    val = compiled_procedure_entry(proc);
                    goto *val.cont;primitive_branch344:;object_free(&val);val = proc.proc(argl); goto *cont.cont;after_lambda337:;{Object t = def_var_val(c_str_to_datum("|add-binding-to-frame!|"));
                                   object_free(&val);val = t;}object_free(&val);val = make_compiled_procedure(&&entry302);goto after_lambda301;entry302:env = compiled_procedure_env();
                          env = extend_environment(c_str_to_datum("(|var| . (|val| . (|env| . ())))"));object_free(&proc);proc = make_compiled_procedure(&&entry306);goto after_lambda305;entry306:env = compiled_procedure_env();
                          env = extend_environment(c_str_to_datum("(|frame| . ())"));object_free(&val);val = make_compiled_procedure(&&entry314);goto after_lambda313;entry314:env = compiled_procedure_env();
                          env = extend_environment(c_str_to_datum("(|vars| . (|vals| . ()))"));save(cont);save(env);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|null?|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|vars|"));argl = cons(object_copy(val),empty);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch334;}cont.cont = &&after_call333;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch334:;object_free(&val);val = proc.proc(argl); after_call333:;object_free(&env);env =restore();object_free(&cont);cont =restore();if(val.type==BOOLEAN && !val.boolean){
                        goto false_branch316;}object_free(&proc);proc = lookup_var_val(c_str_to_datum("|add-binding-to-frame!|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|frame|"));argl = cons(object_copy(val),empty);object_free(&val);val = lookup_var_val(c_str_to_datum("|val|"));argl = cons(object_copy(val), argl);object_free(&val);val = lookup_var_val(c_str_to_datum("|var|"));argl = cons(object_copy(val), argl);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch332;}object_free(&val);
                    val = compiled_procedure_entry(proc);
                    goto *val.cont;primitive_branch332:;object_free(&val);val = proc.proc(argl); goto *cont.cont;false_branch316:;save(cont);save(env);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|eq?|"));save(proc);save(env);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|car|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|vars|"));argl = cons(object_copy(val),empty);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch328;}cont.cont = &&after_call327;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch328:;object_free(&val);val = proc.proc(argl); after_call327:;argl = cons(object_copy(val),empty);object_free(&env);env =restore();object_free(&val);val = lookup_var_val(c_str_to_datum("|var|"));argl = cons(object_copy(val), argl);object_free(&proc);proc =restore();if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch330;}cont.cont = &&after_call329;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch330:;object_free(&val);val = proc.proc(argl); after_call329:;object_free(&env);env =restore();object_free(&cont);cont =restore();if(val.type==BOOLEAN && !val.boolean){
                        goto false_branch318;}object_free(&proc);proc = lookup_var_val(c_str_to_datum("|set-car!|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|val|"));argl = cons(object_copy(val),empty);object_free(&val);val = lookup_var_val(c_str_to_datum("|vals|"));argl = cons(object_copy(val), argl);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch326;}object_free(&val);
                    val = compiled_procedure_entry(proc);
                    goto *val.cont;primitive_branch326:;object_free(&val);val = proc.proc(argl); goto *cont.cont;false_branch318:;object_free(&proc);proc = lookup_var_val(c_str_to_datum("|scan|"));save(cont);save(proc);save(env);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|cdr|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|vals|"));argl = cons(object_copy(val),empty);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch320;}cont.cont = &&after_call319;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch320:;object_free(&val);val = proc.proc(argl); after_call319:;argl = cons(object_copy(val),empty);object_free(&env);env =restore();save(argl);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|cdr|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|vars|"));argl = cons(object_copy(val),empty);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch322;}cont.cont = &&after_call321;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch322:;object_free(&val);val = proc.proc(argl); after_call321:;object_free(&argl);argl =restore();argl = cons(object_copy(val), argl);object_free(&proc);proc =restore();object_free(&cont);cont =restore();if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch324;}object_free(&val);
                    val = compiled_procedure_entry(proc);
                    goto *val.cont;primitive_branch324:;object_free(&val);val = proc.proc(argl); goto *cont.cont;after_lambda313:;{Object t = def_var_val(c_str_to_datum("|scan|"));
                                   object_free(&val);val = t;}object_free(&proc);proc = lookup_var_val(c_str_to_datum("|scan|"));save(cont);save(proc);save(env);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|frame-values|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|frame|"));argl = cons(object_copy(val),empty);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch308;}cont.cont = &&after_call307;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch308:;object_free(&val);val = proc.proc(argl); after_call307:;argl = cons(object_copy(val),empty);object_free(&env);env =restore();save(argl);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|frame-variables|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|frame|"));argl = cons(object_copy(val),empty);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch310;}cont.cont = &&after_call309;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch310:;object_free(&val);val = proc.proc(argl); after_call309:;object_free(&argl);argl =restore();argl = cons(object_copy(val), argl);object_free(&proc);proc =restore();object_free(&cont);cont =restore();if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch312;}object_free(&val);
                    val = compiled_procedure_entry(proc);
                    goto *val.cont;primitive_branch312:;object_free(&val);val = proc.proc(argl); goto *cont.cont;after_lambda305:;save(cont);save(proc);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|first-frame|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|env|"));argl = cons(object_copy(val),empty);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch304;}cont.cont = &&after_call303;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch304:;object_free(&val);val = proc.proc(argl); after_call303:;argl = cons(object_copy(val),empty);object_free(&proc);proc =restore();object_free(&cont);cont =restore();if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch336;}object_free(&val);
                    val = compiled_procedure_entry(proc);
                    goto *val.cont;primitive_branch336:;object_free(&val);val = proc.proc(argl); goto *cont.cont;after_lambda301:;{Object t = def_var_val(c_str_to_datum("|define-variable!|"));
                                   object_free(&val);val = t;}object_free(&val);val = make_compiled_procedure(&&entry254);goto after_lambda253;entry254:env = compiled_procedure_env();
                          env = extend_environment(c_str_to_datum("(|var| . (|val| . (|env| . ())))"));object_free(&val);val = make_compiled_procedure(&&entry258);goto after_lambda257;entry258:env = compiled_procedure_env();
                          env = extend_environment(c_str_to_datum("(|env| . ())"));object_free(&val);val = make_compiled_procedure(&&entry278);goto after_lambda277;entry278:env = compiled_procedure_env();
                          env = extend_environment(c_str_to_datum("(|vars| . (|vals| . ()))"));save(cont);save(env);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|null?|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|vars|"));argl = cons(object_copy(val),empty);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch300;}cont.cont = &&after_call299;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch300:;object_free(&val);val = proc.proc(argl); after_call299:;object_free(&env);env =restore();object_free(&cont);cont =restore();if(val.type==BOOLEAN && !val.boolean){
                        goto false_branch280;}object_free(&proc);proc = lookup_var_val(c_str_to_datum("|env-loop|"));save(cont);save(proc);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|enclosing-environment|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|env|"));argl = cons(object_copy(val),empty);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch296;}cont.cont = &&after_call295;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch296:;object_free(&val);val = proc.proc(argl); after_call295:;argl = cons(object_copy(val),empty);object_free(&proc);proc =restore();object_free(&cont);cont =restore();if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch298;}object_free(&val);
                    val = compiled_procedure_entry(proc);
                    goto *val.cont;primitive_branch298:;object_free(&val);val = proc.proc(argl); goto *cont.cont;false_branch280:;save(cont);save(env);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|eq?|"));save(proc);save(env);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|car|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|vars|"));argl = cons(object_copy(val),empty);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch292;}cont.cont = &&after_call291;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch292:;object_free(&val);val = proc.proc(argl); after_call291:;argl = cons(object_copy(val),empty);object_free(&env);env =restore();object_free(&val);val = lookup_var_val(c_str_to_datum("|var|"));argl = cons(object_copy(val), argl);object_free(&proc);proc =restore();if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch294;}cont.cont = &&after_call293;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch294:;object_free(&val);val = proc.proc(argl); after_call293:;object_free(&env);env =restore();object_free(&cont);cont =restore();if(val.type==BOOLEAN && !val.boolean){
                        goto false_branch282;}object_free(&proc);proc = lookup_var_val(c_str_to_datum("|set-car!|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|val|"));argl = cons(object_copy(val),empty);object_free(&val);val = lookup_var_val(c_str_to_datum("|vals|"));argl = cons(object_copy(val), argl);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch290;}object_free(&val);
                    val = compiled_procedure_entry(proc);
                    goto *val.cont;primitive_branch290:;object_free(&val);val = proc.proc(argl); goto *cont.cont;false_branch282:;object_free(&proc);proc = lookup_var_val(c_str_to_datum("|scan|"));save(cont);save(proc);save(env);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|cdr|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|vals|"));argl = cons(object_copy(val),empty);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch284;}cont.cont = &&after_call283;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch284:;object_free(&val);val = proc.proc(argl); after_call283:;argl = cons(object_copy(val),empty);object_free(&env);env =restore();save(argl);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|cdr|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|vars|"));argl = cons(object_copy(val),empty);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch286;}cont.cont = &&after_call285;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch286:;object_free(&val);val = proc.proc(argl); after_call285:;object_free(&argl);argl =restore();argl = cons(object_copy(val), argl);object_free(&proc);proc =restore();object_free(&cont);cont =restore();if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch288;}object_free(&val);
                    val = compiled_procedure_entry(proc);
                    goto *val.cont;primitive_branch288:;object_free(&val);val = proc.proc(argl); goto *cont.cont;after_lambda277:;{Object t = def_var_val(c_str_to_datum("|scan|"));
                                   object_free(&val);val = t;}save(cont);save(env);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|eq?|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|the-empty-environment|"));argl = cons(object_copy(val),empty);object_free(&val);val = lookup_var_val(c_str_to_datum("|env|"));argl = cons(object_copy(val), argl);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch276;}cont.cont = &&after_call275;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch276:;object_free(&val);val = proc.proc(argl); after_call275:;object_free(&env);env =restore();object_free(&cont);cont =restore();if(val.type==BOOLEAN && !val.boolean){
                        goto false_branch260;}object_free(&proc);proc = lookup_var_val(c_str_to_datum("|error|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|var|"));argl = cons(object_copy(val),empty);object_free(&val);val = c_str_to_datum("\"(set!) unbound variable --\"");argl = cons(object_copy(val), argl);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch274;}object_free(&val);
                    val = compiled_procedure_entry(proc);
                    goto *val.cont;primitive_branch274:;object_free(&val);val = proc.proc(argl); goto *cont.cont;false_branch260:;object_free(&proc);proc = make_compiled_procedure(&&entry264);goto after_lambda263;entry264:env = compiled_procedure_env();
                          env = extend_environment(c_str_to_datum("(|frame| . ())"));object_free(&proc);proc = lookup_var_val(c_str_to_datum("|scan|"));save(cont);save(proc);save(env);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|frame-values|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|frame|"));argl = cons(object_copy(val),empty);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch266;}cont.cont = &&after_call265;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch266:;object_free(&val);val = proc.proc(argl); after_call265:;argl = cons(object_copy(val),empty);object_free(&env);env =restore();save(argl);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|frame-variables|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|frame|"));argl = cons(object_copy(val),empty);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch268;}cont.cont = &&after_call267;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch268:;object_free(&val);val = proc.proc(argl); after_call267:;object_free(&argl);argl =restore();argl = cons(object_copy(val), argl);object_free(&proc);proc =restore();object_free(&cont);cont =restore();if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch270;}object_free(&val);
                    val = compiled_procedure_entry(proc);
                    goto *val.cont;primitive_branch270:;object_free(&val);val = proc.proc(argl); goto *cont.cont;after_lambda263:;save(cont);save(proc);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|first-frame|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|env|"));argl = cons(object_copy(val),empty);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch262;}cont.cont = &&after_call261;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch262:;object_free(&val);val = proc.proc(argl); after_call261:;argl = cons(object_copy(val),empty);object_free(&proc);proc =restore();object_free(&cont);cont =restore();if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch272;}object_free(&val);
                    val = compiled_procedure_entry(proc);
                    goto *val.cont;primitive_branch272:;object_free(&val);val = proc.proc(argl); goto *cont.cont;after_lambda257:;{Object t = def_var_val(c_str_to_datum("|env-loop|"));
                                   object_free(&val);val = t;}object_free(&proc);proc = lookup_var_val(c_str_to_datum("|env-loop|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|env|"));argl = cons(object_copy(val),empty);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch256;}object_free(&val);
                    val = compiled_procedure_entry(proc);
                    goto *val.cont;primitive_branch256:;object_free(&val);val = proc.proc(argl); goto *cont.cont;after_lambda253:;{Object t = def_var_val(c_str_to_datum("|set-variable-value!|"));
                                   object_free(&val);val = t;}object_free(&val);val = make_compiled_procedure(&&entry250);goto after_lambda249;entry250:env = compiled_procedure_env();
                          env = extend_environment(c_str_to_datum("(|parameters| . (|body| . (|env| . ())))"));object_free(&proc);proc = lookup_var_val(c_str_to_datum("|list|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|env|"));argl = cons(object_copy(val),empty);object_free(&val);val = lookup_var_val(c_str_to_datum("|body|"));argl = cons(object_copy(val), argl);object_free(&val);val = lookup_var_val(c_str_to_datum("|parameters|"));argl = cons(object_copy(val), argl);object_free(&val);val = c_str_to_datum("|procedure|");argl = cons(object_copy(val), argl);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch252;}object_free(&val);
                    val = compiled_procedure_entry(proc);
                    goto *val.cont;primitive_branch252:;object_free(&val);val = proc.proc(argl); goto *cont.cont;after_lambda249:;{Object t = def_var_val(c_str_to_datum("|make-procedure|"));
                                   object_free(&val);val = t;}object_free(&val);val = make_compiled_procedure(&&entry246);goto after_lambda245;entry246:env = compiled_procedure_env();
                          env = extend_environment(c_str_to_datum("(|p| . ())"));object_free(&proc);proc = lookup_var_val(c_str_to_datum("|tagged-list?|"));object_free(&val);val = c_str_to_datum("|procedure|");argl = cons(object_copy(val),empty);object_free(&val);val = lookup_var_val(c_str_to_datum("|p|"));argl = cons(object_copy(val), argl);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch248;}object_free(&val);
                    val = compiled_procedure_entry(proc);
                    goto *val.cont;primitive_branch248:;object_free(&val);val = proc.proc(argl); goto *cont.cont;after_lambda245:;{Object t = def_var_val(c_str_to_datum("|compound-procedure?|"));
                                   object_free(&val);val = t;}object_free(&val);val = make_compiled_procedure(&&entry240);goto after_lambda239;entry240:env = compiled_procedure_env();
                          env = extend_environment(c_str_to_datum("(|p| . ())"));object_free(&proc);proc = lookup_var_val(c_str_to_datum("|car|"));save(cont);save(proc);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|cdr|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|p|"));argl = cons(object_copy(val),empty);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch242;}cont.cont = &&after_call241;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch242:;object_free(&val);val = proc.proc(argl); after_call241:;argl = cons(object_copy(val),empty);object_free(&proc);proc =restore();object_free(&cont);cont =restore();if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch244;}object_free(&val);
                    val = compiled_procedure_entry(proc);
                    goto *val.cont;primitive_branch244:;object_free(&val);val = proc.proc(argl); goto *cont.cont;after_lambda239:;{Object t = def_var_val(c_str_to_datum("|procedure-parameters|"));
                                   object_free(&val);val = t;}object_free(&val);val = make_compiled_procedure(&&entry232);goto after_lambda231;entry232:env = compiled_procedure_env();
                          env = extend_environment(c_str_to_datum("(|p| . ())"));object_free(&proc);proc = lookup_var_val(c_str_to_datum("|car|"));save(cont);save(proc);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|cdr|"));save(proc);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|cdr|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|p|"));argl = cons(object_copy(val),empty);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch234;}cont.cont = &&after_call233;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch234:;object_free(&val);val = proc.proc(argl); after_call233:;argl = cons(object_copy(val),empty);object_free(&proc);proc =restore();if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch236;}cont.cont = &&after_call235;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch236:;object_free(&val);val = proc.proc(argl); after_call235:;argl = cons(object_copy(val),empty);object_free(&proc);proc =restore();object_free(&cont);cont =restore();if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch238;}object_free(&val);
                    val = compiled_procedure_entry(proc);
                    goto *val.cont;primitive_branch238:;object_free(&val);val = proc.proc(argl); goto *cont.cont;after_lambda231:;{Object t = def_var_val(c_str_to_datum("|procedure-body|"));
                                   object_free(&val);val = t;}object_free(&val);val = make_compiled_procedure(&&entry222);goto after_lambda221;entry222:env = compiled_procedure_env();
                          env = extend_environment(c_str_to_datum("(|p| . ())"));object_free(&proc);proc = lookup_var_val(c_str_to_datum("|car|"));save(cont);save(proc);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|cdr|"));save(proc);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|cdr|"));save(proc);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|cdr|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|p|"));argl = cons(object_copy(val),empty);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch224;}cont.cont = &&after_call223;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch224:;object_free(&val);val = proc.proc(argl); after_call223:;argl = cons(object_copy(val),empty);object_free(&proc);proc =restore();if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch226;}cont.cont = &&after_call225;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch226:;object_free(&val);val = proc.proc(argl); after_call225:;argl = cons(object_copy(val),empty);object_free(&proc);proc =restore();if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch228;}cont.cont = &&after_call227;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch228:;object_free(&val);val = proc.proc(argl); after_call227:;argl = cons(object_copy(val),empty);object_free(&proc);proc =restore();object_free(&cont);cont =restore();if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch230;}object_free(&val);
                    val = compiled_procedure_entry(proc);
                    goto *val.cont;primitive_branch230:;object_free(&val);val = proc.proc(argl); goto *cont.cont;after_lambda221:;{Object t = def_var_val(c_str_to_datum("|procedure-environment|"));
                                   object_free(&val);val = t;}object_free(&val);val = make_compiled_procedure(&&entry218);goto after_lambda217;entry218:env = compiled_procedure_env();
                          env = extend_environment(c_str_to_datum("(|env| . ())"));object_free(&proc);proc = lookup_var_val(c_str_to_datum("|cdr|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|env|"));argl = cons(object_copy(val),empty);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch220;}object_free(&val);
                    val = compiled_procedure_entry(proc);
                    goto *val.cont;primitive_branch220:;object_free(&val);val = proc.proc(argl); goto *cont.cont;after_lambda217:;{Object t = def_var_val(c_str_to_datum("|enclosing-environment|"));
                                   object_free(&val);val = t;}object_free(&val);val = make_compiled_procedure(&&entry166);goto after_lambda165;entry166:env = compiled_procedure_env();
                          env = extend_environment(c_str_to_datum("(|vars| . (|vals| . (|base-env| . ())))"));object_free(&val);val = make_compiled_procedure(&&entry170);goto after_lambda169;entry170:env = compiled_procedure_env();
                          env = extend_environment(c_str_to_datum("(|vars-0| . (|vals-0| . (|vars-1| . (|vals-1| . ()))))"));save(cont);save(env);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|symbol?|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|vars-0|"));argl = cons(object_copy(val),empty);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch216;}cont.cont = &&after_call215;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch216:;object_free(&val);val = proc.proc(argl); after_call215:;object_free(&env);env =restore();object_free(&cont);cont =restore();if(val.type==BOOLEAN && !val.boolean){
                        goto false_branch172;}object_free(&proc);proc = lookup_var_val(c_str_to_datum("|cons|"));save(cont);save(proc);object_free(&val);val = lookup_var_val(c_str_to_datum("|base-env|"));argl = cons(object_copy(val),empty);save(argl);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|make-frame|"));save(proc);save(env);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|cons|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|vals-1|"));argl = cons(object_copy(val),empty);object_free(&val);val = lookup_var_val(c_str_to_datum("|vals-0|"));argl = cons(object_copy(val), argl);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch208;}cont.cont = &&after_call207;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch208:;object_free(&val);val = proc.proc(argl); after_call207:;argl = cons(object_copy(val),empty);object_free(&env);env =restore();save(argl);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|cons|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|vars-1|"));argl = cons(object_copy(val),empty);object_free(&val);val = lookup_var_val(c_str_to_datum("|vars-0|"));argl = cons(object_copy(val), argl);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch210;}cont.cont = &&after_call209;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch210:;object_free(&val);val = proc.proc(argl); after_call209:;object_free(&argl);argl =restore();argl = cons(object_copy(val), argl);object_free(&proc);proc =restore();if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch212;}cont.cont = &&after_call211;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch212:;object_free(&val);val = proc.proc(argl); after_call211:;object_free(&argl);argl =restore();argl = cons(object_copy(val), argl);object_free(&proc);proc =restore();object_free(&cont);cont =restore();if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch214;}object_free(&val);
                    val = compiled_procedure_entry(proc);
                    goto *val.cont;primitive_branch214:;object_free(&val);val = proc.proc(argl); goto *cont.cont;false_branch172:;save(cont);save(env);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|null?|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|vars-0|"));argl = cons(object_copy(val),empty);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch206;}cont.cont = &&after_call205;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch206:;object_free(&val);val = proc.proc(argl); after_call205:;object_free(&env);env =restore();object_free(&cont);cont =restore();if(val.type==BOOLEAN && !val.boolean){
                        goto false_branch174;}save(cont);save(env);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|null?|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|vals-0|"));argl = cons(object_copy(val),empty);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch204;}cont.cont = &&after_call203;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch204:;object_free(&val);val = proc.proc(argl); after_call203:;object_free(&env);env =restore();object_free(&cont);cont =restore();if(val.type==BOOLEAN && !val.boolean){
                        goto false_branch196;}object_free(&proc);proc = lookup_var_val(c_str_to_datum("|cons|"));save(cont);save(proc);object_free(&val);val = lookup_var_val(c_str_to_datum("|base-env|"));argl = cons(object_copy(val),empty);save(argl);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|make-frame|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|vals-1|"));argl = cons(object_copy(val),empty);object_free(&val);val = lookup_var_val(c_str_to_datum("|vars-1|"));argl = cons(object_copy(val), argl);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch200;}cont.cont = &&after_call199;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch200:;object_free(&val);val = proc.proc(argl); after_call199:;object_free(&argl);argl =restore();argl = cons(object_copy(val), argl);object_free(&proc);proc =restore();object_free(&cont);cont =restore();if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch202;}object_free(&val);
                    val = compiled_procedure_entry(proc);
                    goto *val.cont;primitive_branch202:;object_free(&val);val = proc.proc(argl); goto *cont.cont;false_branch196:;object_free(&proc);proc = lookup_var_val(c_str_to_datum("|error|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|vals|"));argl = cons(object_copy(val),empty);object_free(&val);val = lookup_var_val(c_str_to_datum("|vars|"));argl = cons(object_copy(val), argl);object_free(&val);val = c_str_to_datum("\"Too many arguments supplied\"");argl = cons(object_copy(val), argl);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch198;}object_free(&val);
                    val = compiled_procedure_entry(proc);
                    goto *val.cont;primitive_branch198:;object_free(&val);val = proc.proc(argl); goto *cont.cont;false_branch174:;save(cont);save(env);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|null?|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|vals-0|"));argl = cons(object_copy(val),empty);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch194;}cont.cont = &&after_call193;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch194:;object_free(&val);val = proc.proc(argl); after_call193:;object_free(&env);env =restore();object_free(&cont);cont =restore();if(val.type==BOOLEAN && !val.boolean){
                        goto false_branch176;}object_free(&proc);proc = lookup_var_val(c_str_to_datum("|error|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|vals|"));argl = cons(object_copy(val),empty);object_free(&val);val = lookup_var_val(c_str_to_datum("|vars|"));argl = cons(object_copy(val), argl);object_free(&val);val = c_str_to_datum("\"Too few arguments supplied\"");argl = cons(object_copy(val), argl);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch192;}object_free(&val);
                    val = compiled_procedure_entry(proc);
                    goto *val.cont;primitive_branch192:;object_free(&val);val = proc.proc(argl); goto *cont.cont;false_branch176:;object_free(&proc);proc = lookup_var_val(c_str_to_datum("|iter|"));save(cont);save(proc);save(env);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|cons|"));save(proc);object_free(&val);val = lookup_var_val(c_str_to_datum("|vals-1|"));argl = cons(object_copy(val),empty);save(argl);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|car|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|vals-0|"));argl = cons(object_copy(val),empty);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch178;}cont.cont = &&after_call177;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch178:;object_free(&val);val = proc.proc(argl); after_call177:;object_free(&argl);argl =restore();argl = cons(object_copy(val), argl);object_free(&proc);proc =restore();if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch180;}cont.cont = &&after_call179;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch180:;object_free(&val);val = proc.proc(argl); after_call179:;argl = cons(object_copy(val),empty);object_free(&env);env =restore();save(env);save(argl);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|cons|"));save(proc);object_free(&val);val = lookup_var_val(c_str_to_datum("|vars-1|"));argl = cons(object_copy(val),empty);save(argl);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|car|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|vars-0|"));argl = cons(object_copy(val),empty);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch182;}cont.cont = &&after_call181;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch182:;object_free(&val);val = proc.proc(argl); after_call181:;object_free(&argl);argl =restore();argl = cons(object_copy(val), argl);object_free(&proc);proc =restore();if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch184;}cont.cont = &&after_call183;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch184:;object_free(&val);val = proc.proc(argl); after_call183:;object_free(&argl);argl =restore();argl = cons(object_copy(val), argl);object_free(&env);env =restore();save(env);save(argl);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|cdr|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|vals-0|"));argl = cons(object_copy(val),empty);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch186;}cont.cont = &&after_call185;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch186:;object_free(&val);val = proc.proc(argl); after_call185:;object_free(&argl);argl =restore();argl = cons(object_copy(val), argl);object_free(&env);env =restore();save(argl);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|cdr|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|vars-0|"));argl = cons(object_copy(val),empty);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch188;}cont.cont = &&after_call187;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch188:;object_free(&val);val = proc.proc(argl); after_call187:;object_free(&argl);argl =restore();argl = cons(object_copy(val), argl);object_free(&proc);proc =restore();object_free(&cont);cont =restore();if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch190;}object_free(&val);
                    val = compiled_procedure_entry(proc);
                    goto *val.cont;primitive_branch190:;object_free(&val);val = proc.proc(argl); goto *cont.cont;after_lambda169:;{Object t = def_var_val(c_str_to_datum("|iter|"));
                                   object_free(&val);val = t;}object_free(&proc);proc = lookup_var_val(c_str_to_datum("|iter|"));object_free(&val);val = c_str_to_datum("()");argl = cons(object_copy(val),empty);object_free(&val);val = c_str_to_datum("()");argl = cons(object_copy(val), argl);object_free(&val);val = lookup_var_val(c_str_to_datum("|vals|"));argl = cons(object_copy(val), argl);object_free(&val);val = lookup_var_val(c_str_to_datum("|vars|"));argl = cons(object_copy(val), argl);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch168;}object_free(&val);
                    val = compiled_procedure_entry(proc);
                    goto *val.cont;primitive_branch168:;object_free(&val);val = proc.proc(argl); goto *cont.cont;after_lambda165:;{Object t = def_var_val(c_str_to_datum("|extend-environment|"));
                                   object_free(&val);val = t;}object_free(&val);val = make_compiled_procedure(&&entry118);goto after_lambda117;entry118:env = compiled_procedure_env();
                          env = extend_environment(c_str_to_datum("(|var| . (|env| . ()))"));object_free(&val);val = make_compiled_procedure(&&entry122);goto after_lambda121;entry122:env = compiled_procedure_env();
                          env = extend_environment(c_str_to_datum("(|env| . ())"));object_free(&val);val = make_compiled_procedure(&&entry142);goto after_lambda141;entry142:env = compiled_procedure_env();
                          env = extend_environment(c_str_to_datum("(|vars| . (|vals| . ()))"));save(cont);save(env);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|null?|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|vars|"));argl = cons(object_copy(val),empty);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch164;}cont.cont = &&after_call163;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch164:;object_free(&val);val = proc.proc(argl); after_call163:;object_free(&env);env =restore();object_free(&cont);cont =restore();if(val.type==BOOLEAN && !val.boolean){
                        goto false_branch144;}object_free(&proc);proc = lookup_var_val(c_str_to_datum("|env-loop|"));save(cont);save(proc);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|enclosing-environment|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|env|"));argl = cons(object_copy(val),empty);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch160;}cont.cont = &&after_call159;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch160:;object_free(&val);val = proc.proc(argl); after_call159:;argl = cons(object_copy(val),empty);object_free(&proc);proc =restore();object_free(&cont);cont =restore();if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch162;}object_free(&val);
                    val = compiled_procedure_entry(proc);
                    goto *val.cont;primitive_branch162:;object_free(&val);val = proc.proc(argl); goto *cont.cont;false_branch144:;save(cont);save(env);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|eq?|"));save(proc);save(env);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|car|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|vars|"));argl = cons(object_copy(val),empty);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch156;}cont.cont = &&after_call155;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch156:;object_free(&val);val = proc.proc(argl); after_call155:;argl = cons(object_copy(val),empty);object_free(&env);env =restore();object_free(&val);val = lookup_var_val(c_str_to_datum("|var|"));argl = cons(object_copy(val), argl);object_free(&proc);proc =restore();if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch158;}cont.cont = &&after_call157;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch158:;object_free(&val);val = proc.proc(argl); after_call157:;object_free(&env);env =restore();object_free(&cont);cont =restore();if(val.type==BOOLEAN && !val.boolean){
                        goto false_branch146;}object_free(&proc);proc = lookup_var_val(c_str_to_datum("|car|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|vals|"));argl = cons(object_copy(val),empty);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch154;}object_free(&val);
                    val = compiled_procedure_entry(proc);
                    goto *val.cont;primitive_branch154:;object_free(&val);val = proc.proc(argl); goto *cont.cont;false_branch146:;object_free(&proc);proc = lookup_var_val(c_str_to_datum("|scan|"));save(cont);save(proc);save(env);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|cdr|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|vals|"));argl = cons(object_copy(val),empty);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch148;}cont.cont = &&after_call147;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch148:;object_free(&val);val = proc.proc(argl); after_call147:;argl = cons(object_copy(val),empty);object_free(&env);env =restore();save(argl);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|cdr|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|vars|"));argl = cons(object_copy(val),empty);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch150;}cont.cont = &&after_call149;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch150:;object_free(&val);val = proc.proc(argl); after_call149:;object_free(&argl);argl =restore();argl = cons(object_copy(val), argl);object_free(&proc);proc =restore();object_free(&cont);cont =restore();if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch152;}object_free(&val);
                    val = compiled_procedure_entry(proc);
                    goto *val.cont;primitive_branch152:;object_free(&val);val = proc.proc(argl); goto *cont.cont;after_lambda141:;{Object t = def_var_val(c_str_to_datum("|scan|"));
                                   object_free(&val);val = t;}save(cont);save(env);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|eq?|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|the-empty-environment|"));argl = cons(object_copy(val),empty);object_free(&val);val = lookup_var_val(c_str_to_datum("|env|"));argl = cons(object_copy(val), argl);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch140;}cont.cont = &&after_call139;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch140:;object_free(&val);val = proc.proc(argl); after_call139:;object_free(&env);env =restore();object_free(&cont);cont =restore();if(val.type==BOOLEAN && !val.boolean){
                        goto false_branch124;}object_free(&proc);proc = lookup_var_val(c_str_to_datum("|error|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|var|"));argl = cons(object_copy(val),empty);object_free(&val);val = c_str_to_datum("\"unbound variable\"");argl = cons(object_copy(val), argl);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch138;}object_free(&val);
                    val = compiled_procedure_entry(proc);
                    goto *val.cont;primitive_branch138:;object_free(&val);val = proc.proc(argl); goto *cont.cont;false_branch124:;object_free(&proc);proc = make_compiled_procedure(&&entry128);goto after_lambda127;entry128:env = compiled_procedure_env();
                          env = extend_environment(c_str_to_datum("(|frame| . ())"));object_free(&proc);proc = lookup_var_val(c_str_to_datum("|scan|"));save(cont);save(proc);save(env);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|frame-values|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|frame|"));argl = cons(object_copy(val),empty);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch130;}cont.cont = &&after_call129;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch130:;object_free(&val);val = proc.proc(argl); after_call129:;argl = cons(object_copy(val),empty);object_free(&env);env =restore();save(argl);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|frame-variables|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|frame|"));argl = cons(object_copy(val),empty);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch132;}cont.cont = &&after_call131;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch132:;object_free(&val);val = proc.proc(argl); after_call131:;object_free(&argl);argl =restore();argl = cons(object_copy(val), argl);object_free(&proc);proc =restore();object_free(&cont);cont =restore();if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch134;}object_free(&val);
                    val = compiled_procedure_entry(proc);
                    goto *val.cont;primitive_branch134:;object_free(&val);val = proc.proc(argl); goto *cont.cont;after_lambda127:;save(cont);save(proc);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|first-frame|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|env|"));argl = cons(object_copy(val),empty);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch126;}cont.cont = &&after_call125;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch126:;object_free(&val);val = proc.proc(argl); after_call125:;argl = cons(object_copy(val),empty);object_free(&proc);proc =restore();object_free(&cont);cont =restore();if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch136;}object_free(&val);
                    val = compiled_procedure_entry(proc);
                    goto *val.cont;primitive_branch136:;object_free(&val);val = proc.proc(argl); goto *cont.cont;after_lambda121:;{Object t = def_var_val(c_str_to_datum("|env-loop|"));
                                   object_free(&val);val = t;}object_free(&proc);proc = lookup_var_val(c_str_to_datum("|env-loop|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|env|"));argl = cons(object_copy(val),empty);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch120;}object_free(&val);
                    val = compiled_procedure_entry(proc);
                    goto *val.cont;primitive_branch120:;object_free(&val);val = proc.proc(argl); goto *cont.cont;after_lambda117:;{Object t = def_var_val(c_str_to_datum("|lookup-variable-value|"));
                                   object_free(&val);val = t;}object_free(&val);val = make_compiled_procedure(&&entry114);goto after_lambda113;entry114:env = compiled_procedure_env();
                          env = extend_environment(c_str_to_datum("(|proc| . ())"));object_free(&proc);proc = lookup_var_val(c_str_to_datum("|tagged-list?|"));object_free(&val);val = c_str_to_datum("|primitive|");argl = cons(object_copy(val),empty);object_free(&val);val = lookup_var_val(c_str_to_datum("|proc|"));argl = cons(object_copy(val), argl);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch116;}object_free(&val);
                    val = compiled_procedure_entry(proc);
                    goto *val.cont;primitive_branch116:;object_free(&val);val = proc.proc(argl); goto *cont.cont;after_lambda113:;{Object t = def_var_val(c_str_to_datum("|primitive-procedure?|"));
                                   object_free(&val);val = t;}object_free(&val);val = make_compiled_procedure(&&entry108);goto after_lambda107;entry108:env = compiled_procedure_env();
                          env = extend_environment(c_str_to_datum("(|proc| . ())"));object_free(&proc);proc = lookup_var_val(c_str_to_datum("|car|"));save(cont);save(proc);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|cdr|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|proc|"));argl = cons(object_copy(val),empty);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch110;}cont.cont = &&after_call109;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch110:;object_free(&val);val = proc.proc(argl); after_call109:;argl = cons(object_copy(val),empty);object_free(&proc);proc =restore();object_free(&cont);cont =restore();if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch112;}object_free(&val);
                    val = compiled_procedure_entry(proc);
                    goto *val.cont;primitive_branch112:;object_free(&val);val = proc.proc(argl); goto *cont.cont;after_lambda107:;{Object t = def_var_val(c_str_to_datum("|primitive-implementation|"));
                                   object_free(&val);val = t;}save(cont);save(env);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|list|"));save(proc);save(env);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|list|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|cons|"));argl = cons(object_copy(val),empty);object_free(&val);val = c_str_to_datum("|cons|");argl = cons(object_copy(val), argl);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch100;}cont.cont = &&after_call99;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch100:;object_free(&val);val = proc.proc(argl); after_call99:;argl = cons(object_copy(val),empty);object_free(&env);env =restore();save(env);save(argl);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|list|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|cdr|"));argl = cons(object_copy(val),empty);object_free(&val);val = c_str_to_datum("|cdr|");argl = cons(object_copy(val), argl);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch102;}cont.cont = &&after_call101;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch102:;object_free(&val);val = proc.proc(argl); after_call101:;object_free(&argl);argl =restore();argl = cons(object_copy(val), argl);object_free(&env);env =restore();save(argl);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|list|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|car|"));argl = cons(object_copy(val),empty);object_free(&val);val = c_str_to_datum("|car|");argl = cons(object_copy(val), argl);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch104;}cont.cont = &&after_call103;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch104:;object_free(&val);val = proc.proc(argl); after_call103:;object_free(&argl);argl =restore();argl = cons(object_copy(val), argl);object_free(&proc);proc =restore();if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch106;}cont.cont = &&after_call105;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch106:;object_free(&val);val = proc.proc(argl); after_call105:;object_free(&env);env =restore();{Object t = def_var_val(c_str_to_datum("|primitive-procedures|"));
                                   object_free(&val);val = t;}object_free(&cont);cont =restore();object_free(&val);val = make_compiled_procedure(&&entry96);goto after_lambda95;entry96:env = compiled_procedure_env();
                          env = extend_environment(c_str_to_datum("()"));object_free(&proc);proc = lookup_var_val(c_str_to_datum("|map|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|primitive-procedures|"));argl = cons(object_copy(val),empty);object_free(&val);val = lookup_var_val(c_str_to_datum("|car|"));argl = cons(object_copy(val), argl);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch98;}object_free(&val);
                    val = compiled_procedure_entry(proc);
                    goto *val.cont;primitive_branch98:;object_free(&val);val = proc.proc(argl); goto *cont.cont;after_lambda95:;{Object t = def_var_val(c_str_to_datum("|primitive-procedure-names|"));
                                   object_free(&val);val = t;}object_free(&val);val = make_compiled_procedure(&&entry84);goto after_lambda83;entry84:env = compiled_procedure_env();
                          env = extend_environment(c_str_to_datum("()"));object_free(&proc);proc = lookup_var_val(c_str_to_datum("|map|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|primitive-procedures|"));argl = cons(object_copy(val),empty);object_free(&val);val = make_compiled_procedure(&&entry86);goto after_lambda85;entry86:env = compiled_procedure_env();
                          env = extend_environment(c_str_to_datum("(|proc| . ())"));object_free(&proc);proc = lookup_var_val(c_str_to_datum("|list|"));save(cont);save(proc);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|car|"));save(proc);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|cdr|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|proc|"));argl = cons(object_copy(val),empty);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch88;}cont.cont = &&after_call87;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch88:;object_free(&val);val = proc.proc(argl); after_call87:;argl = cons(object_copy(val),empty);object_free(&proc);proc =restore();if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch90;}cont.cont = &&after_call89;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch90:;object_free(&val);val = proc.proc(argl); after_call89:;argl = cons(object_copy(val),empty);object_free(&val);val = c_str_to_datum("|primitive|");argl = cons(object_copy(val), argl);object_free(&proc);proc =restore();object_free(&cont);cont =restore();if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch92;}object_free(&val);
                    val = compiled_procedure_entry(proc);
                    goto *val.cont;primitive_branch92:;object_free(&val);val = proc.proc(argl); goto *cont.cont;after_lambda85:;argl = cons(object_copy(val), argl);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch94;}object_free(&val);
                    val = compiled_procedure_entry(proc);
                    goto *val.cont;primitive_branch94:;object_free(&val);val = proc.proc(argl); goto *cont.cont;after_lambda83:;{Object t = def_var_val(c_str_to_datum("|primitive-procedure-objects|"));
                                   object_free(&val);val = t;}object_free(&val);val = make_compiled_procedure(&&entry60);goto after_lambda59;entry60:env = compiled_procedure_env();
                          env = extend_environment(c_str_to_datum("()"));object_free(&proc);proc = make_compiled_procedure(&&entry68);goto after_lambda67;entry68:env = compiled_procedure_env();
                          env = extend_environment(c_str_to_datum("(|initial-env| . ())"));save(cont);save(env);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|define-variable!|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|initial-env|"));argl = cons(object_copy(val),empty);object_free(&val);val = lookup_var_val(c_str_to_datum("|quote|"));argl = cons(object_copy(val), argl);object_free(&val);val = c_str_to_datum("|quote|");argl = cons(object_copy(val), argl);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch80;}cont.cont = &&after_call79;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch80:;object_free(&val);val = proc.proc(argl); after_call79:;object_free(&env);env =restore();object_free(&cont);cont =restore();save(cont);save(env);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|define-variable!|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|initial-env|"));argl = cons(object_copy(val),empty);object_free(&val);val = lookup_var_val(c_str_to_datum("|lambda|"));argl = cons(object_copy(val), argl);object_free(&val);val = c_str_to_datum("|lambda|");argl = cons(object_copy(val), argl);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch78;}cont.cont = &&after_call77;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch78:;object_free(&val);val = proc.proc(argl); after_call77:;object_free(&env);env =restore();object_free(&cont);cont =restore();save(cont);save(env);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|define-variable!|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|initial-env|"));argl = cons(object_copy(val),empty);object_free(&val);val = lookup_var_val(c_str_to_datum("|define|"));argl = cons(object_copy(val), argl);object_free(&val);val = c_str_to_datum("|define|");argl = cons(object_copy(val), argl);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch76;}cont.cont = &&after_call75;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch76:;object_free(&val);val = proc.proc(argl); after_call75:;object_free(&env);env =restore();object_free(&cont);cont =restore();save(cont);save(env);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|define-variable!|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|initial-env|"));argl = cons(object_copy(val),empty);object_free(&val);val = lookup_var_val(c_str_to_datum("|set!|"));argl = cons(object_copy(val), argl);object_free(&val);val = c_str_to_datum("|set!|");argl = cons(object_copy(val), argl);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch74;}cont.cont = &&after_call73;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch74:;object_free(&val);val = proc.proc(argl); after_call73:;object_free(&env);env =restore();object_free(&cont);cont =restore();save(cont);save(env);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|define-variable!|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|initial-env|"));argl = cons(object_copy(val),empty);object_free(&val);val = lookup_var_val(c_str_to_datum("|if|"));argl = cons(object_copy(val), argl);object_free(&val);val = c_str_to_datum("|if|");argl = cons(object_copy(val), argl);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch72;}cont.cont = &&after_call71;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch72:;object_free(&val);val = proc.proc(argl); after_call71:;object_free(&env);env =restore();object_free(&cont);cont =restore();save(cont);save(env);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|define-variable!|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|initial-env|"));argl = cons(object_copy(val),empty);object_free(&val);val = lookup_var_val(c_str_to_datum("|begin|"));argl = cons(object_copy(val), argl);object_free(&val);val = c_str_to_datum("|begin|");argl = cons(object_copy(val), argl);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch70;}cont.cont = &&after_call69;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch70:;object_free(&val);val = proc.proc(argl); after_call69:;object_free(&env);env =restore();object_free(&cont);cont =restore();object_free(&val);val = lookup_var_val(c_str_to_datum("|initial-env|"));goto *cont.cont;after_lambda67:;save(cont);save(proc);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|extend-environment|"));save(proc);object_free(&val);val = lookup_var_val(c_str_to_datum("|the-empty-environment|"));argl = cons(object_copy(val),empty);save(env);save(argl);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|primitive-procedure-objects|"));argl = empty;if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch62;}cont.cont = &&after_call61;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch62:;object_free(&val);val = proc.proc(argl); after_call61:;object_free(&argl);argl =restore();argl = cons(object_copy(val), argl);object_free(&env);env =restore();save(argl);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|primitive-procedure-names|"));argl = empty;if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch64;}cont.cont = &&after_call63;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch64:;object_free(&val);val = proc.proc(argl); after_call63:;object_free(&argl);argl =restore();argl = cons(object_copy(val), argl);object_free(&proc);proc =restore();if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch66;}cont.cont = &&after_call65;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch66:;object_free(&val);val = proc.proc(argl); after_call65:;argl = cons(object_copy(val),empty);object_free(&proc);proc =restore();object_free(&cont);cont =restore();if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch82;}object_free(&val);
                    val = compiled_procedure_entry(proc);
                    goto *val.cont;primitive_branch82:;object_free(&val);val = proc.proc(argl); goto *cont.cont;after_lambda59:;{Object t = def_var_val(c_str_to_datum("|setup-environment|"));
                                   object_free(&val);val = t;}save(cont);save(env);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|setup-environment|"));argl = empty;if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch58;}cont.cont = &&after_call57;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch58:;object_free(&val);val = proc.proc(argl); after_call57:;object_free(&env);env =restore();{Object t = def_var_val(c_str_to_datum("|the-global-environment|"));
                                   object_free(&val);val = t;}object_free(&cont);cont =restore();object_free(&val);val = c_str_to_datum("\"> \"");{Object t = def_var_val(c_str_to_datum("|input-prompt|"));
                                   object_free(&val);val = t;}object_free(&val);val = c_str_to_datum("\"=> \"");{Object t = def_var_val(c_str_to_datum("|output-prompt|"));
                                   object_free(&val);val = t;}save(cont);save(env);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|current-input-port|"));argl = empty;if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch56;}cont.cont = &&after_call55;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch56:;object_free(&val);val = proc.proc(argl); after_call55:;object_free(&env);env =restore();{Object t = def_var_val(c_str_to_datum("|input-port|"));
                                   object_free(&val);val = t;}object_free(&cont);cont =restore();save(cont);save(env);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|current-output-port|"));argl = empty;if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch54;}cont.cont = &&after_call53;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch54:;object_free(&val);val = proc.proc(argl); after_call53:;object_free(&env);env =restore();{Object t = def_var_val(c_str_to_datum("|output-port|"));
                                   object_free(&val);val = t;}object_free(&cont);cont =restore();object_free(&val);val = make_compiled_procedure(&&entry32);goto after_lambda31;entry32:env = compiled_procedure_env();
                          env = extend_environment(c_str_to_datum("()"));save(cont);save(env);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|prompt-for-input|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|input-prompt|"));argl = cons(object_copy(val),empty);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch52;}cont.cont = &&after_call51;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch52:;object_free(&val);val = proc.proc(argl); after_call51:;object_free(&env);env =restore();object_free(&cont);cont =restore();save(cont);save(env);object_free(&proc);proc = make_compiled_procedure(&&entry38);goto after_lambda37;entry38:env = compiled_procedure_env();
                          env = extend_environment(c_str_to_datum("(|input| . ())"));object_free(&proc);proc = make_compiled_procedure(&&entry42);goto after_lambda41;entry42:env = compiled_procedure_env();
                          env = extend_environment(c_str_to_datum("(|output| . ())"));save(cont);save(env);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|announce-output|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|output-prompt|"));argl = cons(object_copy(val),empty);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch46;}cont.cont = &&after_call45;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch46:;object_free(&val);val = proc.proc(argl); after_call45:;object_free(&env);env =restore();object_free(&cont);cont =restore();object_free(&proc);proc = lookup_var_val(c_str_to_datum("|user-print|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|output|"));argl = cons(object_copy(val),empty);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch44;}object_free(&val);
                    val = compiled_procedure_entry(proc);
                    goto *val.cont;primitive_branch44:;object_free(&val);val = proc.proc(argl); goto *cont.cont;after_lambda41:;save(cont);save(proc);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|eval|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|the-global-environment|"));argl = cons(object_copy(val),empty);object_free(&val);val = lookup_var_val(c_str_to_datum("|input|"));argl = cons(object_copy(val), argl);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch40;}cont.cont = &&after_call39;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch40:;object_free(&val);val = proc.proc(argl); after_call39:;argl = cons(object_copy(val),empty);object_free(&proc);proc =restore();object_free(&cont);cont =restore();if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch48;}object_free(&val);
                    val = compiled_procedure_entry(proc);
                    goto *val.cont;primitive_branch48:;object_free(&val);val = proc.proc(argl); goto *cont.cont;after_lambda37:;save(proc);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|read|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|input-port|"));argl = cons(object_copy(val),empty);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch36;}cont.cont = &&after_call35;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch36:;object_free(&val);val = proc.proc(argl); after_call35:;argl = cons(object_copy(val),empty);object_free(&proc);proc =restore();if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch50;}cont.cont = &&after_call49;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch50:;object_free(&val);val = proc.proc(argl); after_call49:;object_free(&env);env =restore();object_free(&cont);cont =restore();object_free(&proc);proc = lookup_var_val(c_str_to_datum("|driver-loop|"));argl = empty;if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch34;}object_free(&val);
                    val = compiled_procedure_entry(proc);
                    goto *val.cont;primitive_branch34:;object_free(&val);val = proc.proc(argl); goto *cont.cont;after_lambda31:;{Object t = def_var_val(c_str_to_datum("|driver-loop|"));
                                   object_free(&val);val = t;}object_free(&val);val = make_compiled_procedure(&&entry28);goto after_lambda27;entry28:env = compiled_procedure_env();
                          env = extend_environment(c_str_to_datum("(|string| . ())"));object_free(&proc);proc = lookup_var_val(c_str_to_datum("|display|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|output-port|"));argl = cons(object_copy(val),empty);object_free(&val);val = lookup_var_val(c_str_to_datum("|string|"));argl = cons(object_copy(val), argl);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch30;}object_free(&val);
                    val = compiled_procedure_entry(proc);
                    goto *val.cont;primitive_branch30:;object_free(&val);val = proc.proc(argl); goto *cont.cont;after_lambda27:;{Object t = def_var_val(c_str_to_datum("|prompt-for-input|"));
                                   object_free(&val);val = t;}object_free(&val);val = make_compiled_procedure(&&entry24);goto after_lambda23;entry24:env = compiled_procedure_env();
                          env = extend_environment(c_str_to_datum("(|string| . ())"));object_free(&proc);proc = lookup_var_val(c_str_to_datum("|display|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|output-port|"));argl = cons(object_copy(val),empty);object_free(&val);val = lookup_var_val(c_str_to_datum("|string|"));argl = cons(object_copy(val), argl);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch26;}object_free(&val);
                    val = compiled_procedure_entry(proc);
                    goto *val.cont;primitive_branch26:;object_free(&val);val = proc.proc(argl); goto *cont.cont;after_lambda23:;{Object t = def_var_val(c_str_to_datum("|announce-output|"));
                                   object_free(&val);val = t;}object_free(&val);val = make_compiled_procedure(&&entry6);goto after_lambda5;entry6:env = compiled_procedure_env();
                          env = extend_environment(c_str_to_datum("(|object| . ())"));save(cont);save(env);save(env);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|compound-procedure?|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|object|"));argl = cons(object_copy(val),empty);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch22;}cont.cont = &&after_call21;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch22:;object_free(&val);val = proc.proc(argl); after_call21:;object_free(&env);env =restore();if(val.type==BOOLEAN && !val.boolean){
                        goto false_branch10;}save(env);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|display|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|output-port|"));argl = cons(object_copy(val),empty);object_free(&val);val = c_str_to_datum("|#<compound-procedure |");argl = cons(object_copy(val), argl);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch20;}cont.cont = &&after_call19;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch20:;object_free(&val);val = proc.proc(argl); after_call19:;object_free(&env);env =restore();save(env);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|write|"));save(proc);object_free(&val);val = lookup_var_val(c_str_to_datum("|output-port|"));argl = cons(object_copy(val),empty);save(argl);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|procedure-parameters|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|object|"));argl = cons(object_copy(val),empty);if (proc.type == PROC_APPLY) {
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
                 goto *val.cont;primitive_branch18:;object_free(&val);val = proc.proc(argl); after_call17:;object_free(&env);env =restore();object_free(&proc);proc = lookup_var_val(c_str_to_datum("|write|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|output-port|"));argl = cons(object_copy(val),empty);object_free(&val);val = c_str_to_datum("|>|");argl = cons(object_copy(val), argl);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch14;}cont.cont = &&after_if9;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch14:;object_free(&val);val = proc.proc(argl); goto after_if9;false_branch10:;object_free(&proc);proc = lookup_var_val(c_str_to_datum("|write|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|output-port|"));argl = cons(object_copy(val),empty);object_free(&val);val = lookup_var_val(c_str_to_datum("|object|"));argl = cons(object_copy(val), argl);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch12;}cont.cont = &&after_call11;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch12:;object_free(&val);val = proc.proc(argl); after_call11:;after_if9:;object_free(&env);env =restore();object_free(&cont);cont =restore();object_free(&proc);proc = lookup_var_val(c_str_to_datum("|newline|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|output-port|"));argl = cons(object_copy(val),empty);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch8;}object_free(&val);
                    val = compiled_procedure_entry(proc);
                    goto *val.cont;primitive_branch8:;object_free(&val);val = proc.proc(argl); goto *cont.cont;after_lambda5:;{Object t = def_var_val(c_str_to_datum("|user-print|"));
                                   object_free(&val);val = t;}object_free(&proc);proc = lookup_var_val(c_str_to_datum("|driver-loop|"));argl = empty;if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch4;}object_free(&val);
                    val = compiled_procedure_entry(proc);
                    goto *val.cont;primitive_branch4:;object_free(&val);val = proc.proc(argl); goto *cont.cont;after_lambda1:;argl = empty;if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch882;}cont.cont = &&after_call881;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch882:;object_free(&val);val = proc.proc(argl); after_call881:;printf("=> ");object_write_stdout(val);puts("");}