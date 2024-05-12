#include <stdlib.h>
#include <string.h>
#include "per_byte.h"
#include "../enums/enums.h"

char *per_byte_coding(char text[], enum Qr_versions version)
{
    int len = strlen(text);
    int v = version < TENTH ? 8 : 16;
    char *binary = malloc(len * 8 + 4 + v + 1); // +4 - способ кодирования (0100), +8 - Побайтовое кодирование для версий 1-9
    if (binary == NULL)
        return NULL;
    binary[0] = '\0'; // Обнуляем строку

    for (int i = 0; i < len; ++i)
    {
        char ch = text[i];
        for (int j = 7; j >= 0; --j)
            strcat(binary, ((ch >> j) & 1) ? "1" : "0");
    }

    return binary;
}