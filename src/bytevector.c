
#include "bytevector.h"

#include <string.h> // strlen, strdup

Object bytevector_new(Object byte_list) {
  size_t len = 0;
  for (Object o = byte_list; o.type != EMPTY; o = cdrref(o)) {
    len++;
  }
  uint8_t *s = malloc(sizeof(uint8_t) * len);
  for (size_t i = 0; i < len; i++) {
    s[i] = carref(byte_list).byte;
    byte_list = cdrref(byte_list);
  }
  Object out = cons((Object){.type = BYTEVECTOR_LENGTH, .len = len},
                    (Object){.type = BYTES, .bytes = s});
  out.type = BYTEVECTOR;
  return out;
}
static void bytes_free(Object *o_ptr) { g_free(o_ptr->bytes); }
static bool eqv_p(Object o1, Object o2) { return o1.index == o2.index; }
static void write(Object o, FILE *s) {
  fprintf(s, "#u8(");
  size_t len = carref(o).len;
  uint8_t *bytes = cdrref(o).bytes;
  if (len != 0) {
    for (size_t i = 0;;) {
      fprintf(s, "%u", bytes[i]);
      i++;
      if (i == len) {
        break;
      } else {
        fprintf(s, " ");
      }
    }
  }
  fprintf(s, ")");
}

static Object bytevector(Object args) {
  size_t len = 0;
  for (Object o = argl; o.type != EMPTY; o = cdrref(o)) {
    len++;
  }
  uint8_t *bytes = malloc(sizeof(uint8_t) * len);
  Object o = argl;
  for (size_t i = 0; i < len; i++) {
    Object byte = carref(o);
    bytes[i] = mpz_get_ui(mpq_numref(byte.rational));
    o = cdrref(o);
  }
  Object out = cons((Object){.type = BYTEVECTOR_LENGTH, .len = len},
                    (Object){.type = BYTES, .bytes = bytes});
  out.type = BYTEVECTOR;
  return out;
}
static Object bytevector_append(Object args) {
  size_t len = 0;
  for (Object o = argl; o.type != EMPTY; o = cdrref(o)) {
    Object bv = carref(o);
    len += carref(bv).len;
  }
  uint8_t *bytes = malloc(sizeof(uint8_t) * len);
  size_t i = 0;
  for (Object o = argl; o.type != EMPTY; o = cdrref(o)) {
    Object bv = carref(o);
    size_t len = carref(bv).len;
    Object b = cdrref(bv);
    for (size_t j = 0; j < len; j++) {
      bytes[i] = b.bytes[j];
      i++;
    }
  }
  Object out = cons((Object){.type = BYTEVECTOR_LENGTH, .len = len},
                    (Object){.type = BYTES, .bytes = bytes});
  out.type = BYTEVECTOR;
  return out;
}
static Object bytevector_copy(Object args) {
  uint8_t *bytes0 = cdrref(carref(argl)).bytes;
  size_t start = mpz_get_ui(mpq_numref(carref(cdrref(argl)).rational));
  size_t end = mpz_get_ui(mpq_numref(carref(cdrref(cdrref(argl))).rational));
  size_t len = end - start;
  uint8_t *bytes = malloc(sizeof(uint8_t) * len);
  size_t i = 0;
  for (size_t j = start; j < end; j++) {
    bytes[i] = bytes0[j];
    i++;
  }
  Object out = cons((Object){.type = BYTEVECTOR_LENGTH, .len = len},
                    (Object){.type = BYTES, .bytes = bytes});
  out.type = BYTEVECTOR;
  return out;
}

static Object bytevector_length(Object args) {
  size_t len = carref(carref(argl)).len;
  Object out = {.type = RATIONAL};
  mpq_init(out.rational);
  mpq_set_ui(out.rational, len, 1);
  return out;
}
static Object bytevector_u8_ref(Object args) {
  Object bv = carref(argl);
  Object o = carref(cdrref(argl));
  size_t k = mpz_get_ui(mpq_numref(o.rational));
  Object out = {.type = RATIONAL};
  mpq_init(out.rational);
  mpq_set_ui(out.rational, cdrref(bv).bytes[k], 1);
  return out;
}
static Object bytevector_u8_set(Object args) {
  Object bv = carref(argl);
  Object bs = cdrref(bv);
  Object o = carref(cdrref(argl));
  Object b = carref(cdrref(cdrref(argl)));
  size_t k = mpz_get_ui(mpq_numref(o.rational));
  bs.bytes[k] = (uint8_t)mpz_get_ui(mpq_numref(b.rational));
  return undef;
}
static Object make_bytevector(Object args) {
  size_t k = mpz_get_ui(mpq_numref(carref(argl).rational));
  uint8_t byte = mpz_get_ui(mpq_numref(carref(cdrref(argl)).rational));
  uint8_t *bytes = malloc(sizeof(uint8_t) * k);
  for (size_t i = 0; i < k; i++) {
    bytes[i] = byte;
  }
  Object out = cons((Object){.type = BYTEVECTOR_LENGTH, .len = k},
                    (Object){.type = BYTES, .bytes = bytes});
  out.type = BYTEVECTOR;
  return out;
}
#include "scm_string.h" // string_cons
static Object utf8_to_string(Object args) {
  Object bv = carref(argl);
  gunichar *us = g_utf8_to_ucs4((gchar *)cdrref(bv).bytes, carref(bv).len, NULL,
                                NULL, NULL);
  size_t start = mpz_get_ui(mpq_numref(carref(cdrref(argl)).rational));
  size_t end = mpz_get_ui(mpq_numref(carref(cdrref(cdrref(argl))).rational));
  Object out = {.type = STRING_EMPTY};
  for (size_t i = end; i > start; i--) {
    out = string_cons((Object){.type = CHAR, .ch = us[i - 1]}, out);
  }
  g_free(us);
  return out;
}
static Object write_bytevector(Object args) {
  Object bv = carref(argl);
  uint8_t *bytes = cdrref(bv).bytes;
  FILE *port = carref(cdrref(argl)).port;
  size_t start = mpz_get_ui(mpq_numref(carref(cdrref(cdrref(argl))).rational));
  size_t end =
      mpz_get_ui(mpq_numref(carref(cdrref(cdrref(cdrref(argl)))).rational));
  for (size_t i = start; i < end; i++) {
    fprintf(port, "%c", bytes[i]);
  }
  return undef;
}
static Object write_u8(Object args) {
  uint8_t byte = mpz_get_ui(mpq_numref(carref(argl).rational));
  FILE *port = carref(cdrref(argl)).port;
  fprintf(port, "%c", byte);
  return undef;
}
void bytevector_init() {
  fn_of_obj_ptr of_obj_ptr_ks[] = {object_free, NULL};
  fn_of_obj_ptr of_obj_ptr_vs[] = {bytes_free, NULL};
  for (size_t i = 0; of_obj_ptr_ks[i] != NULL; i++) {
    put_of_obj_ptr(of_obj_ptr_ks[i], BYTES, of_obj_ptr_vs[i]);
  }

  fn_obj_of_obj ks1[] = {object_eqv_p, object_eq_p, NULL};
  fn_bool_of_obj_obj vs1[] = {eqv_p, eqv_p, NULL};
  for (size_t i = 0; ks1[i] != NULL; i++) {
    put_bool_of_obj_obj(ks1[i], BYTEVECTOR, BYTEVECTOR, vs1[i]);
  }
  fn_obj_of_obj of_obj_file_ks[] = {object_write, object_display, NULL};
  fn_of_obj_file of_obj_file_vs[] = {write, write, NULL};
  for (size_t i = 0; of_obj_file_ks[i] != NULL; i++) {
    put_of_obj_file(of_obj_file_ks[i], BYTEVECTOR, of_obj_file_vs[i]);
  }
  char const *names[] = {"c-bytevector",
                         "c-bytevector-append",
                         "c-bytevector-copy",
                         "c-bytevector-length",
                         "c-bytevector-u8-ref",
                         "c-bytevector-u8-set!",
                         "c-make-bytevector",
                         "c-utf8->string",
                         "c-write-bytevector",
                         "c-write-u8",
                         NULL};
  fn_obj_of_obj procs[] = {bytevector,
                           bytevector_append,
                           bytevector_copy,
                           bytevector_length,
                           bytevector_u8_ref,
                           bytevector_u8_set,
                           make_bytevector,
                           utf8_to_string,
                           write_bytevector,
                           write_u8,
                           NULL};
  for (size_t i = 0; names[i] != NULL; i++) {
    val = (Object){.type = PROC, .proc = procs[i]};
    def_var_val(symbol_new(names[i]));
  }
}
