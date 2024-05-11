#include <stdio.h>
#include <stdbool.h>

/*
Упражнение 3.3. Напишите функцию expand(s1, s2), заменяющую сокращенную запись наподобие a-z в
строке s1 эквивалентной полной записью abc. . . xyz в s2. В s1 допускаются буквы (прописные и строчные) и
цифры. Следует уметь справляться с такими случаями, как a-b-c, a-z0-9 и -а-b. Считайте знак - в начале или в
конце s1 обычным символом минус.
*/

void expand(char s1[], char s2[])
{
    int i, j, y;
    int first_char, last_char;
    bool is_lower_case_letters, is_upper_case_letters, is_numbers;

    first_char = last_char = -1;
    i = j = 0;

    while (s1[i] != '\0')
    {
        if (s1[i] == '-')
        {
            first_char = s1[i - 1];
            last_char = s1[i + 1];

            is_lower_case_letters = first_char >= 'a' && first_char <= 'z' && last_char >= 'a' && last_char <= 'z';
            is_upper_case_letters = first_char >= 'A' && first_char <= 'Z' && last_char >= 'A' && last_char <= 'Z';
            is_numbers = first_char >= '0' && first_char <= '9' && last_char >= '0' && last_char <= '9';

            if (is_lower_case_letters || is_upper_case_letters || is_numbers)
                for (y = first_char; y <= last_char; y++)
                    s2[j++] = y;
        }

        ++i;
    }

    s2[j] = '\0';
}

int main()
{
    char str1[] = "a-z0-9";
    char str2[100];

    expand(str1, str2);
    printf("Result is: %s\n", str2);
}