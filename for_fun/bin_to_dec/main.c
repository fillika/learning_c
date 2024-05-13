#include <stdio.h>
#include <string.h>

int bin_to_decimal(char bin[])
{
    int len, i, result;
    result = 0;
    len = strlen(bin);

    for (i = 0; i < len; i++)
        result = result * 2 + (bin[i] - '0'); // Умножаем на 2 и добавляем значение каждого бита

    return result;
}

int main()
{
    printf("Result is: %d\n", bin_to_decimal("10"));       // 2
    printf("Result is: %d\n", bin_to_decimal("00000010")); // 2
    printf("Result is: %d\n", bin_to_decimal("00000011")); // 3
    printf("Result is: %d\n", bin_to_decimal("0011"));     // 3
    printf("Result is: %d\n", bin_to_decimal("00000000")); // 0
    printf("Result is: %d\n", bin_to_decimal("00000001")); // 1
    printf("Result is: %d\n", bin_to_decimal("110"));      // 6
    printf("Result is: %d\n", bin_to_decimal("000110"));   // 6
    printf("Result is: %d\n", bin_to_decimal("00000110")); // 6
    printf("Result is: %d\n", bin_to_decimal("1000"));     // 8
    printf("Result is: %d\n", bin_to_decimal("00001000")); // 8
}