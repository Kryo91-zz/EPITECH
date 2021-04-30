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

struct envi *get_env(void)
{
    envv = malloc(sizeof(struct envi));
    envv->enviro = malloc(sizeof(char *) * 4096);
    envv->path = malloc(sizeof(char) * 4096);
    return (envv);
}

void find_status(int stat)
{
    char *status = strsignal(WTERMSIG(stat));

    if (my_strcmp(status, "Floating point exception") == 0)
        my_printf("Floating exception\n");
    else if (__WCOREDUMP(stat))
        my_printf("Segmentation fault (core dumped)\n", status);
    else
        my_printf("%s\n", status);
    envv->statuss = stat;
    envv->status2 = stat;
}

int main(int ac, char **av, char **env)
{
    if (ac != 1 || env[0] == NULL)
        return (84);
    envv = get_env();
    envv->enviro = env;
    envv->statuss = 0;
    envv->status2 = 0;
    envv->countp = 0;
    envv->vercrocd = 0;
    envv->vercrocdd = 0;
    envv->nbco = 0;
    for (int i = 0; env[i]; i += 1)
        if (my_strncmp(env[i], "PATH=", 5) == 0)
            envv->path = env[i];
    display_shell(env);
}