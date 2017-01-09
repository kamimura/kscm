#include "memory.h"

static const size_t MEMORY_SIZE = 1000000;
static Object *cars = NULL;
static Object *cdrs = NULL;
static bool *marks = NULL;

static size_t free_index = 0;

static void gc();
Object cons_obj;
Object cons(Object o1, Object o2) {
  object_free(&cars[free_index]);
  object_free(&cdrs[free_index]);
  cars[free_index] = o1;
  cdrs[free_index] = o2;
  cons_obj = (Object){.type = PAIR, .index = free_index};
  marks[free_index] = true;
  free_index++;
  if (free_index == MEMORY_SIZE) {
    gc();
  } else {
    for (; marks[free_index];) {
      free_index++;
      if (free_index == MEMORY_SIZE) {
        gc();
      }
    }
  }
  return cons_obj;
}
Object carref(Object o) { return cars[o.index]; }
Object cdrref(Object o) { return cdrs[o.index]; }
Object car(Object o) { return object_copy(cars[o.index]); }
Object cdr(Object o) { return object_copy(cdrs[o.index]); }

void set_car(Object o1, Object o2) {
  object_free(&cars[o1.index]);
  cars[o1.index] = o2;
}
void set_cdr(Object o1, Object o2) {
  object_free(&cdrs[o1.index]);
  cdrs[o1.index] = o2;
}

Object stack;
void save(Object o) { stack = cons(o, stack); }
Object restore() {
  if (stack.type == EMPTY) {
    fprintf(stderr, "%s:%s:%d\n", __FILE__, __FUNCTION__, __LINE__);
    exit(1);
  }
  Object o = car(stack);
  stack = cdrref(stack);
  return o;
}

void memory_init() {
  cars = g_new0(Object, MEMORY_SIZE);
  cdrs = g_new0(Object, MEMORY_SIZE);
  marks = g_new0(bool, MEMORY_SIZE);
  stack = empty;
}

static bool tree_p(Object o) {
  Type t = o.type;
  return t == PAIR || t == STRING || t == PROC_COMPILED || t == BYTEVECTOR;
}
Object env = {.type = UNDEF};
Object val = {.type = UNDEF};
Object cont = {.type = UNDEF};
Object proc = {.type = UNDEF};
Object argl = {.type = UNDEF};
Object yacc_obj = {.type = EMPTY};
Object cmd_line_list = {.type = EMPTY};
static void mark(Object o) {
  GSList *slist = NULL;
  slist = g_slist_prepend(slist, GSIZE_TO_POINTER(o.index));
  for (; slist;) {
    gsize i = GPOINTER_TO_SIZE(g_slist_nth_data(slist, 0));
    slist = g_slist_next(slist);
    for (Object t = (Object){.type = PAIR, .index = i}; tree_p(t);
         t = carref(t)) {
      if (marks[t.index]) {
        break;
      }
      marks[t.index] = true;
      if (tree_p(cdrref(t))) {
        slist = g_slist_prepend(slist, GSIZE_TO_POINTER(cdrref(t).index));
      }
    }
  }
}

void gc() {
  for (size_t i = 0; i < MEMORY_SIZE; i++) {
    marks[i] = false;
  }
  Object objs[] = {stack, env,      val,      proc,
                   argl,  cons_obj, yacc_obj, cmd_line_list};
  for (size_t i = 0; i < 8; i++) {
    if (tree_p(objs[i])) {
      mark(objs[i]);
    }
  }
  free_index = 0;
  for (; marks[free_index];) {
    free_index++;
    if (free_index == MEMORY_SIZE) {
      fprintf(stderr, "insufficient memory\n");
      exit(1);
    }
  }
}
