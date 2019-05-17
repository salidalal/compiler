%{
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <stdarg.h>
#include <malloc.h>


typedef struct Node{
	struct Node **sons;
	int size;
	struct Node *parent;
	char *value;
} Node;






Node * tree;
int size =0;


void addToTree(Node*,Node*);
Node *makeNode(char *value, ...);
void printNode(Node *tree,int tab);
void printTree();
void fixRec(Node*temp,Node*n);
Node* fixFix(Node*);


void changeP (Node *parent);
void closeTree();

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

program:			code { 	 closeTree();}
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
				|	yes_args{ if($1->size>1){Node*temp = makeNode("",NULL); fixRec($1,temp);  $1=temp;} $$ = $1; }
				;
				
			
yes_args:			args ':' arg_type {Node*temp = makeNode("",NULL);fixRec($1,temp);  $$ = makeNode("",$3,temp,NULL);  }							
				|	yes_args ';' args ':' arg_type {Node*temp = makeNode("",NULL);fixRec($3,temp);  $3 = makeNode("",$5,temp,NULL); 
													$$ = makeNode("REC ARGS",$3,$1); }
				;

args:				id {$$=$1;}
				|	args ',' id { $$=makeNode("REC ARGS",$3,$1,NULL);}
				;
no_args:			/*epsilon*/ {$$=makeNode("NONE",NULL);}
				;



call_args:			args_2 { Node*temp = makeNode("",NULL);fixRec($1,temp); $$=temp; }
				|	no_args { $$ = $1; }
				;

args_2:				expression {$$=$1;}
				|	args_2 ',' expression { $$=makeNode("REC ARGS",$3,$1,NULL);}
				;

arg_type: 			type {$$=$1;}
				;



//==================proc and func body===============================

continue_func:		return_va '{' body the_ret '}' {  $$ = makeNode("BODY", $1,$3,$4,NULL);}
				;

proc_id: 			id {$$=$1;}
				;


continue_proc:		'{' body '}' { $2->value="BODY"; $$=$2;}
				;

body:				statmentss {Node*temp = makeNode("",NULL);fixRec($1,temp); $$=temp;}
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
					|	'{' statmentss '}'	{Node*temp = makeNode("BLOCK",NULL);fixRec($2,temp);   $$=temp;}
					| 	/*epsilon*/ {}
					|	func {$$=$1;}
					|	proc {$$ =$1;}
					;

semico:					';'
					;					

statments:				statmentss {Node*temp = makeNode("",NULL);fixRec($1,temp); $$=temp;}
					;

statmentss:				statmentss statment {$$=makeNode("REC ARGS",$2,$1, NULL);}
					|	statment	{ $$=$1;}
					;







var_decls:				VAR ids ':' type ';' {Node*temp = makeNode("",NULL);fixRec($2,temp); $$=makeNode("",$4,temp,NULL);}
					;

ids: 					ids ',' id {$$=makeNode("REC ARGS",$3,$1,NULL);}
					|	id {$$=$1;}
					;

initign_statment:		lhs EQ expression semico {$$=makeNode("=",$1,$3,NULL); }
					;

					

if_statment:			IF '(' expression ')' statment else_statment {$$=makeNode("",makeNode("IF",$3,$5,NULL), $6,NULL ); }
					;

else_statment:			ELSE statment { $$= makeNode("ELSE",$2,NULL); }
					|	/*epsilon*/{$$=NULL;};
					;

while_statment:			WHILE '(' expression ')' block {$$=makeNode("WHILE",$3,$5,NULL);}
					;

for_statment:			FOR '(' for_cond ')' block { $$=makeNode("FOR",$3,$5,NULL);}
					;

for_cond:				init semico expression semico init {$$=makeNode("",$1,$3,$5,NULL);}
					;

init:					lhs EQ expression {$$=makeNode("=",$1,$3,NULL); }
					;


conditions:			expression 
					;

block: 					'{' '}' {$$=makeNode("EMPTY BLOCK",NULL);}	
					|	'{' statmentss '}' {Node*temp = makeNode("BLOCK",NULL); fixRec($2,temp);   $$=temp;}
					|	statment {$$=$1;}
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
}



void addToTree(Node* son, Node* parent)
{

	int i;
    
    Node **temp = NULL;
    //For first child
    if(parent->size == 0){
        parent->sons = (Node**) malloc (sizeof(Node*));
        (parent->sons)[0] = son;
    }
    else{
        temp = (Node **) malloc (((parent->size) + 1) * (sizeof(Node*)));
        for(i = 0; i < parent->size; i++)
            temp[i] = (parent->sons)[i];
        temp[parent->size] = son;
        free(parent->sons);
        parent->sons = temp;
	}
	(parent->size) ++;
	
}


void printTree(){
	printNode(tree,1);
}


Node *makeNode( char *value, ...)
{
	int i, count = 0;
    va_list countPointer, listPointer;
    Node *newNode = (Node *) malloc (sizeof(Node));
    Node *getArg = NULL;

    //Initializing token
    newNode->value = (char *) malloc ((strlen(value)+1)*sizeof(char));
    strcpy(newNode->value, value);
    //Counting number of arguments passed
    va_start(countPointer, value);
    do{
        getArg = va_arg(countPointer, Node *);
        if(getArg != NULL)
            count++;
    }while(getArg != NULL);

    //Assigining children to array
    if(count != 0){
        newNode->size = count;
        va_start(listPointer, value);
        newNode->sons = (Node**) malloc (count * sizeof(Node *));
        for(i = 0; i < count; i++){
            (newNode->sons)[i] = va_arg(listPointer, Node *);
        }     
    }
    else{
        newNode->sons = NULL;
        newNode->size = 0;
    }
	return newNode;
}


void fixRec(Node*temp,Node*n){


	//printf("-%s-%d\n",temp->value,(strcmp(temp->value,"=")));;

	if(temp->size==0  || !(strcmp(temp->value,"=") == 0)  ){
		addToTree(temp,n);
		return;
	}
	else{
			//printf("-%s-%d\n",temp->value,(strcmp(temp->value,"=")));;

	}

	
	//printf("-%s--%s--%s-\n",temp->value,temp->sons[0]->sons[0]->value,temp->sons[0]->sons[1]->value);
	if  (temp && strcmp(temp->sons[1]->value,"REC ARGS"))
	{
		addToTree(temp->sons[1],n);
		addToTree(temp->sons[0],n);
	}
	else
	{
		fixRec(temp->sons[1],n);
		addToTree(temp->sons[0],n);
	}
}

void printNode(Node *n,int tab)
{
	
    for (int i = 1; i < tab; i++) {
        printf("   ");
    }
    if(n->size!=0)
        printf("(");    
    printf("%s\n", n->value);

    for (int i = 0; i < n->size; i++) {
        printNode((n->sons)[i], tab + 1);
    }
    if(n->size!=0){ 
        for (int i = 1; i < tab; i++) {
            printf("   ");
        }
        printf(")\n\n"); 
	}
	/*

	    int i;

    printf("Node: %s\n", n->value);
    if(n->size == 0)
        printf("No children\n");
    else{
    printf("Children:\n");
    for (i = 0; i < n->size; i++) 
        printf("%s ", (n->sons)[i]->value);
	printf("\n");
    for (i = 0; i < n->size; i++) 
	
        printNode((n->sons)[i],0);
}
	*/
}



void closeTree(){
	changeP(tree);

	printTree();
	changeP(tree);

}



void changeP (Node *parent){
  for(int i=0; i<parent->size; i++){
      parent->sons[i]->parent = parent;
      changeP(parent->sons[i] );
  }
}



Node* fixFix (Node*temp){
	Node* newNode = makeNode(temp->value,NULL);
	for(int i =temp->size -1; i>=0; i--)
		addToTree(temp->sons[i],newNode);
	return newNode;
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
