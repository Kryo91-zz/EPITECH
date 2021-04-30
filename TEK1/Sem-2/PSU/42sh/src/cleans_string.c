/*
** EPITECH PROJECT, 2019
** PSU_42sh_2019
** File description:
** one_pipe.c
*/

#include "../inc/my.h"

void my_history(char *buff)
{
    int fd = open(".history", O_RDONLY);
    char *str = malloc(sizeof(char) * 4096);
    int fd2 = read(fd, str, 4096);
    my_printf("%s\n", str);
}

void my_which(char *buff)
{
    char **tab = my_str_to_word_array(buff, " ");
    char **tab2 = my_str_to_word_array(&envv->path[5], ":");

    if (tab[1] == NULL) {
        my_printf("too few argument.\n");
        return ;
    }
    for (int j = 1; tab[j]; ++j) {
        for (int i = 0; tab2[i]; i += 1) {
                if (access(my_strcat(my_strcat(tab2[i], "/\0"),\
                tab[j]), X_OK) == 0)
                    tab[j] = my_strcat(my_strcat(tab2[i], "/\0"), tab[j]);
        }
    }
    for (int j = 1; tab[j]; ++j)
        printf("%s\n", tab[j]);
    free(tab);
    free(tab2);
}

void display_enviro2(char **env, int fd)
{
    for (int i = 0; env[i]; ++i)
        write(fd, env[i], strlen(env[i]));
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