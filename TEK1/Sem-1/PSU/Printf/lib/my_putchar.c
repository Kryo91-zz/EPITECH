/*
** EPITECH PROJECT, 2019
** MY_PUTCHAR
** File description:
** write a character
*/
#include <unistd.h>
#include "../inc/my.h"

void my_putchar(char c)
{
    write(1, &c, 1);
}
