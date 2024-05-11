#include <stdio.h>
/*
Упражнение 3.2. Напишите функцию escape(s, t), которая при копировании текста из t в s преобразует
такие символы, как новая строка и табуляция в "видимые последовательности символов" (вроде \n и \t).
Используйте инструкцию switch. Напишите функцию, выполняющую обратное преобразование эскейп-
последовательностей в настоящие символы.
*/
void escape(char s[], char t[])
{
    int i;
    i = 0;
    while (t[i] != '\0')
    {
        switch (t[i])
        {
        case '\n':
            s[i] = '\\';
            s[++i] = 'n';
            break;
        case '\t':
            s[i] = '\\';
            s[++i] = 't';
            break;
        default:
            s[i] = t[i];
        }

        ++i;
    }

    s[i] = '\0';
}

void reversed_escape(char s[], char t[])
{
    int i, j;
    i = j = 0;

    while (t[i] != '\0')
    {
        switch (t[i])
        {
        case '\\':
            if (t[i + 1] == 'n')
            {
                s[j] = '\n';
                ++i;
                break;
            }
            if (t[i + 1] == 't')
            {
                s[j] = '\t';
                ++i;
                break;
            }
        default:
            s[j] = t[i];
        }

        ++i;
        ++j;
    }

    s[j] = '\0';
}

int main()
{
    char empty[20];
    char str[] = "Hello\\t, World!\\nMy name \\is C lang.";

    reversed_escape(empty, str);
    printf("Result is: %s", empty);
    printf("\n");
}