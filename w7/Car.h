//==============================================
// Name:           Anatoliy Serputov
// Student Number: 167389188
// Email:          aserputov@myseneca.ca
// Section:        NCC
// Date:           10/03/2020
//==============================================
#pragma once
#ifndef SDDS_CARS_H__
#define SDDS_CARS_H__
#include "Vehicle.h"
const int MAX_CHAR = 21;
const int MIN_YEAR = 2000;
using namespace std;

namespace sdds{
    class Car : public Vehicle{
        char m_carType[MAX_CHAR];
        int m_regYear;
    public:
        Car();
        Car(const char* type,int year,int speed,int seats);
        void finetune();
        ostream& display(ostream& os) const;
        istream& input(istream& in);
        friend ostream& operator<<(ostream& os, const Car& C);
        friend istream& operator>>(istream& in, Car& C);


    };


}



#endif
