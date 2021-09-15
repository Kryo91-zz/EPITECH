/*
** EPITECH PROJECT, 2020
** B-CPP-300-MPL-3-1-CPPrush3-lyvia.mallereau
** File description:
** CPUData.hpp
*/

#ifndef CPU_DATA_HPP_
    #define CPU_DATA_HPP_

    #include "Data.hpp"

    class CPUData : public IMonitorModule
    {
        public:
            CPUData(void);
            ~CPUData(void);
            void refreshData(void) override;
            std::string getData(void) const override;
            void updateCPULoad(void);

            int nb_processors;
            std::string model_name;
            int core_per_cpu;
            int nb_cpus; // siblings
            int work_load = 0;
            int idle_load = 0;
            float cpu_load = 0;
    };

#endif