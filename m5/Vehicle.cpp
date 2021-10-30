/* Citation and Sources...
Final Project Milestone ?
Module: ReadWritable
Filename: ReadWritable.cpp
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
Write exactly which part of the code is given to you as help and
who gave it to you, or from what source you acquired it.
My friend Nikita Sushko from another section helped me with exactly functions:
ostream& write(ostream& os) const;
bool operator==(const Vehicle& first, const Vehicle& second)(not all part)
ostream& Vehicle::write(ostream& os) const(just logic of this part)
-----------------------------------------------------------*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cctype>
#include <cstring>
#include "string.h"
#include "Vehicle.h"

using namespace std;

namespace sdds{
    
    Vehicle::Vehicle(){
        
         l_plate[0] = '\0';
         m_model= nullptr;
         ps_number = 0;
    }

    Vehicle::Vehicle(const char* plate, const char* model, int number){
    if (plate == nullptr || model == nullptr || strlen(plate) > 8 || model[0]=='\0' || strlen(model) < 2){
        m_model = nullptr;
        l_plate[0] = '\0';
        ps_number = 0;
    }else{
        strcpy(l_plate, plate);
        for (int i = 0; (size_t)i < strlen(l_plate); i++)
            l_plate[i] = toupper(l_plate[i]);
        m_model = new char[strlen(model)+1];
        strcpy(m_model, model);
        ps_number = number;
        }
    }
    Vehicle::~Vehicle(){
    delete[] m_model;
}
    void Vehicle::setEmpty(){
        l_plate[0] = '\0';
        m_model= nullptr;
        ps_number = 0;
    }
    bool Vehicle::isEmpty()const{
        if (m_model == nullptr || l_plate[0] == '\0'){
            return true;
        }else
            return false;
    }
    bool Vehicle::getLicensePlate() {
         return l_plate[0];
    }
    bool Vehicle::getMakeModel() {
        return this->m_model;
    }
    void Vehicle::setMakeModel(const char* model){
        if (m_model != nullptr)
            delete[] m_model;
        if (model == nullptr){
            m_model = nullptr;
        }else{
            m_model = new char[strlen(model) + 1];
            strcpy(m_model, model);
        }
    }
    int Vehicle::getParkingSpot() const{
        return ps_number;
    }
    void Vehicle::setParkingSpot(int number){
       if (number < 0){
            delete[] m_model;
            m_model = nullptr;
            l_plate[0] = '\0';
            ps_number = 0;
        }else{
            ps_number = number;
        }
    }
     bool operator==(const Vehicle& src, const char* plate){
              bool ret = 0;
              for (int i = 0; (size_t)i < strlen(plate); i++){
                  if (tolower(plate[i]) != tolower(src.l_plate[i]))
                      break;
                  if ((size_t)i == (strlen(plate) - 1))
                      ret = 1;
              }
              return ret;
          }
      
          bool operator==(const Vehicle& src, const Vehicle& ptr){
              bool ret = 0;
              for (int i = 0; (size_t)i < strlen(ptr.l_plate); i++){
                  if (tolower(ptr.l_plate[i]) != tolower(src.l_plate[i]))
                      break;
                  if ((size_t)i == (strlen(ptr.l_plate) - 1))
                      ret = 1;
              }
              return ret;
          }
    istream& Vehicle::read(istream& in){
       char getich[60] = { 0 };
        if (!isCsv()){
            cout << "Enter Licence Plate Number: ";
               in.clear();
               
               in.getline(l_plate,8,'\n');
           
            while (strlen(l_plate) > 8){
                for (int i = 0; (size_t)i < strlen(l_plate); i++)
                    l_plate[i] = '\0';
                cout << "Invalid Licence Plate, try again: ";
                in >> l_plate;
            }

            for (int i = 0; (size_t)i < strlen(l_plate); i++)
                l_plate[i] = toupper(l_plate[i]);

            cout << "Enter Make and Model: ";
            char test[61] = { 0 };
            in.clear();
            
            in.getline(test,60,'\n');
            while (strlen(test) < 2 || strlen(test) > 60)
            {
                for (unsigned int i = 0; i < strlen(test); i++)
                    test[i] = '\0';
                cout << "Invalid Make and model, try again: ";
                in >> test;
            }
            delete[] m_model;
            m_model = new char[strlen(test)+1];
            strcpy(m_model, test);
        }else{
            in >> ps_number;
            in.ignore(1, ',');
            in.getline(l_plate, 8, ',');
            for (int i = 0; (size_t)i < strlen(l_plate); i++)
                l_plate[i] = toupper(l_plate[i]);
            
            in.getline(getich, 60, ',');
            delete[] m_model;
            m_model = new char[strlen(getich)+1];
            strcpy(m_model, getich);
        }
        if (in.fail()){
            this->setEmpty();
        }
        return in;
    }

    ostream& Vehicle::write(ostream& os) const{
       if (this->isEmpty()){
                    cout << "Invalid Vehicle Object" << endl;
                }else{
                    if (this->isCsv()){
                        cin.clear();
                        cout << ps_number << "," << l_plate << "," << m_model << ",";
                    }else{
                        cout << "Parking Spot Number: ";
                        if (ps_number){
                            cout << ps_number;
                        }else{
                            cout << "N/A";
                        }
                        cout << endl;
        
                        cout << "Licence Plate: " << l_plate << endl;
                        cout << "Make and Model: " << m_model << endl;
                    }
                }
                return os;
            }
    }

    









