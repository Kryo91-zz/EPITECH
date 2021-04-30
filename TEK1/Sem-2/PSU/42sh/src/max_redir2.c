/*
** EPITECH PROJECT, 2019
** PSU_42sh_2019
** File description:
** echo.c
*/

#include "../inc/my.h"

int second_pipe(char **cmd1, char **env, int pipefd[], int error)
{
    wait(NULL);
    close(pipefd[1]);
    dup2(pipefd[0], 0);
    close(pipefd[0]);
    error = execve(cmd1[0], cmd1, env);
    return (error);
}

int writer(int fd, char *src)
{
    size_t len = 0;
    char *str = malloc(sizeof(char));
    int good = 0;
    char *tmp = malloc(sizeof(char));

    str[0] = '\0';
    tmp[0] = '\0';
    while (good != -1  && my_strncmp(str, src, my_strlen(src)) != 0) {
        printf("? ");
        good = getline(&str, &len, stdin);
        tmp = my_strdup(str);
        tmp[my_strlen(str) - 1] = '\0';
        if (good != -1 && my_strcmp(tmp, src) != 0)
            write(fd, str, my_strlen(str));
    }
    if (good == -1)
        exit(84);
    else
        return (0);
}

void one_pipe5(char **cmd1, char *src, char **env)
{
    int pipefd[2];
    int pid;
    int error = 0;
    size_t len = 0;

    pipe(pipefd);
    pid = fork();
    if (pid == 0) {
        close(pipefd[0]);
        (writer(pipefd[1], src) != -1);
        close(pipefd[1]);
    } else
        error = second_pipe(cmd1, env, pipefd, error);
    close(pipefd[0]);
    for (int i = 0; i < 2; i++)
        wait(&error);
    return ;
}

void one_pipe_exec5(char *str, char *src, char **env)
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
    return (one_pipe5(cmd1, src, env));
}

int operands_loop2(char **cmds_list, char **env, int i)
{
    i = envv->i;
    if (operand_redirrr(cmds_list, i, env) == 1)
        return (1);
    i = envv->i;
    if (operand_redirl(cmds_list, i, env) == 1)
        return (1);
    i = envv->i;
    if (operand_redirll(cmds_list, i, env) == 1)
        return (1);
    i = envv->i;
    if (last_operand(cmds_list, i, env) == 1)
        return (1);
    return (0);
}