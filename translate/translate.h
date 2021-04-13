#ifndef DYNAMIC_PHONE_PROFILE_H
#define DYNAMIC_PHONE_PROFILE_H

#include<string.h>
#include<stdio.h>
#include<stdlib.h>

typedef struct translateElement{
    char* initial;
    char* transfer;
}translateElement;

void freeTranslateElement(translateElement* label);
translateElement* buildTranslateElement(const char* initial,
                                       const char* transfer);

#endif