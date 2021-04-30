/*
** EPITECH PROJECT, 2019
** PSU_tetris_2019
** File description:
** score.c
*/

#include "../inc/my.h"

char *highcore(void)
{
    char *buf = malloc(sizeof(char) * 4096);
    int fd = open("highscore", O_RDONLY);
    int highscore = read(fd, buf, 4096);
    return (buf);
}

void put_score(char *highest, option_t *option)
{
    mvprintw(10, 23, "%d", option->score);
    mvprintw(12, 23, "%d", option->lines);
    mvprintw(13, 23, "%d", option->L);
    mvprintw(9, 23, "%s", highest);
}

void put_highscore(char *highest)
{
    int fd;

    fd =  open("highscore", O_CREAT | O_RDWR, 0644);
    write(fd, highest, my_strlen(highest));
    endwin();
}