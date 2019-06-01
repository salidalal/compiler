#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>
#include <malloc.h>
#include "definitions.h"

//This function prints code for each node, for personal use
void printAllCodes(Node *node){
    int i;
    printf("Node: %s\nCode:\n%s\nVar: %s\n\n", node->token, node->code, node->var);
    for(i = 0; i < node->numOfChilds; i++)
        printAllCodes(node->child[i]);
}

//This function outputs the generated 3AC code to .txt file
void outputCode(Node *root){
    char *cursor = root->code;
    FILE * outputFile = fopen("output.txt", "w");

    while(*cursor != '\0'){
        if(*cursor == '\n'){
            fputc(*cursor, outputFile);
            cursor++;
            if(*cursor == '$'){
                fputc(32, outputFile);
                cursor++;
            }
            else if (*cursor == '#'){
                cursor++;
            }
            
            else{
                fputc('\t', outputFile);
                fputc(32, outputFile);
            }
        }
        fputc(*cursor, outputFile);
        cursor++;
    }
    fclose(outputFile);
}

//This function starts the 3AC generation process
void start3AC(Node *root){
    generate3AC(root);
    outputCode(root);
}

//This function handles code creation for if/if-else statements
void handleIf(Node *ifNode){
    char * label = getNewLabel(), *otherLabel = NULL;

    if(strcmp(ifNode->token, "IF") == 0){   //If statement
        ifNode->code = appendStrings(appendStrings(appendStrings(appendStrings(appendStrings(appendStrings(appendStrings(appendStrings(appendStrings(
        ifNode->child[0]->code, "ifz "), ifNode->child[0]->var), " Goto "), label), "\n"), 
        ifNode->child[1]->code), 
        "$"), label), ": ");
        
    }
    else{       //If-else statement
        otherLabel = getNewLabel();

        ifNode->code = appendStrings(appendStrings(appendStrings(appendStrings(appendStrings(appendStrings(appendStrings(
            appendStrings(appendStrings(appendStrings(appendStrings(appendStrings(appendStrings(appendStrings(appendStrings(

        ifNode->child[0]->code, 
        "ifz "), ifNode->child[0]->var), " Goto "), label), "\n"),
        ifNode->child[1]->code), 
        "Goto "), otherLabel), "\n$"), 
        label), ": "), ifNode->child[2]->code),
        "$"), otherLabel), ": ");

    }
}


//This function handles code created for return statement
void handleReturn(Node *returnNode){
    if(returnNode->child[0]->numOfChilds != 0){     //If return value is an expression
        returnNode->code = appendStrings(appendStrings(appendStrings(
            returnNode->child[0]->code,
            "Return "), returnNode->child[0]->var), "\n");
    }
    else{   //If return value is a constant / variable
        returnNode->code = appendStrings(appendStrings("Return ", returnNode->child[0]->token), "\n" );
    }
}

//This function generates code for a call node
void handleCall(Node *callNode){
    Node *paramPtr = callNode->child[0];
    int i;

    callNode->var = getNewVar();
    callNode->code = (char *) malloc (sizeof(char));
    strcpy(callNode->code, "");

    for(i = 0; i < paramPtr->numOfChilds; i++)
        callNode->code = appendStrings(callNode->code, paramPtr->child[i]->code);

    for(i = 0; i < paramPtr->numOfChilds; i++)
        callNode->code = appendStrings(appendStrings(
            "PushParam ", paramPtr->child[i]->var), "\n");
    
    callNode->code = appendStrings(appendStrings(appendStrings(appendStrings(
        callNode->code, 
        callNode->var), " = LCall "), paramPtr->token), "\n"); 

    if(paramPtr->numOfChilds != 0)
        callNode->code = appendStrings(appendStrings(appendStrings(
            callNode->code, "PopParams "), calcParamSize(callNode)), "\n");

}

//This function calculates size in bytes for function call parameters
char * calcParamSize(Node *callNode){
    int size = 0, i;
    Node *paramPtr = callNode->child[0];
    char *paramType = NULL;

    for(i = 0; i < paramPtr->numOfChilds; i++){
        if(paramPtr->child[i]->numOfChilds !=0)             //Getting paramater type
            paramType = evalExpression(paramPtr->child[i]);
        else
            paramType = getVarType(paramPtr->child[i]);

        if(paramType == NULL)
            return "";

        //Adding size

        if(strcmp(paramType, "int*") == 0 ||strcmp(paramType, "real*") == 0 || strcmp(paramType, "char*") == 0 || strcmp(paramType, "int") == 0)
            size += 4;
        
        else if(strcmp(paramType, "real") == 0)
            size += 8;
        
        else if(strcmp(paramType, "char") == 0)
            size += 1;
    }

    if(size == 0)
        return "";

    //Returning size string
    return intToString(size);

}

//This function returns a fresh label variable string
char * getNewLabel(){
    int num = freshLabel();
    char *strNum = intToString(num);
    return appendStrings("L", strNum);
}

//This function returns a fresh temp variable string
char * getNewVar(){
    int num = freshVar();
    char *strNum = intToString(num);
    return appendStrings("t", strNum);
}

//This function returns current var count and increments var count
int freshVar(){
    int x = fvar;
    fvar++;
    return x;
}

//This function returns current label count and increments label count
int freshLabel(){
    int x = flab;
    flab++;
    return x;
}
