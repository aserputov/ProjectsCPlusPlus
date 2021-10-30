//==============================================
// Name:           Anatoliy Serputov
// Student Number: 167389188
// Email:          aserputov@myseneca.ca
// Section:        NCC
// Date:           10/03/2020
//==============================================

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <iomanip>
#include "Car.h"
#include "Vehicle.h"

using namespace std;

namespace sdds{
    Car::Car(){
        m_carType[0] = '\0';
        m_regYear = 0;
    }

    Car::Car(const char* type,int year,int speed,int seats):Vehicle( speed, seats){//4 arg
        if(type[0] != '\0' && year > 2000 ){
            strcpy(m_carType,type);
            
                m_regYear = year;
            
            
        }else{
            
                *this = Car();
        }
    }
    void Car::finetune(){
        if(m_regYear < MIN_YEAR){
            cout<<"Car cannot be tuned and has to be scraped"<< endl;
        }else{
            Vehicle::finetune();
            cout<<"This car is finely tuned to default speed"<< endl;
        }
    }
    ostream& Car::display(ostream& os) const{
        if(m_carType[0] == '\0' || m_regYear == 0){
            os<<"Car is not initiated yet"<< std::endl;
        }else{
            os.width(20);
            os<< left << m_carType << m_regYear;
            Vehicle::display(os);
        }
     return os;
    }
    istream& Car::input(istream& in){
        char m_carType[MAX_CHAR];
        cout<<"Enter the car type: ";
        in.getline(m_carType,MAX_CHAR);
        int tmp;
        cout<<"Enter the car registration year: ";
        cin>>tmp;
        // assign tmp to ???
        strcpy(this->m_carType, m_carType);
        if(tmp > 2000){
        m_regYear = tmp;
        }
        Vehicle::input(in);
        return in;
    }
    ostream& operator<<(ostream& os, const Car& C){
        C.display(os);
        return os;
    }
    istream& operator>>(istream& in, Car& C){
        C.input(in);
        return in;
    }

    
    }
