/*
** EPITECH PROJECT, 2019
** error
** File description:
** Str to word array
*/

#include <unistd.h>
#include <stdlib.h>
#include "../inc/struct_bistro.h"

int is_delimiter(char c, argument_t argument)
{
    for (int i = 0; argument.delimiter[i] != '\0'; ++i) {
        if (c == argument.delimiter[i])
            return (1);
    }
    return (0);
}

void fill_tab(argument_t *argument, int i, int count, int count2)
{
    int start = 0;

    for (int j = (i - count); j != i; ++j) {
        argument->result[count2][start] = argument->str[j];
        start++;
    }
    argument->result[count2][start] = '\0';
}

void fill_array(argument_t *argument)
{
    int count2 = 0;

    for (int i = 0, count = 0; argument->str[i] != '\0'; i++) {
        if (is_delimiter(argument->str[i], *argument)) {
            if (count > 0) {
                argument->result[count2] = malloc(sizeof(char)* (count + 1));
                fill_tab(argument, i, count, count2 += 1);
                count = 0;
            }
            argument->result[count2] = malloc(sizeof(char)* 2);
            argument->result[count2][0] = argument->str[i];
            argument->result[count2 += 1][1] = '\0';
        } else if (argument->str[i + 1] == '\0' && count > 0) {
            argument->result[count2] = malloc(sizeof(char)* (count + 2));
            fill_tab(argument, i + 1, count + 1, count2 += 1);
        } else
            count++;
    }
    argument->result[count2] = NULL;
}

void init_array(argument_t *argument)
{
    int count = 0;
    int last_delimiter = 1;
    int count2 = 0;

    for (int i = 0; argument->str[i] != '\0'; i++) {
        if (is_delimiter(argument->str[i], *argument)) {
            count++;
            last_delimiter = 1;
        } else if (last_delimiter) {
            count++;
            last_delimiter = 0;
        }
    }
    argument->result = malloc(sizeof(char *) * (count + 1));
    fill_array(argument);
}

char **my_str_to_word_array(char *str, char *delimiter)
{
    argument_t argument;

    argument.delimiter = delimiter;
    argument.str = str;
    init_array(&argument);
    return argument.result;
}