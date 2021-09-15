/*
** EPITECH PROJECT, 2020
** ex00
** File description:
** Federation.hpp
*/

#include <string>
#include <iostream>
#include <fstream>
#include <cstring>
#include "WarpSystem.hpp"


namespace Federation
{
    namespace Starfleet
    {
        class Captain
        {
            private :
                std::string _name;
                int _age = 0;
            public :
                Captain(std::string name);
                ~Captain(void);
                std::string getName(void);
                int getAge();
                void setAge(int age);
        };
        class Ship
        {
            private :
                int _length;
                int _width;
                std::string _name;
                short _maxWarp;
                WarpSystem::Core *_core = nullptr;
            public :
                Ship(int length, int width, std::string name, short maxWarp);
                ~Ship(void);
                void setupCore(WarpSystem::Core *core);
                void checkCore(void);
                void promote(Federation::Starfleet::Captain *captain);
        };
        class Ensign
        {
            private :
                std::string _name;
            public :
                explicit Ensign(std::string name);
        };
    };
    class Ship
    {
        private :
            int _length;
            int _width;
            std::string _name;
            short _maxWarp;
            WarpSystem::Core *_core = nullptr;
        public :
            Ship(int length, int width, std::string name);
            ~Ship(void);
            void checkCore(void);
            void setupCore(WarpSystem::Core *core);

    };
};