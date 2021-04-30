/*
** EPITECH PROJECT, 2019
** MY_SHOW_WORD_ARRAY
** File description:
** display the content of an array
*/

#include <stdlib.h>

void my_putchar(char c);
int my_putstr(char const *str);

int my_show_word_array(char * const *tab)
{
    int i =0;

    while (tab[i] != 0) {
		my_putstr(tab[i]);
		my_putchar('\n');
        i++;
	}
	return (0);
}
