#include <stdio.h>
#include <stdlib.h>

int string_len(const char *str);
void string_copy(char *dest, const char *src);

int main()
{
    char *dest;

    dest = malloc(100 * sizeof(int));

    printf("len: %d\n", string_len("Hello, World!"));
    string_copy(dest, "Hello, World! My name is Aleksandr.");
    printf("result of copy: %s\n", dest);

    free(dest);
    return 0;
}

int string_len(const char *str)
{
    int i = 0;

    while (str[i] != '\0')
        i++;

    return i;
}

void string_copy(char *dest, const char *src)
{
    int i;

    for (i = 0; src[i] != '\0'; i++)
        dest[i] = src[i];

    dest[i] = '\0';
}
