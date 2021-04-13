#ifndef DYNAMIC_STRING_H
#define DYNAMIC_STRING_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct {
    char* string;
    long currentSize;
    long currentlyUsed;
} DynamicString;

DynamicString* initString();
void readToString(DynamicString* string);
void addToString(DynamicString* string, char symbol);
void freeString(DynamicString* string);

#endif