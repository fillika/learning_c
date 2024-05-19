#include <stdio.h>

int main()
{
    int i;
    int m[20];
    int t1[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    int t2[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9}; // len also will be 10
    int *p;

    p = m;

    for (i = 0; i < 20; i++)
        p[i] = i + 8;

    printf("Index 4 is: %d\n", p[4]);
    printf("sizeof arr is: %ld\n", sizeof(m));
    printf("sizeof t1 is: %ld\n", sizeof(t1));

    for (i = 0; i < sizeof(t2) / sizeof(*t2); i++)
        printf("[%d] = %d\n", i, t2[i]);

    return 0;
}