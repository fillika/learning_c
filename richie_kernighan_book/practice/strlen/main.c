#include <stdio.h>

enum boolean
{
    NO = 0,
    YES
};

int str_len(char s[])
{
    int i;
    i = 0;
    while (s[i] != '\0')
        ++i;

    return i;
}

int main()
{
    printf("\"%s\" len is: %d\n", "Hello world!", str_len("Hello world!"));
    printf("\"%s\" len is: %d\n", "Bye", str_len("Bye"));
    printf("\"%s\" len is: %d\n", "C++", str_len("C++"));
    printf("\"%s\" len is: %d\n", "Programming", str_len("Programming"));
    printf("Bool NO is: %d\n", NO);
    printf("Bool YES is: %d\n", YES);
    return 0;
}