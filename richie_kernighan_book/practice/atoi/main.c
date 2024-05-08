#include <stdio.h>

/* atoi: преобразование s в целое */
int atoi(char s[])
{
    int i, n;
    n = 0;
    for (i = 0; s[i] >= '0' && s[i] <= '9'; ++i)
        n = 10 * n + (s[i] - '0');
    return n;
}

int main()
{

    float f1 = 2.14213123;
    double d1 = 2.65432;
    int x = 3;

    double d2 = (double) f1;

    printf("Result is: %d\n", atoi("245"));
    printf("Result is: %f\n", (float)d1);
    return 0;
}