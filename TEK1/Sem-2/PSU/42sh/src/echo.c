/*
** EPITECH PROJECT, 2019
** PSU_42sh_2019
** File description:
** echo.c
*/

#include "../inc/my.h"

int find_execution2(char *buff, char **env)
{
    if (my_strncmp(buff, "echo", 4) == 0) {
        my_echo(buff, env);
        return (0);
    }
    if (my_strncmp(buff, "which", 4) == 0) {
        my_which(buff);
        return (0);
    }
    if (my_strncmp(buff, "history", 4) == 0) {
        my_history(buff);
        return (0);
    }
    return (1);
}

void flag_e_echo(char *buff)
{
    for (int i = 0; buff[i] != '\0'; i++) {
        if (buff[i] == 92 && buff[i + 1] == 'n') {
            my_printf("\n");
            i += 2;
        }
        my_printf("%c", buff[i]);
    }
    my_printf("\n");
}

int idx_find(char *buff)
{
    for (int i = 1; buff[i] != '\0'; i++)
        if (buff[i] == 34)
            return (i);
}

char *get_msg(char *buff)
{
    int idx = idx_find(buff);
    int size = my_strlen(buff);
    int i = 0;
    char *cmd = malloc(sizeof(char) * (size + 1));

    for (; buff[idx] != '\0';i++, idx++)
        cmd[i] = buff[idx];
    cmd[i] = 0;
    return (cmd);
}

void my_echo(char *buff, char **env)
{
    char **tab = my_str_to_word_array(buff, " ");
    buff = copy_string(get_msg(buff));

    for (int i = 1; tab[i] != NULL; i++) {
        if (my_strcmp(tab[i], "$?") == 0) {
            if (tab[i+1] == NULL)
                my_printf("%d\n", envv->status2);
            else
                my_printf("%d ", envv->status2);
            ++i;
        }
        if (tab[i+1] == NULL) {
            tab[i] = copy_string(tab[i]);
            my_printf("%s\n", tab[i]);
        } else {
            tab[i] = copy_string(tab[i]);
            my_printf("%s ", tab[i]);
        }
    }
}