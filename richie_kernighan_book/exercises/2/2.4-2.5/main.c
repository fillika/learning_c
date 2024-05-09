#include <stdio.h>

enum
{
    NO_COPY = 0,
    COPY
};
/*
Упражнение 2.4. Напишите версию функции squeeze(s1, s2), которая удаляет из s1 все символы,
встречающиеся в строке s2.

squeeze("Hello, world!", "well"); // "Ho, ord!"

*/
void squeeze(char s[], char t[])
{
    int i, k, j;
    int flag;
    flag = COPY;
    i = k = 0;

    while (s[i] != '\0')
    {
        flag = COPY;

        for (j = 0; t[j] != '\0'; j++)
        {
            if (s[i] == t[j])
            {
                flag = NO_COPY;
                continue;
            }
        }

        if (flag == COPY)
            s[k++] = s[i];

        i++;
    }

    s[k] = '\0';
}

/*
Упражнение 2.5. Напишите функцию any(s1, s2), которая возвращает либо ту позицию в s1, где стоит
первый символ, совпавший с любым из символов в s2, либо -1 (если ни один символ из s1 не совпадает с
символами из s2). (Стандартная библиотечная функция strpbrk делает то же самое, но выдает не номер
позиции символа, а указатель на символ.)
*/

int any(char s1[], char s2[])
{
    int pos, j;
    pos = 0;

    while (s1[pos] != '\0')
    {
        for (j = 0; s2[j] != '\0'; j++)
        {
            if (s2[j] == s1[pos])
                return pos;
        }
        ++pos;
    }

    return -1;
}

int main()
{
    char str1[] = "Hello, world!";
    squeeze(str1, "well");
    printf("squeeze result is: %s\n", str1);

    /* 2.5 */
    printf("%d\n", any("Hello world!", "go"));   // 4
    printf("%d\n", any("Hello world!", "Hi"));   // 0
    printf("%d\n", any("Hello world!", "like")); // 1
    printf("%d\n", any("Hello world!", "fu*k")); // -1

    return 0;
}