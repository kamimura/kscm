#include "port.h"

static bool eqv_p(Object o1, Object o2) { return o1.port == o2.port; }
static Object input_port_open_p(Object args) {
  Object o = carref(args);
  return (o.type == PORT_INPUT_TEXT || o.type == PORT_INPUT_BIN) &&
                 o.port != NULL
             ? boolean_true
             : boolean_false;
}
static Object output_port_open_p(Object args) {
  Object o = carref(args);
  return (o.type == PORT_OUTPUT_TEXT || o.type == PORT_OUTPUT_BIN) &&
                 o.port != NULL
             ? boolean_true
             : boolean_false;
}
FILE *cur_input;
FILE *cur_output;
static Object current_input_port(Object args) {
  return (Object){.type = PORT_INPUT_TEXT, .port = cur_input};
}
static Object current_output_port(Object args) {
  return (Object){.type = PORT_OUTPUT_TEXT, .port = cur_output};
}
static Object current_error_port(Object args) {
  return (Object){.type = PORT_ERROR_TEXT, .port = stderr};
}
#include <string.h> // strdup
static char *string_to_cstring(Object o) {
  size_t len = 0;
  for (Object o0 = o; o0.type != STRING_EMPTY; o0 = cdrref(o0)) {
    len++;
  }
  char s[len * 6 + 1];
  char outbuf[6];
  size_t i = 0;
  for (Object o0 = o; o0.type != STRING_EMPTY; o0 = cdrref(o0)) {
    size_t len = g_unichar_to_utf8(carref(o0).ch, outbuf);
    for (size_t j = 0; j < len; j++) {
      s[i] = outbuf[j];
      i++;
    }
  }
  s[i] = '\0';
  return strdup(s);
}
static FILE *open(Object args, char const *mode) {
  Object o = carref(args);
  char *filename = string_to_cstring(o);
  return fopen(filename, mode);
}
static Object open_input_file(Object args) {
  FILE *f = open(args, "r");
  if (f == NULL) {
    printf("error: open_input_file\n");
    object_write_stdout(args);
    puts("");
    exit(1);
  }
  return (Object){.type = PORT_INPUT_TEXT, .port = f};
}
static Object open_binary_input_file(Object args) {
  FILE *f = open(args, "rb");
  if (f == NULL) {
  }
  return (Object){.type = PORT_INPUT_BIN, .port = f};
}
static Object open_output_file(Object args) {
  FILE *f = open(args, "w");
  if (f == NULL) {
  }
  return (Object){.type = PORT_OUTPUT_TEXT, .port = f};
}
static Object open_binary_output_file(Object args) {
  FILE *f = open(args, "wb");
  if (f == NULL) {
  }
  return (Object){.type = PORT_OUTPUT_BIN, .port = f};
}
static Object close_port(Object args) {
  fclose(carref(args).port);
  return undef;
}
static void port_input_text_write(Object o, FILE *s) {
  fprintf(s, "#<input-textual-port: %p>", o.port);
}
static void port_output_text_write(Object o, FILE *s) {
  fprintf(s, "#<output-textual-port: %p>", o.port);
}
static void port_input_binary_write(Object o, FILE *s) {
  fprintf(s, "#<input-binary-port: %p>", o.port);
}
static void port_output_binary_write(Object o, FILE *s) {
  fprintf(s, "#<output-binary-port: %p>", o.port);
}
static void port_error_write(Object o, FILE *s) {
  fprintf(s, "#<error-port: %p>", o.port);
}
void port_init() {
  Type ts[] = {PORT_INPUT_TEXT, PORT_INPUT_BIN, PORT_OUTPUT_TEXT,
               PORT_OUTPUT_BIN, PORT_ERROR_TEXT};
  size_t ts_len = 5;

  fn_obj_of_obj ks1[] = {object_eqv_p, object_eq_p, NULL};
  fn_bool_of_obj_obj vs1[] = {eqv_p, eqv_p, NULL};
  for (size_t i = 0; ks1[i] != NULL; i++) {
    for (size_t j = 0; j < ts_len; j++) {
      put_bool_of_obj_obj(ks1[i], ts[j], ts[j], vs1[i]);
    }
  }

  fn_obj_of_obj of_obj_file_ks[] = {object_write, object_display, NULL};
  fn_of_obj_file of_obj_file_vs1[] = {port_input_text_write,
                                      port_input_text_write, NULL};
  fn_of_obj_file of_obj_file_vs2[] = {port_output_text_write,
                                      port_output_text_write, NULL};
  fn_of_obj_file of_obj_file_vs3[] = {port_input_binary_write,
                                      port_input_binary_write, NULL};
  fn_of_obj_file of_obj_file_vs4[] = {port_output_binary_write,
                                      port_output_binary_write, NULL};
  fn_of_obj_file of_obj_file_vs5[] = {port_error_write, port_error_write, NULL};
  for (size_t i = 0; of_obj_file_ks[i] != NULL; i++) {
    put_of_obj_file(of_obj_file_ks[i], PORT_INPUT_TEXT, of_obj_file_vs1[i]);
    put_of_obj_file(of_obj_file_ks[i], PORT_OUTPUT_TEXT, of_obj_file_vs2[i]);
    put_of_obj_file(of_obj_file_ks[i], PORT_INPUT_BIN, of_obj_file_vs3[i]);
    put_of_obj_file(of_obj_file_ks[i], PORT_OUTPUT_BIN, of_obj_file_vs4[i]);
    put_of_obj_file(of_obj_file_ks[i], PORT_ERROR_TEXT, of_obj_file_vs5[i]);
  }
  char const *names[] = {"input-port-open?",
                         "output-port-open?",
                         "current-input-port",
                         "current-output-port",
                         "current-error-port",
                         "open-input-file",
                         "open-binary-input-file",
                         "open-output-file",
                         "open-binary-output-file",
                         "close-port",
                         NULL};
  fn_obj_of_obj procs[] = {input_port_open_p,
                           output_port_open_p,
                           current_input_port,
                           current_output_port,
                           current_error_port,
                           open_input_file,
                           open_binary_input_file,
                           open_output_file,
                           open_binary_output_file,
                           close_port,
                           NULL};
  for (size_t i = 0; names[i] != NULL; i++) {
    val = (Object){.type = PROC, .proc = procs[i]};
    def_var_val(symbol_new(names[i]));
  }
  cur_input = stdin;
  cur_output = stdout;
}
