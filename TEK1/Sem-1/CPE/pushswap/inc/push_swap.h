/*
** EPITECH PROJECT, 2019
** PUSH_SWAP
** File description:
** .h
*/

#ifndef PUSH_SWAP
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <string.h>


size_t my_strlen(char const *str);
void my_putchar(char c);
int my_putstr(char const *str);
int   my_check_nb(char **c);
int   my_convert_chars_to_nb(char **c);
int    my_getnbr(char const *str);
int my_compute_power_rec(int nb, int p);
void    my_swap(int *a, int *b);
void sort(char *str, char *dest, char *src, char **av);

#endif