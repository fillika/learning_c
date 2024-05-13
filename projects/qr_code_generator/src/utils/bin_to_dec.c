#include <string.h>

int binary_to_decimal(char bin[])
{
    int len, i, result;
    result = 0;
    len = strlen(bin);

    for (i = 0; i < len; i++)
        result = result * 2 + (bin[i] - '0');

    return result;
}