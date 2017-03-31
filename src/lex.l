%option noyywrap 
%x IMG STRINGELM BV SYMBOLV
%{
/** \file  */
#include "obj.h"
#include "parse.tab.h"

void yyerror(char  *msg);

char sgn;
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

{whitespace}* {}
";".*{line_ending} {}

"(" |
")" | 
"'" |
"." { return yytext[0];}

"#(" { return LEX_OP; }

"+i" { yylval.p = znew_fr("1"); return LEX_Z;}
"-i" { yylval.p = znew_fr("-1"); return LEX_Z;}

{initial}([0-9a-zA-Z!$%&*/:<=>?^_~.@+-]|{multi})* {
  yylval.p = symnew(yytext); return LEX_SYM;
}
"|"{initial}([0-9a-zA-Z!$%&*/:<=>?^_~.@+-]|{multi})*"|" {
  yytext[yyleng - 1] = '\0';
  yytext++;
  yylval.p = symnew(yytext); return LEX_SYM;
}
{peculiar_identifier} {
  yylval.p = symnew(yytext); return LEX_SYM;  
}
"|"{peculiar_identifier}"|" {
  yytext[yyleng - 1] = '\0';
  yytext++;
  yylval.p = symnew(yytext); return LEX_SYM;
}
"|" {
  BEGIN SYMBOLV;
}
<SYMBOLV>{any_character_other_than_vertical_line_or_backslash} {
  yylval.p = cnewuc(g_utf8_get_char(yytext));
  return LEX_SYMV;
}
<SYMBOLV>{inline_hex_escape} {
  yytext[yyleng - 1] = '\0';
  yytext += 2;
  yylval.p = cnewuc(strtol(yytext, NULL, 16));
  return LEX_SYMV;
}
<SYMBOLV>"\\a" { yylval.p = cnewuc('\a'); return LEX_SYMV; }
<SYMBOLV>"\\b" { yylval.p = cnewuc('\b'); return LEX_SYMV; }
<SYMBOLV>"\\t" { yylval.p = cnewuc('\t'); return LEX_SYMV; }
<SYMBOLV>"\\n" { yylval.p = cnewuc('\n'); return LEX_SYMV; }
<SYMBOLV>"\\r" { yylval.p = cnewuc('\r'); return LEX_SYMV; }
<SYMBOLV>"\\|" { yylval.p = cnewuc('|'); return LEX_SYMV; }
<SYMBOLV>"|" {
  BEGIN INITIAL;
  return LEX_SYMV_END;
}
"#"[tT]([rR][uU][eE])? {
  yylval.p = true_ptr;
  return LEX_BOOL;
}
"#"[fF]([aA][lL][sS][eE])? {
  yylval.p = false_ptr;
  return LEX_BOOL;
}
"#\\"({one}|{multi}) {
  yytext += 2;
  yylval.p = cnewuc(g_utf8_get_char(yytext));
  return LEX_CHAR;
}
"#\\alarm" { yylval.p = cnewuc('\a'); return LEX_CHAR;}
"#\\backspace" { yylval.p = cnewuc('\b'); return LEX_CHAR;}
"#\\delete" { yylval.p = cnewuc(0x7f); return LEX_CHAR;}
"#\\escape" { yylval.p = cnewuc(0x1b); return LEX_CHAR;}
"#\\newline" { yylval.p = cnewuc('\n'); return LEX_CHAR;}
"#\\null" { yylval.p = cnewuc('\0'); return LEX_CHAR;}
"#\\return" { yylval.p = cnewuc('\r'); return LEX_CHAR;}
"#\\space" { yylval.p = cnewuc(' '); return LEX_CHAR;}
"#\\tab" { yylval.p = cnewuc('\t'); return LEX_CHAR;}
"#\\x"{hex_scalar_value} {
  yytext += 3;
  yylval.p = cnewuc(strtol(yytext, NULL, 16));
  return LEX_CHAR;
}
"\"" {
  BEGIN STRINGELM;
}
<STRINGELM>(([\x00-\xff]{-}[\"\\])|{multi}) {
  yylval.p = cnewuc(g_utf8_get_char(yytext));
  return LEX_STRELM;
}
<STRINGELM>"\\a" { yylval.p = cnewuc('\a'); return LEX_STRELM; }
<STRINGELM>"\\b" { yylval.p = cnewuc('\b'); return LEX_STRELM; }
<STRINGELM>"\\t" { yylval.p = cnewuc('\t'); return LEX_STRELM; }
<STRINGELM>"\\n" { yylval.p = cnewuc('\n'); return LEX_STRELM; }
<STRINGELM>"\\r" { yylval.p = cnewuc('\r'); return LEX_STRELM; }
<STRINGELM>"\\\"" { yylval.p = cnewuc('"'); return LEX_STRELM; }
<STRINGELM>"\\\\" { yylval.p = cnewuc('\\'); return LEX_STRELM; }
<STRINGELM>{inline_hex_escape} {
  yytext[yyleng - 1] = '\0';
  yytext += 2;
  yylval.p = cnewuc(strtol(yytext, NULL, 16));
  return LEX_STRELM;
}
<STRINGELM>"\"" {
  BEGIN INITIAL;
  yylval.p = strempty_ptr;
  return LEX_STRELM_END;
}

"-"?[0-9]+ {
  yylval.p = qnew(yytext);
  return LEX_Q;
}
"-"?[0-9]+"/"[1-9][0-9]* {
  yylval.p = qnew(yytext);
  return LEX_Q;
}
"-"?[0-9]+"."[0-9]* {
  yylval.p = znewfr(yytext);
  return LEX_Z;
}
"-"?[0-9]+("+"|"-") {
  BEGIN IMG;
  sgn = yytext[yyleng - 1];
  yytext[yyleng - 1] = '\0';
  zreal(yytext);
}
"-"?[0-9]+"/"[1-9][0-9]*("+"|"-") {
  BEGIN IMG;
  sgn = yytext[yyleng - 1];
  yytext[yyleng - 1] = '\0';
  zrealq(yytext);
}
"-"?[0-9]+"."[0-9]*("+"|"-") {
  BEGIN IMG;
  sgn = yytext[yyleng - 1];
  yytext[yyleng - 1] = '\0';
  zreal(yytext);
}
<IMG>[0-9]*"i" {
  BEGIN INITIAL;
  if (yyleng == 1) {
    yylval.p = znew_fr_fr(sgn, "1");
    return LEX_Z;
  }
  yytext[yyleng - 1] = '\0';
  yylval.p = znew_fr_fr(sgn, yytext);
  return LEX_Z;
}
<IMG>[0-9]+"/"[1-9][0-9]*"i" {
  BEGIN INITIAL;
  yytext[yyleng - 1] = '\0';
  yylval.p = znew_fr_q(sgn, yytext);
  return LEX_Z;
}
<IMG>[0-9]+"."[0-9]*"i" {
  BEGIN INITIAL;
  yytext[yyleng - 1] = '\0';
  yylval.p = znew_fr_fr(sgn, yytext);
  return LEX_Z;
}

("-"|"+")[0-9]*"i" {
  if (yyleng == 2) {
    yylval.p = yytext[0] == '+' ? znew_fr("1") : znew_fr("-1");
    return LEX_Z;
  }
  yytext[yyleng - 1] = '\0';
  if (yytext[0] == '+') yytext++;
  yylval.p = znew_fr(yytext);
  return LEX_Z;
}
("-"|"+")[0-9]+"/"[1-9][0-9]*"i" {
  yytext[yyleng - 1] = '\0';
  if (yytext[0] == '+') yytext++;
  yylval.p = znew_q(yytext);
  return LEX_Z;
}
("-"|"+")[0-9]+"."[0-9]*"i" {
  yytext[yyleng - 1] = '\0';
  if (yytext[0] == '+') yytext++;
  yylval.p = znew_fr(yytext);
  return LEX_Z;
}

<<EOF>> {
  yylval.p = eof_ptr;
  return LEX_EOF;
}
. {yyerror("(flex)");}
%%
void yyerror(char  *msg) {
    fprintf(stderr, "yyerror: %s '%s' lineno: %d\n", msg, yytext, yylineno);
    exit(1);
}

extern ObjPtr inop;
ObjPtr cread() {
    yyparse();
    return inop;
}

/* for -Wall */
void unneeded() {
    yyunput(0, NULL);
    input();
    }
