/*
** EPITECH PROJECT, 2019
** lib
** File description:
** chompline.c
*/

#include "../../include/my.h"

ssize_t chompline(char **lineptr, size_t *n, FILE *stream)
{
    char *line = NULL;
    ssize_t ret = getline(&line, n, stream);
    size_t len = 0;

    if (ret < 0) {
        *n = 0;
        return (-1);
    }
    len = my_strlen(line);
    if (line[len - 1] == '\n' && len != 1)
        line[len - 1] = 0;
    *lineptr = line;
    return (ret);
}

int get_smp_line(FILE *filestream, char **line_ptr)
{
    size_t n = 0;
    ssize_t ret = 0;

    if (*line_ptr)
        free(line_ptr);
    do {
        ret = chompline(line_ptr, &n, filestream);
    } while (ret > 0 && !str_is_blank(*line_ptr));
    if (ret == -1) {
        free(*line_ptr);
        return (-1);
    }
    return (ret);
}