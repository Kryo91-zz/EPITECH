/*
** EPITECH PROJECT, 2019
** my_compute_power_rec_test
** File description:
** yo
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>

int my_compute_power_rec(int n, int pow);

int my_compute_square_root(int nb);

int my_find_prime_sup(int nb);

int my_getnbr(char const *str);

int my_is_prime(int nb);

void my_putchar(char c);

int my_isneg(int n);

int my_put_nbr(int nb);

int my_putstr(char const *str);

char *my_revstr(char *str);

//char **my_str_to_word_array(char *str, char *delimiter);

int my_str_isalpha (char const *str);

int my_str_islower(char const *str);

int my_str_isnum(char const *str);

int my_str_isupper(char const *str);

char *my_str_lowcase(char *str);

char *my_strcat(char *dest, char const *src);

char *my_strcpy (char *dest ,char const *src);

int my_strlen(char const *str);

char *my_strstr(char const *first, char const *second);

char *my_strupcase(char *str);

void    my_swap(int *a, int *b);

int my_str_isprintable(char const *str);

char *my_strncpy(char *dest, char const *src, int n);

/*Test (my_strncpy, test_on_empty_string)
{ 
    char *dest = "";
    char *src = "";
    int n = 0;
    char *result = my_strncpy(dest ,src , n);
    cr_assert_eq(result, src);
}

Test (my_strncpy, test_on_normal_string)
{ 
    char dest[6];
    char src[] = "Hello";
    int n = 5;
    char *result = my_strncpy(dest ,src , n);
    cr_assert_eq(result, src);
}

Test (my_strncpy, test_n_is_null)
{ 
    char dest[6];
    char src[] = "Hello";
    int n = 0;
    char *result = my_strncpy(dest ,src , n);
    cr_assert_eq(result, src);
}

Test (my_strncpy, test_string_is_number)
{ 
    char dest[6];
    char src[] = "12345";
    int n = 3;
    char *result = my_strncpy(dest ,src , n);
    cr_assert_eq(result, src);
}*/

Test(my_str_isprintable, test_nothin_in_string)
{
    char str[] = "";
    int result = my_str_isprintable(str);

    cr_assert_eq(result, 1);
}

Test(my_str_isprintable, test_all_printable_str)
{
    char str[] = "hello";
    int result = my_str_isprintable(str);

    cr_assert_eq(result, 1);
}

Test(my_str_isprintable, test_noprintable)
{
    char str[] = "\a";
    int result = my_str_isprintable(str);

    cr_assert_eq(result, 0);
}
Test(my_str_isprintable, test_with_space)
{
    char str[] = "hello world";
    int result = my_str_isprintable(str);

    cr_assert_eq(result, 1);
}

Test(my_swap, should_reverse_character)
{
    int a[] = {1};
    int b[] = {2};
    my_swap(a, b);
    cr_assert_eq(*a, 2);
    cr_assert_eq(*b , 1);    
}

Test(my_swap, should_reverse_character_eq)
{
    int a[] = {1};
    int b[] = {1};
    my_swap(a, b);
    cr_assert_eq(*a, 1);
    cr_assert_eq(*b , 1);    
}

Test(my_swap, should_reverse_character_dif)
{
    int a[] = {16564668};
    int b[] = {15424957};
    my_swap(a, b);
    cr_assert_eq(*a, 15424957);
    cr_assert_eq(*b , 16564668);    
}

Test(my_strupcase, should_return_empty_string)
{
    char string[] = "";
    my_strupcase(string);
    cr_assert_str_empty(string);
}

Test(my_strupcase, should_return_A)
{
    char string[] = "a";
    my_strupcase(string);
    cr_assert_str_eq(string, "A");
}

Test(my_strupcase, should_return_ABCDE)
{
    char string[] = "abcde";
    my_strupcase(string);
    cr_assert_str_eq(string, "ABCDE");
}

Test(my_strupcase, should_return_ABCtiretCDE)
{
    char string[] = "ab-cde";
    my_strupcase(string);
    cr_assert_str_eq(string, "AB-CDE");
}

Test(my_strstr, should_find_empty_string_in_empty_string)
{
    char first[] = "";
    char second[] = "";
    char *result = my_strstr(first, second);
    cr_assert_eq(result, first);    
}

Test(my_strstr, should_find_empty_string_in_non_empty_string)
{
    char first[] = "hello";
    char second[] = "";
    char *result = my_strstr(first, second);
    cr_assert_eq(result, first);    
}

Test(my_strstr, should_not_find_non_empty_string_in_empty_string)
{
    char first[] = "";
    char second[] = "hello";
    char *result = my_strstr(first, second);
    cr_assert_null(result);
}

Test(my_strstr, should_find_BC_in_ABC)
{
    char first[] = "ABC";
    char second[] = "BC";
    char *result = my_strstr(first, second);
    cr_assert_eq(result, first + 1);
}

Test(my_strlen, test_on_empty_string)
{
    int result = my_strlen("");
    cr_assert_eq(result, 0);
}

Test(my_strlen, test_on_normal_string)
{
    int result = my_strlen("Hello");
    cr_assert_eq(result, 5);
}

Test(my_strlen, test_on_full_sentence)
{
    int result = my_strlen("Hello World!");
    cr_assert_eq(result, 12);
}

Test(my_strlen, test_on_potentially_broken_strings)
{
    int result = my_strlen("Hello+-*/\nworld");
    cr_assert_eq(result, 15);
}

Test(my_strcpy, should_return_string_Oui_from_src_string)
{
    char src[] = " Oui ";
    char dest[] = "";
    char *result = my_strcpy(dest, src);
    cr_assert_eq(result, dest);
}

Test(my_strcpy, should_find_empty_string_in_src)
{
    char src[] = "";
    char dest[] = "";
    char *result = my_strcpy (dest, src);
    cr_assert_eq (result, dest);
}

Test(my_strcat, should_concats_2_strings) {

    char message[] = "bonjour";
    char message2[] = "oui";

    cr_assert_str_eq(my_strcat(message, message2), "bonjouroui");
}


/*Test(my_str_to_word_array, should_return_NULL) {
    char message[] = "";
    char **result = my_str_to_word_array(message);
    cr_assert_not_null(result);
    cr_assert_null(result[0]);
}

Test(my_str_to_word_array, should_return_AAA_NULL) {
    char message[] = "AAA";
    char **result = my_str_to_word_array(message);
    cr_assert_not_null(result);
    cr_assert_str_eq(result[0], "AAA");
    cr_assert_null(result[1]);
}*/

Test(my_compute_power_rec, should_return_0_power_1)
{
    cr_redirect_stdout();
    int number = 0;
    int power = 1;
    int result = my_compute_power_rec(number, power);
    cr_assert_eq(0, result);
}

Test(my_compute_power_rec, should_return_0)
{
    cr_redirect_stdout();
    int number = 10;
    int power = -4;
    int result = my_compute_power_rec(number, power);
    cr_assert_eq(0, result);
}

Test(my_compute_power_rec, should_return_2_power_32)
{
    cr_redirect_stdout();
    int number = 2;
    int power = 32;
    int result = my_compute_power_rec(number, power);
    cr_assert_eq(0, result);
}

Test(my_compute_power_rec, should_return_3_power_6)
{
    cr_redirect_stdout();
    int number = 3;
    int power = 6;
    int result = my_compute_power_rec(number, power);
    cr_assert_eq(729, result);
}

Test(my_compute_power_rec, should_return_2401)
{
    cr_redirect_stdout();
    int number = -7;
    int power = 4;
    int result = my_compute_power_rec(number, power);
    cr_assert_eq(2401, result);
}

Test(my_compute_power_rec, should_return_square_root_of_64)
{
    int square = 64;
    int result = my_compute_square_root(square);
    cr_assert_eq(result, 8);
}

Test(my_compute_power_rec, should_return_0_with_0)
{
    int square = 0;
    int result = my_compute_square_root(square);
    cr_assert_eq(result, 0);
}

Test(my_compute_power_rec, should_return_0_with_5)
{
    int square = 5;
    int result = my_compute_square_root(square);
    cr_assert_eq(result, 0);
}

/*Test(my_find_prime_sup, zero_is_not_a_prime_number)
{
    int nb = my_find_prime_sup(0);
    cr_assert_eq(nb, 2);
}

Test(my_find_prime_sup, one_is_not_a_prime_number)
{
    int nb = my_find_prime_sup(1);
    cr_assert_eq(nb, 2);
}

Test(my_find_prime_sup, it_is_a_prime_number)
{
    int nb = my_find_prime_sup(600);
    cr_assert_eq(nb, 601);
}

Test(my_find_prime_sup, five_is_a_prime_number)
{
    int nb = my_find_prime_sup(-563);
    cr_assert_eq(nb, 2);
}*/

Test(my_getnbr, should_return_42)
{
    char str[] = "42jemepresentejemappellehenry42gentillepersonne";
    int nb = 0;

    nb = my_getnbr("42jemepresentejemappellehenry42gentillepersonne");
    cr_assert_eq(nb, 42);
}

Test(my_getnbr, should_return_neg42)
{
    char str[] = "-42";
    int nb = 0;

    nb = my_getnbr("-42");
    cr_assert_eq(nb, -42);
}

Test(my_getnbr, should_return_0)
{
    char str[] = "76543234567854";
    int nb = 0;

    nb = my_getnbr("76543234567854");
    cr_assert_eq(nb, 0);
}

Test(my_is_prime, zero_is_not_a_prime_number)
{
    int nb = my_is_prime(0);
    cr_assert_eq(nb, 0);
}

Test(my_is_prime, one_is_not_a_prime_number)
{
    int nb = my_is_prime(1);
    cr_assert_eq(nb, 0);
}

Test(my_is_prime, it_is_a_prime_number)
{
    int nb = my_is_prime(7789);
    cr_assert_eq(nb, 1);
}

Test(my_is_prime, it_is_not_prime_number)
{
    int nb = my_is_prime(172872);
    cr_assert_eq(nb, 0);
}

Test(my_is_prime, five_is_a_prime_number)
{
    int nb = my_is_prime(-563);
    cr_assert_eq(nb, 0);
}

Test (my_isneg, should_print_P)
{
    cr_redirect_stdout();
    my_isneg(0);
    cr_assert_stdout_eq_str("P");
}

Test (my_isneg, should_print_P2)
{
    cr_redirect_stdout();
    my_isneg(12);
    cr_assert_stdout_eq_str("P");
}

Test (my_isneg, should_print_P3)
{
    cr_redirect_stdout();
    my_isneg(54000);
    cr_assert_stdout_eq_str("P");
}

Test (my_isneg, should_print_N)
{
    cr_redirect_stdout();
    my_isneg(-20);
    cr_assert_stdout_eq_str("N");
}

Test (my_isneg, should_print_N2)
{
    cr_redirect_stdout();
    my_isneg(-50000);
    cr_assert_stdout_eq_str("N");
}

void redirect(void)
{
    cr_redirect_stdout();
}

Test(my_put_nbr, nbr_is_print, .init = redirect)
{
    int i = 53423;
    my_put_nbr(i);
    cr_assert_stdout_eq_str("53423", "53423");
}

Test(my_put_nbr, nbr_is_print2, .init = redirect)
{
    int i = 0;
    my_put_nbr(i);
    cr_assert_stdout_eq_str("0", "0");
}

Test(my_put_nbr, nbr_is_print3, .init = redirect)
{
    int i = -123456;
    my_put_nbr(i);
    cr_assert_stdout_eq_str("-123456", "-123456");
}

Test(my_putchar, should_print_A_into_stdout)
{
    cr_redirect_stdout();
    my_putchar('A');
    cr_assert_stdout_eq_str("A");
}

Test(my_putchar, should_print_Hello_into_stdout)
{
    cr_redirect_stdout();
    my_putchar('H');
    my_putchar('e');
    my_putchar('l');
    my_putchar('l');
    my_putchar('o');
    cr_assert_stdout_eq_str("Hello");
}

Test(my_putchar, should_print_non_printable_char_into_stdout)
{
    cr_redirect_stdout();
    my_putchar('\a');
    cr_assert_stdout_eq_str("\a");
}

Test(my_putstr, should_print_ABC_into_stdout)
{
    cr_redirect_stdout();
    my_putstr ("ABC");
    cr_assert_stdout_eq_str("ABC");
}

Test(my_putstr, should_print_non_printable_char_into_stdout)
{
    cr_redirect_stdout();
    my_putstr ("\a");
    cr_assert_stdout_eq_str("\a");
}

Test(my_putstr, should_print_C_into_stdout)
{
    cr_redirect_stdout();
    my_putstr ("C");
    cr_assert_stdout_eq_str("C");
}

Test(my_putstr, should_print_BONJOUR_KARIM_into_stdout)
{
    cr_redirect_stdout();
    my_putstr ("BONJOUR KARIM");
    cr_assert_stdout_eq_str("BONJOUR KARIM");
}

Test(my_revstr, should_return_empty_str)
{
    char str[] = "";
    my_revstr(str);
    cr_assert_str_empty(str);
}

Test(my_revstr, should_return_hello_revstr)
{
    char str[] = "Hello";
    my_revstr(str);
    cr_assert("olleH");
}

Test(my_revstr, should_return_helloworld_revstr)
{
    char str[] = "Hello World !";
    my_revstr(str);
    cr_assert("! dlroW olleH");
}

Test(my_revstr, should_return_string_HELLO)
{
    char message[] = "HELLO";
    my_revstr(message);
    cr_assert_str_eq(message, "OLLEH");
}

Test(my_revstr, should_return_string_Z)
{
    char message[] = "Z";
    my_revstr(message);
    cr_assert_str_eq(message, "Z");
}

Test(my_revstr, should_return_string_TOTO)
{
    char message[] = "TOTO";
    my_revstr(message);
    cr_assert_str_eq(message, "OTOT");
}

Test (my_str_isalpha, should_print_empty_string)
{
    int result = my_str_isalpha ("");
    cr_assert_eq (result, 1);
}

Test (my_str_isalpha, should_print_alpha_string)
{
    int result = my_str_isalpha ("hello");
    cr_assert_eq (result, 1);
}

Test (my_str_isalpha, should_print_no_alpha_string)
{
    int result = my_str_isalpha ("hello/");
    cr_assert_eq (result, 0);
}

Test(my_str_islower, should_return_1_full_low)
{
    int ret = my_str_islower("efkuzefbjkpjrgbjzefjio");
    cr_assert_eq(ret, 1);
}

Test(my_str_islower, should_return_0_full_maj)
{
    int ret = my_str_islower("AEJDDBDZOZDNZDZDP");
    cr_assert_eq(ret, 0);
}

Test(my_str_islower, should_return_0_mix)
{
    int ret = my_str_islower("efkuzefbjkpADJHDBDjrgbjzefjio");
    cr_assert_eq(ret, 0);
}

Test(my_str_islower, should_return_0_non_alpha_chars)
{
    int ret = my_str_islower("efkuzefbjk({(((%ddodozdjzd");
    cr_assert_eq(ret, 0);
}

Test(my_str_islower, should_return_0_only_non_alpha_chars)
{
    int ret = my_str_islower("{|((((2484204924");
    cr_assert_eq(ret, 0);
}

Test(my_str_islower, should_return_1_empty)
{
    int ret = my_str_islower("");
    cr_assert_eq(ret, 1);
}

Test(my_str_isnum, return_1)
{
    int i = 0;
    char str[] = "23456754323456787654";
    i = my_str_isnum(str);

    cr_assert_eq(i, 1);
}

Test(my_str_isnum, return_0_nummaj)
{
    int i = 0;
    char str[] = "12345SDFGX";
    
    i = my_str_isnum(str);
    cr_assert_eq(i, 0);
}

Test(my_str_isnum, return_1_numspace)
{
    int i = 0;
    char str[] = "12345 123456";

    i = my_str_isnum(str);
    cr_assert_eq(i, 1);
}

Test(my_str_isnum, return_0_maj_space)
{
    int i = 0;
    char str[] = "dzdzce CZEVRE";

    i = my_str_isnum(str);
    cr_assert_eq(i, 0);
}

Test(my_str_isupper, should_print_1_into_stdout)
{
    int i = 0;
    cr_redirect_stdout();
    i  = my_str_isupper("");
    cr_assert_eq(i, 1);
}

Test(my_str_isupper, should_print_Hello_into_stdout)
{
    int i = 0;
    cr_redirect_stdout();
    i = my_str_isupper("HELLO");
    cr_assert_eq(i, 1);
}

Test(my_str_isupper, should_print_non_printable_char_into_stdout)
{
    int i = 0;
    cr_redirect_stdout();
    i = my_str_isupper("a");
    cr_assert_eq(i, 0);
}
