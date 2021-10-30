//==============================================
// Name:           Anatoliy Serputov
// Student Number: 167389188
// Email:          aserputov@myseneca.ca
// Section:        NCC
// Date:           4/02/2020
//==============================================
#define _CRT_SECURE_NO_WARNINGS
//Train.cpp
// Train.h
#include <iostream>
#include <cstring>
#include <iomanip>
#include "Saiyan.h"
#include "Saiyan.h"  // this is on purpose
using namespace std;

namespace sdds
{
    Saiyan::Saiyan()
    {
        setEmpty();
    }
    Saiyan::Saiyan(const char m_name [], int m_dob, unsigned int m_power)
    {
        
        if (m_dob > 2020) {
            m_dob = 0;
        };
        
        set( m_name, m_dob, m_power);
        

    }

    bool Saiyan::isSuper() const
    {
        if (m_super == false) {
            return false;
        }
        return true;
    }

    bool Saiyan::isValid() const
    {
        if (m_name[0] == '\0' || m_dob == 0 || m_power == 0 ) {
            return false;
        }
        else{
            return true;
        }
        

    }

    void Saiyan::setEmpty()
    {
         m_name[0] = '\0';
         m_dob = 0;
         this->m_power = 0;
         m_super = false;
         m_level = 0;
         all_name = nullptr;
    }
    void Saiyan::powerup()
    {
       
        if (m_super == true) {
             this->m_power = m_power*(m_level+1);
            
        }
        else {
            
        }


    }

    void Saiyan::display() const
    {
        if (isValid() == true) {
            cout << m_name << endl;
            cout << "DOB: " << m_dob << " Power: " << m_power << endl;
            
            if (m_super == false) {
                cout << "Super Saiyan Ability: " << "Not super Saiyan." << endl << endl;
            }
            else if (m_super == true) {
                cout << "Super Saiyan Ability: " << "Super Saiyan." << endl;
                cout << "Super Saiyan level is: " << m_level << endl;
            }
        }else{
            cout << "Invalid Saiyan!" << endl;
        }
    
        
        
    }

    void Saiyan::set(const char* name, int dob, int power, int level, bool super ) {
        if ((name == nullptr) || strcmp(name, "") == 0) {
            strcpy(m_name, "");
        }
        else {
            if(all_name != nullptr)
                delete[] all_name;
            
            all_name = new char[strlen(name) + 1];
            strcpy(all_name, name);
            strcpy(m_name,all_name);
        }
        if (dob < 1) {  // I tried to change my if statements but actually my indexes will not be valid
            m_dob = 0;
        }
        else {
            m_dob = dob;
        }
        if (power < 0) {
            m_power = 0;
        }
        else {
            m_power = power;
        }
        if (level >= 0) {
            m_level = level;
        }
        else {
            m_level = level;
        }
        if (super == true) {
            m_super = super;
        }
        else {
            m_super = false;
        }

    }
        


    

bool Saiyan::hasLost( Saiyan& other){
    bool check;
    powerup();
    if (this->m_level != 0){
          
        if (this->m_power < other.m_power&& this->isValid() && other.isValid())
               check = false;
           
           else
               check = true;
    }else{
         powerup();
        if (this->m_power > other.m_power&& this->isValid() && other.isValid())
                      check = true;
            else
                      check = false;
    }
    
   
    
    
    return !check; //   it was diy part - so I did it in my original way(if it looks complicated next I will try to make it more better way)
    }
    
Saiyan::~Saiyan()
      {
          delete[] all_name;
          
      }
   
    
        
    

}
