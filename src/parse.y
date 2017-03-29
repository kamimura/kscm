%{
/** \file  */
#include "obj.h"

extern int yylex (void);
extern void yyerror(char  *msg);

ObjPtr inop;
%}

%union {
  ObjPtr p;
  }

                        
%token
                        LEX_SHARP

%token  <p>             LEX_Q
                        LEX_Z
                        LEX_SYM
                        LEX_SYMV
                        LEX_SYMV_END
                        LEX_BOOL
                        LEX_CHAR
                        LEX_STRELM_END
                        LEX_STRELM
                        LEX_EOF
                        

%type   <p>             datum
                        datum_asterisk
                        simple_datum
                        symbol
                        symbolv
                        boolean
                        character
                        string
                        string_element                        
                        number
                        compound_datum
                        list
                        dotted_list
                        tail
                        abbreviation                      
%%
program:        datum
                {
                    inop = $1;
                    YYACCEPT;
                }
        ;
datum:          simple_datum
        |       compound_datum
        ;
datum_asterisk: {$$ = empty_ptr;}
        |       datum datum_asterisk
                {
                    $$ = pnew($1, $2);
                }
        ;
simple_datum:   boolean
        |       number
        |       symbol
        |       character
        |       string
        |       LEX_EOF
        ;
symbol:         LEX_SYM
        |       symbolv
                {
                    char *s = cscmstr_to_utf8($1);
                    $$ = symvnew(s);
                }
        ;
symbolv:        LEX_SYMV_END
                {
                    $$ = strempty_ptr;
                }
        |       LEX_SYMV symbolv
                {
                    $$ = strnew($1, $2);
                }
        ;
boolean:        LEX_BOOL
        ;
character:      LEX_CHAR
        ;
string:         string_element
                {
                    $$ = $1;
                }
        ;
string_element:
                LEX_STRELM_END
        |       LEX_STRELM string_element
                {
                    $$ = strnew($1, $2);
                }
        ;
number:         LEX_Q
        |       LEX_Z
        ;
compound_datum: list
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
                    $$ = pnew($1, $3);
                }
        |       datum tail
                {
                    $$ = pnew($1, $2);
                }
        ;
abbreviation:   '\'' datum
                {
                    $$ = pnew(quote_ptr, pnew($2, empty_ptr));
                }
        ;
%%
