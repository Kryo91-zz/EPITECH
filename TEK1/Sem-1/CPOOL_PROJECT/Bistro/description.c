/*
** EPITECH PROJECT, 2019
** BISTROMATIC
** File description:
** Description
*/

void    my_putchar(char c);

int     my_putstr(char const *str);

void description(int argc, char **argv)
{
    if (argv[1][0] != '-' && argv[1][1] != 'h')
        return;

    else {
        my_putstr("USAGE\n");
        my_putstr("./calc base operators size_read\n");
        my_putchar('\n');
        my_putstr("DESCRIPTION\n");
        my_putstr("- base: all the symbols of the base\n");
        my_putstr("- operators: the symbols for the ");
        my_putstr("parentheses and the 5 operators\n");
        my_putstr("- size_read: number of characters to be read\n");
    }
}