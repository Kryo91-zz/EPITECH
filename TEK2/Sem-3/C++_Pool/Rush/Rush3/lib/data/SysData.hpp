/*
** EPITECH PROJECT, 2020
** B-CPP-300-MPL-3-1-CPPrush3-lyvia.mallereau
** File description:
** Data.hpp
*/

#ifndef SYSDATA_HPP_
    #define SYSDATA_HPP_

    #include <unistd.h>
    #include <unordered_map>
    #include "Data.hpp"
    #include "lib.hpp"
    #include "CPUData.hpp"
    #include "NetData.hpp"

    std::string get_curr_date(void);
    using string_map = std::unordered_map<std::string, std::string>;

    class SysData : public IMonitorModule
    {
        public:
            SysData(void);
            ~SysData(void);
            void refreshData(void) override;
            std::string getData(void) const override;
            string_map getMap(void) { return this->_map; }

            ProcData proc_data;
            DiskData disk_data;
            CPUData cpu_data;
            MemoryData memory_data;
            NETData net_data;
            std::string hostname = "";
            std::string username = "";
            std::string kernel_version;
            std::string curr_time;
            std::string proc_type;
            std::string machine_name;
            std::string distrib;
        private:
            string_map _map;
    };

#endif