/*
** EPITECH PROJECT, 2020
** B-CPP-300-MPL-3-1-CPPrush3-lyvia.mallereau
** File description:
** MemoryData.hpp
*/

#ifndef MEMORY_DATA_HPP_
    #define MEMORY_DATA_HPP_

    #include "Data.hpp"

    std::string string_exec(const char* cmd);

    class MemoryData : public IMonitorModule
    {
        public:
            MemoryData(void);
            ~MemoryData(void);
            void refreshData(void) override;
            std::string getData(void) const override;

            float swap_ratio;
            float ram_ratio;
    };

#endif