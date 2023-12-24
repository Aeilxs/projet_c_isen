#include "utils/strings.h"

void trim(char *str, char removed) {
    int count = 0;
    for (int i = 0; str[i]; i++) {
        if (str[i] != removed) str[count++] = str[i];
    }
    str[count] = '\0';
}