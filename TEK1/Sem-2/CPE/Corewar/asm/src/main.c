/*
** EPITECH PROJECT, 2020
** Corewar, asm
** File description:
** empty main to allow further uni testing
*/

#include "asm.h"

int main(int argc, char const *argv[])
{
    if (argc != 2) {
        write(2, "asm: Only one argument allowed. -h for help.\n", 45);
        return (84);
    }
    if (!my_strcmp(argv[1], "-h")) {
        disp_help();
        return (0);
    }
    return (compile(argv[1]));
}
