#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
    int i;
    double *k;
    k = malloc(360 * sizeof(double));

    for (i = 0; i < 360; i++)
        k[i] = sin((2 * M_PI/360) * (double)i);    

    printf("Index 26 is: %f\n", k[26]);

    free(k);
    return 0;
}