#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *decimal_to_binary(int n)
{
    char *binary_string = (char *)malloc(9 * sizeof(char)); // Для 8 бит + 1 символ для нуль-терминатора
    if (binary_string == NULL)
    {
        printf("Memory allocation failed!\n");
        exit(EXIT_FAILURE);
    }

    int i;
    for (i = 7; i >= 0; --i)
    {
        int bit = (n >> i) & 1;
        binary_string[7 - i] = bit + '0'; // Преобразование цифры в символ '0' или '1'
    }
    binary_string[8] = '\0'; // Нуль-терминатор строки

    return binary_string;
}