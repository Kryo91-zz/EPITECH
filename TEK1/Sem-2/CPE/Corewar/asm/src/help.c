/*
** EPITECH PROJECT, 2019
** Corewar, asm
** File description:
** disp help
*/

#include "unistd.h"

void disp_help(void)
{
    char help[] = "USAGE\n\
./asm file_name[.s]\n\
DESCRIPTION\n\
file_name file in assembly language to be converted into file_name.cor, an\n\
executable in the Virtual Machine.\n";

    write(1, help, 148);
}