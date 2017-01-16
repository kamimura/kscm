%option noyywrap 
%x STR BV
%{
/** \file  */
#include "char.h"
#include "byte.h"

#include "parse.tab.h"

char *real;
char imag_sgn;

%}
 
one    [\x00-\x7f]
two   ([\xc2-\xdf][\x80-\xbf])
three ([\xe0-\xef][\x80-\xbf]{2})
four  ([\xf0-\xf4][\x80-\xbf]{3})
multi ({two}|{three}|{four})

intraline_whitespace [ \t]
whitespace ({intraline_whitespace}|{line_ending})
line_ending ("\n"|"\r\n"|"\r")
initial ([a-zA-Z!$%&*/:<=>?^_~]|{multi})

any_character_other_than_vertical_line_or_backslash (([\x00-\xff]{-}[|\\])|{multi})
subsequent ({initial}|[0-9]|{special_subsequent})
hex_scalar_value ([0-9a-fA-F]+)
mnemonic_escape ("\\a"|"\\b"|"\\t"|"\\n"|"\\r")
peculiar_identifier (({explicit_sign})|({explicit_sign}{sign_subsequent}{subsequent}*)|({explicit_sign}"."{dot_subsequent}{subsequent}*)|("."{dot_subsequent}{subsequent})*)
dot_subsequent ({sign_subsequent}|".")
explicit_sign ("+"|"-")
special_subsequent ({explicit_sign}|"."|"@")
inline_hex_escape ("\\"[xX]{hex_scalar_value}";")
sign_subsequent ({initial}|{explicit_sign}|"@")
symbol_element ({any_character_other_than_vertical_line_or_backslash}|{inline_hex_escape}|{mnemonic_escape}|"\\|")
%%

{line_ending} {}

 /* atmosphere  */
{whitespace}* {}
";".*{line_ending} {}
"#|"[\x00-\xff]*"|#" {}
"#;" { return LEX_SHARP_SEMICOLON;}

"(" |
")" |
"'" |
"." {
  return yytext[0];
}

"#(" { return LEX_SHARP_OP; }
"#u8(" { BEGIN BV; return LEX_SHARP_U_EIGHT_OP; }

{initial}([0-9a-zA-Z!$%&*/:<=>?^_~.@+-]|{multi})* {
  yylval.o = symbol_new(yytext); return LEX_SYMBOL;
}
"|"{initial}([0-9a-zA-Z!$%&*/:<=>?^_~.@+-]|{multi})*"|" {
  yytext[yyleng - 1] = '\0';
  yytext++;
  yylval.o = symbol_new(yytext); return LEX_SYMBOL;
}
{peculiar_identifier} {
  yylval.o = symbol_new(yytext); return LEX_SYMBOL;  
}
"|"{peculiar_identifier}"|" {
  yytext[yyleng - 1] = '\0';
  yytext++;
  yylval.o = symbol_new(yytext); return LEX_SYMBOL;
}
"|"{symbol_element}*"|" {
  yytext[yyleng - 1] = '\0';
  yytext++;
  yylval.o = symbol_vertical_new(yytext); return LEX_SYMBOL;
}
"#"[tT]([rR][uU][eE])? { yylval.o = boolean_true; return LEX_BOOLEAN;}
"#"[fF]([aA][lL][sS][eE])? {;yylval.o = boolean_false; return LEX_BOOLEAN;}

"#\\"({one}|{multi}) {
  yytext += 2;
  yylval.o = char_new(yytext); return LEX_CHARACTER;
}
"#\\alarm" {
  yylval.o = char_new("\x07"); return LEX_CHARACTER;
}
"#\\backspace" {
  yylval.o = char_new("\x08"); return LEX_CHARACTER;
}
"#\\delete" {
  yylval.o = char_new("\x7f"); return LEX_CHARACTER;
}
"#\\escape" {
  yylval.o = char_new("\x1b"); return LEX_CHARACTER;
}
"#\\newline" {
  yylval.o = char_new("\xa"); return LEX_CHARACTER;
}
"#\\null" {
  yylval.o = char_new("\x00"); return LEX_CHARACTER;
}
"#\\return" {
  yylval.o = char_new("\r"); return LEX_CHARACTER;
}
"#\\space" {
  yylval.o = char_new(" "); return LEX_CHARACTER;
}
"#\\tab" {
  yylval.o = char_new("\t"); return LEX_CHARACTER;
}
"#\\x"{hex_scalar_value} {
  yytext += 3;
  char *endptr = NULL;
  uintmax_t ui = strtoumax(yytext, &endptr, 16);
  if (ui == UINTMAX_MAX || ui > 0xffffffff ) {
    /* yyerror("unicode: overflow"); */
  } else {
    yylval.o = (Object){.type=CHAR, .ch=ui};
    return LEX_CHARACTER;
  }
}
"\"" {
  BEGIN STR;
  return '"';
}
<STR>(([\x00-\xff]{-}[\x22\x5c])|{multi}) {  
  yylval.o = char_new(yytext);
  return LEX_STRING_ELEMENT;
}
<STR>"\\a" { yylval.o = (Object){.type=CHAR, .ch=0x07}; return LEX_STRING_ELEMENT;}
<STR>"\\b" { yylval.o = (Object){.type=CHAR, .ch=0x08}; return LEX_STRING_ELEMENT;}
<STR>"\\t" { yylval.o = (Object){.type=CHAR, .ch=0x09}; return LEX_STRING_ELEMENT;}
<STR>"\\n" { yylval.o = (Object){.type=CHAR, .ch=0x0a}; return LEX_STRING_ELEMENT;}
<STR>"\\r" { yylval.o = (Object){.type=CHAR, .ch=0x0d}; return LEX_STRING_ELEMENT;}
<STR>"\\\"" {yylval.o = (Object){.type=CHAR, .ch=0x22}; return LEX_STRING_ELEMENT;}
<STR>"\\\\" { yylval.o = (Object){.type=CHAR, .ch=0x5c}; return LEX_STRING_ELEMENT;}
<STR>"\\"{intraline_whitespace}*{line_ending}{intraline_whitespace}* {
  
}
<STR>{inline_hex_escape} {  
  yytext[yyleng - 1] = '\0';
  yytext += 2;
  char *endptr = NULL;
  uintmax_t ui = strtoumax(yytext, &endptr, 16);
  if (ui == UINTMAX_MAX || ui > 0xffffffff ) {
    /* yyerror("unicode: overflow"); */
  } else {
    yylval.o = (Object){.type=CHAR, .ch=ui};
    return LEX_STRING_ELEMENT;
  }
}
<STR>"\"" {
  BEGIN INITIAL;
  return '"';
}
"#b""-"?[01]*("/1"[01]*)? {
  yytext += 2;
  yylval.o = rational_new(yytext, 2);
  return LEX_EXACT;
}
"#o""-"?[0-7]*("/"[1-7][0-7]*)? {
  yytext += 2;
  yylval.o = rational_new(yytext, 8);
  return LEX_EXACT;
}
"#d"?"-"?[0-9]*("/"[1-9][0-9]*)? {
  if (yytext[0] == '#') {
    yytext += 2;
  }
  yylval.o = rational_new(yytext, 10);
  return LEX_EXACT;
}

"#x""-"?[0-9a-fA-F]*("/"[1-9a-fA-F][0-9a-fA-F]*)? {
  yytext += 2;
  yylval.o = rational_new(yytext, 16);
  return LEX_EXACT;
}
<BV>[0-9] |
<BV>[1-9][0-9] |
<BV>1[0-9][0-9] |
<BV>2[0-4][0-9] |
<BV>25[0-5] { yylval.o = byte_new(yytext); return LEX_BYTE;}
<BV>")" { BEGIN INITIAL; return yytext[0];}

<<EOF>> {
  yylval.o = (Object){.type=EOF_OBJ};
  return LEX_EOF;
}

. {
  printf("lex: lineno: %d ??? '%c' '%x' '%d' \n",
         yylineno, yytext[0], yytext[0], yytext[0]);
}
%%
void yyerror(char  *msg) {
    fprintf(stderr, "yyerror: '%s' '%s'\n", msg, yytext);
}

void f() {
    yyunput(10, "a");
    printf("%p\n", input);
}

extern Object input_obj;
Object c_str_to_datum(char const *s) {
    yy_scan_string(s);
    yyparse();
    return input_obj;
}
Object number_to_string(Object args) {
    Object o1 = carref(argl);
    char *s = NULL;
    if (o1.type == COMPLEX) {        
        asprintf(&s, "%lf%f+lfi", creal(o1.z), cimag(o1.z));
        yy_scan_string(s);    
        yyparse();
        free(s);
    } else if (o1.type == RATIONAL) {
        if (mpz_cmp_ui(mpq_denref(o1.rational), 1) == 0) {
            gmp_asprintf(&s, "\"%Zd\"", mpq_numref(o1.rational));
        } else {
            gmp_asprintf(&s, "\"%Qd\"", o1.rational);
        }
        yy_scan_string(s);    
        yyparse();
        g_free(s);
    }
    return input_obj;
}

Object object_read(Object args) {
  Object o = carref(argl);
  FILE *t = cur_input;
  cur_input = o.port;
  yyrestart(cur_input);  
  yyparse();
  cur_input = t;
  yyrestart(cur_input); 
  return input_obj;
}
