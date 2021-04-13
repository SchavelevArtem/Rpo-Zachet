#include "translate.h"
#include <stdio.h>


translateElement* buildTranslateElement(const char* initial,
                                  const char* transfer) {
    unsigned int nameLength = strlen(initial);
    unsigned int phoneLength = strlen(transfer);
    translateElement* label = (translateElement*)malloc(sizeof(translateElement));
    label->initial = (char*)malloc((nameLength + 1) * sizeof(char));
    label->transfer = (char*)malloc((phoneLength + 1) * sizeof(char));
    for (int i = 0; i < nameLength; ++i) {
        label->initial[i] = initial[i];
    }
    for (int i = 0; i < phoneLength; i++) {
        label->transfer[i] = transfer[i];
    }
    return label;
}

void freeTranslateElement(translateElement* label){
    free(label->initial);
    free(label->transfer);
    free(label);
}

