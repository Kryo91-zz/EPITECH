/*
** EPITECH PROJECT, 2020
** B-CPP-300-MPL-3-1-CPPrush3-lyvia.mallereau
** File description:
** DiskData.hpp
*/

#ifndef DISK_DATA_HPP_
    #define DISK_DATA_HPP_

    #include "Data.hpp"

    class DiskData : public IMonitorModule
    {
        public:
            DiskData(void);
            ~DiskData(void);
            void refreshData(void) override;
            std::string getData(void) const override;

            int kilo_octets_used = 0; // Il faut qu'on trouve ce que c'est
    };

#endif