/*
** EPITECH PROJECT, 2020
** B-CPP-300-MPL-3-1-CPPD07A-corentin.petrau
** File description:
** criterion.c
*/

#include "../ex00/Skat.hpp"
#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <assert.h>
#include <cassert>
#include <utility>
#include "../ex00/Skat.cpp"
#include <functional>
#include <stdfix.h>
#include <ostream>

// namespace MyNamespace
// {
//     class TEST_CLASS
//     {
//         public :
//             class TEST_METHOD
//             {
//                 Skat s();
//                 Assert::("Soldier bob reporting 15 stimpaks remaining sir!\n");
//             };
//     };
// };

// Test(eq, sould_return_a_bool_true_to_check_eqality_int)
// {

// }

// Test(eq, sould_return_a_bool_false_to_check_eqality_int)
// {

//     cr_assert_eq(res_eq, 0);
// }

// Test(eq, sould_return_a_bool_true_to_check_greater_int)
// {

//     cr_assert_eq(res_gt, 1);
// }

// Test(eq, sould_return_a_bool_false_to_check_greater_int)
// {


//     cr_assert_eq(res_gt, 0);
// }

// Test(eq, sould_return_a_bool_true_to_check_less_int)
// {


//     cr_assert_eq(res_lt, 1);
// }

// Test(eq, sould_return_a_bool_false_to_check_less_int)
// {


//     cr_assert_eq(res_lt, 0);
// }

// Test(addition, sould_add_int)
// {


//     cr_assert_str_eq(str(res), "<Int (11)>");
// }

// Test(subtraction, sould_sub_int)
// {


//     cr_assert_str_eq(str(res), "<Int (9)>");
// }

// Test(multiplication, sould_mul_int)
// {


//     cr_assert_str_eq(str(res), "<Int (10)>");
// }

// Test(division, sould_div_int)
// {


//     cr_assert_str_eq(str(res), "<Int (10)>");
// }

class OSRedirector {
    private:
        std::ostringstream _oss;
        std::streambuf *_backup;
        std::ostream &_c;

    public:
        OSRedirector(std::ostream &c) : _c(c) {
            _backup = _c.rdbuf();
            _c.rdbuf(_oss.rdbuf());
        }

        ~OSRedirector() {
            _c.rdbuf(_backup);
        }

        const std::string getContent() {
            _oss << std::flush;
            return _oss.str();
        }
};

Test(Redirector, read_all_content) {
    OSRedirector oss(std::cout);
    Skat s();

    std::cout << s.status() << std::endl;
    cr_assert_eq(oss.getContent(), "Toto\n");
}