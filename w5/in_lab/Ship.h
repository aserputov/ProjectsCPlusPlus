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
using namespace std;

namespace sdds
{
    
    class Ship
    {
        int length;
        char ship_type[7];
        Engine eng_arr[MAX_SIZE];
    public:
        Ship();
        Ship(const char* type,Engine* eng_ar, int length);
        void setEmpty();
        bool empty() const;
        float calculatePower() const;
        void display() const;
        Ship& operator+=(Engine e);
        friend bool operator==(const Ship&, const Ship&);
    };
    bool operator<(const Ship& y, double x);
}

#endif
