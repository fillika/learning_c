#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "./enums/enums.h"
#include "./encoding/per_byte.h"
#include "./utils/bin_to_dec.h"

#define DIGITAL_ENCODING_TYPE 0b001
#define DIG_LIT_ENCODING_TYPE 0b010
#define BYTE_ENCODING_TYPE 0b100

#define EMPTY_BYTE_1 "11101100"
#define EMPTY_BYTE_2 "00010001"

char test_data[] = "Hello, world!"; // 1101000010100101110100001011000011010000101100011101000110000000

/*
https://habr.com/ru/articles/172525/
https://www.thonky.com/qr-code-tutorial/data-encoding

#1 Перевести данные в двоичный вид
#2 Указать тип кодирования, с помощью которого Я переводил эти данные.
#3 В зависимости от версии указать длину данных между типом и данными

DIGITAL_ENCODING_TYPE

0010 - 000000111 - 10010...10

*/

int main()
{
    int i, amount_of_correction_bytes;
    int empty_byte_order = 0;

    // todo how to define verion of QR
    char *binary = per_byte_coding(test_data, FIRST);
    if (binary != NULL)
    {
        // На этом этапе у меня есть строковое выражение данных в двоичном
        // виде со всеми служебными добавлениями

        // Сейчас нужно добавить нулей для размера, кратного 8.
        while (strlen(binary) % 8 != 0)
            strcat(binary, "0");

        // todo определить конечную длину, согласно Qr_versions и CorrectionLevel

        int data_len = 128;
        // Для уровня QR == FIRST и CorrectionLevel == M длина будет 128

        // Следом добавить 2 пустых байта поочередно, пока не наберем нужную длину
        while (strlen(binary) <= data_len) // todo get it from table or formula
            strcat(binary, empty_byte_order++ % 2 == 0 ? EMPTY_BYTE_1 : EMPTY_BYTE_2);

        // todo определить кол-во блоков, на которые делятся данные.
        int amount_of_blocks = data_len / 1;

        // todo определить кол-во байтов коррекции по формуле (где искать - хз)
        // В таблице для QR == FIRST и CorrectionLevel == M кол-во равно 10
        amount_of_correction_bytes = 10;
        int correction_bytes[10] = {251, 67, 46, 61, 118, 70, 64, 94, 32, 45};
        int data_bytes[data_len / 8];

        char byte[9];

        for (i = 0; i < data_len; i++)
        {
            if (i % 8 != 0)
                strcat(byte, binary[i]);
            else
            {
                // todo доработать
                data_bytes[(i / 8) - 1] = binary_to_decimal(byte);
                byte[0] = '\0';
            }
        }

        // todo придумать нормальное имя
        int arr[data_len + amount_of_correction_bytes];
        for (i = 0; i < data_len + correction_bytes; i++)
            arr[i] = binary[i] != '\0'
                         ? binary[i] == '0' ? 0 : 1
                         : 0;

        for (i = 0; i < data_len + correction_bytes; i++)
            printf("%d", arr[i]);

        printf("\n%s\n", binary);

        free(binary);
    }
    else
        printf("Failed to convert string to binary.\n");

    return 0;
}
