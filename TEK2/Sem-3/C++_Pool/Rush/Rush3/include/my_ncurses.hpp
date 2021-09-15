/*
** EPITECH PROJECT, 2019
** MY
** File description:
** .h
*/

#ifndef __MY_H__
#define __MY_H__

#include <curses.h>
#include <ncurses.h>
#include <stdarg.h>

typedef struct window_s
{
    char *print;
    WINDOW *line;
} window_t;

typedef struct page_s
{
    window_t *page;
} page_t;

void disp_ncurses(int tic __attribute__((unused)), SysData data);
void init_curse(void);

#endif