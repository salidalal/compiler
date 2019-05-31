#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>
#include <malloc.h>
#include "definitions.h"

void printAllCodes(Node *node){
    int i;
    printf("Node: %s\nCode:\n%s\nVar: %s\n\n", node->token, node->code, node->var);
    for(i = 0; i < node->numOfChilds; i++)
        printAllCodes(node->child[i]);
}

void printCode(Node *root){
    char *cursor = root->code;
    FILE * outputFile = fopen("output.txt", "w");

    printf("---------------------\n");
    printf("\n%s", root->code);
    printf("---------------------\n");
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
                // fputc('\t', outputFile);
                fputc(32, outputFile);
            }
        }
        fputc(*cursor, outputFile);
        cursor++;
    }

    fclose(outputFile);

}

void start3AC(Node *root){
    handleExpressions(root);
    handleRest(root);
}

//This function dispatches an expression node to be handled sepratly
void handleExpressions(Node *node){
    int i;

    if(getOperatorType(node->token) != NONE){
        generateExpression3AC(node);
        return;
    }

    for(i = 0; i < node->numOfChilds; i++)
        handleExpressions(node->child[i]); 
}


// void generateExpression3AC(Node *node){
//     int i;
//     for(i = 0; i < node->numOfChilds; i++)
//         generateExpression3AC(node->child[i]);



//         if(strcmp(node->token, "=") == 0){

//         }

// }





//This function handles generation of 3AC for expressions
void generateExpression3AC(Node *node){
    int i, j;
    for(i = 0; i < node->numOfChilds; i++)
        generateExpression3AC(node->child[i]);
    
    if(node->numOfChilds == 0){     //Leaf nodes, i.e. constants or variables
        if(strcmp(node->parent->parent->token, "CALL") == 0){       //If node is function call parameter
            node->var = getNewVar();
            node->code = appendStrings(appendStrings(appendStrings(
                node->var, "="), node->token), "\n");
        }
        else{
            node->var = (char *) malloc ( (strlen(node->token) + 1) * sizeof(char) );
            strcpy(node->var,node->token);
            node->code = (char *) malloc ( sizeof(char) );
            strcpy(node->code ,"");

        }
    }

    if(node->numOfChilds == 1){
        if(strcmp(node->token, "CALL") == 0){   //Node is a function call
            node->var = getNewVar();
            node->code = (char *) malloc (sizeof(char));
            for(j = 0; j < node->child[0]->numOfChilds; j++)
                node->code = appendStrings(node->code, node->child[0]->child[j]->code);       //Adding parameters code
            
            for(j = 0; j < node->child[0]->numOfChilds; j++)
                node->code = appendStrings(appendStrings(appendStrings(node->code, "PushParam "), node->child[0]->child[j]->var), "\n");  //Pushing parameters
            
            node->code = appendStrings(appendStrings(appendStrings(appendStrings(appendStrings(
                node->code, node->var), "="), "LCall "), node->child[0]->token), "\n");
            if(node->child[0]->numOfChilds != 0)
                node->code = appendStrings(node->code, "PopParams\n");

        }
        else{
            node->var = getNewVar();
            node->code = appendStrings(appendStrings(appendStrings(appendStrings(appendStrings(
            node->child[0]->code, node->var), " = "), node->token), node->child[0]->var), "\n");
        }
    }

    if(node->numOfChilds == 2 && strcmp(node->token, "=") != 0){
        if(strcmp(node->token, "[]") == 0){
            node->var = getNewVar();

            node->code = appendStrings(appendStrings(appendStrings(appendStrings(appendStrings(appendStrings(appendStrings(appendStrings(
                node->child[0]->code, node->child[1]->code), node->var), " = "), "&"), node->child[0]->var), " + "), node->child[1]->var), "\n")
                ;

        }

        else{
            node->var = getNewVar();
            node->code = appendStrings(appendStrings(appendStrings(appendStrings(appendStrings(appendStrings(appendStrings(
                node->child[0]->code, node->child[1]->code), node->var), " = "), node->child[0]->var), node->token), node->child[1]->var), "\n");
        }

    }
    else if(node->numOfChilds == 2 && strcmp(node->token, "=") == 0 && strcmp(node->token, "[]") != 0){
        if(strcmp(node->child[0]->token, "[]") == 0){
            node->code = appendStrings(appendStrings(appendStrings(appendStrings(appendStrings(
                node->child[0]->code, "^"), node->child[0]->var), " = "), node->child[1]->var), "\n");
        }
        else{
            node->code = appendStrings(appendStrings(appendStrings(appendStrings(appendStrings(
                     node->child[0]->code ,node->child[1]->code), node->child[0]->var), " = "), node->child[1]->var), "\n");
        }
        
        // node->var = getNewVar();
        // node->code = appendStrings(appendStrings(appendStrings(appendStrings(appendStrings(
        //              node->child[0]->code ,node->child[1]->code), node->var), " = "), node->child[1]->var), "\n");
    }

}

//This function dispatches to other function to handle code creation for non-expression nodes
void handleRest(Node *node){
    int i;
    for(i = 0; i < node->numOfChilds; i++)
        handleRest(node->child[i]);
    if(strcmp(node->token, "WHILE") == 0)
        handleWhile(node);
    if(strcmp(node->token, "FOR") == 0)
        handleFor(node);
    if(strcmp(node->token, "IF") == 0 || strcmp(node->token, "IF-ELSE") == 0)
        handleIf(node);
    if(strcmp(node->token, "BLOCK") == 0 || strcmp(node->token, "BODY") == 0)
        handleBlock(node);
    if(strcmp(node->token, "RETURN") == 0)
        handleReturn(node);
    if(strcmp(node->token, "MAIN") == 0 || strcmp(node->token, "PROC") == 0 || strcmp(node->token, "FUNC") == 0)
        handleFunc(node);
    if(strcmp(node->token, "CODE") == 0)
        handleCode(node);
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
        
        if(strcmp(blockNode->child[i]->token, "VAR") != 0 &&    //Not including nodes that are not statements
            strcmp(blockNode->child[i]->token, "RET") != 0
        )
        {
            blockNode->code = appendStrings(blockNode->code, blockNode->child[i]->code);
        }
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