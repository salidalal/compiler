#pragma once
#include <stdarg.h>
#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include <string.h>
#include "part2.h"

char* t="t";



int isDeclaration(Node* node){
    

    char*value = node->value;
    if( !strcmp(value, "ARGS") || !strcmp(value, "ARGS NONE") ||
        !strcmp(value, "VAR")  || !strcmp(value, "RET"))
        return 1;
    return 0;
}

int isMethodId(Node* node){

    Node* parent = node->parent;
    if(!parent){
        return 0;
    }

    else if(!strcmp(parent->value,"FUNC") || !strcmp(parent->value,"PROC"))
        if(parent->sons[0] == node)
            return 1;

    return 0;
}

int isCall(Node*node){

    if(!(node->parent)){
        return 0;
    }

    if( node->parent && !strcmp(node->parent->value, "CALL"))
        return 1;

    return 0;
}

void call3Ac(Node* node){

    if( isDeclaration(node) || isMethodId(node) )
        return;
    
    for(int i=0; i<node->size; i++){
        call3Ac(node->sons[i]);
    }

    //printf("start-->%s\n",node->value);
    sendByValue(node);
        printf("end-->%s\n",node->value);

}

void sendByValue(Node* node){
    char* value = node->value;

    if(!strcmp("CODE",value))
        closeCode(node);
    
    else if(!strcmp("Main",value) || !strcmp("PROC",value) || !strcmp("FUNC",value))
        closeMethod(node);
    
    else if(!strcmp(value, "BLOCK") || !strcmp(value, "BODY"))
        closeBody(node);

    else if(!strcmp(value, "RETURN"))
        closeReturn(node);

    else if(!strcmp(value, "WHILE"))
        closeWhile(node);

    else if(!strcmp(value, "FOR"))
        closeFor(node);

    else if(!strcmp(value, "IF") || !strcmp(value, "IFELSE"))
        closeIf(node);

    else if(isCall(node))
        closeCall(node);

    else{
        switch(node->size){
            case 0: closeConstOP(node); break;
            case 1: closeUnaryOP(node); break;
            case 2: closeBinaryOP(node); break;
        }

    }

}



void closeCode(Node * tree){
    tree->code = concat("","");
    for(int i = 0; i < tree->size; i++)
        tree->code = concat(tree->code, tree->sons[i]->code);
}




void closeConstOP(Node * node){

    char* value = node->value;
    if(isNumber(value) || isString(value)){      
           //printf("Const node: %s\n", value);
        node->var = concat(t,stringInt(codeCounter++));
        node->code = concat(node->var,concat(" = ",concat(value,"\n")));
    }

    else{  
        //printf("Id node: %s\n", value);
        node->var = concat("", value);
        node->code = "";
        }
}



void closeUnaryOP(Node * node){
    node->var = concat(t,stringInt(codeCounter++));
    char* soncode = node->sons[0]->code;
    char* sonvar = node->sons[0]->var;
    node->code = concat(soncode,concat(node->var,concat(" = ",concat(node->value,concat(sonvar,"\n")))));
}


void closeAss(Node* node){
    node->var ="";
    char* soncode1 = node->sons[1]->code;
    char* sonvar1 = node->sons[1]->var;
    char* sonvar0 = node->sons[0]->var;
    node->code = concat(soncode1,concat(sonvar0,concat(" = ",concat(sonvar1,"\n"))));
}

void closeBody(Node*node){

    Node ** sons= node->sons;
    int i=0;
    node->var="";
    node->code = "";

    for (i = 0; i < node->size ; i++){
        if(strcmp(sons[i]->value, "VAR")){
            node->code = concat(node->code,sons[i]->code);
        }
    }
}


void closeBinaryOP(Node * node){

    if(!strcmp(node->value, " = "))    
        closeAss(node);    

    else{  
        char* soncode1 = node->sons[1]->code;
        char* sonvar1 = node->sons[1]->var;
        char* soncode0 = node->sons[0]->code;
        char* sonvar0 = node->sons[0]->var;

        node->var = concat(t,stringInt(codeCounter++));
        node->code = concat(soncode0,concat(soncode1,concat(node->var,concat(" = ",
                     concat(sonvar0,concat(node->value,concat(sonvar1,"\n")))))));
    }
}








void closeMethod(Node *node){
    Node** sons = node->sons;
    int i=0;
    char *id = node->value;
    codeCounter = 0;
    if(strcmp(id, "Main"))
        id = node->sons[0]->value;
    
    while(strcmp(sons[i]->value, "BODY") && strcmp(sons[i]->value, "BLOCK")){
        i++;
    }
    printf("the i is %d\n",i);
    node->var="";
    node->code = concat(id,concat(" :\n",concat("BeginFunc\n",concat(sons[i]->code,"EndFunc\n\n\n$"))));
    
}


void closeReturn(Node * node){
    if(!node->sons[0]->size){
        node->var="";
        node->code = concat("Return",concat(node->sons[0]->value,"\n"));
    }
    else{
        node->var = "";
        node->code = concat(node->sons[0]->code,concat("Return ",concat(node->sons[0]->var,"\n")));
    }

}




void closeWhile(Node* node){
    char* condLab = concat("L",stringInt(labelCounter++));
    char* endLab = concat("L",stringInt(labelCounter++));
    node->var="";
    node->code = concat("@", concat(condLab,concat(" : ",concat(node->sons[0]->code,
    concat("ifz ",concat(node->sons[0]->var,concat(" GoTo ",concat(endLab,concat("\n",
    concat(node->sons[1]->code,concat("GoTo ",concat(condLab,concat("\nLABLE",
    concat(endLab," : "))))))))))))));
}



void closeFor(Node* node){
    Node ** sons = node->sons;
    char* condLab = concat("L",stringInt(labelCounter++));
    char* endLab = concat("L",stringInt(labelCounter++));

    node->var="";
    node->code = concat(sons[0]->code,concat("@",concat(condLab,(concat(" : ",concat(sons[1]->code,
    concat("ifz ",concat(sons[1]->var,concat(" GoTo ",concat(endLab,concat("\n",
    concat(sons[3]->code,concat(sons[2]->code,concat("GoTo ",concat(condLab,
    concat("\n@",concat(endLab," : ")))))))))))))))));

}



void closeIf(Node * node){

    if(!strcmp(node->value,"IFELSE")){
        closeIfElse(node);
        return;
    }
    char* condLab = concat("L",stringInt(labelCounter++));
    Node ** sons = node->sons;

    node->var="";
    node->code= concat(sons[0]->code,concat("ifz ",concat(sons[0]->var,
    concat(" GoTo ",concat(condLab,concat("\n",concat(sons[1]->code,
    concat("@",concat(condLab," : ")))))))));

}




void closeIfElse(Node* node){
    char* condLab = concat("L",stringInt(labelCounter++));
    char* elseLab = concat("L",stringInt(labelCounter++));
    Node** sons=node->sons;
    node->code= concat(sons[0]->code,concat("ifz ",concat(sons[0]->var,
    concat(" GoTo ",concat(condLab,concat("\n",concat(sons[1]->code,

    concat("GoTo ",concat(elseLab,concat("\n@",concat(condLab,
    concat(" : ",(concat(sons[2]->code,
    concat("@",concat(elseLab," : "))))))))))))))));
}



char* getArgsSize(Node* node){
    if(son->size){
        char* charbytes="";
        int intbytes = 0;
        for (int i=0; i<son->size; i++){
            char* type=NULL;

            switch(son->sons[i]->size){
                case 0: type=getType(son->sons[i]);break;
                default: type=eval(son->sons[i]);
            }
            if(!type){
                charbytes="";
                
                break;
            } 
            else if(isPointer(type)|| !strcmp("INT",type))
                intbytes+=4;
            else if(!strcmp(type,"CHAR"))
                intbytes+=1;
            else if(!strcmp(type,"REAL"))
                intbytes+=8;
        }
        charbytes = stringInt(intbytes);

        node->code = concat(node->code,concat("PopParams ",charbytes ));
    }
    
}



void closeCall(Node*node){
    node->var=concat(t,stringInt(codeCounter++));
    node->code="";
    Node * son = node->sons[0];

    for(int i=0; i<son->size; i++) 
        node->code=concat(node->code,son->sons[i]->code);

    for(int i=0; i<son->size; i++)
        node->code=concat(node->code,concat("PushParam ",concat(son->sons[i]->var,"\n")));

    node->code = concat(node->code,concat(node->var,concat(" = LCall ", (concat(son->value,"\n")))));
    
    
    getArgsSize(node);
    node->code=concat(node->code,"\n");

}



/*

void print(Node * tree){

    FILE * codeOutput = fopen("codeOutput.txt", "w");

    char *code = tree->code, c;

    for (int i=0; code[i]; i++){
        c=code[i];

        if(c=='\n'){
            fprintf(codeOutput,"\n");
            c=code[++i];
            if(c=='$'){
                fprintf(codeOutput," ");
                c=code[++i];
            }
            else if(c=='@')
                c=code[++i];
            else
                fprintf(codeOutput,"\t ");
            }
            fprintf("%c",c);
            c=code[++i];
    }

    fclose(codeOutput); 
}

*/




void print(Node *root){
    char *cursor = root->code;
    FILE * outputFile = fopen("output.txt", "w");

    while(*cursor != '\0'){
        if(*cursor == '\n'){
            putc(*cursor, outputFile);
            cursor++;
            if(*cursor == '@'){
                putc(32, outputFile);
                cursor++;
            }
            else if (*cursor == '$'){
                cursor++;
            }
            
            else{
                putc('\t', outputFile);
                putc(32, outputFile);
            }
        }
        putc(*cursor, outputFile);
        cursor++;
    }
    fclose(outputFile);
}

