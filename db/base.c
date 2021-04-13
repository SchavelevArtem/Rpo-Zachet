#include "base.h"
#include <string.h>

fakeBase *initializationFakeDataBase(int size){
    fakeBase *base = (fakeBase*)malloc(sizeof(fakeBase));
    base->elements = (translateElement **)malloc(sizeof(struct translateElement*) * size);
    base->size = 0;
    base->realSize = size;
    return base;
}


double loadFactor(fakeBase *base) {
    if (base->realSize == 0) {
        return 0.0;
    }
    return base->size/base->realSize;
}

void fakeAdd(fakeBase *base, translateElement* label){
    if (loadFactor(base) > 0.7) {
        int newRealSize = base->realSize * 2;
        base->elements = (translateElement **) realloc(base->elements,
                                                      sizeof(translateElement *) * (newRealSize));
        base->realSize = newRealSize;
    }
    int index = base->size;
    base->elements[index] = label;
    base->size = index + 1;
}


int fakeLikeSearch(fakeBase *base, char * name){
    // при наождение похожего профиля возвращает 1, иначе -1
    for (int element=0; element < base->size; ++element){
        translateElement *currentElement = base->elements[element];
        if (currentElement->initial == NULL) {
            continue;
        }
        if (strcmp(currentElement->initial, name) == 0){
            return element;
        }
    }
    return -1;
}
