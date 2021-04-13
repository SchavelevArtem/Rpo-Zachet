#include <stdio.h>
#include "db/base.h"
#include "translate/translate.h"
#include "utilites/dynamicString.h"
#include "utilites/stringTools.h"


int main(int argc, char* argv[]) {
    if (argc < 2) {
        return 1;
    }
    char *filePath = argv[1];

    fakeBase *base = initializationFakeDataBase(1500);
    FILE* file;
    if (!(file = fopen(filePath, "r"))) {
        return 1;
    }
    while(!feof(file)){
        char word1[256];
        char word2[256];
        char buf[512];
        fgets(buf,sizeof(buf),file);

        int status = 0;
        int bufLen = strlen(buf);
        for (int i=0; i < bufLen; ++i){
            char element = buf[i];
            if (status==0) {
                if (element == '\t'){
                    status = 1;
                    word1[i]= '\0';
                    continue;
                }
                word1[i] = element;
                continue;
            }
            if (element == '\n'){
                break;
            }
            int word1Len = strlen(word1);
            word2[i - word1Len -1] = element;
            word2[i - word1Len] = '\0';
        }

        //Чистим строки
        char *word1Valid = trim(word1);
        char *word2Valid = trim(word2);


        translateElement * element1 = buildTranslateElement(word1Valid, word2Valid);
        translateElement * element2 = buildTranslateElement(word2Valid, word1Valid);

        fakeAdd(base, element1);
        fakeAdd(base, element2);
        free(word1Valid);
        free(word2Valid);
    }

    printf("Используется словарь: %s\n", filePath);
    while (1){
        printf("Введите слово: ");
        DynamicString * inputString = initString();
        readToString(inputString);


        char *validString = trim(inputString->string);

        freeString(inputString);

        if (strcmp(validString, "q") == 0) {
            printf("выход из программы\n");
            exit(0);
        }

        int searchResult = fakeLikeSearch(base, validString);
        if (searchResult == -1){
            printf("Перевод не найден\n");
            continue;
        }

        printf("Перевод: %s\n", base->elements[searchResult]->transfer);


    }

}
