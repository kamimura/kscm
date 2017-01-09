/** \file */
#include <kscm.h>
int main (int argc,char *argv[]){init();get_command_line(argc, argv);object_free(&proc);proc = make_compiled_procedure(&&entry2);goto after_lambda1;entry2:env = compiled_procedure_env();
                          env = extend_environment(c_str_to_datum("()"));object_free(&val);val = make_compiled_procedure(&&entry2260);goto after_lambda2259;entry2260:env = compiled_procedure_env();
                          env = extend_environment(c_str_to_datum("(|message| . |objs|)"));object_free(&proc);proc = lookup_var_val(c_str_to_datum("|list|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|objs|"));argl = cons(object_copy(val),empty);object_free(&val);val = lookup_var_val(c_str_to_datum("|message|"));argl = cons(object_copy(val), argl);object_free(&val);val = c_str_to_datum("|error-object|");argl = cons(object_copy(val), argl);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch2262;}object_free(&val);
                    val = compiled_procedure_entry(proc);
                    goto *val.cont;primitive_branch2262:;object_free(&val);val = proc.proc(argl); goto *cont.cont;after_lambda2259:;{Object t = def_var_val(c_str_to_datum("|error|"));
                                   object_free(&val);val = t;}object_free(&val);val = make_compiled_procedure(&&entry2256);goto after_lambda2255;entry2256:env = compiled_procedure_env();
                          env = extend_environment(c_str_to_datum("(|exp| . ())"));object_free(&proc);proc = lookup_var_val(c_str_to_datum("|tagged-list?|"));object_free(&val);val = c_str_to_datum("|error-object|");argl = cons(object_copy(val),empty);object_free(&val);val = lookup_var_val(c_str_to_datum("|exp|"));argl = cons(object_copy(val), argl);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch2258;}object_free(&val);
                    val = compiled_procedure_entry(proc);
                    goto *val.cont;primitive_branch2258:;object_free(&val);val = proc.proc(argl); goto *cont.cont;after_lambda2255:;{Object t = def_var_val(c_str_to_datum("|error-object?|"));
                                   object_free(&val);val = t;}object_free(&val);val = make_compiled_procedure(&&entry2250);goto after_lambda2249;entry2250:env = compiled_procedure_env();
                          env = extend_environment(c_str_to_datum("(|exp| . ())"));object_free(&proc);proc = lookup_var_val(c_str_to_datum("|car|"));save(cont);save(proc);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|cdr|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|exp|"));argl = cons(object_copy(val),empty);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch2252;}cont.cont = &&after_call2251;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch2252:;object_free(&val);val = proc.proc(argl); after_call2251:;argl = cons(object_copy(val),empty);object_free(&proc);proc =restore();object_free(&cont);cont =restore();if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch2254;}object_free(&val);
                    val = compiled_procedure_entry(proc);
                    goto *val.cont;primitive_branch2254:;object_free(&val);val = proc.proc(argl); goto *cont.cont;after_lambda2249:;{Object t = def_var_val(c_str_to_datum("|error-object-message|"));
                                   object_free(&val);val = t;}object_free(&val);val = make_compiled_procedure(&&entry2242);goto after_lambda2241;entry2242:env = compiled_procedure_env();
                          env = extend_environment(c_str_to_datum("(|exp| . ())"));object_free(&proc);proc = lookup_var_val(c_str_to_datum("|car|"));save(cont);save(proc);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|cdr|"));save(proc);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|cdr|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|exp|"));argl = cons(object_copy(val),empty);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch2244;}cont.cont = &&after_call2243;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch2244:;object_free(&val);val = proc.proc(argl); after_call2243:;argl = cons(object_copy(val),empty);object_free(&proc);proc =restore();if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch2246;}cont.cont = &&after_call2245;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch2246:;object_free(&val);val = proc.proc(argl); after_call2245:;argl = cons(object_copy(val),empty);object_free(&proc);proc =restore();object_free(&cont);cont =restore();if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch2248;}object_free(&val);
                    val = compiled_procedure_entry(proc);
                    goto *val.cont;primitive_branch2248:;object_free(&val);val = proc.proc(argl); goto *cont.cont;after_lambda2241:;{Object t = def_var_val(c_str_to_datum("|error-objects|"));
                                   object_free(&val);val = t;}object_free(&val);val = make_compiled_procedure(&&entry2140);goto after_lambda2139;entry2140:env = compiled_procedure_env();
                          env = extend_environment(c_str_to_datum("(|exp| . (|env| . ()))"));save(cont);save(env);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|error-object?|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|exp|"));argl = cons(object_copy(val),empty);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch2240;}cont.cont = &&after_call2239;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch2240:;object_free(&val);val = proc.proc(argl); after_call2239:;object_free(&env);env =restore();object_free(&cont);cont =restore();if(val.type==BOOLEAN && !val.boolean){
                        goto false_branch2142;}object_free(&val);val = lookup_var_val(c_str_to_datum("|exp|"));goto *cont.cont;false_branch2142:;save(cont);save(env);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|eof-object?|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|exp|"));argl = cons(object_copy(val),empty);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch2238;}cont.cont = &&after_call2237;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch2238:;object_free(&val);val = proc.proc(argl); after_call2237:;object_free(&env);env =restore();object_free(&cont);cont =restore();if(val.type==BOOLEAN && !val.boolean){
                        goto false_branch2144;}object_free(&proc);proc = lookup_var_val(c_str_to_datum("|exit|"));argl = empty;if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch2236;}object_free(&val);
                    val = compiled_procedure_entry(proc);
                    goto *val.cont;primitive_branch2236:;object_free(&val);val = proc.proc(argl); goto *cont.cont;false_branch2144:;save(cont);save(env);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|self-evaluating?|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|exp|"));argl = cons(object_copy(val),empty);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch2234;}cont.cont = &&after_call2233;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch2234:;object_free(&val);val = proc.proc(argl); after_call2233:;object_free(&env);env =restore();object_free(&cont);cont =restore();if(val.type==BOOLEAN && !val.boolean){
                        goto false_branch2146;}object_free(&val);val = lookup_var_val(c_str_to_datum("|exp|"));goto *cont.cont;false_branch2146:;save(cont);save(env);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|variable?|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|exp|"));argl = cons(object_copy(val),empty);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch2232;}cont.cont = &&after_call2231;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch2232:;object_free(&val);val = proc.proc(argl); after_call2231:;object_free(&env);env =restore();object_free(&cont);cont =restore();if(val.type==BOOLEAN && !val.boolean){
                        goto false_branch2148;}object_free(&proc);proc = lookup_var_val(c_str_to_datum("|lookup-variable-value|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|env|"));argl = cons(object_copy(val),empty);object_free(&val);val = lookup_var_val(c_str_to_datum("|exp|"));argl = cons(object_copy(val), argl);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch2230;}object_free(&val);
                    val = compiled_procedure_entry(proc);
                    goto *val.cont;primitive_branch2230:;object_free(&val);val = proc.proc(argl); goto *cont.cont;false_branch2148:;save(cont);save(env);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|quoted?|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|exp|"));argl = cons(object_copy(val),empty);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch2228;}cont.cont = &&after_call2227;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch2228:;object_free(&val);val = proc.proc(argl); after_call2227:;object_free(&env);env =restore();object_free(&cont);cont =restore();if(val.type==BOOLEAN && !val.boolean){
                        goto false_branch2150;}object_free(&proc);proc = lookup_var_val(c_str_to_datum("|text-of-quotation|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|exp|"));argl = cons(object_copy(val),empty);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch2226;}object_free(&val);
                    val = compiled_procedure_entry(proc);
                    goto *val.cont;primitive_branch2226:;object_free(&val);val = proc.proc(argl); goto *cont.cont;false_branch2150:;save(cont);save(env);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|lambda?|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|exp|"));argl = cons(object_copy(val),empty);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch2224;}cont.cont = &&after_call2223;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch2224:;object_free(&val);val = proc.proc(argl); after_call2223:;object_free(&env);env =restore();object_free(&cont);cont =restore();if(val.type==BOOLEAN && !val.boolean){
                        goto false_branch2152;}object_free(&proc);proc = lookup_var_val(c_str_to_datum("|make-procedure|"));save(cont);save(proc);object_free(&val);val = lookup_var_val(c_str_to_datum("|env|"));argl = cons(object_copy(val),empty);save(env);save(argl);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|lambda-body|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|exp|"));argl = cons(object_copy(val),empty);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch2218;}cont.cont = &&after_call2217;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch2218:;object_free(&val);val = proc.proc(argl); after_call2217:;object_free(&argl);argl =restore();argl = cons(object_copy(val), argl);object_free(&env);env =restore();save(argl);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|lambda-parameters|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|exp|"));argl = cons(object_copy(val),empty);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch2220;}cont.cont = &&after_call2219;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch2220:;object_free(&val);val = proc.proc(argl); after_call2219:;object_free(&argl);argl =restore();argl = cons(object_copy(val), argl);object_free(&proc);proc =restore();object_free(&cont);cont =restore();if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch2222;}object_free(&val);
                    val = compiled_procedure_entry(proc);
                    goto *val.cont;primitive_branch2222:;object_free(&val);val = proc.proc(argl); goto *cont.cont;false_branch2152:;save(cont);save(env);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|definition?|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|exp|"));argl = cons(object_copy(val),empty);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch2216;}cont.cont = &&after_call2215;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch2216:;object_free(&val);val = proc.proc(argl); after_call2215:;object_free(&env);env =restore();object_free(&cont);cont =restore();if(val.type==BOOLEAN && !val.boolean){
                        goto false_branch2154;}object_free(&proc);proc = lookup_var_val(c_str_to_datum("|eval-definition|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|env|"));argl = cons(object_copy(val),empty);object_free(&val);val = lookup_var_val(c_str_to_datum("|exp|"));argl = cons(object_copy(val), argl);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch2214;}object_free(&val);
                    val = compiled_procedure_entry(proc);
                    goto *val.cont;primitive_branch2214:;object_free(&val);val = proc.proc(argl); goto *cont.cont;false_branch2154:;save(cont);save(env);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|assignment?|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|exp|"));argl = cons(object_copy(val),empty);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch2212;}cont.cont = &&after_call2211;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch2212:;object_free(&val);val = proc.proc(argl); after_call2211:;object_free(&env);env =restore();object_free(&cont);cont =restore();if(val.type==BOOLEAN && !val.boolean){
                        goto false_branch2156;}object_free(&proc);proc = lookup_var_val(c_str_to_datum("|eval-assignment|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|env|"));argl = cons(object_copy(val),empty);object_free(&val);val = lookup_var_val(c_str_to_datum("|exp|"));argl = cons(object_copy(val), argl);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch2210;}object_free(&val);
                    val = compiled_procedure_entry(proc);
                    goto *val.cont;primitive_branch2210:;object_free(&val);val = proc.proc(argl); goto *cont.cont;false_branch2156:;save(cont);save(env);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|if?|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|exp|"));argl = cons(object_copy(val),empty);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch2208;}cont.cont = &&after_call2207;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch2208:;object_free(&val);val = proc.proc(argl); after_call2207:;object_free(&env);env =restore();object_free(&cont);cont =restore();if(val.type==BOOLEAN && !val.boolean){
                        goto false_branch2158;}object_free(&proc);proc = lookup_var_val(c_str_to_datum("|eval-if|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|env|"));argl = cons(object_copy(val),empty);object_free(&val);val = lookup_var_val(c_str_to_datum("|exp|"));argl = cons(object_copy(val), argl);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch2206;}object_free(&val);
                    val = compiled_procedure_entry(proc);
                    goto *val.cont;primitive_branch2206:;object_free(&val);val = proc.proc(argl); goto *cont.cont;false_branch2158:;save(cont);save(env);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|begin?|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|exp|"));argl = cons(object_copy(val),empty);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch2204;}cont.cont = &&after_call2203;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch2204:;object_free(&val);val = proc.proc(argl); after_call2203:;object_free(&env);env =restore();object_free(&cont);cont =restore();if(val.type==BOOLEAN && !val.boolean){
                        goto false_branch2160;}object_free(&proc);proc = lookup_var_val(c_str_to_datum("|eval-sequence|"));save(cont);save(proc);object_free(&val);val = lookup_var_val(c_str_to_datum("|env|"));argl = cons(object_copy(val),empty);save(argl);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|begin-actions|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|exp|"));argl = cons(object_copy(val),empty);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch2200;}cont.cont = &&after_call2199;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch2200:;object_free(&val);val = proc.proc(argl); after_call2199:;object_free(&argl);argl =restore();argl = cons(object_copy(val), argl);object_free(&proc);proc =restore();object_free(&cont);cont =restore();if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch2202;}object_free(&val);
                    val = compiled_procedure_entry(proc);
                    goto *val.cont;primitive_branch2202:;object_free(&val);val = proc.proc(argl); goto *cont.cont;false_branch2160:;save(cont);save(env);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|load?|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|exp|"));argl = cons(object_copy(val),empty);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch2198;}cont.cont = &&after_call2197;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch2198:;object_free(&val);val = proc.proc(argl); after_call2197:;object_free(&env);env =restore();object_free(&cont);cont =restore();if(val.type==BOOLEAN && !val.boolean){
                        goto false_branch2162;}object_free(&proc);proc = lookup_var_val(c_str_to_datum("|eval|"));save(cont);save(proc);object_free(&val);val = lookup_var_val(c_str_to_datum("|env|"));argl = cons(object_copy(val),empty);save(argl);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|read|"));save(proc);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|open-input-file|"));save(proc);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|car|"));save(proc);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|cdr|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|exp|"));argl = cons(object_copy(val),empty);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch2188;}cont.cont = &&after_call2187;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch2188:;object_free(&val);val = proc.proc(argl); after_call2187:;argl = cons(object_copy(val),empty);object_free(&proc);proc =restore();if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch2190;}cont.cont = &&after_call2189;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch2190:;object_free(&val);val = proc.proc(argl); after_call2189:;argl = cons(object_copy(val),empty);object_free(&proc);proc =restore();if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch2192;}cont.cont = &&after_call2191;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch2192:;object_free(&val);val = proc.proc(argl); after_call2191:;argl = cons(object_copy(val),empty);object_free(&proc);proc =restore();if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch2194;}cont.cont = &&after_call2193;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch2194:;object_free(&val);val = proc.proc(argl); after_call2193:;object_free(&argl);argl =restore();argl = cons(object_copy(val), argl);object_free(&proc);proc =restore();object_free(&cont);cont =restore();if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch2196;}object_free(&val);
                    val = compiled_procedure_entry(proc);
                    goto *val.cont;primitive_branch2196:;object_free(&val);val = proc.proc(argl); goto *cont.cont;false_branch2162:;save(cont);save(env);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|pair?|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|exp|"));argl = cons(object_copy(val),empty);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch2186;}cont.cont = &&after_call2185;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch2186:;object_free(&val);val = proc.proc(argl); after_call2185:;object_free(&env);env =restore();object_free(&cont);cont =restore();if(val.type==BOOLEAN && !val.boolean){
                        goto false_branch2164;}save(cont);save(env);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|eval|"));save(proc);object_free(&val);val = lookup_var_val(c_str_to_datum("|env|"));argl = cons(object_copy(val),empty);save(argl);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|car|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|exp|"));argl = cons(object_copy(val),empty);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch2182;}cont.cont = &&after_call2181;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch2182:;object_free(&val);val = proc.proc(argl); after_call2181:;object_free(&argl);argl =restore();argl = cons(object_copy(val), argl);object_free(&proc);proc =restore();if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch2184;}cont.cont = &&after_call2183;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch2184:;object_free(&val);val = proc.proc(argl); after_call2183:;object_free(&env);env =restore();{Object t = def_var_val(c_str_to_datum("|op|"));
                                   object_free(&val);val = t;}object_free(&cont);cont =restore();save(cont);save(env);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|error-object?|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|op|"));argl = cons(object_copy(val),empty);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch2180;}cont.cont = &&after_call2179;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch2180:;object_free(&val);val = proc.proc(argl); after_call2179:;object_free(&env);env =restore();object_free(&cont);cont =restore();if(val.type==BOOLEAN && !val.boolean){
                        goto false_branch2168;}object_free(&val);val = lookup_var_val(c_str_to_datum("|op|"));goto *cont.cont;false_branch2168:;save(cont);save(env);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|list-of-values|"));save(proc);object_free(&val);val = lookup_var_val(c_str_to_datum("|env|"));argl = cons(object_copy(val),empty);save(argl);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|cdr|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|exp|"));argl = cons(object_copy(val),empty);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch2176;}cont.cont = &&after_call2175;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch2176:;object_free(&val);val = proc.proc(argl); after_call2175:;object_free(&argl);argl =restore();argl = cons(object_copy(val), argl);object_free(&proc);proc =restore();if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch2178;}cont.cont = &&after_call2177;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch2178:;object_free(&val);val = proc.proc(argl); after_call2177:;object_free(&env);env =restore();{Object t = def_var_val(c_str_to_datum("|ops|"));
                                   object_free(&val);val = t;}object_free(&cont);cont =restore();save(cont);save(env);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|include-error?|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|ops|"));argl = cons(object_copy(val),empty);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch2174;}cont.cont = &&after_call2173;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch2174:;object_free(&val);val = proc.proc(argl); after_call2173:;object_free(&env);env =restore();{Object t = def_var_val(c_str_to_datum("|o|"));
                                   object_free(&val);val = t;}object_free(&cont);cont =restore();object_free(&val);val = lookup_var_val(c_str_to_datum("|o|"));if(val.type==BOOLEAN && !val.boolean){
                        goto false_branch2170;}object_free(&val);val = lookup_var_val(c_str_to_datum("|o|"));goto *cont.cont;false_branch2170:;object_free(&proc);proc = lookup_var_val(c_str_to_datum("|apply|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|ops|"));argl = cons(object_copy(val),empty);object_free(&val);val = lookup_var_val(c_str_to_datum("|op|"));argl = cons(object_copy(val), argl);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch2172;}object_free(&val);
                    val = compiled_procedure_entry(proc);
                    goto *val.cont;primitive_branch2172:;object_free(&val);val = proc.proc(argl); goto *cont.cont;false_branch2164:;object_free(&proc);proc = lookup_var_val(c_str_to_datum("|error|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|exp|"));argl = cons(object_copy(val),empty);object_free(&val);val = c_str_to_datum("\"(eval) unknown expression type --\"");argl = cons(object_copy(val), argl);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch2166;}object_free(&val);
                    val = compiled_procedure_entry(proc);
                    goto *val.cont;primitive_branch2166:;object_free(&val);val = proc.proc(argl); goto *cont.cont;after_lambda2139:;{Object t = def_var_val(c_str_to_datum("|eval|"));
                                   object_free(&val);val = t;}object_free(&val);val = make_compiled_procedure(&&entry2072);goto after_lambda2071;entry2072:env = compiled_procedure_env();
                          env = extend_environment(c_str_to_datum("(|exp| . (|env| . ()))"));save(cont);save(env);save(env);save(env);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|symbol?|"));save(proc);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|car|"));save(proc);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|cdr|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|exp|"));argl = cons(object_copy(val),empty);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch2134;}cont.cont = &&after_call2133;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch2134:;object_free(&val);val = proc.proc(argl); after_call2133:;argl = cons(object_copy(val),empty);object_free(&proc);proc =restore();if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch2136;}cont.cont = &&after_call2135;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch2136:;object_free(&val);val = proc.proc(argl); after_call2135:;argl = cons(object_copy(val),empty);object_free(&proc);proc =restore();if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch2138;}cont.cont = &&after_call2137;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch2138:;object_free(&val);val = proc.proc(argl); after_call2137:;object_free(&env);env =restore();if(val.type==BOOLEAN && !val.boolean){
                        goto false_branch2128;}object_free(&proc);proc = lookup_var_val(c_str_to_datum("|=|"));save(proc);object_free(&val);val = c_str_to_datum("3");argl = cons(object_copy(val),empty);save(argl);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|length|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|exp|"));argl = cons(object_copy(val),empty);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch2130;}cont.cont = &&after_call2129;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch2130:;object_free(&val);val = proc.proc(argl); after_call2129:;object_free(&argl);argl =restore();argl = cons(object_copy(val), argl);object_free(&proc);proc =restore();if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch2132;}cont.cont = &&after_if2127;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch2132:;object_free(&val);val = proc.proc(argl); goto after_if2127;false_branch2128:;object_free(&val);val = c_str_to_datum("#false");after_if2127:;object_free(&env);env =restore();if(val.type==BOOLEAN && !val.boolean){
                        goto false_branch2088;}save(env);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|symbol?|"));save(proc);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|car|"));save(proc);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|cdr|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|exp|"));argl = cons(object_copy(val),empty);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch2122;}cont.cont = &&after_call2121;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch2122:;object_free(&val);val = proc.proc(argl); after_call2121:;argl = cons(object_copy(val),empty);object_free(&proc);proc =restore();if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch2124;}cont.cont = &&after_call2123;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch2124:;object_free(&val);val = proc.proc(argl); after_call2123:;argl = cons(object_copy(val),empty);object_free(&proc);proc =restore();if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch2126;}cont.cont = &&after_call2125;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch2126:;object_free(&val);val = proc.proc(argl); after_call2125:;object_free(&env);env =restore();if(val.type==BOOLEAN && !val.boolean){
                        goto false_branch2116;}object_free(&proc);proc = lookup_var_val(c_str_to_datum("|=|"));save(proc);object_free(&val);val = c_str_to_datum("3");argl = cons(object_copy(val),empty);save(argl);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|length|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|exp|"));argl = cons(object_copy(val),empty);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch2118;}cont.cont = &&after_call2117;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch2118:;object_free(&val);val = proc.proc(argl); after_call2117:;object_free(&argl);argl =restore();argl = cons(object_copy(val), argl);object_free(&proc);proc =restore();if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch2120;}cont.cont = &&after_if2087;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch2120:;object_free(&val);val = proc.proc(argl); goto after_if2087;false_branch2116:;object_free(&val);val = c_str_to_datum("#false");goto after_if2087;false_branch2088:;save(env);save(env);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|pair?|"));save(proc);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|car|"));save(proc);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|cdr|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|exp|"));argl = cons(object_copy(val),empty);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch2110;}cont.cont = &&after_call2109;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch2110:;object_free(&val);val = proc.proc(argl); after_call2109:;argl = cons(object_copy(val),empty);object_free(&proc);proc =restore();if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch2112;}cont.cont = &&after_call2111;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch2112:;object_free(&val);val = proc.proc(argl); after_call2111:;argl = cons(object_copy(val),empty);object_free(&proc);proc =restore();if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch2114;}cont.cont = &&after_call2113;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch2114:;object_free(&val);val = proc.proc(argl); after_call2113:;object_free(&env);env =restore();if(val.type==BOOLEAN && !val.boolean){
                        goto false_branch2104;}object_free(&proc);proc = lookup_var_val(c_str_to_datum("|<|"));save(proc);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|length|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|exp|"));argl = cons(object_copy(val),empty);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch2106;}cont.cont = &&after_call2105;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch2106:;object_free(&val);val = proc.proc(argl); after_call2105:;argl = cons(object_copy(val),empty);object_free(&val);val = c_str_to_datum("2");argl = cons(object_copy(val), argl);object_free(&proc);proc =restore();if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch2108;}cont.cont = &&after_if2103;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch2108:;object_free(&val);val = proc.proc(argl); goto after_if2103;false_branch2104:;object_free(&val);val = c_str_to_datum("#false");after_if2103:;object_free(&env);env =restore();if(val.type==BOOLEAN && !val.boolean){
                        goto false_branch2090;}save(env);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|pair?|"));save(proc);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|car|"));save(proc);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|cdr|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|exp|"));argl = cons(object_copy(val),empty);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch2098;}cont.cont = &&after_call2097;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch2098:;object_free(&val);val = proc.proc(argl); after_call2097:;argl = cons(object_copy(val),empty);object_free(&proc);proc =restore();if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch2100;}cont.cont = &&after_call2099;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch2100:;object_free(&val);val = proc.proc(argl); after_call2099:;argl = cons(object_copy(val),empty);object_free(&proc);proc =restore();if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch2102;}cont.cont = &&after_call2101;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch2102:;object_free(&val);val = proc.proc(argl); after_call2101:;object_free(&env);env =restore();if(val.type==BOOLEAN && !val.boolean){
                        goto false_branch2092;}object_free(&proc);proc = lookup_var_val(c_str_to_datum("|<|"));save(proc);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|length|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|exp|"));argl = cons(object_copy(val),empty);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch2094;}cont.cont = &&after_call2093;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch2094:;object_free(&val);val = proc.proc(argl); after_call2093:;argl = cons(object_copy(val),empty);object_free(&val);val = c_str_to_datum("2");argl = cons(object_copy(val), argl);object_free(&proc);proc =restore();if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch2096;}cont.cont = &&after_if2089;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch2096:;object_free(&val);val = proc.proc(argl); goto after_if2089;false_branch2092:;object_free(&val);val = c_str_to_datum("#false");goto after_if2089;false_branch2090:;object_free(&val);val = c_str_to_datum("#false");after_if2089:;after_if2087:;object_free(&env);env =restore();object_free(&cont);cont =restore();if(val.type==BOOLEAN && !val.boolean){
                        goto false_branch2074;}save(cont);save(env);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|eval|"));save(proc);object_free(&val);val = lookup_var_val(c_str_to_datum("|env|"));argl = cons(object_copy(val),empty);save(argl);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|definition-value|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|exp|"));argl = cons(object_copy(val),empty);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch2084;}cont.cont = &&after_call2083;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch2084:;object_free(&val);val = proc.proc(argl); after_call2083:;object_free(&argl);argl =restore();argl = cons(object_copy(val), argl);object_free(&proc);proc =restore();if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch2086;}cont.cont = &&after_call2085;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch2086:;object_free(&val);val = proc.proc(argl); after_call2085:;object_free(&env);env =restore();{Object t = def_var_val(c_str_to_datum("|o|"));
                                   object_free(&val);val = t;}object_free(&cont);cont =restore();save(cont);save(env);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|error-object?|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|o|"));argl = cons(object_copy(val),empty);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch2082;}cont.cont = &&after_call2081;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch2082:;object_free(&val);val = proc.proc(argl); after_call2081:;object_free(&env);env =restore();object_free(&cont);cont =restore();if(val.type==BOOLEAN && !val.boolean){
                        goto false_branch2076;}object_free(&val);val = lookup_var_val(c_str_to_datum("|o|"));goto *cont.cont;false_branch2076:;object_free(&proc);proc = lookup_var_val(c_str_to_datum("|define-variable!|"));save(cont);save(proc);object_free(&val);val = lookup_var_val(c_str_to_datum("|env|"));argl = cons(object_copy(val),empty);object_free(&val);val = lookup_var_val(c_str_to_datum("|o|"));argl = cons(object_copy(val), argl);save(argl);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|definition-variable|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|exp|"));argl = cons(object_copy(val),empty);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch2078;}cont.cont = &&after_call2077;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch2078:;object_free(&val);val = proc.proc(argl); after_call2077:;object_free(&argl);argl =restore();argl = cons(object_copy(val), argl);object_free(&proc);proc =restore();object_free(&cont);cont =restore();if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch2080;}object_free(&val);
                    val = compiled_procedure_entry(proc);
                    goto *val.cont;primitive_branch2080:;object_free(&val);val = proc.proc(argl); goto *cont.cont;false_branch2074:;object_free(&val);val = undef;goto *cont.cont;after_lambda2071:;{Object t = def_var_val(c_str_to_datum("|eval-definition|"));
                                   object_free(&val);val = t;}object_free(&val);val = make_compiled_procedure(&&entry2050);goto after_lambda2049;entry2050:env = compiled_procedure_env();
                          env = extend_environment(c_str_to_datum("(|exp| . (|env| . ()))"));save(cont);save(env);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|=|"));save(proc);object_free(&val);val = c_str_to_datum("3");argl = cons(object_copy(val),empty);save(argl);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|length|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|exp|"));argl = cons(object_copy(val),empty);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch2068;}cont.cont = &&after_call2067;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch2068:;object_free(&val);val = proc.proc(argl); after_call2067:;object_free(&argl);argl =restore();argl = cons(object_copy(val), argl);object_free(&proc);proc =restore();if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch2070;}cont.cont = &&after_call2069;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch2070:;object_free(&val);val = proc.proc(argl); after_call2069:;object_free(&env);env =restore();object_free(&cont);cont =restore();if(val.type==BOOLEAN && !val.boolean){
                        goto false_branch2052;}save(cont);save(env);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|eval|"));save(proc);object_free(&val);val = lookup_var_val(c_str_to_datum("|env|"));argl = cons(object_copy(val),empty);save(argl);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|assignment-value|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|exp|"));argl = cons(object_copy(val),empty);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch2064;}cont.cont = &&after_call2063;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch2064:;object_free(&val);val = proc.proc(argl); after_call2063:;object_free(&argl);argl =restore();argl = cons(object_copy(val), argl);object_free(&proc);proc =restore();if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch2066;}cont.cont = &&after_call2065;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch2066:;object_free(&val);val = proc.proc(argl); after_call2065:;object_free(&env);env =restore();{Object t = def_var_val(c_str_to_datum("|o|"));
                                   object_free(&val);val = t;}object_free(&cont);cont =restore();save(cont);save(env);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|error-object?|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|o|"));argl = cons(object_copy(val),empty);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch2062;}cont.cont = &&after_call2061;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch2062:;object_free(&val);val = proc.proc(argl); after_call2061:;object_free(&env);env =restore();object_free(&cont);cont =restore();if(val.type==BOOLEAN && !val.boolean){
                        goto false_branch2056;}object_free(&val);val = lookup_var_val(c_str_to_datum("|o|"));goto *cont.cont;false_branch2056:;object_free(&proc);proc = lookup_var_val(c_str_to_datum("|set-variable-value!|"));save(cont);save(proc);object_free(&val);val = lookup_var_val(c_str_to_datum("|env|"));argl = cons(object_copy(val),empty);object_free(&val);val = lookup_var_val(c_str_to_datum("|o|"));argl = cons(object_copy(val), argl);save(argl);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|assignment-variable|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|exp|"));argl = cons(object_copy(val),empty);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch2058;}cont.cont = &&after_call2057;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch2058:;object_free(&val);val = proc.proc(argl); after_call2057:;object_free(&argl);argl =restore();argl = cons(object_copy(val), argl);object_free(&proc);proc =restore();object_free(&cont);cont =restore();if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch2060;}object_free(&val);
                    val = compiled_procedure_entry(proc);
                    goto *val.cont;primitive_branch2060:;object_free(&val);val = proc.proc(argl); goto *cont.cont;false_branch2052:;object_free(&proc);proc = lookup_var_val(c_str_to_datum("|error|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|exp|"));argl = cons(object_copy(val),empty);object_free(&val);val = c_str_to_datum("\"(eval) unknown expression type --\"");argl = cons(object_copy(val), argl);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch2054;}object_free(&val);
                    val = compiled_procedure_entry(proc);
                    goto *val.cont;primitive_branch2054:;object_free(&val);val = proc.proc(argl); goto *cont.cont;after_lambda2049:;{Object t = def_var_val(c_str_to_datum("|eval-assignment|"));
                                   object_free(&val);val = t;}object_free(&val);val = make_compiled_procedure(&&entry2006);goto after_lambda2005;entry2006:env = compiled_procedure_env();
                          env = extend_environment(c_str_to_datum("(|exp| . (|env| . ()))"));save(cont);save(env);save(env);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|=|"));save(proc);object_free(&val);val = c_str_to_datum("3");argl = cons(object_copy(val),empty);save(argl);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|length|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|exp|"));argl = cons(object_copy(val),empty);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch2046;}cont.cont = &&after_call2045;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch2046:;object_free(&val);val = proc.proc(argl); after_call2045:;object_free(&argl);argl =restore();argl = cons(object_copy(val), argl);object_free(&proc);proc =restore();if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch2048;}cont.cont = &&after_call2047;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch2048:;object_free(&val);val = proc.proc(argl); after_call2047:;object_free(&env);env =restore();if(val.type==BOOLEAN && !val.boolean){
                        goto false_branch2030;}object_free(&proc);proc = lookup_var_val(c_str_to_datum("|=|"));save(proc);object_free(&val);val = c_str_to_datum("3");argl = cons(object_copy(val),empty);save(argl);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|length|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|exp|"));argl = cons(object_copy(val),empty);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch2042;}cont.cont = &&after_call2041;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch2042:;object_free(&val);val = proc.proc(argl); after_call2041:;object_free(&argl);argl =restore();argl = cons(object_copy(val), argl);object_free(&proc);proc =restore();if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch2044;}cont.cont = &&after_if2029;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch2044:;object_free(&val);val = proc.proc(argl); goto after_if2029;false_branch2030:;save(env);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|=|"));save(proc);object_free(&val);val = c_str_to_datum("4");argl = cons(object_copy(val),empty);save(argl);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|length|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|exp|"));argl = cons(object_copy(val),empty);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch2038;}cont.cont = &&after_call2037;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch2038:;object_free(&val);val = proc.proc(argl); after_call2037:;object_free(&argl);argl =restore();argl = cons(object_copy(val), argl);object_free(&proc);proc =restore();if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch2040;}cont.cont = &&after_call2039;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch2040:;object_free(&val);val = proc.proc(argl); after_call2039:;object_free(&env);env =restore();if(val.type==BOOLEAN && !val.boolean){
                        goto false_branch2032;}object_free(&proc);proc = lookup_var_val(c_str_to_datum("|=|"));save(proc);object_free(&val);val = c_str_to_datum("4");argl = cons(object_copy(val),empty);save(argl);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|length|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|exp|"));argl = cons(object_copy(val),empty);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch2034;}cont.cont = &&after_call2033;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch2034:;object_free(&val);val = proc.proc(argl); after_call2033:;object_free(&argl);argl =restore();argl = cons(object_copy(val), argl);object_free(&proc);proc =restore();if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch2036;}cont.cont = &&after_if2031;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch2036:;object_free(&val);val = proc.proc(argl); goto after_if2031;false_branch2032:;object_free(&val);val = c_str_to_datum("#false");after_if2031:;after_if2029:;object_free(&env);env =restore();object_free(&cont);cont =restore();if(val.type==BOOLEAN && !val.boolean){
                        goto false_branch2008;}save(cont);save(env);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|eval|"));save(proc);object_free(&val);val = lookup_var_val(c_str_to_datum("|env|"));argl = cons(object_copy(val),empty);save(argl);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|if-predicate|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|exp|"));argl = cons(object_copy(val),empty);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch2026;}cont.cont = &&after_call2025;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch2026:;object_free(&val);val = proc.proc(argl); after_call2025:;object_free(&argl);argl =restore();argl = cons(object_copy(val), argl);object_free(&proc);proc =restore();if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch2028;}cont.cont = &&after_call2027;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch2028:;object_free(&val);val = proc.proc(argl); after_call2027:;object_free(&env);env =restore();{Object t = def_var_val(c_str_to_datum("|pred|"));
                                   object_free(&val);val = t;}object_free(&cont);cont =restore();save(cont);save(env);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|error-object?|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|pred|"));argl = cons(object_copy(val),empty);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch2024;}cont.cont = &&after_call2023;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch2024:;object_free(&val);val = proc.proc(argl); after_call2023:;object_free(&env);env =restore();object_free(&cont);cont =restore();if(val.type==BOOLEAN && !val.boolean){
                        goto false_branch2012;}object_free(&val);val = lookup_var_val(c_str_to_datum("|pred|"));goto *cont.cont;false_branch2012:;object_free(&val);val = lookup_var_val(c_str_to_datum("|pred|"));if(val.type==BOOLEAN && !val.boolean){
                        goto false_branch2014;}object_free(&proc);proc = lookup_var_val(c_str_to_datum("|eval|"));save(cont);save(proc);object_free(&val);val = lookup_var_val(c_str_to_datum("|env|"));argl = cons(object_copy(val),empty);save(argl);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|if-consequent|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|exp|"));argl = cons(object_copy(val),empty);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch2020;}cont.cont = &&after_call2019;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch2020:;object_free(&val);val = proc.proc(argl); after_call2019:;object_free(&argl);argl =restore();argl = cons(object_copy(val), argl);object_free(&proc);proc =restore();object_free(&cont);cont =restore();if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch2022;}object_free(&val);
                    val = compiled_procedure_entry(proc);
                    goto *val.cont;primitive_branch2022:;object_free(&val);val = proc.proc(argl); goto *cont.cont;false_branch2014:;object_free(&proc);proc = lookup_var_val(c_str_to_datum("|eval|"));save(cont);save(proc);object_free(&val);val = lookup_var_val(c_str_to_datum("|env|"));argl = cons(object_copy(val),empty);save(argl);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|if-alternative|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|exp|"));argl = cons(object_copy(val),empty);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch2016;}cont.cont = &&after_call2015;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch2016:;object_free(&val);val = proc.proc(argl); after_call2015:;object_free(&argl);argl =restore();argl = cons(object_copy(val), argl);object_free(&proc);proc =restore();object_free(&cont);cont =restore();if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch2018;}object_free(&val);
                    val = compiled_procedure_entry(proc);
                    goto *val.cont;primitive_branch2018:;object_free(&val);val = proc.proc(argl); goto *cont.cont;false_branch2008:;object_free(&proc);proc = lookup_var_val(c_str_to_datum("|error|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|exp|"));argl = cons(object_copy(val),empty);object_free(&val);val = c_str_to_datum("\"(eval) unknown expression type --\"");argl = cons(object_copy(val), argl);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch2010;}object_free(&val);
                    val = compiled_procedure_entry(proc);
                    goto *val.cont;primitive_branch2010:;object_free(&val);val = proc.proc(argl); goto *cont.cont;after_lambda2005:;{Object t = def_var_val(c_str_to_datum("|eval-if|"));
                                   object_free(&val);val = t;}object_free(&val);val = make_compiled_procedure(&&entry1982);goto after_lambda1981;entry1982:env = compiled_procedure_env();
                          env = extend_environment(c_str_to_datum("(|exps| . (|env| . ()))"));save(cont);save(env);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|null?|"));save(proc);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|cdr|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|exps|"));argl = cons(object_copy(val),empty);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch2002;}cont.cont = &&after_call2001;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch2002:;object_free(&val);val = proc.proc(argl); after_call2001:;argl = cons(object_copy(val),empty);object_free(&proc);proc =restore();if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch2004;}cont.cont = &&after_call2003;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch2004:;object_free(&val);val = proc.proc(argl); after_call2003:;object_free(&env);env =restore();object_free(&cont);cont =restore();if(val.type==BOOLEAN && !val.boolean){
                        goto false_branch1984;}object_free(&proc);proc = lookup_var_val(c_str_to_datum("|eval|"));save(cont);save(proc);object_free(&val);val = lookup_var_val(c_str_to_datum("|env|"));argl = cons(object_copy(val),empty);save(argl);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|car|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|exps|"));argl = cons(object_copy(val),empty);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch1998;}cont.cont = &&after_call1997;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch1998:;object_free(&val);val = proc.proc(argl); after_call1997:;object_free(&argl);argl =restore();argl = cons(object_copy(val), argl);object_free(&proc);proc =restore();object_free(&cont);cont =restore();if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch2000;}object_free(&val);
                    val = compiled_procedure_entry(proc);
                    goto *val.cont;primitive_branch2000:;object_free(&val);val = proc.proc(argl); goto *cont.cont;false_branch1984:;save(cont);save(env);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|eval|"));save(proc);object_free(&val);val = lookup_var_val(c_str_to_datum("|env|"));argl = cons(object_copy(val),empty);save(argl);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|car|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|exps|"));argl = cons(object_copy(val),empty);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch1994;}cont.cont = &&after_call1993;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch1994:;object_free(&val);val = proc.proc(argl); after_call1993:;object_free(&argl);argl =restore();argl = cons(object_copy(val), argl);object_free(&proc);proc =restore();if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch1996;}cont.cont = &&after_call1995;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch1996:;object_free(&val);val = proc.proc(argl); after_call1995:;object_free(&env);env =restore();{Object t = def_var_val(c_str_to_datum("|o|"));
                                   object_free(&val);val = t;}object_free(&cont);cont =restore();save(cont);save(env);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|error-object?|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|o|"));argl = cons(object_copy(val),empty);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch1992;}cont.cont = &&after_call1991;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch1992:;object_free(&val);val = proc.proc(argl); after_call1991:;object_free(&env);env =restore();object_free(&cont);cont =restore();if(val.type==BOOLEAN && !val.boolean){
                        goto false_branch1986;}object_free(&val);val = lookup_var_val(c_str_to_datum("|o|"));goto *cont.cont;false_branch1986:;object_free(&proc);proc = lookup_var_val(c_str_to_datum("|eval-sequence|"));save(cont);save(proc);object_free(&val);val = lookup_var_val(c_str_to_datum("|env|"));argl = cons(object_copy(val),empty);save(argl);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|cdr|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|exps|"));argl = cons(object_copy(val),empty);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch1988;}cont.cont = &&after_call1987;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch1988:;object_free(&val);val = proc.proc(argl); after_call1987:;object_free(&argl);argl =restore();argl = cons(object_copy(val), argl);object_free(&proc);proc =restore();object_free(&cont);cont =restore();if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch1990;}object_free(&val);
                    val = compiled_procedure_entry(proc);
                    goto *val.cont;primitive_branch1990:;object_free(&val);val = proc.proc(argl); goto *cont.cont;after_lambda1981:;{Object t = def_var_val(c_str_to_datum("|eval-sequence|"));
                                   object_free(&val);val = t;}object_free(&val);val = make_compiled_procedure(&&entry1964);goto after_lambda1963;entry1964:env = compiled_procedure_env();
                          env = extend_environment(c_str_to_datum("(|list| . ())"));save(cont);save(env);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|null?|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|list|"));argl = cons(object_copy(val),empty);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch1980;}cont.cont = &&after_call1979;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch1980:;object_free(&val);val = proc.proc(argl); after_call1979:;object_free(&env);env =restore();object_free(&cont);cont =restore();if(val.type==BOOLEAN && !val.boolean){
                        goto false_branch1966;}object_free(&val);val = c_str_to_datum("#false");goto *cont.cont;false_branch1966:;save(cont);save(env);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|error-object?|"));save(proc);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|car|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|list|"));argl = cons(object_copy(val),empty);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch1976;}cont.cont = &&after_call1975;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch1976:;object_free(&val);val = proc.proc(argl); after_call1975:;argl = cons(object_copy(val),empty);object_free(&proc);proc =restore();if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch1978;}cont.cont = &&after_call1977;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch1978:;object_free(&val);val = proc.proc(argl); after_call1977:;object_free(&env);env =restore();object_free(&cont);cont =restore();if(val.type==BOOLEAN && !val.boolean){
                        goto false_branch1968;}object_free(&proc);proc = lookup_var_val(c_str_to_datum("|car|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|list|"));argl = cons(object_copy(val),empty);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch1974;}object_free(&val);
                    val = compiled_procedure_entry(proc);
                    goto *val.cont;primitive_branch1974:;object_free(&val);val = proc.proc(argl); goto *cont.cont;false_branch1968:;object_free(&proc);proc = lookup_var_val(c_str_to_datum("|include-error?|"));save(cont);save(proc);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|cdr|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|list|"));argl = cons(object_copy(val),empty);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch1970;}cont.cont = &&after_call1969;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch1970:;object_free(&val);val = proc.proc(argl); after_call1969:;argl = cons(object_copy(val),empty);object_free(&proc);proc =restore();object_free(&cont);cont =restore();if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch1972;}object_free(&val);
                    val = compiled_procedure_entry(proc);
                    goto *val.cont;primitive_branch1972:;object_free(&val);val = proc.proc(argl); goto *cont.cont;after_lambda1963:;{Object t = def_var_val(c_str_to_datum("|include-error?|"));
                                   object_free(&val);val = t;}object_free(&val);val = make_compiled_procedure(&&entry1948);goto after_lambda1947;entry1948:env = compiled_procedure_env();
                          env = extend_environment(c_str_to_datum("(|exps| . (|env| . ()))"));save(cont);save(env);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|null?|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|exps|"));argl = cons(object_copy(val),empty);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch1962;}cont.cont = &&after_call1961;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch1962:;object_free(&val);val = proc.proc(argl); after_call1961:;object_free(&env);env =restore();object_free(&cont);cont =restore();if(val.type==BOOLEAN && !val.boolean){
                        goto false_branch1950;}object_free(&val);val = c_str_to_datum("()");goto *cont.cont;false_branch1950:;object_free(&proc);proc = lookup_var_val(c_str_to_datum("|cons|"));save(cont);save(proc);save(env);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|list-of-values|"));save(proc);object_free(&val);val = lookup_var_val(c_str_to_datum("|env|"));argl = cons(object_copy(val),empty);save(argl);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|cdr|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|exps|"));argl = cons(object_copy(val),empty);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch1952;}cont.cont = &&after_call1951;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch1952:;object_free(&val);val = proc.proc(argl); after_call1951:;object_free(&argl);argl =restore();argl = cons(object_copy(val), argl);object_free(&proc);proc =restore();if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch1954;}cont.cont = &&after_call1953;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch1954:;object_free(&val);val = proc.proc(argl); after_call1953:;argl = cons(object_copy(val),empty);object_free(&env);env =restore();save(argl);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|eval|"));save(proc);object_free(&val);val = lookup_var_val(c_str_to_datum("|env|"));argl = cons(object_copy(val),empty);save(argl);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|car|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|exps|"));argl = cons(object_copy(val),empty);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch1956;}cont.cont = &&after_call1955;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch1956:;object_free(&val);val = proc.proc(argl); after_call1955:;object_free(&argl);argl =restore();argl = cons(object_copy(val), argl);object_free(&proc);proc =restore();if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch1958;}cont.cont = &&after_call1957;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch1958:;object_free(&val);val = proc.proc(argl); after_call1957:;object_free(&argl);argl =restore();argl = cons(object_copy(val), argl);object_free(&proc);proc =restore();object_free(&cont);cont =restore();if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch1960;}object_free(&val);
                    val = compiled_procedure_entry(proc);
                    goto *val.cont;primitive_branch1960:;object_free(&val);val = proc.proc(argl); goto *cont.cont;after_lambda1947:;{Object t = def_var_val(c_str_to_datum("|list-of-values|"));
                                   object_free(&val);val = t;}object_free(&val);val = make_compiled_procedure(&&entry1918);goto after_lambda1917;entry1918:env = compiled_procedure_env();
                          env = extend_environment(c_str_to_datum("(|procedure| . (|arguments| . ()))"));save(cont);save(env);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|primitive-procedure?|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|procedure|"));argl = cons(object_copy(val),empty);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch1946;}cont.cont = &&after_call1945;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch1946:;object_free(&val);val = proc.proc(argl); after_call1945:;object_free(&env);env =restore();object_free(&cont);cont =restore();if(val.type==BOOLEAN && !val.boolean){
                        goto false_branch1920;}object_free(&proc);proc = lookup_var_val(c_str_to_datum("|c-apply|"));save(cont);save(proc);object_free(&val);val = lookup_var_val(c_str_to_datum("|arguments|"));argl = cons(object_copy(val),empty);save(argl);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|primitive-implementation|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|procedure|"));argl = cons(object_copy(val),empty);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch1942;}cont.cont = &&after_call1941;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch1942:;object_free(&val);val = proc.proc(argl); after_call1941:;object_free(&argl);argl =restore();argl = cons(object_copy(val), argl);object_free(&proc);proc =restore();object_free(&cont);cont =restore();if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch1944;}object_free(&val);
                    val = compiled_procedure_entry(proc);
                    goto *val.cont;primitive_branch1944:;object_free(&val);val = proc.proc(argl); goto *cont.cont;false_branch1920:;save(cont);save(env);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|compound-procedure?|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|procedure|"));argl = cons(object_copy(val),empty);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch1940;}cont.cont = &&after_call1939;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch1940:;object_free(&val);val = proc.proc(argl); after_call1939:;object_free(&env);env =restore();object_free(&cont);cont =restore();if(val.type==BOOLEAN && !val.boolean){
                        goto false_branch1922;}save(cont);save(env);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|extend-environment|"));save(proc);save(env);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|procedure-environment|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|procedure|"));argl = cons(object_copy(val),empty);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch1934;}cont.cont = &&after_call1933;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch1934:;object_free(&val);val = proc.proc(argl); after_call1933:;argl = cons(object_copy(val),empty);object_free(&env);env =restore();object_free(&val);val = lookup_var_val(c_str_to_datum("|arguments|"));argl = cons(object_copy(val), argl);save(argl);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|procedure-parameters|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|procedure|"));argl = cons(object_copy(val),empty);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch1936;}cont.cont = &&after_call1935;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch1936:;object_free(&val);val = proc.proc(argl); after_call1935:;object_free(&argl);argl =restore();argl = cons(object_copy(val), argl);object_free(&proc);proc =restore();if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch1938;}cont.cont = &&after_call1937;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch1938:;object_free(&val);val = proc.proc(argl); after_call1937:;object_free(&env);env =restore();{Object t = def_var_val(c_str_to_datum("|env|"));
                                   object_free(&val);val = t;}object_free(&cont);cont =restore();save(cont);save(env);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|error-object?|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|env|"));argl = cons(object_copy(val),empty);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch1932;}cont.cont = &&after_call1931;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch1932:;object_free(&val);val = proc.proc(argl); after_call1931:;object_free(&env);env =restore();object_free(&cont);cont =restore();if(val.type==BOOLEAN && !val.boolean){
                        goto false_branch1926;}object_free(&val);val = lookup_var_val(c_str_to_datum("|env|"));goto *cont.cont;false_branch1926:;object_free(&proc);proc = lookup_var_val(c_str_to_datum("|eval-sequence|"));save(cont);save(proc);object_free(&val);val = lookup_var_val(c_str_to_datum("|env|"));argl = cons(object_copy(val),empty);save(argl);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|procedure-body|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|procedure|"));argl = cons(object_copy(val),empty);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch1928;}cont.cont = &&after_call1927;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch1928:;object_free(&val);val = proc.proc(argl); after_call1927:;object_free(&argl);argl =restore();argl = cons(object_copy(val), argl);object_free(&proc);proc =restore();object_free(&cont);cont =restore();if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch1930;}object_free(&val);
                    val = compiled_procedure_entry(proc);
                    goto *val.cont;primitive_branch1930:;object_free(&val);val = proc.proc(argl); goto *cont.cont;false_branch1922:;object_free(&proc);proc = lookup_var_val(c_str_to_datum("|error|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|procedure|"));argl = cons(object_copy(val),empty);object_free(&val);val = c_str_to_datum("\"unknown procedure type --\"");argl = cons(object_copy(val), argl);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch1924;}object_free(&val);
                    val = compiled_procedure_entry(proc);
                    goto *val.cont;primitive_branch1924:;object_free(&val);val = proc.proc(argl); goto *cont.cont;after_lambda1917:;{Object t = def_var_val(c_str_to_datum("|apply|"));
                                   object_free(&val);val = t;}object_free(&val);val = make_compiled_procedure(&&entry1864);goto after_lambda1863;entry1864:env = compiled_procedure_env();
                          env = extend_environment(c_str_to_datum("(|exp| . ())"));save(cont);save(env);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|boolean?|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|exp|"));argl = cons(object_copy(val),empty);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch1916;}cont.cont = &&after_call1915;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch1916:;object_free(&val);val = proc.proc(argl); after_call1915:;object_free(&env);env =restore();object_free(&cont);cont =restore();if(val.type==BOOLEAN && !val.boolean){
                        goto false_branch1866;}object_free(&proc);proc = lookup_var_val(c_str_to_datum("|boolean?|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|exp|"));argl = cons(object_copy(val),empty);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch1914;}object_free(&val);
                    val = compiled_procedure_entry(proc);
                    goto *val.cont;primitive_branch1914:;object_free(&val);val = proc.proc(argl); goto *cont.cont;false_branch1866:;save(cont);save(env);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|number?|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|exp|"));argl = cons(object_copy(val),empty);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch1912;}cont.cont = &&after_call1911;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch1912:;object_free(&val);val = proc.proc(argl); after_call1911:;object_free(&env);env =restore();object_free(&cont);cont =restore();if(val.type==BOOLEAN && !val.boolean){
                        goto false_branch1868;}object_free(&proc);proc = lookup_var_val(c_str_to_datum("|number?|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|exp|"));argl = cons(object_copy(val),empty);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch1910;}object_free(&val);
                    val = compiled_procedure_entry(proc);
                    goto *val.cont;primitive_branch1910:;object_free(&val);val = proc.proc(argl); goto *cont.cont;false_branch1868:;save(cont);save(env);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|vector?|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|exp|"));argl = cons(object_copy(val),empty);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch1908;}cont.cont = &&after_call1907;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch1908:;object_free(&val);val = proc.proc(argl); after_call1907:;object_free(&env);env =restore();object_free(&cont);cont =restore();if(val.type==BOOLEAN && !val.boolean){
                        goto false_branch1870;}object_free(&proc);proc = lookup_var_val(c_str_to_datum("|vector?|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|exp|"));argl = cons(object_copy(val),empty);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch1906;}object_free(&val);
                    val = compiled_procedure_entry(proc);
                    goto *val.cont;primitive_branch1906:;object_free(&val);val = proc.proc(argl); goto *cont.cont;false_branch1870:;save(cont);save(env);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|c-char?|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|exp|"));argl = cons(object_copy(val),empty);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch1904;}cont.cont = &&after_call1903;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch1904:;object_free(&val);val = proc.proc(argl); after_call1903:;object_free(&env);env =restore();object_free(&cont);cont =restore();if(val.type==BOOLEAN && !val.boolean){
                        goto false_branch1872;}object_free(&proc);proc = lookup_var_val(c_str_to_datum("|c-char?|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|exp|"));argl = cons(object_copy(val),empty);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch1902;}object_free(&val);
                    val = compiled_procedure_entry(proc);
                    goto *val.cont;primitive_branch1902:;object_free(&val);val = proc.proc(argl); goto *cont.cont;false_branch1872:;save(cont);save(env);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|string?|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|exp|"));argl = cons(object_copy(val),empty);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch1900;}cont.cont = &&after_call1899;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch1900:;object_free(&val);val = proc.proc(argl); after_call1899:;object_free(&env);env =restore();object_free(&cont);cont =restore();if(val.type==BOOLEAN && !val.boolean){
                        goto false_branch1874;}object_free(&proc);proc = lookup_var_val(c_str_to_datum("|string?|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|exp|"));argl = cons(object_copy(val),empty);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch1898;}object_free(&val);
                    val = compiled_procedure_entry(proc);
                    goto *val.cont;primitive_branch1898:;object_free(&val);val = proc.proc(argl); goto *cont.cont;false_branch1874:;save(cont);save(env);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|bytevector?|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|exp|"));argl = cons(object_copy(val),empty);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch1896;}cont.cont = &&after_call1895;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch1896:;object_free(&val);val = proc.proc(argl); after_call1895:;object_free(&env);env =restore();object_free(&cont);cont =restore();if(val.type==BOOLEAN && !val.boolean){
                        goto false_branch1876;}object_free(&proc);proc = lookup_var_val(c_str_to_datum("|bytevector?|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|exp|"));argl = cons(object_copy(val),empty);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch1894;}object_free(&val);
                    val = compiled_procedure_entry(proc);
                    goto *val.cont;primitive_branch1894:;object_free(&val);val = proc.proc(argl); goto *cont.cont;false_branch1876:;save(cont);save(env);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|procedure?|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|exp|"));argl = cons(object_copy(val),empty);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch1892;}cont.cont = &&after_call1891;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch1892:;object_free(&val);val = proc.proc(argl); after_call1891:;object_free(&env);env =restore();object_free(&cont);cont =restore();if(val.type==BOOLEAN && !val.boolean){
                        goto false_branch1878;}object_free(&proc);proc = lookup_var_val(c_str_to_datum("|procedure?|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|exp|"));argl = cons(object_copy(val),empty);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch1890;}object_free(&val);
                    val = compiled_procedure_entry(proc);
                    goto *val.cont;primitive_branch1890:;object_free(&val);val = proc.proc(argl); goto *cont.cont;false_branch1878:;save(cont);save(env);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|eq?|"));object_free(&val);val = c_str_to_datum("#false");if(val.type==BOOLEAN && !val.boolean){
                        goto false_branch1886;}object_free(&val);val = c_str_to_datum("#false");goto after_if1885;false_branch1886:;object_free(&val);val = undef;after_if1885:;argl = cons(object_copy(val),empty);object_free(&val);val = lookup_var_val(c_str_to_datum("|exp|"));argl = cons(object_copy(val), argl);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch1888;}cont.cont = &&after_call1887;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch1888:;object_free(&val);val = proc.proc(argl); after_call1887:;object_free(&env);env =restore();object_free(&cont);cont =restore();if(val.type==BOOLEAN && !val.boolean){
                        goto false_branch1880;}object_free(&proc);proc = lookup_var_val(c_str_to_datum("|eq?|"));object_free(&val);val = c_str_to_datum("#false");if(val.type==BOOLEAN && !val.boolean){
                        goto false_branch1882;}object_free(&val);val = c_str_to_datum("#false");goto after_if1881;false_branch1882:;object_free(&val);val = undef;after_if1881:;argl = cons(object_copy(val),empty);object_free(&val);val = lookup_var_val(c_str_to_datum("|exp|"));argl = cons(object_copy(val), argl);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch1884;}object_free(&val);
                    val = compiled_procedure_entry(proc);
                    goto *val.cont;primitive_branch1884:;object_free(&val);val = proc.proc(argl); goto *cont.cont;false_branch1880:;object_free(&val);val = c_str_to_datum("#false");goto *cont.cont;after_lambda1863:;{Object t = def_var_val(c_str_to_datum("|self-evaluating?|"));
                                   object_free(&val);val = t;}object_free(&val);val = make_compiled_procedure(&&entry1860);goto after_lambda1859;entry1860:env = compiled_procedure_env();
                          env = extend_environment(c_str_to_datum("(|exp| . ())"));object_free(&proc);proc = lookup_var_val(c_str_to_datum("|symbol?|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|exp|"));argl = cons(object_copy(val),empty);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch1862;}object_free(&val);
                    val = compiled_procedure_entry(proc);
                    goto *val.cont;primitive_branch1862:;object_free(&val);val = proc.proc(argl); goto *cont.cont;after_lambda1859:;{Object t = def_var_val(c_str_to_datum("|variable?|"));
                                   object_free(&val);val = t;}object_free(&val);val = make_compiled_procedure(&&entry1856);goto after_lambda1855;entry1856:env = compiled_procedure_env();
                          env = extend_environment(c_str_to_datum("(|exp| . ())"));object_free(&proc);proc = lookup_var_val(c_str_to_datum("|tagged-list?|"));object_free(&val);val = c_str_to_datum("|quote|");argl = cons(object_copy(val),empty);object_free(&val);val = lookup_var_val(c_str_to_datum("|exp|"));argl = cons(object_copy(val), argl);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch1858;}object_free(&val);
                    val = compiled_procedure_entry(proc);
                    goto *val.cont;primitive_branch1858:;object_free(&val);val = proc.proc(argl); goto *cont.cont;after_lambda1855:;{Object t = def_var_val(c_str_to_datum("|quoted?|"));
                                   object_free(&val);val = t;}object_free(&val);val = make_compiled_procedure(&&entry1850);goto after_lambda1849;entry1850:env = compiled_procedure_env();
                          env = extend_environment(c_str_to_datum("(|exp| . ())"));object_free(&proc);proc = lookup_var_val(c_str_to_datum("|car|"));save(cont);save(proc);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|cdr|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|exp|"));argl = cons(object_copy(val),empty);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch1852;}cont.cont = &&after_call1851;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch1852:;object_free(&val);val = proc.proc(argl); after_call1851:;argl = cons(object_copy(val),empty);object_free(&proc);proc =restore();object_free(&cont);cont =restore();if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch1854;}object_free(&val);
                    val = compiled_procedure_entry(proc);
                    goto *val.cont;primitive_branch1854:;object_free(&val);val = proc.proc(argl); goto *cont.cont;after_lambda1849:;{Object t = def_var_val(c_str_to_datum("|text-of-quotation|"));
                                   object_free(&val);val = t;}object_free(&val);val = make_compiled_procedure(&&entry1840);goto after_lambda1839;entry1840:env = compiled_procedure_env();
                          env = extend_environment(c_str_to_datum("(|exp| . (|tag| . ()))"));save(cont);save(env);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|pair?|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|exp|"));argl = cons(object_copy(val),empty);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch1848;}cont.cont = &&after_call1847;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch1848:;object_free(&val);val = proc.proc(argl); after_call1847:;object_free(&env);env =restore();object_free(&cont);cont =restore();if(val.type==BOOLEAN && !val.boolean){
                        goto false_branch1842;}object_free(&proc);proc = lookup_var_val(c_str_to_datum("|eq?|"));save(cont);save(proc);object_free(&val);val = lookup_var_val(c_str_to_datum("|tag|"));argl = cons(object_copy(val),empty);save(argl);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|car|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|exp|"));argl = cons(object_copy(val),empty);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch1844;}cont.cont = &&after_call1843;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch1844:;object_free(&val);val = proc.proc(argl); after_call1843:;object_free(&argl);argl =restore();argl = cons(object_copy(val), argl);object_free(&proc);proc =restore();object_free(&cont);cont =restore();if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch1846;}object_free(&val);
                    val = compiled_procedure_entry(proc);
                    goto *val.cont;primitive_branch1846:;object_free(&val);val = proc.proc(argl); goto *cont.cont;false_branch1842:;object_free(&val);val = c_str_to_datum("#false");goto *cont.cont;after_lambda1839:;{Object t = def_var_val(c_str_to_datum("|tagged-list?|"));
                                   object_free(&val);val = t;}object_free(&val);val = make_compiled_procedure(&&entry1836);goto after_lambda1835;entry1836:env = compiled_procedure_env();
                          env = extend_environment(c_str_to_datum("(|exp| . ())"));object_free(&proc);proc = lookup_var_val(c_str_to_datum("|tagged-list?|"));object_free(&val);val = c_str_to_datum("|lambda|");argl = cons(object_copy(val),empty);object_free(&val);val = lookup_var_val(c_str_to_datum("|exp|"));argl = cons(object_copy(val), argl);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch1838;}object_free(&val);
                    val = compiled_procedure_entry(proc);
                    goto *val.cont;primitive_branch1838:;object_free(&val);val = proc.proc(argl); goto *cont.cont;after_lambda1835:;{Object t = def_var_val(c_str_to_datum("|lambda?|"));
                                   object_free(&val);val = t;}object_free(&val);val = make_compiled_procedure(&&entry1830);goto after_lambda1829;entry1830:env = compiled_procedure_env();
                          env = extend_environment(c_str_to_datum("(|exp| . ())"));object_free(&proc);proc = lookup_var_val(c_str_to_datum("|car|"));save(cont);save(proc);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|cdr|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|exp|"));argl = cons(object_copy(val),empty);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch1832;}cont.cont = &&after_call1831;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch1832:;object_free(&val);val = proc.proc(argl); after_call1831:;argl = cons(object_copy(val),empty);object_free(&proc);proc =restore();object_free(&cont);cont =restore();if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch1834;}object_free(&val);
                    val = compiled_procedure_entry(proc);
                    goto *val.cont;primitive_branch1834:;object_free(&val);val = proc.proc(argl); goto *cont.cont;after_lambda1829:;{Object t = def_var_val(c_str_to_datum("|lambda-parameters|"));
                                   object_free(&val);val = t;}object_free(&val);val = make_compiled_procedure(&&entry1824);goto after_lambda1823;entry1824:env = compiled_procedure_env();
                          env = extend_environment(c_str_to_datum("(|exp| . ())"));object_free(&proc);proc = lookup_var_val(c_str_to_datum("|cdr|"));save(cont);save(proc);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|cdr|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|exp|"));argl = cons(object_copy(val),empty);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch1826;}cont.cont = &&after_call1825;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch1826:;object_free(&val);val = proc.proc(argl); after_call1825:;argl = cons(object_copy(val),empty);object_free(&proc);proc =restore();object_free(&cont);cont =restore();if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch1828;}object_free(&val);
                    val = compiled_procedure_entry(proc);
                    goto *val.cont;primitive_branch1828:;object_free(&val);val = proc.proc(argl); goto *cont.cont;after_lambda1823:;{Object t = def_var_val(c_str_to_datum("|lambda-body|"));
                                   object_free(&val);val = t;}object_free(&val);val = make_compiled_procedure(&&entry1818);goto after_lambda1817;entry1818:env = compiled_procedure_env();
                          env = extend_environment(c_str_to_datum("(|parameters| . (|body| . ()))"));object_free(&proc);proc = lookup_var_val(c_str_to_datum("|cons|"));save(cont);save(proc);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|cons|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|body|"));argl = cons(object_copy(val),empty);object_free(&val);val = lookup_var_val(c_str_to_datum("|parameters|"));argl = cons(object_copy(val), argl);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch1820;}cont.cont = &&after_call1819;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch1820:;object_free(&val);val = proc.proc(argl); after_call1819:;argl = cons(object_copy(val),empty);object_free(&val);val = c_str_to_datum("|lambda|");argl = cons(object_copy(val), argl);object_free(&proc);proc =restore();object_free(&cont);cont =restore();if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch1822;}object_free(&val);
                    val = compiled_procedure_entry(proc);
                    goto *val.cont;primitive_branch1822:;object_free(&val);val = proc.proc(argl); goto *cont.cont;after_lambda1817:;{Object t = def_var_val(c_str_to_datum("|make-lambda|"));
                                   object_free(&val);val = t;}object_free(&val);val = make_compiled_procedure(&&entry1814);goto after_lambda1813;entry1814:env = compiled_procedure_env();
                          env = extend_environment(c_str_to_datum("(|exp| . ())"));object_free(&proc);proc = lookup_var_val(c_str_to_datum("|tagged-list?|"));object_free(&val);val = c_str_to_datum("|if|");argl = cons(object_copy(val),empty);object_free(&val);val = lookup_var_val(c_str_to_datum("|exp|"));argl = cons(object_copy(val), argl);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch1816;}object_free(&val);
                    val = compiled_procedure_entry(proc);
                    goto *val.cont;primitive_branch1816:;object_free(&val);val = proc.proc(argl); goto *cont.cont;after_lambda1813:;{Object t = def_var_val(c_str_to_datum("|if?|"));
                                   object_free(&val);val = t;}object_free(&val);val = make_compiled_procedure(&&entry1808);goto after_lambda1807;entry1808:env = compiled_procedure_env();
                          env = extend_environment(c_str_to_datum("(|exp| . ())"));object_free(&proc);proc = lookup_var_val(c_str_to_datum("|car|"));save(cont);save(proc);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|cdr|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|exp|"));argl = cons(object_copy(val),empty);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch1810;}cont.cont = &&after_call1809;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch1810:;object_free(&val);val = proc.proc(argl); after_call1809:;argl = cons(object_copy(val),empty);object_free(&proc);proc =restore();object_free(&cont);cont =restore();if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch1812;}object_free(&val);
                    val = compiled_procedure_entry(proc);
                    goto *val.cont;primitive_branch1812:;object_free(&val);val = proc.proc(argl); goto *cont.cont;after_lambda1807:;{Object t = def_var_val(c_str_to_datum("|if-predicate|"));
                                   object_free(&val);val = t;}object_free(&val);val = make_compiled_procedure(&&entry1800);goto after_lambda1799;entry1800:env = compiled_procedure_env();
                          env = extend_environment(c_str_to_datum("(|exp| . ())"));object_free(&proc);proc = lookup_var_val(c_str_to_datum("|car|"));save(cont);save(proc);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|cdr|"));save(proc);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|cdr|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|exp|"));argl = cons(object_copy(val),empty);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch1802;}cont.cont = &&after_call1801;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch1802:;object_free(&val);val = proc.proc(argl); after_call1801:;argl = cons(object_copy(val),empty);object_free(&proc);proc =restore();if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch1804;}cont.cont = &&after_call1803;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch1804:;object_free(&val);val = proc.proc(argl); after_call1803:;argl = cons(object_copy(val),empty);object_free(&proc);proc =restore();object_free(&cont);cont =restore();if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch1806;}object_free(&val);
                    val = compiled_procedure_entry(proc);
                    goto *val.cont;primitive_branch1806:;object_free(&val);val = proc.proc(argl); goto *cont.cont;after_lambda1799:;{Object t = def_var_val(c_str_to_datum("|if-consequent|"));
                                   object_free(&val);val = t;}object_free(&val);val = make_compiled_procedure(&&entry1778);goto after_lambda1777;entry1778:env = compiled_procedure_env();
                          env = extend_environment(c_str_to_datum("(|exp| . ())"));save(cont);save(env);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|not|"));save(proc);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|null?|"));save(proc);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|cdr|"));save(proc);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|cdr|"));save(proc);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|cdr|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|exp|"));argl = cons(object_copy(val),empty);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch1790;}cont.cont = &&after_call1789;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch1790:;object_free(&val);val = proc.proc(argl); after_call1789:;argl = cons(object_copy(val),empty);object_free(&proc);proc =restore();if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch1792;}cont.cont = &&after_call1791;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch1792:;object_free(&val);val = proc.proc(argl); after_call1791:;argl = cons(object_copy(val),empty);object_free(&proc);proc =restore();if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch1794;}cont.cont = &&after_call1793;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch1794:;object_free(&val);val = proc.proc(argl); after_call1793:;argl = cons(object_copy(val),empty);object_free(&proc);proc =restore();if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch1796;}cont.cont = &&after_call1795;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch1796:;object_free(&val);val = proc.proc(argl); after_call1795:;argl = cons(object_copy(val),empty);object_free(&proc);proc =restore();if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch1798;}cont.cont = &&after_call1797;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch1798:;object_free(&val);val = proc.proc(argl); after_call1797:;object_free(&env);env =restore();object_free(&cont);cont =restore();if(val.type==BOOLEAN && !val.boolean){
                        goto false_branch1780;}object_free(&proc);proc = lookup_var_val(c_str_to_datum("|car|"));save(cont);save(proc);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|cdr|"));save(proc);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|cdr|"));save(proc);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|cdr|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|exp|"));argl = cons(object_copy(val),empty);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch1782;}cont.cont = &&after_call1781;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch1782:;object_free(&val);val = proc.proc(argl); after_call1781:;argl = cons(object_copy(val),empty);object_free(&proc);proc =restore();if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch1784;}cont.cont = &&after_call1783;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch1784:;object_free(&val);val = proc.proc(argl); after_call1783:;argl = cons(object_copy(val),empty);object_free(&proc);proc =restore();if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch1786;}cont.cont = &&after_call1785;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch1786:;object_free(&val);val = proc.proc(argl); after_call1785:;argl = cons(object_copy(val),empty);object_free(&proc);proc =restore();object_free(&cont);cont =restore();if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch1788;}object_free(&val);
                    val = compiled_procedure_entry(proc);
                    goto *val.cont;primitive_branch1788:;object_free(&val);val = proc.proc(argl); goto *cont.cont;false_branch1780:;object_free(&val);val = undef;goto *cont.cont;after_lambda1777:;{Object t = def_var_val(c_str_to_datum("|if-alternative|"));
                                   object_free(&val);val = t;}object_free(&val);val = make_compiled_procedure(&&entry1774);goto after_lambda1773;entry1774:env = compiled_procedure_env();
                          env = extend_environment(c_str_to_datum("(|exp| . ())"));object_free(&proc);proc = lookup_var_val(c_str_to_datum("|tagged-list?|"));object_free(&val);val = c_str_to_datum("|begin|");argl = cons(object_copy(val),empty);object_free(&val);val = lookup_var_val(c_str_to_datum("|exp|"));argl = cons(object_copy(val), argl);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch1776;}object_free(&val);
                    val = compiled_procedure_entry(proc);
                    goto *val.cont;primitive_branch1776:;object_free(&val);val = proc.proc(argl); goto *cont.cont;after_lambda1773:;{Object t = def_var_val(c_str_to_datum("|begin?|"));
                                   object_free(&val);val = t;}object_free(&val);val = make_compiled_procedure(&&entry1770);goto after_lambda1769;entry1770:env = compiled_procedure_env();
                          env = extend_environment(c_str_to_datum("(|exp| . ())"));object_free(&proc);proc = lookup_var_val(c_str_to_datum("|cdr|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|exp|"));argl = cons(object_copy(val),empty);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch1772;}object_free(&val);
                    val = compiled_procedure_entry(proc);
                    goto *val.cont;primitive_branch1772:;object_free(&val);val = proc.proc(argl); goto *cont.cont;after_lambda1769:;{Object t = def_var_val(c_str_to_datum("|begin-actions|"));
                                   object_free(&val);val = t;}object_free(&val);val = make_compiled_procedure(&&entry1766);goto after_lambda1765;entry1766:env = compiled_procedure_env();
                          env = extend_environment(c_str_to_datum("(|exp| . ())"));object_free(&proc);proc = lookup_var_val(c_str_to_datum("|tagged-list?|"));object_free(&val);val = c_str_to_datum("|load|");argl = cons(object_copy(val),empty);object_free(&val);val = lookup_var_val(c_str_to_datum("|exp|"));argl = cons(object_copy(val), argl);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch1768;}object_free(&val);
                    val = compiled_procedure_entry(proc);
                    goto *val.cont;primitive_branch1768:;object_free(&val);val = proc.proc(argl); goto *cont.cont;after_lambda1765:;{Object t = def_var_val(c_str_to_datum("|load?|"));
                                   object_free(&val);val = t;}object_free(&val);val = make_compiled_procedure(&&entry1762);goto after_lambda1761;entry1762:env = compiled_procedure_env();
                          env = extend_environment(c_str_to_datum("(|exp| . ())"));object_free(&proc);proc = lookup_var_val(c_str_to_datum("|tagged-list?|"));object_free(&val);val = c_str_to_datum("|define|");argl = cons(object_copy(val),empty);object_free(&val);val = lookup_var_val(c_str_to_datum("|exp|"));argl = cons(object_copy(val), argl);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch1764;}object_free(&val);
                    val = compiled_procedure_entry(proc);
                    goto *val.cont;primitive_branch1764:;object_free(&val);val = proc.proc(argl); goto *cont.cont;after_lambda1761:;{Object t = def_var_val(c_str_to_datum("|definition?|"));
                                   object_free(&val);val = t;}object_free(&val);val = make_compiled_procedure(&&entry1742);goto after_lambda1741;entry1742:env = compiled_procedure_env();
                          env = extend_environment(c_str_to_datum("(|exp| . ())"));save(cont);save(env);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|symbol?|"));save(proc);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|car|"));save(proc);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|cdr|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|exp|"));argl = cons(object_copy(val),empty);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch1756;}cont.cont = &&after_call1755;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch1756:;object_free(&val);val = proc.proc(argl); after_call1755:;argl = cons(object_copy(val),empty);object_free(&proc);proc =restore();if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch1758;}cont.cont = &&after_call1757;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch1758:;object_free(&val);val = proc.proc(argl); after_call1757:;argl = cons(object_copy(val),empty);object_free(&proc);proc =restore();if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch1760;}cont.cont = &&after_call1759;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch1760:;object_free(&val);val = proc.proc(argl); after_call1759:;object_free(&env);env =restore();object_free(&cont);cont =restore();if(val.type==BOOLEAN && !val.boolean){
                        goto false_branch1744;}object_free(&proc);proc = lookup_var_val(c_str_to_datum("|car|"));save(cont);save(proc);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|cdr|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|exp|"));argl = cons(object_copy(val),empty);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch1752;}cont.cont = &&after_call1751;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch1752:;object_free(&val);val = proc.proc(argl); after_call1751:;argl = cons(object_copy(val),empty);object_free(&proc);proc =restore();object_free(&cont);cont =restore();if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch1754;}object_free(&val);
                    val = compiled_procedure_entry(proc);
                    goto *val.cont;primitive_branch1754:;object_free(&val);val = proc.proc(argl); goto *cont.cont;false_branch1744:;object_free(&proc);proc = lookup_var_val(c_str_to_datum("|car|"));save(cont);save(proc);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|car|"));save(proc);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|cdr|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|exp|"));argl = cons(object_copy(val),empty);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch1746;}cont.cont = &&after_call1745;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch1746:;object_free(&val);val = proc.proc(argl); after_call1745:;argl = cons(object_copy(val),empty);object_free(&proc);proc =restore();if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch1748;}cont.cont = &&after_call1747;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch1748:;object_free(&val);val = proc.proc(argl); after_call1747:;argl = cons(object_copy(val),empty);object_free(&proc);proc =restore();object_free(&cont);cont =restore();if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch1750;}object_free(&val);
                    val = compiled_procedure_entry(proc);
                    goto *val.cont;primitive_branch1750:;object_free(&val);val = proc.proc(argl); goto *cont.cont;after_lambda1741:;{Object t = def_var_val(c_str_to_datum("|definition-variable|"));
                                   object_free(&val);val = t;}object_free(&val);val = make_compiled_procedure(&&entry1714);goto after_lambda1713;entry1714:env = compiled_procedure_env();
                          env = extend_environment(c_str_to_datum("(|exp| . ())"));save(cont);save(env);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|symbol?|"));save(proc);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|car|"));save(proc);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|cdr|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|exp|"));argl = cons(object_copy(val),empty);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch1736;}cont.cont = &&after_call1735;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch1736:;object_free(&val);val = proc.proc(argl); after_call1735:;argl = cons(object_copy(val),empty);object_free(&proc);proc =restore();if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch1738;}cont.cont = &&after_call1737;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch1738:;object_free(&val);val = proc.proc(argl); after_call1737:;argl = cons(object_copy(val),empty);object_free(&proc);proc =restore();if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch1740;}cont.cont = &&after_call1739;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch1740:;object_free(&val);val = proc.proc(argl); after_call1739:;object_free(&env);env =restore();object_free(&cont);cont =restore();if(val.type==BOOLEAN && !val.boolean){
                        goto false_branch1716;}object_free(&proc);proc = lookup_var_val(c_str_to_datum("|car|"));save(cont);save(proc);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|cdr|"));save(proc);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|cdr|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|exp|"));argl = cons(object_copy(val),empty);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch1730;}cont.cont = &&after_call1729;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch1730:;object_free(&val);val = proc.proc(argl); after_call1729:;argl = cons(object_copy(val),empty);object_free(&proc);proc =restore();if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch1732;}cont.cont = &&after_call1731;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch1732:;object_free(&val);val = proc.proc(argl); after_call1731:;argl = cons(object_copy(val),empty);object_free(&proc);proc =restore();object_free(&cont);cont =restore();if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch1734;}object_free(&val);
                    val = compiled_procedure_entry(proc);
                    goto *val.cont;primitive_branch1734:;object_free(&val);val = proc.proc(argl); goto *cont.cont;false_branch1716:;object_free(&proc);proc = lookup_var_val(c_str_to_datum("|make-lambda|"));save(cont);save(proc);save(env);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|cdr|"));save(proc);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|cdr|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|exp|"));argl = cons(object_copy(val),empty);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch1718;}cont.cont = &&after_call1717;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch1718:;object_free(&val);val = proc.proc(argl); after_call1717:;argl = cons(object_copy(val),empty);object_free(&proc);proc =restore();if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch1720;}cont.cont = &&after_call1719;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch1720:;object_free(&val);val = proc.proc(argl); after_call1719:;argl = cons(object_copy(val),empty);object_free(&env);env =restore();save(argl);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|cdr|"));save(proc);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|car|"));save(proc);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|cdr|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|exp|"));argl = cons(object_copy(val),empty);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch1722;}cont.cont = &&after_call1721;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch1722:;object_free(&val);val = proc.proc(argl); after_call1721:;argl = cons(object_copy(val),empty);object_free(&proc);proc =restore();if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch1724;}cont.cont = &&after_call1723;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch1724:;object_free(&val);val = proc.proc(argl); after_call1723:;argl = cons(object_copy(val),empty);object_free(&proc);proc =restore();if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch1726;}cont.cont = &&after_call1725;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch1726:;object_free(&val);val = proc.proc(argl); after_call1725:;object_free(&argl);argl =restore();argl = cons(object_copy(val), argl);object_free(&proc);proc =restore();object_free(&cont);cont =restore();if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch1728;}object_free(&val);
                    val = compiled_procedure_entry(proc);
                    goto *val.cont;primitive_branch1728:;object_free(&val);val = proc.proc(argl); goto *cont.cont;after_lambda1713:;{Object t = def_var_val(c_str_to_datum("|definition-value|"));
                                   object_free(&val);val = t;}object_free(&val);val = make_compiled_procedure(&&entry1710);goto after_lambda1709;entry1710:env = compiled_procedure_env();
                          env = extend_environment(c_str_to_datum("(|exp| . ())"));object_free(&proc);proc = lookup_var_val(c_str_to_datum("|tagged-list?|"));object_free(&val);val = c_str_to_datum("|set!|");argl = cons(object_copy(val),empty);object_free(&val);val = lookup_var_val(c_str_to_datum("|exp|"));argl = cons(object_copy(val), argl);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch1712;}object_free(&val);
                    val = compiled_procedure_entry(proc);
                    goto *val.cont;primitive_branch1712:;object_free(&val);val = proc.proc(argl); goto *cont.cont;after_lambda1709:;{Object t = def_var_val(c_str_to_datum("|assignment?|"));
                                   object_free(&val);val = t;}object_free(&val);val = make_compiled_procedure(&&entry1704);goto after_lambda1703;entry1704:env = compiled_procedure_env();
                          env = extend_environment(c_str_to_datum("(|exp| . ())"));object_free(&proc);proc = lookup_var_val(c_str_to_datum("|car|"));save(cont);save(proc);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|cdr|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|exp|"));argl = cons(object_copy(val),empty);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch1706;}cont.cont = &&after_call1705;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch1706:;object_free(&val);val = proc.proc(argl); after_call1705:;argl = cons(object_copy(val),empty);object_free(&proc);proc =restore();object_free(&cont);cont =restore();if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch1708;}object_free(&val);
                    val = compiled_procedure_entry(proc);
                    goto *val.cont;primitive_branch1708:;object_free(&val);val = proc.proc(argl); goto *cont.cont;after_lambda1703:;{Object t = def_var_val(c_str_to_datum("|assignment-variable|"));
                                   object_free(&val);val = t;}object_free(&val);val = make_compiled_procedure(&&entry1696);goto after_lambda1695;entry1696:env = compiled_procedure_env();
                          env = extend_environment(c_str_to_datum("(|exp| . ())"));object_free(&proc);proc = lookup_var_val(c_str_to_datum("|car|"));save(cont);save(proc);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|cdr|"));save(proc);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|cdr|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|exp|"));argl = cons(object_copy(val),empty);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch1698;}cont.cont = &&after_call1697;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch1698:;object_free(&val);val = proc.proc(argl); after_call1697:;argl = cons(object_copy(val),empty);object_free(&proc);proc =restore();if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch1700;}cont.cont = &&after_call1699;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch1700:;object_free(&val);val = proc.proc(argl); after_call1699:;argl = cons(object_copy(val),empty);object_free(&proc);proc =restore();object_free(&cont);cont =restore();if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch1702;}object_free(&val);
                    val = compiled_procedure_entry(proc);
                    goto *val.cont;primitive_branch1702:;object_free(&val);val = proc.proc(argl); goto *cont.cont;after_lambda1695:;{Object t = def_var_val(c_str_to_datum("|assignment-value|"));
                                   object_free(&val);val = t;}object_free(&val);val = make_compiled_procedure(&&entry1692);goto after_lambda1691;entry1692:env = compiled_procedure_env();
                          env = extend_environment(c_str_to_datum("(|env| . ())"));object_free(&proc);proc = lookup_var_val(c_str_to_datum("|car|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|env|"));argl = cons(object_copy(val),empty);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch1694;}object_free(&val);
                    val = compiled_procedure_entry(proc);
                    goto *val.cont;primitive_branch1694:;object_free(&val);val = proc.proc(argl); goto *cont.cont;after_lambda1691:;{Object t = def_var_val(c_str_to_datum("|first-frame|"));
                                   object_free(&val);val = t;}object_free(&val);val = c_str_to_datum("()");{Object t = def_var_val(c_str_to_datum("|the-empty-environment|"));
                                   object_free(&val);val = t;}object_free(&val);val = make_compiled_procedure(&&entry1688);goto after_lambda1687;entry1688:env = compiled_procedure_env();
                          env = extend_environment(c_str_to_datum("(|variables| . (|values| . ()))"));object_free(&proc);proc = lookup_var_val(c_str_to_datum("|cons|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|values|"));argl = cons(object_copy(val),empty);object_free(&val);val = lookup_var_val(c_str_to_datum("|variables|"));argl = cons(object_copy(val), argl);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch1690;}object_free(&val);
                    val = compiled_procedure_entry(proc);
                    goto *val.cont;primitive_branch1690:;object_free(&val);val = proc.proc(argl); goto *cont.cont;after_lambda1687:;{Object t = def_var_val(c_str_to_datum("|make-frame|"));
                                   object_free(&val);val = t;}object_free(&val);val = make_compiled_procedure(&&entry1684);goto after_lambda1683;entry1684:env = compiled_procedure_env();
                          env = extend_environment(c_str_to_datum("(|frame| . ())"));object_free(&proc);proc = lookup_var_val(c_str_to_datum("|car|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|frame|"));argl = cons(object_copy(val),empty);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch1686;}object_free(&val);
                    val = compiled_procedure_entry(proc);
                    goto *val.cont;primitive_branch1686:;object_free(&val);val = proc.proc(argl); goto *cont.cont;after_lambda1683:;{Object t = def_var_val(c_str_to_datum("|frame-variables|"));
                                   object_free(&val);val = t;}object_free(&val);val = make_compiled_procedure(&&entry1680);goto after_lambda1679;entry1680:env = compiled_procedure_env();
                          env = extend_environment(c_str_to_datum("(|frame| . ())"));object_free(&proc);proc = lookup_var_val(c_str_to_datum("|cdr|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|frame|"));argl = cons(object_copy(val),empty);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch1682;}object_free(&val);
                    val = compiled_procedure_entry(proc);
                    goto *val.cont;primitive_branch1682:;object_free(&val);val = proc.proc(argl); goto *cont.cont;after_lambda1679:;{Object t = def_var_val(c_str_to_datum("|frame-values|"));
                                   object_free(&val);val = t;}object_free(&val);val = make_compiled_procedure(&&entry1666);goto after_lambda1665;entry1666:env = compiled_procedure_env();
                          env = extend_environment(c_str_to_datum("(|var| . (|val| . (|frame| . ())))"));save(cont);save(env);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|set-car!|"));save(proc);save(env);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|cons|"));save(proc);save(env);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|car|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|frame|"));argl = cons(object_copy(val),empty);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch1674;}cont.cont = &&after_call1673;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch1674:;object_free(&val);val = proc.proc(argl); after_call1673:;argl = cons(object_copy(val),empty);object_free(&env);env =restore();object_free(&val);val = lookup_var_val(c_str_to_datum("|var|"));argl = cons(object_copy(val), argl);object_free(&proc);proc =restore();if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch1676;}cont.cont = &&after_call1675;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch1676:;object_free(&val);val = proc.proc(argl); after_call1675:;argl = cons(object_copy(val),empty);object_free(&env);env =restore();object_free(&val);val = lookup_var_val(c_str_to_datum("|frame|"));argl = cons(object_copy(val), argl);object_free(&proc);proc =restore();if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch1678;}cont.cont = &&after_call1677;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch1678:;object_free(&val);val = proc.proc(argl); after_call1677:;object_free(&env);env =restore();object_free(&cont);cont =restore();object_free(&proc);proc = lookup_var_val(c_str_to_datum("|set-cdr!|"));save(cont);save(proc);save(env);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|cons|"));save(proc);save(env);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|cdr|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|frame|"));argl = cons(object_copy(val),empty);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch1668;}cont.cont = &&after_call1667;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch1668:;object_free(&val);val = proc.proc(argl); after_call1667:;argl = cons(object_copy(val),empty);object_free(&env);env =restore();object_free(&val);val = lookup_var_val(c_str_to_datum("|val|"));argl = cons(object_copy(val), argl);object_free(&proc);proc =restore();if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch1670;}cont.cont = &&after_call1669;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch1670:;object_free(&val);val = proc.proc(argl); after_call1669:;argl = cons(object_copy(val),empty);object_free(&env);env =restore();object_free(&val);val = lookup_var_val(c_str_to_datum("|frame|"));argl = cons(object_copy(val), argl);object_free(&proc);proc =restore();object_free(&cont);cont =restore();if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch1672;}object_free(&val);
                    val = compiled_procedure_entry(proc);
                    goto *val.cont;primitive_branch1672:;object_free(&val);val = proc.proc(argl); goto *cont.cont;after_lambda1665:;{Object t = def_var_val(c_str_to_datum("|add-binding-to-frame!|"));
                                   object_free(&val);val = t;}object_free(&val);val = make_compiled_procedure(&&entry1630);goto after_lambda1629;entry1630:env = compiled_procedure_env();
                          env = extend_environment(c_str_to_datum("(|var| . (|val| . (|env| . ())))"));object_free(&proc);proc = make_compiled_procedure(&&entry1634);goto after_lambda1633;entry1634:env = compiled_procedure_env();
                          env = extend_environment(c_str_to_datum("(|frame| . ())"));object_free(&val);val = make_compiled_procedure(&&entry1642);goto after_lambda1641;entry1642:env = compiled_procedure_env();
                          env = extend_environment(c_str_to_datum("(|vars| . (|vals| . ()))"));save(cont);save(env);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|null?|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|vars|"));argl = cons(object_copy(val),empty);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch1662;}cont.cont = &&after_call1661;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch1662:;object_free(&val);val = proc.proc(argl); after_call1661:;object_free(&env);env =restore();object_free(&cont);cont =restore();if(val.type==BOOLEAN && !val.boolean){
                        goto false_branch1644;}object_free(&proc);proc = lookup_var_val(c_str_to_datum("|add-binding-to-frame!|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|frame|"));argl = cons(object_copy(val),empty);object_free(&val);val = lookup_var_val(c_str_to_datum("|val|"));argl = cons(object_copy(val), argl);object_free(&val);val = lookup_var_val(c_str_to_datum("|var|"));argl = cons(object_copy(val), argl);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch1660;}object_free(&val);
                    val = compiled_procedure_entry(proc);
                    goto *val.cont;primitive_branch1660:;object_free(&val);val = proc.proc(argl); goto *cont.cont;false_branch1644:;save(cont);save(env);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|eq?|"));save(proc);save(env);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|car|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|vars|"));argl = cons(object_copy(val),empty);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch1656;}cont.cont = &&after_call1655;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch1656:;object_free(&val);val = proc.proc(argl); after_call1655:;argl = cons(object_copy(val),empty);object_free(&env);env =restore();object_free(&val);val = lookup_var_val(c_str_to_datum("|var|"));argl = cons(object_copy(val), argl);object_free(&proc);proc =restore();if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch1658;}cont.cont = &&after_call1657;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch1658:;object_free(&val);val = proc.proc(argl); after_call1657:;object_free(&env);env =restore();object_free(&cont);cont =restore();if(val.type==BOOLEAN && !val.boolean){
                        goto false_branch1646;}object_free(&proc);proc = lookup_var_val(c_str_to_datum("|set-car!|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|val|"));argl = cons(object_copy(val),empty);object_free(&val);val = lookup_var_val(c_str_to_datum("|vals|"));argl = cons(object_copy(val), argl);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch1654;}object_free(&val);
                    val = compiled_procedure_entry(proc);
                    goto *val.cont;primitive_branch1654:;object_free(&val);val = proc.proc(argl); goto *cont.cont;false_branch1646:;object_free(&proc);proc = lookup_var_val(c_str_to_datum("|scan|"));save(cont);save(proc);save(env);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|cdr|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|vals|"));argl = cons(object_copy(val),empty);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch1648;}cont.cont = &&after_call1647;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch1648:;object_free(&val);val = proc.proc(argl); after_call1647:;argl = cons(object_copy(val),empty);object_free(&env);env =restore();save(argl);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|cdr|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|vars|"));argl = cons(object_copy(val),empty);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch1650;}cont.cont = &&after_call1649;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch1650:;object_free(&val);val = proc.proc(argl); after_call1649:;object_free(&argl);argl =restore();argl = cons(object_copy(val), argl);object_free(&proc);proc =restore();object_free(&cont);cont =restore();if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch1652;}object_free(&val);
                    val = compiled_procedure_entry(proc);
                    goto *val.cont;primitive_branch1652:;object_free(&val);val = proc.proc(argl); goto *cont.cont;after_lambda1641:;{Object t = def_var_val(c_str_to_datum("|scan|"));
                                   object_free(&val);val = t;}object_free(&proc);proc = lookup_var_val(c_str_to_datum("|scan|"));save(cont);save(proc);save(env);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|frame-values|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|frame|"));argl = cons(object_copy(val),empty);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch1636;}cont.cont = &&after_call1635;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch1636:;object_free(&val);val = proc.proc(argl); after_call1635:;argl = cons(object_copy(val),empty);object_free(&env);env =restore();save(argl);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|frame-variables|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|frame|"));argl = cons(object_copy(val),empty);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch1638;}cont.cont = &&after_call1637;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch1638:;object_free(&val);val = proc.proc(argl); after_call1637:;object_free(&argl);argl =restore();argl = cons(object_copy(val), argl);object_free(&proc);proc =restore();object_free(&cont);cont =restore();if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch1640;}object_free(&val);
                    val = compiled_procedure_entry(proc);
                    goto *val.cont;primitive_branch1640:;object_free(&val);val = proc.proc(argl); goto *cont.cont;after_lambda1633:;save(cont);save(proc);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|first-frame|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|env|"));argl = cons(object_copy(val),empty);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch1632;}cont.cont = &&after_call1631;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch1632:;object_free(&val);val = proc.proc(argl); after_call1631:;argl = cons(object_copy(val),empty);object_free(&proc);proc =restore();object_free(&cont);cont =restore();if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch1664;}object_free(&val);
                    val = compiled_procedure_entry(proc);
                    goto *val.cont;primitive_branch1664:;object_free(&val);val = proc.proc(argl); goto *cont.cont;after_lambda1629:;{Object t = def_var_val(c_str_to_datum("|define-variable!|"));
                                   object_free(&val);val = t;}object_free(&val);val = make_compiled_procedure(&&entry1582);goto after_lambda1581;entry1582:env = compiled_procedure_env();
                          env = extend_environment(c_str_to_datum("(|var| . (|val| . (|env| . ())))"));object_free(&val);val = make_compiled_procedure(&&entry1586);goto after_lambda1585;entry1586:env = compiled_procedure_env();
                          env = extend_environment(c_str_to_datum("(|env| . ())"));object_free(&val);val = make_compiled_procedure(&&entry1606);goto after_lambda1605;entry1606:env = compiled_procedure_env();
                          env = extend_environment(c_str_to_datum("(|vars| . (|vals| . ()))"));save(cont);save(env);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|null?|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|vars|"));argl = cons(object_copy(val),empty);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch1628;}cont.cont = &&after_call1627;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch1628:;object_free(&val);val = proc.proc(argl); after_call1627:;object_free(&env);env =restore();object_free(&cont);cont =restore();if(val.type==BOOLEAN && !val.boolean){
                        goto false_branch1608;}object_free(&proc);proc = lookup_var_val(c_str_to_datum("|env-loop|"));save(cont);save(proc);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|enclosing-environment|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|env|"));argl = cons(object_copy(val),empty);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch1624;}cont.cont = &&after_call1623;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch1624:;object_free(&val);val = proc.proc(argl); after_call1623:;argl = cons(object_copy(val),empty);object_free(&proc);proc =restore();object_free(&cont);cont =restore();if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch1626;}object_free(&val);
                    val = compiled_procedure_entry(proc);
                    goto *val.cont;primitive_branch1626:;object_free(&val);val = proc.proc(argl); goto *cont.cont;false_branch1608:;save(cont);save(env);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|eq?|"));save(proc);save(env);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|car|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|vars|"));argl = cons(object_copy(val),empty);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch1620;}cont.cont = &&after_call1619;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch1620:;object_free(&val);val = proc.proc(argl); after_call1619:;argl = cons(object_copy(val),empty);object_free(&env);env =restore();object_free(&val);val = lookup_var_val(c_str_to_datum("|var|"));argl = cons(object_copy(val), argl);object_free(&proc);proc =restore();if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch1622;}cont.cont = &&after_call1621;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch1622:;object_free(&val);val = proc.proc(argl); after_call1621:;object_free(&env);env =restore();object_free(&cont);cont =restore();if(val.type==BOOLEAN && !val.boolean){
                        goto false_branch1610;}object_free(&proc);proc = lookup_var_val(c_str_to_datum("|set-car!|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|val|"));argl = cons(object_copy(val),empty);object_free(&val);val = lookup_var_val(c_str_to_datum("|vals|"));argl = cons(object_copy(val), argl);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch1618;}object_free(&val);
                    val = compiled_procedure_entry(proc);
                    goto *val.cont;primitive_branch1618:;object_free(&val);val = proc.proc(argl); goto *cont.cont;false_branch1610:;object_free(&proc);proc = lookup_var_val(c_str_to_datum("|scan|"));save(cont);save(proc);save(env);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|cdr|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|vals|"));argl = cons(object_copy(val),empty);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch1612;}cont.cont = &&after_call1611;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch1612:;object_free(&val);val = proc.proc(argl); after_call1611:;argl = cons(object_copy(val),empty);object_free(&env);env =restore();save(argl);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|cdr|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|vars|"));argl = cons(object_copy(val),empty);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch1614;}cont.cont = &&after_call1613;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch1614:;object_free(&val);val = proc.proc(argl); after_call1613:;object_free(&argl);argl =restore();argl = cons(object_copy(val), argl);object_free(&proc);proc =restore();object_free(&cont);cont =restore();if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch1616;}object_free(&val);
                    val = compiled_procedure_entry(proc);
                    goto *val.cont;primitive_branch1616:;object_free(&val);val = proc.proc(argl); goto *cont.cont;after_lambda1605:;{Object t = def_var_val(c_str_to_datum("|scan|"));
                                   object_free(&val);val = t;}save(cont);save(env);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|eq?|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|the-empty-environment|"));argl = cons(object_copy(val),empty);object_free(&val);val = lookup_var_val(c_str_to_datum("|env|"));argl = cons(object_copy(val), argl);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch1604;}cont.cont = &&after_call1603;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch1604:;object_free(&val);val = proc.proc(argl); after_call1603:;object_free(&env);env =restore();object_free(&cont);cont =restore();if(val.type==BOOLEAN && !val.boolean){
                        goto false_branch1588;}object_free(&proc);proc = lookup_var_val(c_str_to_datum("|error|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|var|"));argl = cons(object_copy(val),empty);object_free(&val);val = c_str_to_datum("\"(set!) unbound variable --\"");argl = cons(object_copy(val), argl);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch1602;}object_free(&val);
                    val = compiled_procedure_entry(proc);
                    goto *val.cont;primitive_branch1602:;object_free(&val);val = proc.proc(argl); goto *cont.cont;false_branch1588:;object_free(&proc);proc = make_compiled_procedure(&&entry1592);goto after_lambda1591;entry1592:env = compiled_procedure_env();
                          env = extend_environment(c_str_to_datum("(|frame| . ())"));object_free(&proc);proc = lookup_var_val(c_str_to_datum("|scan|"));save(cont);save(proc);save(env);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|frame-values|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|frame|"));argl = cons(object_copy(val),empty);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch1594;}cont.cont = &&after_call1593;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch1594:;object_free(&val);val = proc.proc(argl); after_call1593:;argl = cons(object_copy(val),empty);object_free(&env);env =restore();save(argl);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|frame-variables|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|frame|"));argl = cons(object_copy(val),empty);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch1596;}cont.cont = &&after_call1595;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch1596:;object_free(&val);val = proc.proc(argl); after_call1595:;object_free(&argl);argl =restore();argl = cons(object_copy(val), argl);object_free(&proc);proc =restore();object_free(&cont);cont =restore();if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch1598;}object_free(&val);
                    val = compiled_procedure_entry(proc);
                    goto *val.cont;primitive_branch1598:;object_free(&val);val = proc.proc(argl); goto *cont.cont;after_lambda1591:;save(cont);save(proc);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|first-frame|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|env|"));argl = cons(object_copy(val),empty);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch1590;}cont.cont = &&after_call1589;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch1590:;object_free(&val);val = proc.proc(argl); after_call1589:;argl = cons(object_copy(val),empty);object_free(&proc);proc =restore();object_free(&cont);cont =restore();if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch1600;}object_free(&val);
                    val = compiled_procedure_entry(proc);
                    goto *val.cont;primitive_branch1600:;object_free(&val);val = proc.proc(argl); goto *cont.cont;after_lambda1585:;{Object t = def_var_val(c_str_to_datum("|env-loop|"));
                                   object_free(&val);val = t;}object_free(&proc);proc = lookup_var_val(c_str_to_datum("|env-loop|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|env|"));argl = cons(object_copy(val),empty);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch1584;}object_free(&val);
                    val = compiled_procedure_entry(proc);
                    goto *val.cont;primitive_branch1584:;object_free(&val);val = proc.proc(argl); goto *cont.cont;after_lambda1581:;{Object t = def_var_val(c_str_to_datum("|set-variable-value!|"));
                                   object_free(&val);val = t;}object_free(&val);val = make_compiled_procedure(&&entry1578);goto after_lambda1577;entry1578:env = compiled_procedure_env();
                          env = extend_environment(c_str_to_datum("(|parameters| . (|body| . (|env| . ())))"));object_free(&proc);proc = lookup_var_val(c_str_to_datum("|list|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|env|"));argl = cons(object_copy(val),empty);object_free(&val);val = lookup_var_val(c_str_to_datum("|body|"));argl = cons(object_copy(val), argl);object_free(&val);val = lookup_var_val(c_str_to_datum("|parameters|"));argl = cons(object_copy(val), argl);object_free(&val);val = c_str_to_datum("|procedure|");argl = cons(object_copy(val), argl);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch1580;}object_free(&val);
                    val = compiled_procedure_entry(proc);
                    goto *val.cont;primitive_branch1580:;object_free(&val);val = proc.proc(argl); goto *cont.cont;after_lambda1577:;{Object t = def_var_val(c_str_to_datum("|make-procedure|"));
                                   object_free(&val);val = t;}object_free(&val);val = make_compiled_procedure(&&entry1574);goto after_lambda1573;entry1574:env = compiled_procedure_env();
                          env = extend_environment(c_str_to_datum("(|p| . ())"));object_free(&proc);proc = lookup_var_val(c_str_to_datum("|tagged-list?|"));object_free(&val);val = c_str_to_datum("|procedure|");argl = cons(object_copy(val),empty);object_free(&val);val = lookup_var_val(c_str_to_datum("|p|"));argl = cons(object_copy(val), argl);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch1576;}object_free(&val);
                    val = compiled_procedure_entry(proc);
                    goto *val.cont;primitive_branch1576:;object_free(&val);val = proc.proc(argl); goto *cont.cont;after_lambda1573:;{Object t = def_var_val(c_str_to_datum("|compound-procedure?|"));
                                   object_free(&val);val = t;}object_free(&val);val = make_compiled_procedure(&&entry1568);goto after_lambda1567;entry1568:env = compiled_procedure_env();
                          env = extend_environment(c_str_to_datum("(|p| . ())"));object_free(&proc);proc = lookup_var_val(c_str_to_datum("|car|"));save(cont);save(proc);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|cdr|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|p|"));argl = cons(object_copy(val),empty);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch1570;}cont.cont = &&after_call1569;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch1570:;object_free(&val);val = proc.proc(argl); after_call1569:;argl = cons(object_copy(val),empty);object_free(&proc);proc =restore();object_free(&cont);cont =restore();if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch1572;}object_free(&val);
                    val = compiled_procedure_entry(proc);
                    goto *val.cont;primitive_branch1572:;object_free(&val);val = proc.proc(argl); goto *cont.cont;after_lambda1567:;{Object t = def_var_val(c_str_to_datum("|procedure-parameters|"));
                                   object_free(&val);val = t;}object_free(&val);val = make_compiled_procedure(&&entry1560);goto after_lambda1559;entry1560:env = compiled_procedure_env();
                          env = extend_environment(c_str_to_datum("(|p| . ())"));object_free(&proc);proc = lookup_var_val(c_str_to_datum("|car|"));save(cont);save(proc);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|cdr|"));save(proc);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|cdr|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|p|"));argl = cons(object_copy(val),empty);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch1562;}cont.cont = &&after_call1561;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch1562:;object_free(&val);val = proc.proc(argl); after_call1561:;argl = cons(object_copy(val),empty);object_free(&proc);proc =restore();if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch1564;}cont.cont = &&after_call1563;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch1564:;object_free(&val);val = proc.proc(argl); after_call1563:;argl = cons(object_copy(val),empty);object_free(&proc);proc =restore();object_free(&cont);cont =restore();if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch1566;}object_free(&val);
                    val = compiled_procedure_entry(proc);
                    goto *val.cont;primitive_branch1566:;object_free(&val);val = proc.proc(argl); goto *cont.cont;after_lambda1559:;{Object t = def_var_val(c_str_to_datum("|procedure-body|"));
                                   object_free(&val);val = t;}object_free(&val);val = make_compiled_procedure(&&entry1550);goto after_lambda1549;entry1550:env = compiled_procedure_env();
                          env = extend_environment(c_str_to_datum("(|p| . ())"));object_free(&proc);proc = lookup_var_val(c_str_to_datum("|car|"));save(cont);save(proc);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|cdr|"));save(proc);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|cdr|"));save(proc);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|cdr|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|p|"));argl = cons(object_copy(val),empty);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch1552;}cont.cont = &&after_call1551;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch1552:;object_free(&val);val = proc.proc(argl); after_call1551:;argl = cons(object_copy(val),empty);object_free(&proc);proc =restore();if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch1554;}cont.cont = &&after_call1553;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch1554:;object_free(&val);val = proc.proc(argl); after_call1553:;argl = cons(object_copy(val),empty);object_free(&proc);proc =restore();if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch1556;}cont.cont = &&after_call1555;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch1556:;object_free(&val);val = proc.proc(argl); after_call1555:;argl = cons(object_copy(val),empty);object_free(&proc);proc =restore();object_free(&cont);cont =restore();if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch1558;}object_free(&val);
                    val = compiled_procedure_entry(proc);
                    goto *val.cont;primitive_branch1558:;object_free(&val);val = proc.proc(argl); goto *cont.cont;after_lambda1549:;{Object t = def_var_val(c_str_to_datum("|procedure-environment|"));
                                   object_free(&val);val = t;}object_free(&val);val = make_compiled_procedure(&&entry1546);goto after_lambda1545;entry1546:env = compiled_procedure_env();
                          env = extend_environment(c_str_to_datum("(|env| . ())"));object_free(&proc);proc = lookup_var_val(c_str_to_datum("|cdr|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|env|"));argl = cons(object_copy(val),empty);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch1548;}object_free(&val);
                    val = compiled_procedure_entry(proc);
                    goto *val.cont;primitive_branch1548:;object_free(&val);val = proc.proc(argl); goto *cont.cont;after_lambda1545:;{Object t = def_var_val(c_str_to_datum("|enclosing-environment|"));
                                   object_free(&val);val = t;}object_free(&val);val = make_compiled_procedure(&&entry1494);goto after_lambda1493;entry1494:env = compiled_procedure_env();
                          env = extend_environment(c_str_to_datum("(|vars| . (|vals| . (|base-env| . ())))"));object_free(&val);val = make_compiled_procedure(&&entry1498);goto after_lambda1497;entry1498:env = compiled_procedure_env();
                          env = extend_environment(c_str_to_datum("(|vars-0| . (|vals-0| . (|vars-1| . (|vals-1| . ()))))"));save(cont);save(env);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|symbol?|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|vars-0|"));argl = cons(object_copy(val),empty);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch1544;}cont.cont = &&after_call1543;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch1544:;object_free(&val);val = proc.proc(argl); after_call1543:;object_free(&env);env =restore();object_free(&cont);cont =restore();if(val.type==BOOLEAN && !val.boolean){
                        goto false_branch1500;}object_free(&proc);proc = lookup_var_val(c_str_to_datum("|cons|"));save(cont);save(proc);object_free(&val);val = lookup_var_val(c_str_to_datum("|base-env|"));argl = cons(object_copy(val),empty);save(argl);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|make-frame|"));save(proc);save(env);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|cons|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|vals-1|"));argl = cons(object_copy(val),empty);object_free(&val);val = lookup_var_val(c_str_to_datum("|vals-0|"));argl = cons(object_copy(val), argl);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch1536;}cont.cont = &&after_call1535;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch1536:;object_free(&val);val = proc.proc(argl); after_call1535:;argl = cons(object_copy(val),empty);object_free(&env);env =restore();save(argl);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|cons|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|vars-1|"));argl = cons(object_copy(val),empty);object_free(&val);val = lookup_var_val(c_str_to_datum("|vars-0|"));argl = cons(object_copy(val), argl);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch1538;}cont.cont = &&after_call1537;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch1538:;object_free(&val);val = proc.proc(argl); after_call1537:;object_free(&argl);argl =restore();argl = cons(object_copy(val), argl);object_free(&proc);proc =restore();if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch1540;}cont.cont = &&after_call1539;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch1540:;object_free(&val);val = proc.proc(argl); after_call1539:;object_free(&argl);argl =restore();argl = cons(object_copy(val), argl);object_free(&proc);proc =restore();object_free(&cont);cont =restore();if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch1542;}object_free(&val);
                    val = compiled_procedure_entry(proc);
                    goto *val.cont;primitive_branch1542:;object_free(&val);val = proc.proc(argl); goto *cont.cont;false_branch1500:;save(cont);save(env);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|null?|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|vars-0|"));argl = cons(object_copy(val),empty);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch1534;}cont.cont = &&after_call1533;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch1534:;object_free(&val);val = proc.proc(argl); after_call1533:;object_free(&env);env =restore();object_free(&cont);cont =restore();if(val.type==BOOLEAN && !val.boolean){
                        goto false_branch1502;}save(cont);save(env);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|null?|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|vals-0|"));argl = cons(object_copy(val),empty);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch1532;}cont.cont = &&after_call1531;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch1532:;object_free(&val);val = proc.proc(argl); after_call1531:;object_free(&env);env =restore();object_free(&cont);cont =restore();if(val.type==BOOLEAN && !val.boolean){
                        goto false_branch1524;}object_free(&proc);proc = lookup_var_val(c_str_to_datum("|cons|"));save(cont);save(proc);object_free(&val);val = lookup_var_val(c_str_to_datum("|base-env|"));argl = cons(object_copy(val),empty);save(argl);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|make-frame|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|vals-1|"));argl = cons(object_copy(val),empty);object_free(&val);val = lookup_var_val(c_str_to_datum("|vars-1|"));argl = cons(object_copy(val), argl);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch1528;}cont.cont = &&after_call1527;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch1528:;object_free(&val);val = proc.proc(argl); after_call1527:;object_free(&argl);argl =restore();argl = cons(object_copy(val), argl);object_free(&proc);proc =restore();object_free(&cont);cont =restore();if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch1530;}object_free(&val);
                    val = compiled_procedure_entry(proc);
                    goto *val.cont;primitive_branch1530:;object_free(&val);val = proc.proc(argl); goto *cont.cont;false_branch1524:;object_free(&proc);proc = lookup_var_val(c_str_to_datum("|error|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|vals|"));argl = cons(object_copy(val),empty);object_free(&val);val = lookup_var_val(c_str_to_datum("|vars|"));argl = cons(object_copy(val), argl);object_free(&val);val = c_str_to_datum("\"too many arguments supplied\"");argl = cons(object_copy(val), argl);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch1526;}object_free(&val);
                    val = compiled_procedure_entry(proc);
                    goto *val.cont;primitive_branch1526:;object_free(&val);val = proc.proc(argl); goto *cont.cont;false_branch1502:;save(cont);save(env);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|null?|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|vals-0|"));argl = cons(object_copy(val),empty);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch1522;}cont.cont = &&after_call1521;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch1522:;object_free(&val);val = proc.proc(argl); after_call1521:;object_free(&env);env =restore();object_free(&cont);cont =restore();if(val.type==BOOLEAN && !val.boolean){
                        goto false_branch1504;}object_free(&proc);proc = lookup_var_val(c_str_to_datum("|error|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|vals|"));argl = cons(object_copy(val),empty);object_free(&val);val = lookup_var_val(c_str_to_datum("|vars|"));argl = cons(object_copy(val), argl);object_free(&val);val = c_str_to_datum("\"too few arguments supplied\"");argl = cons(object_copy(val), argl);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch1520;}object_free(&val);
                    val = compiled_procedure_entry(proc);
                    goto *val.cont;primitive_branch1520:;object_free(&val);val = proc.proc(argl); goto *cont.cont;false_branch1504:;object_free(&proc);proc = lookup_var_val(c_str_to_datum("|iter|"));save(cont);save(proc);save(env);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|cons|"));save(proc);object_free(&val);val = lookup_var_val(c_str_to_datum("|vals-1|"));argl = cons(object_copy(val),empty);save(argl);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|car|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|vals-0|"));argl = cons(object_copy(val),empty);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch1506;}cont.cont = &&after_call1505;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch1506:;object_free(&val);val = proc.proc(argl); after_call1505:;object_free(&argl);argl =restore();argl = cons(object_copy(val), argl);object_free(&proc);proc =restore();if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch1508;}cont.cont = &&after_call1507;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch1508:;object_free(&val);val = proc.proc(argl); after_call1507:;argl = cons(object_copy(val),empty);object_free(&env);env =restore();save(env);save(argl);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|cons|"));save(proc);object_free(&val);val = lookup_var_val(c_str_to_datum("|vars-1|"));argl = cons(object_copy(val),empty);save(argl);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|car|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|vars-0|"));argl = cons(object_copy(val),empty);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch1510;}cont.cont = &&after_call1509;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch1510:;object_free(&val);val = proc.proc(argl); after_call1509:;object_free(&argl);argl =restore();argl = cons(object_copy(val), argl);object_free(&proc);proc =restore();if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch1512;}cont.cont = &&after_call1511;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch1512:;object_free(&val);val = proc.proc(argl); after_call1511:;object_free(&argl);argl =restore();argl = cons(object_copy(val), argl);object_free(&env);env =restore();save(env);save(argl);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|cdr|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|vals-0|"));argl = cons(object_copy(val),empty);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch1514;}cont.cont = &&after_call1513;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch1514:;object_free(&val);val = proc.proc(argl); after_call1513:;object_free(&argl);argl =restore();argl = cons(object_copy(val), argl);object_free(&env);env =restore();save(argl);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|cdr|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|vars-0|"));argl = cons(object_copy(val),empty);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch1516;}cont.cont = &&after_call1515;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch1516:;object_free(&val);val = proc.proc(argl); after_call1515:;object_free(&argl);argl =restore();argl = cons(object_copy(val), argl);object_free(&proc);proc =restore();object_free(&cont);cont =restore();if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch1518;}object_free(&val);
                    val = compiled_procedure_entry(proc);
                    goto *val.cont;primitive_branch1518:;object_free(&val);val = proc.proc(argl); goto *cont.cont;after_lambda1497:;{Object t = def_var_val(c_str_to_datum("|iter|"));
                                   object_free(&val);val = t;}object_free(&proc);proc = lookup_var_val(c_str_to_datum("|iter|"));object_free(&val);val = c_str_to_datum("()");argl = cons(object_copy(val),empty);object_free(&val);val = c_str_to_datum("()");argl = cons(object_copy(val), argl);object_free(&val);val = lookup_var_val(c_str_to_datum("|vals|"));argl = cons(object_copy(val), argl);object_free(&val);val = lookup_var_val(c_str_to_datum("|vars|"));argl = cons(object_copy(val), argl);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch1496;}object_free(&val);
                    val = compiled_procedure_entry(proc);
                    goto *val.cont;primitive_branch1496:;object_free(&val);val = proc.proc(argl); goto *cont.cont;after_lambda1493:;{Object t = def_var_val(c_str_to_datum("|extend-environment|"));
                                   object_free(&val);val = t;}object_free(&val);val = make_compiled_procedure(&&entry1446);goto after_lambda1445;entry1446:env = compiled_procedure_env();
                          env = extend_environment(c_str_to_datum("(|var| . (|env| . ()))"));object_free(&val);val = make_compiled_procedure(&&entry1450);goto after_lambda1449;entry1450:env = compiled_procedure_env();
                          env = extend_environment(c_str_to_datum("(|env| . ())"));object_free(&val);val = make_compiled_procedure(&&entry1470);goto after_lambda1469;entry1470:env = compiled_procedure_env();
                          env = extend_environment(c_str_to_datum("(|vars| . (|vals| . ()))"));save(cont);save(env);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|null?|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|vars|"));argl = cons(object_copy(val),empty);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch1492;}cont.cont = &&after_call1491;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch1492:;object_free(&val);val = proc.proc(argl); after_call1491:;object_free(&env);env =restore();object_free(&cont);cont =restore();if(val.type==BOOLEAN && !val.boolean){
                        goto false_branch1472;}object_free(&proc);proc = lookup_var_val(c_str_to_datum("|env-loop|"));save(cont);save(proc);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|enclosing-environment|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|env|"));argl = cons(object_copy(val),empty);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch1488;}cont.cont = &&after_call1487;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch1488:;object_free(&val);val = proc.proc(argl); after_call1487:;argl = cons(object_copy(val),empty);object_free(&proc);proc =restore();object_free(&cont);cont =restore();if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch1490;}object_free(&val);
                    val = compiled_procedure_entry(proc);
                    goto *val.cont;primitive_branch1490:;object_free(&val);val = proc.proc(argl); goto *cont.cont;false_branch1472:;save(cont);save(env);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|eq?|"));save(proc);save(env);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|car|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|vars|"));argl = cons(object_copy(val),empty);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch1484;}cont.cont = &&after_call1483;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch1484:;object_free(&val);val = proc.proc(argl); after_call1483:;argl = cons(object_copy(val),empty);object_free(&env);env =restore();object_free(&val);val = lookup_var_val(c_str_to_datum("|var|"));argl = cons(object_copy(val), argl);object_free(&proc);proc =restore();if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch1486;}cont.cont = &&after_call1485;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch1486:;object_free(&val);val = proc.proc(argl); after_call1485:;object_free(&env);env =restore();object_free(&cont);cont =restore();if(val.type==BOOLEAN && !val.boolean){
                        goto false_branch1474;}object_free(&proc);proc = lookup_var_val(c_str_to_datum("|car|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|vals|"));argl = cons(object_copy(val),empty);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch1482;}object_free(&val);
                    val = compiled_procedure_entry(proc);
                    goto *val.cont;primitive_branch1482:;object_free(&val);val = proc.proc(argl); goto *cont.cont;false_branch1474:;object_free(&proc);proc = lookup_var_val(c_str_to_datum("|scan|"));save(cont);save(proc);save(env);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|cdr|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|vals|"));argl = cons(object_copy(val),empty);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch1476;}cont.cont = &&after_call1475;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch1476:;object_free(&val);val = proc.proc(argl); after_call1475:;argl = cons(object_copy(val),empty);object_free(&env);env =restore();save(argl);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|cdr|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|vars|"));argl = cons(object_copy(val),empty);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch1478;}cont.cont = &&after_call1477;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch1478:;object_free(&val);val = proc.proc(argl); after_call1477:;object_free(&argl);argl =restore();argl = cons(object_copy(val), argl);object_free(&proc);proc =restore();object_free(&cont);cont =restore();if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch1480;}object_free(&val);
                    val = compiled_procedure_entry(proc);
                    goto *val.cont;primitive_branch1480:;object_free(&val);val = proc.proc(argl); goto *cont.cont;after_lambda1469:;{Object t = def_var_val(c_str_to_datum("|scan|"));
                                   object_free(&val);val = t;}save(cont);save(env);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|eq?|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|the-empty-environment|"));argl = cons(object_copy(val),empty);object_free(&val);val = lookup_var_val(c_str_to_datum("|env|"));argl = cons(object_copy(val), argl);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch1468;}cont.cont = &&after_call1467;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch1468:;object_free(&val);val = proc.proc(argl); after_call1467:;object_free(&env);env =restore();object_free(&cont);cont =restore();if(val.type==BOOLEAN && !val.boolean){
                        goto false_branch1452;}object_free(&proc);proc = lookup_var_val(c_str_to_datum("|error|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|var|"));argl = cons(object_copy(val),empty);object_free(&val);val = c_str_to_datum("\"unbound variable --\"");argl = cons(object_copy(val), argl);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch1466;}object_free(&val);
                    val = compiled_procedure_entry(proc);
                    goto *val.cont;primitive_branch1466:;object_free(&val);val = proc.proc(argl); goto *cont.cont;false_branch1452:;object_free(&proc);proc = make_compiled_procedure(&&entry1456);goto after_lambda1455;entry1456:env = compiled_procedure_env();
                          env = extend_environment(c_str_to_datum("(|frame| . ())"));object_free(&proc);proc = lookup_var_val(c_str_to_datum("|scan|"));save(cont);save(proc);save(env);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|frame-values|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|frame|"));argl = cons(object_copy(val),empty);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch1458;}cont.cont = &&after_call1457;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch1458:;object_free(&val);val = proc.proc(argl); after_call1457:;argl = cons(object_copy(val),empty);object_free(&env);env =restore();save(argl);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|frame-variables|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|frame|"));argl = cons(object_copy(val),empty);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch1460;}cont.cont = &&after_call1459;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch1460:;object_free(&val);val = proc.proc(argl); after_call1459:;object_free(&argl);argl =restore();argl = cons(object_copy(val), argl);object_free(&proc);proc =restore();object_free(&cont);cont =restore();if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch1462;}object_free(&val);
                    val = compiled_procedure_entry(proc);
                    goto *val.cont;primitive_branch1462:;object_free(&val);val = proc.proc(argl); goto *cont.cont;after_lambda1455:;save(cont);save(proc);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|first-frame|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|env|"));argl = cons(object_copy(val),empty);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch1454;}cont.cont = &&after_call1453;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch1454:;object_free(&val);val = proc.proc(argl); after_call1453:;argl = cons(object_copy(val),empty);object_free(&proc);proc =restore();object_free(&cont);cont =restore();if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch1464;}object_free(&val);
                    val = compiled_procedure_entry(proc);
                    goto *val.cont;primitive_branch1464:;object_free(&val);val = proc.proc(argl); goto *cont.cont;after_lambda1449:;{Object t = def_var_val(c_str_to_datum("|env-loop|"));
                                   object_free(&val);val = t;}object_free(&proc);proc = lookup_var_val(c_str_to_datum("|env-loop|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|env|"));argl = cons(object_copy(val),empty);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch1448;}object_free(&val);
                    val = compiled_procedure_entry(proc);
                    goto *val.cont;primitive_branch1448:;object_free(&val);val = proc.proc(argl); goto *cont.cont;after_lambda1445:;{Object t = def_var_val(c_str_to_datum("|lookup-variable-value|"));
                                   object_free(&val);val = t;}object_free(&val);val = make_compiled_procedure(&&entry1430);goto after_lambda1429;entry1430:env = compiled_procedure_env();
                          env = extend_environment(c_str_to_datum("(|objs| . ())"));save(cont);save(env);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|null?|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|objs|"));argl = cons(object_copy(val),empty);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch1444;}cont.cont = &&after_call1443;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch1444:;object_free(&val);val = proc.proc(argl); after_call1443:;object_free(&env);env =restore();object_free(&cont);cont =restore();if(val.type==BOOLEAN && !val.boolean){
                        goto false_branch1432;}object_free(&val);val = c_str_to_datum("#true");goto *cont.cont;false_branch1432:;save(cont);save(env);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|number?|"));save(proc);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|car|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|objs|"));argl = cons(object_copy(val),empty);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch1440;}cont.cont = &&after_call1439;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch1440:;object_free(&val);val = proc.proc(argl); after_call1439:;argl = cons(object_copy(val),empty);object_free(&proc);proc =restore();if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch1442;}cont.cont = &&after_call1441;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch1442:;object_free(&val);val = proc.proc(argl); after_call1441:;object_free(&env);env =restore();object_free(&cont);cont =restore();if(val.type==BOOLEAN && !val.boolean){
                        goto false_branch1434;}object_free(&proc);proc = lookup_var_val(c_str_to_datum("|numbers?|"));save(cont);save(proc);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|cdr|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|objs|"));argl = cons(object_copy(val),empty);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch1436;}cont.cont = &&after_call1435;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch1436:;object_free(&val);val = proc.proc(argl); after_call1435:;argl = cons(object_copy(val),empty);object_free(&proc);proc =restore();object_free(&cont);cont =restore();if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch1438;}object_free(&val);
                    val = compiled_procedure_entry(proc);
                    goto *val.cont;primitive_branch1438:;object_free(&val);val = proc.proc(argl); goto *cont.cont;false_branch1434:;object_free(&val);val = c_str_to_datum("#false");goto *cont.cont;after_lambda1429:;{Object t = def_var_val(c_str_to_datum("|numbers?|"));
                                   object_free(&val);val = t;}object_free(&val);val = make_compiled_procedure(&&entry1426);goto after_lambda1425;entry1426:env = compiled_procedure_env();
                          env = extend_environment(c_str_to_datum("(|proc| . ())"));object_free(&proc);proc = lookup_var_val(c_str_to_datum("|tagged-list?|"));object_free(&val);val = c_str_to_datum("|primitive|");argl = cons(object_copy(val),empty);object_free(&val);val = lookup_var_val(c_str_to_datum("|proc|"));argl = cons(object_copy(val), argl);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch1428;}object_free(&val);
                    val = compiled_procedure_entry(proc);
                    goto *val.cont;primitive_branch1428:;object_free(&val);val = proc.proc(argl); goto *cont.cont;after_lambda1425:;{Object t = def_var_val(c_str_to_datum("|primitive-procedure?|"));
                                   object_free(&val);val = t;}object_free(&val);val = make_compiled_procedure(&&entry1420);goto after_lambda1419;entry1420:env = compiled_procedure_env();
                          env = extend_environment(c_str_to_datum("(|proc| . ())"));object_free(&proc);proc = lookup_var_val(c_str_to_datum("|car|"));save(cont);save(proc);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|cdr|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|proc|"));argl = cons(object_copy(val),empty);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch1422;}cont.cont = &&after_call1421;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch1422:;object_free(&val);val = proc.proc(argl); after_call1421:;argl = cons(object_copy(val),empty);object_free(&proc);proc =restore();object_free(&cont);cont =restore();if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch1424;}object_free(&val);
                    val = compiled_procedure_entry(proc);
                    goto *val.cont;primitive_branch1424:;object_free(&val);val = proc.proc(argl); goto *cont.cont;after_lambda1419:;{Object t = def_var_val(c_str_to_datum("|primitive-implementation|"));
                                   object_free(&val);val = t;}object_free(&val);val = make_compiled_procedure(&&entry1376);goto after_lambda1375;entry1376:env = compiled_procedure_env();
                          env = extend_environment(c_str_to_datum("|args|"));object_free(&val);val = make_compiled_procedure(&&entry1380);goto after_lambda1379;entry1380:env = compiled_procedure_env();
                          env = extend_environment(c_str_to_datum("(|zs| . (|result| . (|e?| . ())))"));save(cont);save(env);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|c-null?|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|zs|"));argl = cons(object_copy(val),empty);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch1418;}cont.cont = &&after_call1417;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch1418:;object_free(&val);val = proc.proc(argl); after_call1417:;object_free(&env);env =restore();object_free(&cont);cont =restore();if(val.type==BOOLEAN && !val.boolean){
                        goto false_branch1382;}object_free(&val);val = lookup_var_val(c_str_to_datum("|result|"));goto *cont.cont;false_branch1382:;object_free(&proc);proc = make_compiled_procedure(&&entry1386);goto after_lambda1385;entry1386:env = compiled_procedure_env();
                          env = extend_environment(c_str_to_datum("(|z| . ())"));save(cont);save(env);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|c-number?|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|z|"));argl = cons(object_copy(val),empty);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch1414;}cont.cont = &&after_call1413;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch1414:;object_free(&val);val = proc.proc(argl); after_call1413:;object_free(&env);env =restore();object_free(&cont);cont =restore();if(val.type==BOOLEAN && !val.boolean){
                        goto false_branch1388;}save(cont);save(env);object_free(&val);val = lookup_var_val(c_str_to_datum("|e?|"));if(val.type==BOOLEAN && !val.boolean){
                        goto false_branch1410;}object_free(&proc);proc = lookup_var_val(c_str_to_datum("|c-exact?|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|z|"));argl = cons(object_copy(val),empty);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch1412;}cont.cont = &&after_if1409;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch1412:;object_free(&val);val = proc.proc(argl); goto after_if1409;false_branch1410:;object_free(&val);val = c_str_to_datum("#false");after_if1409:;object_free(&env);env =restore();object_free(&cont);cont =restore();if(val.type==BOOLEAN && !val.boolean){
                        goto false_branch1392;}object_free(&proc);proc = lookup_var_val(c_str_to_datum("|iter|"));save(cont);save(proc);object_free(&val);val = lookup_var_val(c_str_to_datum("|e?|"));argl = cons(object_copy(val),empty);save(env);save(argl);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|c-*|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|z|"));argl = cons(object_copy(val),empty);object_free(&val);val = lookup_var_val(c_str_to_datum("|result|"));argl = cons(object_copy(val), argl);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch1404;}cont.cont = &&after_call1403;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch1404:;object_free(&val);val = proc.proc(argl); after_call1403:;object_free(&argl);argl =restore();argl = cons(object_copy(val), argl);object_free(&env);env =restore();save(argl);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|c-cdr|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|zs|"));argl = cons(object_copy(val),empty);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch1406;}cont.cont = &&after_call1405;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch1406:;object_free(&val);val = proc.proc(argl); after_call1405:;object_free(&argl);argl =restore();argl = cons(object_copy(val), argl);object_free(&proc);proc =restore();object_free(&cont);cont =restore();if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch1408;}object_free(&val);
                    val = compiled_procedure_entry(proc);
                    goto *val.cont;primitive_branch1408:;object_free(&val);val = proc.proc(argl); goto *cont.cont;false_branch1392:;object_free(&proc);proc = lookup_var_val(c_str_to_datum("|iter|"));save(cont);save(proc);object_free(&val);val = c_str_to_datum("#false");argl = cons(object_copy(val),empty);save(env);save(argl);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|c-*|"));save(proc);save(env);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|c-inexact|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|z|"));argl = cons(object_copy(val),empty);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch1394;}cont.cont = &&after_call1393;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch1394:;object_free(&val);val = proc.proc(argl); after_call1393:;argl = cons(object_copy(val),empty);object_free(&env);env =restore();save(argl);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|c-inexact|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|result|"));argl = cons(object_copy(val),empty);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch1396;}cont.cont = &&after_call1395;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch1396:;object_free(&val);val = proc.proc(argl); after_call1395:;object_free(&argl);argl =restore();argl = cons(object_copy(val), argl);object_free(&proc);proc =restore();if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch1398;}cont.cont = &&after_call1397;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch1398:;object_free(&val);val = proc.proc(argl); after_call1397:;object_free(&argl);argl =restore();argl = cons(object_copy(val), argl);object_free(&env);env =restore();save(argl);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|c-cdr|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|zs|"));argl = cons(object_copy(val),empty);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch1400;}cont.cont = &&after_call1399;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch1400:;object_free(&val);val = proc.proc(argl); after_call1399:;object_free(&argl);argl =restore();argl = cons(object_copy(val), argl);object_free(&proc);proc =restore();object_free(&cont);cont =restore();if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch1402;}object_free(&val);
                    val = compiled_procedure_entry(proc);
                    goto *val.cont;primitive_branch1402:;object_free(&val);val = proc.proc(argl); goto *cont.cont;false_branch1388:;object_free(&proc);proc = lookup_var_val(c_str_to_datum("|error|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|args|"));argl = cons(object_copy(val),empty);object_free(&val);val = c_str_to_datum("|(*) wrong type of argument --|");argl = cons(object_copy(val), argl);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch1390;}object_free(&val);
                    val = compiled_procedure_entry(proc);
                    goto *val.cont;primitive_branch1390:;object_free(&val);val = proc.proc(argl); goto *cont.cont;after_lambda1385:;save(cont);save(proc);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|c-car|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|zs|"));argl = cons(object_copy(val),empty);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch1384;}cont.cont = &&after_call1383;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch1384:;object_free(&val);val = proc.proc(argl); after_call1383:;argl = cons(object_copy(val),empty);object_free(&proc);proc =restore();object_free(&cont);cont =restore();if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch1416;}object_free(&val);
                    val = compiled_procedure_entry(proc);
                    goto *val.cont;primitive_branch1416:;object_free(&val);val = proc.proc(argl); goto *cont.cont;after_lambda1379:;{Object t = def_var_val(c_str_to_datum("|iter|"));
                                   object_free(&val);val = t;}object_free(&proc);proc = lookup_var_val(c_str_to_datum("|iter|"));object_free(&val);val = c_str_to_datum("#true");argl = cons(object_copy(val),empty);object_free(&val);val = c_str_to_datum("1");argl = cons(object_copy(val), argl);object_free(&val);val = lookup_var_val(c_str_to_datum("|args|"));argl = cons(object_copy(val), argl);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch1378;}object_free(&val);
                    val = compiled_procedure_entry(proc);
                    goto *val.cont;primitive_branch1378:;object_free(&val);val = proc.proc(argl); goto *cont.cont;after_lambda1375:;{Object t = def_var_val(c_str_to_datum("|*|"));
                                   object_free(&val);val = t;}object_free(&val);val = make_compiled_procedure(&&entry1332);goto after_lambda1331;entry1332:env = compiled_procedure_env();
                          env = extend_environment(c_str_to_datum("|args|"));object_free(&val);val = make_compiled_procedure(&&entry1336);goto after_lambda1335;entry1336:env = compiled_procedure_env();
                          env = extend_environment(c_str_to_datum("(|zs| . (|result| . (|e?| . ())))"));save(cont);save(env);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|c-null?|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|zs|"));argl = cons(object_copy(val),empty);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch1374;}cont.cont = &&after_call1373;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch1374:;object_free(&val);val = proc.proc(argl); after_call1373:;object_free(&env);env =restore();object_free(&cont);cont =restore();if(val.type==BOOLEAN && !val.boolean){
                        goto false_branch1338;}object_free(&val);val = lookup_var_val(c_str_to_datum("|result|"));goto *cont.cont;false_branch1338:;object_free(&proc);proc = make_compiled_procedure(&&entry1342);goto after_lambda1341;entry1342:env = compiled_procedure_env();
                          env = extend_environment(c_str_to_datum("(|z| . ())"));save(cont);save(env);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|c-number?|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|z|"));argl = cons(object_copy(val),empty);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch1370;}cont.cont = &&after_call1369;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch1370:;object_free(&val);val = proc.proc(argl); after_call1369:;object_free(&env);env =restore();object_free(&cont);cont =restore();if(val.type==BOOLEAN && !val.boolean){
                        goto false_branch1344;}save(cont);save(env);object_free(&val);val = lookup_var_val(c_str_to_datum("|e?|"));if(val.type==BOOLEAN && !val.boolean){
                        goto false_branch1366;}object_free(&proc);proc = lookup_var_val(c_str_to_datum("|c-exact?|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|z|"));argl = cons(object_copy(val),empty);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch1368;}cont.cont = &&after_if1365;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch1368:;object_free(&val);val = proc.proc(argl); goto after_if1365;false_branch1366:;object_free(&val);val = c_str_to_datum("#false");after_if1365:;object_free(&env);env =restore();object_free(&cont);cont =restore();if(val.type==BOOLEAN && !val.boolean){
                        goto false_branch1348;}object_free(&proc);proc = lookup_var_val(c_str_to_datum("|iter|"));save(cont);save(proc);object_free(&val);val = lookup_var_val(c_str_to_datum("|e?|"));argl = cons(object_copy(val),empty);save(env);save(argl);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|c-+|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|z|"));argl = cons(object_copy(val),empty);object_free(&val);val = lookup_var_val(c_str_to_datum("|result|"));argl = cons(object_copy(val), argl);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch1360;}cont.cont = &&after_call1359;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch1360:;object_free(&val);val = proc.proc(argl); after_call1359:;object_free(&argl);argl =restore();argl = cons(object_copy(val), argl);object_free(&env);env =restore();save(argl);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|c-cdr|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|zs|"));argl = cons(object_copy(val),empty);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch1362;}cont.cont = &&after_call1361;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch1362:;object_free(&val);val = proc.proc(argl); after_call1361:;object_free(&argl);argl =restore();argl = cons(object_copy(val), argl);object_free(&proc);proc =restore();object_free(&cont);cont =restore();if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch1364;}object_free(&val);
                    val = compiled_procedure_entry(proc);
                    goto *val.cont;primitive_branch1364:;object_free(&val);val = proc.proc(argl); goto *cont.cont;false_branch1348:;object_free(&proc);proc = lookup_var_val(c_str_to_datum("|iter|"));save(cont);save(proc);object_free(&val);val = c_str_to_datum("#false");argl = cons(object_copy(val),empty);save(env);save(argl);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|c-+|"));save(proc);save(env);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|c-inexact|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|z|"));argl = cons(object_copy(val),empty);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch1350;}cont.cont = &&after_call1349;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch1350:;object_free(&val);val = proc.proc(argl); after_call1349:;argl = cons(object_copy(val),empty);object_free(&env);env =restore();save(argl);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|c-inexact|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|result|"));argl = cons(object_copy(val),empty);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch1352;}cont.cont = &&after_call1351;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch1352:;object_free(&val);val = proc.proc(argl); after_call1351:;object_free(&argl);argl =restore();argl = cons(object_copy(val), argl);object_free(&proc);proc =restore();if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch1354;}cont.cont = &&after_call1353;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch1354:;object_free(&val);val = proc.proc(argl); after_call1353:;object_free(&argl);argl =restore();argl = cons(object_copy(val), argl);object_free(&env);env =restore();save(argl);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|c-cdr|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|zs|"));argl = cons(object_copy(val),empty);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch1356;}cont.cont = &&after_call1355;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch1356:;object_free(&val);val = proc.proc(argl); after_call1355:;object_free(&argl);argl =restore();argl = cons(object_copy(val), argl);object_free(&proc);proc =restore();object_free(&cont);cont =restore();if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch1358;}object_free(&val);
                    val = compiled_procedure_entry(proc);
                    goto *val.cont;primitive_branch1358:;object_free(&val);val = proc.proc(argl); goto *cont.cont;false_branch1344:;object_free(&proc);proc = lookup_var_val(c_str_to_datum("|error|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|args|"));argl = cons(object_copy(val),empty);object_free(&val);val = c_str_to_datum("|(+) wrong type of argument --|");argl = cons(object_copy(val), argl);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch1346;}object_free(&val);
                    val = compiled_procedure_entry(proc);
                    goto *val.cont;primitive_branch1346:;object_free(&val);val = proc.proc(argl); goto *cont.cont;after_lambda1341:;save(cont);save(proc);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|c-car|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|zs|"));argl = cons(object_copy(val),empty);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch1340;}cont.cont = &&after_call1339;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch1340:;object_free(&val);val = proc.proc(argl); after_call1339:;argl = cons(object_copy(val),empty);object_free(&proc);proc =restore();object_free(&cont);cont =restore();if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch1372;}object_free(&val);
                    val = compiled_procedure_entry(proc);
                    goto *val.cont;primitive_branch1372:;object_free(&val);val = proc.proc(argl); goto *cont.cont;after_lambda1335:;{Object t = def_var_val(c_str_to_datum("|iter|"));
                                   object_free(&val);val = t;}object_free(&proc);proc = lookup_var_val(c_str_to_datum("|iter|"));object_free(&val);val = c_str_to_datum("#true");argl = cons(object_copy(val),empty);object_free(&val);val = c_str_to_datum("0");argl = cons(object_copy(val), argl);object_free(&val);val = lookup_var_val(c_str_to_datum("|args|"));argl = cons(object_copy(val), argl);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch1334;}object_free(&val);
                    val = compiled_procedure_entry(proc);
                    goto *val.cont;primitive_branch1334:;object_free(&val);val = proc.proc(argl); goto *cont.cont;after_lambda1331:;{Object t = def_var_val(c_str_to_datum("|+|"));
                                   object_free(&val);val = t;}object_free(&val);val = make_compiled_procedure(&&entry1242);goto after_lambda1241;entry1242:env = compiled_procedure_env();
                          env = extend_environment(c_str_to_datum("|args|"));save(cont);save(env);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|c-length|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|args|"));argl = cons(object_copy(val),empty);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch1330;}cont.cont = &&after_call1329;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch1330:;object_free(&val);val = proc.proc(argl); after_call1329:;object_free(&env);env =restore();{Object t = def_var_val(c_str_to_datum("|len|"));
                                   object_free(&val);val = t;}object_free(&cont);cont =restore();save(cont);save(env);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|c-=|"));object_free(&val);val = c_str_to_datum("0");argl = cons(object_copy(val),empty);object_free(&val);val = lookup_var_val(c_str_to_datum("|len|"));argl = cons(object_copy(val), argl);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch1328;}cont.cont = &&after_call1327;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch1328:;object_free(&val);val = proc.proc(argl); after_call1327:;object_free(&env);env =restore();object_free(&cont);cont =restore();if(val.type==BOOLEAN && !val.boolean){
                        goto false_branch1244;}object_free(&proc);proc = lookup_var_val(c_str_to_datum("|error|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|args|"));argl = cons(object_copy(val),empty);object_free(&val);val = c_str_to_datum("|(-) wrong number of arguments --|");argl = cons(object_copy(val), argl);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch1326;}object_free(&val);
                    val = compiled_procedure_entry(proc);
                    goto *val.cont;primitive_branch1326:;object_free(&val);val = proc.proc(argl); goto *cont.cont;false_branch1244:;save(cont);save(env);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|c-=|"));object_free(&val);val = c_str_to_datum("1");argl = cons(object_copy(val),empty);object_free(&val);val = lookup_var_val(c_str_to_datum("|len|"));argl = cons(object_copy(val), argl);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch1324;}cont.cont = &&after_call1323;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch1324:;object_free(&val);val = proc.proc(argl); after_call1323:;object_free(&env);env =restore();object_free(&cont);cont =restore();if(val.type==BOOLEAN && !val.boolean){
                        goto false_branch1246;}save(cont);save(env);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|c-number?|"));save(proc);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|c-car|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|args|"));argl = cons(object_copy(val),empty);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch1320;}cont.cont = &&after_call1319;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch1320:;object_free(&val);val = proc.proc(argl); after_call1319:;argl = cons(object_copy(val),empty);object_free(&proc);proc =restore();if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch1322;}cont.cont = &&after_call1321;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch1322:;object_free(&val);val = proc.proc(argl); after_call1321:;object_free(&env);env =restore();object_free(&cont);cont =restore();if(val.type==BOOLEAN && !val.boolean){
                        goto false_branch1300;}save(cont);save(env);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|c-exact?|"));save(proc);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|c-car|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|args|"));argl = cons(object_copy(val),empty);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch1316;}cont.cont = &&after_call1315;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch1316:;object_free(&val);val = proc.proc(argl); after_call1315:;argl = cons(object_copy(val),empty);object_free(&proc);proc =restore();if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch1318;}cont.cont = &&after_call1317;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch1318:;object_free(&val);val = proc.proc(argl); after_call1317:;object_free(&env);env =restore();object_free(&cont);cont =restore();if(val.type==BOOLEAN && !val.boolean){
                        goto false_branch1304;}object_free(&proc);proc = lookup_var_val(c_str_to_datum("|c-*|"));save(cont);save(proc);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|c-car|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|args|"));argl = cons(object_copy(val),empty);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch1312;}cont.cont = &&after_call1311;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch1312:;object_free(&val);val = proc.proc(argl); after_call1311:;argl = cons(object_copy(val),empty);object_free(&val);val = c_str_to_datum("-1");argl = cons(object_copy(val), argl);object_free(&proc);proc =restore();object_free(&cont);cont =restore();if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch1314;}object_free(&val);
                    val = compiled_procedure_entry(proc);
                    goto *val.cont;primitive_branch1314:;object_free(&val);val = proc.proc(argl); goto *cont.cont;false_branch1304:;object_free(&proc);proc = lookup_var_val(c_str_to_datum("|c-*|"));save(cont);save(proc);save(env);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|c-car|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|args|"));argl = cons(object_copy(val),empty);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch1306;}cont.cont = &&after_call1305;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch1306:;object_free(&val);val = proc.proc(argl); after_call1305:;argl = cons(object_copy(val),empty);object_free(&env);env =restore();save(argl);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|c-inexact|"));object_free(&val);val = c_str_to_datum("-1");argl = cons(object_copy(val),empty);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch1308;}cont.cont = &&after_call1307;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch1308:;object_free(&val);val = proc.proc(argl); after_call1307:;object_free(&argl);argl =restore();argl = cons(object_copy(val), argl);object_free(&proc);proc =restore();object_free(&cont);cont =restore();if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch1310;}object_free(&val);
                    val = compiled_procedure_entry(proc);
                    goto *val.cont;primitive_branch1310:;object_free(&val);val = proc.proc(argl); goto *cont.cont;false_branch1300:;object_free(&proc);proc = lookup_var_val(c_str_to_datum("|error|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|args|"));argl = cons(object_copy(val),empty);object_free(&val);val = c_str_to_datum("|(-) wrong type of argument --|");argl = cons(object_copy(val), argl);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch1302;}object_free(&val);
                    val = compiled_procedure_entry(proc);
                    goto *val.cont;primitive_branch1302:;object_free(&val);val = proc.proc(argl); goto *cont.cont;false_branch1246:;object_free(&val);val = make_compiled_procedure(&&entry1258);goto after_lambda1257;entry1258:env = compiled_procedure_env();
                          env = extend_environment(c_str_to_datum("(|nums| . (|result| . (|e?| . ())))"));save(cont);save(env);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|c-null?|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|nums|"));argl = cons(object_copy(val),empty);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch1298;}cont.cont = &&after_call1297;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch1298:;object_free(&val);val = proc.proc(argl); after_call1297:;object_free(&env);env =restore();object_free(&cont);cont =restore();if(val.type==BOOLEAN && !val.boolean){
                        goto false_branch1260;}object_free(&val);val = lookup_var_val(c_str_to_datum("|result|"));goto *cont.cont;false_branch1260:;save(cont);save(env);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|c-number?|"));save(proc);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|c-car|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|nums|"));argl = cons(object_copy(val),empty);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch1294;}cont.cont = &&after_call1293;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch1294:;object_free(&val);val = proc.proc(argl); after_call1293:;argl = cons(object_copy(val),empty);object_free(&proc);proc =restore();if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch1296;}cont.cont = &&after_call1295;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch1296:;object_free(&val);val = proc.proc(argl); after_call1295:;object_free(&env);env =restore();object_free(&cont);cont =restore();if(val.type==BOOLEAN && !val.boolean){
                        goto false_branch1262;}save(cont);save(env);object_free(&val);val = lookup_var_val(c_str_to_datum("|e?|"));if(val.type==BOOLEAN && !val.boolean){
                        goto false_branch1288;}object_free(&proc);proc = lookup_var_val(c_str_to_datum("|c-exact?|"));save(proc);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|c-car|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|nums|"));argl = cons(object_copy(val),empty);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch1290;}cont.cont = &&after_call1289;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch1290:;object_free(&val);val = proc.proc(argl); after_call1289:;argl = cons(object_copy(val),empty);object_free(&proc);proc =restore();if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch1292;}cont.cont = &&after_if1287;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch1292:;object_free(&val);val = proc.proc(argl); goto after_if1287;false_branch1288:;object_free(&val);val = c_str_to_datum("#false");after_if1287:;object_free(&env);env =restore();object_free(&cont);cont =restore();if(val.type==BOOLEAN && !val.boolean){
                        goto false_branch1266;}object_free(&proc);proc = lookup_var_val(c_str_to_datum("|iter|"));save(cont);save(proc);object_free(&val);val = c_str_to_datum("#true");argl = cons(object_copy(val),empty);save(env);save(argl);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|c--|"));save(proc);save(env);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|c-car|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|nums|"));argl = cons(object_copy(val),empty);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch1280;}cont.cont = &&after_call1279;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch1280:;object_free(&val);val = proc.proc(argl); after_call1279:;argl = cons(object_copy(val),empty);object_free(&env);env =restore();object_free(&val);val = lookup_var_val(c_str_to_datum("|result|"));argl = cons(object_copy(val), argl);object_free(&proc);proc =restore();if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch1282;}cont.cont = &&after_call1281;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch1282:;object_free(&val);val = proc.proc(argl); after_call1281:;object_free(&argl);argl =restore();argl = cons(object_copy(val), argl);object_free(&env);env =restore();save(argl);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|c-cdr|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|nums|"));argl = cons(object_copy(val),empty);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch1284;}cont.cont = &&after_call1283;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch1284:;object_free(&val);val = proc.proc(argl); after_call1283:;object_free(&argl);argl =restore();argl = cons(object_copy(val), argl);object_free(&proc);proc =restore();object_free(&cont);cont =restore();if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch1286;}object_free(&val);
                    val = compiled_procedure_entry(proc);
                    goto *val.cont;primitive_branch1286:;object_free(&val);val = proc.proc(argl); goto *cont.cont;false_branch1266:;object_free(&proc);proc = lookup_var_val(c_str_to_datum("|iter|"));save(cont);save(proc);object_free(&val);val = c_str_to_datum("#false");argl = cons(object_copy(val),empty);save(env);save(argl);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|c--|"));save(proc);save(env);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|c-inexact|"));save(proc);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|c-car|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|nums|"));argl = cons(object_copy(val),empty);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch1268;}cont.cont = &&after_call1267;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch1268:;object_free(&val);val = proc.proc(argl); after_call1267:;argl = cons(object_copy(val),empty);object_free(&proc);proc =restore();if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch1270;}cont.cont = &&after_call1269;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch1270:;object_free(&val);val = proc.proc(argl); after_call1269:;argl = cons(object_copy(val),empty);object_free(&env);env =restore();save(argl);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|c-inexact|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|result|"));argl = cons(object_copy(val),empty);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch1272;}cont.cont = &&after_call1271;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch1272:;object_free(&val);val = proc.proc(argl); after_call1271:;object_free(&argl);argl =restore();argl = cons(object_copy(val), argl);object_free(&proc);proc =restore();if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch1274;}cont.cont = &&after_call1273;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch1274:;object_free(&val);val = proc.proc(argl); after_call1273:;object_free(&argl);argl =restore();argl = cons(object_copy(val), argl);object_free(&env);env =restore();save(argl);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|c-cdr|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|nums|"));argl = cons(object_copy(val),empty);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch1276;}cont.cont = &&after_call1275;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch1276:;object_free(&val);val = proc.proc(argl); after_call1275:;object_free(&argl);argl =restore();argl = cons(object_copy(val), argl);object_free(&proc);proc =restore();object_free(&cont);cont =restore();if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch1278;}object_free(&val);
                    val = compiled_procedure_entry(proc);
                    goto *val.cont;primitive_branch1278:;object_free(&val);val = proc.proc(argl); goto *cont.cont;false_branch1262:;object_free(&proc);proc = lookup_var_val(c_str_to_datum("|error|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|args|"));argl = cons(object_copy(val),empty);object_free(&val);val = c_str_to_datum("|(-) wrong type of argument --|");argl = cons(object_copy(val), argl);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch1264;}object_free(&val);
                    val = compiled_procedure_entry(proc);
                    goto *val.cont;primitive_branch1264:;object_free(&val);val = proc.proc(argl); goto *cont.cont;after_lambda1257:;{Object t = def_var_val(c_str_to_datum("|iter|"));
                                   object_free(&val);val = t;}object_free(&proc);proc = lookup_var_val(c_str_to_datum("|iter|"));save(cont);save(proc);save(env);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|c-exact?|"));save(proc);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|c-car|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|args|"));argl = cons(object_copy(val),empty);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch1248;}cont.cont = &&after_call1247;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch1248:;object_free(&val);val = proc.proc(argl); after_call1247:;argl = cons(object_copy(val),empty);object_free(&proc);proc =restore();if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch1250;}cont.cont = &&after_call1249;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch1250:;object_free(&val);val = proc.proc(argl); after_call1249:;argl = cons(object_copy(val),empty);object_free(&env);env =restore();save(env);save(argl);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|c-car|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|args|"));argl = cons(object_copy(val),empty);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch1252;}cont.cont = &&after_call1251;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch1252:;object_free(&val);val = proc.proc(argl); after_call1251:;object_free(&argl);argl =restore();argl = cons(object_copy(val), argl);object_free(&env);env =restore();save(argl);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|c-cdr|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|args|"));argl = cons(object_copy(val),empty);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch1254;}cont.cont = &&after_call1253;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch1254:;object_free(&val);val = proc.proc(argl); after_call1253:;object_free(&argl);argl =restore();argl = cons(object_copy(val), argl);object_free(&proc);proc =restore();object_free(&cont);cont =restore();if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch1256;}object_free(&val);
                    val = compiled_procedure_entry(proc);
                    goto *val.cont;primitive_branch1256:;object_free(&val);val = proc.proc(argl); goto *cont.cont;after_lambda1241:;{Object t = def_var_val(c_str_to_datum("|-|"));
                                   object_free(&val);val = t;}object_free(&val);val = make_compiled_procedure(&&entry1144);goto after_lambda1143;entry1144:env = compiled_procedure_env();
                          env = extend_environment(c_str_to_datum("|args|"));save(cont);save(env);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|c-length|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|args|"));argl = cons(object_copy(val),empty);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch1240;}cont.cont = &&after_call1239;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch1240:;object_free(&val);val = proc.proc(argl); after_call1239:;object_free(&env);env =restore();{Object t = def_var_val(c_str_to_datum("|len|"));
                                   object_free(&val);val = t;}object_free(&cont);cont =restore();save(cont);save(env);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|c-=|"));object_free(&val);val = c_str_to_datum("0");argl = cons(object_copy(val),empty);object_free(&val);val = lookup_var_val(c_str_to_datum("|len|"));argl = cons(object_copy(val), argl);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch1238;}cont.cont = &&after_call1237;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch1238:;object_free(&val);val = proc.proc(argl); after_call1237:;object_free(&env);env =restore();object_free(&cont);cont =restore();if(val.type==BOOLEAN && !val.boolean){
                        goto false_branch1146;}object_free(&proc);proc = lookup_var_val(c_str_to_datum("|error|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|args|"));argl = cons(object_copy(val),empty);object_free(&val);val = c_str_to_datum("|(/) wrong number of arguments --|");argl = cons(object_copy(val), argl);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch1236;}object_free(&val);
                    val = compiled_procedure_entry(proc);
                    goto *val.cont;primitive_branch1236:;object_free(&val);val = proc.proc(argl); goto *cont.cont;false_branch1146:;save(cont);save(env);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|c-=|"));object_free(&val);val = c_str_to_datum("1");argl = cons(object_copy(val),empty);object_free(&val);val = lookup_var_val(c_str_to_datum("|len|"));argl = cons(object_copy(val), argl);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch1234;}cont.cont = &&after_call1233;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch1234:;object_free(&val);val = proc.proc(argl); after_call1233:;object_free(&env);env =restore();object_free(&cont);cont =restore();if(val.type==BOOLEAN && !val.boolean){
                        goto false_branch1148;}save(cont);save(env);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|c-number?|"));save(proc);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|c-car|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|args|"));argl = cons(object_copy(val),empty);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch1230;}cont.cont = &&after_call1229;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch1230:;object_free(&val);val = proc.proc(argl); after_call1229:;argl = cons(object_copy(val),empty);object_free(&proc);proc =restore();if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch1232;}cont.cont = &&after_call1231;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch1232:;object_free(&val);val = proc.proc(argl); after_call1231:;object_free(&env);env =restore();object_free(&cont);cont =restore();if(val.type==BOOLEAN && !val.boolean){
                        goto false_branch1210;}save(cont);save(env);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|c-exact?|"));save(proc);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|c-car|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|args|"));argl = cons(object_copy(val),empty);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch1226;}cont.cont = &&after_call1225;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch1226:;object_free(&val);val = proc.proc(argl); after_call1225:;argl = cons(object_copy(val),empty);object_free(&proc);proc =restore();if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch1228;}cont.cont = &&after_call1227;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch1228:;object_free(&val);val = proc.proc(argl); after_call1227:;object_free(&env);env =restore();object_free(&cont);cont =restore();if(val.type==BOOLEAN && !val.boolean){
                        goto false_branch1214;}object_free(&proc);proc = lookup_var_val(c_str_to_datum("|c-/|"));save(cont);save(proc);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|c-car|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|args|"));argl = cons(object_copy(val),empty);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch1222;}cont.cont = &&after_call1221;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch1222:;object_free(&val);val = proc.proc(argl); after_call1221:;argl = cons(object_copy(val),empty);object_free(&val);val = c_str_to_datum("1");argl = cons(object_copy(val), argl);object_free(&proc);proc =restore();object_free(&cont);cont =restore();if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch1224;}object_free(&val);
                    val = compiled_procedure_entry(proc);
                    goto *val.cont;primitive_branch1224:;object_free(&val);val = proc.proc(argl); goto *cont.cont;false_branch1214:;object_free(&proc);proc = lookup_var_val(c_str_to_datum("|c-/|"));save(cont);save(proc);save(env);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|c-car|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|args|"));argl = cons(object_copy(val),empty);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch1216;}cont.cont = &&after_call1215;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch1216:;object_free(&val);val = proc.proc(argl); after_call1215:;argl = cons(object_copy(val),empty);object_free(&env);env =restore();save(argl);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|c-inexact|"));object_free(&val);val = c_str_to_datum("1");argl = cons(object_copy(val),empty);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch1218;}cont.cont = &&after_call1217;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch1218:;object_free(&val);val = proc.proc(argl); after_call1217:;object_free(&argl);argl =restore();argl = cons(object_copy(val), argl);object_free(&proc);proc =restore();object_free(&cont);cont =restore();if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch1220;}object_free(&val);
                    val = compiled_procedure_entry(proc);
                    goto *val.cont;primitive_branch1220:;object_free(&val);val = proc.proc(argl); goto *cont.cont;false_branch1210:;object_free(&proc);proc = lookup_var_val(c_str_to_datum("|error|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|args|"));argl = cons(object_copy(val),empty);object_free(&val);val = c_str_to_datum("|(/) wrong type of argument --|");argl = cons(object_copy(val), argl);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch1212;}object_free(&val);
                    val = compiled_procedure_entry(proc);
                    goto *val.cont;primitive_branch1212:;object_free(&val);val = proc.proc(argl); goto *cont.cont;false_branch1148:;object_free(&val);val = make_compiled_procedure(&&entry1160);goto after_lambda1159;entry1160:env = compiled_procedure_env();
                          env = extend_environment(c_str_to_datum("(|nums| . (|result| . (|e?| . ())))"));save(cont);save(env);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|c-null?|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|nums|"));argl = cons(object_copy(val),empty);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch1208;}cont.cont = &&after_call1207;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch1208:;object_free(&val);val = proc.proc(argl); after_call1207:;object_free(&env);env =restore();object_free(&cont);cont =restore();if(val.type==BOOLEAN && !val.boolean){
                        goto false_branch1162;}object_free(&val);val = lookup_var_val(c_str_to_datum("|result|"));goto *cont.cont;false_branch1162:;save(cont);save(env);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|c-number?|"));save(proc);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|c-car|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|nums|"));argl = cons(object_copy(val),empty);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch1204;}cont.cont = &&after_call1203;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch1204:;object_free(&val);val = proc.proc(argl); after_call1203:;argl = cons(object_copy(val),empty);object_free(&proc);proc =restore();if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch1206;}cont.cont = &&after_call1205;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch1206:;object_free(&val);val = proc.proc(argl); after_call1205:;object_free(&env);env =restore();object_free(&cont);cont =restore();if(val.type==BOOLEAN && !val.boolean){
                        goto false_branch1164;}save(cont);save(env);object_free(&val);val = lookup_var_val(c_str_to_datum("|e?|"));if(val.type==BOOLEAN && !val.boolean){
                        goto false_branch1198;}object_free(&proc);proc = lookup_var_val(c_str_to_datum("|c-exact?|"));save(proc);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|c-car|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|nums|"));argl = cons(object_copy(val),empty);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch1200;}cont.cont = &&after_call1199;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch1200:;object_free(&val);val = proc.proc(argl); after_call1199:;argl = cons(object_copy(val),empty);object_free(&proc);proc =restore();if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch1202;}cont.cont = &&after_if1197;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch1202:;object_free(&val);val = proc.proc(argl); goto after_if1197;false_branch1198:;object_free(&val);val = c_str_to_datum("#false");after_if1197:;object_free(&env);env =restore();object_free(&cont);cont =restore();if(val.type==BOOLEAN && !val.boolean){
                        goto false_branch1168;}save(cont);save(env);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|c-=|"));save(proc);object_free(&val);val = c_str_to_datum("0");argl = cons(object_copy(val),empty);save(argl);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|c-car|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|nums|"));argl = cons(object_copy(val),empty);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch1194;}cont.cont = &&after_call1193;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch1194:;object_free(&val);val = proc.proc(argl); after_call1193:;object_free(&argl);argl =restore();argl = cons(object_copy(val), argl);object_free(&proc);proc =restore();if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch1196;}cont.cont = &&after_call1195;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch1196:;object_free(&val);val = proc.proc(argl); after_call1195:;object_free(&env);env =restore();object_free(&cont);cont =restore();if(val.type==BOOLEAN && !val.boolean){
                        goto false_branch1182;}object_free(&proc);proc = lookup_var_val(c_str_to_datum("|error|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|args|"));argl = cons(object_copy(val),empty);object_free(&val);val = c_str_to_datum("|(/) division by zero --|");argl = cons(object_copy(val), argl);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch1192;}object_free(&val);
                    val = compiled_procedure_entry(proc);
                    goto *val.cont;primitive_branch1192:;object_free(&val);val = proc.proc(argl); goto *cont.cont;false_branch1182:;object_free(&proc);proc = lookup_var_val(c_str_to_datum("|iter|"));save(cont);save(proc);object_free(&val);val = c_str_to_datum("#true");argl = cons(object_copy(val),empty);save(env);save(argl);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|c-/|"));save(proc);save(env);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|c-car|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|nums|"));argl = cons(object_copy(val),empty);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch1184;}cont.cont = &&after_call1183;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch1184:;object_free(&val);val = proc.proc(argl); after_call1183:;argl = cons(object_copy(val),empty);object_free(&env);env =restore();object_free(&val);val = lookup_var_val(c_str_to_datum("|result|"));argl = cons(object_copy(val), argl);object_free(&proc);proc =restore();if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch1186;}cont.cont = &&after_call1185;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch1186:;object_free(&val);val = proc.proc(argl); after_call1185:;object_free(&argl);argl =restore();argl = cons(object_copy(val), argl);object_free(&env);env =restore();save(argl);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|c-cdr|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|nums|"));argl = cons(object_copy(val),empty);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch1188;}cont.cont = &&after_call1187;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch1188:;object_free(&val);val = proc.proc(argl); after_call1187:;object_free(&argl);argl =restore();argl = cons(object_copy(val), argl);object_free(&proc);proc =restore();object_free(&cont);cont =restore();if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch1190;}object_free(&val);
                    val = compiled_procedure_entry(proc);
                    goto *val.cont;primitive_branch1190:;object_free(&val);val = proc.proc(argl); goto *cont.cont;false_branch1168:;object_free(&proc);proc = lookup_var_val(c_str_to_datum("|iter|"));save(cont);save(proc);object_free(&val);val = c_str_to_datum("#false");argl = cons(object_copy(val),empty);save(env);save(argl);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|c-/|"));save(proc);save(env);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|c-inexact|"));save(proc);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|c-car|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|nums|"));argl = cons(object_copy(val),empty);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch1170;}cont.cont = &&after_call1169;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch1170:;object_free(&val);val = proc.proc(argl); after_call1169:;argl = cons(object_copy(val),empty);object_free(&proc);proc =restore();if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch1172;}cont.cont = &&after_call1171;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch1172:;object_free(&val);val = proc.proc(argl); after_call1171:;argl = cons(object_copy(val),empty);object_free(&env);env =restore();save(argl);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|c-inexact|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|result|"));argl = cons(object_copy(val),empty);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch1174;}cont.cont = &&after_call1173;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch1174:;object_free(&val);val = proc.proc(argl); after_call1173:;object_free(&argl);argl =restore();argl = cons(object_copy(val), argl);object_free(&proc);proc =restore();if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch1176;}cont.cont = &&after_call1175;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch1176:;object_free(&val);val = proc.proc(argl); after_call1175:;object_free(&argl);argl =restore();argl = cons(object_copy(val), argl);object_free(&env);env =restore();save(argl);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|c-cdr|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|nums|"));argl = cons(object_copy(val),empty);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch1178;}cont.cont = &&after_call1177;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch1178:;object_free(&val);val = proc.proc(argl); after_call1177:;object_free(&argl);argl =restore();argl = cons(object_copy(val), argl);object_free(&proc);proc =restore();object_free(&cont);cont =restore();if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch1180;}object_free(&val);
                    val = compiled_procedure_entry(proc);
                    goto *val.cont;primitive_branch1180:;object_free(&val);val = proc.proc(argl); goto *cont.cont;false_branch1164:;object_free(&proc);proc = lookup_var_val(c_str_to_datum("|error|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|args|"));argl = cons(object_copy(val),empty);object_free(&val);val = c_str_to_datum("|(/) wrong type of argument --|");argl = cons(object_copy(val), argl);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch1166;}object_free(&val);
                    val = compiled_procedure_entry(proc);
                    goto *val.cont;primitive_branch1166:;object_free(&val);val = proc.proc(argl); goto *cont.cont;after_lambda1159:;{Object t = def_var_val(c_str_to_datum("|iter|"));
                                   object_free(&val);val = t;}object_free(&proc);proc = lookup_var_val(c_str_to_datum("|iter|"));save(cont);save(proc);save(env);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|c-exact?|"));save(proc);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|c-car|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|args|"));argl = cons(object_copy(val),empty);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch1150;}cont.cont = &&after_call1149;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch1150:;object_free(&val);val = proc.proc(argl); after_call1149:;argl = cons(object_copy(val),empty);object_free(&proc);proc =restore();if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch1152;}cont.cont = &&after_call1151;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch1152:;object_free(&val);val = proc.proc(argl); after_call1151:;argl = cons(object_copy(val),empty);object_free(&env);env =restore();save(env);save(argl);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|c-car|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|args|"));argl = cons(object_copy(val),empty);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch1154;}cont.cont = &&after_call1153;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch1154:;object_free(&val);val = proc.proc(argl); after_call1153:;object_free(&argl);argl =restore();argl = cons(object_copy(val), argl);object_free(&env);env =restore();save(argl);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|c-cdr|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|args|"));argl = cons(object_copy(val),empty);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch1156;}cont.cont = &&after_call1155;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch1156:;object_free(&val);val = proc.proc(argl); after_call1155:;object_free(&argl);argl =restore();argl = cons(object_copy(val), argl);object_free(&proc);proc =restore();object_free(&cont);cont =restore();if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch1158;}object_free(&val);
                    val = compiled_procedure_entry(proc);
                    goto *val.cont;primitive_branch1158:;object_free(&val);val = proc.proc(argl); goto *cont.cont;after_lambda1143:;{Object t = def_var_val(c_str_to_datum("|/|"));
                                   object_free(&val);val = t;}object_free(&val);val = make_compiled_procedure(&&entry1076);goto after_lambda1075;entry1076:env = compiled_procedure_env();
                          env = extend_environment(c_str_to_datum("|args|"));save(cont);save(env);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|c-length|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|args|"));argl = cons(object_copy(val),empty);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch1142;}cont.cont = &&after_call1141;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch1142:;object_free(&val);val = proc.proc(argl); after_call1141:;object_free(&env);env =restore();{Object t = def_var_val(c_str_to_datum("|len|"));
                                   object_free(&val);val = t;}object_free(&cont);cont =restore();save(cont);save(env);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|c-<|"));object_free(&val);val = c_str_to_datum("2");argl = cons(object_copy(val),empty);object_free(&val);val = lookup_var_val(c_str_to_datum("|len|"));argl = cons(object_copy(val), argl);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch1140;}cont.cont = &&after_call1139;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch1140:;object_free(&val);val = proc.proc(argl); after_call1139:;object_free(&env);env =restore();object_free(&cont);cont =restore();if(val.type==BOOLEAN && !val.boolean){
                        goto false_branch1078;}object_free(&proc);proc = lookup_var_val(c_str_to_datum("|error|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|args|"));argl = cons(object_copy(val),empty);object_free(&val);val = c_str_to_datum("|(<) wrong number of arguments --|");argl = cons(object_copy(val), argl);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch1138;}object_free(&val);
                    val = compiled_procedure_entry(proc);
                    goto *val.cont;primitive_branch1138:;object_free(&val);val = proc.proc(argl); goto *cont.cont;false_branch1078:;save(cont);save(env);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|c-real?|"));save(proc);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|c-car|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|args|"));argl = cons(object_copy(val),empty);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch1134;}cont.cont = &&after_call1133;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch1134:;object_free(&val);val = proc.proc(argl); after_call1133:;argl = cons(object_copy(val),empty);object_free(&proc);proc =restore();if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch1136;}cont.cont = &&after_call1135;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch1136:;object_free(&val);val = proc.proc(argl); after_call1135:;object_free(&env);env =restore();object_free(&cont);cont =restore();if(val.type==BOOLEAN && !val.boolean){
                        goto false_branch1080;}object_free(&val);val = make_compiled_procedure(&&entry1116);goto after_lambda1115;entry1116:env = compiled_procedure_env();
                          env = extend_environment(c_str_to_datum("(|x| . (|y| . ()))"));save(cont);save(env);save(env);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|c-exact?|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|x|"));argl = cons(object_copy(val),empty);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch1132;}cont.cont = &&after_call1131;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch1132:;object_free(&val);val = proc.proc(argl); after_call1131:;object_free(&env);env =restore();if(val.type==BOOLEAN && !val.boolean){
                        goto false_branch1128;}object_free(&proc);proc = lookup_var_val(c_str_to_datum("|c-exact?|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|y|"));argl = cons(object_copy(val),empty);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch1130;}cont.cont = &&after_if1127;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch1130:;object_free(&val);val = proc.proc(argl); goto after_if1127;false_branch1128:;object_free(&val);val = c_str_to_datum("#false");after_if1127:;object_free(&env);env =restore();object_free(&cont);cont =restore();if(val.type==BOOLEAN && !val.boolean){
                        goto false_branch1118;}object_free(&proc);proc = lookup_var_val(c_str_to_datum("|c-<|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|y|"));argl = cons(object_copy(val),empty);object_free(&val);val = lookup_var_val(c_str_to_datum("|x|"));argl = cons(object_copy(val), argl);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch1126;}object_free(&val);
                    val = compiled_procedure_entry(proc);
                    goto *val.cont;primitive_branch1126:;object_free(&val);val = proc.proc(argl); goto *cont.cont;false_branch1118:;object_free(&proc);proc = lookup_var_val(c_str_to_datum("|c-<|"));save(cont);save(proc);save(env);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|c-inexact|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|y|"));argl = cons(object_copy(val),empty);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch1120;}cont.cont = &&after_call1119;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch1120:;object_free(&val);val = proc.proc(argl); after_call1119:;argl = cons(object_copy(val),empty);object_free(&env);env =restore();save(argl);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|c-inexact|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|x|"));argl = cons(object_copy(val),empty);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch1122;}cont.cont = &&after_call1121;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch1122:;object_free(&val);val = proc.proc(argl); after_call1121:;object_free(&argl);argl =restore();argl = cons(object_copy(val), argl);object_free(&proc);proc =restore();object_free(&cont);cont =restore();if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch1124;}object_free(&val);
                    val = compiled_procedure_entry(proc);
                    goto *val.cont;primitive_branch1124:;object_free(&val);val = proc.proc(argl); goto *cont.cont;after_lambda1115:;{Object t = def_var_val(c_str_to_datum("|cmp|"));
                                   object_free(&val);val = t;}object_free(&val);val = make_compiled_procedure(&&entry1090);goto after_lambda1089;entry1090:env = compiled_procedure_env();
                          env = extend_environment(c_str_to_datum("(|x| . (|xs| . ()))"));save(cont);save(env);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|c-null?|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|xs|"));argl = cons(object_copy(val),empty);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch1114;}cont.cont = &&after_call1113;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch1114:;object_free(&val);val = proc.proc(argl); after_call1113:;object_free(&env);env =restore();object_free(&cont);cont =restore();if(val.type==BOOLEAN && !val.boolean){
                        goto false_branch1092;}object_free(&val);val = c_str_to_datum("#true");goto *cont.cont;false_branch1092:;save(cont);save(env);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|c-real?|"));save(proc);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|c-car|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|xs|"));argl = cons(object_copy(val),empty);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch1110;}cont.cont = &&after_call1109;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch1110:;object_free(&val);val = proc.proc(argl); after_call1109:;argl = cons(object_copy(val),empty);object_free(&proc);proc =restore();if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch1112;}cont.cont = &&after_call1111;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch1112:;object_free(&val);val = proc.proc(argl); after_call1111:;object_free(&env);env =restore();object_free(&cont);cont =restore();if(val.type==BOOLEAN && !val.boolean){
                        goto false_branch1094;}save(cont);save(env);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|cmp|"));save(proc);save(env);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|c-car|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|xs|"));argl = cons(object_copy(val),empty);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch1106;}cont.cont = &&after_call1105;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch1106:;object_free(&val);val = proc.proc(argl); after_call1105:;argl = cons(object_copy(val),empty);object_free(&env);env =restore();object_free(&val);val = lookup_var_val(c_str_to_datum("|x|"));argl = cons(object_copy(val), argl);object_free(&proc);proc =restore();if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch1108;}cont.cont = &&after_call1107;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch1108:;object_free(&val);val = proc.proc(argl); after_call1107:;object_free(&env);env =restore();object_free(&cont);cont =restore();if(val.type==BOOLEAN && !val.boolean){
                        goto false_branch1098;}object_free(&proc);proc = lookup_var_val(c_str_to_datum("|iter|"));save(cont);save(proc);save(env);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|c-cdr|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|xs|"));argl = cons(object_copy(val),empty);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch1100;}cont.cont = &&after_call1099;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch1100:;object_free(&val);val = proc.proc(argl); after_call1099:;argl = cons(object_copy(val),empty);object_free(&env);env =restore();save(argl);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|c-car|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|xs|"));argl = cons(object_copy(val),empty);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch1102;}cont.cont = &&after_call1101;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch1102:;object_free(&val);val = proc.proc(argl); after_call1101:;object_free(&argl);argl =restore();argl = cons(object_copy(val), argl);object_free(&proc);proc =restore();object_free(&cont);cont =restore();if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch1104;}object_free(&val);
                    val = compiled_procedure_entry(proc);
                    goto *val.cont;primitive_branch1104:;object_free(&val);val = proc.proc(argl); goto *cont.cont;false_branch1098:;object_free(&val);val = c_str_to_datum("#false");goto *cont.cont;false_branch1094:;object_free(&proc);proc = lookup_var_val(c_str_to_datum("|error|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|args|"));argl = cons(object_copy(val),empty);object_free(&val);val = c_str_to_datum("|(<) wrong type of argument --|");argl = cons(object_copy(val), argl);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch1096;}object_free(&val);
                    val = compiled_procedure_entry(proc);
                    goto *val.cont;primitive_branch1096:;object_free(&val);val = proc.proc(argl); goto *cont.cont;after_lambda1089:;{Object t = def_var_val(c_str_to_datum("|iter|"));
                                   object_free(&val);val = t;}object_free(&proc);proc = lookup_var_val(c_str_to_datum("|iter|"));save(cont);save(proc);save(env);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|c-cdr|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|args|"));argl = cons(object_copy(val),empty);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch1084;}cont.cont = &&after_call1083;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch1084:;object_free(&val);val = proc.proc(argl); after_call1083:;argl = cons(object_copy(val),empty);object_free(&env);env =restore();save(argl);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|c-car|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|args|"));argl = cons(object_copy(val),empty);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch1086;}cont.cont = &&after_call1085;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch1086:;object_free(&val);val = proc.proc(argl); after_call1085:;object_free(&argl);argl =restore();argl = cons(object_copy(val), argl);object_free(&proc);proc =restore();object_free(&cont);cont =restore();if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch1088;}object_free(&val);
                    val = compiled_procedure_entry(proc);
                    goto *val.cont;primitive_branch1088:;object_free(&val);val = proc.proc(argl); goto *cont.cont;false_branch1080:;object_free(&proc);proc = lookup_var_val(c_str_to_datum("|error|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|args|"));argl = cons(object_copy(val),empty);object_free(&val);val = c_str_to_datum("|(<) wrong type of argument --|");argl = cons(object_copy(val), argl);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch1082;}object_free(&val);
                    val = compiled_procedure_entry(proc);
                    goto *val.cont;primitive_branch1082:;object_free(&val);val = proc.proc(argl); goto *cont.cont;after_lambda1075:;{Object t = def_var_val(c_str_to_datum("|<|"));
                                   object_free(&val);val = t;}object_free(&val);val = make_compiled_procedure(&&entry976);goto after_lambda975;entry976:env = compiled_procedure_env();
                          env = extend_environment(c_str_to_datum("|args|"));save(cont);save(env);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|c-length|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|args|"));argl = cons(object_copy(val),empty);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch1074;}cont.cont = &&after_call1073;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch1074:;object_free(&val);val = proc.proc(argl); after_call1073:;object_free(&env);env =restore();{Object t = def_var_val(c_str_to_datum("|len|"));
                                   object_free(&val);val = t;}object_free(&cont);cont =restore();save(cont);save(env);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|c-<|"));object_free(&val);val = c_str_to_datum("2");argl = cons(object_copy(val),empty);object_free(&val);val = lookup_var_val(c_str_to_datum("|len|"));argl = cons(object_copy(val), argl);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch1072;}cont.cont = &&after_call1071;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch1072:;object_free(&val);val = proc.proc(argl); after_call1071:;object_free(&env);env =restore();object_free(&cont);cont =restore();if(val.type==BOOLEAN && !val.boolean){
                        goto false_branch978;}object_free(&proc);proc = lookup_var_val(c_str_to_datum("|error|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|args|"));argl = cons(object_copy(val),empty);object_free(&val);val = c_str_to_datum("|(<=) wrong number of arguments --|");argl = cons(object_copy(val), argl);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch1070;}object_free(&val);
                    val = compiled_procedure_entry(proc);
                    goto *val.cont;primitive_branch1070:;object_free(&val);val = proc.proc(argl); goto *cont.cont;false_branch978:;save(cont);save(env);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|c-real?|"));save(proc);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|c-car|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|args|"));argl = cons(object_copy(val),empty);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch1066;}cont.cont = &&after_call1065;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch1066:;object_free(&val);val = proc.proc(argl); after_call1065:;argl = cons(object_copy(val),empty);object_free(&proc);proc =restore();if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch1068;}cont.cont = &&after_call1067;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch1068:;object_free(&val);val = proc.proc(argl); after_call1067:;object_free(&env);env =restore();object_free(&cont);cont =restore();if(val.type==BOOLEAN && !val.boolean){
                        goto false_branch980;}object_free(&val);val = make_compiled_procedure(&&entry1016);goto after_lambda1015;entry1016:env = compiled_procedure_env();
                          env = extend_environment(c_str_to_datum("(|x| . (|y| . ()))"));save(cont);save(env);save(env);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|c-exact?|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|x|"));argl = cons(object_copy(val),empty);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch1064;}cont.cont = &&after_call1063;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch1064:;object_free(&val);val = proc.proc(argl); after_call1063:;object_free(&env);env =restore();if(val.type==BOOLEAN && !val.boolean){
                        goto false_branch1060;}object_free(&proc);proc = lookup_var_val(c_str_to_datum("|c-exact?|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|y|"));argl = cons(object_copy(val),empty);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch1062;}cont.cont = &&after_if1059;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch1062:;object_free(&val);val = proc.proc(argl); goto after_if1059;false_branch1060:;object_free(&val);val = c_str_to_datum("#false");after_if1059:;object_free(&env);env =restore();object_free(&cont);cont =restore();if(val.type==BOOLEAN && !val.boolean){
                        goto false_branch1018;}save(cont);save(env);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|c-=|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|y|"));argl = cons(object_copy(val),empty);object_free(&val);val = lookup_var_val(c_str_to_datum("|x|"));argl = cons(object_copy(val), argl);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch1058;}cont.cont = &&after_call1057;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch1058:;object_free(&val);val = proc.proc(argl); after_call1057:;object_free(&env);env =restore();object_free(&cont);cont =restore();if(val.type==BOOLEAN && !val.boolean){
                        goto false_branch1048;}object_free(&proc);proc = lookup_var_val(c_str_to_datum("|c-=|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|y|"));argl = cons(object_copy(val),empty);object_free(&val);val = lookup_var_val(c_str_to_datum("|x|"));argl = cons(object_copy(val), argl);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch1056;}object_free(&val);
                    val = compiled_procedure_entry(proc);
                    goto *val.cont;primitive_branch1056:;object_free(&val);val = proc.proc(argl); goto *cont.cont;false_branch1048:;save(cont);save(env);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|c-<|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|y|"));argl = cons(object_copy(val),empty);object_free(&val);val = lookup_var_val(c_str_to_datum("|x|"));argl = cons(object_copy(val), argl);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch1054;}cont.cont = &&after_call1053;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch1054:;object_free(&val);val = proc.proc(argl); after_call1053:;object_free(&env);env =restore();object_free(&cont);cont =restore();if(val.type==BOOLEAN && !val.boolean){
                        goto false_branch1050;}object_free(&proc);proc = lookup_var_val(c_str_to_datum("|c-<|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|y|"));argl = cons(object_copy(val),empty);object_free(&val);val = lookup_var_val(c_str_to_datum("|x|"));argl = cons(object_copy(val), argl);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch1052;}object_free(&val);
                    val = compiled_procedure_entry(proc);
                    goto *val.cont;primitive_branch1052:;object_free(&val);val = proc.proc(argl); goto *cont.cont;false_branch1050:;object_free(&val);val = c_str_to_datum("#false");goto *cont.cont;false_branch1018:;save(cont);save(env);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|c-=|"));save(proc);save(env);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|c-inexact|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|y|"));argl = cons(object_copy(val),empty);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch1042;}cont.cont = &&after_call1041;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch1042:;object_free(&val);val = proc.proc(argl); after_call1041:;argl = cons(object_copy(val),empty);object_free(&env);env =restore();save(argl);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|c-inexact|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|x|"));argl = cons(object_copy(val),empty);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch1044;}cont.cont = &&after_call1043;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch1044:;object_free(&val);val = proc.proc(argl); after_call1043:;object_free(&argl);argl =restore();argl = cons(object_copy(val), argl);object_free(&proc);proc =restore();if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch1046;}cont.cont = &&after_call1045;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch1046:;object_free(&val);val = proc.proc(argl); after_call1045:;object_free(&env);env =restore();object_free(&cont);cont =restore();if(val.type==BOOLEAN && !val.boolean){
                        goto false_branch1020;}object_free(&proc);proc = lookup_var_val(c_str_to_datum("|c-=|"));save(cont);save(proc);save(env);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|c-inexact|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|y|"));argl = cons(object_copy(val),empty);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch1036;}cont.cont = &&after_call1035;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch1036:;object_free(&val);val = proc.proc(argl); after_call1035:;argl = cons(object_copy(val),empty);object_free(&env);env =restore();save(argl);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|c-inexact|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|x|"));argl = cons(object_copy(val),empty);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch1038;}cont.cont = &&after_call1037;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch1038:;object_free(&val);val = proc.proc(argl); after_call1037:;object_free(&argl);argl =restore();argl = cons(object_copy(val), argl);object_free(&proc);proc =restore();object_free(&cont);cont =restore();if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch1040;}object_free(&val);
                    val = compiled_procedure_entry(proc);
                    goto *val.cont;primitive_branch1040:;object_free(&val);val = proc.proc(argl); goto *cont.cont;false_branch1020:;save(cont);save(env);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|c-<|"));save(proc);save(env);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|c-inexact|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|y|"));argl = cons(object_copy(val),empty);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch1030;}cont.cont = &&after_call1029;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch1030:;object_free(&val);val = proc.proc(argl); after_call1029:;argl = cons(object_copy(val),empty);object_free(&env);env =restore();save(argl);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|c-inexact|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|x|"));argl = cons(object_copy(val),empty);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch1032;}cont.cont = &&after_call1031;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch1032:;object_free(&val);val = proc.proc(argl); after_call1031:;object_free(&argl);argl =restore();argl = cons(object_copy(val), argl);object_free(&proc);proc =restore();if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch1034;}cont.cont = &&after_call1033;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch1034:;object_free(&val);val = proc.proc(argl); after_call1033:;object_free(&env);env =restore();object_free(&cont);cont =restore();if(val.type==BOOLEAN && !val.boolean){
                        goto false_branch1022;}object_free(&proc);proc = lookup_var_val(c_str_to_datum("|c-<|"));save(cont);save(proc);save(env);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|c-inexact|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|y|"));argl = cons(object_copy(val),empty);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch1024;}cont.cont = &&after_call1023;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch1024:;object_free(&val);val = proc.proc(argl); after_call1023:;argl = cons(object_copy(val),empty);object_free(&env);env =restore();save(argl);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|c-inexact|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|x|"));argl = cons(object_copy(val),empty);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch1026;}cont.cont = &&after_call1025;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch1026:;object_free(&val);val = proc.proc(argl); after_call1025:;object_free(&argl);argl =restore();argl = cons(object_copy(val), argl);object_free(&proc);proc =restore();object_free(&cont);cont =restore();if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch1028;}object_free(&val);
                    val = compiled_procedure_entry(proc);
                    goto *val.cont;primitive_branch1028:;object_free(&val);val = proc.proc(argl); goto *cont.cont;false_branch1022:;object_free(&val);val = c_str_to_datum("#false");goto *cont.cont;after_lambda1015:;{Object t = def_var_val(c_str_to_datum("|cmp|"));
                                   object_free(&val);val = t;}object_free(&val);val = make_compiled_procedure(&&entry990);goto after_lambda989;entry990:env = compiled_procedure_env();
                          env = extend_environment(c_str_to_datum("(|x| . (|xs| . ()))"));save(cont);save(env);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|c-null?|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|xs|"));argl = cons(object_copy(val),empty);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch1014;}cont.cont = &&after_call1013;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch1014:;object_free(&val);val = proc.proc(argl); after_call1013:;object_free(&env);env =restore();object_free(&cont);cont =restore();if(val.type==BOOLEAN && !val.boolean){
                        goto false_branch992;}object_free(&val);val = c_str_to_datum("#true");goto *cont.cont;false_branch992:;save(cont);save(env);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|c-real?|"));save(proc);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|c-car|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|xs|"));argl = cons(object_copy(val),empty);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch1010;}cont.cont = &&after_call1009;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch1010:;object_free(&val);val = proc.proc(argl); after_call1009:;argl = cons(object_copy(val),empty);object_free(&proc);proc =restore();if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch1012;}cont.cont = &&after_call1011;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch1012:;object_free(&val);val = proc.proc(argl); after_call1011:;object_free(&env);env =restore();object_free(&cont);cont =restore();if(val.type==BOOLEAN && !val.boolean){
                        goto false_branch994;}save(cont);save(env);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|cmp|"));save(proc);save(env);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|c-car|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|xs|"));argl = cons(object_copy(val),empty);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch1006;}cont.cont = &&after_call1005;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch1006:;object_free(&val);val = proc.proc(argl); after_call1005:;argl = cons(object_copy(val),empty);object_free(&env);env =restore();object_free(&val);val = lookup_var_val(c_str_to_datum("|x|"));argl = cons(object_copy(val), argl);object_free(&proc);proc =restore();if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch1008;}cont.cont = &&after_call1007;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch1008:;object_free(&val);val = proc.proc(argl); after_call1007:;object_free(&env);env =restore();object_free(&cont);cont =restore();if(val.type==BOOLEAN && !val.boolean){
                        goto false_branch998;}object_free(&proc);proc = lookup_var_val(c_str_to_datum("|iter|"));save(cont);save(proc);save(env);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|c-cdr|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|xs|"));argl = cons(object_copy(val),empty);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch1000;}cont.cont = &&after_call999;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch1000:;object_free(&val);val = proc.proc(argl); after_call999:;argl = cons(object_copy(val),empty);object_free(&env);env =restore();save(argl);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|c-car|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|xs|"));argl = cons(object_copy(val),empty);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch1002;}cont.cont = &&after_call1001;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch1002:;object_free(&val);val = proc.proc(argl); after_call1001:;object_free(&argl);argl =restore();argl = cons(object_copy(val), argl);object_free(&proc);proc =restore();object_free(&cont);cont =restore();if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch1004;}object_free(&val);
                    val = compiled_procedure_entry(proc);
                    goto *val.cont;primitive_branch1004:;object_free(&val);val = proc.proc(argl); goto *cont.cont;false_branch998:;object_free(&val);val = c_str_to_datum("#false");goto *cont.cont;false_branch994:;object_free(&proc);proc = lookup_var_val(c_str_to_datum("|error|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|args|"));argl = cons(object_copy(val),empty);object_free(&val);val = c_str_to_datum("|(<=) wrong type of argument --|");argl = cons(object_copy(val), argl);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch996;}object_free(&val);
                    val = compiled_procedure_entry(proc);
                    goto *val.cont;primitive_branch996:;object_free(&val);val = proc.proc(argl); goto *cont.cont;after_lambda989:;{Object t = def_var_val(c_str_to_datum("|iter|"));
                                   object_free(&val);val = t;}object_free(&proc);proc = lookup_var_val(c_str_to_datum("|iter|"));save(cont);save(proc);save(env);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|c-cdr|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|args|"));argl = cons(object_copy(val),empty);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch984;}cont.cont = &&after_call983;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch984:;object_free(&val);val = proc.proc(argl); after_call983:;argl = cons(object_copy(val),empty);object_free(&env);env =restore();save(argl);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|c-car|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|args|"));argl = cons(object_copy(val),empty);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch986;}cont.cont = &&after_call985;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch986:;object_free(&val);val = proc.proc(argl); after_call985:;object_free(&argl);argl =restore();argl = cons(object_copy(val), argl);object_free(&proc);proc =restore();object_free(&cont);cont =restore();if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch988;}object_free(&val);
                    val = compiled_procedure_entry(proc);
                    goto *val.cont;primitive_branch988:;object_free(&val);val = proc.proc(argl); goto *cont.cont;false_branch980:;object_free(&proc);proc = lookup_var_val(c_str_to_datum("|error|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|args|"));argl = cons(object_copy(val),empty);object_free(&val);val = c_str_to_datum("|(<=) wrong type of argument --|");argl = cons(object_copy(val), argl);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch982;}object_free(&val);
                    val = compiled_procedure_entry(proc);
                    goto *val.cont;primitive_branch982:;object_free(&val);val = proc.proc(argl); goto *cont.cont;after_lambda975:;{Object t = def_var_val(c_str_to_datum("|<=|"));
                                   object_free(&val);val = t;}object_free(&val);val = make_compiled_procedure(&&entry908);goto after_lambda907;entry908:env = compiled_procedure_env();
                          env = extend_environment(c_str_to_datum("|args|"));save(cont);save(env);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|c-length|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|args|"));argl = cons(object_copy(val),empty);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch974;}cont.cont = &&after_call973;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch974:;object_free(&val);val = proc.proc(argl); after_call973:;object_free(&env);env =restore();{Object t = def_var_val(c_str_to_datum("|len|"));
                                   object_free(&val);val = t;}object_free(&cont);cont =restore();save(cont);save(env);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|c-<|"));object_free(&val);val = c_str_to_datum("2");argl = cons(object_copy(val),empty);object_free(&val);val = lookup_var_val(c_str_to_datum("|len|"));argl = cons(object_copy(val), argl);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch972;}cont.cont = &&after_call971;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch972:;object_free(&val);val = proc.proc(argl); after_call971:;object_free(&env);env =restore();object_free(&cont);cont =restore();if(val.type==BOOLEAN && !val.boolean){
                        goto false_branch910;}object_free(&proc);proc = lookup_var_val(c_str_to_datum("|error|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|args|"));argl = cons(object_copy(val),empty);object_free(&val);val = c_str_to_datum("|(=) wrong number of arguments --|");argl = cons(object_copy(val), argl);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch970;}object_free(&val);
                    val = compiled_procedure_entry(proc);
                    goto *val.cont;primitive_branch970:;object_free(&val);val = proc.proc(argl); goto *cont.cont;false_branch910:;save(cont);save(env);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|c-number?|"));save(proc);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|c-car|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|args|"));argl = cons(object_copy(val),empty);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch966;}cont.cont = &&after_call965;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch966:;object_free(&val);val = proc.proc(argl); after_call965:;argl = cons(object_copy(val),empty);object_free(&proc);proc =restore();if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch968;}cont.cont = &&after_call967;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch968:;object_free(&val);val = proc.proc(argl); after_call967:;object_free(&env);env =restore();object_free(&cont);cont =restore();if(val.type==BOOLEAN && !val.boolean){
                        goto false_branch912;}object_free(&val);val = make_compiled_procedure(&&entry948);goto after_lambda947;entry948:env = compiled_procedure_env();
                          env = extend_environment(c_str_to_datum("(|x| . (|y| . ()))"));save(cont);save(env);save(env);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|c-exact?|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|x|"));argl = cons(object_copy(val),empty);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch964;}cont.cont = &&after_call963;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch964:;object_free(&val);val = proc.proc(argl); after_call963:;object_free(&env);env =restore();if(val.type==BOOLEAN && !val.boolean){
                        goto false_branch960;}object_free(&proc);proc = lookup_var_val(c_str_to_datum("|c-exact?|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|y|"));argl = cons(object_copy(val),empty);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch962;}cont.cont = &&after_if959;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch962:;object_free(&val);val = proc.proc(argl); goto after_if959;false_branch960:;object_free(&val);val = c_str_to_datum("#false");after_if959:;object_free(&env);env =restore();object_free(&cont);cont =restore();if(val.type==BOOLEAN && !val.boolean){
                        goto false_branch950;}object_free(&proc);proc = lookup_var_val(c_str_to_datum("|c-=|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|y|"));argl = cons(object_copy(val),empty);object_free(&val);val = lookup_var_val(c_str_to_datum("|x|"));argl = cons(object_copy(val), argl);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch958;}object_free(&val);
                    val = compiled_procedure_entry(proc);
                    goto *val.cont;primitive_branch958:;object_free(&val);val = proc.proc(argl); goto *cont.cont;false_branch950:;object_free(&proc);proc = lookup_var_val(c_str_to_datum("|c-=|"));save(cont);save(proc);save(env);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|c-inexact|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|y|"));argl = cons(object_copy(val),empty);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch952;}cont.cont = &&after_call951;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch952:;object_free(&val);val = proc.proc(argl); after_call951:;argl = cons(object_copy(val),empty);object_free(&env);env =restore();save(argl);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|c-inexact|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|x|"));argl = cons(object_copy(val),empty);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch954;}cont.cont = &&after_call953;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch954:;object_free(&val);val = proc.proc(argl); after_call953:;object_free(&argl);argl =restore();argl = cons(object_copy(val), argl);object_free(&proc);proc =restore();object_free(&cont);cont =restore();if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch956;}object_free(&val);
                    val = compiled_procedure_entry(proc);
                    goto *val.cont;primitive_branch956:;object_free(&val);val = proc.proc(argl); goto *cont.cont;after_lambda947:;{Object t = def_var_val(c_str_to_datum("|cmp|"));
                                   object_free(&val);val = t;}object_free(&val);val = make_compiled_procedure(&&entry922);goto after_lambda921;entry922:env = compiled_procedure_env();
                          env = extend_environment(c_str_to_datum("(|x| . (|xs| . ()))"));save(cont);save(env);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|c-null?|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|xs|"));argl = cons(object_copy(val),empty);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch946;}cont.cont = &&after_call945;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch946:;object_free(&val);val = proc.proc(argl); after_call945:;object_free(&env);env =restore();object_free(&cont);cont =restore();if(val.type==BOOLEAN && !val.boolean){
                        goto false_branch924;}object_free(&val);val = c_str_to_datum("#true");goto *cont.cont;false_branch924:;save(cont);save(env);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|c-number?|"));save(proc);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|c-car|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|xs|"));argl = cons(object_copy(val),empty);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch942;}cont.cont = &&after_call941;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch942:;object_free(&val);val = proc.proc(argl); after_call941:;argl = cons(object_copy(val),empty);object_free(&proc);proc =restore();if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch944;}cont.cont = &&after_call943;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch944:;object_free(&val);val = proc.proc(argl); after_call943:;object_free(&env);env =restore();object_free(&cont);cont =restore();if(val.type==BOOLEAN && !val.boolean){
                        goto false_branch926;}save(cont);save(env);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|cmp|"));save(proc);save(env);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|c-car|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|xs|"));argl = cons(object_copy(val),empty);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch938;}cont.cont = &&after_call937;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch938:;object_free(&val);val = proc.proc(argl); after_call937:;argl = cons(object_copy(val),empty);object_free(&env);env =restore();object_free(&val);val = lookup_var_val(c_str_to_datum("|x|"));argl = cons(object_copy(val), argl);object_free(&proc);proc =restore();if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch940;}cont.cont = &&after_call939;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch940:;object_free(&val);val = proc.proc(argl); after_call939:;object_free(&env);env =restore();object_free(&cont);cont =restore();if(val.type==BOOLEAN && !val.boolean){
                        goto false_branch930;}object_free(&proc);proc = lookup_var_val(c_str_to_datum("|iter|"));save(cont);save(proc);save(env);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|c-cdr|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|xs|"));argl = cons(object_copy(val),empty);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch932;}cont.cont = &&after_call931;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch932:;object_free(&val);val = proc.proc(argl); after_call931:;argl = cons(object_copy(val),empty);object_free(&env);env =restore();save(argl);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|c-car|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|xs|"));argl = cons(object_copy(val),empty);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch934;}cont.cont = &&after_call933;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch934:;object_free(&val);val = proc.proc(argl); after_call933:;object_free(&argl);argl =restore();argl = cons(object_copy(val), argl);object_free(&proc);proc =restore();object_free(&cont);cont =restore();if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch936;}object_free(&val);
                    val = compiled_procedure_entry(proc);
                    goto *val.cont;primitive_branch936:;object_free(&val);val = proc.proc(argl); goto *cont.cont;false_branch930:;object_free(&val);val = c_str_to_datum("#false");goto *cont.cont;false_branch926:;object_free(&proc);proc = lookup_var_val(c_str_to_datum("|error|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|args|"));argl = cons(object_copy(val),empty);object_free(&val);val = c_str_to_datum("|(=) wrong type of argument --|");argl = cons(object_copy(val), argl);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch928;}object_free(&val);
                    val = compiled_procedure_entry(proc);
                    goto *val.cont;primitive_branch928:;object_free(&val);val = proc.proc(argl); goto *cont.cont;after_lambda921:;{Object t = def_var_val(c_str_to_datum("|iter|"));
                                   object_free(&val);val = t;}object_free(&proc);proc = lookup_var_val(c_str_to_datum("|iter|"));save(cont);save(proc);save(env);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|c-cdr|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|args|"));argl = cons(object_copy(val),empty);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch916;}cont.cont = &&after_call915;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch916:;object_free(&val);val = proc.proc(argl); after_call915:;argl = cons(object_copy(val),empty);object_free(&env);env =restore();save(argl);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|c-car|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|args|"));argl = cons(object_copy(val),empty);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch918;}cont.cont = &&after_call917;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch918:;object_free(&val);val = proc.proc(argl); after_call917:;object_free(&argl);argl =restore();argl = cons(object_copy(val), argl);object_free(&proc);proc =restore();object_free(&cont);cont =restore();if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch920;}object_free(&val);
                    val = compiled_procedure_entry(proc);
                    goto *val.cont;primitive_branch920:;object_free(&val);val = proc.proc(argl); goto *cont.cont;false_branch912:;object_free(&proc);proc = lookup_var_val(c_str_to_datum("|error|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|args|"));argl = cons(object_copy(val),empty);object_free(&val);val = c_str_to_datum("|(=) wrong type of argument --|");argl = cons(object_copy(val), argl);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch914;}object_free(&val);
                    val = compiled_procedure_entry(proc);
                    goto *val.cont;primitive_branch914:;object_free(&val);val = proc.proc(argl); goto *cont.cont;after_lambda907:;{Object t = def_var_val(c_str_to_datum("|=|"));
                                   object_free(&val);val = t;}object_free(&val);val = make_compiled_procedure(&&entry840);goto after_lambda839;entry840:env = compiled_procedure_env();
                          env = extend_environment(c_str_to_datum("|args|"));save(cont);save(env);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|c-length|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|args|"));argl = cons(object_copy(val),empty);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch906;}cont.cont = &&after_call905;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch906:;object_free(&val);val = proc.proc(argl); after_call905:;object_free(&env);env =restore();{Object t = def_var_val(c_str_to_datum("|len|"));
                                   object_free(&val);val = t;}object_free(&cont);cont =restore();save(cont);save(env);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|c-<|"));object_free(&val);val = c_str_to_datum("2");argl = cons(object_copy(val),empty);object_free(&val);val = lookup_var_val(c_str_to_datum("|len|"));argl = cons(object_copy(val), argl);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch904;}cont.cont = &&after_call903;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch904:;object_free(&val);val = proc.proc(argl); after_call903:;object_free(&env);env =restore();object_free(&cont);cont =restore();if(val.type==BOOLEAN && !val.boolean){
                        goto false_branch842;}object_free(&proc);proc = lookup_var_val(c_str_to_datum("|error|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|args|"));argl = cons(object_copy(val),empty);object_free(&val);val = c_str_to_datum("|(>) wrong number of arguments --|");argl = cons(object_copy(val), argl);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch902;}object_free(&val);
                    val = compiled_procedure_entry(proc);
                    goto *val.cont;primitive_branch902:;object_free(&val);val = proc.proc(argl); goto *cont.cont;false_branch842:;save(cont);save(env);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|c-real?|"));save(proc);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|c-car|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|args|"));argl = cons(object_copy(val),empty);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch898;}cont.cont = &&after_call897;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch898:;object_free(&val);val = proc.proc(argl); after_call897:;argl = cons(object_copy(val),empty);object_free(&proc);proc =restore();if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch900;}cont.cont = &&after_call899;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch900:;object_free(&val);val = proc.proc(argl); after_call899:;object_free(&env);env =restore();object_free(&cont);cont =restore();if(val.type==BOOLEAN && !val.boolean){
                        goto false_branch844;}object_free(&val);val = make_compiled_procedure(&&entry880);goto after_lambda879;entry880:env = compiled_procedure_env();
                          env = extend_environment(c_str_to_datum("(|x| . (|y| . ()))"));save(cont);save(env);save(env);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|c-exact?|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|x|"));argl = cons(object_copy(val),empty);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch896;}cont.cont = &&after_call895;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch896:;object_free(&val);val = proc.proc(argl); after_call895:;object_free(&env);env =restore();if(val.type==BOOLEAN && !val.boolean){
                        goto false_branch892;}object_free(&proc);proc = lookup_var_val(c_str_to_datum("|c-exact?|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|y|"));argl = cons(object_copy(val),empty);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch894;}cont.cont = &&after_if891;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch894:;object_free(&val);val = proc.proc(argl); goto after_if891;false_branch892:;object_free(&val);val = c_str_to_datum("#false");after_if891:;object_free(&env);env =restore();object_free(&cont);cont =restore();if(val.type==BOOLEAN && !val.boolean){
                        goto false_branch882;}object_free(&proc);proc = lookup_var_val(c_str_to_datum("|c-<|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|x|"));argl = cons(object_copy(val),empty);object_free(&val);val = lookup_var_val(c_str_to_datum("|y|"));argl = cons(object_copy(val), argl);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch890;}object_free(&val);
                    val = compiled_procedure_entry(proc);
                    goto *val.cont;primitive_branch890:;object_free(&val);val = proc.proc(argl); goto *cont.cont;false_branch882:;object_free(&proc);proc = lookup_var_val(c_str_to_datum("|c-<|"));save(cont);save(proc);save(env);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|c-inexact|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|x|"));argl = cons(object_copy(val),empty);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch884;}cont.cont = &&after_call883;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch884:;object_free(&val);val = proc.proc(argl); after_call883:;argl = cons(object_copy(val),empty);object_free(&env);env =restore();save(argl);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|c-inexact|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|y|"));argl = cons(object_copy(val),empty);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch886;}cont.cont = &&after_call885;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch886:;object_free(&val);val = proc.proc(argl); after_call885:;object_free(&argl);argl =restore();argl = cons(object_copy(val), argl);object_free(&proc);proc =restore();object_free(&cont);cont =restore();if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch888;}object_free(&val);
                    val = compiled_procedure_entry(proc);
                    goto *val.cont;primitive_branch888:;object_free(&val);val = proc.proc(argl); goto *cont.cont;after_lambda879:;{Object t = def_var_val(c_str_to_datum("|cmp|"));
                                   object_free(&val);val = t;}object_free(&val);val = make_compiled_procedure(&&entry854);goto after_lambda853;entry854:env = compiled_procedure_env();
                          env = extend_environment(c_str_to_datum("(|x| . (|xs| . ()))"));save(cont);save(env);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|c-null?|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|xs|"));argl = cons(object_copy(val),empty);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch878;}cont.cont = &&after_call877;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch878:;object_free(&val);val = proc.proc(argl); after_call877:;object_free(&env);env =restore();object_free(&cont);cont =restore();if(val.type==BOOLEAN && !val.boolean){
                        goto false_branch856;}object_free(&val);val = c_str_to_datum("#true");goto *cont.cont;false_branch856:;save(cont);save(env);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|c-real?|"));save(proc);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|c-car|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|xs|"));argl = cons(object_copy(val),empty);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch874;}cont.cont = &&after_call873;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch874:;object_free(&val);val = proc.proc(argl); after_call873:;argl = cons(object_copy(val),empty);object_free(&proc);proc =restore();if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch876;}cont.cont = &&after_call875;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch876:;object_free(&val);val = proc.proc(argl); after_call875:;object_free(&env);env =restore();object_free(&cont);cont =restore();if(val.type==BOOLEAN && !val.boolean){
                        goto false_branch858;}save(cont);save(env);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|cmp|"));save(proc);save(env);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|c-car|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|xs|"));argl = cons(object_copy(val),empty);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch870;}cont.cont = &&after_call869;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch870:;object_free(&val);val = proc.proc(argl); after_call869:;argl = cons(object_copy(val),empty);object_free(&env);env =restore();object_free(&val);val = lookup_var_val(c_str_to_datum("|x|"));argl = cons(object_copy(val), argl);object_free(&proc);proc =restore();if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch872;}cont.cont = &&after_call871;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch872:;object_free(&val);val = proc.proc(argl); after_call871:;object_free(&env);env =restore();object_free(&cont);cont =restore();if(val.type==BOOLEAN && !val.boolean){
                        goto false_branch862;}object_free(&proc);proc = lookup_var_val(c_str_to_datum("|iter|"));save(cont);save(proc);save(env);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|c-cdr|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|xs|"));argl = cons(object_copy(val),empty);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch864;}cont.cont = &&after_call863;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch864:;object_free(&val);val = proc.proc(argl); after_call863:;argl = cons(object_copy(val),empty);object_free(&env);env =restore();save(argl);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|c-car|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|xs|"));argl = cons(object_copy(val),empty);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch866;}cont.cont = &&after_call865;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch866:;object_free(&val);val = proc.proc(argl); after_call865:;object_free(&argl);argl =restore();argl = cons(object_copy(val), argl);object_free(&proc);proc =restore();object_free(&cont);cont =restore();if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch868;}object_free(&val);
                    val = compiled_procedure_entry(proc);
                    goto *val.cont;primitive_branch868:;object_free(&val);val = proc.proc(argl); goto *cont.cont;false_branch862:;object_free(&val);val = c_str_to_datum("#false");goto *cont.cont;false_branch858:;object_free(&proc);proc = lookup_var_val(c_str_to_datum("|error|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|args|"));argl = cons(object_copy(val),empty);object_free(&val);val = c_str_to_datum("|(>) wrong type of argument --|");argl = cons(object_copy(val), argl);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch860;}object_free(&val);
                    val = compiled_procedure_entry(proc);
                    goto *val.cont;primitive_branch860:;object_free(&val);val = proc.proc(argl); goto *cont.cont;after_lambda853:;{Object t = def_var_val(c_str_to_datum("|iter|"));
                                   object_free(&val);val = t;}object_free(&proc);proc = lookup_var_val(c_str_to_datum("|iter|"));save(cont);save(proc);save(env);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|c-cdr|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|args|"));argl = cons(object_copy(val),empty);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch848;}cont.cont = &&after_call847;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch848:;object_free(&val);val = proc.proc(argl); after_call847:;argl = cons(object_copy(val),empty);object_free(&env);env =restore();save(argl);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|c-car|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|args|"));argl = cons(object_copy(val),empty);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch850;}cont.cont = &&after_call849;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch850:;object_free(&val);val = proc.proc(argl); after_call849:;object_free(&argl);argl =restore();argl = cons(object_copy(val), argl);object_free(&proc);proc =restore();object_free(&cont);cont =restore();if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch852;}object_free(&val);
                    val = compiled_procedure_entry(proc);
                    goto *val.cont;primitive_branch852:;object_free(&val);val = proc.proc(argl); goto *cont.cont;false_branch844:;object_free(&proc);proc = lookup_var_val(c_str_to_datum("|error|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|args|"));argl = cons(object_copy(val),empty);object_free(&val);val = c_str_to_datum("|(>) wrong type of argument --|");argl = cons(object_copy(val), argl);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch846;}object_free(&val);
                    val = compiled_procedure_entry(proc);
                    goto *val.cont;primitive_branch846:;object_free(&val);val = proc.proc(argl); goto *cont.cont;after_lambda839:;{Object t = def_var_val(c_str_to_datum("|>|"));
                                   object_free(&val);val = t;}object_free(&val);val = make_compiled_procedure(&&entry740);goto after_lambda739;entry740:env = compiled_procedure_env();
                          env = extend_environment(c_str_to_datum("|args|"));save(cont);save(env);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|c-length|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|args|"));argl = cons(object_copy(val),empty);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch838;}cont.cont = &&after_call837;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch838:;object_free(&val);val = proc.proc(argl); after_call837:;object_free(&env);env =restore();{Object t = def_var_val(c_str_to_datum("|len|"));
                                   object_free(&val);val = t;}object_free(&cont);cont =restore();save(cont);save(env);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|c-<|"));object_free(&val);val = c_str_to_datum("2");argl = cons(object_copy(val),empty);object_free(&val);val = lookup_var_val(c_str_to_datum("|len|"));argl = cons(object_copy(val), argl);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch836;}cont.cont = &&after_call835;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch836:;object_free(&val);val = proc.proc(argl); after_call835:;object_free(&env);env =restore();object_free(&cont);cont =restore();if(val.type==BOOLEAN && !val.boolean){
                        goto false_branch742;}object_free(&proc);proc = lookup_var_val(c_str_to_datum("|error|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|args|"));argl = cons(object_copy(val),empty);object_free(&val);val = c_str_to_datum("|(>=) wrong number of arguments --|");argl = cons(object_copy(val), argl);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch834;}object_free(&val);
                    val = compiled_procedure_entry(proc);
                    goto *val.cont;primitive_branch834:;object_free(&val);val = proc.proc(argl); goto *cont.cont;false_branch742:;save(cont);save(env);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|c-real?|"));save(proc);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|c-car|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|args|"));argl = cons(object_copy(val),empty);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch830;}cont.cont = &&after_call829;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch830:;object_free(&val);val = proc.proc(argl); after_call829:;argl = cons(object_copy(val),empty);object_free(&proc);proc =restore();if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch832;}cont.cont = &&after_call831;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch832:;object_free(&val);val = proc.proc(argl); after_call831:;object_free(&env);env =restore();object_free(&cont);cont =restore();if(val.type==BOOLEAN && !val.boolean){
                        goto false_branch744;}object_free(&val);val = make_compiled_procedure(&&entry780);goto after_lambda779;entry780:env = compiled_procedure_env();
                          env = extend_environment(c_str_to_datum("(|x| . (|y| . ()))"));save(cont);save(env);save(env);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|c-exact?|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|x|"));argl = cons(object_copy(val),empty);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch828;}cont.cont = &&after_call827;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch828:;object_free(&val);val = proc.proc(argl); after_call827:;object_free(&env);env =restore();if(val.type==BOOLEAN && !val.boolean){
                        goto false_branch824;}object_free(&proc);proc = lookup_var_val(c_str_to_datum("|c-exact?|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|y|"));argl = cons(object_copy(val),empty);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch826;}cont.cont = &&after_if823;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch826:;object_free(&val);val = proc.proc(argl); goto after_if823;false_branch824:;object_free(&val);val = c_str_to_datum("#false");after_if823:;object_free(&env);env =restore();object_free(&cont);cont =restore();if(val.type==BOOLEAN && !val.boolean){
                        goto false_branch782;}save(cont);save(env);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|c-=|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|y|"));argl = cons(object_copy(val),empty);object_free(&val);val = lookup_var_val(c_str_to_datum("|x|"));argl = cons(object_copy(val), argl);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch822;}cont.cont = &&after_call821;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch822:;object_free(&val);val = proc.proc(argl); after_call821:;object_free(&env);env =restore();object_free(&cont);cont =restore();if(val.type==BOOLEAN && !val.boolean){
                        goto false_branch812;}object_free(&proc);proc = lookup_var_val(c_str_to_datum("|c-=|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|y|"));argl = cons(object_copy(val),empty);object_free(&val);val = lookup_var_val(c_str_to_datum("|x|"));argl = cons(object_copy(val), argl);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch820;}object_free(&val);
                    val = compiled_procedure_entry(proc);
                    goto *val.cont;primitive_branch820:;object_free(&val);val = proc.proc(argl); goto *cont.cont;false_branch812:;save(cont);save(env);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|c-<|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|x|"));argl = cons(object_copy(val),empty);object_free(&val);val = lookup_var_val(c_str_to_datum("|y|"));argl = cons(object_copy(val), argl);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch818;}cont.cont = &&after_call817;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch818:;object_free(&val);val = proc.proc(argl); after_call817:;object_free(&env);env =restore();object_free(&cont);cont =restore();if(val.type==BOOLEAN && !val.boolean){
                        goto false_branch814;}object_free(&proc);proc = lookup_var_val(c_str_to_datum("|c-<|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|x|"));argl = cons(object_copy(val),empty);object_free(&val);val = lookup_var_val(c_str_to_datum("|y|"));argl = cons(object_copy(val), argl);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch816;}object_free(&val);
                    val = compiled_procedure_entry(proc);
                    goto *val.cont;primitive_branch816:;object_free(&val);val = proc.proc(argl); goto *cont.cont;false_branch814:;object_free(&val);val = c_str_to_datum("#false");goto *cont.cont;false_branch782:;save(cont);save(env);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|c-=|"));save(proc);save(env);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|c-inexact|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|y|"));argl = cons(object_copy(val),empty);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch806;}cont.cont = &&after_call805;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch806:;object_free(&val);val = proc.proc(argl); after_call805:;argl = cons(object_copy(val),empty);object_free(&env);env =restore();save(argl);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|c-inexact|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|x|"));argl = cons(object_copy(val),empty);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch808;}cont.cont = &&after_call807;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch808:;object_free(&val);val = proc.proc(argl); after_call807:;object_free(&argl);argl =restore();argl = cons(object_copy(val), argl);object_free(&proc);proc =restore();if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch810;}cont.cont = &&after_call809;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch810:;object_free(&val);val = proc.proc(argl); after_call809:;object_free(&env);env =restore();object_free(&cont);cont =restore();if(val.type==BOOLEAN && !val.boolean){
                        goto false_branch784;}object_free(&proc);proc = lookup_var_val(c_str_to_datum("|c-=|"));save(cont);save(proc);save(env);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|c-inexact|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|y|"));argl = cons(object_copy(val),empty);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch800;}cont.cont = &&after_call799;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch800:;object_free(&val);val = proc.proc(argl); after_call799:;argl = cons(object_copy(val),empty);object_free(&env);env =restore();save(argl);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|c-inexact|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|x|"));argl = cons(object_copy(val),empty);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch802;}cont.cont = &&after_call801;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch802:;object_free(&val);val = proc.proc(argl); after_call801:;object_free(&argl);argl =restore();argl = cons(object_copy(val), argl);object_free(&proc);proc =restore();object_free(&cont);cont =restore();if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch804;}object_free(&val);
                    val = compiled_procedure_entry(proc);
                    goto *val.cont;primitive_branch804:;object_free(&val);val = proc.proc(argl); goto *cont.cont;false_branch784:;save(cont);save(env);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|c-<|"));save(proc);save(env);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|c-inexact|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|x|"));argl = cons(object_copy(val),empty);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch794;}cont.cont = &&after_call793;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch794:;object_free(&val);val = proc.proc(argl); after_call793:;argl = cons(object_copy(val),empty);object_free(&env);env =restore();save(argl);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|c-inexact|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|y|"));argl = cons(object_copy(val),empty);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch796;}cont.cont = &&after_call795;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch796:;object_free(&val);val = proc.proc(argl); after_call795:;object_free(&argl);argl =restore();argl = cons(object_copy(val), argl);object_free(&proc);proc =restore();if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch798;}cont.cont = &&after_call797;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch798:;object_free(&val);val = proc.proc(argl); after_call797:;object_free(&env);env =restore();object_free(&cont);cont =restore();if(val.type==BOOLEAN && !val.boolean){
                        goto false_branch786;}object_free(&proc);proc = lookup_var_val(c_str_to_datum("|c-<|"));save(cont);save(proc);save(env);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|c-inexact|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|x|"));argl = cons(object_copy(val),empty);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch788;}cont.cont = &&after_call787;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch788:;object_free(&val);val = proc.proc(argl); after_call787:;argl = cons(object_copy(val),empty);object_free(&env);env =restore();save(argl);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|c-inexact|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|y|"));argl = cons(object_copy(val),empty);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch790;}cont.cont = &&after_call789;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch790:;object_free(&val);val = proc.proc(argl); after_call789:;object_free(&argl);argl =restore();argl = cons(object_copy(val), argl);object_free(&proc);proc =restore();object_free(&cont);cont =restore();if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch792;}object_free(&val);
                    val = compiled_procedure_entry(proc);
                    goto *val.cont;primitive_branch792:;object_free(&val);val = proc.proc(argl); goto *cont.cont;false_branch786:;object_free(&val);val = c_str_to_datum("#false");goto *cont.cont;after_lambda779:;{Object t = def_var_val(c_str_to_datum("|cmp|"));
                                   object_free(&val);val = t;}object_free(&val);val = make_compiled_procedure(&&entry754);goto after_lambda753;entry754:env = compiled_procedure_env();
                          env = extend_environment(c_str_to_datum("(|x| . (|xs| . ()))"));save(cont);save(env);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|c-null?|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|xs|"));argl = cons(object_copy(val),empty);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch778;}cont.cont = &&after_call777;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch778:;object_free(&val);val = proc.proc(argl); after_call777:;object_free(&env);env =restore();object_free(&cont);cont =restore();if(val.type==BOOLEAN && !val.boolean){
                        goto false_branch756;}object_free(&val);val = c_str_to_datum("#true");goto *cont.cont;false_branch756:;save(cont);save(env);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|c-real?|"));save(proc);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|c-car|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|xs|"));argl = cons(object_copy(val),empty);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch774;}cont.cont = &&after_call773;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch774:;object_free(&val);val = proc.proc(argl); after_call773:;argl = cons(object_copy(val),empty);object_free(&proc);proc =restore();if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch776;}cont.cont = &&after_call775;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch776:;object_free(&val);val = proc.proc(argl); after_call775:;object_free(&env);env =restore();object_free(&cont);cont =restore();if(val.type==BOOLEAN && !val.boolean){
                        goto false_branch758;}save(cont);save(env);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|cmp|"));save(proc);save(env);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|c-car|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|xs|"));argl = cons(object_copy(val),empty);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch770;}cont.cont = &&after_call769;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch770:;object_free(&val);val = proc.proc(argl); after_call769:;argl = cons(object_copy(val),empty);object_free(&env);env =restore();object_free(&val);val = lookup_var_val(c_str_to_datum("|x|"));argl = cons(object_copy(val), argl);object_free(&proc);proc =restore();if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch772;}cont.cont = &&after_call771;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch772:;object_free(&val);val = proc.proc(argl); after_call771:;object_free(&env);env =restore();object_free(&cont);cont =restore();if(val.type==BOOLEAN && !val.boolean){
                        goto false_branch762;}object_free(&proc);proc = lookup_var_val(c_str_to_datum("|iter|"));save(cont);save(proc);save(env);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|c-cdr|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|xs|"));argl = cons(object_copy(val),empty);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch764;}cont.cont = &&after_call763;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch764:;object_free(&val);val = proc.proc(argl); after_call763:;argl = cons(object_copy(val),empty);object_free(&env);env =restore();save(argl);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|c-car|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|xs|"));argl = cons(object_copy(val),empty);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch766;}cont.cont = &&after_call765;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch766:;object_free(&val);val = proc.proc(argl); after_call765:;object_free(&argl);argl =restore();argl = cons(object_copy(val), argl);object_free(&proc);proc =restore();object_free(&cont);cont =restore();if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch768;}object_free(&val);
                    val = compiled_procedure_entry(proc);
                    goto *val.cont;primitive_branch768:;object_free(&val);val = proc.proc(argl); goto *cont.cont;false_branch762:;object_free(&val);val = c_str_to_datum("#false");goto *cont.cont;false_branch758:;object_free(&proc);proc = lookup_var_val(c_str_to_datum("|error|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|args|"));argl = cons(object_copy(val),empty);object_free(&val);val = c_str_to_datum("|(>=) wrong type of argument --|");argl = cons(object_copy(val), argl);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch760;}object_free(&val);
                    val = compiled_procedure_entry(proc);
                    goto *val.cont;primitive_branch760:;object_free(&val);val = proc.proc(argl); goto *cont.cont;after_lambda753:;{Object t = def_var_val(c_str_to_datum("|iter|"));
                                   object_free(&val);val = t;}object_free(&proc);proc = lookup_var_val(c_str_to_datum("|iter|"));save(cont);save(proc);save(env);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|c-cdr|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|args|"));argl = cons(object_copy(val),empty);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch748;}cont.cont = &&after_call747;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch748:;object_free(&val);val = proc.proc(argl); after_call747:;argl = cons(object_copy(val),empty);object_free(&env);env =restore();save(argl);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|c-car|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|args|"));argl = cons(object_copy(val),empty);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch750;}cont.cont = &&after_call749;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch750:;object_free(&val);val = proc.proc(argl); after_call749:;object_free(&argl);argl =restore();argl = cons(object_copy(val), argl);object_free(&proc);proc =restore();object_free(&cont);cont =restore();if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch752;}object_free(&val);
                    val = compiled_procedure_entry(proc);
                    goto *val.cont;primitive_branch752:;object_free(&val);val = proc.proc(argl); goto *cont.cont;false_branch744:;object_free(&proc);proc = lookup_var_val(c_str_to_datum("|error|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|args|"));argl = cons(object_copy(val),empty);object_free(&val);val = c_str_to_datum("|(>=) wrong type of argument --|");argl = cons(object_copy(val), argl);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch746;}object_free(&val);
                    val = compiled_procedure_entry(proc);
                    goto *val.cont;primitive_branch746:;object_free(&val);val = proc.proc(argl); goto *cont.cont;after_lambda739:;{Object t = def_var_val(c_str_to_datum("|>=|"));
                                   object_free(&val);val = t;}object_free(&val);val = make_compiled_procedure(&&entry710);goto after_lambda709;entry710:env = compiled_procedure_env();
                          env = extend_environment(c_str_to_datum("|args|"));save(cont);save(env);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|c-=|"));save(proc);object_free(&val);val = c_str_to_datum("1");argl = cons(object_copy(val),empty);save(argl);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|c-length|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|args|"));argl = cons(object_copy(val),empty);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch736;}cont.cont = &&after_call735;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch736:;object_free(&val);val = proc.proc(argl); after_call735:;object_free(&argl);argl =restore();argl = cons(object_copy(val), argl);object_free(&proc);proc =restore();if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch738;}cont.cont = &&after_call737;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch738:;object_free(&val);val = proc.proc(argl); after_call737:;object_free(&env);env =restore();object_free(&cont);cont =restore();if(val.type==BOOLEAN && !val.boolean){
                        goto false_branch712;}save(cont);save(env);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|c-real?|"));save(proc);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|c-car|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|args|"));argl = cons(object_copy(val),empty);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch732;}cont.cont = &&after_call731;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch732:;object_free(&val);val = proc.proc(argl); after_call731:;argl = cons(object_copy(val),empty);object_free(&proc);proc =restore();if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch734;}cont.cont = &&after_call733;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch734:;object_free(&val);val = proc.proc(argl); after_call733:;object_free(&env);env =restore();object_free(&cont);cont =restore();if(val.type==BOOLEAN && !val.boolean){
                        goto false_branch716;}save(cont);save(env);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|c-<|"));save(proc);object_free(&val);val = c_str_to_datum("0");argl = cons(object_copy(val),empty);save(argl);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|c-car|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|args|"));argl = cons(object_copy(val),empty);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch728;}cont.cont = &&after_call727;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch728:;object_free(&val);val = proc.proc(argl); after_call727:;object_free(&argl);argl =restore();argl = cons(object_copy(val), argl);object_free(&proc);proc =restore();if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch730;}cont.cont = &&after_call729;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch730:;object_free(&val);val = proc.proc(argl); after_call729:;object_free(&env);env =restore();object_free(&cont);cont =restore();if(val.type==BOOLEAN && !val.boolean){
                        goto false_branch720;}object_free(&proc);proc = lookup_var_val(c_str_to_datum("|c-*|"));save(cont);save(proc);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|c-car|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|args|"));argl = cons(object_copy(val),empty);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch724;}cont.cont = &&after_call723;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch724:;object_free(&val);val = proc.proc(argl); after_call723:;argl = cons(object_copy(val),empty);object_free(&val);val = c_str_to_datum("-1");argl = cons(object_copy(val), argl);object_free(&proc);proc =restore();object_free(&cont);cont =restore();if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch726;}object_free(&val);
                    val = compiled_procedure_entry(proc);
                    goto *val.cont;primitive_branch726:;object_free(&val);val = proc.proc(argl); goto *cont.cont;false_branch720:;object_free(&proc);proc = lookup_var_val(c_str_to_datum("|c-car|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|args|"));argl = cons(object_copy(val),empty);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch722;}object_free(&val);
                    val = compiled_procedure_entry(proc);
                    goto *val.cont;primitive_branch722:;object_free(&val);val = proc.proc(argl); goto *cont.cont;false_branch716:;object_free(&proc);proc = lookup_var_val(c_str_to_datum("|error|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|args|"));argl = cons(object_copy(val),empty);object_free(&val);val = c_str_to_datum("|(abs) wrong type of argument --|");argl = cons(object_copy(val), argl);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch718;}object_free(&val);
                    val = compiled_procedure_entry(proc);
                    goto *val.cont;primitive_branch718:;object_free(&val);val = proc.proc(argl); goto *cont.cont;false_branch712:;object_free(&proc);proc = lookup_var_val(c_str_to_datum("|error|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|args|"));argl = cons(object_copy(val),empty);object_free(&val);val = c_str_to_datum("|(abs) wrong number of arguments --|");argl = cons(object_copy(val), argl);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch714;}object_free(&val);
                    val = compiled_procedure_entry(proc);
                    goto *val.cont;primitive_branch714:;object_free(&val);val = proc.proc(argl); goto *cont.cont;after_lambda709:;{Object t = def_var_val(c_str_to_datum("|abs|"));
                                   object_free(&val);val = t;}object_free(&val);val = make_compiled_procedure(&&entry644);goto after_lambda643;entry644:env = compiled_procedure_env();
                          env = extend_environment(c_str_to_datum("|list-of-list|"));save(cont);save(env);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|c-null?|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|list-of-list|"));argl = cons(object_copy(val),empty);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch708;}cont.cont = &&after_call707;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch708:;object_free(&val);val = proc.proc(argl); after_call707:;object_free(&env);env =restore();object_free(&cont);cont =restore();if(val.type==BOOLEAN && !val.boolean){
                        goto false_branch646;}object_free(&val);val = c_str_to_datum("()");goto *cont.cont;false_branch646:;save(cont);save(env);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|c-reverse|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|list-of-list|"));argl = cons(object_copy(val),empty);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch706;}cont.cont = &&after_call705;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch706:;object_free(&val);val = proc.proc(argl); after_call705:;object_free(&env);env =restore();{Object t = def_var_val(c_str_to_datum("|reversed|"));
                                   object_free(&val);val = t;}object_free(&cont);cont =restore();save(cont);save(env);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|c-car|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|reversed|"));argl = cons(object_copy(val),empty);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch704;}cont.cont = &&after_call703;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch704:;object_free(&val);val = proc.proc(argl); after_call703:;object_free(&env);env =restore();{Object t = def_var_val(c_str_to_datum("|o|"));
                                   object_free(&val);val = t;}object_free(&cont);cont =restore();save(cont);save(env);save(env);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|c-null?|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|o|"));argl = cons(object_copy(val),empty);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch702;}cont.cont = &&after_call701;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch702:;object_free(&val);val = proc.proc(argl); after_call701:;object_free(&env);env =restore();if(val.type==BOOLEAN && !val.boolean){
                        goto false_branch692;}object_free(&proc);proc = lookup_var_val(c_str_to_datum("|c-null?|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|o|"));argl = cons(object_copy(val),empty);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch700;}cont.cont = &&after_if691;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch700:;object_free(&val);val = proc.proc(argl); goto after_if691;false_branch692:;save(env);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|c-pair?|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|o|"));argl = cons(object_copy(val),empty);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch698;}cont.cont = &&after_call697;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch698:;object_free(&val);val = proc.proc(argl); after_call697:;object_free(&env);env =restore();if(val.type==BOOLEAN && !val.boolean){
                        goto false_branch694;}object_free(&proc);proc = lookup_var_val(c_str_to_datum("|c-pair?|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|o|"));argl = cons(object_copy(val),empty);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch696;}cont.cont = &&after_if693;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch696:;object_free(&val);val = proc.proc(argl); goto after_if693;false_branch694:;object_free(&val);val = c_str_to_datum("#false");after_if693:;after_if691:;object_free(&env);env =restore();object_free(&cont);cont =restore();if(val.type==BOOLEAN && !val.boolean){
                        goto false_branch648;}object_free(&val);val = make_compiled_procedure(&&entry678);goto after_lambda677;entry678:env = compiled_procedure_env();
                          env = extend_environment(c_str_to_datum("(|list| . (|result| . ()))"));save(cont);save(env);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|c-null?|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|list|"));argl = cons(object_copy(val),empty);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch690;}cont.cont = &&after_call689;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch690:;object_free(&val);val = proc.proc(argl); after_call689:;object_free(&env);env =restore();object_free(&cont);cont =restore();if(val.type==BOOLEAN && !val.boolean){
                        goto false_branch680;}object_free(&val);val = lookup_var_val(c_str_to_datum("|result|"));goto *cont.cont;false_branch680:;object_free(&proc);proc = lookup_var_val(c_str_to_datum("|iter-1|"));save(cont);save(proc);save(env);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|c-cons|"));save(proc);object_free(&val);val = lookup_var_val(c_str_to_datum("|result|"));argl = cons(object_copy(val),empty);save(argl);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|c-car|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|list|"));argl = cons(object_copy(val),empty);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch682;}cont.cont = &&after_call681;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch682:;object_free(&val);val = proc.proc(argl); after_call681:;object_free(&argl);argl =restore();argl = cons(object_copy(val), argl);object_free(&proc);proc =restore();if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch684;}cont.cont = &&after_call683;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch684:;object_free(&val);val = proc.proc(argl); after_call683:;argl = cons(object_copy(val),empty);object_free(&env);env =restore();save(argl);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|c-cdr|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|list|"));argl = cons(object_copy(val),empty);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch686;}cont.cont = &&after_call685;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch686:;object_free(&val);val = proc.proc(argl); after_call685:;object_free(&argl);argl =restore();argl = cons(object_copy(val), argl);object_free(&proc);proc =restore();object_free(&cont);cont =restore();if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch688;}object_free(&val);
                    val = compiled_procedure_entry(proc);
                    goto *val.cont;primitive_branch688:;object_free(&val);val = proc.proc(argl); goto *cont.cont;after_lambda677:;{Object t = def_var_val(c_str_to_datum("|iter-1|"));
                                   object_free(&val);val = t;}object_free(&val);val = make_compiled_procedure(&&entry654);goto after_lambda653;entry654:env = compiled_procedure_env();
                          env = extend_environment(c_str_to_datum("(|list-of-list| . (|result| . ()))"));save(cont);save(env);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|c-null?|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|list-of-list|"));argl = cons(object_copy(val),empty);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch676;}cont.cont = &&after_call675;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch676:;object_free(&val);val = proc.proc(argl); after_call675:;object_free(&env);env =restore();object_free(&cont);cont =restore();if(val.type==BOOLEAN && !val.boolean){
                        goto false_branch656;}object_free(&val);val = lookup_var_val(c_str_to_datum("|result|"));goto *cont.cont;false_branch656:;save(cont);save(env);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|c-list?|"));save(proc);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|c-car|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|list-of-list|"));argl = cons(object_copy(val),empty);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch672;}cont.cont = &&after_call671;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch672:;object_free(&val);val = proc.proc(argl); after_call671:;argl = cons(object_copy(val),empty);object_free(&proc);proc =restore();if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch674;}cont.cont = &&after_call673;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch674:;object_free(&val);val = proc.proc(argl); after_call673:;object_free(&env);env =restore();object_free(&cont);cont =restore();if(val.type==BOOLEAN && !val.boolean){
                        goto false_branch658;}object_free(&proc);proc = lookup_var_val(c_str_to_datum("|iter-2|"));save(cont);save(proc);save(env);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|iter-1|"));save(proc);object_free(&val);val = lookup_var_val(c_str_to_datum("|result|"));argl = cons(object_copy(val),empty);save(argl);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|c-reverse|"));save(proc);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|c-car|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|list-of-list|"));argl = cons(object_copy(val),empty);if (proc.type == PROC_APPLY) {
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
                 goto *val.cont;primitive_branch664:;object_free(&val);val = proc.proc(argl); after_call663:;object_free(&argl);argl =restore();argl = cons(object_copy(val), argl);object_free(&proc);proc =restore();if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch666;}cont.cont = &&after_call665;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch666:;object_free(&val);val = proc.proc(argl); after_call665:;argl = cons(object_copy(val),empty);object_free(&env);env =restore();save(argl);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|c-cdr|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|list-of-list|"));argl = cons(object_copy(val),empty);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch668;}cont.cont = &&after_call667;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch668:;object_free(&val);val = proc.proc(argl); after_call667:;object_free(&argl);argl =restore();argl = cons(object_copy(val), argl);object_free(&proc);proc =restore();object_free(&cont);cont =restore();if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch670;}object_free(&val);
                    val = compiled_procedure_entry(proc);
                    goto *val.cont;primitive_branch670:;object_free(&val);val = proc.proc(argl); goto *cont.cont;false_branch658:;object_free(&proc);proc = lookup_var_val(c_str_to_datum("|error|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|args|"));argl = cons(object_copy(val),empty);object_free(&val);val = c_str_to_datum("|(append) wrong type of argument --|");argl = cons(object_copy(val), argl);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch660;}object_free(&val);
                    val = compiled_procedure_entry(proc);
                    goto *val.cont;primitive_branch660:;object_free(&val);val = proc.proc(argl); goto *cont.cont;after_lambda653:;{Object t = def_var_val(c_str_to_datum("|iter-2|"));
                                   object_free(&val);val = t;}object_free(&proc);proc = lookup_var_val(c_str_to_datum("|iter-2|"));save(cont);save(proc);object_free(&val);val = lookup_var_val(c_str_to_datum("|o|"));argl = cons(object_copy(val),empty);save(argl);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|c-cdr|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|reversed|"));argl = cons(object_copy(val),empty);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch650;}cont.cont = &&after_call649;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch650:;object_free(&val);val = proc.proc(argl); after_call649:;object_free(&argl);argl =restore();argl = cons(object_copy(val), argl);object_free(&proc);proc =restore();object_free(&cont);cont =restore();if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch652;}object_free(&val);
                    val = compiled_procedure_entry(proc);
                    goto *val.cont;primitive_branch652:;object_free(&val);val = proc.proc(argl); goto *cont.cont;false_branch648:;object_free(&val);val = lookup_var_val(c_str_to_datum("|o|"));goto *cont.cont;after_lambda643:;{Object t = def_var_val(c_str_to_datum("|append|"));
                                   object_free(&val);val = t;}object_free(&val);val = make_compiled_procedure(&&entry630);goto after_lambda629;entry630:env = compiled_procedure_env();
                          env = extend_environment(c_str_to_datum("|args|"));save(cont);save(env);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|c-=|"));save(proc);object_free(&val);val = c_str_to_datum("1");argl = cons(object_copy(val),empty);save(argl);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|c-length|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|args|"));argl = cons(object_copy(val),empty);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch640;}cont.cont = &&after_call639;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch640:;object_free(&val);val = proc.proc(argl); after_call639:;object_free(&argl);argl =restore();argl = cons(object_copy(val), argl);object_free(&proc);proc =restore();if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch642;}cont.cont = &&after_call641;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch642:;object_free(&val);val = proc.proc(argl); after_call641:;object_free(&env);env =restore();object_free(&cont);cont =restore();if(val.type==BOOLEAN && !val.boolean){
                        goto false_branch632;}object_free(&proc);proc = lookup_var_val(c_str_to_datum("|c-binary-port?|"));save(cont);save(proc);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|c-car|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|args|"));argl = cons(object_copy(val),empty);if (proc.type == PROC_APPLY) {
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
                   if (proc.type == PROC) { goto primitive_branch638;}object_free(&val);
                    val = compiled_procedure_entry(proc);
                    goto *val.cont;primitive_branch638:;object_free(&val);val = proc.proc(argl); goto *cont.cont;false_branch632:;object_free(&proc);proc = lookup_var_val(c_str_to_datum("|error|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|args|"));argl = cons(object_copy(val),empty);object_free(&val);val = c_str_to_datum("|(binary-port?) wrong number of arguments --|");argl = cons(object_copy(val), argl);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch634;}object_free(&val);
                    val = compiled_procedure_entry(proc);
                    goto *val.cont;primitive_branch634:;object_free(&val);val = proc.proc(argl); goto *cont.cont;after_lambda629:;{Object t = def_var_val(c_str_to_datum("|binary-port?|"));
                                   object_free(&val);val = t;}object_free(&val);val = make_compiled_procedure(&&entry584);goto after_lambda583;entry584:env = compiled_procedure_env();
                          env = extend_environment(c_str_to_datum("|args|"));save(cont);save(env);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|c-<|"));save(proc);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|c-length|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|args|"));argl = cons(object_copy(val),empty);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch626;}cont.cont = &&after_call625;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch626:;object_free(&val);val = proc.proc(argl); after_call625:;argl = cons(object_copy(val),empty);object_free(&val);val = c_str_to_datum("1");argl = cons(object_copy(val), argl);object_free(&proc);proc =restore();if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch628;}cont.cont = &&after_call627;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch628:;object_free(&val);val = proc.proc(argl); after_call627:;object_free(&env);env =restore();object_free(&cont);cont =restore();if(val.type==BOOLEAN && !val.boolean){
                        goto false_branch586;}save(cont);save(env);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|c-car|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|args|"));argl = cons(object_copy(val),empty);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch624;}cont.cont = &&after_call623;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch624:;object_free(&val);val = proc.proc(argl); after_call623:;object_free(&env);env =restore();{Object t = def_var_val(c_str_to_datum("|boolean|"));
                                   object_free(&val);val = t;}object_free(&cont);cont =restore();save(cont);save(env);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|c-boolean?|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|boolean|"));argl = cons(object_copy(val),empty);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch622;}cont.cont = &&after_call621;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch622:;object_free(&val);val = proc.proc(argl); after_call621:;object_free(&env);env =restore();object_free(&cont);cont =restore();if(val.type==BOOLEAN && !val.boolean){
                        goto false_branch590;}object_free(&val);val = make_compiled_procedure(&&entry598);goto after_lambda597;entry598:env = compiled_procedure_env();
                          env = extend_environment(c_str_to_datum("(|booleans| . ())"));save(cont);save(env);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|c-null?|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|booleans|"));argl = cons(object_copy(val),empty);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch620;}cont.cont = &&after_call619;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch620:;object_free(&val);val = proc.proc(argl); after_call619:;object_free(&env);env =restore();object_free(&cont);cont =restore();if(val.type==BOOLEAN && !val.boolean){
                        goto false_branch600;}object_free(&val);val = c_str_to_datum("#true");goto *cont.cont;false_branch600:;save(cont);save(env);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|c-boolean?|"));save(proc);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|c-car|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|booleans|"));argl = cons(object_copy(val),empty);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch616;}cont.cont = &&after_call615;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch616:;object_free(&val);val = proc.proc(argl); after_call615:;argl = cons(object_copy(val),empty);object_free(&proc);proc =restore();if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch618;}cont.cont = &&after_call617;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch618:;object_free(&val);val = proc.proc(argl); after_call617:;object_free(&env);env =restore();object_free(&cont);cont =restore();if(val.type==BOOLEAN && !val.boolean){
                        goto false_branch602;}save(cont);save(env);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|c-eq?|"));save(proc);object_free(&val);val = lookup_var_val(c_str_to_datum("|boolean|"));argl = cons(object_copy(val),empty);save(argl);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|c-car|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|booleans|"));argl = cons(object_copy(val),empty);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch612;}cont.cont = &&after_call611;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch612:;object_free(&val);val = proc.proc(argl); after_call611:;object_free(&argl);argl =restore();argl = cons(object_copy(val), argl);object_free(&proc);proc =restore();if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch614;}cont.cont = &&after_call613;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch614:;object_free(&val);val = proc.proc(argl); after_call613:;object_free(&env);env =restore();object_free(&cont);cont =restore();if(val.type==BOOLEAN && !val.boolean){
                        goto false_branch606;}object_free(&proc);proc = lookup_var_val(c_str_to_datum("|iter|"));save(cont);save(proc);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|c-cdr|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|booleans|"));argl = cons(object_copy(val),empty);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch608;}cont.cont = &&after_call607;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch608:;object_free(&val);val = proc.proc(argl); after_call607:;argl = cons(object_copy(val),empty);object_free(&proc);proc =restore();object_free(&cont);cont =restore();if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch610;}object_free(&val);
                    val = compiled_procedure_entry(proc);
                    goto *val.cont;primitive_branch610:;object_free(&val);val = proc.proc(argl); goto *cont.cont;false_branch606:;object_free(&val);val = c_str_to_datum("#false");goto *cont.cont;false_branch602:;object_free(&proc);proc = lookup_var_val(c_str_to_datum("|error|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|args|"));argl = cons(object_copy(val),empty);object_free(&val);val = c_str_to_datum("|(boolean=?) wrong type of argument --|");argl = cons(object_copy(val), argl);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch604;}object_free(&val);
                    val = compiled_procedure_entry(proc);
                    goto *val.cont;primitive_branch604:;object_free(&val);val = proc.proc(argl); goto *cont.cont;after_lambda597:;{Object t = def_var_val(c_str_to_datum("|iter|"));
                                   object_free(&val);val = t;}object_free(&proc);proc = lookup_var_val(c_str_to_datum("|iter|"));save(cont);save(proc);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|c-cdr|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|args|"));argl = cons(object_copy(val),empty);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch594;}cont.cont = &&after_call593;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch594:;object_free(&val);val = proc.proc(argl); after_call593:;argl = cons(object_copy(val),empty);object_free(&proc);proc =restore();object_free(&cont);cont =restore();if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch596;}object_free(&val);
                    val = compiled_procedure_entry(proc);
                    goto *val.cont;primitive_branch596:;object_free(&val);val = proc.proc(argl); goto *cont.cont;false_branch590:;object_free(&proc);proc = lookup_var_val(c_str_to_datum("|error|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|args|"));argl = cons(object_copy(val),empty);object_free(&val);val = c_str_to_datum("|(boolean=?) wrong type of argument --|");argl = cons(object_copy(val), argl);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch592;}object_free(&val);
                    val = compiled_procedure_entry(proc);
                    goto *val.cont;primitive_branch592:;object_free(&val);val = proc.proc(argl); goto *cont.cont;false_branch586:;object_free(&proc);proc = lookup_var_val(c_str_to_datum("|error|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|args|"));argl = cons(object_copy(val),empty);object_free(&val);val = c_str_to_datum("|(boolean=?) wrong number of arguments --|");argl = cons(object_copy(val), argl);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch588;}object_free(&val);
                    val = compiled_procedure_entry(proc);
                    goto *val.cont;primitive_branch588:;object_free(&val);val = proc.proc(argl); goto *cont.cont;after_lambda583:;{Object t = def_var_val(c_str_to_datum("|boolean=?|"));
                                   object_free(&val);val = t;}object_free(&val);val = make_compiled_procedure(&&entry570);goto after_lambda569;entry570:env = compiled_procedure_env();
                          env = extend_environment(c_str_to_datum("|args|"));save(cont);save(env);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|c-=|"));save(proc);object_free(&val);val = c_str_to_datum("1");argl = cons(object_copy(val),empty);save(argl);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|c-length|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|args|"));argl = cons(object_copy(val),empty);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch580;}cont.cont = &&after_call579;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch580:;object_free(&val);val = proc.proc(argl); after_call579:;object_free(&argl);argl =restore();argl = cons(object_copy(val), argl);object_free(&proc);proc =restore();if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch582;}cont.cont = &&after_call581;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch582:;object_free(&val);val = proc.proc(argl); after_call581:;object_free(&env);env =restore();object_free(&cont);cont =restore();if(val.type==BOOLEAN && !val.boolean){
                        goto false_branch572;}object_free(&proc);proc = lookup_var_val(c_str_to_datum("|c-boolean?|"));save(cont);save(proc);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|c-car|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|args|"));argl = cons(object_copy(val),empty);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch576;}cont.cont = &&after_call575;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch576:;object_free(&val);val = proc.proc(argl); after_call575:;argl = cons(object_copy(val),empty);object_free(&proc);proc =restore();object_free(&cont);cont =restore();if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch578;}object_free(&val);
                    val = compiled_procedure_entry(proc);
                    goto *val.cont;primitive_branch578:;object_free(&val);val = proc.proc(argl); goto *cont.cont;false_branch572:;object_free(&proc);proc = lookup_var_val(c_str_to_datum("|error|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|args|"));argl = cons(object_copy(val),empty);object_free(&val);val = c_str_to_datum("|(boolean?) wrong number of arguments --|");argl = cons(object_copy(val), argl);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch574;}object_free(&val);
                    val = compiled_procedure_entry(proc);
                    goto *val.cont;primitive_branch574:;object_free(&val);val = proc.proc(argl); goto *cont.cont;after_lambda569:;{Object t = def_var_val(c_str_to_datum("|boolean?|"));
                                   object_free(&val);val = t;}object_free(&val);val = make_compiled_procedure(&&entry528);goto after_lambda527;entry528:env = compiled_procedure_env();
                          env = extend_environment(c_str_to_datum("|args|"));object_free(&val);val = make_compiled_procedure(&&entry554);goto after_lambda553;entry554:env = compiled_procedure_env();
                          env = extend_environment(c_str_to_datum("(|o| . ())"));save(cont);save(env);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|c-integer?|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|o|"));argl = cons(object_copy(val),empty);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch568;}cont.cont = &&after_call567;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch568:;object_free(&val);val = proc.proc(argl); after_call567:;object_free(&env);env =restore();object_free(&cont);cont =restore();if(val.type==BOOLEAN && !val.boolean){
                        goto false_branch556;}save(cont);save(env);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|c-exact?|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|o|"));argl = cons(object_copy(val),empty);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch566;}cont.cont = &&after_call565;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch566:;object_free(&val);val = proc.proc(argl); after_call565:;object_free(&env);env =restore();object_free(&cont);cont =restore();if(val.type==BOOLEAN && !val.boolean){
                        goto false_branch558;}save(cont);save(env);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|c-<|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|o|"));argl = cons(object_copy(val),empty);object_free(&val);val = c_str_to_datum("-1");argl = cons(object_copy(val), argl);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch564;}cont.cont = &&after_call563;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch564:;object_free(&val);val = proc.proc(argl); after_call563:;object_free(&env);env =restore();object_free(&cont);cont =restore();if(val.type==BOOLEAN && !val.boolean){
                        goto false_branch560;}object_free(&proc);proc = lookup_var_val(c_str_to_datum("|c-<|"));object_free(&val);val = c_str_to_datum("256");argl = cons(object_copy(val),empty);object_free(&val);val = lookup_var_val(c_str_to_datum("|o|"));argl = cons(object_copy(val), argl);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch562;}object_free(&val);
                    val = compiled_procedure_entry(proc);
                    goto *val.cont;primitive_branch562:;object_free(&val);val = proc.proc(argl); goto *cont.cont;false_branch560:;object_free(&val);val = c_str_to_datum("#false");goto *cont.cont;false_branch558:;object_free(&val);val = c_str_to_datum("#false");goto *cont.cont;false_branch556:;object_free(&val);val = c_str_to_datum("#false");goto *cont.cont;after_lambda553:;{Object t = def_var_val(c_str_to_datum("|byte?|"));
                                   object_free(&val);val = t;}object_free(&val);val = make_compiled_procedure(&&entry538);goto after_lambda537;entry538:env = compiled_procedure_env();
                          env = extend_environment(c_str_to_datum("(|bytes| . ())"));save(cont);save(env);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|c-null?|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|bytes|"));argl = cons(object_copy(val),empty);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch552;}cont.cont = &&after_call551;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch552:;object_free(&val);val = proc.proc(argl); after_call551:;object_free(&env);env =restore();object_free(&cont);cont =restore();if(val.type==BOOLEAN && !val.boolean){
                        goto false_branch540;}object_free(&val);val = c_str_to_datum("#true");goto *cont.cont;false_branch540:;save(cont);save(env);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|byte?|"));save(proc);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|c-car|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|bytes|"));argl = cons(object_copy(val),empty);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch548;}cont.cont = &&after_call547;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch548:;object_free(&val);val = proc.proc(argl); after_call547:;argl = cons(object_copy(val),empty);object_free(&proc);proc =restore();if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch550;}cont.cont = &&after_call549;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch550:;object_free(&val);val = proc.proc(argl); after_call549:;object_free(&env);env =restore();object_free(&cont);cont =restore();if(val.type==BOOLEAN && !val.boolean){
                        goto false_branch542;}object_free(&proc);proc = lookup_var_val(c_str_to_datum("|bytes?|"));save(cont);save(proc);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|c-cdr|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|bytes|"));argl = cons(object_copy(val),empty);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch544;}cont.cont = &&after_call543;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch544:;object_free(&val);val = proc.proc(argl); after_call543:;argl = cons(object_copy(val),empty);object_free(&proc);proc =restore();object_free(&cont);cont =restore();if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch546;}object_free(&val);
                    val = compiled_procedure_entry(proc);
                    goto *val.cont;primitive_branch546:;object_free(&val);val = proc.proc(argl); goto *cont.cont;false_branch542:;object_free(&val);val = c_str_to_datum("#false");goto *cont.cont;after_lambda537:;{Object t = def_var_val(c_str_to_datum("|bytes?|"));
                                   object_free(&val);val = t;}save(cont);save(env);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|bytes?|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|args|"));argl = cons(object_copy(val),empty);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch536;}cont.cont = &&after_call535;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch536:;object_free(&val);val = proc.proc(argl); after_call535:;object_free(&env);env =restore();object_free(&cont);cont =restore();if(val.type==BOOLEAN && !val.boolean){
                        goto false_branch530;}object_free(&proc);proc = lookup_var_val(c_str_to_datum("|c-apply|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|args|"));argl = cons(object_copy(val),empty);object_free(&val);val = lookup_var_val(c_str_to_datum("|c-bytevector|"));argl = cons(object_copy(val), argl);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch534;}object_free(&val);
                    val = compiled_procedure_entry(proc);
                    goto *val.cont;primitive_branch534:;object_free(&val);val = proc.proc(argl); goto *cont.cont;false_branch530:;object_free(&proc);proc = lookup_var_val(c_str_to_datum("|error|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|args|"));argl = cons(object_copy(val),empty);object_free(&val);val = c_str_to_datum("|(bytevector) wrong type of argument --|");argl = cons(object_copy(val), argl);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch532;}object_free(&val);
                    val = compiled_procedure_entry(proc);
                    goto *val.cont;primitive_branch532:;object_free(&val);val = proc.proc(argl); goto *cont.cont;after_lambda527:;{Object t = def_var_val(c_str_to_datum("|bytevector|"));
                                   object_free(&val);val = t;}object_free(&val);val = make_compiled_procedure(&&entry502);goto after_lambda501;entry502:env = compiled_procedure_env();
                          env = extend_environment(c_str_to_datum("|args|"));object_free(&val);val = make_compiled_procedure(&&entry512);goto after_lambda511;entry512:env = compiled_procedure_env();
                          env = extend_environment(c_str_to_datum("(|bytevectors| . ())"));save(cont);save(env);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|c-null?|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|bytevectors|"));argl = cons(object_copy(val),empty);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch526;}cont.cont = &&after_call525;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch526:;object_free(&val);val = proc.proc(argl); after_call525:;object_free(&env);env =restore();object_free(&cont);cont =restore();if(val.type==BOOLEAN && !val.boolean){
                        goto false_branch514;}object_free(&val);val = c_str_to_datum("#true");goto *cont.cont;false_branch514:;save(cont);save(env);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|c-bytevector?|"));save(proc);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|c-car|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|bytevectors|"));argl = cons(object_copy(val),empty);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch522;}cont.cont = &&after_call521;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch522:;object_free(&val);val = proc.proc(argl); after_call521:;argl = cons(object_copy(val),empty);object_free(&proc);proc =restore();if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch524;}cont.cont = &&after_call523;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch524:;object_free(&val);val = proc.proc(argl); after_call523:;object_free(&env);env =restore();object_free(&cont);cont =restore();if(val.type==BOOLEAN && !val.boolean){
                        goto false_branch516;}object_free(&proc);proc = lookup_var_val(c_str_to_datum("|bytevectors?|"));save(cont);save(proc);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|c-cdr|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|bytevectors|"));argl = cons(object_copy(val),empty);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch518;}cont.cont = &&after_call517;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch518:;object_free(&val);val = proc.proc(argl); after_call517:;argl = cons(object_copy(val),empty);object_free(&proc);proc =restore();object_free(&cont);cont =restore();if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch520;}object_free(&val);
                    val = compiled_procedure_entry(proc);
                    goto *val.cont;primitive_branch520:;object_free(&val);val = proc.proc(argl); goto *cont.cont;false_branch516:;object_free(&val);val = c_str_to_datum("#false");goto *cont.cont;after_lambda511:;{Object t = def_var_val(c_str_to_datum("|bytevectors?|"));
                                   object_free(&val);val = t;}save(cont);save(env);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|bytevectors?|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|args|"));argl = cons(object_copy(val),empty);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch510;}cont.cont = &&after_call509;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch510:;object_free(&val);val = proc.proc(argl); after_call509:;object_free(&env);env =restore();object_free(&cont);cont =restore();if(val.type==BOOLEAN && !val.boolean){
                        goto false_branch504;}object_free(&proc);proc = lookup_var_val(c_str_to_datum("|c-apply|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|args|"));argl = cons(object_copy(val),empty);object_free(&val);val = lookup_var_val(c_str_to_datum("|c-bytevector-append|"));argl = cons(object_copy(val), argl);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch508;}object_free(&val);
                    val = compiled_procedure_entry(proc);
                    goto *val.cont;primitive_branch508:;object_free(&val);val = proc.proc(argl); goto *cont.cont;false_branch504:;object_free(&proc);proc = lookup_var_val(c_str_to_datum("|error|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|args|"));argl = cons(object_copy(val),empty);object_free(&val);val = c_str_to_datum("|(bytevector-append) wrong type of argument --|");argl = cons(object_copy(val), argl);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch506;}object_free(&val);
                    val = compiled_procedure_entry(proc);
                    goto *val.cont;primitive_branch506:;object_free(&val);val = proc.proc(argl); goto *cont.cont;after_lambda501:;{Object t = def_var_val(c_str_to_datum("|bytevector-append|"));
                                   object_free(&val);val = t;}object_free(&val);val = make_compiled_procedure(&&entry432);goto after_lambda431;entry432:env = compiled_procedure_env();
                          env = extend_environment(c_str_to_datum("|args|"));save(cont);save(env);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|c-length|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|args|"));argl = cons(object_copy(val),empty);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch500;}cont.cont = &&after_call499;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch500:;object_free(&val);val = proc.proc(argl); after_call499:;object_free(&env);env =restore();{Object t = def_var_val(c_str_to_datum("|len|"));
                                   object_free(&val);val = t;}object_free(&cont);cont =restore();save(cont);save(env);save(env);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|c-<|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|len|"));argl = cons(object_copy(val),empty);object_free(&val);val = c_str_to_datum("0");argl = cons(object_copy(val), argl);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch498;}cont.cont = &&after_call497;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch498:;object_free(&val);val = proc.proc(argl); after_call497:;object_free(&env);env =restore();if(val.type==BOOLEAN && !val.boolean){
                        goto false_branch494;}object_free(&proc);proc = lookup_var_val(c_str_to_datum("|c-<|"));object_free(&val);val = c_str_to_datum("4");argl = cons(object_copy(val),empty);object_free(&val);val = lookup_var_val(c_str_to_datum("|len|"));argl = cons(object_copy(val), argl);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch496;}cont.cont = &&after_if493;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch496:;object_free(&val);val = proc.proc(argl); goto after_if493;false_branch494:;object_free(&val);val = c_str_to_datum("#false");after_if493:;object_free(&env);env =restore();object_free(&cont);cont =restore();if(val.type==BOOLEAN && !val.boolean){
                        goto false_branch434;}save(cont);save(env);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|c-car|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|args|"));argl = cons(object_copy(val),empty);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch492;}cont.cont = &&after_call491;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch492:;object_free(&val);val = proc.proc(argl); after_call491:;object_free(&env);env =restore();{Object t = def_var_val(c_str_to_datum("|bytevector|"));
                                   object_free(&val);val = t;}object_free(&cont);cont =restore();save(cont);save(env);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|c-bytevector?|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|bytevector|"));argl = cons(object_copy(val),empty);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch490;}cont.cont = &&after_call489;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch490:;object_free(&val);val = proc.proc(argl); after_call489:;object_free(&env);env =restore();object_free(&cont);cont =restore();if(val.type==BOOLEAN && !val.boolean){
                        goto false_branch438;}save(cont);save(env);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|c-bytevector-length|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|bytevector|"));argl = cons(object_copy(val),empty);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch488;}cont.cont = &&after_call487;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch488:;object_free(&val);val = proc.proc(argl); after_call487:;object_free(&env);env =restore();{Object t = def_var_val(c_str_to_datum("|bytevector-len|"));
                                   object_free(&val);val = t;}object_free(&cont);cont =restore();save(cont);save(env);save(env);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|c-=|"));object_free(&val);val = c_str_to_datum("1");argl = cons(object_copy(val),empty);object_free(&val);val = lookup_var_val(c_str_to_datum("|len|"));argl = cons(object_copy(val), argl);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch486;}cont.cont = &&after_call485;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch486:;object_free(&val);val = proc.proc(argl); after_call485:;object_free(&env);env =restore();if(val.type==BOOLEAN && !val.boolean){
                        goto false_branch482;}object_free(&val);val = c_str_to_datum("0");goto after_if481;false_branch482:;object_free(&proc);proc = lookup_var_val(c_str_to_datum("|c-cadr|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|args|"));argl = cons(object_copy(val),empty);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch484;}cont.cont = &&after_call483;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch484:;object_free(&val);val = proc.proc(argl); after_call483:;after_if481:;object_free(&env);env =restore();{Object t = def_var_val(c_str_to_datum("|start|"));
                                   object_free(&val);val = t;}object_free(&cont);cont =restore();save(cont);save(env);save(env);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|c-<|"));object_free(&val);val = c_str_to_datum("3");argl = cons(object_copy(val),empty);object_free(&val);val = lookup_var_val(c_str_to_datum("|len|"));argl = cons(object_copy(val), argl);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch480;}cont.cont = &&after_call479;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch480:;object_free(&val);val = proc.proc(argl); after_call479:;object_free(&env);env =restore();if(val.type==BOOLEAN && !val.boolean){
                        goto false_branch476;}object_free(&val);val = lookup_var_val(c_str_to_datum("|bytevector-len|"));goto after_if475;false_branch476:;object_free(&proc);proc = lookup_var_val(c_str_to_datum("|c-caddr|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|args|"));argl = cons(object_copy(val),empty);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch478;}cont.cont = &&after_call477;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch478:;object_free(&val);val = proc.proc(argl); after_call477:;after_if475:;object_free(&env);env =restore();{Object t = def_var_val(c_str_to_datum("|end|"));
                                   object_free(&val);val = t;}object_free(&cont);cont =restore();save(cont);save(env);save(env);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|c-integer?|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|start|"));argl = cons(object_copy(val),empty);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch474;}cont.cont = &&after_call473;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch474:;object_free(&val);val = proc.proc(argl); after_call473:;object_free(&env);env =restore();if(val.type==BOOLEAN && !val.boolean){
                        goto false_branch448;}save(env);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|c-exact?|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|start|"));argl = cons(object_copy(val),empty);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch472;}cont.cont = &&after_call471;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch472:;object_free(&val);val = proc.proc(argl); after_call471:;object_free(&env);env =restore();if(val.type==BOOLEAN && !val.boolean){
                        goto false_branch450;}save(env);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|c-integer?|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|end|"));argl = cons(object_copy(val),empty);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch470;}cont.cont = &&after_call469;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch470:;object_free(&val);val = proc.proc(argl); after_call469:;object_free(&env);env =restore();if(val.type==BOOLEAN && !val.boolean){
                        goto false_branch452;}save(env);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|c-exact?|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|end|"));argl = cons(object_copy(val),empty);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch468;}cont.cont = &&after_call467;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch468:;object_free(&val);val = proc.proc(argl); after_call467:;object_free(&env);env =restore();if(val.type==BOOLEAN && !val.boolean){
                        goto false_branch454;}save(env);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|c-<|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|start|"));argl = cons(object_copy(val),empty);object_free(&val);val = c_str_to_datum("-1");argl = cons(object_copy(val), argl);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch466;}cont.cont = &&after_call465;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch466:;object_free(&val);val = proc.proc(argl); after_call465:;object_free(&env);env =restore();if(val.type==BOOLEAN && !val.boolean){
                        goto false_branch456;}save(env);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|c-<|"));save(proc);save(env);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|c-+|"));object_free(&val);val = c_str_to_datum("1");argl = cons(object_copy(val),empty);object_free(&val);val = lookup_var_val(c_str_to_datum("|bytevector-len|"));argl = cons(object_copy(val), argl);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch462;}cont.cont = &&after_call461;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch462:;object_free(&val);val = proc.proc(argl); after_call461:;argl = cons(object_copy(val),empty);object_free(&env);env =restore();object_free(&val);val = lookup_var_val(c_str_to_datum("|end|"));argl = cons(object_copy(val), argl);object_free(&proc);proc =restore();if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch464;}cont.cont = &&after_call463;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch464:;object_free(&val);val = proc.proc(argl); after_call463:;object_free(&env);env =restore();if(val.type==BOOLEAN && !val.boolean){
                        goto false_branch458;}object_free(&proc);proc = lookup_var_val(c_str_to_datum("|c-<|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|end|"));argl = cons(object_copy(val),empty);object_free(&val);val = lookup_var_val(c_str_to_datum("|start|"));argl = cons(object_copy(val), argl);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch460;}cont.cont = &&after_if447;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch460:;object_free(&val);val = proc.proc(argl); goto after_if447;false_branch458:;object_free(&val);val = c_str_to_datum("#false");goto after_if447;false_branch456:;object_free(&val);val = c_str_to_datum("#false");goto after_if447;false_branch454:;object_free(&val);val = c_str_to_datum("#false");goto after_if447;false_branch452:;object_free(&val);val = c_str_to_datum("#false");goto after_if447;false_branch450:;object_free(&val);val = c_str_to_datum("#false");goto after_if447;false_branch448:;object_free(&val);val = c_str_to_datum("#false");after_if447:;object_free(&env);env =restore();object_free(&cont);cont =restore();if(val.type==BOOLEAN && !val.boolean){
                        goto false_branch442;}object_free(&proc);proc = lookup_var_val(c_str_to_datum("|c-bytevector-copy|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|end|"));argl = cons(object_copy(val),empty);object_free(&val);val = lookup_var_val(c_str_to_datum("|start|"));argl = cons(object_copy(val), argl);object_free(&val);val = lookup_var_val(c_str_to_datum("|bytevector|"));argl = cons(object_copy(val), argl);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch446;}object_free(&val);
                    val = compiled_procedure_entry(proc);
                    goto *val.cont;primitive_branch446:;object_free(&val);val = proc.proc(argl); goto *cont.cont;false_branch442:;object_free(&proc);proc = lookup_var_val(c_str_to_datum("|error|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|args|"));argl = cons(object_copy(val),empty);object_free(&val);val = c_str_to_datum("|(bytevector-copy) wrong type of argument --|");argl = cons(object_copy(val), argl);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch444;}object_free(&val);
                    val = compiled_procedure_entry(proc);
                    goto *val.cont;primitive_branch444:;object_free(&val);val = proc.proc(argl); goto *cont.cont;false_branch438:;object_free(&proc);proc = lookup_var_val(c_str_to_datum("|error|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|args|"));argl = cons(object_copy(val),empty);object_free(&val);val = c_str_to_datum("|(bytevector-copy) wrong type of argument --|");argl = cons(object_copy(val), argl);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch440;}object_free(&val);
                    val = compiled_procedure_entry(proc);
                    goto *val.cont;primitive_branch440:;object_free(&val);val = proc.proc(argl); goto *cont.cont;false_branch434:;object_free(&proc);proc = lookup_var_val(c_str_to_datum("|error|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|args|"));argl = cons(object_copy(val),empty);object_free(&val);val = c_str_to_datum("|(bytevector-copy) wrong number of arguments --|");argl = cons(object_copy(val), argl);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch436;}object_free(&val);
                    val = compiled_procedure_entry(proc);
                    goto *val.cont;primitive_branch436:;object_free(&val);val = proc.proc(argl); goto *cont.cont;after_lambda431:;{Object t = def_var_val(c_str_to_datum("|bytevector-copy|"));
                                   object_free(&val);val = t;}object_free(&val);val = make_compiled_procedure(&&entry410);goto after_lambda409;entry410:env = compiled_procedure_env();
                          env = extend_environment(c_str_to_datum("|args|"));save(cont);save(env);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|c-=|"));save(proc);object_free(&val);val = c_str_to_datum("1");argl = cons(object_copy(val),empty);save(argl);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|c-length|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|args|"));argl = cons(object_copy(val),empty);if (proc.type == PROC_APPLY) {
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
                 goto *val.cont;primitive_branch430:;object_free(&val);val = proc.proc(argl); after_call429:;object_free(&env);env =restore();object_free(&cont);cont =restore();if(val.type==BOOLEAN && !val.boolean){
                        goto false_branch412;}save(cont);save(env);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|c-bytevector?|"));save(proc);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|c-car|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|args|"));argl = cons(object_copy(val),empty);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch424;}cont.cont = &&after_call423;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch424:;object_free(&val);val = proc.proc(argl); after_call423:;argl = cons(object_copy(val),empty);object_free(&proc);proc =restore();if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch426;}cont.cont = &&after_call425;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch426:;object_free(&val);val = proc.proc(argl); after_call425:;object_free(&env);env =restore();object_free(&cont);cont =restore();if(val.type==BOOLEAN && !val.boolean){
                        goto false_branch416;}object_free(&proc);proc = lookup_var_val(c_str_to_datum("|c-bytevector-length|"));save(cont);save(proc);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|c-car|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|args|"));argl = cons(object_copy(val),empty);if (proc.type == PROC_APPLY) {
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
                    goto *val.cont;primitive_branch422:;object_free(&val);val = proc.proc(argl); goto *cont.cont;false_branch416:;object_free(&proc);proc = lookup_var_val(c_str_to_datum("|error|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|args|"));argl = cons(object_copy(val),empty);object_free(&val);val = c_str_to_datum("|(bytevector-length) wrong type of argument --|");argl = cons(object_copy(val), argl);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch418;}object_free(&val);
                    val = compiled_procedure_entry(proc);
                    goto *val.cont;primitive_branch418:;object_free(&val);val = proc.proc(argl); goto *cont.cont;false_branch412:;object_free(&proc);proc = lookup_var_val(c_str_to_datum("|error|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|args|"));argl = cons(object_copy(val),empty);object_free(&val);val = c_str_to_datum("|(bytevector-length) wrong number of arguments --|");argl = cons(object_copy(val), argl);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch414;}object_free(&val);
                    val = compiled_procedure_entry(proc);
                    goto *val.cont;primitive_branch414:;object_free(&val);val = proc.proc(argl); goto *cont.cont;after_lambda409:;{Object t = def_var_val(c_str_to_datum("|bytevector-length|"));
                                   object_free(&val);val = t;}object_free(&val);val = make_compiled_procedure(&&entry370);goto after_lambda369;entry370:env = compiled_procedure_env();
                          env = extend_environment(c_str_to_datum("|args|"));save(cont);save(env);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|c-=|"));save(proc);object_free(&val);val = c_str_to_datum("2");argl = cons(object_copy(val),empty);save(argl);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|c-length|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|args|"));argl = cons(object_copy(val),empty);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch406;}cont.cont = &&after_call405;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch406:;object_free(&val);val = proc.proc(argl); after_call405:;object_free(&argl);argl =restore();argl = cons(object_copy(val), argl);object_free(&proc);proc =restore();if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch408;}cont.cont = &&after_call407;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch408:;object_free(&val);val = proc.proc(argl); after_call407:;object_free(&env);env =restore();object_free(&cont);cont =restore();if(val.type==BOOLEAN && !val.boolean){
                        goto false_branch372;}save(cont);save(env);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|c-car|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|args|"));argl = cons(object_copy(val),empty);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch404;}cont.cont = &&after_call403;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch404:;object_free(&val);val = proc.proc(argl); after_call403:;object_free(&env);env =restore();{Object t = def_var_val(c_str_to_datum("|bv|"));
                                   object_free(&val);val = t;}object_free(&cont);cont =restore();save(cont);save(env);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|c-cadr|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|args|"));argl = cons(object_copy(val),empty);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch402;}cont.cont = &&after_call401;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch402:;object_free(&val);val = proc.proc(argl); after_call401:;object_free(&env);env =restore();{Object t = def_var_val(c_str_to_datum("|k|"));
                                   object_free(&val);val = t;}object_free(&cont);cont =restore();save(cont);save(env);save(env);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|c-bytevector?|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|bv|"));argl = cons(object_copy(val),empty);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch400;}cont.cont = &&after_call399;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch400:;object_free(&val);val = proc.proc(argl); after_call399:;object_free(&env);env =restore();if(val.type==BOOLEAN && !val.boolean){
                        goto false_branch382;}save(env);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|c-integer?|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|k|"));argl = cons(object_copy(val),empty);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch398;}cont.cont = &&after_call397;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch398:;object_free(&val);val = proc.proc(argl); after_call397:;object_free(&env);env =restore();if(val.type==BOOLEAN && !val.boolean){
                        goto false_branch384;}save(env);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|c-exact?|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|k|"));argl = cons(object_copy(val),empty);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch396;}cont.cont = &&after_call395;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch396:;object_free(&val);val = proc.proc(argl); after_call395:;object_free(&env);env =restore();if(val.type==BOOLEAN && !val.boolean){
                        goto false_branch386;}save(env);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|c-<|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|k|"));argl = cons(object_copy(val),empty);object_free(&val);val = c_str_to_datum("-1");argl = cons(object_copy(val), argl);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch394;}cont.cont = &&after_call393;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch394:;object_free(&val);val = proc.proc(argl); after_call393:;object_free(&env);env =restore();if(val.type==BOOLEAN && !val.boolean){
                        goto false_branch388;}object_free(&proc);proc = lookup_var_val(c_str_to_datum("|c-<|"));save(proc);save(env);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|c-bytevector-length|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|bv|"));argl = cons(object_copy(val),empty);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch390;}cont.cont = &&after_call389;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch390:;object_free(&val);val = proc.proc(argl); after_call389:;argl = cons(object_copy(val),empty);object_free(&env);env =restore();object_free(&val);val = lookup_var_val(c_str_to_datum("|k|"));argl = cons(object_copy(val), argl);object_free(&proc);proc =restore();if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch392;}cont.cont = &&after_if381;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch392:;object_free(&val);val = proc.proc(argl); goto after_if381;false_branch388:;object_free(&val);val = c_str_to_datum("#false");goto after_if381;false_branch386:;object_free(&val);val = c_str_to_datum("#false");goto after_if381;false_branch384:;object_free(&val);val = c_str_to_datum("#false");goto after_if381;false_branch382:;object_free(&val);val = c_str_to_datum("#false");after_if381:;object_free(&env);env =restore();object_free(&cont);cont =restore();if(val.type==BOOLEAN && !val.boolean){
                        goto false_branch376;}object_free(&proc);proc = lookup_var_val(c_str_to_datum("|c-bytevector-u8-ref|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|k|"));argl = cons(object_copy(val),empty);object_free(&val);val = lookup_var_val(c_str_to_datum("|bv|"));argl = cons(object_copy(val), argl);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch380;}object_free(&val);
                    val = compiled_procedure_entry(proc);
                    goto *val.cont;primitive_branch380:;object_free(&val);val = proc.proc(argl); goto *cont.cont;false_branch376:;object_free(&proc);proc = lookup_var_val(c_str_to_datum("|error|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|args|"));argl = cons(object_copy(val),empty);object_free(&val);val = c_str_to_datum("|(bytevector-u8-ref) wrong type of argument --|");argl = cons(object_copy(val), argl);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch378;}object_free(&val);
                    val = compiled_procedure_entry(proc);
                    goto *val.cont;primitive_branch378:;object_free(&val);val = proc.proc(argl); goto *cont.cont;false_branch372:;object_free(&proc);proc = lookup_var_val(c_str_to_datum("|error|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|args|"));argl = cons(object_copy(val),empty);object_free(&val);val = c_str_to_datum("|(bytevector-u8-ref) wrong number of arguments --|");argl = cons(object_copy(val), argl);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch374;}object_free(&val);
                    val = compiled_procedure_entry(proc);
                    goto *val.cont;primitive_branch374:;object_free(&val);val = proc.proc(argl); goto *cont.cont;after_lambda369:;{Object t = def_var_val(c_str_to_datum("|bytevector-u8-ref|"));
                                   object_free(&val);val = t;}object_free(&val);val = make_compiled_procedure(&&entry328);goto after_lambda327;entry328:env = compiled_procedure_env();
                          env = extend_environment(c_str_to_datum("|args|"));save(cont);save(env);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|c-=|"));save(proc);object_free(&val);val = c_str_to_datum("3");argl = cons(object_copy(val),empty);save(argl);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|c-length|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|args|"));argl = cons(object_copy(val),empty);if (proc.type == PROC_APPLY) {
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
                 goto *val.cont;primitive_branch368:;object_free(&val);val = proc.proc(argl); after_call367:;object_free(&env);env =restore();object_free(&cont);cont =restore();if(val.type==BOOLEAN && !val.boolean){
                        goto false_branch330;}save(cont);save(env);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|c-car|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|args|"));argl = cons(object_copy(val),empty);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch364;}cont.cont = &&after_call363;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch364:;object_free(&val);val = proc.proc(argl); after_call363:;object_free(&env);env =restore();{Object t = def_var_val(c_str_to_datum("|bv|"));
                                   object_free(&val);val = t;}object_free(&cont);cont =restore();save(cont);save(env);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|c-cadr|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|args|"));argl = cons(object_copy(val),empty);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch362;}cont.cont = &&after_call361;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch362:;object_free(&val);val = proc.proc(argl); after_call361:;object_free(&env);env =restore();{Object t = def_var_val(c_str_to_datum("|k|"));
                                   object_free(&val);val = t;}object_free(&cont);cont =restore();save(cont);save(env);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|c-caddr|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|args|"));argl = cons(object_copy(val),empty);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch360;}cont.cont = &&after_call359;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch360:;object_free(&val);val = proc.proc(argl); after_call359:;object_free(&env);env =restore();{Object t = def_var_val(c_str_to_datum("|byte|"));
                                   object_free(&val);val = t;}object_free(&cont);cont =restore();save(cont);save(env);save(env);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|c-bytevector?|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|bv|"));argl = cons(object_copy(val),empty);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch358;}cont.cont = &&after_call357;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch358:;object_free(&val);val = proc.proc(argl); after_call357:;object_free(&env);env =restore();if(val.type==BOOLEAN && !val.boolean){
                        goto false_branch340;}save(env);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|c-integer?|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|k|"));argl = cons(object_copy(val),empty);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch356;}cont.cont = &&after_call355;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch356:;object_free(&val);val = proc.proc(argl); after_call355:;object_free(&env);env =restore();if(val.type==BOOLEAN && !val.boolean){
                        goto false_branch342;}save(env);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|c-exact?|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|k|"));argl = cons(object_copy(val),empty);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch354;}cont.cont = &&after_call353;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch354:;object_free(&val);val = proc.proc(argl); after_call353:;object_free(&env);env =restore();if(val.type==BOOLEAN && !val.boolean){
                        goto false_branch344;}save(env);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|c-<|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|k|"));argl = cons(object_copy(val),empty);object_free(&val);val = c_str_to_datum("-1");argl = cons(object_copy(val), argl);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch352;}cont.cont = &&after_call351;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch352:;object_free(&val);val = proc.proc(argl); after_call351:;object_free(&env);env =restore();if(val.type==BOOLEAN && !val.boolean){
                        goto false_branch346;}object_free(&proc);proc = lookup_var_val(c_str_to_datum("|c-<|"));save(proc);save(env);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|c-bytevector-length|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|bv|"));argl = cons(object_copy(val),empty);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch348;}cont.cont = &&after_call347;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch348:;object_free(&val);val = proc.proc(argl); after_call347:;argl = cons(object_copy(val),empty);object_free(&env);env =restore();object_free(&val);val = lookup_var_val(c_str_to_datum("|k|"));argl = cons(object_copy(val), argl);object_free(&proc);proc =restore();if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch350;}cont.cont = &&after_if339;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch350:;object_free(&val);val = proc.proc(argl); goto after_if339;false_branch346:;object_free(&val);val = c_str_to_datum("#false");goto after_if339;false_branch344:;object_free(&val);val = c_str_to_datum("#false");goto after_if339;false_branch342:;object_free(&val);val = c_str_to_datum("#false");goto after_if339;false_branch340:;object_free(&val);val = c_str_to_datum("#false");after_if339:;object_free(&env);env =restore();object_free(&cont);cont =restore();if(val.type==BOOLEAN && !val.boolean){
                        goto false_branch334;}object_free(&proc);proc = lookup_var_val(c_str_to_datum("|c-bytevector-u8-set!|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|byte|"));argl = cons(object_copy(val),empty);object_free(&val);val = lookup_var_val(c_str_to_datum("|k|"));argl = cons(object_copy(val), argl);object_free(&val);val = lookup_var_val(c_str_to_datum("|bv|"));argl = cons(object_copy(val), argl);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch338;}object_free(&val);
                    val = compiled_procedure_entry(proc);
                    goto *val.cont;primitive_branch338:;object_free(&val);val = proc.proc(argl); goto *cont.cont;false_branch334:;object_free(&proc);proc = lookup_var_val(c_str_to_datum("|error|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|args|"));argl = cons(object_copy(val),empty);object_free(&val);val = c_str_to_datum("|(bytevector-u8-set!) wrong type of argument --|");argl = cons(object_copy(val), argl);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch336;}object_free(&val);
                    val = compiled_procedure_entry(proc);
                    goto *val.cont;primitive_branch336:;object_free(&val);val = proc.proc(argl); goto *cont.cont;false_branch330:;object_free(&proc);proc = lookup_var_val(c_str_to_datum("|error|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|args|"));argl = cons(object_copy(val),empty);object_free(&val);val = c_str_to_datum("|(bytevector-u8-set!) wrong number of arguments --|");argl = cons(object_copy(val), argl);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch332;}object_free(&val);
                    val = compiled_procedure_entry(proc);
                    goto *val.cont;primitive_branch332:;object_free(&val);val = proc.proc(argl); goto *cont.cont;after_lambda327:;{Object t = def_var_val(c_str_to_datum("|bytevector-u8-set!|"));
                                   object_free(&val);val = t;}object_free(&val);val = make_compiled_procedure(&&entry314);goto after_lambda313;entry314:env = compiled_procedure_env();
                          env = extend_environment(c_str_to_datum("|args|"));save(cont);save(env);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|c-=|"));save(proc);object_free(&val);val = c_str_to_datum("1");argl = cons(object_copy(val),empty);save(argl);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|c-length|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|args|"));argl = cons(object_copy(val),empty);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch324;}cont.cont = &&after_call323;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch324:;object_free(&val);val = proc.proc(argl); after_call323:;object_free(&argl);argl =restore();argl = cons(object_copy(val), argl);object_free(&proc);proc =restore();if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch326;}cont.cont = &&after_call325;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch326:;object_free(&val);val = proc.proc(argl); after_call325:;object_free(&env);env =restore();object_free(&cont);cont =restore();if(val.type==BOOLEAN && !val.boolean){
                        goto false_branch316;}object_free(&proc);proc = lookup_var_val(c_str_to_datum("|c-bytevector?|"));save(cont);save(proc);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|c-car|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|args|"));argl = cons(object_copy(val),empty);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch320;}cont.cont = &&after_call319;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch320:;object_free(&val);val = proc.proc(argl); after_call319:;argl = cons(object_copy(val),empty);object_free(&proc);proc =restore();object_free(&cont);cont =restore();if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch322;}object_free(&val);
                    val = compiled_procedure_entry(proc);
                    goto *val.cont;primitive_branch322:;object_free(&val);val = proc.proc(argl); goto *cont.cont;false_branch316:;object_free(&proc);proc = lookup_var_val(c_str_to_datum("|error|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|args|"));argl = cons(object_copy(val),empty);object_free(&val);val = c_str_to_datum("|(bytevector?) wrong number of arguments --|");argl = cons(object_copy(val), argl);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch318;}object_free(&val);
                    val = compiled_procedure_entry(proc);
                    goto *val.cont;primitive_branch318:;object_free(&val);val = proc.proc(argl); goto *cont.cont;after_lambda313:;{Object t = def_var_val(c_str_to_datum("|bytevector?|"));
                                   object_free(&val);val = t;}object_free(&val);val = make_compiled_procedure(&&entry292);goto after_lambda291;entry292:env = compiled_procedure_env();
                          env = extend_environment(c_str_to_datum("|args|"));save(cont);save(env);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|=|"));save(proc);object_free(&val);val = c_str_to_datum("1");argl = cons(object_copy(val),empty);save(argl);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|c-length|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|args|"));argl = cons(object_copy(val),empty);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch310;}cont.cont = &&after_call309;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch310:;object_free(&val);val = proc.proc(argl); after_call309:;object_free(&argl);argl =restore();argl = cons(object_copy(val), argl);object_free(&proc);proc =restore();if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch312;}cont.cont = &&after_call311;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch312:;object_free(&val);val = proc.proc(argl); after_call311:;object_free(&env);env =restore();object_free(&cont);cont =restore();if(val.type==BOOLEAN && !val.boolean){
                        goto false_branch294;}save(cont);save(env);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|c-pair?|"));save(proc);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|c-car|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|args|"));argl = cons(object_copy(val),empty);if (proc.type == PROC_APPLY) {
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
                        goto false_branch298;}object_free(&proc);proc = lookup_var_val(c_str_to_datum("|c-car|"));save(cont);save(proc);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|c-car|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|args|"));argl = cons(object_copy(val),empty);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch302;}cont.cont = &&after_call301;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch302:;object_free(&val);val = proc.proc(argl); after_call301:;argl = cons(object_copy(val),empty);object_free(&proc);proc =restore();object_free(&cont);cont =restore();if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch304;}object_free(&val);
                    val = compiled_procedure_entry(proc);
                    goto *val.cont;primitive_branch304:;object_free(&val);val = proc.proc(argl); goto *cont.cont;false_branch298:;object_free(&proc);proc = lookup_var_val(c_str_to_datum("|error|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|args|"));argl = cons(object_copy(val),empty);object_free(&val);val = c_str_to_datum("|(car) wrong type of argument --|");argl = cons(object_copy(val), argl);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch300;}object_free(&val);
                    val = compiled_procedure_entry(proc);
                    goto *val.cont;primitive_branch300:;object_free(&val);val = proc.proc(argl); goto *cont.cont;false_branch294:;object_free(&proc);proc = lookup_var_val(c_str_to_datum("|error|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|args|"));argl = cons(object_copy(val),empty);object_free(&val);val = c_str_to_datum("|(car) wrong number of arguments --|");argl = cons(object_copy(val), argl);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch296;}object_free(&val);
                    val = compiled_procedure_entry(proc);
                    goto *val.cont;primitive_branch296:;object_free(&val);val = proc.proc(argl); goto *cont.cont;after_lambda291:;{Object t = def_var_val(c_str_to_datum("|car|"));
                                   object_free(&val);val = t;}object_free(&val);val = make_compiled_procedure(&&entry270);goto after_lambda269;entry270:env = compiled_procedure_env();
                          env = extend_environment(c_str_to_datum("|args|"));save(cont);save(env);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|=|"));save(proc);object_free(&val);val = c_str_to_datum("1");argl = cons(object_copy(val),empty);save(argl);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|c-length|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|args|"));argl = cons(object_copy(val),empty);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch288;}cont.cont = &&after_call287;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch288:;object_free(&val);val = proc.proc(argl); after_call287:;object_free(&argl);argl =restore();argl = cons(object_copy(val), argl);object_free(&proc);proc =restore();if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch290;}cont.cont = &&after_call289;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch290:;object_free(&val);val = proc.proc(argl); after_call289:;object_free(&env);env =restore();object_free(&cont);cont =restore();if(val.type==BOOLEAN && !val.boolean){
                        goto false_branch272;}save(cont);save(env);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|c-pair?|"));save(proc);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|car|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|args|"));argl = cons(object_copy(val),empty);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch284;}cont.cont = &&after_call283;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch284:;object_free(&val);val = proc.proc(argl); after_call283:;argl = cons(object_copy(val),empty);object_free(&proc);proc =restore();if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch286;}cont.cont = &&after_call285;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch286:;object_free(&val);val = proc.proc(argl); after_call285:;object_free(&env);env =restore();object_free(&cont);cont =restore();if(val.type==BOOLEAN && !val.boolean){
                        goto false_branch276;}object_free(&proc);proc = lookup_var_val(c_str_to_datum("|c-cdr|"));save(cont);save(proc);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|c-car|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|args|"));argl = cons(object_copy(val),empty);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch280;}cont.cont = &&after_call279;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch280:;object_free(&val);val = proc.proc(argl); after_call279:;argl = cons(object_copy(val),empty);object_free(&proc);proc =restore();object_free(&cont);cont =restore();if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch282;}object_free(&val);
                    val = compiled_procedure_entry(proc);
                    goto *val.cont;primitive_branch282:;object_free(&val);val = proc.proc(argl); goto *cont.cont;false_branch276:;object_free(&proc);proc = lookup_var_val(c_str_to_datum("|error|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|args|"));argl = cons(object_copy(val),empty);object_free(&val);val = c_str_to_datum("|(cdr) wrong type of argument --|");argl = cons(object_copy(val), argl);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch278;}object_free(&val);
                    val = compiled_procedure_entry(proc);
                    goto *val.cont;primitive_branch278:;object_free(&val);val = proc.proc(argl); goto *cont.cont;false_branch272:;object_free(&proc);proc = lookup_var_val(c_str_to_datum("|error|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|args|"));argl = cons(object_copy(val),empty);object_free(&val);val = c_str_to_datum("|(cdr) wrong number of arguments --|");argl = cons(object_copy(val), argl);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch274;}object_free(&val);
                    val = compiled_procedure_entry(proc);
                    goto *val.cont;primitive_branch274:;object_free(&val);val = proc.proc(argl); goto *cont.cont;after_lambda269:;{Object t = def_var_val(c_str_to_datum("|cdr|"));
                                   object_free(&val);val = t;}object_free(&val);val = make_compiled_procedure(&&entry248);goto after_lambda247;entry248:env = compiled_procedure_env();
                          env = extend_environment(c_str_to_datum("|args|"));save(cont);save(env);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|c-=|"));save(proc);object_free(&val);val = c_str_to_datum("1");argl = cons(object_copy(val),empty);save(argl);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|c-length|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|args|"));argl = cons(object_copy(val),empty);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch266;}cont.cont = &&after_call265;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch266:;object_free(&val);val = proc.proc(argl); after_call265:;object_free(&argl);argl =restore();argl = cons(object_copy(val), argl);object_free(&proc);proc =restore();if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch268;}cont.cont = &&after_call267;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch268:;object_free(&val);val = proc.proc(argl); after_call267:;object_free(&env);env =restore();object_free(&cont);cont =restore();if(val.type==BOOLEAN && !val.boolean){
                        goto false_branch250;}save(cont);save(env);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|c-real?|"));save(proc);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|c-car|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|args|"));argl = cons(object_copy(val),empty);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch262;}cont.cont = &&after_call261;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch262:;object_free(&val);val = proc.proc(argl); after_call261:;argl = cons(object_copy(val),empty);object_free(&proc);proc =restore();if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch264;}cont.cont = &&after_call263;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch264:;object_free(&val);val = proc.proc(argl); after_call263:;object_free(&env);env =restore();object_free(&cont);cont =restore();if(val.type==BOOLEAN && !val.boolean){
                        goto false_branch254;}object_free(&proc);proc = lookup_var_val(c_str_to_datum("|c-ceiling|"));save(cont);save(proc);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|c-car|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|args|"));argl = cons(object_copy(val),empty);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch258;}cont.cont = &&after_call257;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch258:;object_free(&val);val = proc.proc(argl); after_call257:;argl = cons(object_copy(val),empty);object_free(&proc);proc =restore();object_free(&cont);cont =restore();if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch260;}object_free(&val);
                    val = compiled_procedure_entry(proc);
                    goto *val.cont;primitive_branch260:;object_free(&val);val = proc.proc(argl); goto *cont.cont;false_branch254:;object_free(&proc);proc = lookup_var_val(c_str_to_datum("|error|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|args|"));argl = cons(object_copy(val),empty);object_free(&val);val = c_str_to_datum("|(ceiling) wrong type of argument --|");argl = cons(object_copy(val), argl);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch256;}object_free(&val);
                    val = compiled_procedure_entry(proc);
                    goto *val.cont;primitive_branch256:;object_free(&val);val = proc.proc(argl); goto *cont.cont;false_branch250:;object_free(&proc);proc = lookup_var_val(c_str_to_datum("|error|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|args|"));argl = cons(object_copy(val),empty);object_free(&val);val = c_str_to_datum("|(ceiling) wrong number of arguments --|");argl = cons(object_copy(val), argl);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch252;}object_free(&val);
                    val = compiled_procedure_entry(proc);
                    goto *val.cont;primitive_branch252:;object_free(&val);val = proc.proc(argl); goto *cont.cont;after_lambda247:;{Object t = def_var_val(c_str_to_datum("|ceiling|"));
                                   object_free(&val);val = t;}object_free(&val);val = make_compiled_procedure(&&entry226);goto after_lambda225;entry226:env = compiled_procedure_env();
                          env = extend_environment(c_str_to_datum("|args|"));save(cont);save(env);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|c-=|"));save(proc);object_free(&val);val = c_str_to_datum("1");argl = cons(object_copy(val),empty);save(argl);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|c-length|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|args|"));argl = cons(object_copy(val),empty);if (proc.type == PROC_APPLY) {
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
                 goto *val.cont;primitive_branch246:;object_free(&val);val = proc.proc(argl); after_call245:;object_free(&env);env =restore();object_free(&cont);cont =restore();if(val.type==BOOLEAN && !val.boolean){
                        goto false_branch228;}save(cont);save(env);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|c-char?|"));save(proc);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|c-car|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|args|"));argl = cons(object_copy(val),empty);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch240;}cont.cont = &&after_call239;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch240:;object_free(&val);val = proc.proc(argl); after_call239:;argl = cons(object_copy(val),empty);object_free(&proc);proc =restore();if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch242;}cont.cont = &&after_call241;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch242:;object_free(&val);val = proc.proc(argl); after_call241:;object_free(&env);env =restore();object_free(&cont);cont =restore();if(val.type==BOOLEAN && !val.boolean){
                        goto false_branch232;}object_free(&proc);proc = lookup_var_val(c_str_to_datum("|c-char->integer|"));save(cont);save(proc);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|c-car|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|args|"));argl = cons(object_copy(val),empty);if (proc.type == PROC_APPLY) {
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
                    goto *val.cont;primitive_branch238:;object_free(&val);val = proc.proc(argl); goto *cont.cont;false_branch232:;object_free(&proc);proc = lookup_var_val(c_str_to_datum("|error|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|args|"));argl = cons(object_copy(val),empty);object_free(&val);val = c_str_to_datum("|(char->integer) wrong type of argument --|");argl = cons(object_copy(val), argl);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch234;}object_free(&val);
                    val = compiled_procedure_entry(proc);
                    goto *val.cont;primitive_branch234:;object_free(&val);val = proc.proc(argl); goto *cont.cont;false_branch228:;object_free(&proc);proc = lookup_var_val(c_str_to_datum("|error|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|args|"));argl = cons(object_copy(val),empty);object_free(&val);val = c_str_to_datum("|(char->integer) wrong number of arguments --|");argl = cons(object_copy(val), argl);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch230;}object_free(&val);
                    val = compiled_procedure_entry(proc);
                    goto *val.cont;primitive_branch230:;object_free(&val);val = proc.proc(argl); goto *cont.cont;after_lambda225:;{Object t = def_var_val(c_str_to_datum("|char->integer|"));
                                   object_free(&val);val = t;}object_free(&val);val = make_compiled_procedure(&&entry210);goto after_lambda209;entry210:env = compiled_procedure_env();
                          env = extend_environment(c_str_to_datum("|args|"));save(cont);save(env);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|=|"));save(proc);object_free(&val);val = c_str_to_datum("2");argl = cons(object_copy(val),empty);save(argl);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|c-length|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|args|"));argl = cons(object_copy(val),empty);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch222;}cont.cont = &&after_call221;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch222:;object_free(&val);val = proc.proc(argl); after_call221:;object_free(&argl);argl =restore();argl = cons(object_copy(val), argl);object_free(&proc);proc =restore();if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch224;}cont.cont = &&after_call223;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch224:;object_free(&val);val = proc.proc(argl); after_call223:;object_free(&env);env =restore();object_free(&cont);cont =restore();if(val.type==BOOLEAN && !val.boolean){
                        goto false_branch212;}object_free(&proc);proc = lookup_var_val(c_str_to_datum("|c-cons|"));save(cont);save(proc);save(env);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|c-cadr|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|args|"));argl = cons(object_copy(val),empty);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch216;}cont.cont = &&after_call215;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch216:;object_free(&val);val = proc.proc(argl); after_call215:;argl = cons(object_copy(val),empty);object_free(&env);env =restore();save(argl);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|c-car|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|args|"));argl = cons(object_copy(val),empty);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch218;}cont.cont = &&after_call217;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch218:;object_free(&val);val = proc.proc(argl); after_call217:;object_free(&argl);argl =restore();argl = cons(object_copy(val), argl);object_free(&proc);proc =restore();object_free(&cont);cont =restore();if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch220;}object_free(&val);
                    val = compiled_procedure_entry(proc);
                    goto *val.cont;primitive_branch220:;object_free(&val);val = proc.proc(argl); goto *cont.cont;false_branch212:;object_free(&proc);proc = lookup_var_val(c_str_to_datum("|error|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|args|"));argl = cons(object_copy(val),empty);object_free(&val);val = c_str_to_datum("\"(cons) wrong number of arguments --\"");argl = cons(object_copy(val), argl);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch214;}object_free(&val);
                    val = compiled_procedure_entry(proc);
                    goto *val.cont;primitive_branch214:;object_free(&val);val = proc.proc(argl); goto *cont.cont;after_lambda209:;{Object t = def_var_val(c_str_to_datum("|cons|"));
                                   object_free(&val);val = t;}save(cont);save(env);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|list|"));save(proc);save(env);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|list|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|cons|"));argl = cons(object_copy(val),empty);object_free(&val);val = c_str_to_datum("|cons|");argl = cons(object_copy(val), argl);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch156;}cont.cont = &&after_call155;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch156:;object_free(&val);val = proc.proc(argl); after_call155:;argl = cons(object_copy(val),empty);object_free(&env);env =restore();save(env);save(argl);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|list|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|char->integer|"));argl = cons(object_copy(val),empty);object_free(&val);val = c_str_to_datum("|char->integer|");argl = cons(object_copy(val), argl);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch158;}cont.cont = &&after_call157;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch158:;object_free(&val);val = proc.proc(argl); after_call157:;object_free(&argl);argl =restore();argl = cons(object_copy(val), argl);object_free(&env);env =restore();save(env);save(argl);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|list|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|ceiling|"));argl = cons(object_copy(val),empty);object_free(&val);val = c_str_to_datum("|ceiling|");argl = cons(object_copy(val), argl);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch160;}cont.cont = &&after_call159;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch160:;object_free(&val);val = proc.proc(argl); after_call159:;object_free(&argl);argl =restore();argl = cons(object_copy(val), argl);object_free(&env);env =restore();save(env);save(argl);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|list|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|cdr|"));argl = cons(object_copy(val),empty);object_free(&val);val = c_str_to_datum("|cdr|");argl = cons(object_copy(val), argl);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch162;}cont.cont = &&after_call161;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch162:;object_free(&val);val = proc.proc(argl); after_call161:;object_free(&argl);argl =restore();argl = cons(object_copy(val), argl);object_free(&env);env =restore();save(env);save(argl);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|list|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|car|"));argl = cons(object_copy(val),empty);object_free(&val);val = c_str_to_datum("|car|");argl = cons(object_copy(val), argl);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch164;}cont.cont = &&after_call163;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch164:;object_free(&val);val = proc.proc(argl); after_call163:;object_free(&argl);argl =restore();argl = cons(object_copy(val), argl);object_free(&env);env =restore();save(env);save(argl);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|list|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|bytevector?|"));argl = cons(object_copy(val),empty);object_free(&val);val = c_str_to_datum("|bytevector?|");argl = cons(object_copy(val), argl);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch166;}cont.cont = &&after_call165;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch166:;object_free(&val);val = proc.proc(argl); after_call165:;object_free(&argl);argl =restore();argl = cons(object_copy(val), argl);object_free(&env);env =restore();save(env);save(argl);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|list|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|bytevector-u8-set!|"));argl = cons(object_copy(val),empty);object_free(&val);val = c_str_to_datum("|bytevector-u8-set!|");argl = cons(object_copy(val), argl);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch168;}cont.cont = &&after_call167;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch168:;object_free(&val);val = proc.proc(argl); after_call167:;object_free(&argl);argl =restore();argl = cons(object_copy(val), argl);object_free(&env);env =restore();save(env);save(argl);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|list|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|bytevector-u8-ref|"));argl = cons(object_copy(val),empty);object_free(&val);val = c_str_to_datum("|bytevector-u8-ref|");argl = cons(object_copy(val), argl);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch170;}cont.cont = &&after_call169;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch170:;object_free(&val);val = proc.proc(argl); after_call169:;object_free(&argl);argl =restore();argl = cons(object_copy(val), argl);object_free(&env);env =restore();save(env);save(argl);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|list|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|bytevector-length|"));argl = cons(object_copy(val),empty);object_free(&val);val = c_str_to_datum("|bytevector-length|");argl = cons(object_copy(val), argl);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch172;}cont.cont = &&after_call171;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch172:;object_free(&val);val = proc.proc(argl); after_call171:;object_free(&argl);argl =restore();argl = cons(object_copy(val), argl);object_free(&env);env =restore();save(env);save(argl);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|list|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|bytevector-copy|"));argl = cons(object_copy(val),empty);object_free(&val);val = c_str_to_datum("|bytevector-copy|");argl = cons(object_copy(val), argl);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch174;}cont.cont = &&after_call173;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch174:;object_free(&val);val = proc.proc(argl); after_call173:;object_free(&argl);argl =restore();argl = cons(object_copy(val), argl);object_free(&env);env =restore();save(env);save(argl);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|list|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|bytevector-append|"));argl = cons(object_copy(val),empty);object_free(&val);val = c_str_to_datum("|bytevector-append|");argl = cons(object_copy(val), argl);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch176;}cont.cont = &&after_call175;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch176:;object_free(&val);val = proc.proc(argl); after_call175:;object_free(&argl);argl =restore();argl = cons(object_copy(val), argl);object_free(&env);env =restore();save(env);save(argl);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|list|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|bytevector|"));argl = cons(object_copy(val),empty);object_free(&val);val = c_str_to_datum("|bytevector|");argl = cons(object_copy(val), argl);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch178;}cont.cont = &&after_call177;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch178:;object_free(&val);val = proc.proc(argl); after_call177:;object_free(&argl);argl =restore();argl = cons(object_copy(val), argl);object_free(&env);env =restore();save(env);save(argl);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|list|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|boolean?|"));argl = cons(object_copy(val),empty);object_free(&val);val = c_str_to_datum("|boolean?|");argl = cons(object_copy(val), argl);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch180;}cont.cont = &&after_call179;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch180:;object_free(&val);val = proc.proc(argl); after_call179:;object_free(&argl);argl =restore();argl = cons(object_copy(val), argl);object_free(&env);env =restore();save(env);save(argl);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|list|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|boolean=?|"));argl = cons(object_copy(val),empty);object_free(&val);val = c_str_to_datum("|boolean=?|");argl = cons(object_copy(val), argl);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch182;}cont.cont = &&after_call181;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch182:;object_free(&val);val = proc.proc(argl); after_call181:;object_free(&argl);argl =restore();argl = cons(object_copy(val), argl);object_free(&env);env =restore();save(env);save(argl);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|list|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|binary-port?|"));argl = cons(object_copy(val),empty);object_free(&val);val = c_str_to_datum("|binary-port?|");argl = cons(object_copy(val), argl);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch184;}cont.cont = &&after_call183;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch184:;object_free(&val);val = proc.proc(argl); after_call183:;object_free(&argl);argl =restore();argl = cons(object_copy(val), argl);object_free(&env);env =restore();save(env);save(argl);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|list|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|append|"));argl = cons(object_copy(val),empty);object_free(&val);val = c_str_to_datum("|append|");argl = cons(object_copy(val), argl);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch186;}cont.cont = &&after_call185;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch186:;object_free(&val);val = proc.proc(argl); after_call185:;object_free(&argl);argl =restore();argl = cons(object_copy(val), argl);object_free(&env);env =restore();save(env);save(argl);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|list|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|abs|"));argl = cons(object_copy(val),empty);object_free(&val);val = c_str_to_datum("|abs|");argl = cons(object_copy(val), argl);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch188;}cont.cont = &&after_call187;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch188:;object_free(&val);val = proc.proc(argl); after_call187:;object_free(&argl);argl =restore();argl = cons(object_copy(val), argl);object_free(&env);env =restore();save(env);save(argl);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|list|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|>=|"));argl = cons(object_copy(val),empty);object_free(&val);val = c_str_to_datum("|>=|");argl = cons(object_copy(val), argl);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch190;}cont.cont = &&after_call189;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch190:;object_free(&val);val = proc.proc(argl); after_call189:;object_free(&argl);argl =restore();argl = cons(object_copy(val), argl);object_free(&env);env =restore();save(env);save(argl);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|list|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|>|"));argl = cons(object_copy(val),empty);object_free(&val);val = c_str_to_datum("|>|");argl = cons(object_copy(val), argl);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch192;}cont.cont = &&after_call191;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch192:;object_free(&val);val = proc.proc(argl); after_call191:;object_free(&argl);argl =restore();argl = cons(object_copy(val), argl);object_free(&env);env =restore();save(env);save(argl);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|list|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|=|"));argl = cons(object_copy(val),empty);object_free(&val);val = c_str_to_datum("|=|");argl = cons(object_copy(val), argl);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch194;}cont.cont = &&after_call193;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch194:;object_free(&val);val = proc.proc(argl); after_call193:;object_free(&argl);argl =restore();argl = cons(object_copy(val), argl);object_free(&env);env =restore();save(env);save(argl);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|list|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|<=|"));argl = cons(object_copy(val),empty);object_free(&val);val = c_str_to_datum("|<=|");argl = cons(object_copy(val), argl);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch196;}cont.cont = &&after_call195;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch196:;object_free(&val);val = proc.proc(argl); after_call195:;object_free(&argl);argl =restore();argl = cons(object_copy(val), argl);object_free(&env);env =restore();save(env);save(argl);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|list|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|<|"));argl = cons(object_copy(val),empty);object_free(&val);val = c_str_to_datum("|<|");argl = cons(object_copy(val), argl);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch198;}cont.cont = &&after_call197;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch198:;object_free(&val);val = proc.proc(argl); after_call197:;object_free(&argl);argl =restore();argl = cons(object_copy(val), argl);object_free(&env);env =restore();save(env);save(argl);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|list|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|/|"));argl = cons(object_copy(val),empty);object_free(&val);val = c_str_to_datum("|/|");argl = cons(object_copy(val), argl);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch200;}cont.cont = &&after_call199;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch200:;object_free(&val);val = proc.proc(argl); after_call199:;object_free(&argl);argl =restore();argl = cons(object_copy(val), argl);object_free(&env);env =restore();save(env);save(argl);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|list|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|-|"));argl = cons(object_copy(val),empty);object_free(&val);val = c_str_to_datum("|-|");argl = cons(object_copy(val), argl);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch202;}cont.cont = &&after_call201;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch202:;object_free(&val);val = proc.proc(argl); after_call201:;object_free(&argl);argl =restore();argl = cons(object_copy(val), argl);object_free(&env);env =restore();save(env);save(argl);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|list|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|+|"));argl = cons(object_copy(val),empty);object_free(&val);val = c_str_to_datum("|+|");argl = cons(object_copy(val), argl);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch204;}cont.cont = &&after_call203;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch204:;object_free(&val);val = proc.proc(argl); after_call203:;object_free(&argl);argl =restore();argl = cons(object_copy(val), argl);object_free(&env);env =restore();save(argl);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|list|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|*|"));argl = cons(object_copy(val),empty);object_free(&val);val = c_str_to_datum("|*|");argl = cons(object_copy(val), argl);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch206;}cont.cont = &&after_call205;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch206:;object_free(&val);val = proc.proc(argl); after_call205:;object_free(&argl);argl =restore();argl = cons(object_copy(val), argl);object_free(&proc);proc =restore();if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch208;}cont.cont = &&after_call207;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch208:;object_free(&val);val = proc.proc(argl); after_call207:;object_free(&env);env =restore();{Object t = def_var_val(c_str_to_datum("|primitive-procedures|"));
                                   object_free(&val);val = t;}object_free(&cont);cont =restore();object_free(&val);val = make_compiled_procedure(&&entry140);goto after_lambda139;entry140:env = compiled_procedure_env();
                          env = extend_environment(c_str_to_datum("(|proc| . (|list| . ()))"));save(cont);save(env);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|null?|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|list|"));argl = cons(object_copy(val),empty);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch154;}cont.cont = &&after_call153;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch154:;object_free(&val);val = proc.proc(argl); after_call153:;object_free(&env);env =restore();object_free(&cont);cont =restore();if(val.type==BOOLEAN && !val.boolean){
                        goto false_branch142;}object_free(&val);val = c_str_to_datum("()");goto *cont.cont;false_branch142:;object_free(&proc);proc = lookup_var_val(c_str_to_datum("|cons|"));save(cont);save(proc);save(env);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|map|"));save(proc);save(env);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|cdr|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|list|"));argl = cons(object_copy(val),empty);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch144;}cont.cont = &&after_call143;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch144:;object_free(&val);val = proc.proc(argl); after_call143:;argl = cons(object_copy(val),empty);object_free(&env);env =restore();object_free(&val);val = lookup_var_val(c_str_to_datum("|proc|"));argl = cons(object_copy(val), argl);object_free(&proc);proc =restore();if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch146;}cont.cont = &&after_call145;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch146:;object_free(&val);val = proc.proc(argl); after_call145:;argl = cons(object_copy(val),empty);object_free(&env);env =restore();save(argl);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|proc|"));save(proc);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|car|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|list|"));argl = cons(object_copy(val),empty);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch148;}cont.cont = &&after_call147;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch148:;object_free(&val);val = proc.proc(argl); after_call147:;argl = cons(object_copy(val),empty);object_free(&proc);proc =restore();if (proc.type == PROC_APPLY) {
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
                    goto *val.cont;primitive_branch152:;object_free(&val);val = proc.proc(argl); goto *cont.cont;after_lambda139:;{Object t = def_var_val(c_str_to_datum("|map|"));
                                   object_free(&val);val = t;}object_free(&val);val = make_compiled_procedure(&&entry136);goto after_lambda135;entry136:env = compiled_procedure_env();
                          env = extend_environment(c_str_to_datum("()"));object_free(&proc);proc = lookup_var_val(c_str_to_datum("|map|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|primitive-procedures|"));argl = cons(object_copy(val),empty);object_free(&val);val = lookup_var_val(c_str_to_datum("|car|"));argl = cons(object_copy(val), argl);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch138;}object_free(&val);
                    val = compiled_procedure_entry(proc);
                    goto *val.cont;primitive_branch138:;object_free(&val);val = proc.proc(argl); goto *cont.cont;after_lambda135:;{Object t = def_var_val(c_str_to_datum("|primitive-procedure-names|"));
                                   object_free(&val);val = t;}object_free(&val);val = make_compiled_procedure(&&entry124);goto after_lambda123;entry124:env = compiled_procedure_env();
                          env = extend_environment(c_str_to_datum("()"));object_free(&proc);proc = lookup_var_val(c_str_to_datum("|map|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|primitive-procedures|"));argl = cons(object_copy(val),empty);object_free(&val);val = make_compiled_procedure(&&entry126);goto after_lambda125;entry126:env = compiled_procedure_env();
                          env = extend_environment(c_str_to_datum("(|proc| . ())"));object_free(&proc);proc = lookup_var_val(c_str_to_datum("|list|"));save(cont);save(proc);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|car|"));save(proc);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|cdr|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|proc|"));argl = cons(object_copy(val),empty);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch128;}cont.cont = &&after_call127;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch128:;object_free(&val);val = proc.proc(argl); after_call127:;argl = cons(object_copy(val),empty);object_free(&proc);proc =restore();if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch130;}cont.cont = &&after_call129;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch130:;object_free(&val);val = proc.proc(argl); after_call129:;argl = cons(object_copy(val),empty);object_free(&val);val = c_str_to_datum("|primitive|");argl = cons(object_copy(val), argl);object_free(&proc);proc =restore();object_free(&cont);cont =restore();if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch132;}object_free(&val);
                    val = compiled_procedure_entry(proc);
                    goto *val.cont;primitive_branch132:;object_free(&val);val = proc.proc(argl); goto *cont.cont;after_lambda125:;argl = cons(object_copy(val), argl);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch134;}object_free(&val);
                    val = compiled_procedure_entry(proc);
                    goto *val.cont;primitive_branch134:;object_free(&val);val = proc.proc(argl); goto *cont.cont;after_lambda123:;{Object t = def_var_val(c_str_to_datum("|primitive-procedure-objects|"));
                                   object_free(&val);val = t;}object_free(&val);val = make_compiled_procedure(&&entry100);goto after_lambda99;entry100:env = compiled_procedure_env();
                          env = extend_environment(c_str_to_datum("()"));object_free(&proc);proc = make_compiled_procedure(&&entry108);goto after_lambda107;entry108:env = compiled_procedure_env();
                          env = extend_environment(c_str_to_datum("(|initial-env| . ())"));save(cont);save(env);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|define-variable!|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|initial-env|"));argl = cons(object_copy(val),empty);object_free(&val);val = lookup_var_val(c_str_to_datum("|quote|"));argl = cons(object_copy(val), argl);object_free(&val);val = c_str_to_datum("|quote|");argl = cons(object_copy(val), argl);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch120;}cont.cont = &&after_call119;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch120:;object_free(&val);val = proc.proc(argl); after_call119:;object_free(&env);env =restore();object_free(&cont);cont =restore();save(cont);save(env);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|define-variable!|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|initial-env|"));argl = cons(object_copy(val),empty);object_free(&val);val = lookup_var_val(c_str_to_datum("|lambda|"));argl = cons(object_copy(val), argl);object_free(&val);val = c_str_to_datum("|lambda|");argl = cons(object_copy(val), argl);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch118;}cont.cont = &&after_call117;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch118:;object_free(&val);val = proc.proc(argl); after_call117:;object_free(&env);env =restore();object_free(&cont);cont =restore();save(cont);save(env);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|define-variable!|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|initial-env|"));argl = cons(object_copy(val),empty);object_free(&val);val = lookup_var_val(c_str_to_datum("|define|"));argl = cons(object_copy(val), argl);object_free(&val);val = c_str_to_datum("|define|");argl = cons(object_copy(val), argl);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch116;}cont.cont = &&after_call115;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch116:;object_free(&val);val = proc.proc(argl); after_call115:;object_free(&env);env =restore();object_free(&cont);cont =restore();save(cont);save(env);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|define-variable!|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|initial-env|"));argl = cons(object_copy(val),empty);object_free(&val);val = lookup_var_val(c_str_to_datum("|set!|"));argl = cons(object_copy(val), argl);object_free(&val);val = c_str_to_datum("|set!|");argl = cons(object_copy(val), argl);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch114;}cont.cont = &&after_call113;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch114:;object_free(&val);val = proc.proc(argl); after_call113:;object_free(&env);env =restore();object_free(&cont);cont =restore();save(cont);save(env);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|define-variable!|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|initial-env|"));argl = cons(object_copy(val),empty);object_free(&val);val = lookup_var_val(c_str_to_datum("|if|"));argl = cons(object_copy(val), argl);object_free(&val);val = c_str_to_datum("|if|");argl = cons(object_copy(val), argl);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch112;}cont.cont = &&after_call111;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch112:;object_free(&val);val = proc.proc(argl); after_call111:;object_free(&env);env =restore();object_free(&cont);cont =restore();save(cont);save(env);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|define-variable!|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|initial-env|"));argl = cons(object_copy(val),empty);object_free(&val);val = lookup_var_val(c_str_to_datum("|begin|"));argl = cons(object_copy(val), argl);object_free(&val);val = c_str_to_datum("|begin|");argl = cons(object_copy(val), argl);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch110;}cont.cont = &&after_call109;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch110:;object_free(&val);val = proc.proc(argl); after_call109:;object_free(&env);env =restore();object_free(&cont);cont =restore();object_free(&val);val = lookup_var_val(c_str_to_datum("|initial-env|"));goto *cont.cont;after_lambda107:;save(cont);save(proc);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|extend-environment|"));save(proc);object_free(&val);val = lookup_var_val(c_str_to_datum("|the-empty-environment|"));argl = cons(object_copy(val),empty);save(env);save(argl);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|primitive-procedure-objects|"));argl = empty;if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch102;}cont.cont = &&after_call101;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch102:;object_free(&val);val = proc.proc(argl); after_call101:;object_free(&argl);argl =restore();argl = cons(object_copy(val), argl);object_free(&env);env =restore();save(argl);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|primitive-procedure-names|"));argl = empty;if (proc.type == PROC_APPLY) {
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
                 goto *val.cont;primitive_branch106:;object_free(&val);val = proc.proc(argl); after_call105:;argl = cons(object_copy(val),empty);object_free(&proc);proc =restore();object_free(&cont);cont =restore();if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch122;}object_free(&val);
                    val = compiled_procedure_entry(proc);
                    goto *val.cont;primitive_branch122:;object_free(&val);val = proc.proc(argl); goto *cont.cont;after_lambda99:;{Object t = def_var_val(c_str_to_datum("|setup-environment|"));
                                   object_free(&val);val = t;}save(cont);save(env);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|setup-environment|"));argl = empty;if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch98;}cont.cont = &&after_call97;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch98:;object_free(&val);val = proc.proc(argl); after_call97:;object_free(&env);env =restore();{Object t = def_var_val(c_str_to_datum("|the-global-environment|"));
                                   object_free(&val);val = t;}object_free(&cont);cont =restore();object_free(&val);val = c_str_to_datum("\"> \"");{Object t = def_var_val(c_str_to_datum("|input-prompt|"));
                                   object_free(&val);val = t;}object_free(&val);val = c_str_to_datum("\"=> \"");{Object t = def_var_val(c_str_to_datum("|output-prompt|"));
                                   object_free(&val);val = t;}save(cont);save(env);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|current-input-port|"));argl = empty;if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch96;}cont.cont = &&after_call95;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch96:;object_free(&val);val = proc.proc(argl); after_call95:;object_free(&env);env =restore();{Object t = def_var_val(c_str_to_datum("|input-port|"));
                                   object_free(&val);val = t;}object_free(&cont);cont =restore();save(cont);save(env);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|current-output-port|"));argl = empty;if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch94;}cont.cont = &&after_call93;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch94:;object_free(&val);val = proc.proc(argl); after_call93:;object_free(&env);env =restore();{Object t = def_var_val(c_str_to_datum("|output-port|"));
                                   object_free(&val);val = t;}object_free(&cont);cont =restore();object_free(&val);val = make_compiled_procedure(&&entry72);goto after_lambda71;entry72:env = compiled_procedure_env();
                          env = extend_environment(c_str_to_datum("()"));save(cont);save(env);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|prompt-for-input|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|input-prompt|"));argl = cons(object_copy(val),empty);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch92;}cont.cont = &&after_call91;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch92:;object_free(&val);val = proc.proc(argl); after_call91:;object_free(&env);env =restore();object_free(&cont);cont =restore();save(cont);save(env);object_free(&proc);proc = make_compiled_procedure(&&entry78);goto after_lambda77;entry78:env = compiled_procedure_env();
                          env = extend_environment(c_str_to_datum("(|input| . ())"));object_free(&proc);proc = make_compiled_procedure(&&entry82);goto after_lambda81;entry82:env = compiled_procedure_env();
                          env = extend_environment(c_str_to_datum("(|output| . ())"));save(cont);save(env);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|announce-output|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|output-prompt|"));argl = cons(object_copy(val),empty);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch86;}cont.cont = &&after_call85;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch86:;object_free(&val);val = proc.proc(argl); after_call85:;object_free(&env);env =restore();object_free(&cont);cont =restore();object_free(&proc);proc = lookup_var_val(c_str_to_datum("|user-print|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|output|"));argl = cons(object_copy(val),empty);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch84;}object_free(&val);
                    val = compiled_procedure_entry(proc);
                    goto *val.cont;primitive_branch84:;object_free(&val);val = proc.proc(argl); goto *cont.cont;after_lambda81:;save(cont);save(proc);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|eval|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|the-global-environment|"));argl = cons(object_copy(val),empty);object_free(&val);val = lookup_var_val(c_str_to_datum("|input|"));argl = cons(object_copy(val), argl);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch80;}cont.cont = &&after_call79;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch80:;object_free(&val);val = proc.proc(argl); after_call79:;argl = cons(object_copy(val),empty);object_free(&proc);proc =restore();object_free(&cont);cont =restore();if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch88;}object_free(&val);
                    val = compiled_procedure_entry(proc);
                    goto *val.cont;primitive_branch88:;object_free(&val);val = proc.proc(argl); goto *cont.cont;after_lambda77:;save(proc);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|read|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|input-port|"));argl = cons(object_copy(val),empty);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch76;}cont.cont = &&after_call75;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch76:;object_free(&val);val = proc.proc(argl); after_call75:;argl = cons(object_copy(val),empty);object_free(&proc);proc =restore();if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch90;}cont.cont = &&after_call89;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch90:;object_free(&val);val = proc.proc(argl); after_call89:;object_free(&env);env =restore();object_free(&cont);cont =restore();object_free(&proc);proc = lookup_var_val(c_str_to_datum("|driver-loop|"));argl = empty;if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch74;}object_free(&val);
                    val = compiled_procedure_entry(proc);
                    goto *val.cont;primitive_branch74:;object_free(&val);val = proc.proc(argl); goto *cont.cont;after_lambda71:;{Object t = def_var_val(c_str_to_datum("|driver-loop|"));
                                   object_free(&val);val = t;}object_free(&val);val = make_compiled_procedure(&&entry68);goto after_lambda67;entry68:env = compiled_procedure_env();
                          env = extend_environment(c_str_to_datum("(|string| . ())"));object_free(&proc);proc = lookup_var_val(c_str_to_datum("|display|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|output-port|"));argl = cons(object_copy(val),empty);object_free(&val);val = lookup_var_val(c_str_to_datum("|string|"));argl = cons(object_copy(val), argl);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch70;}object_free(&val);
                    val = compiled_procedure_entry(proc);
                    goto *val.cont;primitive_branch70:;object_free(&val);val = proc.proc(argl); goto *cont.cont;after_lambda67:;{Object t = def_var_val(c_str_to_datum("|prompt-for-input|"));
                                   object_free(&val);val = t;}object_free(&val);val = make_compiled_procedure(&&entry64);goto after_lambda63;entry64:env = compiled_procedure_env();
                          env = extend_environment(c_str_to_datum("(|string| . ())"));object_free(&proc);proc = lookup_var_val(c_str_to_datum("|display|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|output-port|"));argl = cons(object_copy(val),empty);object_free(&val);val = lookup_var_val(c_str_to_datum("|string|"));argl = cons(object_copy(val), argl);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch66;}object_free(&val);
                    val = compiled_procedure_entry(proc);
                    goto *val.cont;primitive_branch66:;object_free(&val);val = proc.proc(argl); goto *cont.cont;after_lambda63:;{Object t = def_var_val(c_str_to_datum("|announce-output|"));
                                   object_free(&val);val = t;}object_free(&val);val = make_compiled_procedure(&&entry8);goto after_lambda7;entry8:env = compiled_procedure_env();
                          env = extend_environment(c_str_to_datum("(|object| . ())"));save(cont);save(env);save(env);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|error-object?|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|object|"));argl = cons(object_copy(val),empty);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch62;}cont.cont = &&after_call61;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch62:;object_free(&val);val = proc.proc(argl); after_call61:;object_free(&env);env =restore();if(val.type==BOOLEAN && !val.boolean){
                        goto false_branch12;}save(env);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|display|"));object_free(&val);val = c_str_to_datum("\"Error: \"");argl = cons(object_copy(val),empty);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch60;}cont.cont = &&after_call59;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch60:;object_free(&val);val = proc.proc(argl); after_call59:;object_free(&env);env =restore();save(env);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|display|"));save(proc);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|error-object-message|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|object|"));argl = cons(object_copy(val),empty);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch56;}cont.cont = &&after_call55;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch56:;object_free(&val);val = proc.proc(argl); after_call55:;argl = cons(object_copy(val),empty);object_free(&proc);proc =restore();if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch58;}cont.cont = &&after_call57;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch58:;object_free(&val);val = proc.proc(argl); after_call57:;object_free(&env);env =restore();object_free(&val);val = make_compiled_procedure(&&entry38);goto after_lambda37;entry38:env = compiled_procedure_env();
                          env = extend_environment(c_str_to_datum("(|objs| . ())"));save(cont);save(env);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|not|"));save(proc);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|null?|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|objs|"));argl = cons(object_copy(val),empty);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch52;}cont.cont = &&after_call51;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch52:;object_free(&val);val = proc.proc(argl); after_call51:;argl = cons(object_copy(val),empty);object_free(&proc);proc =restore();if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch54;}cont.cont = &&after_call53;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch54:;object_free(&val);val = proc.proc(argl); after_call53:;object_free(&env);env =restore();object_free(&cont);cont =restore();if(val.type==BOOLEAN && !val.boolean){
                        goto false_branch40;}save(cont);save(env);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|display|"));object_free(&val);val = c_str_to_datum("\" \"");argl = cons(object_copy(val),empty);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch50;}cont.cont = &&after_call49;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch50:;object_free(&val);val = proc.proc(argl); after_call49:;object_free(&env);env =restore();object_free(&cont);cont =restore();save(cont);save(env);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|write|"));save(proc);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|car|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|objs|"));argl = cons(object_copy(val),empty);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch46;}cont.cont = &&after_call45;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch46:;object_free(&val);val = proc.proc(argl); after_call45:;argl = cons(object_copy(val),empty);object_free(&proc);proc =restore();if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch48;}cont.cont = &&after_call47;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch48:;object_free(&val);val = proc.proc(argl); after_call47:;object_free(&env);env =restore();object_free(&cont);cont =restore();object_free(&proc);proc = lookup_var_val(c_str_to_datum("|iter|"));save(cont);save(proc);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|cdr|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|objs|"));argl = cons(object_copy(val),empty);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch42;}cont.cont = &&after_call41;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch42:;object_free(&val);val = proc.proc(argl); after_call41:;argl = cons(object_copy(val),empty);object_free(&proc);proc =restore();object_free(&cont);cont =restore();if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch44;}object_free(&val);
                    val = compiled_procedure_entry(proc);
                    goto *val.cont;primitive_branch44:;object_free(&val);val = proc.proc(argl); goto *cont.cont;false_branch40:;object_free(&val);val = undef;goto *cont.cont;after_lambda37:;{Object t = def_var_val(c_str_to_datum("|iter|"));
                                   object_free(&val);val = t;}object_free(&proc);proc = lookup_var_val(c_str_to_datum("|iter|"));save(proc);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|error-objects|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|object|"));argl = cons(object_copy(val),empty);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch34;}cont.cont = &&after_call33;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch34:;object_free(&val);val = proc.proc(argl); after_call33:;argl = cons(object_copy(val),empty);object_free(&proc);proc =restore();if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch36;}cont.cont = &&after_if11;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch36:;object_free(&val);val = proc.proc(argl); goto after_if11;false_branch12:;save(env);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|primitive-procedure?|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|object|"));argl = cons(object_copy(val),empty);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch32;}cont.cont = &&after_call31;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch32:;object_free(&val);val = proc.proc(argl); after_call31:;object_free(&env);env =restore();if(val.type==BOOLEAN && !val.boolean){
                        goto false_branch14;}object_free(&proc);proc = lookup_var_val(c_str_to_datum("|display|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|output-port|"));argl = cons(object_copy(val),empty);object_free(&val);val = c_str_to_datum("|#<primitive-procedure>|");argl = cons(object_copy(val), argl);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch30;}cont.cont = &&after_if13;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch30:;object_free(&val);val = proc.proc(argl); goto after_if13;false_branch14:;save(env);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|compound-procedure?|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|object|"));argl = cons(object_copy(val),empty);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch28;}cont.cont = &&after_call27;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch28:;object_free(&val);val = proc.proc(argl); after_call27:;object_free(&env);env =restore();if(val.type==BOOLEAN && !val.boolean){
                        goto false_branch16;}save(env);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|display|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|output-port|"));argl = cons(object_copy(val),empty);object_free(&val);val = c_str_to_datum("|#<compound-procedure |");argl = cons(object_copy(val), argl);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch26;}cont.cont = &&after_call25;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch26:;object_free(&val);val = proc.proc(argl); after_call25:;object_free(&env);env =restore();save(env);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|write|"));save(proc);object_free(&val);val = lookup_var_val(c_str_to_datum("|output-port|"));argl = cons(object_copy(val),empty);save(argl);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|procedure-parameters|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|object|"));argl = cons(object_copy(val),empty);if (proc.type == PROC_APPLY) {
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
                 goto *val.cont;primitive_branch24:;object_free(&val);val = proc.proc(argl); after_call23:;object_free(&env);env =restore();object_free(&proc);proc = lookup_var_val(c_str_to_datum("|write|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|output-port|"));argl = cons(object_copy(val),empty);object_free(&val);val = c_str_to_datum("|>|");argl = cons(object_copy(val), argl);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch20;}cont.cont = &&after_if15;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch20:;object_free(&val);val = proc.proc(argl); goto after_if15;false_branch16:;object_free(&proc);proc = lookup_var_val(c_str_to_datum("|write|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|output-port|"));argl = cons(object_copy(val),empty);object_free(&val);val = lookup_var_val(c_str_to_datum("|object|"));argl = cons(object_copy(val), argl);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch18;}cont.cont = &&after_call17;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch18:;object_free(&val);val = proc.proc(argl); after_call17:;after_if15:;after_if13:;after_if11:;object_free(&env);env =restore();object_free(&cont);cont =restore();object_free(&proc);proc = lookup_var_val(c_str_to_datum("|newline|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|output-port|"));argl = cons(object_copy(val),empty);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch10;}object_free(&val);
                    val = compiled_procedure_entry(proc);
                    goto *val.cont;primitive_branch10:;object_free(&val);val = proc.proc(argl); goto *cont.cont;after_lambda7:;{Object t = def_var_val(c_str_to_datum("|user-print|"));
                                   object_free(&val);val = t;}save(cont);save(env);object_free(&proc);proc = lookup_var_val(c_str_to_datum("|eval|"));object_free(&val);val = lookup_var_val(c_str_to_datum("|the-global-environment|"));argl = cons(object_copy(val),empty);object_free(&val);val = c_str_to_datum("(|load| . (\"compound_procedures.scm\" . ()))");argl = cons(object_copy(val), argl);if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch6;}cont.cont = &&after_call5;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch6:;object_free(&val);val = proc.proc(argl); after_call5:;object_free(&env);env =restore();object_free(&cont);cont =restore();object_free(&proc);proc = lookup_var_val(c_str_to_datum("|driver-loop|"));argl = empty;if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch4;}object_free(&val);
                    val = compiled_procedure_entry(proc);
                    goto *val.cont;primitive_branch4:;object_free(&val);val = proc.proc(argl); goto *cont.cont;after_lambda1:;argl = empty;if (proc.type == PROC_APPLY) {
                     proc = apply_proc();
                     argl = apply_argl();
                   }
                   if (proc.type == PROC) { goto primitive_branch2264;}cont.cont = &&after_call2263;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;primitive_branch2264:;object_free(&val);val = proc.proc(argl); after_call2263:;printf("=> ");object_write_stdout(val);puts("");}