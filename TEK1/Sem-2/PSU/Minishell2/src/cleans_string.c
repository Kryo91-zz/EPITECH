/*
** EPITECH PROJECT, 2019
** PSU_42sh_2019
** File description:
** one_pipe.c
*/

#include "../inc/my.h"

void display_enviro2(char **env, int fd)
{
    for (int i = 0; env[i]; ++i)
        write(fd, env[i], my_strlen(env[i]));
}

int find_execution3(char *buff, int fd)
{
    if (my_strcmp(buff, "env") == 0) {
        display_enviro2(envv->enviro, fd);
        return (0);
    }
    return (1);
}

char **prepare_string(char **cmd)
{
    for (int i = 0; cmd[i]; ++i) {
        cmd[i] = copy_string2(cmd[i]);
        cmd[i] = copy_string(cmd[i]);
        cmd[i] = copy_string3(cmd[i]);
    }
    return (cmd);
}