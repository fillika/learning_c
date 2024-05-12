#include <stdio.h>
#include <stdlib.h>

void scan_double(char text[], double *d);
void scan_char(char text[], char *c);

int main()
{
    double x, y;
    char operation;

    scan_double("Input x = ", &x);
    scan_double("Input y = ", &y);
    scan_char("Select operation (+, -, *, /) = ", &operation);

    switch (operation)
    {
    case '+':
        printf("%lf %c %lf = %lf\n", x, operation, y, x + y);
        break;
    case '-':
        printf("%lf %c %lf = %lf\n", x, operation, y, x - y);
        break;
    case '*':
        printf("%lf %c %lf = %lf\n", x, operation, y, x * y);
        break;
    case '/':
        printf("%lf %c %lf = %lf\n", x, operation, y, x / y);
        break;
    default:
        printf("Wrong operator {%c}\n", operation);
        break;
    }
}

void scan_int(char text[], int *x)
{
    printf("%s", text);
    scanf("%d", x);
}

void scan_double(char text[], double *d)
{
    printf("%s", text);
    scanf("%lf", d);
}

void scan_char(char text[], char *c)
{
    printf("%s", text);
    scanf(" %c", c);
}