/*
** EPITECH PROJECT, 2019
** minishell1
** File description:
** minishell1
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <unistd.h>
#include "../inc/my.h"

void find_status(int stat)
{
    char *status = strsignal(WTERMSIG(stat));

    if (my_strcmp(status, "Floating point exception") == 0)
        my_printf("Floating exception\n");
    else if (__WCOREDUMP(stat))
        my_printf("segmentation fault (core dump)\n", status);
    else
        my_printf("%s\n", status);
}

int main(int ac, char **av, char **env)
{
    if (ac != 1 || env[0] == NULL)
        return (84);
    display_shell(env);
}