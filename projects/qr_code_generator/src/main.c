#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "./enums/enums.h"
#include "./encoding/per_byte.h"

#define DIGITAL_ENCODING_TYPE 0b001
#define DIG_LIT_ENCODING_TYPE 0b010
#define BYTE_ENCODING_TYPE 0b100

#define EMPTY_BYTE_1 "11101100"
#define EMPTY_BYTE_2 "00010001"

char test_data[] = "Хабр"; // 1101000010100101110100001011000011010000101100011101000110000000

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
        printf("Binary representation of '%s': %s\n", test_data, binary); // todo clean
        printf("len: %lu\n", strlen(binary));                             // todo clean

        // На этом этапе у меня есть строковое выражение данных в двоичном
        // виде со всеми служебными добавлениями

        // Сейчас нужно добавить нулей для размера, кратного 8.

        while (strlen(binary) % 8 != 0)
            strcat(binary, "0");

        // todo определить конечную длину, согласно Qr_versions и CorrectionLevel

        // Следом добавить 2 пустых байта поочередно, пока не наберем нужную длину

        free(binary);
    }
    else
        printf("Failed to convert string to binary.\n");

    return 0;
}
