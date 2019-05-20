#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>
#include <malloc.h>
#include "part2.h"



Symbol * createSymbol(char *id, char *type, char *value, variableType varType){
    Symbol *sym = (Symbol*) malloc (sizeof(Symbol));
    sym->type = type;
    sym->value = value;
    sym->id = id;
    sym->varType = varType;
    sym->next = NULL;

    return sym;
}


SymTable * createSymTbl(Node *scopePtr){
    SymTable *tbl = (SymTable*) malloc (sizeof(SymTable));
    tbl->scopePtr = scopePtr;
    tbl->next = NULL;
    tbl->head = NULL;
    return tbl;
}



int addSymbol(SymTable *tbl, Symbol *sym){
    Symbol *temp = NULL;

    if(findSymbol(tbl, sym->id))
        return 0;

    if(!(tbl->head))
        tbl->head = sym;

    else{
        temp = tbl->head;
        while(temp->next)
            temp = temp->next;
        temp->next = sym;
    }
    return 1;

}

void addTable(SymTable *tbl){


    if(scopes_head){
        tbl->next = scopes_head;
        scopes_head = tbl; 
    }
    else{
        scopes_head = tbl;   
    }
}


Symbol * findSym(SymTable *table, char *id){
    Symbol *search = table->head;
    while(search){
        if(!strcmp(search->id, id))
            return search;
        search = search->next;
    }
    return search;
}

SymTable * findTbl(Node *scopePtr){
    SymTable *search = scopes_head;
    while(search){
        if(search->scopePtr == scopePtr)
            return search;
        search = search->next;
    }
    return search;
}







