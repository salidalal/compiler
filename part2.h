#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>
#include <malloc.h>

char * concat (const char* s1, const char* s2) {
    if(!s1 && !s2)
        return "";
	char *result =(char*) malloc(strlen(s1)+strlen(s2)+1);
	strcpy(result,s1);
	strcat(result,s2);
	return result;
}



char * stringInt(int num){
    int size = 0;
    char buffer[1000], *number;
    sprintf(buffer,"%d",num);

    for(int i=0; buffer[i]; i++)
        size++;
    number = (char*)malloc (sizeof(char)*(size+1));
    strcat(number,buffer);
    return number;
    
}


//NODE
typedef struct Node{
	struct Node **sons;
	int size;
	struct Node *parent;
	char *value;

    char* var;
    char* code;


} Node;



void addToTree(Node*,Node*);
Node *makeNode(char *value, ...);
void printNode(Node *tree,int tab);
void printTree(Node* tree);
void fixRec(Node*temp,Node*n);
Node* fixFix(Node*);
void changeP (Node *parent);
int getSonsIndex(Node *, Node *);





//SYM TBL

typedef enum 
{ 
    VARIABLE,
    METHOD  
} variableType;

typedef enum{
    NONE,
    ARITHMETIC,
    LOGICAL,
    COMPARE_NUM,
    COMPARE_EQ,
    ASSIGN,
    UNARY
} opType;



typedef struct Symbol Symbol;
typedef struct Symbol{
    char *id;
    char *type;
    char *value;
    Symbol *next;
    variableType idType;
    } Symbol;

typedef struct SymTable SymTable;
typedef struct SymTable{
    Node * scopeNode;
    Symbol *head;
    SymTable *next;
} SymTable;


Symbol * createSymbol(char *, char *, char *, variableType varType);
SymTable * createSymTbl(Node *);
int addSymbol(SymTable *, Symbol *);
void addTable(SymTable *);

Symbol * findSym(SymTable *, char *, variableType);
SymTable * findTbl(Node *);

void initScopes(Node *);
void printScopes();
void printTable(SymTable *);
void printSymbol(Symbol *);
int tblSize(SymTable *);

void errorSummary();
void pushErr(const char *);
void checks(Node *, int );
Node * findScopeNode(Node *);
int isString(char*);
int isNumber(char *);
int isScope(char *);
void checkCall(Node *);
void checkMain(Node *);
void checkReturn(Node *);
void isBool(Node *);
int stringSize(Node *);
Node * getMethod(Node *);
void initScopes(Node *); 
opType operatorType(char *);
char * getVarType(Node *);
char * getResultType(char *operator, char *left, char *right);
char * eval(Node *);























int yydebug=1;
int lastChild = 0;
char semErrors[200][200];
int ErrorListSize = 0;

SymTable *scopes_head = NULL;
Node *currentEmptyNode = NULL;









int labelCounter=1;
int codeCounter=0;
int isDeclaration(Node* node);
int isMethodId(Node* node);
int isCall(Node*node);
void call3Ac(Node* node);
void sendByValue(Node* node);
void closeCode(Node * tree);
void closeConstOP(Node * node);
void closeUnaryOP(Node * node);
void closeAss(Node* node);
void closeBinaryOP(Node * node);
void closeMethod(Node *node);
void closeBody(Node*node);




