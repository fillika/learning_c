#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "./enums/enums.h"
#include "./encoding/per_byte.h"

#define DIGITAL_ENCODING_TYPE 0b001
#define DIG_LIT_ENCODING_TYPE 0b010
#define BYTE_ENCODING_TYPE 0b100

char test_data[] = "Прив";

/*
https://habr.com/ru/articles/172525/

#1 Перевести данные в двоичный вид
#2 Указать тип кодирования, с помощью которого Я переводил эти данные.
#3 В зависимости от версии указать длину данных между типом и данными

DIGITAL_ENCODING_TYPE

0010 - 000000111 - 10010...10

*/

int main()
{
    // todo how to define verion of QR
    char *binary = per_byte_coding(test_data, FIRST);
    if (binary != NULL)
    {
        printf("Binary representation of '%s': %s\n", test_data, binary);
        free(binary);
    }
    else
        printf("Failed to convert string to binary.\n");

    return 0;
}
