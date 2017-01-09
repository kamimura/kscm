#include "system.h"
#include "scm_string.h"

void get_command_line(int argc, char *argv[]) {
  for (int i = argc; i > 0; i--) {
    glong items_written;
    gunichar *s = g_utf8_to_ucs4(argv[i - 1], -1, NULL, &items_written, NULL);
    val = (Object){.type = STRING_EMPTY};
    for (glong j = items_written; j > 0; j--) {
      val = string_cons((Object){.type = CHAR, .ch = s[j - 1]}, val);
    }
    cmd_line_list = cons(val, cmd_line_list);
    g_free(s);
  }
}

static Object c_delete_file(Object args) {
  Object o = carref(args);
  glong len = 0;
  for (Object t = o; t.type != STRING_EMPTY; t = cdrref(t)) {
    len++;
  }
  char s[len * 6 + 1];
  size_t i = 0;
  for (size_t j = 0; j < len; j++) {
    char outbuf[6];
    gint len0 = g_unichar_to_utf8(carref(o).ch, outbuf);
    for (size_t k = 0; k < len0; k++) {
      s[i] = outbuf[k];
      i++;
    }
    o = cdrref(o);
  }
  s[i] = '\0';
  remove(s);
  return undef;
}

static Object c_command_line(Object args) {
  check_argl_length("command-line", 0);
  return cmd_line_list;
}
static Object c_run_shell_command(Object args) {
  Object o = carref(argl);
  glong len = 0;
  for (Object t = o; t.type != STRING_EMPTY; t = cdrref(t)) {
    len++;
  }
  char s[len * 6 + 1];
  size_t i = 0;
  for (size_t j = 0; j < len; j++) {
    char outbuf[6];
    gint len0 = g_unichar_to_utf8(carref(o).ch, outbuf);
    for (size_t k = 0; k < len0; k++) {
      s[i] = outbuf[k];
      i++;
    }
    o = cdrref(o);
  }
  s[i] = '\0';
  int n = system(s);
  Object out = {.type = RATIONAL};
  mpq_init(out.rational);
  mpq_set_si(out.rational, n, 1);
  return out;
}

static Object c_exit(Object args) {
  if (argl.type == EMPTY) {
    printf("exit: 0\n");
    exit(0);
  }
  check_argl_length("exit", 1);
  printf("exit: ");
  Object o = carref(argl);
  object_writeln_stdout(o);
  if (o.type == BOOLEAN && o.boolean) {
    exit(0);
  }
  exit(1);
}
void system_init() {
  char const *names[] = {"c-delete-file", "command-line", "run-shell-command",
                         "exit", NULL};
  fn_obj_of_obj procs[] = {c_delete_file, c_command_line, c_run_shell_command,
                           c_exit, NULL};
  for (size_t i = 0; names[i] != NULL; i++) {
    val = (Object){.type = PROC, .proc = procs[i]};
    def_var_val(symbol_new(names[i]));
    val.type = NONE;
  }
}
