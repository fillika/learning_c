#include <stdlib.h>
#include <string.h>
#include "per_byte.h"
#include "../enums/enums.h"
#include "../utils/decimal_to_bin.h"

#define CODING_TYPE_SIZE 4

char *per_byte_coding(char text[], enum Qr_versions version)
{
    int len = strlen(text);
    int v = version < TENTH ? 8 : 16;
    char *binary = malloc(len * 8 + v + CODING_TYPE_SIZE + 1); // +4 - способ кодирования (0100), +8 - Побайтовое кодирование для версий 1-9
    if (binary == NULL)
        return NULL;

    binary[0] = '\0'; // Обнуляем строку

    strcat(binary, "0100");

    char* binary_string = decimal_to_binary(len);
    strcat(binary, binary_string);
    free(binary_string);

    for (int i = 0; text[i] != '\0'; ++i)
    {
        char ch = text[i];
        for (int j = 7; j >= 0; --j)
            strcat(binary, ((ch >> j) & 1) ? "1" : "0");
    }

    // binary[i] = '\0';

    return binary;
}