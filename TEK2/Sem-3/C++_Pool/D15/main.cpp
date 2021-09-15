/*
** EPITECH PROJECT, 2020
** B-CPP-300-MPL-3-1-CPPD15-corentin.petrau
** File description:
** main.cpp
*/

#include "ex00/ex00.hpp"
#include <iostream>
#include <string>
#include "ex01/ex01.hpp"

class  toto
{
    public:
        toto() = default;
        toto &operator=( const  toto&) = delete;
        toto(const  toto &) = delete;
        bool  operator==( const  toto&)  const { return  true; }
        bool  operator>( const  toto&)  const { return  false; }
        bool  operator<( const  toto&)  const { return  false; }
};


// int main(int argc, char const *argv[])
// {
//     toto a, b;
//     std::cout << std::boolalpha << (compare(a, b) == 0) << std::endl;
//     std::cout << std::boolalpha << (compare<const char *>("chaineZ", "chaineA42") == 1) << std::endl;
//     const char *s1 = "42", *s2 = "lulz";
//     std::cout << std::boolalpha << (compare(s1, s2) == -1) << std::endl;
//     return 0;
// }

// #include "ex03/ex03.hpp"

// int main()
// {
//     int tab[] = { 11, 3, 89, 42 };
//     foreach(tab , print <int >, 4);
//     std:: string  tab2[] = { "j'", "aime", "les", "templates", "!" };
//     foreach(tab2 , print , 5);
//     return 0;
// }
#include "ex04/ex04.hpp"

int main ()
{
    // std::cout << "1 == 0 ? " << equal(1 , 0) << std::endl;
    // std::cout << "1 == 1 ? " << equal(1 , 1) << std::endl;
    // std::cout << "1 == 1 ? " << equal("1" , "1") << std::endl;

    // Tester <int> iT;
    // Tester <std::string> it;

    // std::cout << "41 == 42 ? " << iT.equal(41 , 42) << std::endl;
    // std::cout << "42 == 42 ? " << iT.equal(42 , 42) << std::endl;
    // std::cout << "chaine1 == 42 ? " << it.equal("chaine1" , "42") << std::endl;
    float nb = 1, nb2 = 0, nb3 = 1;
    double nb4 = 1, nb5 = 0, nb6 = 1;
    std::cout << "1 == 0 ? " << equal(1 , 0) << std::endl;
    std::cout << "1 == 1 ? " << equal(1 , 1) << std::endl;
    std::cout << "1 == 1 ? " << equal(nb , nb3) << std::endl;
    std::cout << "1 == 0 ? " << equal(nb , nb2) << std::endl;
    std::cout << "1 == 1 ? " << equal(nb4 , nb6) << std::endl;
    std::cout << "1 == 0 ? " << equal(nb4 , nb5) << std::endl;
    std::cout << "1 == 1 ? " << equal("1" , "1") << std::endl;

    Tester <int> iT;
    Tester <float> It;
    Tester <double> IT;
    Tester <std::string> it;

    std::cout << "41 == 42 ? " << iT.equal(41 , 42) << std::endl;
    std::cout << "42 == 42 ? " << iT.equal(42 , 42) << std::endl;
    std::cout << "41 == 42 ? " << IT.equal(41 , 42) << std::endl;
    std::cout << "42 == 42 ? " << IT.equal(42 , 42) << std::endl;
    std::cout << "41 == 42 ? " << It.equal(41 , 42) << std::endl;
    std::cout << "42 == 42 ? " << It.equal(42 , 42) << std::endl;
    std::cout << "chaine1 == 42 ? " << it.equal("chaine1" , "42") << std::endl;
    std::cout << "chaine1 == 42 ? " << it.equal("42" , "42") << std::endl;
    return 0;
}