/*
** EPITECH PROJECT, 2019
** PSU_42sh_2019
** File description:
** redir.c
*/

#include "../inc/my.h"

char *clean_str(char *buff)
{
    for (int j = 0; buff[j]; j += 1)
        if (buff[j] == '\t')
            buff[j] = ' ';
    return (buff);
}

int check_operand_redundance(char *buff)
{
    for (int i = 0; buff[i] && buff[i] != '\n'; i += 1) {
        if (buff[i] == '<' || buff[i] == '>' || buff[i] == ';' || \
buff[i] == '|' || buff[i] == '&') {
            if (buff[i+1] != '\0' && (buff[i+1] == '<' || buff[i+1] == '>' || \
buff[i+1] == ';' || buff[i+1] == '|' || buff[i+1] == '&'))
                i += 1;
            i += 1;
            while (buff[i] != '\0' && buff[i] != '\n' && buff[i] == ' ')
                i += 1;
            if (buff[i] != '\0' && (buff[i] == '<' || buff[i] == '>' || \
buff[i] == ';' || buff[i] == '|' || buff[i] == '&')) {
                my_printf("Invalid null command.\n");
                return (1);
            }
        }
    }
    return (0);
}

int parse_operand(char *buff, char **cmds_list, int ind, int i)
{
    if (cmds_list[ind] != NULL)
        ind += 1;
    cmds_list[ind] = malloc(sizeof(char) * 5 + 1);
    cmds_list[ind][0] = buff[i];
    if (buff[i + 1]) {
        i += 1;
        if (buff[i] == '<' || buff[i] == '>' || buff[i] == ';' || \
buff[i] == '|' || buff[i] == '&') {
            cmds_list[ind][1] = buff[i];
            i += 1;
            cmds_list[ind][2] = '\0';
            ind += 1;
        } else {
            cmds_list[ind][1] = '\0';
            ind += 1;
        }
    }
    cmds_list[ind] = malloc(sizeof(char) * my_strlen(buff) + i);
    return (i);
}

char **list_commands(char *buff, char **cmds_list, char **env)
{
    int ind = 0;
    int j = 0;
    char *test = without_space(buff);

    check_smth(test, env);
    cmds_list[0] = malloc(sizeof(char) * my_strlen(buff) + 1);
    for (int i = 0; buff[i]; i += 1, j += 1) {
        if (buff[i] == '<' || buff[i] == '>' || buff[i] == ';' || \
buff[i] == '|' || buff[i] == '&') {
            cmds_list[ind][j] = '\0';
            i = parse_operand(buff, cmds_list, ind, i);
            ind += 2;
            j = 0;
        }
        cmds_list[ind][j] = buff[i];
    }
    cmds_list = put_backslash_zero(cmds_list, ind, j);
    return (cmds_list);
}

void disp_shell(char **tab, char **env, char *buff, char **cmds_list)
{
    time_t rawtime;
    struct tm * timeinfo;
    int fd = open(".history", O_APPEND | O_RDONLY | O_WRONLY, S_IRWXU);

    time (&rawtime);
    timeinfo = localtime (&rawtime);
    if (check_operand_redundance(buff) == 1)
        display_shell(env);
    buff = copy_string3(buff);
    dprintf(fd, "%d %s %s\n", envv->nbco, asctime(timeinfo), buff);
    cmds_list = list_commands(buff, cmds_list, env);
    if (check_operands(cmds_list) == 1)
        display_shell(env);
    for (int i = 0; cmds_list[i]; ++i)
        cmds_list[i] = copy_string2(cmds_list[i]);
    if (check_ambiguous_redirect(cmds_list) == -1)
        display_shell(env);
    envv->i = 0;
    operands_loop(cmds_list, env);
    env = envv->enviro;
    display_shell(env);
}