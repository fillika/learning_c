#include <stdio.h>

void squeeze(char s[], int c)
{
    int i, j;
    for (i = j = 0; s[i] != '\0'; i++)
        if (s[i] != c)
            s[j++] = s[i];
    s[j] = '\0';
}

void str_cat(char s[], char t[])
{
    int i, j;
    i = j = 0;
    while (s[i] != '\0')
        i++;

    while (t[j] != '\0')
    {
        s[i++] = t[j++];
    }
    s[i] = '\0';
}

int main()
{
    char str[] = "Hello, World!";
    char str1[64] = "This text was added -> ";
    char str2[] = "OMG";
    squeeze(str, 'o');
    str_cat(str1, str2);
    printf("Squezeeeeeed: %s\n", str);
    printf("STR_CAT: %s\n", str1);
    return 0;
}