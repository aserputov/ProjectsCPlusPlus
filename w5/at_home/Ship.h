//==============================================
// Name:           Anatoliy Serputov
// Student Number: 167389188
// Email:          aserputov@myseneca.ca
// Section:        NCC
// Date:           11/02/2020
//==============================================
//
#ifndef sdds_ship_h
#define sdds_ship_h
#define FIX 10
#pragma once
#include "Engine.h"
const int MAX_SIZE = 31;
const int MAX_STR = 7;
const int MAX_L = 10;
using namespace std;

namespace sdds
{
    
    class Ship
    {
        int length;
        char *ship_type;
        Engine *eng_arr;
        //Engine eng_arr[];
    public:
        Ship();
        Ship(const char* type,Engine* eng_ar, int length);
        ~Ship();
        void setEmpty();
        bool empty() const;
        float calculatePower() const;
        void display() const;
        bool isValid();
        Ship& operator+=(Engine e);
        friend bool operator==(const Ship&, const Ship&);
        
    };
    bool operator<(const Ship& y, double x);
}

#endif
