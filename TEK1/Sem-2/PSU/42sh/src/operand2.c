/*
** EPITECH PROJECT, 2019
** PSU_42sh_2019
** File description:
** redir.c
*/

#include "../inc/my.h"

int operand_redirr(char **cmds_list, int i, char **env)
{
    if (cmds_list[i+1] && my_strcmp(cmds_list[i+1], ">") == 0) {
        one_pipe_exec2(cmds_list[i], cmds_list[i+2], env);
        if (cmds_list[i+4])
            i += 4;
        else
            return (1);
    }
    envv->i = i;
    return (0);
}

int operand_redirrr(char **cmds_list, int i, char **env)
{
    if (cmds_list[i+1] && my_strcmp(cmds_list[i+1], ">>") == 0) {
        if (find_execution(cmds_list[i], envv->enviro) == 1) {
            one_pipe_exec3(cmds_list[i], cmds_list[i+2], env);
            if (cmds_list[i+4])
                i += 4;
            else
                return (1);
        }
    }
    envv->i = i;
    return (0);
}

int operand_redirl(char **cmds_list, int i, char **env)
{
    if (cmds_list[i+1] && my_strcmp(cmds_list[i+1], "<") == 0) {
        if (find_execution(cmds_list[i], envv->enviro) == 1) {
            one_pipe_exec4(cmds_list[i], cmds_list[i+2], env);
            if (cmds_list[i+4])
                i += 4;
            else
                return (1);
        }
    }
    envv->i = i;
    return (0);
}

int operand_redirll(char **cmds_list, int i, char **env)
{
    if (cmds_list[i+1] && my_strcmp(cmds_list[i+1], "<<") == 0) {
        if (find_execution(cmds_list[i], envv->enviro) == 1) {
            one_pipe_exec5(cmds_list[i], cmds_list[i+2], env);
            if (cmds_list[i+4])
                i += 4;
            else
                return (1);
        }
    }
    envv->i = i;
    return (0);
}