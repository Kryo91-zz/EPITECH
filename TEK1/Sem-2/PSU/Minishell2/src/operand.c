/*
** EPITECH PROJECT, 2019
** PSU_42sh_2019
** File description:
** redir.c
*/

#include "../inc/my.h"

void operand_sep(char **cmds_list, int i, char **env)
{
    if (cmds_list[i+1] != NULL && my_strcmp(cmds_list[i+1], ";") == 0) {
        if (find_execution(cmds_list[i], env) == 1)
            execution(cmds_list[i], env);
        envv->statuss = 0;
    }
}

int operand_nd(char **cmds_list, int i, char **env)
{
    if (cmds_list[i+1] != NULL && my_strcmp(cmds_list[i+1], "&&") == 0) {
        if (envv->statuss == 0 || my_strcmp(cmds_list[i-1], "||") == 0 |\
| envv->statuss == 666) {
            if (find_execution(cmds_list[i], env) == 1) {
                execution(cmds_list[i], env);
            if (envv->statuss == 0) {
                i = i;
            } else
                return (1);
            }
        } else if (envv->statuss != 0 && cmds_list[i + 2] && my_strcmp\
(cmds_list[i+1], "&&") == 0) {
            while (cmds_list[i + 2] && my_strcmp(cmds_list[i+1], "&&") == 0)
                i += 2;
            envv->statuss = 0;
        }
    }
    envv->i = i;
    return (0);
}

int operand_re(char **cmds_list, int i, char **env)
{
    if (cmds_list[i+1] != NULL && my_strcmp(cmds_list[i+1], "||") == 0) {
        if (envv->statuss != 0 || i == 0 || \
my_strcmp(cmds_list[i-1], "&&" ) == 0 || my_strcmp(cmds_list[i-1], ";" ) == 0){
            if (find_execution(cmds_list[i], env) == 1) {
                execution(cmds_list[i], env);
                i = i;
                if (envv->statuss == 0 && check_for_dots(cmds_list, i) == 0)
                    return (1);
                else if (check_for_dots(cmds_list, i) == 1) {
                    for (; my_strcmp(cmds_list[i+1], "||") == 0; i += 2);
                    envv->statuss = 666;
                }
            }
        }
    }
    envv->i = i;
    return (0);
}

int operand_pipe(char **cmds_list, int i, char **env)
{
    char ***tab = NULL;
    envv->countp = 0;
    if (cmds_list[i+1] && my_strcmp(cmds_list[i+1], "|") == 0) {
        if (find_execution(cmds_list[i], envv->enviro) == 1) {
            envv->countp = count_tab(cmds_list, "|", (i+1)) + 1;
            int pipefd[envv->countp+1];
            tab = get_tab(cmds_list, tab, i+1);
            one_pipe_exec(cmds_list[i], cmds_list[i+2], env);
            if (cmds_list[i + (envv->countp + 3)])
                i += (envv->countp + 3);
            else
                return (1);
        }
    }
    envv->i = i;
    return (0);
}

int last_operand(char ** cmds_list, int i, char **env)
{
    if (cmds_list[i+1] == NULL) {
        if (i > 0 && my_strcmp(cmds_list[i-1], "&&") == 0)
            if (envv->statuss != 0)
                return (1);
        if (i > 0 && my_strcmp(cmds_list[i-1], "||") == 0)
            if (envv->statuss == 0)
                return (1);
        if (find_execution(cmds_list[i], env) == 1)
            execution(cmds_list[i], env);
    }
    return (0);
}