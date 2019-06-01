#pragma once
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
    sym->idType = varType;
    sym->next = NULL;

    return sym;
}


SymTable * createSymTbl(Node *scopeNode){
    SymTable *tbl = (SymTable*) malloc (sizeof(SymTable));
    tbl->head = NULL;
    tbl->scopeNode = scopeNode;
    tbl->next = NULL;
    return tbl;
}



int addSymbol(SymTable *tbl, Symbol *sym){
    Symbol *temp = NULL;

    if(findSym(tbl, sym->id,sym->idType))
        return 0;

    else if(!(tbl->head)){
        tbl->head = sym;
        return 1;
    }

    else{
        temp = tbl->head;
        while(temp->next)
            temp = temp->next;
        temp->next = sym;
        return 1;
    }

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




Symbol * findSym(SymTable *tbl, char *id, variableType type){
    Symbol *search = tbl->head;
    while(search){
        if( search->idType == type &&  (!strcmp(search->id, id)) )
            return search;
        search = search->next;
    }
    return search;
}

SymTable * findTbl(Node *scopeNode){
    SymTable *search = scopes_head;
    while(search){
        if(search->scopeNode == scopeNode)
            return search;
        search = search->next;
    }
    return search;
}




void printSymbol(Symbol *sym){
    
    printf("%-15s| name: %-15s| Value: %-15s| SymbolType:  ",sym->type, sym->id, sym->value);

    if(sym->idType == VARIABLE)
        printf("VARIABLE\n");
    else
        printf("METHOD\n");   
}



void printTable(SymTable *tbl){
    Symbol *sym = tbl->head;
    printf("scope: %s\n", tbl->scopeNode->value);
    while(sym){
        printSymbol(sym);
        sym = sym->next;
    }
    printf("\n");
}


void printScopes(){
    SymTable *sym = scopes_head;
    while(sym){
        printTable(sym);
        sym = sym->next;
    }
}


int tblSize(SymTable *tbl){
    int cou = 0;
    Symbol *sym = tbl->head;
    while(sym){
        cou++;
        sym = sym->next;
    }
    return cou;
}










//semantics functions


Node * findScopeNode(Node *node){
    node = node->parent;
    while(node){
        if(isScope(node->value))
            return node;
        node = node->parent;
    }
    return node;
}


void checks(Node *node, int level){
    int i;
    //printf("start %s\n",node->value);
    for(i = 0; i < node->size; i++)
        checks(node->sons[i], level+1);

    char* value = node->value;
    
    if(!strcmp(value, "CODE"))
        checkMain(node);
    //else if(!strcmp(value,"Main"))
      //  return;
    else if(!strcmp(value, "IF") || 
            !strcmp(value, "IFELSE") || 
            !strcmp(value, "WHILE") || 
            !strcmp(value, "FOR"))
        isBool(node);
    else if(!strcmp(value, "RETURN"))
        checkReturn(node);
    else if(!strcmp(value, "CALL"))
        checkCall(node);
    if(operatorType(value) != NONE){
        eval(node);
    }
    //printf("done %s\n",node->value);
    //printf("DONE\n");

}



opType operatorType(char *value){

    if(!strcmp(value, "&&") || !strcmp(value, "||"))
        return LOGICAL;

    else if(!strcmp(value, "==") || !strcmp(value, "!="))
       return COMPARE_EQ;



    else if(!strcmp(value, ">")  || !strcmp(value, "<") ||
            !strcmp(value, "<=") || !strcmp(value, ">="))
        return COMPARE_NUM;

    else if(!strcmp(value, "+") || !strcmp(value, "-") ||
            !strcmp(value, "/") || !strcmp(value, "*"))
        return ARITHMETIC;

    else if(!strcmp(value, "="))
        return ASSIGN;

    else if( !strcmp(value, "STRING LEN") || !strcmp(value, "LEN") || !strcmp(value, "&") ||
             !strcmp(value, "!")   || !strcmp(value, "^"))
        return UNARY;
    
    else
        return NONE;
}




int isNumber(char *value){
    int i, isReal = 0;
    if(isString(value))
        return 0;

    else if( strlen(value) >= 2 && value[0] == '0' && (value[1] == 'x' || value[1] == 'X'))
        return 1;

    for (i = 0; i < strlen(value); i++){
        if(value[i] == '.' || value[i] == '+' || value[i] == 'e' || value[i] == 'E'){   
            isReal = 1;
        }
        else{
            if( ((value[i] < '0') || (value[i] > '9') ) && value[i] != '-')   
                return 0;
        }
        
    }
    if(isReal)
        return 2;
    return 1;
}



int isString(char * value){
    if( strlen(value) == 3    &&    value[0] == '\''  &&
        value[strlen(value) - 1] == '\'')
        return 1;  
    else if (value[0] == '"' && value[strlen(value) - 1] == '"')
        return 2;   
    return 0;
}

Symbol * searchSymbol(Node *scope, char *id, variableType idType){
    if(!scope)
        return NULL;

    else if (isScope(scope->value)){
        SymTable *tbl = findTbl(scope);
        Symbol *sym = findSym(tbl, id, idType);
        if(!sym)
            return searchSymbol(scope->parent, id, idType);
        return sym;
    }

    return searchSymbol(scope->parent, id, idType);

}


char * getType(Node *node){
    Node *MethodNode = NULL;
    Symbol *sym  = NULL;
    if(!strcmp(node->value,"TRUE") || !strcmp(node->value, "FALSE"))
        return "BOOL";
    else if(!strcmp(node->value, "NULL"))
        return "NULL";

    else if(!strcmp(node->value, "CALL")){     
        MethodNode = getMethod(node);
        if(!MethodNode){
            pushErr("Must Define Methods Befor Call");
            return NULL;
        }
        if(!strcmp(MethodNode->value, "PROC")){
            pushErr("Procedure dosen't return a value");
            return NULL;
        }
        return MethodNode->sons[2]->sons[0]->value;
        
    }
    if(!isNumber(node->value) && !isString(node->value)){     //If node is not a constant
        sym = searchSymbol(node, node->value, VARIABLE);
        if(!sym){
            pushErr("Need to declare vars before use");
            return "";
        }
        
        return sym->type;

    }

    switch(isNumber(node->value)){
        case 1: return "INT";
        case 2: return "REAL";
    }
    switch(isString(node->value)){
        case 1: return "CHAR";
        case 2: return "STRING";
    }

}



Node * getMethod(Node *callNode){
    Node *search = callNode->parent, *prev = callNode;
    int index, i, found = 0;

    while(search){
        index = getSonsIndex(search, prev);
        for(i = index - 1; i >= 0; i--){
            if(!strcmp(search->sons[i]->value, "PROC") || !strcmp(search->sons[i]->value, "FUNC")){  
                if(!strcmp(callNode->sons[0]->value, search->sons[i]->sons[0]->value))
                    return search->sons[i];     
            }
            else if(!strcmp(search->value, "PROC") || !strcmp(search->value, "FUNC")){      
                if(!strcmp(callNode->sons[0]->value, search->sons[0]->value))
                    return search; 
            }
        }
        prev = search;
        search = search->parent;
    }
    return NULL;
}


char * getResultType(char *operator, char *left, char *right){
    //printf("\nThe op is %s - %s - %s\n",operator,left, right);
    if(!right){ // unary
        if(!strcmp(operator, "!") && !strcmp(left, "BOOL"))
            return "BOOL";
        else if((!strcmp(operator, "LEN") ||(!strcmp(operator, "STRING LEN")))   && !strcmp(left, "STRING") )
            return "INT";
        else if(!strcmp(operator, "&")){
            if(!strcmp(left, "INT"))
                return "INT*";
            else if(!strcmp(left, "REAL")) 
                return "REAL*";
            else if(!strcmp(left, "CHAR"))
                return "CHAR*";

        }
        else if(!strcmp(operator, "^")){
            if(!strcmp(left, "INT*") )
                return "INT";
            else if(!strcmp(left, "REAL*"))
                return "REAL";
            else if(!strcmp(left, "CHAR*"))
                return "CHAR";

        }
        
    }
    else{  
        opType opType = operatorType(operator);
        if(opType == ASSIGN && !strcmp(left, right))
            return left;
    
        else if (opType == LOGICAL && !strcmp(left, "BOOL")  && !strcmp(right,left))
            return "BOOL";

        else if (opType == ARITHMETIC && !strcmp(left, "INT") && !strcmp(right, left))
            return "INT";

        else if (
            opType == ARITHMETIC &&
                (!strcmp(left,  "INT")|| !strcmp(left,  "REAL") ) &&
                (!strcmp(right, "INT")|| !strcmp(right, "REAL") )
            )
            return "REAL";

        else if (
            (opType == COMPARE_NUM) &&
                (!strcmp(left, "INT") || !strcmp(left,  "REAL") ) &&
                (!strcmp(right,"INT") || !strcmp(right, "REAL") )
            )
            return "BOOL";

        else if (
            (opType == COMPARE_EQ) &&

            (
                (!strcmp(left, "INT")   && !strcmp(right, "INT")  ) ||
                (!strcmp(left, "REAL")  && !strcmp(right, "REAL") ) ||
                (!strcmp(left, "BOOL")  && !strcmp(right, "BOOL") ) ||
                (!strcmp(left, "CHAR")  && !strcmp(right, "CHAR") ) ||
                (!strcmp(left, "CHAR*") && !strcmp(right, "CHAR*")) ||
                (!strcmp(left, "REAL*") && !strcmp(right, "REAL*")) ||
                (!strcmp(left, "INT*")  && !strcmp(right, "INT*") ) 
                
            )
            
        )
        return "BOOL";

        else if(!strcmp(operator, "ARR") && !strcmp(left, "STRING") && !strcmp(right, "INT"))
            return "CHAR";

        else if(
            !strcmp(operator, "=") &&
            (!strcmp(left, "CHAR*") || !strcmp(left, "INT*") || !strcmp(left, "REAL*") ) &&
             !strcmp(right, "NULL") 
        )  { return left; 
             }

        else if(
            (strcmp(operator, "+") || strcmp(operator, "-")) &&
            (!strcmp(left, "CHAR*") || !strcmp(left, "INT*")  || !strcmp(left, "REAL*")) &&
            !strcmp(right, "INT"))   
            return left;
    }
    pushErr(concat("illegal operation with operator ", operator));
//    printf("%s,%s,%s\n",operator,left,right);
    return " ";
    
}


char * eval(Node *node){
    char *left = NULL, *right = NULL;
    if(node->size == 0 || !strcmp(node->value, "CALL"))         
        return getType(node);

    if(node->size == 1){        
        left = eval(node->sons[0]);
        return getResultType(node->value, left, NULL);
    }

    if(node->size == 2){       
        left = eval(node->sons[0]);
        right = eval(node->sons[1]);
        return getResultType(node->value, left, right);
    }

}

void checkReturn(Node *ret){

    Node *MethodNode = ret;
    char * resultType = eval(ret->sons[0]), *expectedResult = NULL;
  
    while(strcmp(MethodNode->value, "FUNC"))
        MethodNode = MethodNode->parent;

    
    expectedResult = MethodNode->sons[2]->sons[0]->value;
    if(!strcmp(resultType, "STRING"))
        pushErr("Strings cannot be returned from functions");

    else if(strcmp(resultType, expectedResult)){
//        printf("LOOK HERE - expec =%s - res = %s\n",resultType, expectedResult);
        pushErr("Wrong return type");
    }

}

void isBool(Node *node){
    Node *condNode = NULL;
    
    if(!strcmp(node->value, "FOR"))
        condNode = node->sons[1];
    else
        condNode = node->sons[0];

    if(strcmp(eval(condNode), "BOOL") )
        pushErr("Condition expression should be of type boolean");

}



int isEXP(Node* node){
    char* val = node->value;
    if( !strcmp(val,"+") || !strcmp(val,"-") || !strcmp(val,"*") || !strcmp(val,"\\")  )
        return 1;
    return 0;
}




void checkCall(Node *callNode){
    //printf("LOOK\n");printNode(callNode,1);
    Node * MethodNode = getMethod(callNode);
    Node * nodeArgs = callNode->sons[0]; 
    SymTable *tbl = findTbl(MethodNode);  
    if(!tbl){
        pushErr("Must Define Methods Befor Call");
        return;
    }  
    Symbol *sym = tbl->head; 
    char *curType = NULL;
    
    int i, curNum = 0, expNumArgs = tblSize(tbl);

    if(!MethodNode){
        pushErr(concat(nodeArgs->value," is Not defined - Define Function Befor Call"));
        return;
    }

//printNode(nodeArgs,1);
    if(expNumArgs != nodeArgs->size){

        pushErr(concat("Wrong number of arguments to the method ",nodeArgs->value));
        return;
    }

    for(i = 0; i < nodeArgs->size; i++){
        //printNode(nodeArgs,1);
        if(isEXP(nodeArgs->sons[i]))
            curType= eval(nodeArgs->sons[i]);
        else
            curType = getType(nodeArgs->sons[i]);
        if(!curType){               
            pushErr("Must declare vars before use");
            return;
        }
        if(sym){
            //printf("arg-%s sym-%s\n",curType, sym->type);
            if(!strcmp(curType, sym->type))   
                curNum++;
            sym = sym->next;
        }
    }

    if(expNumArgs != curNum){
        //printNode(nodeArgs,1);
        //printf("%s\n",getType(nodeArgs->sons[0]));
        pushErr("Wrong argument type passed to funtion");
    }
    return;
}


int strLen(Node *stringNode){
    char buffer[100];
    char *stringPtr = stringNode->value, *bufferPtr = buffer;

    int res;
    while(*stringPtr != '[')
        stringPtr++;
    stringPtr++;
    while(*stringPtr != ']'){
        *bufferPtr = *stringPtr;
        stringPtr++;
        bufferPtr++;
    }
    *bufferPtr = '\0';

    res = atoi(buffer);
    return res;


}



void initScopes(Node *node){
    int i, j, k, strSize;
    Node *scopeNode = NULL;
    Symbol *newSym = NULL;
    SymTable *table = NULL, *newScope = NULL;

    char *strId = node->value;
    
    if(isScope(strId)){
        newScope = createSymTbl(node);
        addTable(newScope);
        scopeNode = findScopeNode(node);
        if(scopeNode){      
            if(!strcmp(strId, "PROC") || !strcmp(strId, "FUNC")){    
            newSym = createSymbol(node->sons[0]->value, strId, NULL, METHOD);
            table = findTbl(scopeNode);
            if(!addSymbol(table, newSym))
                pushErr("Method definition is already exsist");
            }       
        }
    }
    strId=NULL;

    if(!strcmp(node->value, "ARGS") || !strcmp(node->value, "VAR")){
        scopeNode = findScopeNode(node);
        table = findTbl(scopeNode);
        for(i = 0; i < node->size; i++){     //for each type
            for(j = 0; j < node->sons[i]->size; j++){   //for each var/arg
                if(strcmp(node->sons[i]->value, "STRING") >= 0){   //If variable type is string, creating symbol for each cell
                    strSize = strLen(node->sons[i]);
                    if(strSize <= 0){
                        pushErr("Invalid string decleration");
                    }
                    else{
                        char*temp = node->sons[i]->sons[j]->value;
                        if(!addSymbol(table, createSymbol(temp, "STRING", NULL, VARIABLE)))
                                pushErr("Conflicting local variable or argument name");
                        for(k = 0; k < strSize; k++){
                            strId = concat(concat(concat(temp, "["), stringInt(k)),"]");
                            if(!addSymbol(table, createSymbol(strId, "CHAR", NULL, VARIABLE)))
                                pushErr("Conflicting local variable or argument name");
                        }
                    } 
                }
                else if(!addSymbol(table, createSymbol(node->sons[i]->sons[j]->value, node->sons[i]->value, NULL, VARIABLE)) )
                    pushErr("Conflicting local variable or argument name");
            }
        }
    }
    for(i = 0; i < node->size; i++)
        initScopes(node->sons[i]);

}




void checkMain(Node *code){

    int cou = 0;
    char* value = code->sons[code->size-1]->value;

    for(int i=0; i<code->size; i++){    
        if(!strcmp(code->sons[i]->value, "Main"))
            cou++;
    }
    switch(cou){

        case 0: pushErr("The Main proc is not defined"); break;
        
        case 1:
            if(strcmp(value, "Main"))
                pushErr("Main proc must be the last method declared");
                break;
        default: pushErr("More than one Main proc declared");
    }
}

int isScope(char *value){
    return (
        !strcmp(value, "PROC") ||
        !strcmp(value, "BLOCK")||  
        !strcmp(value, "FUNC") || 
        !strcmp(value, "BODY") ||
        !strcmp(value, "CODE")
        ) ;
}



void errorSummary(){
    int i;
    if(ErrorListSize == 0)
        printf("\nCompiled succesfuly\n");
    
    else
        printf("Program was not compiled because:\n");
    for(i=0; i<ErrorListSize; i++)
        printf("# %d - %s\n", i+1, semErrors[i]);
    
}

void pushErr(const char *err){
    int i;

    for (i=0; i<ErrorListSize; i++)
        if(!strcmp(err,semErrors[i]))
            return;
    strcpy(semErrors[ErrorListSize++], err);
}











