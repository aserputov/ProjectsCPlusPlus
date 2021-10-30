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
           
           if(type != nullptr && strlen(type) > 0 && x > 0){
               this->ship_type = new char[strlen(type)+1];
               strcpy(this->ship_type,type);
               this->eng_arr = new Engine[x];
               for(int i=0;i< x; i++)
                    this->eng_arr[i]=eng_ar[i];
               this->length = x;
           }
           else{
               this->setEmpty();
           }
           
         // if(strlen(ship_type) <= 6 && strlen(ship_type) != 0 && length >= 1){
      
          }
           //else{
         //    *this = Ship();
       //}
           
       //}
    void Ship::setEmpty()
      {
          this->ship_type = nullptr;
          this->length = 0;
          this->eng_arr = nullptr;
          
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
bool Ship::isValid() {
     return (this->ship_type != nullptr && this->length < MAX_L );
  }
Ship& Ship::operator+=(Engine e){
    if(isValid()){
        
        
        Engine* arr_ptr = new Engine[this->length+1];
        for(int i = 0;i<this->length;i++){
            arr_ptr[i] = this->eng_arr[i];
        }
        arr_ptr[this->length] = e;
        
        delete [] this->eng_arr;
        this->eng_arr = nullptr;
        eng_arr = arr_ptr;
        this->length++;
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
}

Ship::~Ship(){
    delete[] eng_arr;
    eng_arr = nullptr;
    delete[] ship_type;
    ship_type = nullptr;
}


}


//  Copyright © 2020 Anatoliy. All rights reserved.

