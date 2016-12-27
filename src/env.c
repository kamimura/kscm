#include "env.h"

void add_bind_to_frame(Object var, Object frame) {
  if (var.type != SYMBOL && var.type != SYMBOL_VERTICAL) {
    fprintf(stderr, "add_bind_to_frame\n");
    object_writeln_stdout(var);
    exit(1);
  }
  save(frame);
  Object t = cons(var, carref(frame));
  frame = restore();
  set_car(frame, t);
  save(frame);
  t = cons(object_copy(val), cdrref(frame));
  frame = restore();
  set_cdr(frame, t);
  if (frame.type != PAIR) {
    fprintf(stderr, "%s: %s: %d\n", __FILE__, __FUNCTION__, __LINE__);
    object_writeln_stdout(frame);
    exit(1);
  }
}

Object lookup_var_val(Object obj) {
  if (env.type != PAIR && env.type != EMPTY) {
    fprintf(stderr, "not env: %s: %s\n", __FUNCTION__, obj.symbol);
    exit(1);
  }
  for (Object o = env; o.type != EMPTY; o = cdrref(o)) {
    Object frame = carref(o);
    if (frame.type != PAIR) {
      fprintf(stderr, "%s:%s:frame.type:%d\n"
                      "var: '%s'\n",
              __FILE__, __FUNCTION__, frame.type, obj.symbol);
      puts("frame:");
      object_writeln_stdout(frame);
      puts("env");
      object_writeln_stdout(env);
      exit(1);
    }
    Object vars = carref(frame);
    Object vals = cdrref(frame);
    for (; vars.type == PAIR;) {
      Object var = carref(vars);
      if (var.type != SYMBOL && var.type != SYMBOL_VERTICAL) {
        fprintf(stderr, "Error: lookup_var_val: '%s'\n", obj.symbol);
        printf("var: not symbol: %d\n", var.type);
        puts("var");
        object_writeln_stdout(var);
        puts("vars");
        object_writeln_stdout(vars);
        puts("vals");
        object_writeln_stdout(vals);
        puts("obj");
        object_writeln_stdout(obj);
        puts("env");
        object_writeln_stdout(env);
        exit(1);
      }
      if (var.symbol == obj.symbol) {
        return car(vals);
      }
      vars = cdrref(vars);
      vals = cdrref(vals);
    }
    if ((vars.type == SYMBOL || vars.type == SYMBOL_VERTICAL) &&
        (vars.symbol == obj.symbol)) {
      return vals;
    }
  }
  fprintf(stderr, "error: unbound variable -- %s\n", obj.symbol);
  exit(1);
}

#include <string.h>
Object def_var_val(Object const var) {
  if (carref(env).type != PAIR) {
    fprintf(stderr, "%s: %s: %d\n", __FILE__, __FUNCTION__, __LINE__);
    object_writeln_stdout(carref(env));
    exit(1);
  }
  if (var.type != SYMBOL && var.type != SYMBOL_VERTICAL) {
    fprintf(stderr, "error: def_var_val\n");
    object_writeln_stdout(var);
    exit(1);
  }
  Object frame = carref(env);
  if (frame.type != PAIR) {
    fprintf(stderr, "%s: %s: %d\n", __FILE__, __FUNCTION__, __LINE__);
    object_writeln_stdout(carref(env));
    exit(1);
  }
  Object vars = carref(frame);
  Object vals = cdrref(frame);
  for (; vars.type == PAIR;) {
    if (var.symbol == carref(vars).symbol) {
      set_car(vals, val);
      return undef;
    }
    if ((cdrref(vars).type == SYMBOL || cdrref(vars).type == SYMBOL_VERTICAL) &&
        var.symbol == cdrref(vars).symbol) {
      set_cdr(vals, val);
      return undef;
    }
    vars = cdrref(vars);
    vals = cdrref(vals);
  }
  add_bind_to_frame(var, frame);
  return undef;
}
Object set_var_val(Object const var) {
  if (var.type != SYMBOL && var.type != SYMBOL_VERTICAL) {
    fprintf(stderr, "error: set_var_val\n");
    object_writeln_stdout(var);
    exit(1);
  }
  for (Object o1 = env; o1.type == PAIR; o1 = cdrref(o1)) {
    Object frame = carref(o1);
    if (frame.type != PAIR) {
      fprintf(stderr, "%s: %s: %d\n", __FILE__, __FUNCTION__, __LINE__);
      object_writeln_stdout(carref(env));
      exit(1);
    }
    Object vars = carref(frame);
    Object vals = cdrref(frame);
    for (; vars.type == PAIR;) {
      if (var.symbol == carref(vars).symbol) {
        set_car(vals, val);
        return undef;
      }
      if ((cdrref(vars).type == SYMBOL ||
           cdrref(vars).type == SYMBOL_VERTICAL) &&
          var.symbol == cdrref(vars).symbol) {
        set_cdr(vals, val);
        return undef;
      }
      vars = cdrref(vars);
      vals = cdrref(vals);
    }
  }
  fprintf(stderr, "error: unbound variable -- %s", var.symbol);
  exit(1);
}

static bool list_p(Object o) {
  Object t = o;
  for (; t.type == PAIR; t = cdrref(t)) {
  }
  return t.type == EMPTY;
}
static size_t length(Object o) {
  size_t len = 0;
  for (Object t = o; t.type != EMPTY; t = cdrref(t)) {
    len++;
  }
  return len;
}
static bool symbol_all_p(Object o) {
  Object t = o;
  for (; t.type == PAIR; t = cdrref(t)) {
    if (carref(t).type != SYMBOL && carref(t).type != SYMBOL_VERTICAL) {
      return false;
    }
  }
  if (t.type == EMPTY || t.type == SYMBOL || t.type == SYMBOL_VERTICAL) {
    return true;
  }
  fprintf(stderr, "%s: %s: %d\n", __FILE__, __FUNCTION__, __LINE__);
  object_writeln_stdout(o);
  exit(1);
  return false;
}
static Object make_frame(Object vars, Object vals) {
  if (symbol_all_p(vars)) {
    return cons(vars, vals);
  }

  fprintf(stderr, "make_frame:\n");
  exit(1);
}
Object extend_environment(Object params) {
  if (carref(env).type != PAIR) {
    fprintf(stderr, "%s: %s: %d\n", __FILE__, __FUNCTION__, __LINE__);
    object_writeln_stdout(env);
    exit(1);
  }
  if (params.type == SYMBOL || params.type == SYMBOL_VERTICAL) {
    Object t1 = cons(params, empty);
    Object t2 = cons(argl, empty);
    return cons(make_frame(t1, t2), env);
  }
  if (params.type == EMPTY) {
    if (argl.type == EMPTY) {
      return cons(make_frame(empty, empty), env);
    }
    fprintf(stderr, "%s: %s: %d\n", __FILE__, __FUNCTION__, __LINE__);
    object_writeln_stdout(env);
    exit(1);
  }
  if (list_p(params) && (length(params) != length(argl))) {
    fprintf(stderr, "make_frame: %lu %lu\n", length(params), length(argl));
    object_writeln_stdout(params);
    object_writeln_stdout(argl);
    exit(1);
  }
  if (params.type == PAIR && symbol_all_p(params)) {
    return cons(make_frame(params, argl), env);
  }
  fprintf(stderr, "error extend_environment\n"
                  "params type: %d\n",
          params.type);
  object_writeln_stdout(params);
  object_writeln_stdout(argl);
  exit(1);
}

#include "symbol.h" // symbol_new
void env_init() {
  Object vars = empty;
  Object vals = empty;
  env = cons(make_frame(vars, vals), empty);
  if (carref(env).type != PAIR) {
    fprintf(stderr, "%s: %s: %d\n", __FILE__, __FUNCTION__, __LINE__);
    object_writeln_stdout(carref(env));
    exit(1);
  }
}
