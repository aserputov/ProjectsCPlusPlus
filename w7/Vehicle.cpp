//==============================================
// Name:           Anatoliy Serputov
// Student Number: 167389188
// Email:          aserputov@myseneca.ca
// Section:        NCC
// Date:           10/03/2020
//==============================================

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "Vehicle.h"
using namespace std;

namespace sdds{
   Vehicle::Vehicle(){
       m_speed = 0;
       m_noOfSeats = 0;
    }
   Vehicle::Vehicle(int speed, int seats){
        if(speed >= MIN_SPEED || seats > 0){
            m_speed = speed;
            m_noOfSeats = seats;
        }
            
    }
    bool Vehicle::isEmpty()const{
        if(m_speed == 0 || m_noOfSeats == 0)
            return true;
        else
            return false;
    }
    bool Vehicle::finetune(){
        if(m_speed > MAX_SPEED){
            m_speed = MIN_SPEED;
            return true;
        }
        else{
            cout << "The car cannot be tuned" << endl;
            return false;
        }
    }

    std::ostream& Vehicle::display(std::ostream& os) const{
        if(m_speed>=MIN_SPEED && m_noOfSeats > 0 ){
            os<<"|"<< this->m_speed << "|" << this->m_noOfSeats << std::endl;
        }
        if(m_speed>MAX_SPEED){
            os<<"Car has to be fine tuned for speed limit"<< std::endl;
        }
        if(isEmpty()== true){
            os<<"This Car is not initiated"<< std::endl;
        }
         return os;
    }
    std::istream& Vehicle::input(std::istream& in){
        int tmp;
        cout<<"Enter the Vehicle`s speed: ";
        cin >> tmp;
        m_speed = tmp;
        int sts;
        cout<<"Enter no of seats: ";
        cin >> sts;
        m_noOfSeats = sts;
        return cin;
    }
    ostream& operator<<(ostream& os, const Vehicle& v){
        v.display(os);
        return os;
    
    }
    istream& operator>>(istream& in, Vehicle& V){
        V.input(in);
        return in;
    
    }
   

}
