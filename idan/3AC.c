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

//This function generates 3AC for operands and operators 
void generateExpression3AC(Node *node){

    //If node is an identifier/constant
    if(node->numOfChilds == 0){
        if(isConst(node)){      //Constant
            node->var = getNewVar();
            node->code = appendStrings(appendStrings(appendStrings(
                node->var, " = "), node->token), "\n");
        }

        else{   //Identifier
            node->var = appendStrings("", node->token);
            node->code = (char *) malloc (sizeof(char));
            strcpy(node->code, "");
        }
    }

    //Unary operator
    else if (node->numOfChilds == 1){
        node->var = getNewVar();
        node->code = appendStrings(appendStrings(appendStrings(appendStrings(appendStrings(
            node->child[0]->code,
            node->var), " = "), node->token), node->child[0]->var), "\n");
    }

    //Binary operator
    else if(node->numOfChilds == 2){
        if(strcmp(node->token, "=") == 0){      //Assignment operator
            node->var = (char *) malloc (sizeof(char));
            strcpy(node->var, "");
            node->code = appendStrings(appendStrings(appendStrings(appendStrings(
                node->child[1]->code, node->child[0]->var), " = "), node->child[1]->var), "\n");
        }

        else{       //Other binary operators
            node->var = getNewVar();
            node->code = appendStrings(appendStrings(appendStrings(appendStrings(appendStrings(appendStrings(appendStrings(
                node->child[0]->code, node->child[1]->code),
                node->var), " = "), node->child[0]->var), node->token), node->child[1]->var), "\n");
        }
    }

}

//This function dispatches to other function to handle code creation for non-expression nodes
void generate3AC(Node *node){
    int i;

    //Making sure not to check declarations or ret statements
    if(strcmp(node->token, "ARGS") == 0 
    || strcmp(node->token, "ARGS NONE") == 0 
    || strcmp(node->token, "VAR") == 0 
    || strcmp(node->token, "RET") == 0)
        return;
    
    //Making sure node is not a function/proc name
    if(node->parent != NULL && 
    (strcmp(node->parent->token, "PROC") == 0 || strcmp(node->parent->token, "FUNC") == 0) &&
    getChildIndex(node->parent, node) == 0
    )
        return;

    for(i = 0; i < node->numOfChilds; i++)
        generate3AC(node->child[i]);

    if(strcmp(node->token, "WHILE") == 0)
        handleWhile(node);
    else if(strcmp(node->token, "FOR") == 0)
        handleFor(node);
    else if(strcmp(node->token, "IF") == 0 || strcmp(node->token, "IF-ELSE") == 0)
        handleIf(node);
    else if(strcmp(node->token, "BLOCK") == 0 || strcmp(node->token, "BODY") == 0)
        handleBlock(node);
    else if(strcmp(node->token, "RETURN") == 0)
        handleReturn(node);
    else if(strcmp(node->token, "MAIN") == 0 || strcmp(node->token, "PROC") == 0 || strcmp(node->token, "FUNC") == 0)
        handleFunc(node);
    else if(strcmp(node->token, "CODE") == 0)
        handleCode(node);
    else if(node->parent != NULL && strcmp(node->parent->token, "CALL") == 0)
        handleCall(node->parent);
    else{
        if(strcmp(node->token, "CALL") != 0)
            generateExpression3AC(node);
    }    

}

//This function handles code creation for code node
void handleCode(Node *codeNode){
    int i;

    codeNode->code = (char *) malloc (sizeof(char));
    strcpy(codeNode->code, "");

    for(i = 0; i < codeNode->numOfChilds; i++)
        codeNode->code = appendStrings(codeNode->code, codeNode->child[i]->code);

}

//This function handles code creation for while loop node
void handleWhile(Node *whileNode){

    char *startLabel = getNewLabel(), *endLabel = getNewLabel();
    whileNode->code = appendStrings(appendStrings(appendStrings(appendStrings(appendStrings(appendStrings(appendStrings(appendStrings(appendStrings(
                    appendStrings(appendStrings(appendStrings(appendStrings(appendStrings(

       "$", startLabel), ": "), whileNode->child[0]->code), 
       "ifz "), whileNode->child[0]->var), " Goto "), endLabel), "\n"), 
       whileNode->child[1]->code),
        "Goto "), startLabel), "\n$"), endLabel), ": ");
}

//This function handles code creation for block/body node
void handleBlock(Node *blockNode){
    int i;

    blockNode->code = (char *) malloc (sizeof(char));
    strcpy(blockNode->code, "");
    for (i = 0; i < blockNode->numOfChilds; i++){
        if(strcmp(blockNode->child[i]->token, "VAR") != 0)
            blockNode->code = appendStrings(blockNode->code, blockNode->child[i]->code);
    }
        
}

//This function handles code creation for For loop node
void handleFor(Node *forNode){
    //Pointing to for elements
    Node *init = forNode->child[0], *cond = forNode->child[1], *assign = forNode->child[2], *statements = forNode->child[3];
    char *startLabel = getNewLabel(), *endLabel = getNewLabel();
    
    forNode->code = appendStrings(appendStrings(appendStrings(appendStrings(appendStrings(appendStrings(appendStrings(appendStrings(appendStrings(
        appendStrings(appendStrings(appendStrings(appendStrings(appendStrings(appendStrings(appendStrings(
    init->code, 
    "$"), startLabel), ": "), cond->code), 
    "ifz "), cond->var), " Goto "), endLabel), "\n"),
    statements->code),
    assign->code),
    "Goto "), startLabel), "\n$"), endLabel), ": ");

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

//This function handles code created for a proc/func
void handleFunc(Node *funcNode){
    Node *funcBlock = NULL;
    int i;
    char *funcName = NULL;
    //Determine func/proc name
    if(strcmp(funcNode->token, "MAIN") == 0)
        funcName = "Main";
    else
        funcName = funcNode->child[0]->token;
    
    for(i = 0; i < funcNode->numOfChilds; i++){     //Finding block/body node
        if( strcmp(funcNode->child[i]->token, "BODY") == 0 || strcmp(funcNode->child[i]->token, "BLOCK") == 0 )
            funcBlock = funcNode->child[i];
    }

    //Creating function node code
    funcNode->code = (char *) malloc (sizeof(char));
    strcpy(funcNode->code, "");
    funcNode->code = appendStrings(appendStrings(appendStrings(appendStrings(
    funcName, ":\n"), "BeginFunc\n"), funcBlock->code), "EndFunc\n\n\n#");

    //Resetting var count
    fvar = 0;

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
