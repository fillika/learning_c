#include <stdio.h>
#include <string.h>

#define MAX_STRING 200

/*
    Сашке не достанется кулича.
    Этот комментарий надо удалить
    
    */

// И этот тоже!

int reverse(char str[])
{
    int i;
    int length = strlen(str);

    for (i = length; i >= 0; i--)
        printf("%c", str[i]);

    printf("\n");

    return 0;
}