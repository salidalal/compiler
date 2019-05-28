#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>
#include <malloc.h>
#include "definitions.h"

void printCode(Node *node){
    int i;
    for(i = 0; i < node->numOfChilds; i++)
        printCode(node->child[i]);

    if(node->code != NULL){
        if(strcmp(node->code, "") != 0)
            printf("Code generated for node '%s': %s\n", node->token, node->code);
        else
            printf("Code generated for node '%s': EMPTY STRING\n", node->token);
    }
        
    if(node->var != NULL)
        printf("Var generated for node '%s': %s\n", node->token, node->var);
}

void scanExpressions(Node *node){
    int i;
    if(strcmp(node->token, "=") == 0)
        generateExpression3AC(node);
    for(i = 0; i < node->numOfChilds; i++)
        scanExpressions(node->child[i]);

}

//This function handles creation of 3ac code for an assignment statement
void generateAssign3AC(Node *assignNode){
    assignNode->child[0]->var = assignNode->child[0]->token;    //Left side of assignment is identifier's name
    generateExpression3AC(assignNode->child[1]);  //Generating right side of assignment
    assignNode->code = appendStrings(appendStrings(appendStrings(appendStrings(
        assignNode->child[0]->code, assignNode->child[0]->var), " := "), assignNode->child[1]->var), "\n");

}


void generateExpression3AC(Node *node){
    int i;
    for(i = 0; i < node->numOfChilds; i++)
        generateExpression3AC(node->child[i]);

    if(node->numOfChilds == 0){     //Leaf nodes, i.e. constants or variables
        node->var = (char *) malloc ( (strlen(node->token) + 1) * sizeof(char) );
        strcpy(node->var,node->token);
        node->code = (char *) malloc ( sizeof(char) );
        strcpy(node->code ,"");
    }

    if(node->numOfChilds == 1){
        node->var = getNewVar();
        node->code = appendStrings(appendStrings(appendStrings(appendStrings(appendStrings(
            node->child[0]->code, node->var), " := "), node->token), node->child[0]->var), "\n");
    }

    if(node->numOfChilds == 2 && strcmp(node->token, "=") != 0){
        node->var = getNewVar();
        node->code = appendStrings(appendStrings(appendStrings(appendStrings(appendStrings(appendStrings(appendStrings(
            node->child[0]->code, node->child[1]->code), node->var), " := "), node->child[0]->var), node->token), node->child[1]->var), "\n");
    }
    else if(node->numOfChilds == 2 && strcmp(node->token, "=") == 0){
        // node->var = getNewVar();
        node->code = appendStrings(appendStrings(appendStrings(appendStrings(
                    node->child[1]->code, node->child[0]->var), " := "), node->child[1]->var), "\n");
    }

}


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
