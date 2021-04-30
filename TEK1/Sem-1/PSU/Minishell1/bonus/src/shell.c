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
#include <errno.h>
#include "../inc/my.h"

void exec(pid_t pid, char **args, char **env, int stat)
{
    if (pid < 0)
        exit(84);
    if (pid == 0) {
        execve(args[0], args, env);
        if (EACCES == errno)
            my_printf("%s: Permission denied.\n", args[0]);
        else if (ENOEXEC == errno) {
            my_printf("%s: Exec format error. Wrong ", args[0]);
            my_printf("Architecture.\n");
        } else
            my_printf("%s: Command not found.\n", args[0]);
            exit(84);
    } else
        waitpid(pid, &stat, 0);
    if (WIFSIGNALED(stat))
        find_status(stat);
}

int  execution(char *buff, char **env)
{
    char *buf = copy_string(buff);
    char **args = my_str_to_word_array(buf, " ");
    int stat = 0;
    char *path = malloc(sizeof(char) * 4096);
    char **tab = NULL;
    char **envi = NULL;
    int i = 0;
    int count = 1;
    pid_t pid;
    pid = fork();

    path = tcheck_path(env, buf, path);
    tab = my_str_to_word_array(&path[5], ":");
    for (int i = 0; tab[i]; i += 1) {
        if (access(my_strcat(my_strcat(tab[i], "/\0"), args[0]), X_OK) == 0)
            args[0] = my_strcat(my_strcat(tab[i], "/\0"), args[0]);
    }
    exec(pid, args, env, stat);
}

int find_execution(char *buff, char **env)
{
    if (my_strcmp(buff, "exit\n") == 0)
        my_exit(buff);
    if (my_strcmp(buff, "env\n") == 0)
        display_enviro(env);
    if (my_strncmp(buff, "setenv", 6) == 0)
        set_enviro(buff, env);
    if (my_strncmp(buff, "unsetenv", 8) == 0)
        unset_enviro(buff, env);
    if (my_strncmp(buff, "cd", 2) == 0)
        my_cd(buff, env);
    if (my_strncmp(buff, "cat", 3) == 0)
        cat_something(buff, env);
    return (1);
}

void display_shell(char **env)
{
    char *buff = malloc(sizeof(char) * 4096);
    size_t len = 0;
    char *path = malloc(sizeof(char) * 4096);
    char *str = getcwd(path, 4096);
    int i = 0;

    if (isatty(0) == 1)
        my_printf("%s$>", str);
    i = getline(&buff, &len, stdin);
    for (int j = 0; buff[j]; j += 1)
        if (buff[j] == '\t')
            buff[j] = ' ';
    if (i <= 0)
        exit(0);
    if (my_strlen(buff) <= 1)
        display_shell(env);
    if (find_execution(buff, env) == 1) {
        execution(buff, env);
        display_shell(env);
    }
}

void display_shell2(char **env)
{
    char *buff = malloc(sizeof(char) * 4096);
    size_t len = 0;
    char *path = malloc(sizeof(char) * 4096);
    char *str = getcwd(path, 4096);
    int i = 0;

    print_prompt();
    i = getline(&buff, &len, stdin);
    for (int j = 0; buff[j]; j += 1)
        if (buff[j] == '\t')
            buff[j] = ' ';
    if (i <= 0)
        exit(0);
    if (my_strlen(buff) <= 1)
        display_shell(env);
    if (find_execution(buff, env) == 1) {
        if (execution(buff, env) == 1)
            display_shell(env);
        display_shell(env);
    }
}