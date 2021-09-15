

#include "Skat.hpp"

int main(int argc, char **argv)
{
    Skat s("Junior", 5);
    std::cout  << "Soldier " << s.name() << std::endl;
    s.status();
    s.useStimPaks();
    return  0;
}