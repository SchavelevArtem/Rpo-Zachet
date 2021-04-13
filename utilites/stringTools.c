#include "stringTools.h"

char *trim(char *spaced)
{
    int length = strlen(spaced);

    while (isspace(spaced[length - 1]))
        --length;
    while (*spaced && isspace(*spaced))
        ++spaced, --length;

    return strndup(spaced, length);
}