//==============================================
// Name:           Anatoliy Serputov
// Student Number: 167389188
// Email:          aserputov@myseneca.ca
// Section:        NCC
// Date:           11/02/2020
//==============================================
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <iomanip>
#include "Ship.h"
#include "Engine.h"
// this is on purpose
using namespace std;

namespace sdds
{
    Ship::Ship(){
        setEmpty();
    }

    Ship::Ship(const char* type,Engine* eng_ar, int x){
        setEmpty();
       //if(strlen(ship_type) <= 6 && strlen(ship_type) != 0 && length >= 1){
            strcpy(ship_type,type);
            for(int i=0;i<x;i++){
                eng_arr[i]=eng_ar[i];
            }
            length = x;
   
//        }
//        else{
//            *this = Ship();
//        }
        
    }
    void Ship::setEmpty()
      {
          ship_type[0] = '\0';
          length = 0;
          eng_arr[0] = {0,'\0'};
      }
bool Ship::empty() const{
    return length == 0;
}
float Ship::calculatePower() const{
    float eng_power = 0.00;
    for(int i=0;i<length;i++){
        eng_power += eng_arr[i].get() * 5;
    }
    return eng_power;
}
void Ship::display() const{
    if(!empty()){
        if(calculatePower() > 100){
            cout << ship_type << "-" ;
            cout << fixed << setprecision(2) << calculatePower() << endl;
        }else{
            cout << ship_type << "- " ;
            cout << fixed << setprecision(2) << calculatePower() << endl;
        }
        
        for(int i=0;i<length;i++){
             eng_arr[i].display();
        }
    }
    else {
        cout << "No available data" << endl;
    }
    
}
Ship& Ship::operator+=(Engine e){
    if(e.get() < FIX || strlen(ship_type) != 0){
         eng_arr[length] = e;
         length++;
    }else{
        cout << "The ship doesn't have a type! Engine cannot be added!"<< endl;
    }
    return *this;
}
    
bool operator==(const Ship& a, const Ship& b){
    return (a.calculatePower()==b.calculatePower());
}
bool operator<(const Ship& y, double x){
    return (y.calculatePower() < x );
};
}


//  Copyright © 2020 Anatoliy. All rights reserved.

