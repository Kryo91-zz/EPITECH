/*
** EPITECH PROJECT, 2019
** AIA_n4s_2019
** File description:
** test.c
*/

#include "my.h"

void middle(char **tab)
{
    char rt[14];
    char *cmd = NULL;

    memset(rt, 0, 14);
    gcvt((atof(tab[3]) - atof(tab[34])) / 3000, 3, rt);
    cmd = my_strcat("WHEELS_DIR:", rt);
    exec_cmd(cmd);
    free(cmd);
}

void check_direction(char **tab)
{
    if (atof(tab[19]) < 100 || atof(tab[34]) < 100 || atof(tab[3]) < 100) {
        exec_cmd("CAR_FORWARD:0");
        exec_cmd("CAR_BACKWARDS:1");
        usleep(0.5);
    }
    if (atof(tab[34]) > atof(tab[3]))
        maintain_right(tab);
    if (atof(tab[34]) < atof(tab[3]))
        maintain_left(tab);
}

void speed_loop(char **tab)
{
    char sp[14];
    char *speed = "CAR_FORWARD:";
    float percent = ((atof(tab[18]) + atof(tab[19])) / 2) / (3010 * 2.1);

    memset(sp, 0, 14);
    gcvt(percent < 0.175 ? 0.175 : percent, 3, sp);
    speed = my_strcat(speed, sp);
    exec_cmd(speed);
    free(speed);
}

int game_loop(void)
{
    char **tab;

    tab = get_info_lidar();
    while (detect_end(tab) != 1) {
        tab = get_info_lidar();
        speed_loop(tab);
        get_dir(tab + 3);
    }
    exec_cmd("STOP_SIMULATION");
    return (0);
}

int main(void)
{
    exec_cmd("START_SIMULATION");
    return (game_loop());
}