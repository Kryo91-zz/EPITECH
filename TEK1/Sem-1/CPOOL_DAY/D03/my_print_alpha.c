/*
** EPITECH PROJECT, 2019
** MY_PRINT_ALPHA
** File description:
** displays the lowercase alphabet in ascending order
*/
int     my_print_alpha(void)
{
    int a = 97;
    while (a <= 122) {
            my_putchar (a);
            a = a + 1;
    }
}

