/*
** EPITECH PROJECT, 2019
** Bistro-matic
** File description:
** arg error
*/

int error_arg_syn(char **av)
{
    int i = my_strlen(av[1]);
    int j = my_strlen(av[2]);

    if (i != 10) {
        write(2, "syntax error", 13);
        return (84);
    }
    if (j != 7) {
        write(2, "syntax error", 13);
        return (84);
    }
    if (error_identical_digit1(av) == 84 || error_identical_digit2(av) == 84)
        return (84);
    if (error_identical_ope1(av) == 84 || error_identical_ope2(av) == 84)
        return (84);
    return ;
}

int error_identical_digit1(char **argv)
{
    int c0 = 0;
    int c1 = 0;
    int c2 = 0;
    int c3 = 0;
    int c4 = 0;

    for (int i = 0;  argv[1][i] != '5'; ++i) {
        c0 += (argv[1][i] == '0');
        c1 += (argv[1][i] == '1');
        c2 += (argv[1][i] == '2');
        c3 += (argv[1][i] == '3');
        c4 += (argv[1][i] == '4');
    }
    if (c0 != 1 || c1 != 1 || c2 != 1 || c3 != 1 || c4 != 1) {
        write(2, "syntax error", 13);
        return (84);
    }
}

int error_identical_digit2(char **argv)
{
    int c5 = 0;
    int c6 = 0;
    int c7 = 0;
    int c8 = 0;
    int c9 = 0;

    for (int i = 5; argv[1][i] != '\0'; ++i) {
        c5 += (argv[1][i] == '5');
        c6 += (argv[1][i] == '6');
        c7 += (argv[1][i] == '7');
        c8 += (argv[1][i] == '8');
        c9 += (argv[1][i] == '9');

    }
    if (c5 != 1 || c6 != 1 || c7 != 1 || c8 != 1 || c9 != 1) {
        write(2, "syntax error", 13);
        return (84);
    }
}

int error_identical_ope1(char **argv)
{
    int c0 = 0;
    int c1 = 0;
    int c2 = 0;
    int c3 = 0;

    for (int i = 0; argv[2][i] != '*'; ++i) {
        c0 += (argv[2][i] == '(');
        c1 += (argv[2][i] == ')');
        c2 += (argv[2][i] == '+');
        c3 += (argv[2][i] == '-');
    }
    if (c0 != 1 || c1 != 1 || c2 != 1 || c3 != 1) {
        write(2, "syntax error", 13);
        return (84);
    }
}

int error_identical_ope2(char **argv)
{
    int c4 = 0;
    int c5 = 0;
    int c6 = 0;
    int i = 4;

    while (argv[2][i] != '\0') {
        c4 += (argv[2][i] == '*');
        c5 += (argv[2][i] == '/');
        c6 += (argv[2][i] == '%');
        ++i;
    }
    if (c4 != 1 || c5 != 1 || c6 != 1) {
        write(2, "syntax error", 13);
        return (84);
    }
}