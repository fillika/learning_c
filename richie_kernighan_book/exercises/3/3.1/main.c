#include <stdio.h>
#include <time.h>

#define SIZE_OF_ARRAY 1000000

int binsearch(int x, int v[], int n)
{
    int low, high, mid;
    low = 0;
    high = n - 1;
    while (low <= high)
    {
        mid = (low + high) / 2;
        if (x < v[mid])
            high = mid - 1;
        else if (x > v[mid])
            low = mid + 1;
        else
            return mid;
    }
    return -1;
}

// SOLVE
int binsearch_2(int x, int v[], int n)
{
    int low, high, mid;
    low = 0;
    high = n - 1;
    mid = (low + high) / 2;
    while (low <= high && x != v[mid])
    {
        if (x < v[mid])
            high = mid - 1;
        else
            low = mid + 1;

        mid = (low + high) / 2;
    }

    if (x == v[mid])
        return mid;

    return -1;
}

/*
Упражнение 3.1. В нашей программе бинарного поиска внутри цикла осуществляются две проверки, хотя
могла быть только одна (при увеличении числа проверок вне цикла). Напишите программу, предусмотрев в
ней одну проверку внутри цикла. Оцените разницу во времени выполнения.
*/

int main()
{
    int ordered_arr[SIZE_OF_ARRAY];
    int result;

    for (size_t i = 0; i < SIZE_OF_ARRAY; i++)
        ordered_arr[i] = i + 2;

    clock_t start = clock();
    result = binsearch_2(10, ordered_arr, SIZE_OF_ARRAY);
    clock_t end = clock();

    double time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;

    printf("Time is: %10f seconds\n", time_taken);
    printf("Result is: %d\n", result);
}