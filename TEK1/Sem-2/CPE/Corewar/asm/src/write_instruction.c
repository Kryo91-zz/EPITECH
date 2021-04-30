/*
** EPITECH PROJECT, 2019
** asm
** File description:
** write_instruction.c
*/

#include "asm.h"

void write_args(int fd, instruction_t *inst, char **args)
{
    args_type_t type = T_UNKOWN;

    for (int i = 0; args[i]; i++) {
        type = detect_types(args[i]);
        switch (type) {
        case T_DIR:
            write_dir(fd, args[i], direct_is_index(inst->op));
            break;
        case T_IND:
            write_ind(fd, args[i]);
            break;
        default:
            write_reg(fd, args[i]);
            break;
        }
    }
}

void write_instruction(int fd, instruction_t *inst)
{
    if (!inst->op)
        return;
    for (int i = 0; op_tab[i].mnemonique; i++)
        if (!my_strcmp(op_tab[i].mnemonique, inst->op)) {
            inst->opcode = op_tab[i].code;
            break;
        }
    write(fd, &(inst->opcode), 1);
    if (my_strcmp(inst->op, "live") && my_strcmp(inst->op, "zjmp") && \
    my_strcmp(inst->op, "fork") && my_strcmp(inst->op, "lfork"))
        write(fd, &(inst->coding_byte), 1);
    write_args(fd, inst, inst->args);
}

void write_header(int fd, file_data_t data)
{
    int magic = COREWAR_EXEC_MAGIC;
    char name[NAME_LEN + 1] = {};
    char comment[COMM_LEN + 1] = {};
    int tmp = 0;

    my_strcpy(name, data.name);
    my_strcpy(comment, data.comment);
    write_big_endian(fd, &magic, sizeof(int));
    write(fd, name, NAME_LEN);
    write_big_endian(fd, &data.size, sizeof(data.size));
    write(fd, comment, COMM_LEN);
    write(fd, &tmp, sizeof(tmp));
}