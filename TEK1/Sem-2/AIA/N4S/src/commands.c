/*
** EPITECH PROJECT, 2019
** AIA_n4s_2019
** File description:
** commands.c
*/

#include "my.h"

void maintain_left(char **tab)
{
    if (atof(tab[3]) < 300)
        exec_cmd("WHEELS_DIR:-0.05");
    if (atof(tab[3]) < 150)
        exec_cmd("WHEELS_DIR:-0.1");
    if (atof(tab[3]) > 300)
        exec_cmd("WHEELS_DIR:0.01");
    if (atof(tab[3]) > 400)
        exec_cmd("WHEELS_DIR:0.1");
    if (atof(tab[3]) > 600)
        exec_cmd("WHEELS_DIR:0.3");
}

void maintain_right(char **tab)
{
    if (atof(tab[34]) < 300)
        exec_cmd("WHEELS_DIR:0.05");
    if (atof(tab[34]) < 150)
        exec_cmd("WHEELS_DIR:0.1");
    if (atof(tab[34]) > 300)
        exec_cmd("WHEELS_DIR:-0.01");
    if (atof(tab[34]) > 400)
        exec_cmd("WHEELS_DIR:-0.1");
    if (atof(tab[34]) > 600)
        exec_cmd("WHEELS_DIR:-0.3");
}

int detect_end(char **tab)
{
    char *tmp = NULL;
    size_t size = 0;
    char *str = "STOP_SIMULATION";

    if (strncmp(tab[35], "Track Cleared", 14) == 0) {
        write(1, str, strlen(str));
        write(1, "\n", 1);
        write(2, str, strlen(str));
        while (getline(&tmp, &size, stdin) == -1);
        write(2, tmp, size);
        write(2, "\n\n", 2);
        return (1);
    }
    return (0);
}

char **get_info_lidar(void)
{
    char *tmp = NULL;
    size_t size = 0;
    char **tab;

    write(1, "GET_INFO_LIDAR\n", 15);
    while (getline(&tmp, &size, stdin) == -1);
    write(2, "GET_INFO_LIDAR\n", 15);
    write(2, tmp, size);
    tab = my_sep_array(tmp, ':');
    write(2, "\n\n", 2);
    return (tab);
}

void exec_cmd(char *str)
{
    char *tmp = NULL;
    size_t size = 0;

    write(1, str, strlen(str));
    write(1, "\n", 1);
    write(2, str, strlen(str));
    while (getline(&tmp, &size, stdin) == -1);
    write(2, tmp, size);
    write(2, "\n\n", 2);
}