/*
** EPITECH PROJECT, 2019
** CONCATS_PARAMS
** File description:
** turn the command-line into a single string
*/
#include <stdlib.h>

int my_putstr(char const *str);
void my_putchar(char c);

char *concat_params(int argc, char **argv)
{
    int i = 0;
    char *dest = malloc(1);
    
    while(i < argc)
    {
        dest[i] = argv[i];
	my_putstr(argv[i]);
        my_putchar('\n');
        i++;
        dest++;
    }
    return(dest);
}
         
