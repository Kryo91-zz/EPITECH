/*
** EPITECH PROJECT, 2019
** PSU_42sh_2019
** File description:
** check_ands.c
*/

#include "../inc/my.h"

int check_for_dots(char **cmds_list, int i)
{
    for (; cmds_list[i+1] && my_strcmp(cmds_list[i+1], "||") == 0; i += 2) {
        if (cmds_list[i + 3] && my_strcmp(cmds_list[i+3], ";") == 0)
            return (1);
    }
    return (0);
}

void check_smth(char *test, char **env)
{
    if (test[0] == '<' || test[0] == '>' || test[0] == ';' || \
        test[0] == '|' || test[0] == '&' || test[my_strlen(test) - 1] == '<' \
        || test[my_strlen(test) - 1] == '>' || \
        test[my_strlen(test) - 1] == ';' || test[my_strlen(test) - 1] == '|' \
        || test[my_strlen(test) - 1] == '&') {
        my_printf("Invalid null command.\n");
        display_shell(env);
    }
}

char **put_backslash_zero(char **cmds_list, int ind, int j)
{
    cmds_list[ind][j] = '\0';
    if (j > 0)
        ind++;
    cmds_list[ind] = NULL;
    return (cmds_list);
}

void operands_loop(char **cmds_list, char **env)
{
    for (int i = 0; cmds_list[i]; i += 2) {
        operand_sep(cmds_list, i, env);
        if (operand_nd(cmds_list, i, env) == 1)
            break ;
        i = envv->i;
        if (operand_re(cmds_list, i, env) == 1)
            break ;
        i = envv->i;
        if (operand_pipe(cmds_list, i, env) == 1)
            break ;
        i = envv->i;
        if (operand_redirr(cmds_list, i, env) == 1)
            break;
        if (operands_loop2(cmds_list, env, i) == 1)
            break;
    }
}

int fork_pipe(int pid, int pipefd[], char **cmd2, char **env)
{
    int error = 0;

    pid = fork();
    if (pid == 0) {
        dup2(pipefd[0], 0);
        close(pipefd[0]);
        close(pipefd[1]);
        error = execve(cmd2[0], cmd2, env);
    }
    return (error);
}