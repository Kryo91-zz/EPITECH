/*
** EPITECH PROJECT, 2019
** MY_SORT_PARAMS
** File description:
** display all its arguments in ascii order
*/

void my_sort_params(int argc, char **argv)
{
    int i = 1;
    char *j;

    while(argc > i) {
        if(my_strcmp(argv[i - 1], argv[i]) > 0) {
                j = argv[i - 1];
                argv[i - 1] = argv[i];
                argv[i] = j;
                i = 0;
            }
        i++;
    }
    i = 0;
    while(i < argc) {
        my_putstr(argv[i]);
        my_putchar('\n');
        i++;
    }
}

int main(int argc, char **argv)
{
    my_sort_params(argc, argv);
    return (0);
}

int my_putstr(char const *str)
{
    int k = 0;

    while(str[k] != '\0') {
        my_putchar(str[k]);
        k++;
    }
}
void my_putchar(char c)
{
    write(1, &c, 1);
}

int my_strcmp(char const *s1, char const *s2)
{
    int result = 0;
    int result2 = 0;
    char *str;
    char *str2;
    int a = 0;
    int b = 0;
    int res;

    while(s1[a] != '\0') {
        result = result + s1[a];
        a++;
    }
    while(s2[b] != '\0') {
        result2 = result2 + s2[b];
        b++;
    }
    res = result - result2;
}
                   
    
