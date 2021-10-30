//==============================================
// Name:           Anatoliy Serputov
// Student Number: 167389188
// Email:          aserputov@myseneca.ca
// Section:        NCC
// Date:           09/02/2020
//==============================================
// Train.h
#ifndef sdds_Train_H
#define sdds_Train_H
#pragma once
using namespace std;

namespace sdds
{
    
    class Saiyan
    {
        char m_name[30];
        int m_dob;
        unsigned int m_power;
        bool m_super = false;
        int m_level = 0;
        char *all_name = nullptr;

    public:
        Saiyan();
        Saiyan(const char m_name [],
            int m_dob,
            unsigned int m_power);
        bool isSuper() const;
        bool isValid()const;
        void powerup();
        void setEmpty();
        void display() const;
        void set(const char* name, int dob, int power, int level = 0, bool super = false);
        bool hasLost(Saiyan& other);
        ~Saiyan();
        
    };
    
}

#endif
