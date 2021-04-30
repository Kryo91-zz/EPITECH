/*
** EPITECH PROJECT, 2019
** asm
** File description:
** labels_list.c
*/

#include "asm.h"

void add_label(label_t **list, char *name, int pos)
{
    label_t *current = *list;
    label_t *new = malloc(sizeof(*new));

    if (name[my_strlen(name) - 1] == LABEL_CHAR)
        name[my_strlen(name) - 1] = 0;
    if (!is_right_chars(name, LABEL_CHARS))
        my_exit("Wrong label characters\n", 84);
    new->next = NULL;
    new->name = name;
    new->pos = pos;
    if (!(*list))
        *list = new;
    else {
        while (current->next)
            current = current->next;
        current->next = new;
    }
}

void destroy_label_list(label_t *list)
{
    label_t *tmp = list;

    while (list) {
        tmp = list;
        list = list->next;
        free(tmp->name);
        free(tmp);
    }
}

bool get_relative_value(file_data_t *data, char *lb, int inst_pos, int *val)
{
    label_t *current = data->labels;

    while (current) {
        if (!my_strcmp(current->name, lb)) {
            *val = current->pos - inst_pos + 3;
            break;
        }
        current = current->next;
    }
    return ((bool)(current));
}

bool replace_label_in_str(char **str, file_data_t *data, instruction_t *op)
{
    int value = 0;
    char *tmp = NULL;

    tmp = *str;
    if ((tmp)[0] == LABEL_CHAR || (tmp)[1] == LABEL_CHAR) {
        tmp += (tmp)[0] == LABEL_CHAR ? 1 : 2;
        if (!get_relative_value(data, tmp, op->pos, &value))
            return (bool_message("Undefined label\n", false, 2, NULL));
        tmp = (*str)[0] == DIRECT_CHAR ? str_slice(*str, 0, 1) : NULL;
        tmp = my_freecat(tmp, my_itos(value));
        free(*str);
        *str = tmp;
    }
    return (true);
}

bool replace_labels(file_data_t *data, instruction_t *op)
{
    char **args = op->args;
    label_t *lb = data->labels;

    if (!op->op)
        return (true);
    while (lb) {
        if (!is_right_chars(lb->name, LABEL_CHARS))
            return (false);
        lb = lb->next;
    }
    for (int i = 0; args[i]; i++) {
        if (!replace_label_in_str(&(args[i]), data, op))
            return (false);
    }
    return (true);
}