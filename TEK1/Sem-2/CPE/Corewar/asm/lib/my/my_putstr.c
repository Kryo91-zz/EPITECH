/*
** EPITECH PROJECT, 2019
** my_putstr
** File description:
** print str
*/

#include <unistd.h>

int my_putstr(char const *str)
{
    int n = 0;

    if (!str) {
        write(1, "(null)", 6);
        return (-1);
    }
    for (; str && str[n]; n++);
    return (write(1, str, n));
}
