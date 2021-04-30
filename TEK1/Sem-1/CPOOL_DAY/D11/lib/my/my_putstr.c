/*
** EPITECH PROJECT, 2019
** MY_PUTSTR
** File description:
** displays, one by one the characters of a string
*/
void my_putchar(char c);

int my_putstr(char const *str)
{
    int i;
    
    i = 0;

    while (str[i] != '\0') {
        my_putchar(str[i]);
        i = i + 1;
    }
}
