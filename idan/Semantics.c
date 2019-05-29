#include "definitions.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>
#include <malloc.h>
#ifndef SEMANTICS
#define SEMANTICS

#include "Utilities.c"

//This function adds a new error
void newError(const char *error){
    int i;
    
    char *newErr = (char*) malloc (sizeof(char) * strlen(error));
    strcpy(newErr, error);
    char **temp = NULL;
    //For first error
    if(numOfErrors == 0){
        semErrors = (char**) malloc (sizeof(char*));
        semErrors[0] = newErr;
        numOfErrors = 1;
    }
    else{
        for(i = 0; i < numOfErrors; i++){
            if(strcmp(error, semErrors[i]) == 0)
                return;
        }
        temp = (char **) malloc (((numOfErrors) + 1) * (sizeof(char*)));
        for(i = 0; i < numOfErrors; i++)
            temp[i] = semErrors[i];
        temp[numOfErrors] = newErr;
        free(semErrors);
        semErrors = temp;
        numOfErrors++;
    }
}

//This function prints out all errors collected in semantic check
void errorSummary(){
    int i;
    if(numOfErrors == 0)
        printf("No errors\n");
    else{
        for(i=0; i<numOfErrors; i++)
            printf("Error #%d: %s\n", i+1, semErrors[i]);
    }
}

//This function runs all semantic check functions
void checkSemantics(Node *node, int level){
    int i;
    for(i = 0; i < node->numOfChilds; i++)
        checkSemantics(node->child[i], level+1);

    if(strcmp(node->token, "CODE") == 0)
        checkMain(node);
    if(strcmp(node->token, "CALL") == 0)
        checkFunctionCall(node);
    if(strcmp(node->token, "RETURN") == 0)
        checkReturn(node);
    if(strcmp(node->token, "IF") == 0 || strcmp(node->token, "IF-ELSE") == 0 || strcmp(node->token, "WHILE") == 0 || strcmp(node->token, "FOR") == 0)
        checkCondition(node);
    if(getOperatorType(node->token) != NONE)
        evalExpression(node);
}

//This function checks that there is only one main function and it is defined as the last one
void checkMain(Node *node){
    //node argument is a "CODE" node
    int countMains = 0, i;
    for(i=0; i<node->numOfChilds; i++){     //Counting all "MAIN" nodes
        if(strcmp(node->child[i]->token, "MAIN") == 0)
            countMains++;
    }
    if(countMains == 0)
        newError("No main defined");
    if(countMains > 1)
        newError("More than one Main function");
    if(countMains == 1){
        if(strcmp(node->child[node->numOfChilds-1]->token, "MAIN") != 0)
            newError("Main function must be the last one");
    }
}

//This function checks if a func/proc call is valid
void checkFunctionCall(Node *callNode){
    Node * funcNode = getFuncOrProc(callNode), *argsPtr = NULL;
    SymTable *funcTable = NULL;
    Symbol *argumentSym = NULL;
    char *argType = NULL;
    int i, countMatch = 0, expectedMatch;

    //Func/Proc definition not found
    if(funcNode == NULL){
        newError("Func/Proc must be defined before call");
        return;
    }

    argsPtr = callNode->child[0];   //Pointing to the parent of the arguments passed in call 
    funcTable = findTable(funcNode);
    argumentSym = funcTable->symbolListHead;    //Pointing to first argument in func decleration
    expectedMatch = getTableSize(funcTable);

    //Unmatching amount of arguments
    if(expectedMatch != argsPtr->numOfChilds){
        newError("Invalid amount of arguments passed to func/proc");
        return;
    }

    for(i = 0; i < argsPtr->numOfChilds; i++){
        argType = getVarType(argsPtr->child[i]);
        if(argType == NULL){                //If variable passed is not defined

            newError("Variables must be declared before use");
            return;
        }
        if(argumentSym != NULL){
            if(strcmp(argType, argumentSym->type) == 0)     //Matching types
                countMatch++;
            argumentSym = argumentSym->next;
        }
    }

    //Unmatching types
    if(expectedMatch != countMatch)
        newError("Invalid argument type passed to proc/func");
    return;
}

//This function checks a return statement expression result type and compares it with type declared in function
void checkReturn(Node *returnNode){
  Node *funcNode = returnNode;
  char * resultType = evalExpression(returnNode->child[0]), *expectedResult = NULL;
  
  while(strcmp(funcNode->token, "FUNC") != 0)   //Finding out function of return node
    funcNode = funcNode->parent;

    expectedResult = funcNode->child[2]->child[0]->token;       //Function return type

    if(strcmp(resultType, "string") == 0)
        newError("Strings cannot be returned from functions");

    else if(strcmp(resultType, expectedResult) != 0){
        newError("Return statement type dosen't match function return type");
    }
}

//This function varifies that statements within if-else, while, and for statements are of type bool
void checkCondition(Node *statementNode){
    Node *condNode = NULL;
    char *expType = NULL;
    //Pointing to condition expression according to the node passed
    if(strcmp(statementNode->token, "FOR") == 0)
        condNode = statementNode->child[1];
    else
        condNode = statementNode->child[0];

    expType = evalExpression(condNode);     //Evaluating condition
    if(strcmp(expType, "bool") != 0)
        newError("Expected type for condition is bool");

}

//This function evaluates and expression and returns it's expected type result
char * evalExpression(Node *node){
    char *left = NULL, *right = NULL;
    if(node->numOfChilds == 0 || strcmp(node->token, "CALL") == 0)          //If node is a leaf or function call, meaning, it should have a type
        return getVarType(node);

    if(node->numOfChilds == 1){         //For unary operators
        left = evalExpression(node->child[0]);
        return getResultType(node->token, left, NULL);
    }

    if(node->numOfChilds == 2){         //For binary operators
        left = evalExpression(node->child[0]);
        right = evalExpression(node->child[1]);
        return getResultType(node->token, left, right);
    }

}

//This function gets a node and returns it's type, returns empty string and raises error if node is undefined variable
char * getVarType(Node *node){
    Node *funcNode = NULL;
    int number = isNumber(node), string = isString(node);
    Symbol *sym  = NULL;
    if(strcmp(node->token,"true") == 0 || strcmp(node->token, "false") == 0)
        return "bool";
    if(strcmp(node->token, "null") == 0)
        return "null";

    if(strcmp(node->token, "CALL") == 0){       //If variable is func call, check it's return value
        funcNode = getFuncOrProc(node);
        if(funcNode == NULL){
            newError("Func/Proc must be defined before call");
            return NULL;
        }
        if(strcmp(funcNode->token, "PROC") == 0){
            newError("Proc dosen't return a value");
            return NULL;
        }
        return funcNode->child[2]->child[0]->token;
        
    }
    if(!number && !string){     //If node is not a constant
        sym = searchSymbol(node, node->token, VARIABLE);
            printf("LOOK HERE - %s\n",node->token);

        if(sym != NULL)
            return sym->type;
        else{
            newError("Variables must be declared before use");
            return "";
        }
    }

    //If constant, returning constant type
    switch(number){
        case 1: return "int";
        case 2: return "real";
    }
    switch(string){
        case 1: return "char";
        case 2: return "string";
    }

}

//This function defines rules of operation given unary/binary operator and operand/s
//returns expected operation result type
//returns empty string and raises error if operation is not valid
char * getResultType(char *operator, char *left, char *right){
    printf("\nThe op is %s - %s - %s\n",operator,left, right);

    opType type = getOperatorType(operator);

    if(right == NULL){  //For unary operators
        if(strcmp(operator, "!") == 0 && strcmp(left, "bool") == 0)
            return "bool";
        else if(strcmp(operator, "LEN") == 0 && strcmp(left, "string") == 0)
            return "int";
        else if(strcmp(operator, "&") == 0){
            if(strcmp(left, "int") == 0) return "int*";
            else if(strcmp(left, "real") == 0) return "real*";
            else if(strcmp(left, "char") == 0) return "char*";

        }
        else if(strcmp(operator, "^") == 0){
            if(strcmp(left, "int*") == 0) return "int";
            else if(strcmp(left, "real*") == 0) return "real";
            else if(strcmp(left, "char*") == 0) return "char";

        }
        
    }

    else{   //For binary operators
        if(type == ASSIGN && strcmp(left, right) == 0)
            return left;
    
        else if (type == LOGICAL && strcmp(left, "bool") == 0 && strcmp(right, "bool") == 0)
            return "bool";

        else if (type == ARITHMETIC && strcmp(left, "int") == 0 && strcmp(right, "int") == 0)
            return "int";

        else if (
            type == ARITHMETIC &&
                (strcmp(left, "int") == 0 || strcmp(left, "real") == 0) &&
                (strcmp(right, "int") == 0 || strcmp(right, "real") == 0)
            )
            return "real";

        else if (
            (type == COMPARE_NUM) &&
                (strcmp(left, "int") == 0 || strcmp(left, "real") == 0) &&
                (strcmp(right, "int") == 0 || strcmp(right, "real") == 0)
            )
            return "bool";

        else if (
            (type == COMPARE_EQ) &&

            (
                (strcmp(left, "int") == 0 && strcmp(right, "int") == 0) ||
                (strcmp(left, "real") == 0 && strcmp(right, "real") == 0) ||
                (strcmp(left, "bool") == 0 && strcmp(right, "bool") == 0) ||
                (strcmp(left, "char") == 0 && strcmp(right, "char") == 0) ||
                (strcmp(left, "char*") == 0 && strcmp(right, "char*") == 0)
            )
            
        )
        return "bool";

        else if(strcmp(operator, "[]") == 0 && strcmp(left, "string") == 0 && strcmp(right, "int") == 0)
            return "char";

        else if(
            strcmp(operator, "=") == 0 &&
            (strcmp(left, "char*") == 0 || strcmp(left, "int*") == 0 || strcmp(left, "real*") == 0) &&
            strcmp(right, "null") == 0
        )   return left;

        else if(
            (strcmp(operator, "+") || strcmp(operator, "-")) &&
            (strcmp(left, "char*") == 0 || strcmp(left, "int*") == 0 || strcmp(left, "real*") == 0) &&
            strcmp(right, "int") == 0

            )   return left;
    }
    newError(appendStrings("illegal operation with operator ", operator));
    return " ";
    
}

//This function returns node operator type, or NONE if not an operator
opType getOperatorType(char *token){
    if(
        strcmp(token, ">") == 0 || strcmp(token, "<") == 0 ||
        strcmp(token, "<=") == 0 || strcmp(token, ">=") == 0
    )   return COMPARE_NUM;

    if(
        strcmp(token, "==") == 0 || strcmp(token, "!=") == 0
    )   return COMPARE_EQ;

    if(
        strcmp(token, "&&") == 0 || strcmp(token, "||") == 0
    )   return LOGICAL;

    if(
        strcmp(token, "+") == 0 || strcmp(token, "-") == 0 ||
        strcmp(token, "/") == 0 || strcmp(token, "*") == 0
    ) return ARITHMETIC;

    if(
        strcmp(token, "=") == 0
    ) return ASSIGN;
    if(
        strcmp(token, "LEN") == 0 || strcmp(token, "&") == 0 ||
        strcmp(token, "!") == 0 || strcmp(token, "^") == 0
    ) return UNARY;

    return NONE;
}

//This function returns a node's scope node
Node * findScopeNode(Node *node){
    Node *search = node->parent;
    while(search != NULL){
        if(isScope(search))
            return search;
        search = search->parent;
    }
    return search;
}

//This function searches for a func/proc with given call node
Node * getFuncOrProc(Node *callNode){
    Node *search = callNode->parent, *prev = callNode;
    int index, i, found = 0;

    while(search != NULL){
        index = getChildIndex(search, prev);
        for(i = index - 1; i >= 0; i--){
            if(strcmp(search->child[i]->token, "PROC") == 0 || strcmp(search->child[i]->token, "FUNC") == 0){   //Regular call
                if(strcmp(callNode->child[0]->token, search->child[i]->child[0]->token) == 0)
                    return search->child[i];     
            }
            else if(strcmp(search->token, "PROC") == 0 || strcmp(search->token, "FUNC") == 0){      //Recursive call
                if(strcmp(callNode->child[0]->token, search->child[0]->token) == 0)
                    return search; 
            }
        }
        prev = search;
        search = search->parent;
    }
    return NULL;
}

//This function checks if a given node is a scope node 
int isScope(Node *node){
    if(
        strcmp(node->token, "PROC") == 0 || 
        strcmp(node->token, "FUNC") == 0 || 
        strcmp(node->token, "BLOCK") == 0 || 
        strcmp(node->token, "BODY") == 0 ||
        strcmp(node->token, "CODE") == 0
        )
        return 1;
    return 0;
}

//This function checks if a node's token is a number
//returns 0 if not a number, 1 for integer and 2 for real
int isNumber(Node *node){
    int i, isReal = 0;
    if(isString(node))
        return 0;
    if(strlen(node->token) >= 2 && node->token[0] == '0' && (node->token[1] == 'x' || node->token[1] == 'X'))
        return 1;
    for (i = 0; i < strlen(node->token); i++){
        if(node->token[i] == '.' || node->token[i] == '+' || node->token[i] == 'e' || node->token[i] == 'E'){   //real number
            isReal = 1;
        }
        else{
            if(! (node->token[i] >= 48 && node->token[i] <= 57) && node->token[i] != '-')    //If not a digit
                return 0;
        }
        
    }
    if(isReal)
        return 2;
    return 1;
}

//This function checks if a node represents a character or a string
//returns 0 if not a string or char, 1 for char, 2 for string
int isString(Node *node){
    if(strlen(node->token) == 3 && node->token[0] == 39 && node->token[strlen(node->token) - 1] == 39)
        return 1;  //Char: single quote = 39
    else if (node->token[0] == 34 && node->token[strlen(node->token) - 1] == 34)
        return 2;   //String: double quotes = 34
    return 0;
}

//This function checks if a node represents constant, i.e. char, string or number
//returns 1 if constant, 0 otherwise
int isConst(Node *node){
    if(isNumber(node) == 0 && isString(node) == 0)
        return 0;
    return 1;
}

//This function get a scope node, identifier name and type and searches for it in the scope,
//returns symbol if found, NULL otherwise
Symbol * searchSymbol(Node *scope, char *id, identifierType idType){
    if(scope == NULL)
        return NULL;

    if (isScope(scope)){
        SymTable *table = findTable(scope);
        Symbol *symbol = findSymbol(table, id, idType);
        if(symbol == NULL)
            return searchSymbol(scope->parent, id, idType);
        return symbol;
    }

    return searchSymbol(scope->parent, id, idType);

}

//This function initializes scopes and their symbol tables
void initScopes(Node *node){
    int i, j, k, strSize;
    Node *scopePtr = NULL;
    Symbol *newSym = NULL;
    SymTable *table = NULL, *newScope = NULL;
    char *strId = NULL;
    
    if(isScope(node)){      //For scope node, creating new symbol table
        newScope = newSymTable(node);
        addTable(newScope);
        scopePtr = findScopeNode(node);
        if(scopePtr != NULL){        //For nested scopes
            if(strcmp(node->token, "PROC") == 0 || strcmp(node->token, "FUNC") == 0){    //If node is func/proc, add it's id to scope table
            newSym = newSymbol(node->child[0]->token, node->token, NULL, FUNCTION);
            table = findTable(scopePtr);
            if(addSymbol(table, newSym) == 0)
                newError("Conflicting Func/Proc definition");       //If there is already func/proc with the same name in the same scope
            }       
        }
    }

    if(strcmp(node->token, "ARGS") == 0 || strcmp(node->token, "VAR") == 0){
        scopePtr = findScopeNode(node);
        table = findTable(scopePtr);
        for(i = 0; i < node->numOfChilds; i++){     //for each type
            for(j = 0; j < node->child[i]->numOfChilds; j++){   //for each var/arg
                if(strcmp(node->child[i]->token, "string") >= 0){   //If variable type is string, creating symbol for each cell
                    strSize = getStringSize(node->child[i]);        //Extracting string size from declaration
                    if(strSize <= 0){
                        newError("Invalid string decleration");
                    }
                    else{
                        //Adding one symbol of type string
                        if(addSymbol(table, newSymbol(node->child[i]->child[j]->token, "string", NULL, VARIABLE)) == 0)
                                newError("Conflicting local variable or argument name");
                        for(k = 0; k < strSize; k++){
                            //Each cell in string array gets a coresponding char symbol
                            strId = appendStrings(appendStrings(appendStrings(node->child[i]->child[j]->token, "["), intToString(k)),"]");
                            if(addSymbol(table, newSymbol(strId, "char", NULL, VARIABLE)) == 0)
                                newError("Conflicting local variable or argument name");
                        }
                    } 
                }
                /*If not a string, adding symbol once*/
                else if(addSymbol(table, newSymbol(node->child[i]->child[j]->token, node->child[i]->token, NULL, VARIABLE)) == 0)
                    newError("Conflicting local variable or argument name");
            }
        }
    }
    for(i = 0; i < node->numOfChilds; i++)
        initScopes(node->child[i]);
}

#endif
