%{
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <stdarg.h>
#include <malloc.h>
#include "node.c"
#include "symTbl.c"

Node * tree;
int size =0;
void closeTree();
int yylex(void);
void yyerror(char*);
extern char* yytext;
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

program:			code { 	 closeTree();}
				;

code:	 			code_pros {}
				;

code_pros:			code_pros proc	{addToTree($2,tree);}
				|	code_pros func {addToTree($2,tree);}
				|	code_pros main {addToTree($2,tree);}
				|	/*epsilon*/
				;

func: 				FUNC proc_id '(' get_arg ')' RETURN continue_func {
													$$=makeNode("FUNC",$2,$4,$7->sons[0],$7->sons[1],NULL); }
				;



proc: 				PROC proc_id '(' get_arg ')' continue_proc {$$=makeNode("PROC",$2,$4,$6,NULL);};

main:				PROC MAIN '(' ')' continue_proc { $$=makeNode("Main",$5,NULL); };



//=================PARAMETERS LIST=================

get_arg:			args_list {   $$=$1; }
				;

args_list:			no_args{ $1->value = "ARGS NONE"; $$ = $1; }
				|	yes_args{       if(!strcmp("REC ARGS",$1->value))
										{Node*temp = makeNode("",NULL); fixRec($1,temp);  $1=temp;}
									else
										{$1=makeNode("",$1,NULL);}	
									$1->value="ARGS"; $$ = $1;	  									
							}
				;
				
			
yes_args:			args ':' arg_type {Node*temp = makeNode("",NULL);fixRec($1,temp);  temp->value = $3->value; $$ = temp ; }							
				|	yes_args ';' args ':' arg_type {    Node*temp = makeNode("",NULL);fixRec($3,temp);  temp->value =$5->value; $3 = makeNode($5->value,temp,NULL); 
													$$ = makeNode("REC ARGS",temp,$1,NULL); }
				;

args:				id {$$=$1;}
				|	args ',' id { $$=makeNode("REC ARGS",$3,$1,NULL);}
				;
no_args:			/*epsilon*/ {$$=makeNode("NONE",NULL);}
				;


call_args:			args_2 { if(!strcmp($1->value,"REC ARGS"))
								{Node*temp = makeNode("",NULL);fixRec($1,temp); $$=temp;}
							else
								{$$=makeNode("",$1,NULL);} }
				|	no_args { $$ = $1; }
				;


args_2:				expression {$$=$1; printNode($1,1);}
				|	args_2 ',' expression { $$=makeNode("REC ARGS",$3,$1,NULL);}
				;

arg_type: 			type {$$=$1;}
				;



//==================proc and func body===============================

continue_func:		return_va '{' body  '}' {  $$ = makeNode("BLOCK", makeNode("RET",$1,NULL),$3,NULL);}
				;

proc_id: 			id {$$=$1;}
				;


continue_proc:		'{' body '}' { if(!$2){$2=makeNode("",NULL);} $2->value="BLOCK"; $$=$2;}
				;

body:				statmentss {Node*temp = makeNode("BODY",NULL);fixRec($1,temp); $$=temp;}
				|	/**/ { $$ = NULL;}
				;


return_va:			TYPE_INT {$$=makeNode("INT", NULL);}
				|	TYPE_CHAR {$$=makeNode("CHAR", NULL);}
				|	TYPE_BOOL  {$$=makeNode("BOOL", NULL);}
				|	TYPE_REAL  {$$=makeNode("REAL", NULL);}
				|	INT_PTR  {$$=makeNode("INT*", NULL);}
				|	CHAR_PTR  {$$=makeNode("CHAR*", NULL);}
				|	REAL_PTR {$$=makeNode("REAL*", NULL);}
				| 	TYPE_STRING'['INT']' { $$= makeNode(concat("STRING[",concat((char*)$3,"]")) ,NULL);}
				;

the_ret:			RETURN expression ';' {$$=makeNode("RETURN",$2,NULL); }
				;



//statment======================================================


statment:				call semico {$$=$1;}
					|	if_statment 	{$$ = $1;}				
					|	for_statment  {$$=$1;}
					|	while_statment {$$=$1;}
					|	initign_statment  {$$=$1;}
					|	var_decls {  $1->value="VAR";   $1->sons[0]->sons= $1->sons[1]->sons;
														$1->sons[0]->size= $1->sons[1]->size;  
														$1->sons[1]=NULL; $1->size=1; $$=$1; }

					|	'{' statmentss '}'	{ Node*temp = makeNode("BLOCK",NULL);fixRec($2,temp);   $$=temp;}
//					| 	/*epsilon*/ { $$ = makeNode("EMPTY",NULL);}
					|	the_ret {$$=$1;}
					|	func {$$=$1;}
					|	proc {$$ =$1;}
					;

semico:					';'
					;					


statmentss:				statmentss statment {$$=makeNode("REC ARGS",$2,$1, NULL);}
					|	statment	{ $$=$1;}
					;







var_decls:				VAR ids ':' type ';' {Node*temp = makeNode("LALA1",NULL);fixRec($2,temp); $$=makeNode("LALA2",$4,temp,NULL);}
					;

ids: 					ids ',' id {$$=makeNode("REC ARGS",$3,$1,NULL);}
					|	id {$$=$1;}
					;

initign_statment:		lhs EQ expression semico {$$=makeNode("=",$1,$3,NULL); }
					|	DEREF lhs EQ expression semico {$$=makeNode("=",makeNode("^",$2,NULL),$4,NULL); }

					;

					

if_statment:			IF '(' expression ')' statment else_statment { if($6){$$ = makeNode("IFELSE",$3,$5,$6,NULL);}
																		else {$$ = makeNode("IF",$3,$5,NULL); }   }
					;

else_statment:			ELSE statment { $$= $2; }
					|	/*epsilon*/{$$=NULL;};
					;

while_statment:			WHILE '(' expression ')' block {$$=makeNode("WHILE",$3,$5,NULL);}
					;

for_statment:			FOR '(' for_cond ')' block { $$=makeNode("FOR",$3->sons[0],$3->sons[1],$3->sons[2],$5,NULL);}
					;

for_cond:				init semico expression semico init {$$=makeNode("",$1,$3,$5,NULL);}
					;

init:					lhs EQ expression {$$=makeNode("=",$1,$3,NULL); }
					|	DEREF lhs EQ expression {$$=makeNode("=",makeNode("^",$2,NULL),$4,NULL); }
					;


block: 					statment {$$=$1;}
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
					|	NOT expression {$$=makeNode("!",$2,NULL);}
					|	expression NOTEQ expression {$$=makeNode("!=",$1,$3,NULL);}
					|	expression OR expression {$$=makeNode("||",$1,$3,NULL);}	
					|	expression AND expression {$$=makeNode("&&",$1,$3,NULL);}	
					|	'(' expression ')' {$$=$2;}
					|	value {$$=$1;}
					|	DEREF expression { $$=makeNode("^",$2,NULL); printNode($$,1);}
					| 	AMP expression { $$=makeNode("&",$2,NULL);}; 
					;


lhs :					id {$$ = $1; }
					|	id '[' expression ']' {$$ = makeNode("ARR",makeNode((char*)$1->value,NULL),$3,NULL);}
					;


value:					lhs | boolean | string | char | real | int | len | call  | null
					;

type:					TYPE_INT {$$=makeNode("INT",NULL);}
					|	TYPE_BOOL {$$=makeNode("BOOL",NULL);}
					|	TYPE_CHAR {$$=makeNode("CHAR",NULL);}
					|	TYPE_REAL {$$=makeNode("REAL",NULL);}
					|	TYPE_STRING '['INT']' {$$=makeNode( concat("STRING",concat("[",concat((char*)$3,"]"))) ,NULL);}
					|	INT_PTR {$$=makeNode("INT*",NULL);}
					|	CHAR_PTR {$$=makeNode("CHAR*",NULL);}
					|	REAL_PTR {$$=makeNode("REAL*",NULL);}
					;

id:						ID {$$=makeNode((char*)$1,NULL) ; }

					
					;


				


call:					id '(' call_args ')'  { $1->sons = $3->sons; $1->size = $3->size; $$ = makeNode("CALL",$1,NULL); }
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
null:					TYPE_NULL  {$$=makeNode("NULL",NULL); };
%%	

#include "lex.yy.c"
int main(){
	tree= makeNode("CODE", NULL);
	return yyparse();
}









void yyerror(char* s){
	printf("%s: at line %d found token [%s] \n",s,counter,yytext);
}






void closeTree(){
	changeP(tree);

	printf("\nCode tree:\n");
	printTree(tree);
	initScopes(tree);

	printf("\nScopes:\n");
	//printScopes();
	checks(tree, 1);
    errorSummary();

}