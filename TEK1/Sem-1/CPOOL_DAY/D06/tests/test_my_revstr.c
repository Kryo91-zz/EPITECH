#include <criterion/criterion.h>

char *my_revstr(char *str);

Test(my_revstr1, swap_character_one_by_one)
{
    cr_assert_str_eq(str("hello"), "olleh");
}
