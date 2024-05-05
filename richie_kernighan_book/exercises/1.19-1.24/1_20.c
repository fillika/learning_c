#include <stdio.h>

#define AMOUNT_OF_SPACE 4

int detab()
{
    int c, i;

    while ((c = getchar()) != EOF)
    {
        if (c == '\t')
            for (i = 0; i < AMOUNT_OF_SPACE; i++)
                printf("^");
        else
            printf("%c", c);
    }

    printf("\n");

    return 0;
}