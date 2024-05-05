#include <stdio.h>

#define BUFFER_SIZE 1000

int deleteCommentsFromFile(char filename[])
{
    FILE *file;
    int c, next_char, prev_char;
    int bytes_read, is_multi_line_comment, is_single_line_comment;
    int cleared_counter, multi_line_counter;
    char buffer[BUFFER_SIZE], cleared_buffer[BUFFER_SIZE];

    cleared_counter = multi_line_counter = is_multi_line_comment = is_single_line_comment = 0;

    printf("Read from filename: %s\n", filename);

    file = fopen(filename, "r");
    if (file == NULL)
    {
        printf("Error\n");
        return 1;
    }

    // Чтение данных из файла в буфер
    bytes_read = fread(buffer, sizeof(char), sizeof(buffer), file);
    if (bytes_read == 0)
    {
        fprintf(stderr, "Ошибка чтения файла '%s'.\n", filename);
        fclose(file);
        return 1;
    }

    for (int i = 0; i < BUFFER_SIZE; i++)
    {
        c = buffer[i];
        prev_char = buffer[i - 1];
        next_char = buffer[i + 1];

        if (is_multi_line_comment == 0 || is_single_line_comment == 0)
        {
            if (c == 47)
            {
                if (next_char == 42)
                    is_multi_line_comment = 1;
                else if (next_char == 47)
                    is_single_line_comment = 1;
            }
        }

        if (is_multi_line_comment == 1)
        {
            if (c == 47 && prev_char == 42)
            {
                is_multi_line_comment = 0;
                is_single_line_comment = 0;
            }
            continue;
        }

        if (is_single_line_comment == 1)
        {
            if (c == '\n')
            {
                is_single_line_comment = 0;
                cleared_buffer[cleared_counter++] = c;
            }
            continue;
        }

        if (c == EOF)
            break;

        cleared_buffer[cleared_counter++] = c;
    }

    fclose(file);

    printf("Comments have been cleared. Result:\n\n%s\n", cleared_buffer);
    return 0;
}