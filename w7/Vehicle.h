//==============================================
// Name:           Anatoliy Serputov
// Student Number: 167389188
// Email:          aserputov@myseneca.ca
// Section:        NCC
// Date:           10/03/2020
//==============================================
#pragma once
#ifndef SDDS_VEHICLE_H__
#define SDDS_VEHICLE_H__
const int MIN_SPEED = 100;
const int MAX_SPEED = 140;
using namespace std;

namespace sdds{

        class Vehicle{
            int m_speed;
            int m_noOfSeats;
        public:
            Vehicle();
            Vehicle(int speed,int seats);
            bool isEmpty () const;
            bool finetune();
            ostream& display(ostream& os) const;
            istream& input(istream& in);
            friend ostream& operator<<(ostream& os, const Vehicle& v);
            friend istream& operator>>(istream& in, Vehicle& V);
    
        
        };
    
    }
    


#endif
