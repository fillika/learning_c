#include <stdio.h>

int main()
{
    int i, c, lim;
    lim = 20;
    char s[lim];

    for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
        s[i] = c;

    s[i] = '\0'; // Добавляем в конце, чтобы строка была корректна

    printf("Result is: %s\n", s);
}