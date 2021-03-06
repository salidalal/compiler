%{
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <stdarg.h>
#include <malloc.h>
#include "node.c"






Node * tree;
int size =0;



int yylex(void);
void yyerror(char*);
extern char* yytext;
char * concat (const char* s1, const char* s2);

#define YYSTYPE struct Node *
%} 
/*
%union{
	char* val;
	Node* pNode;
}


%type <val> real string char int return_va
%type <pNode> program code code_pros func proc main get_arg args_list yes_args no_args args call_args args_2 arg_type
%type <pNode> continue_func proc_id continue_proc body the_ret statment statments statmentss semico var_decls ids initign_statment
%type <pNode> if_statment else_statment while_statment for_statment for_cond init conditions block block_body expression lhs value
%type <pNode> type id ref call len boolean null 
*/

%token TYPE_BOOL TYPE_CHAR TYPE_INT TYPE_REAL TYPE_STRING INT_PTR CHAR_PTR REAL_PTR
%token IF ELSE WHILE FOR
%token PROC FUNC VAR MAIN
%token RETURN TYPE_NULL ';' ':' ','
%token BOOL_TRUE BOOL_FALSE REAL ID INT CHAR STRING
%token AND DIVIDE EQ EQEQ GT GTE LT LTE MINUS NOT NOTEQ OR PLUS MUL AMP DEREF
%token '{' '}' '(' ')' '[' ']'


%left NOTEQ EQ ';' ','
%left GT GTE LT LTE EQEQ NOT
%left '{' '}' '(' ')' '['']'
%left DEREF OR AND AMP
%left MINUS PLUS MUL DIVIDE
%start program
%%

program:			code { }
				;

code:	 			code_pros main {addToTree($2,tree);}
				;

code_pros:			code_pros proc	{addToTree($2,tree);}
				|	code_pros func {addToTree($2,tree);}
				|	/*epsilon*/
				;

func: 				FUNC proc_id '(' get_arg ')' RETURN continue_func {$$=makeNode("FUNC",$2,$4,$7,NULL);}
				;



proc: 				PROC proc_id '(' get_arg ')' continue_proc {$$=makeNode("PROC",$2,$4,$6,NULL);};

main:				PROC MAIN '(' ')' continue_proc { $$=makeNode("MAIN",$5,NULL); };



//=================PARAMETERS LIST=================

get_arg:			args_list {  $1->value="ARGS"; $$=$1; }
				;

args_list:			no_args{ $$ = $1; }
				|	yes_args{ if($1->size>1){Node*temp = makeNode("",NULL); fixRec($1,temp); fixFix(temp); $1=temp;} $$ = $1; }
				;
yes_args:			args ':' arg_type { Node*temp = makeNode("",NULL);  fixRec($1,temp); fixFix($1); $$ = makeNode("",$3,temp,NULL); }							
				|	yes_args ';' args ':' arg_type { Node*temp = makeNode("",NULL); fixRec($3,temp); fixFix(temp);
													$$=makeNode("REC ARGS", makeNode("",$5,temp,NULL),$1, NULL);}
				;

args:				id {$$=$1;}
				|	args ',' id { $$=makeNode("REC ARGS",$3,$1,NULL);}
				;
no_args:			/*epsilon*/ {$$=makeNode("NONE",NULL);}
				;

call_args:			args_2 { if($1->size>1){ Node*temp = makeNode("",NULL); fixRec($1,temp); fixFix(temp); $1=temp;} $$ = $1; }
				|	no_args { $$ = $1; }
				;

args_2:				expression {$$=$1;}
				|	args_2 ',' expression { $$=makeNode("REC ARGS",$3,$1,NULL);}
				;

arg_type: 			type {$$=$1;}
				;



//==================proc and func body===============================

continue_func:		return_va '{' body the_ret '}' { Node*temp = makeNode("",NULL); fixRec($3,temp); fixFix(temp); $$ = makeNode("BODY", $1,temp,$4,NULL);}
				;

proc_id: 			id {$$=$1;}
				;

continue_proc:		'{' body '}' { Node*temp = makeNode("BODY",NULL); fixRec($2,temp); fixFix(temp);  $$ = temp; }
				;


body:				statments {$$=$1;}
				;


return_va:			TYPE_INT {$$=makeNode("RET INT", NULL);}
				|	TYPE_CHAR {$$=makeNode("RET CHAR", NULL);}
				|	TYPE_BOOL  {$$=makeNode("RET BOOL", NULL);}
				|	TYPE_REAL  {$$=makeNode("RET REAL", NULL);}
				|	INT_PTR  {$$=makeNode("RET INT*", NULL);}
				|	CHAR_PTR  {$$=makeNode("RET CHAR*", NULL);}
				|	REAL_PTR {$$=makeNode("RET REAL*", NULL);}
				;

the_ret:			RETURN expression ';' {$$=makeNode("RET",$2,NULL); }
				;



//statment======================================================


statment:				call semico {$$=$1;}
					|	if_statment 	{$$ = $1;}				
					|	for_statment  {$$=$1;}
					|	while_statment {$$=$1;}
					|	initign_statment  {$$=$1;}
					|	var_decls {  $1->value="VAR"; $$=$1; }
					|	'{' statments '}'	{$2->value="BLOCK"; $$=$2;}
					| 	/*epsilon*/ {}
					|	func {$$=$1;}
					|	proc {$$ =$1;}
					;

semico:					';'
					;					

statments:				statmentss {Node*temp = makeNode("",NULL); fixRec($1,temp); fixFix(temp); $$ = temp;}
					;

statmentss:				statmentss statment {$$=makeNode("REC ARGS",$1,$2, NULL);}
					|	statment	{ $$=$1;}
					;








var_decls:				VAR ids ':' type ';' {Node*temp = makeNode("",NULL); fixRec($2,temp); fixFix(temp); $$ = makeNode("",$4,temp,NULL);}
					;

ids: 					ids ',' id {$$=makeNode("REC ARGS",$3,$1,NULL);}
					|	id {$$=$1;}
					;

initign_statment:		lhs EQ expression semico {$$=makeNode("=",$1,$3,NULL); }
					;

					

if_statment:			IF '(' expression ')' block else_statment {$$=makeNode("",makeNode("IF",$3,$5,NULL), $6,NULL );}
					;

else_statment:			ELSE block { $$= makeNode("ELSE",$2,NULL); }
					|	/*epsilon*/{$$=NULL;};
					;

while_statment:			WHILE '(' expression ')' block {$$=makeNode("WHILE",$3,$5,NULL);}
					;

for_statment:			FOR '(' for_cond ')' block { $$=makeNode("FOR",$3,$5,NULL);}
					;

for_cond:				init conditions semico init {$$=makeNode("",$1,$2,$4,NULL);}
					;

init:					lhs EQ expression  {$$=makeNode("=",$1,$3,NULL); }
					;


conditions:			|	conditions GT conditions {$$=makeNode(">",$1,$3,NULL);}
					|	conditions GTE conditions {$$=makeNode(">=" ,$1,$3,NULL);}
					|	conditions LT conditions {$$=makeNode("<",$1,$3,NULL);}
					|	conditions LTE conditions {$$=makeNode("<=",$1,$3,NULL);}
					|	conditions NOT conditions {$$=makeNode("!",$1,$3,NULL);}
					|	conditions NOTEQ conditions {$$=makeNode("!=",$1,$3,NULL);}
					|	conditions OR conditions {$$=makeNode("||",$1,$3,NULL);}	
					|	conditions AND conditions {$$=makeNode("&&",$1,$3,NULL);}
					|	'(' expression ')' {$$=$1;}
					|	value {$$=$1;}	
					;


block: 					{$$=NULL;}	
					|	'{' statments '}' {$2->value="BLOCK"; $$=$2;}
					;

	

expression:				expression PLUS expression {$$=makeNode("+",$1,$3,NULL);}
					|	expression MINUS expression {$$=makeNode("-",$1,$3,NULL);}
					|	expression MUL expression {$$=makeNode("*",$1,$3,NULL);}
					|	expression DIVIDE expression {$$=makeNode("/",$1,$3,NULL);}
					|	expression EQEQ expression {$$=makeNode("==",$1,$3,NULL);}
					|	expression GT expression {$$=makeNode(">",$1,$3,NULL);}
					|	expression GTE expression {$$=makeNode(">=",$1,$3,NULL);}
					|	expression LT expression {$$=makeNode("<",$1,$3,NULL);}
					|	expression LTE expression {$$=makeNode("<=",$1,$3,NULL);}
					|	expression NOT expression {$$=makeNode("!",$1,$3,NULL);}
					|	expression NOTEQ expression {$$=makeNode("!=",$1,$3,NULL);}
					|	expression OR expression {$$=makeNode("||",$1,$3,NULL);}	
					|	expression AND expression {$$=makeNode("&&",$1,$3,NULL);}	
					|	value {$$=$1;}
					;


lhs :					id {$$ = $1; }
					|	ID '[' expression ']' {$$ = makeNode("ARR",makeNode((char*)$1,NULL),$3,NULL);}
					;


value:					id | boolean | string | char | real | int | len | call | ref | null
					;

type:					TYPE_INT {$$=makeNode("INT",NULL);}
					|	TYPE_BOOL {$$=makeNode("BOOL",NULL);}
					|	TYPE_CHAR {$$=makeNode("CHAR",NULL);}
					|	TYPE_REAL {$$=makeNode("REAL",NULL);}
					|	TYPE_STRING {$$=makeNode("STRING",NULL);}
					|	INT_PTR {$$=makeNode("INT*",NULL);}
					|	CHAR_PTR {$$=makeNode("CHAR*",NULL);}
					|	REAL_PTR {$$=makeNode("REAL*",NULL);}
					;

id:						ID {$$=makeNode((char*)$1,NULL) ; }
					|	DEREF ID { $$=makeNode((char*)$1,makeNode((char*)$2,NULL),NULL); }
					;

ref:					AMP ID { $$=makeNode((char*)$1,makeNode((char*)$2,NULL),NULL); }					
					;
					

call:					id '(' call_args ')'  { $$ = makeNode("CALL",$1,makeNode("ARGS",$3,NULL),NULL); }
					;

len:					'|' id '|' { $$=makeNode("LEN",$2,NULL); }
					|	'|' string '|' { $$=makeNode("STRING LEN",$2,NULL); }
					;

boolean:				BOOL_TRUE {$$=makeNode("TRUE",NULL);}
					|	BOOL_FALSE {$$=makeNode("FALSE",NULL);}
					;

string:					STRING {$$=makeNode(yytext,NULL);};
char:					CHAR {$$=makeNode(yytext,NULL);};
real:					REAL {$$=makeNode(yytext,NULL);};
int:					INT {$$=makeNode(yytext,NULL); };
null:					TYPE_NULL  {$$=makeNode(yytext,NULL); };
%%	

#include "lex.yy.c"
int main(){
	tree= makeNode("CODE", NULL);
	return yyparse();
	 closeTree(tree);
}







void yyerror(char* s){
	printf("%s: at line %d found token [%s] \n",s,counter,yytext);
}

char * concat (const char* s1, const char* s2) {
	char *result =(char*) malloc(strlen(s1)+strlen(s2)+1);
	strcpy(result,s1);
	strcat(result,s2);
	return result;
}
