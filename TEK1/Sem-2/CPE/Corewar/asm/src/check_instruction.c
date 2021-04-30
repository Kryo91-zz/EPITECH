/*
** EPITECH PROJECT, 2019
** Corewar, asm
** File description:
** Check if an assembly instruction is valid
*/

#include "asm.h"

bool check_arguments(op_t instruction, char **arguments)
{
    args_type_t detected = 0;

    if ((int)array_len(arguments) != instruction.nbr_args)
        return (bool_message("Wrong number of arguments\n", false, 2, NULL));
    for (int i = 0; arguments[i]; i++) {
        detected = detect_types(arguments[i]);
        if (!(detected & instruction.type[i]))
            return (bool_message("Wrong argument type\n", false, 2, NULL));
    }
    return (true);
}

bool check_instruction(char **instruction)
{
    op_t inst_stc = {};

    if (instruction[0][my_strlen(instruction[0]) - 1] == LABEL_CHAR)
        instruction++;
    if (!instruction[0])
        return (true);
    for (int i = 0; op_tab[i].mnemonique; i++)
        if (!my_strcmp(op_tab[i].mnemonique, instruction[0])) {
            inst_stc = op_tab[i];
            break;
        }
    if (!(inst_stc.mnemonique)) {
        return (bool_message("Wrong instruction\n", false, 2, NULL));
    } else
        return (check_arguments(inst_stc, instruction + 1));
}

bool is_correct(char *instruction)
{
    char **tmp = NULL;

    if (!instruction)
        return (false);
    for (int i = 0; instruction[i]; i++)
        if (instruction[i] == ',')
            instruction[i] = ' ';
    tmp = my_word_array(instruction);
    if (!check_instruction(tmp))
        return (false);
    free_array(tmp);
    return (true);
}