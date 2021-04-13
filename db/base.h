#ifndef WTFFF_BASE_H
#define WTFFF_BASE_H

#include "../translate/translate.h"
#include "../utilites/dynamicString.h"


typedef struct fakeBase{
    translateElement **elements;
    int size;
    int realSize;
}fakeBase;
fakeBase *initializationFakeDataBase(int size);
double loadFactor(fakeBase *base);
void fakeAdd(fakeBase *base, translateElement* label);
int fakeLikeSearch(fakeBase *base, char * name);

#endif
