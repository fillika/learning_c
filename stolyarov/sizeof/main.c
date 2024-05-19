#include <stdio.h>

int main() {
    printf("Char has %lu byte length\n", sizeof(char));
    printf("Short has %lu byte length\n", sizeof(short));
    printf("Int has %lu byte length\n", sizeof(int));
    printf("Long has %lu byte length\n", sizeof(long));
    printf("Long Long has %lu byte length\n", sizeof(long long));
    printf("Float has %lu byte length\n", sizeof(float));
    printf("Double has %lu byte length\n", sizeof(double));
    printf("Long Double has %lu byte length\n", sizeof(long double));
    return 0;
}