#include "definitions.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>
#include <malloc.h>
#ifndef UTILITIES
#define UTILITIES

//This function appends str2 to str1
char * appendStrings(char *str1, char *str2){
    char *app = (char*) malloc ((strlen(str1) + strlen(str2) + 1) * sizeof(char)), *ptr1 = str1, *ptr2 = str2, *ptr3 = app;

    // strcpy(app, str1);
    // strcat(app, str2);
    while(*ptr1 != '\0'){
        *ptr3 = *ptr1;
        ptr1++;
        ptr3++;
    }
    while(*ptr2 != '\0'){
        *ptr3 = *ptr2;
        ptr2++;
        ptr3++;
    }
    *ptr3 = '\0';
    // app[strlen(app)] = '\0';
    return app;
}

//The following functions are for counting words in a string and parsing
//May not need them
int countWords(char *string){
    int count = 0, i;
    for(i = 0; i < strlen(string); i++){
        if(string[i] == ' ')
            count++;
    }
    return count;
}
char ** parseString(char *var, int size){
    const char delim[2] = " ";
    char *buffer = (char*) malloc (strlen(var) * sizeof(char));
    char **varNames = NULL;
    int i = 0;
    strcpy(buffer, var);

    varNames = (char**) malloc (size * sizeof(char*));
    buffer = strtok(buffer, delim);
   /* walk through other tokens */
   while( buffer != NULL ) {
       varNames[i] = buffer;
       i++;
        buffer = strtok(NULL, delim);
   }
   return varNames;
}  

//This function turns an integer to a string
char * intToString(int num){
    int temp = num, size = 0;
    char buffer[100], number[100];
    char *res = NULL, *bufferPtr = buffer, *numPtr = number;

    if(num < 10){
        res = (char*) malloc (sizeof(char));
        *res = num + '0';
        return res;
    }

    *bufferPtr = '$';
    bufferPtr++;

    while(temp != 0){
        *bufferPtr = (temp % 10) + '0';
        temp = temp / 10;
        bufferPtr++;  
    }

    bufferPtr--;
    while(*bufferPtr != '$'){
        *numPtr = *bufferPtr;
        bufferPtr--;
        numPtr++;
    }
    *numPtr = '\0';
    res = (char*) malloc ((strlen(number) + 1) * sizeof(char));
    strcpy(res, number);
    return res;
}

//This function extracts string size from string decleration
int getStringSize(Node *stringNode){
    char buffer[100];
    char *stringPtr = stringNode->token, *bufferPtr = buffer;
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

#endif