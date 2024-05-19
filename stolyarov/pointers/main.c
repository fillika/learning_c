#include <stdio.h>

void swap(int *a, int *b);

int main()
{
    int x, y;
    int *p, *q, *r;

    x = 25;
    y = 36;
    p = &x;
    q = &y;
    r = p;

    printf("x == %d\n", x);
    printf("p == %d\n", *p);
    printf("q == %d\n", *q);
    printf("r == %d\n", *r);

    printf("x == %d, y == %d\n", x, y);
    swap(&x, &y);
    printf("Swap x and y...\n");
    printf("x == %d, y == %d\n", x, y);

    return 0;
}

void swap (int *a, int *b) {
    int t;
    t = *a;
    *a = *b;
    *b = t;
}