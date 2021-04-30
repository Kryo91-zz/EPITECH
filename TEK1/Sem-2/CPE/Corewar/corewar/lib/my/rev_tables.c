/*
** EPITECH PROJECT, 2019
** my_revstr
** File description:
** reverse str
*/

void my_revstr(char *str)
{
    int len = 0;
    char swap = 0;

    for (; str[len]; len++);
    for (int i = 0; i < len / 2; i++) {
        swap = str[i];
        str[i] = str[len - i - 1];
        str[len - i - 1] = swap;
    }
}

void rev_int_arr(int *arr, int len)
{
    int swap = 0;

    for (int i = 0; i < len / 2; i++) {
        swap = arr[i];
        arr[i] = arr[len - i - 1];
        arr[len - i - 1] = swap;
    }
}

void rev_ptr_tab(void *tab)
{
    int len = 0;
    void **arr = (void **)tab;
    void *swap = 0;

    for (; arr[len]; len++);
    for (int i = 0; i < len / 2; i++) {
        swap = arr[i];
        arr[i] = arr[len - i - 1];
        arr[len - i - 1] = swap;
    }
}