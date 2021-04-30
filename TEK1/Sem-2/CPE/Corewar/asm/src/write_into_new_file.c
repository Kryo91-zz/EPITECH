/*
** EPITECH PROJECT, 2019
** asm
** File description:
** write_into_new_file.c
*/

#include "asm.h"

byte_t make_cbyte(byte_t coding_byte, args_type_t type, int offset)
{
    byte_t part = 0;

    if (type == T_DIR) {
        part = 2;
    } else if (type == T_IND) {
        part = 3;
    } else {
        part = 1;
    }
    return (coding_byte | (part << offset));
}

int direct_is_index(char *op)
{
    if (!my_strcmp(op, "ldi") || !my_strcmp(op, "zjmp") || \
    !my_strcmp(op, "lldi") || !my_strcmp(op, "fork") || \
    !my_strcmp(op, "sti") || !my_strcmp(op, "lfork") || !my_strcmp(op, "ld"))
        return (2);
    return (4);
}

int fill_instruction(instruction_t *new)
{
    int offset = 6;
    args_type_t type = T_UNKOWN;

    new->size = new->op ? 1 : 0;
    new->coding_byte = 0;
    for (int i = 0; new->op && new->args[i]; i++) {
        type = detect_types(new->args[i]);
        if (type == T_DIR) {
            new->size += direct_is_index(new->op);
        } else if (type == T_IND) {
            new->size += 2;
        } else
            new->size += 1;
        new->coding_byte = make_cbyte(new->coding_byte, type, offset);
        offset -= 2;
    }
    if (new->op && my_strcmp(new->op, "live") && my_strcmp(new->op, "zjmp") \
    && my_strcmp(new->op, "fork") && my_strcmp(new->op, "lfork"))
        new->size += 1;
    return (new->size);
}

bool fill_data_struct(file_data_t *data)
{
    char **tmp = NULL;
    instruction_t *nw = NULL;

    for (int i = 0; data->file && data->file[i]; i++) {
        tmp = my_word_array(data->file[i]);
        nw = malloc(sizeof(*nw));
        nw->to_free = tmp;
        if (tmp[0][my_strlen(tmp[0]) - 1] == LABEL_CHAR)
            add_label(&data->labels, my_strdup(tmp[0]), data->size);
        nw->op = tmp[0][my_strlen(tmp[0]) - 1] == LABEL_CHAR ? tmp[1] : tmp[0];
        nw->args = nw->op == tmp[1] ? tmp + 2 : tmp + 1;
        data->size += fill_instruction(nw);
        nw->pos = data->size;
        data->inst = append_array(data->inst, nw);
    }
    for (int i = 0; data->inst && data->inst[i]; i++)
        if (!replace_labels(data, data->inst[i]))
            return (bool_message("Wrong label chars\n", false, 2, NULL));
    return (true);
}

bool write_into_new_file(file_data_t data, char const *name)
{
    char *filename = my_strcat(name, ".cor");
    int fd = open(filename, O_WRONLY | O_CREAT, 0644);

    if (fd == - 1 || !fill_data_struct(&data))
        return (false);
    write_header(fd, data);
    for (int i = 0; data.inst &&
     data.inst[i]; i++)
        write_instruction(fd, data.inst[i]);
    if (close(fd))
        return (false);
    return (true);
}