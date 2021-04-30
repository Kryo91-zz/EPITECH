/*
** EPITECH PROJECT, 2019
** factorial
** File description:
** factorial
*/

int my_factorial(int factor)
{
    if (factor == 1)
        return (factor);
    for (int i = factor; i > 1; i--)
        factor *= i;
    return (factor);
}