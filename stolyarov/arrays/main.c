#include <stdio.h>

int main() {
    int i;
    int m[20];
    int *p;

    p = m;

    for (i = 0; i < 20; i++)
        p[i] = i + 8;    

    printf("Index 4 is: %d\n", p[4]);
    printf("sizeof arr is: %ld\n", sizeof(m));

    return 0;
}