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

char *copy_string(char *buff)
{
    char *str = malloc(sizeof(char) * 4096);
    int i = 0;

    while (buff[i] != '\n') {
        str[i] = buff[i];
        ++i;
    }
    str[i] = '\0';
    return (str);
}

void unset_enviro(char *buff, char **env)
{
    char *str = copy_string(buff);
    char **tab = my_str_to_word_array(str, " ");
    char **envi = malloc(sizeof(char *) * 4096);
    int i = 0;
    int y = 0;

    tcheck_error(tab, env);
    char *dest = my_strcat(tab[1], "=");
    for (; env[i] != NULL;) {
        if (my_strncmp(dest, env[i], my_strlen(dest)) == 0) {
            envi[i] == env[y+1];
            ++y;
        }
        envi[i] = env[y];
        ++y;
        ++i;
    }
    envi[i] == NULL;
    display_shell(envi);
}

void set_enviro(char *buff, char **env)
{
    char *str = copy_string(buff);
    char **tab = my_str_to_word_array(str, " ");

    if (tab[1] == NULL)
        display_enviro(env);
    if (my_str_isnum(tab[1]) == 1) {
        my_printf("setenv: Variable name must contain \
alphanumeric characters.\n");
        display_shell(env);
    }
    char **envi = unset_env2(buff, env);
    reset_enviro2(str, envi);
}

void display_enviro(char **env)
{
    int i = 0;

    while (env[i] != NULL) {
        my_printf("%s\n", env[i]),
        ++i;
    }
    display_shell(env);
}

char **unset_env2(char *buff, char **env)
{
    char *str = copy_string(buff);
    char **tab = my_str_to_word_array(str, " ");
    char **envi = malloc(sizeof(char *) * 4096);
    int i = 0;
    int y = 0;

    tcheck_error(tab, env);
    char *dest = my_strcat(tab[1], "=");
    for (; env[i] != NULL;) {
        if (my_strncmp(dest, env[i], my_strlen(dest)) == 0) {
            envi[i] == env[y+1];
            ++y;
        }
        envi[i] = env[y];
        ++y;
        ++i;
    }
    envi[i] == NULL;
    return (envi);
}