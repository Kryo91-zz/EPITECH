/*
** EPITECH PROJECT, 2019
** MY_REV_PARAMS
** File description:
** reverse all parameter set in the command line
*/
void my_rev_params(int argc, char **argv)
{
    int i;

    i = argc - 1;

    while(i >= 0)
    {
        my_putstr(argv[i]);
        my_putchar('\n');
        i--;
    }
}

int main(int argc, char **argv)
{
    my_rev_params(argc, argv);
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
