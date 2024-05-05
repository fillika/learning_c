#include <stdio.h>

int wordWrap(int wrap)
{
    int c, i, counter;

    counter = 0;

    while ((c = getchar()) != EOF)
    {
        ++counter;
        printf("%c", c);
        if (counter > wrap && c == 32)
        {
            counter = 0;
            printf("\n");
        }
    }

    printf("\n");

    return 0;
}