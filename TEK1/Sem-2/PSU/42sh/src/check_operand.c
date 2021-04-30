/*
** EPITECH PROJECT, 2019
** PSU_42sh_2019
** File description:
** check_operand.c
*/

#include "../inc/my.h"

int check_ambiguous_redirect(char **cmds_list)
{
    for (int i = 0; cmds_list[i]; i += 1) {
        if (my_strncmp(cmds_list[i] , "<", 1) == 0 || my_strncmp(cmds_l\
ist[i] , ">", 1) == 0) {
            if (cmds_list[i+2] && (my_strncmp(cmds_list[i+2], ">", 1) == 0 \
|| (my_strncmp(cmds_list[i+2], "<", 1) == 0) || \
(my_strncmp(cmds_list[i+2], "|", 1) == 0))) {
                my_printf("Ambiguous output redirect.\n");
                return (-1);
            }
        }
    }
    return (0);
}

char *without_space(char *buff)
{
    char *str = malloc(sizeof(char) * my_strlen(buff) + 3);
    int i = 0;
    int j = 0;

    if (buff[0] == ' ')
        i = 1;
    for (; buff[i] != '\0'; ++i, ++j)
        str[j] = buff[i];
    str[j] = '\0';
    return (str);
}

int check_operands(char **cmds_list)
{
    for (int i = 0; cmds_list[i]; i++ ) {
        if (cmds_list[i][0] == '<' || cmds_list[i][0] == '>' || \
cmds_list[i][0] == ';' || cmds_list[i][0] == '|' || \
cmds_list[i][0] == '&') {
            if (cmds_list[i+1] == NULL) {
                my_printf("Invalid null command.\n");
                return (1);
            }
            if (cmds_list[i+1][0] == '<' || cmds_list[i+1][0] == '>' || cm\
ds_list[i+1][0] == ';' || cmds_list[i+1][0] == '|' || \
cmds_list[i+1][0] == '&') {
                my_printf("Invalid null command.\n");
                return (1);
            }
        }
    }
    return (0);
}