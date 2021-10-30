/* Citation and Sources...
Final Project Milestone ?
Module: ReadWritable
Filename: ReadWritable.h
Version 1.0
Author Anatoliy Serputov
Revision History
-----------------------------------------------------------
Date
2020/24/03
2020/24/03
Reason
Preliminary release
Debugged DMA
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------*/
#pragma once
#include <iostream>
#include "ReadWritable.h"
using namespace std;
const int MAX_PLATE = 8;
namespace sdds{

class Vehicle : public ReadWritable{
        char l_plate[MAX_PLATE+1];
        char* m_model;
        int ps_number;
   
    protected:
        void setEmpty();
        bool isEmpty()const;
        const char* getMakeModel() const;
        void setMakeModel(const char* model);
    public:
        Vehicle();
        Vehicle(const char* plate, const char* model);
        Vehicle(const Vehicle& src)=delete;
        Vehicle& operator =(const Vehicle& src) = delete;
        ~Vehicle();
        int getParkingSpot() const;
        void setParkingSpot(int number);
        const char* getLicensePlate() const;
        friend bool operator==(const Vehicle& src, const char* ptr);
        friend  bool operator==(const Vehicle& src, const Vehicle& ptr);
        ostream& write(ostream& os= cout) const;
        istream& read(istream& in = cin) ;
        
    };
}


