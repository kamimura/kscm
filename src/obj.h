#pragma once
/** \file  */
#include <stdio.h>   // FILE
#include <stdbool.h> // bool
#include <stdlib.h>  // free, malloc
#include <glib.h>    // gunichar
#include <gmp.h>     // mpq_t
#include <mpfr.h>
#include <mpc.h>     // mpc_t

typedef void *Ptr;
typedef enum Type Type;
typedef struct Obj Obj;
typedef Obj *ObjPtr;
typedef struct Pair Pair;
typedef Pair *PairPtr;
typedef struct Proc Proc;
typedef Proc *ProcPtr;
typedef struct Port Port;
typedef Port *PortPtr;
typedef ObjPtr (*fn_type)(ObjPtr);

enum Type {
  EMPTY,
  PAIR,
  SYM,
  SYMV,
  COMPLEX,
  RATIONAL, /* 5 */
  IPORT,
  OPORT,
  IPORT_CLOSED,
  OPORT_CLOSED,
  UNDEF,
  BOOLEAN_TRUE,
  BOOLEAN_FALSE,
  STREMPTY, /* 10 */
  PROC,
  CPROC,
  PROC_APPLY,
  CHAR,
  STR,
  CONT, /* 15 */
  OEOF,
  ERR,
  RERR,
  FERR,
};
struct Obj {
  Type t;
  union {
    PairPtr p;
    char *s;
    mpc_t z;
    mpq_t q;
    PortPtr port;
    ProcPtr proc;
    gunichar uc;
    Ptr ptr;
  };
};
struct Pair {
  ObjPtr l;
  ObjPtr r;
};
struct Proc {
  char *name;
  fn_type fn;
};
struct Port {
  char *name;
  FILE *fh;
};
extern ObjPtr empty_ptr;

extern ObjPtr undef_ptr;
extern ObjPtr true_ptr;
extern ObjPtr false_ptr;
extern ObjPtr strempty_ptr;
extern ObjPtr quote_ptr;
extern ObjPtr eof_ptr;

extern ObjPtr oport;
extern ObjPtr eport;

ObjPtr pnew(ObjPtr l, ObjPtr r);
ObjPtr strnew(ObjPtr l, ObjPtr r);
char *cscmstr_to_utf8(ObjPtr p);

ObjPtr symnew(char *s);
ObjPtr symvnew(char *s);
ObjPtr contnew(Ptr p);

ObjPtr qnew(char *s);
ObjPtr znewfr(char *s);
void zreal(char *s);
void zrealq(char *s);
ObjPtr znew_fr_fr(char sgn, char *s);
ObjPtr znew_fr_q(char sgn, char *s);
ObjPtr znew_fr(char *s);
ObjPtr znew_q(char *s);
ObjPtr znew_s_s(char *s1, char *s);
ObjPtr cnewuc(gunichar uc);

bool err_p(ObjPtr p);
void ewrite(ObjPtr p);

ObjPtr scm_write();

void cdisplay(ObjPtr p, ObjPtr port);
void cwrite(ObjPtr p, ObjPtr port);
extern ObjPtr cread();

ObjPtr cprocnew(Ptr entry, ObjPtr p);
ObjPtr compiled_procedure(ObjPtr p);
ObjPtr compiled_procedure_env(ObjPtr p);
ObjPtr extend_environment(ObjPtr p1, ObjPtr p2, ObjPtr p3);
ObjPtr setup_environment();
ObjPtr define_variable(ObjPtr var, ObjPtr val, ObjPtr env);
ObjPtr set_variable_value(ObjPtr var, ObjPtr val, ObjPtr env);
bool primitive_procedure_p(ObjPtr p);
void save(ObjPtr p);
ObjPtr restore();
ObjPtr lookup_variable_value(ObjPtr var, ObjPtr env);
bool primitive_procedure_p(ObjPtr p);
ObjPtr compiled_procedure_entry(ObjPtr p);

extern ObjPtr scm_argv;

void init();
