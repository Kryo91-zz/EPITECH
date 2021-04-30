/*
** EPITECH PROJECT, 2019
** my.h
** File description:
** all prototypes of all the lib
*/

#ifndef MY_H_
    #define MY_H_

    #include <stdlib.h>
    #include <stdio.h>
    #include <unistd.h>
    #include <stdbool.h>

    int my_factorial(int nb);
    int my_strlen(char const *str);
    int my_pow(int nb, int p);
    int my_sqrt(int nb);
    int my_getnbr(char const *str);
    void my_putchar(char c);
    bool isnum(char const *str);
    void my_put_nbr(int n);
    int my_putstr(char const *str);
    void my_revstr(char *str);
    void rev_int_arr(int *arr, int len);
    char *my_strcat(char const *dest, char const *src);
    int my_strcmp(char const *s1, char const *s2);
    char *my_strcpy(char *dest, char const *src);
    char *my_strdup(char const *src);
    char *my_strncat(char *dest, char const *src, int n);
    int my_strncmp(char const *s1, char const *s2, int n);
    char *my_strncpy(char *dest, char const *src, int n);
    int my_putnbr_base(long nbr, char const *base);
    int my_printf(char *str, ...);
    char *my_itos(long long nb);
    char *my_append_str(char *str, char c);
    void *append_array(void *arr, void *to_append);
    char **my_word_array(char *st);
    char **my_sep_array(char *st, char sep);
    bool str_is_blank(char *str);
    size_t array_len(void *array);
    int num_test(char *str);
    void my_exit(char *str, int code);
    int alpha_test(char *str);
    void free_array(void *array);
    void *ptr_message(char const *mess, void *ptr, int fd, void *to_free);
    int int_message(char const *mess, int to_ret, int fd, void *to_free);
    bool bool_message(char const *mess, bool to_ret, int fd, void *to_free);
    char char_message(char const *mess, char to_ret, int fd, void *to_free);
    ssize_t chompline(char **lineptr, size_t *n, FILE *stream);

    #ifndef FUNCTIONS_MY_PRINTF_H_
        #define FUNCTIONS_MY_PRINTF_H_

        #include <stdarg.h>
        #include <errno.h>
        #include <time.h>
        #include "my.h"

        void my_flag_p(va_list ap);
        void my_flag_x(va_list ap);
        void my_flag_bigx(va_list ap);
        void my_flag_o(va_list ap);
        void my_flag_b(va_list ap);
        void my_flag_c(va_list ap);
        void my_flag_mod(va_list ap);
        void my_flag_m(va_list ap);
        void my_flag_bigs(va_list ap);
        void my_flag_u(va_list ap);
        void my_flag_d_i(va_list ap);
        void my_flag_s(va_list ap);

        typedef struct pf_func_tab_s {
            char c;
            void (*ptr)(va_list);
        } pf_func_tab_t;

    #endif

#endif /*MY_H_ */
