/*
** EPITECH PROJECT, 2019
** MY_ISNEG
** File description:
**displays either N if the number is negative, P if positive or null
*/
void my_putchar(char c);

int     my_isneg(int n)
{
    if (n >= 0) {
        my_putchar ('P');
    }
    if (n < 0) {
        my_putchar ('N');
    }
    return (0);
}

