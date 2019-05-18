
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>
#include <malloc.h>


//NODE
typedef struct Node{
	struct Node **sons;
	int size;
	struct Node *parent;
	char *value;
} Node;



void addToTree(Node*,Node*);
Node *makeNode(char *value, ...);
void printNode(Node *tree,int tab);
void printTree(Node* tree);
void fixRec(Node*temp,Node*n);
Node* fixFix(Node*);
void changeP (Node *parent);
int getChildIndex(Node *father, Node *child);





//SYM TBL

typedef enum 
{ 
    ARG, 
    LOCAL 
} variableType;

typedef enum{
    NONE,
    ARITHMETIC,
    LOGICAL,
    COMPARE_NUM,
    COMPARE_EQ,
    ASSIGN
} opType;



typedef struct Symbol Symbol;
typedef struct Symbol{
    char *id;
    char *type;
    char *value;
    Symbol *next;
    variableType varType;
} Symbol;

typedef struct SymTable SymTable;
typedef struct SymTable{
    Node * scopePtr;
    Symbol *head;
    SymTable *next;
} SymTable;


Symbol * createSymbol(char *, char *, char *, variableType varType);
SymTable * createSymTbl(Node *scopePtr);
int addSymbol(SymTable *, Symbol *);
void addTable(SymTable *newTable);






















int yydebug=1;
int lastChild = 0;
char **semErrors = NULL;
int numOfErrors = 0;

SymTable *scopes_head = NULL;
Node *currentEmptyNode = NULL;










