/*
** EPITECH PROJECT, 2019
** my_str_to_word_array
** File description:
** str to array
*/

#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>

int my_strlen(char *str);

char **alloc(char *str, char sepa, char **word_array)
{
    int spaces = 0;
    int where = 0;
    int letters = 0;
    int test = 0;

    while (str[test] == ' ' || str[test] == sepa) {
        test += 1;
    }
    for (int i = test; i < my_strlen(str); i++) {
    if ((str[i] == ' ' || str[i] == sepa) && str[i + 1]
    != ' ' && str[i + 1] != sepa)
        spaces += 1;
    }
    word_array = malloc(sizeof(char *) * (spaces + 2));
    for (int i = test; i < my_strlen(str); i++) {
        if (((str[i] == ' ' || str[i] == sepa) &&
        str[i + 1] != ' ' && str[i + 1] != sepa) || str[i + 1] == '\0') {
            word_array[where] = malloc(sizeof(char) * (letters + 2));
            where += 1;
            letters = 0;
        } else {
            letters += 1;
        }
    }
    return (word_array);
}

char **my_str_to_word_array(char *str, char sepa)
{
    int where = 0;
    int second_where = 0;
    int i = 0;
    char **word_array = malloc(sizeof(char *) * 2);
    word_array = alloc(str, sepa, word_array);
    while (str[i] == ' ' || str[i] == sepa) {
        i += 1;
    }
    for (; i < my_strlen(str); i++) {
        if (((str[i] == ' ' || str[i] == sepa) &&
        (str[i + 1] != ' ' && str[i + 1] != sepa)) || str[i + 1] == '\0') {
            if (str[i + 1] == '\0') {
                word_array[where][second_where] = str[i];
                second_where += 1;
            }
            word_array[where][second_where] = '\0';
            where += 1;
            second_where = 0;
        } else if (str[i] != ' ' && str[i] != sepa){
            word_array[where][second_where] = str[i];
            second_where += 1;
        }
    }
    word_array[where] = NULL;
    return (word_array);
}