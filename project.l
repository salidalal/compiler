%{
#include<stdio.h>
#include<stdlib.h>
#include"y.tab.h"
int counter=1;
%}
%x comment
%%
"bool" {return TYPE_BOOL;}
"char" {return TYPE_CHAR;}
"int" {return TYPE_INT;}
"real" {return TYPE_REAL;}
"string" {return TYPE_STRING;}
"int*" {return INT_PTR;}
"char*" {return CHAR_PTR;}
"real*" {return REAL_PTR;}
"if" {return IF;}
"else" {return ELSE;}
"while" {return WHILE;}
"for" {return FOR;}
"var" {return VAR;}
"func" { return FUNC;}
"proc" {return PROC;}
"Main"	{return MAIN;}
"return" {return RETURN;}
"null" {return TYPE_NULL;}
"&&" {return AND;}
"/" {return DIVIDE;}
"=" {return EQ;}
"==" {return EQEQ;}
">" {return GT;}
">=" {return GTE;}
"<" {return LT;}
"<=" {return LTE;}
"-" {return MINUS;}
"!" {return NOT;}
"!=" {return NOTEQ;}
"||" {return OR;}
"+" return PLUS;
"*" {return MUL;}
"&" {return AMP;}
"^" {return DEREF;}
true {return BOOL_TRUE;}
false return BOOL_FALSE;
"{"		{ return '{'; }
"}"		{ return '}' ; }
\(			{ return '('; }
\)			{ return ')'; }
\[			{ return '['; }
\]			{ return ']'; }
";" return ';';
":" return ':';
"," return ',';
0|[-+]?[[1-9][0-9]*]*\.?[0-9]+([eE][-+]?[0-9]+)? { yylval = strdup(yytext); return REAL;}
[a-zA-Z][0-9a-zA-Z_]* { yylval = strdup(yytext); return ID;}
[1-9][0-9]*|0|[0x|0X][0-9A-F]+ { yylval = strdup(yytext); return INT; }
[\'][a-zA-Z0-9][\'] { yylval = strdup(yytext); return CHAR;}
[\"][^\"^\n]*[\"] {  yylval = strdup(yytext); return STRING;}
[ \t] ;
\n ; counter++;
. return yytext[0]; ;
"/%" BEGIN comment;
<comment>[^\n] ;
<comment>\n ;
<comment>"%/" BEGIN 0 ;
%%

int yywrap(void)
{
    return 1;
}
