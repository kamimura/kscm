%{
/** \file  */
extern int yylex(void);
extern void yyerror(char *s);

#include "scm_string.h"
#include "bytevector.h"

Object input_obj;
%}

%union {
  Object o;
  }

%token
                        LEX_SHARP_SEMICOLON
                        
%token  <o>             LEX_SHARP_OP
                        LEX_SHARP_U_EIGHT_OP
                        LEX_IDENTIFIER
                        LEX_BOOLEAN
                        LEX_CHARACTER
                        LEX_STRING_ELEMENT
                        LEX_EXACT
                        LEX_INEXACT
                        LEX_SYMBOL
                        LEX_BYTE

                        LEX_EOF

%type   <o>             datum
                        datum_asterisk
                        simple_datum
                        compound_datum
                        number
                        bytevector
                        list
                        dotted_list
                        tail
                        string
                        string_element
                        string_element_asterisk
                        vector
                        abbreviation
                        abbrev_prefix
                        byte_asterisk
                        byte
%%

ptoragm:        datum
                {
                    input_obj = $1;
                    yacc_obj = empty;
                    YYACCEPT;
                }
        ;
datum:          simple_datum
        |       compound_datum
                {
                    yacc_obj = cons($1, yacc_obj);
                }
        |       LEX_SHARP_SEMICOLON datum datum
                {
                    object_free(&$2);
                    $$ = $3;
                }
        ;
datum_asterisk: { $$ = empty; }
        |       datum datum_asterisk
                {
                    $$ = cons($1, $2);
                }
        ;
simple_datum:   LEX_BOOLEAN
        |       number
        |       LEX_CHARACTER
        |       string
        |       LEX_SYMBOL
        |       bytevector
        |       LEX_EOF
        ;
compound_datum: list
        |       vector
        |       abbreviation
        ;
list:           '(' datum_asterisk ')'
                {
                  $$ = $2;
                }
        |       dotted_list
        ;
dotted_list:    '(' tail
                {
                    $$ = $2;
                }
        ;
tail:           datum '.' datum ')'
                {
                    $$ = cons($1, $3);
                }
        |       datum tail
                {
                    $$ = cons($1, $2);
                }
        ;
abbreviation:   abbrev_prefix datum
                {
                    $$ = cons($1, cons($2, empty));
                }
        ;
abbrev_prefix:  '\''
                {                  
                  $$ = symbol_quote;
                }
        ;
vector:         LEX_SHARP_OP datum_asterisk ')'
                {
                }
        ;
string:         '"' string_element_asterisk '"'
                {
                  $$ = $2;
                }
        ;
string_element_asterisk:
                {
                  $$ = (Object){.type=STRING_EMPTY};
                }
        |       string_element string_element_asterisk
                {
                  $$ = string_cons($1, $2);
                }
        ;
string_element: LEX_STRING_ELEMENT
        ;
bytevector:     LEX_SHARP_U_EIGHT_OP byte_asterisk ')'
                {                    
                    $$ = bytevector_new($2);
                }
        ;
byte_asterisk:  { $$ = empty; }
        |       byte byte_asterisk
                {
                    $$ = cons($1, $2);
                }
        ;
byte:           LEX_BYTE
        ;
number:         LEX_EXACT
        |       LEX_INEXACT
        ;
%%
