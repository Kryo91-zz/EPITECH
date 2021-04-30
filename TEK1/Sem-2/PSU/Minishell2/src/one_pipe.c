/*
** EPITECH PROJECT, 2019
** PSU_42sh_2019
** File description:
** one_pipe.c
*/

#include "../inc/my.h"
#include <unistd.h>

void one_pipe_exec(char *str, char *src, char **env)
{
    char **tab2 = my_str_to_word_array(&envv->path[5], ":");
    src = without_space(src);
    char **cmd1 = my_str_to_word_array(str, " ");
    char **cmd2 = my_str_to_word_array(src, " ");

    cmd1 = prepare_string(cmd1);
    cmd2 = prepare_string(cmd2);
    for (int i = 0; tab2[i]; i += 1) {
        if (access(my_strcat(my_strcat(tab2[i], "/\0"), cmd1[0]), X_OK) == 0)
            cmd1[0] = my_strcat(my_strcat(tab2[i], "/\0"), cmd1[0]);
        if (access(my_strcat(my_strcat(tab2[i], "/\0"), cmd2[0]), X_OK) == 0)
            cmd2[0] = my_strcat(my_strcat(tab2[i], "/\0"), cmd2[0]);
    }
    free(tab2);
    return (one_pipe(cmd1, cmd2, env));
}

void one_pipe(char **cmd1, char **cmd2, char **env)
{
    int pipefd[2];
    int pid;
    int fd;
    int error = 0;

    pipe(pipefd);
    pid = fork();
    if (pid == 0) {
        dup2(pipefd[1], 1);
        close(pipefd[1]);
        close(pipefd[0]);
        error = execve(cmd1[0], cmd1, env);
    } else
        error = fork_pipe(pid, pipefd, cmd2, env);
    close(pipefd[0]);
    close(pipefd[1]);
    for (int i = 0; i < 2; i++)
        wait(&error);
}

void one_pipe_exec2(char *str, char *src, char **env)
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
    return (one_pipe2(cmd1, src, env));
}

void one_pipe2(char **cmd1, char *src, char **env)
{
    int pipefd[2];
    int pid;
    int fd = open(src, O_CREAT | O_RDONLY | O_WRONLY, S_IRWXU);
    int error = 0;
    int dd = 0;

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