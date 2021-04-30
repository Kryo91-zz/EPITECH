/*
** EPITECH PROJECT, 2019
** MY_STRCMP
** File description:
** compare two stringand return an integer number
*/

int my_strcmp(char const *s1, char const *s2)
{
    int result = 0;
    int result2 = 0;
    int res;

    for (int i = 0; s1[i] != '\0'; i+=1) 
        result = result + s1[i];
    for (int j = 0; s2[j] != '\0'; j+=1) 
        result2 = result2 + s2[j];

    res = result - result2;
    
    if(res > 0) {
        return (1);
    }
    if(res == 0) {
        return (0);
    }
    if(res < 0) {
        return (-1);
    }
}
