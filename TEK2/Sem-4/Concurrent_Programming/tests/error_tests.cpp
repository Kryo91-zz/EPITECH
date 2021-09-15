/*
** EPITECH PROJECT, 2021
** B-CCP-400-MPL-4-1-theplazza-corentin.petrau
** File description:
** error_tests
*/

#include "../inc/inc.hpp"
#include "../inc/Error.hpp"
#include "criterion/criterion.h"
#include "criterion/redirect.h"
#include "../inc/Exception.hpp"

void redirect_all_std()
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}

Test(check_nb_args, throw_an_error_with_bah_args)
{
    int ac = 6;
    char **av;

    cr_assert_throw(Error err(ac, av), std::exception);
}

Test(check_null_args, throw_an_error_with_null)
{
    int ac = 0;
    char **av;

    cr_assert_throw(Error err(ac, av), std::exception);
}

Test(check_argv, throw_an_error_with_argv_1_false)
{
    int ac = 4;
    char *av1 = strdup("1");
    char *av2 = strdup("0");
    char *av[4] = {av2, av1, av2};

    cr_assert_throw(Error err(ac, av), std::exception);
}

Test(check_argv2, throw_an_error_with_argv_2_false)
{
    int ac = 4;
    char *av1 = strdup("1");
    char *av2 = strdup("0");
    char *av[4] = {av1, av2, av1};

    cr_assert_throw(Error err(ac, av), std::exception);
}

Test(check_argv3, throw_an_error_with_argv_3_false)
{
    int ac = 4;
    char *av1 = strdup("1");
    char *av2 = strdup("0");
    char *av[4] = {av1, av1, av2};

    cr_assert_throw(Error err(ac, av), std::exception);
}

Test(check_try_catch, throw_an_error, .init=redirect_all_std)
{
    int ac = 6;
    char **av;
    std::string pomme;

    try {
        Error err(ac, av);
    } catch (Exception &e) {
        pomme = e.what();
    }
    cr_assert_str_eq("Not enough argument to continue", pomme.c_str());
}

Test(check_try_catch_null, throw_an_error_null, .init=redirect_all_std)
{
    int ac = 0;
    char **av;
    std::string pomme;

    try {
        Error err(ac, av);
    } catch (Exception &e) {
        pomme = e.what();
    }
    cr_assert_str_eq("Not enough argument to continue", pomme.c_str());
}

Test(check_try_catch_bad_argv1, throw_an_error_argv1, .init=redirect_all_std)
{
    int ac = 4;
    char *av0 = strdup("./plazza");
    char *av1 = strdup("1");
    char *av2 = strdup("0");
    std::string pomme;
    char *av[5] = {av0, av2, av2, av2};
    try {
        Error err(ac, av);
    } catch (Exception &e) {
        pomme = e.what();
    }
    cr_assert_str_eq("Invalid multiplier", pomme.c_str());
}

Test(check_try_catch_bad_argv2, throw_an_error_argv2, .init=redirect_all_std)
{
    int ac = 4;
    char *av0 = strdup("./plazza");
    char *av1 = strdup("1");
    char *av2 = strdup("0");
    std::string pomme;
    char *av[5] = {av0, av1, av2, av2};
    try {
        Error err(ac, av);
    } catch (Exception &e) {
        pomme = e.what();
    }
    cr_assert_str_eq("Number should be non-null and positive", pomme.c_str());
}

Test(check_try_catch_bad_argv3, throw_an_error_argv3, .init=redirect_all_std)
{
    int ac = 4;
    char *av0 = strdup("./plazza");
    char *av1 = strdup("1");
    char *av2 = strdup("0");
    std::string pomme;
    char *av[5] = {av0, av1, av1, av2};
    try {
        Error err(ac, av);
    } catch (Exception &e) {
        pomme = e.what();
    }
    cr_assert_str_eq("Invalid restock time, should be non-null and positive", pomme.c_str());
}

Test(check_destruc, call_desctuctor, .init=redirect_all_std)
{
    int ac = 4;
    char *av0 = strdup("./plazza");
    char *av1 = strdup("1");
    char *av2 = strdup("0");
    std::string pomme;
    char *av[5] = {av0, av1, av1, av1};
    Error err(ac, av);
    err.~Error();
    cr_assert_str_eq("", "");
}