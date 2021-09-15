/*
** EPITECH PROJECT, 2020
** ex00
** File description:
** WarpSystem.hpp
*/

#ifndef WARPSYSTEM_HPP_
#define WARPSYSTEM_HPP_

namespace WarpSystem
{
    class QuantumReactor
    {
        private:
            bool _stability;
        public:
            QuantumReactor(void);
            ~QuantumReactor(void);
            bool isStable(void);
            void setStability(bool stability);
    };
    class Core
    {
        private:
            QuantumReactor *_coreReactor = nullptr;
        public:
            Core(WarpSystem::QuantumReactor *coreReactor);
            ~Core(void);
            QuantumReactor *checkReactor(void);
    };
};

#endif /* !WARPSYSTEM_HPP_ */