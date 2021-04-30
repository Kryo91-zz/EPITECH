/*
** EPITECH PROJECT, 2019
** PSU_tetris_2019
** File description:
** window.c
*/

#include "../inc/my.h"

int create_all_win(window_t *win, option_t *option)
{
    if ((!(win->score = create_new_boarrrd(12, 31, 7, 1))) ||
(!(win->board = create_new_board(option->map_size[0], option->map_size[1]\
* 2, 2, 34))) || (!(win->title = create_new_boarrd(5 , 30, 0, 0))))
        return (1);
    else if (option->w == 0) {
        if (!(win->next = create_new_boarrrrd(7, 13, 1, \
option->map_size[1] * 2 + 1 + 35)))
            return (1);
    }
    return (0);
}

void display_interface(window_t *win, option_t *option)
{
    if (option->w == 0)
        wrefresh(win->next);
    wrefresh(win->title);
    wrefresh(win->score);
    wrefresh(win->board);
}

void timer(int time)
{
    time %= 3600;
    int minutes = time / 60;
    time %= 60;
    int seconds = time;
    mvprintw(15, 23, "%d:%d", minutes, time);
}

int too_small(void)
{
    int key = 0;
    char *msg = "Screen too small";

    while (COLS < 71 || LINES < 23) {
        refresh();
        mvprintw(LINES / 2, (COLS / 2) - 8, msg);
        key = getch();
        if (key == 27)
            endwin();
        clear();
    }
}

int curse(option_t *option, window_t *win)
{
    int key = 0;
    int time = 0;
    char *highest = highcore();

    init_curse();
    while (key != 27) {
        refresh();
        put_score(highest, option);
        time += 1;
        timer(time);
        too_small();
        if (create_all_win(win, option) == 1)
            return (84);
        display_interface(win, option);
        key = getch();
        napms(1000);
        clear();
    }
    put_highscore(highest);
    return (0);
}