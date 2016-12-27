#include "syntax.h"

static void write(FILE *stream, char *s) { fprintf(stream, "#<syntax %s>", s); }
static void quote_write(Object o, FILE *stream) { write(stream, "quote"); }
static void lambda_write(Object o, FILE *stream) { write(stream, "lambda"); }
static void if_write(Object o, FILE *stream) { write(stream, "if"); }
static void define_write(Object o, FILE *stream) { write(stream, "define"); }
static void set_write(Object o, FILE *stream) { write(stream, "set!"); }
static void begin_write(Object o, FILE *stream) { write(stream, "begin"); }
static void and_write(Object o, FILE *stream) { write(stream, "and"); }
static void or_write(Object o, FILE *stream) { write(stream, "or"); }

#include "env.h"    // def_var_val
#include "symbol.h" // symbol_new
void syntax_init() {

  fn_of_obj_file of_obj_file_vs[] = {quote_write, lambda_write, define_write,
                                     if_write,    set_write,    begin_write,
                                     and_write,   or_write,     NULL};
  Type ts[] = {QUOTE, LAMBDA, DEFINE, IF, SET, BEGIN_OBJ, AND_OBJ, OR_OBJ};
  for (size_t i = 0; of_obj_file_vs[i] != NULL; i++) {
    put_of_obj_file(object_write, ts[i], of_obj_file_vs[i]);
  }

  char const *names[] = {"quote", "lambda", "define", "if", "set!",
                         "begin", "and",    "or",     NULL};
  for (size_t i = 0; names[i] != NULL; i++) {
    val = (Object){.type = ts[i]};
    def_var_val(symbol_new(names[i]));
  }
}
