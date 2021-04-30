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

void my_cd(char *buff, char **env)
{
    char *buf = copy_string(buff);
    char **tab = my_str_to_word_array(buf, " ");
    char **args = NULL;
    char *path = malloc(sizeof(char) * 4096);
    char *test = malloc(sizeof(char) * 4096);
    static char *str = NULL;
    int i = 0;

    my_cd_minus(buf, str, test, env);
    for (; env[i]; i += 1)
        if (my_strncmp(env[i], "HOME=", 5) == 0)
            path = env[i];
    if (!tab[1] || my_strcmp(tab[1], "~") == 0) {
        str = getcwd(test, 4096);
        chdir(path + 5);
        display_shell(env);
    }
    my_cd2(env, tab, path, i);
}

void my_cd2(char **env, char **tab, char *path, int i)
{
    if (tab[2] != NULL) {
        my_printf("Bad argument\n");
        display_shell(env);
    }
    getcwd(path, 4096);
    i = chdir(tab[1]);
    if (i == -1) {
        my_printf("%s: Not a directory.\n", tab[1]);
        display_shell(env);
    }
    getcwd(path, 4096);
    display_shell(env);
}

void my_cd_minus(char *buf, char *str, char *test, char **env)
{
    if (my_strcmp(buf, "cd -") == 0) {
        chdir(str);
        str = getcwd(test, 4096);
        display_shell(env);
    }
}

char *tcheck_path(char **env, char *buf, char *path)
{
        for (int i = 0; env[i]; i += 1) {
        if (my_strncmp(env[i], "PATH=", 5) == 0)
            path = env[i];
    }
    if (path == NULL) {
        my_printf("%s: Command not found\n", buf);
        display_shell(env);
    }
    return (path);
}

void print_prompt(void)
{
    if (isatty(0) == 1)
        my_printf("$>");
}