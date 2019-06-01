
#ifndef DEFINITIONS
#define DEFINITIONS
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>
#include <malloc.h>

/*Structs and enum definitions*/
typedef struct Node Node;
typedef struct Node{
    char *token;
    Node **child;
    Node* parent;
    int numOfChilds;

    char *code;
    char *var;

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





// YACC functions
void yyerror(char *s);
int yywrap();

// Tree functions
Node * createNode(char *token, ...);
void addChild(Node *father, Node *newChild);
void print(Node *root);
void printTree(Node *node, int level);
void printer(Node *node);
void reverseChilds(Node *node);
void makeParents(Node *node, int level);
int getChildIndex(Node *father, Node *child);

// Symbol table functions
Symbol * newSymbol(char *id, char *type, char *value, identifierType idType);
int addSymbol(SymTable *table, Symbol *newSym);
Symbol * findSymbol(SymTable *table, char *id, identifierType idType);
SymTable * newSymTable(Node *scopePtr);
void addTable(SymTable *newTable);
SymTable * findTable(Node *scopePtr);
void printSymbol(Symbol *symbol);
void printTable(SymTable *table);
void printScopes();
int getTableSize(SymTable *table);

// Semantics functions
void newError(const char *error);
void errorSummary();
void checkSemantics(Node *node, int level);
void checkMain(Node *node);
void checkFunctionCall(Node *callNode);
void checkReturn(Node *returnNode);
void checkCondition(Node *statementNode);
char * evalExpression(Node *node);
char * getVarType(Node *node);
char * getResultType(char *operator, char *left, char *right);
opType getOperatorType(char *token);
Node * findScopeNode(Node *node);
Node * getFuncOrProc(Node *callNode);
int isScope(Node *node);
int isNumber(Node *node);
int isString(Node *node);
int isConst(Node *node);
Symbol * searchSymbol(Node *scope, char *id, identifierType idType);
void initScopes(Node *node);

// Three address code functions

void handleWhile(Node *whileNode);
void handleFor(Node *forNode);
void handleIf(Node *ifNode);
void handleBlock(Node *blockNode);
void handleCall(Node *idNode);
void handleReturn(Node *returnNode);
void handleRest(Node *node);
void handleFunc(Node *funcNode);
void handleCode(Node *codeNode);
char * getNewLabel();
char * calcParamSize(Node *callNode);
int freshLabel();
int freshVar();
char * getNewVar();
void start3AC(Node *root);
void handleExpressions(Node *root);
void generateExpression3AC(Node *node);
void scanExpressions(Node *node);
void outputCode(Node *node);
void printAllCodes(Node *node);

// Utilities functions
char * appendStrings(char *str1, char *str2);
char * appStrings(void *first, ...);
int countWords(char *string);
char ** parseString(char *var, int size);
char * intToString(int num);
int getStringSize(Node *stringNode);

// Global variables
Node* pTree;
char **semErrors = NULL;
int numOfErrors = 0;
int yydebug=1;
SymTable *scopes_head = NULL;

static int fvar = 0;
static int flab = 1;


#endif