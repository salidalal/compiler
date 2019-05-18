#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>
#include <malloc.h>


typedef enum 
{ 
    ARGUMENT, 
    LOCAL,  
} variableType;

typedef struct Symbol Symbol;

typedef struct Symbol{
    char *id;
    char *type;
    char *value;
    variableType varType;
    Symbol *next;

} Symbol;

typedef struct SymTable SymTable;

typedef struct SymTable{
    Node * scopePtr;
    Symbol *symbolListHead;
    SymTable *next;
} SymTable;

SymTable *scopes_head = NULL;

Symbol * newSymbol(char *id, char *type, char *value, variableType varType);
void addSymbol(SymTable *table, Symbol *symbol);
Symbol * findSymbol(SymTable *table, char *id);
SymTable * newSymTable(Node *scopePtr);
void addTable(SymTable *newTable);
SymTable * findTable(Node *scopePtr);


//from file.y
void initScopes(Node *node);
Node * findScopeNode(Node *node);





void addTable(SymTable *newTable){
    if(scopes_head == NULL)
        scopes_head = newTable;
    else{
        newTable->next = scopes_head;
        scopes_head = newTable;
    }
}

SymTable * findTable(Node *scopePtr){
    SymTable *search = scopes_head;
    while(search != NULL){
        if(search->scopePtr == scopePtr)
            return search;
        search = search->next;
    }
    return search;
}

void printSymbol(Symbol *symbol){
    if(symbol->value!=NULL)
        printf("Id: %s\tType: %s\tValue: %s\tSymbol type: ", symbol->id,symbol->type, symbol->value);
    else
        printf("Id: %s\tType: %s\tValue: NULL\tSymbol type: ", symbol->id,symbol->type);

    if(symbol->varType == ARGUMENT)
        printf("ARGUMENT\n");
    else
        printf("LOCAL\n");
    
    
}

void printTable(SymTable *table){
    Symbol *scan = table->symbolListHead;
    printf("Scope: %s\n", table->scopePtr->value);
    while(scan != NULL){
        printf("HERE ");
        printSymbol(scan);
        scan = scan->next;
    }
}

void printScopes(){
    SymTable *scan = scopes_head;
    while(scan != NULL){
        printTable(scan);
        scan = scan->next;
    }
}




char ** parseString(char *var, int size){
    const char delim[2] = " ";
    char *buffer = (char*) malloc (strlen(var) * sizeof(char));
    char **varNames = NULL;
    int i = 0;
    strcpy(buffer, var);

    varNames = (char**) malloc (size * sizeof(char*));
    buffer = strtok(buffer, delim);
   /* walk through other values */
   while( buffer != NULL ) {
       varNames[i] = buffer;
       i++;
        buffer = strtok(NULL, delim);
   }
   return varNames;
} 




int checkTableRepeat(SymTable *table){
    Symbol *ptr1 = table->symbolListHead, *ptr2 = table->symbolListHead;
    if(ptr2 == NULL)
        return 1;
    
    while(ptr1 != NULL){
        while(ptr2 != NULL){
            if(ptr1!=ptr2 && strcmp(ptr1->id, ptr2->id) >= 0 && ptr1->varType == ptr2->varType)
                return 0;
            ptr2 = ptr2->next;
        }
        ptr2 = table->symbolListHead;
        ptr1 = ptr1->next;
    }
    return 1;
}


int countWords(char *string){
    int count = 0, i;
    for(i = 0; i < strlen(string); i++){
        if(string[i] == ' ')
            count++;
    }
    if(count == 0 && strlen(string) >= 1)
        count++;
    return count;
}




Symbol * findSymbol(SymTable *table, char *id){
    Symbol *search = table->symbolListHead;
    while(search != NULL){
        if(strcmp(search->id, id) == 0)
            return search;
        search = search->next;
    }
    return search;
}



SymTable * newSymTable(Node *scopePtr){
    SymTable *newTable = (SymTable*) malloc (sizeof(SymTable));
    newTable->scopePtr = scopePtr;
    newTable->symbolListHead = NULL;
    newTable->next = NULL;
    return newTable;
}





void addSymbol(SymTable *table, Symbol *symbol){
    if(table->symbolListHead == NULL)
        table->symbolListHead = symbol;
    else{
        symbol->next = table->symbolListHead;
        table->symbolListHead = symbol;
    }

}





Symbol * newSymbol(char *id, char *type, char *value, variableType varType){
    Symbol *newSymbol = (Symbol*) malloc (sizeof(Symbol));
    newSymbol->id = id;
    newSymbol->type = type;
    newSymbol->value = value;
    newSymbol->varType = varType;
    newSymbol->next = NULL;
    return newSymbol;
}












void initScopes(Node *node){
    int i, j, count;
    char **variables = NULL;
    Node *scopePtr = NULL;
    Symbol *newSym = NULL;
    SymTable *table = NULL, *newScope = NULL;
    variableType varType;
    
    if(strcmp(node->value, "PROC") == 0 || strcmp(node->value, "FUNC") == 0 || strcmp(node->value, "BLOCK") == 0 || strcmp(node->value, "BODY") == 0){
        newScope = newSymTable(node);
        addTable(newScope);
    }

    if(strcmp(node->value, "ARGS") == 0 || strcmp(node->value, "VAR") == 0){
        if(strcmp(node->value, "ARGS") == 0)
            varType = ARGUMENT;
        else
            varType = LOCAL;

        scopePtr = findScopeNode(node);

        for(i = 0; i < node->size; i++){
            count = countWords(node->sons[i]->value);
            
            variables = parseString(node->sons[i]->value, count);
            for(j = 1; j < count; j++){
                newSym = newSymbol(variables[j], variables[0], NULL, varType);
                table = findTable(scopePtr);
                addSymbol(table, newSym);
            }
        }
    }
    for(i = 0; i < node->size; i++)
        initScopes(node->sons[i]);
}








Node * findScopeNode(Node *node){
    Node *search = node->parent;
    while(search != NULL){
        if(strcmp(search->value, "PROC") == 0 || strcmp(search->value, "FUNC") == 0 || strcmp(search->value, "BLOCK") == 0)
            return search;
        search = search->parent;
    }
    return search;
}

