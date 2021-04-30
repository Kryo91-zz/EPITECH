/*
** EPITECH PROJECT, 2019
** my_putstr
** File description:
** display string
*/

#include "../include/my.h"

void report_error(char *str)
{

    for (int len = 0; str[len]; len++) {
        write(2, str, len);
        close (84);
    }
}

void my_putchar(char c)
{
    write(1, &c, 1);
}

int my_putstr(char const *str)
{
    int i = 0;

    while (str[i] != '\0') {
        my_putchar(str[i]);
        i = i + 1;
    }
    return (0);
}

int my_len(char const *str)
{
    int i = 0;
    while (str[i] != '\0') {
        i += 1;
    }
    return (i);
}

int my_strcmp(char const *s1, char const *s2)
{
    int i = my_len(s1);
    int j = my_len(s2);
    int l = 0;
    int ret = i - j;
    if (ret < 0) {
        ret = i;
    } else {
        ret = j;
    }
    while (l <= ret) {
        if (s1[l] != s2[l]) {
            ret = s1[l] - s2[l];
            return ret;
        } else {
            l += 1;
        }
    }
    return (0);
}
