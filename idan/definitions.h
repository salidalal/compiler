
#ifndef DEFINITIONS
#define DEFINITIONS
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>
#include <malloc.h>


typedef struct Node Node;
typedef struct Node{
    char *token;
    Node **child;
    Node* parent;
    int numOfChilds;
} Node;

typedef enum 
{ 
    VARIABLE,
    FUNCTION  
} identifierType;

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
    identifierType idType;
    Symbol *next;

} Symbol;

typedef struct SymTable SymTable;
typedef struct SymTable{
    Node * scopePtr;
    Symbol *symbolListHead;
    SymTable *next;
} SymTable;








void yyerror(char *s);
int yywrap();


// Tree functions


// Semantic checking functions
void checkSemantics(Node *root, int level);
void checkMain(Node *node);
void checkProcFuncScope(Node *procNode);
void checkVarScope(Node *varNode);
void checkFunctionCall(Node *node);
void checkArguments(Node *callNode, Node *funcNode);


opType getOperatorType(char *token);
char * evalExpression(Node *node);
void checkAssign(Node *node);
void checkReturn(Node *funcNode);
void printScopes();

// Error handling
void newError(const char *error);
void errorSummary();



//Symbol table
Symbol * newSymbol(char *id, char *type, char *value, identifierType idType);
int addSymbol(SymTable *table, Symbol *symbol);
Symbol * findSymbol(SymTable *table, char *id, identifierType idType);
SymTable * newSymTable(Node *scopePtr);
void addTable(SymTable *newTable);
SymTable * findTable(Node *scopePtr);
void initScopes(Node *node);
Node * findScopeNode(Node *node);
Symbol * searchSymbol(Node *scope, char *id, identifierType idType);
int isScope(Node *node);

Node * getFuncOrProc(Node *callNode);

char * getVarType(Node *node);

int getTableSize(SymTable *table);
int isString(Node *node);

void checkCondition(Node *statementNode);

Node * createNode(char *token, ...);
void addChild(Node *father, Node *newChild);
void printTree(Node *node, int level);
void print(Node *root);
void reverseChilds(Node *node);
void makeParents(Node *node, int level);
void printer(Node *node);
int getChildIndex(Node *father, Node *child);

int countWords(char *string);
char ** parseString(char *var, int size);
// char ** getArgumentTypes(SymTable *table);


char * appendStrings(char *str1, char *str2);
// Empty node handling
void fixTree(Node *root);
void checkEmpty(Node *node, int level);
void fixEmptyNode(Node *emptyNode);

// Global variables
Node* pTree;

int yydebug=1;
int lastChild = 0;
char **semErrors = NULL;
int numOfErrors = 0;

SymTable *scopes_head = NULL;
Node *currentEmptyNode = NULL;


#endif