#include <stdio.h>
#include <limits.h>
#include <float.h>

int main() {
    printf("Диапазоны чисел:\n");
    printf("char\n\tsigned:   [%d, %d]\n\tunsigned: [0, %u]\n", CHAR_MIN, CHAR_MAX, UCHAR_MAX);
    printf("short\n\tsigned:   [%d, %d]\n\tunsigned: [0, %u]\n", SHRT_MIN, SHRT_MAX, USHRT_MAX);
    printf("int\n\tsigned:   [%d, %d]\n\tunsigned: [0, %u]\n", INT_MIN, INT_MAX, UINT_MAX);
    printf("long\n\tsigned:   [%ld, %ld]\n\tunsigned: [0, %lu]\n", LONG_MAX, LONG_MIN, ULONG_MAX);

    // floats
    printf("float\n\t[%f, %f]\n", FLT_MIN, FLT_MAX);
    printf("double\n\t[%lf, %lf]\n", DBL_MIN, DBL_MAX);
    printf("long double\n\t[%Lf, %Lf]\n", LDBL_MIN, LDBL_MAX);
}