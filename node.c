#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <stdarg.h>
#include <malloc.h>
#include "part2.h"




void addToTree(Node* son, Node* parent)
{

	int i;
    
    Node **temp = NULL;
    //For first child
    if(parent->size == 0){
        parent->sons = (Node**) malloc (sizeof(Node*));
        (parent->sons)[0] = son;
    }
    else{
        temp = (Node **) malloc (((parent->size) + 1) * (sizeof(Node*)));
        for(i = 0; i < parent->size; i++)
            temp[i] = (parent->sons)[i];
        temp[parent->size] = son;
        free(parent->sons);
        parent->sons = temp;
	}
	(parent->size) ++;
	
}


void printTree(Node* tree){
	printNode(tree,1);
    printer(tree);
}


Node *makeNode( char *value, ...)
{
	int i, count = 0;
    va_list countPointer, listPointer;
    Node *newNode = (Node *) malloc (sizeof(Node));
    Node *getArg = NULL;

    //Initializing token
    newNode->value = (char *) malloc ((strlen(value)+1)*sizeof(char));
    strcpy(newNode->value, value);
    //Counting number of arguments passed
    va_start(countPointer, value);
    do{
        getArg = va_arg(countPointer, Node *);
        if(getArg != NULL)
            count++;
    }while(getArg != NULL);

    //Assigining children to array
    if(count != 0){
        newNode->size = count;
        va_start(listPointer, value);
        newNode->sons = (Node**) malloc (count * sizeof(Node *));
        for(i = 0; i < count; i++){
            (newNode->sons)[i] = va_arg(listPointer, Node *);
        }     
    }
    else{
        newNode->sons = NULL;
        newNode->size = 0;
    }
	return newNode;
}


int getChildIndex(Node *father, Node *child){
    int i = 0;
    for(i=0; i<father->size; i++){
        if(father->sons[i] == child)
            return i;
    }
    return -1;
}




void fixRec(Node*temp,Node*n){


	//printf("-%s-%d\n",temp->value,(strcmp(temp->value,"=")));;

	if(temp->size==0  || (strcmp(temp->value,"=") == 0) || (strcmp(temp->value,"IF-ELSE") == 0) || (strcmp(temp->value,"IF") == 0)
    || (strcmp(temp->value,"NONE") == 0) || (strcmp(temp->value,"WHILE") == 0) || (strcmp(temp->value,"FOR") == 0)
    || (strcmp(temp->value,"VAR") == 0) || (strcmp(temp->value,"ARGS") == 0) || (strcmp(temp->value,"PROC") == 0) 
    || (strcmp(temp->value,"FUNC") == 0) || (strcmp(temp->value,"ARGS") == 0) || (strcmp(temp->value,"ARR") == 0) ){
		addToTree(temp,n);
		return;
	}

    else if (strcmp(temp->value,"EMPTY") == 0)
        return;


    //else if (strcmp(temp->value,"") == 0)
	

	//printf("-%s--%s--%s-\n",temp->value,temp->sons[0]->sons[0]->value,temp->sons[0]->sons[1]->value);
	if  (temp && strcmp(temp->sons[1]->value,"REC ARGS"))
	{
		addToTree(temp->sons[1],n);
		addToTree(temp->sons[0],n);
	}
	else
	{
		fixRec(temp->sons[1],n);
		addToTree(temp->sons[0],n);
	}
}

void printNode(Node *n,int tab)
{
	
    for (int i = 1; i < tab; i++) {
        printf("   ");
    }
    if(n->size!=0)
        printf("(");    
    printf("%s\n", n->value);

    for (int i = 0; i < n->size; i++) {
        printNode((n->sons)[i], tab + 1);
    }
    if(n->size!=0){ 
        for (int i = 1; i < tab; i++) {
            printf("   ");
        }
        printf(")\n\n"); 
	}
	




	
}



void printer(Node*n){

	    int i;

    printf("Node: %s\n", n->value);
    if(n->size == 0)
        printf("No children\n");
    else{
    printf("Children:\n");
    for (i = 0; i < n->size; i++) 
        printf("%s ", (n->sons)[i]->value);
	printf("\n");
    for (i = 0; i < n->size; i++) 
	
        printer((n->sons)[i]);
}
}





void changeP (Node *parent){
  for(int i=0; i<parent->size; i++){
      parent->sons[i]->parent = parent;
      changeP(parent->sons[i] );
  }
}



Node* fixFix (Node*temp){
	Node* newNode = makeNode(temp->value,NULL);
	for(int i =temp->size -1; i>=0; i--)
		addToTree(temp->sons[i],newNode);
	return newNode;
}

