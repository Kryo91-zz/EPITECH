/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** ptr_message.c
*/

#include <stdlib.h>
#include <unistd.h>
#include <stdbool.h>

void *ptr_message(char const *mess, void *ptr, int fd, void *to_free)
{
    size_t len = 0;

    for (; mess[len]; len++);
    if (to_free)
        free(to_free);
    if (write(fd, mess, len) == -1) {
        write(2, "Write error\n", 12);
        return (ptr);
    }
    return (ptr);
}

int int_message(char const *mess, int to_ret, int fd, void *to_free)
{
    size_t len = 0;

    for (; mess[len]; len++);
    if (to_free)
        free(to_free);
    if (write(fd, mess, len) == -1) {
        write(2, "Write error\n", 12);
        return (to_ret);
    }
    return (to_ret);
}

bool bool_message(char const *mess, bool to_ret, int fd, void *to_free)
{
    size_t len = 0;

    for (; mess[len]; len++);
    if (to_free)
        free(to_free);
    if (write(fd, mess, len) == -1)
        write(2, "Write error\n", 12);
    return (to_ret);
}

char char_message(char const *mess, char to_ret, int fd, void *to_free)
{
    size_t len = 0;

    for (; mess[len]; len++);
    if (to_free)
        free(to_free);
    if (write(fd, mess, len) == -1) {
        write(2, "Write error\n", 12);
        return (to_ret);
    }
    return (to_ret);
}