/*
** EPITECH PROJECT, 2019
** MY_PRINT_PARAMS
** File description:
** display parameter set in the command line
*/

void my_print_params(int argc, char **argv)
{
    int i = 0;

    while(i < argc)
    {
        my_putstr(argv[i]);
        my_putchar('\n');
        i++;
    }
}

int main(int argc, char **argv)
{
    my_print_params(argc, argv);
    return (0);
}

int my_putstr(char const *str)
{
    int j = 0;

    while(str[j] != '\0') {
        my_putchar(str[j]);
        j++;
    }
}

void my_putchar(char c)
{
    write(1, &c, 1);
}
         
