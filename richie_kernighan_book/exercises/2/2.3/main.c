/*
Упражнение 2.З. Напишите функцию htol(s), которая преобразует последовательность
шестнадцатеричных цифр, начинающуюся с 0х или 0Х, в соответствующее целое. Шестнадцатеричными
цифрами являются символы 0…9, а…f, А…F.
*/

#include <stdio.h>

#define HEX_BASE 16
#define LOWER_ASCII_DECREMENT 10

int to_lower(int c)
{
    if (c >= 'A' && c <= 'Z')
        return c + 32;
    return c;
}

int htol(char s[])
{
    int i, result, num_dig, c;
    result = num_dig = 0;

    if (s[0] == '0' && 'x' == to_lower(s[1]))
    {
        for (i = 2; s[i] != '\0'; i++)
        {
            c = to_lower(s[i]);

            if (c >= 97 && c <= 102)
                result = HEX_BASE * num_dig * result + (c - LOWER_ASCII_DECREMENT);
            else if (s[i] >= '0' && s[i] <= '9')
                result = HEX_BASE * num_dig * result + (c - '0');
            else
            {
                printf("Incorrect format of hex number: %s\n", s);
                return 1;
            }
            ++num_dig;
        }

        return result;
    }
    else
    {
        printf("Incorrect format of hex number: %s\n", s);
        return 1;
    }
}

int main()
{
    printf("Result is: %d\n", htol("0x1")); // 1
    printf("Result is: %d\n", htol("0x16")); // 22
    printf("Result is: %d\n", htol("0xa")); // 10
    printf("Result is: %d\n", htol("0xA")); // 10
    printf("Result is: %d\n", htol("0xff")); // 255
    printf("Result is: %d\n", htol("1xff")); // error
}