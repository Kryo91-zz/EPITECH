/*
** EPITECH PROJECT, 2020
** hospital
** File description:
** KoalaNurse.cpp
*/

#include "KoalaNurse.hpp"

KoalaNurse::KoalaNurse(std::string id)
{
    this->id = id;
}

KoalaNurse::~KoalaNurse()
{
    std::cout << "Nurse" << this->id << ": Finally some rest!" << std::endl;
}

void KoalaNurse::giveDrug(std::string drug, SickKoala *koala)
{
    koala->takeDrug(drug);
}

int count_cara(std::string filename)
{
    int i = 0;

    for (; filename[i+1] && filename[i] != '.' && filename[i+1] != 'r'; ++i);
    
    return i;
}

bool check_report(int i, std::string filename)
{
    std::string check;

    for (int j = 0; filename[i]; ++i, ++j)
        check[j] = filename[i];
    if (check.compare(".report") == 0)
        return (false);
    return true;  
}

std::string KoalaNurse::readReport(std::string filename)
{
    int i = count_cara(filename);
    if (check_report(i, filename) == 0)
        return ("");
    std::string line;
    char c = 'c';
    std::ifstream file_name;
    file_name.open(filename, std::fstream::in);
    std::string patientName = filename.substr(0, i);
    std::string drug;

    for (int nb = 0; file_name.eof() == 0; ++nb) {
        file_name.get(c);
        if (file_name.eof() == 0)
            drug[nb] = c;
    }
    std::cout << "Nurse" << this->id << ": " << "Kreog! Mr." << patientName << " needs a " << drug.c_str() << "!" << std::endl;
    return (drug);
}
 