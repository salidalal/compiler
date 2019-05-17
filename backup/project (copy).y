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

void addToTree(Node*);
Node *makeNode(char *value, ...);
void printNode(Node *tree,int tab);
void printTree();

void fixTree(Node *node);
void changeP (Node *parent);
void closeTree();

int yylex(void);
void yyerror(char*);
extern char* yytext;
char * concat (const char* s1, const char* s2);

#define YYSTYPE struct Node *
%} 

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

program:			code { closeTree();}
				;

code:	 			code_pros main {addToTree($2);}
				;

code_pros:			code_pros proc	{addToTree($2);}
				|	code_pros func {addToTree($2);}
				|	/*epsilon*/
				;

func: 				FUNC proc_id '(' get_arg ')' RETURN continue_func {$$=makeNode("FUNC ",$2,$4,$7,NULL);}
				;



proc: 				PROC proc_id '(' get_arg ')' continue_proc {$$=makeNode("PROC ",$2,$4,$6,NULL);};

main:				PROC MAIN '(' ')' continue_proc { $$=makeNode("MAIN ",$5,NULL); }



//=================PARAMETERS LIST=================

get_arg:			args_list { $$=makeNode("ARGS ",$1,NULL); }
				;

args_list:			no_args{ $$ = $1; }
				|	yes_args{ $$ = $1; }
				;
yes_args:			args ':' arg_type { $$ = makeNode("",$3,$1,NULL); }							
				|	yes_args ';' args ':' arg_type {$$=makeNode("",$1, makeNode("",$4,$3,NULL), NULL);}
				;

args:				id {$$=$1;}
				|	args ',' id {$$=makeNode("",$1,$3,NULL);}
				;
no_args:			/*epsilon*/ {$$=makeNode(" NONE",NULL);}
				;

call_args:			args { $$ = $1; }
				|	no_args { $$ = $1; }
				;

arg_type: 			type {$$=$1;}
				;



//==================proc and func body===============================

continue_func:		return_va '{' body the_ret '}' { $$ = makeNode("BODY ", $1,$3,$4,NULL);}
				;

proc_id: 			id {$$=$1;}
				;

continue_proc:		'{' body '}' {$$=$2;}
				;

body:				/*empty body*/ {$$=NULL;}
				|	body statment {$$=makeNode("",$1,$2,NULL);}
				;


return_va:			TYPE_INT {$$=makeNode("RET INT", NULL);}
				|	TYPE_CHAR {$$=makeNode("RET CHAR", NULL);}
				|	TYPE_BOOL  {$$=makeNode("RET BOOL", NULL);}
				|	TYPE_REAL  {$$=makeNode("RET REAL", NULL);}
				|	INT_PTR  {$$=makeNode("RET INT*", NULL);}
				|	CHAR_PTR  {$$=makeNode("RET CHAR*", NULL);}
				|	REAL_PTR {$$=makeNode("RET REAL*", NULL);}
				;

the_ret:			RETURN expression ';' {$$=makeNode("RET ",$2,NULL); }
				;



//statment======================================================

statment:				call semico {$$=$1;}
					|	if_statment 	{$$ = $1;}				
					|	for_statment  {$$=makeNode("FOR ",$1,NULL);}
					|	while_statment {$$=makeNode("WHILE ",$1,NULL );}
					|	initign_statment  {$$=$1;}
					|	the_ret semico	{ $$ = $1;}
					|	var_decls {  $$ = $1; }
					|	'{' statments '}'	{ $$=$1;}
					| 	/*epsilon*/ {}
					;

semico:					
					|	';'
					;					

statments:				statments statment { $$=makeNode("",$1,$2,NULL);}
					|	statment	{ $$= $1;}
					;

var_decls:				VAR ids ':' type ';' {$$=makeNode("VAR: ",$4,$2,NULL);}
					|	var_decls VAR ids ':' type ';' {$$=makeNode("VAR: ",$5,$3,$1,NULL);}
					;

ids: 					ids ',' id {$$=makeNode("",$1,$3,NULL);}
					|	id {$$=$1;}
					;

initign_statment:		lhs EQ expression semico {$$=makeNode(" = ",$1,$3,NULL); }
					;

					

if_statment:			IF '(' expression ')' block else_statment {$$=makeNode("",makeNode("IF ",$3,$5,NULL), $6,NULL );}
					;

else_statment:			ELSE block { $$= makeNode("ELSE ",$2,NULL); }
					|	/*epsilon*/{$$=NULL;};
					;

while_statment:			WHILE '(' expression ')' block {$$=makeNode("",$3,$5,NULL);}
					;

for_statment:			FOR '(' for_cond ')' block { $$=makeNode("",$3,$5,NULL);}
					;

for_cond:				init conditions semico iter {$$=makeNode("",$1,$2,$4,NULL);}
					;

init:					initign_statment {$$=$1;} 
					;


conditions:			|	expression GT expression {$$=makeNode(" > ",$1,$3,NULL);}
					|	expression GTE expression {$$=makeNode(" >=" ,$1,$3,NULL);}
					|	expression LT expression {$$=makeNode(" < ",$1,$3,NULL);}
					|	expression LTE expression {$$=makeNode(" <= ",$1,$3,NULL);}
					|	expression NOT expression {$$=makeNode(" ! ",$1,$3,NULL);}
					|	expression NOTEQ expression {$$=makeNode(" != ",$1,$3,NULL);}
					|	expression OR expression {$$=makeNode(" || ",$1,$3,NULL);}	
					|	expression AND expression {$$=makeNode(" && ",$1,$3,NULL);}	
					;


iter:					expression {$$=$1;}
					;

block: 					{$$=NULL;}	
					|	'{' block_body '}' {$$=makeNode("BLOCK",$2,NULL);}
					;

block_body: 			{$$=makeNode("",NULL);}
					|	block_body statment  { $$ = makeNode("",$1,$2,NULL);}
					;
					
	

expression:				expression PLUS expression {$$=makeNode(" + ",$1,$3,NULL);}
					|	expression MINUS expression {$$=makeNode(" - ",$1,$3,NULL);}
					|	expression MUL expression {$$=makeNode(" * ",$1,$3,NULL);}
					|	expression DIVIDE expression {$$=makeNode(" / ",$1,$3,NULL);}
					|	expression EQEQ expression {$$=makeNode(" == ",$1,$3,NULL);}
					|	expression GT expression {$$=makeNode(" > ",$1,$3,NULL);}
					|	expression GTE expression {$$=makeNode(" >= ",$1,$3,NULL);}
					|	expression LT expression {$$=makeNode(" < ",$1,$3,NULL);}
					|	expression LTE expression {$$=makeNode(" <= ",$1,$3,NULL);}
					|	expression NOT expression {$$=makeNode(" ! ",$1,$3,NULL);}
					|	expression NOTEQ expression {$$=makeNode(" != ",$1,$3,NULL);}
					|	expression OR expression {$$=makeNode(" || ",$1,$3,NULL);}	
					|	expression AND expression {$$=makeNode(" && ",$1,$3,NULL);}	
					|	value 
					;


lhs :					id {$$ = makeNode("",$1,NULL); }
					|	ID '[' expression ']' {$$ = makeNode("ARR",makeNode($1,NULL),$3,NULL);}
					;


value:					id | boolean | string | char | real | int | len | call | ref | null;

type:					TYPE_INT {$$=makeNode(" INT ",NULL);}
					|	TYPE_BOOL {$$=makeNode(" BOOL ",NULL);}
					|	TYPE_CHAR {$$=makeNode(" CHAR ",NULL);}
					|	TYPE_REAL {$$=makeNode(" REAL ",NULL);}
					|	TYPE_STRING {$$=makeNode(" STRING ",NULL);}
					|	INT_PTR {$$=makeNode(" INT* ",NULL);}
					|	CHAR_PTR {$$=makeNode(" CHAR* ",NULL);}
					|	REAL_PTR {$$=makeNode(" REAL* ",NULL);}
					;

id:						ID {$$=makeNode($1,NULL) ; }
					|	DEREF ID { $$=makeNode($1,makeNode($2,NULL),NULL); }
					;

ref:					AMP ID { $$=makeNode($1,makeNode($2,NULL),NULL); }					
					;
					

call:					id '(' call_args ')'  { $$ = makeNode("CALL",$1,makeNode("ARGS",$3,NULL),NULL); }
					;

len:					'|' id '|' { $$=makeNode("LEN",$2,NULL); }
					|	'|' string '|' { $$=makeNode("STRING LEN",$2,NULL); }

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
	tree= makeNode("CODE ", NULL);
	return yyparse();
}

void addToTree(Node* son)
{

	int i;
    
    Node **temp = NULL;
    //For first child
    if(tree->size == 0){
        tree->sons = (Node**) malloc (sizeof(Node*));
        (tree->sons)[0] = son;
    }
    else{
        temp = (Node **) malloc (((tree->size) + 1) * (sizeof(Node*)));
        for(i = 0; i < tree->size; i++)
            temp[i] = (tree->sons)[i];
        temp[tree->size] = son;
        free(tree->sons);
        tree->sons = temp;
	}
	(tree->size) ++;
	
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








void printNode(Node *n,int tab)
{
	/*
	int i;
    for (i = 1; i < tab; i++) {
        printf("   ");
    }
    if(n->size!=0)
        printf("(");    
    printf("%s\n", n->value);

    for (i = 0; i < n->size; i++) {
        printNode((n->sons)[i], tab + 1);
    }
    if(n->size!=0){ 
        for (i = 1; i < tab; i++) {
            printf("   ");
        }
        printf(")\n\n"); 
	}
	*/

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
	
}



void closeTree(){

	printTree();


//reversing childs
	int i = 0, j = (tree->size) - 1;
    Node **newChilds = (Node**) malloc ( (tree->size) * sizeof(Node *) );
    while(j >= 0){
        newChilds[j] = (tree->sons)[i];
        j--;
        i++;
    }
    free((tree->sons));
	tree->sons = newChilds;
	tree->parent = NULL;

	changeP(tree);







}



void changeP (Node *parent){
  for(int i=0; i<parent->size; i++){
      parent->sons[i]->parent = parent;
      changeP(parent->sons[i] );
  }
}







void fixTree(Node *node){
    int i;
    for(i=0; i<node->size; i++)
        fixTree(node->sons[i]);
    //if(strcmp(node->value, "") == 0)
        //fixEmptyNode(node);
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
