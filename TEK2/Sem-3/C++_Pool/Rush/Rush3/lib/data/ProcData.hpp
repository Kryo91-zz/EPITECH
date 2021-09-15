/*
** EPITECH PROJECT, 2020
** B-CPP-300-MPL-3-1-CPPrush3-lyvia.mallereau
** File description:
** ProcData.hpp
*/

#ifndef PROC_DATA_HPP_
    #define PROC_DATA_HPP_

    #include "Data.hpp"

    std::string string_exec(const char* cmd);

    class ProcData : public IMonitorModule
    {
        public:
            ProcData(void);
            ~ProcData(void);
            void refreshData(void) override;
            std::string getData(void) const override;

            size_t nb_processes = 0;
            size_t nb_users = 1;
    };

#endif