#include "dynamicString.h"

DynamicString* initString() {
    DynamicString* result = (DynamicString*)malloc(sizeof(DynamicString));
    result->currentSize = 16;
    result->currentlyUsed = 0;
    result->string = (char*)malloc(result->currentSize * sizeof(char));
    memset(result->string, '\0', result->currentSize * sizeof(char));

    return result;
}

void addToString(DynamicString* string, char symbol) {
    if (string->currentlyUsed > string->currentSize) {
        string->currentSize += 16;
        string->string =
                (char*)realloc(string->string, string->currentSize * sizeof(char));
        memset(&(string->string[string->currentlyUsed]), '\0',
               sizeof(char) * (string->currentSize - string->currentlyUsed));
    }

    string->string[string->currentlyUsed] = symbol;
    ++string->currentlyUsed;
}

void readToString(DynamicString* string) {
    char newSymbol;
    scanf(" %c", &newSymbol);

    while (newSymbol != '\n') {
        addToString(string, newSymbol);
        scanf("%c", &newSymbol);
    }
}

void freeString(DynamicString* string) {
    free(string->string);
    free(string);
}