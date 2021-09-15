/*
** EPITECH PROJECT, 2020
** B-CPP-300-MPL-3-1-CPPrush3-lyvia.mallereau
** File description:
** NetData.hpp
*/

#ifndef NET_DATA_HPP_
    #define NET_DATA_HPP_

    #include "Data.hpp"

    class NETData : public IMonitorModule
    {
        public:
            NETData(void);
            ~NETData(void);
            void refreshData(void) override;
            std::string getData(void) const override;

            std::string name = "";
            size_t bytes_receive = 0;
            size_t bytes_transmit = 0;
            size_t packets_receive = 0;
            size_t packets_transmit = 0;
    };

#endif