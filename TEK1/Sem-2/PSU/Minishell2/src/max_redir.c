/*
** EPITECH PROJECT, 2019
** PSU_42sh_2019
** File description:
** echo.c
*/

#include "../inc/my.h"

void one_pipe_exec3(char *str, char *src, char **env)
{
    char **tab2 = my_str_to_word_array(&envv->path[5], ":");
    src = without_space(src);
    char **cmd1 = my_str_to_word_array(str, " ");

    for (int i = 0; cmd1[i]; ++i) {
        cmd1[i] = copy_string2(cmd1[i]);
        cmd1[i] = copy_string(cmd1[i]);
        cmd1[i] = copy_string3(cmd1[i]);
    }
        src = copy_string2(src);
        src = copy_string(src);
        src = copy_string3(src);

    for (int i = 0; tab2[i]; i += 1) {
        if (access(my_strcat(my_strcat(tab2[i], "/\0"), cmd1[0]), X_OK) == 0)
            cmd1[0] = my_strcat(my_strcat(tab2[i], "/\0"), cmd1[0]);
    }
    return (one_pipe3(cmd1, src, env));
}

void one_pipe3(char **cmd1, char *src, char **env)
{
    int pipefd[2];
    int pid;
    int fd = open(src, O_CREAT | O_RDONLY | O_WRONLY | O_APPEND, S_IRWXU);
    int error = 0;

    pipe(pipefd);
    pid = fork();
    if (pid == 0) {
        dup2(fd, 1);
        close(fd);
        if ((error = execve(cmd1[0], cmd1, env)) < 0)
            my_printf("%d\n", error);
    }
    close(fd);
    for (int i = 0; i < 2; i++)
        wait(&error);
    return ;
}

void one_pipe_exec4(char *str, char *src, char **env)
{
    char **tab2 = my_str_to_word_array(&envv->path[5], ":");
    src = without_space(src);
    char **cmd1 = my_str_to_word_array(str, " ");

    for (int i = 0; cmd1[i]; ++i) {
        cmd1[i] = copy_string2(cmd1[i]);
        cmd1[i] = copy_string(cmd1[i]);
        cmd1[i] = copy_string3(cmd1[i]);
    }
        src = copy_string2(src);
        src = copy_string(src);
        src = copy_string3(src);

    for (int i = 0; tab2[i]; i += 1) {
        if (access(my_strcat(my_strcat(tab2[i], "/\0"), cmd1[0]), X_OK) == 0)
            cmd1[0] = my_strcat(my_strcat(tab2[i], "/\0"), cmd1[0]);
    }
    return (one_pipe4(cmd1, src, env));
}

void one_pipe4(char **cmd1, char *src, char **env)
{
    int pipefd[2];
    int pid;
    int fd = open(src, O_RDONLY);
    int error = 0;

    pipe(pipefd);
    pid = fork();
    if (pid == 0) {
        dup2(fd, 0);
        close(fd);
        if ((error = execve(cmd1[0], cmd1, env)) < 0)
            my_printf("%d\n", error);
    }
    close(fd);
    for (int i = 0; i < 2; i++)
        wait(&error);
    return ;
}