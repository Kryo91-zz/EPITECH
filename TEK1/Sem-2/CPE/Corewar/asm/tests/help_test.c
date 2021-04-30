/*
** EPITECH PROJECT, 2019
** asm
** File description:
** help_test.c
*/

#include "asm.h"
#include <criterion/criterion.h>
#include <criterion/redirect.h>

Test(disp_help, should_print_help)
{
    cr_redirect_stdout();
    disp_help();
    cr_assert_stdout_eq_str("USAGE\n\
./asm file_name[.s]\n\
DESCRIPTION\n\
file_name file in assembly language to be converted into file_name.cor, an\n\
executable in the Virtual Machine.\n");
}