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

    for (; str[n]; n++);
    return (write(1, str, n));
}
