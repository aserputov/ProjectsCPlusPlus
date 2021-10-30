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
My friend Andrei Batomonkuev 119124126  helped me with exactly functions:
bool operator==(const Vehicle& first, const Vehicle& second)(not all part more logic for operators )
istream& Vehicle::read(istream& in)
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
       setEmpty();
    }

    Vehicle::Vehicle(const char* plate, const char* model){
        if ( plate == nullptr || strlen(plate) < 0 || strlen(plate) >= MAX_PLATE || model == nullptr || strlen(model) < 0 || strlen(model) <= 2) {
            setEmpty();
        }else {
            setEmpty();
            strcpy(l_plate, plate);
            setMakeModel(model);
        }
    }

    void Vehicle::setEmpty(){
        l_plate[0] = '\0';
        m_model = nullptr;
        ps_number = 0;
    }
    bool Vehicle::isEmpty() const{
        if (m_model == nullptr || l_plate[0] == '\0'){
            return true;
        }else
            return false;
    }

    const char* Vehicle::getLicensePlate() const {
        return l_plate;
    }

    const char* Vehicle::getMakeModel() const{
        return m_model;
    }

    void Vehicle::setMakeModel(const char* model){
        if (m_model != nullptr){
            delete[] m_model;
            m_model = nullptr;
        }
        if(model == nullptr || strlen(model) < 0) {
            m_model = nullptr;
            setEmpty();
        }else{
            m_model = new char[strlen(model) + 1];
            strcpy(m_model, model);
            
        }
    }
    int Vehicle::getParkingSpot() const{
        return ps_number;
    }

    void Vehicle::setParkingSpot(int number){
        if (number < 0) {
            delete[] m_model;
            setEmpty();
        }
        else {
            ps_number = number;
        }
    }
    istream& Vehicle::read(istream& in){
        char model[60];
        if (isCsv()) {
            int park_n;
            in >> park_n;
            setParkingSpot(park_n);
            in.ignore(1, ',');
            in.getline(l_plate, 9, ',');
                for (int i = 0; l_plate[i] != '\0'; i++) {
                    l_plate[i] = char(toupper(l_plate[i]));
                }
            in.getline(model, 60, ',');
            setMakeModel(model);
        }else{
            cout << "Enter Licence Plate Number: ";
            in.getline(l_plate,60,'\n');
                while (strlen(l_plate) > 8 || strlen(l_plate) < 1) {
                    cout << "Invalid Licence Plate, try again: ";
                    in.getline(l_plate, 60, '\n');
                }
                for (int i=0; l_plate[i] != '\0'; i++) {
                    l_plate[i] = char(toupper(l_plate[i]));
                }
            cout << "Enter Make and Model: ";
            in.getline(model,60,'\n');
                while (strlen(model) < 2 || strlen(model) > 60) {
                    cout << "Invalid Make and model, try again: ";
                    in.getline(model,60, '\n');
                }
            setMakeModel(model);
            ps_number = 0;
        }
            if (in.fail()) {
                setEmpty();
            }
        return in;
    }

    ostream& Vehicle::write(ostream& os) const{
        if (!isEmpty()) {
            if (isCsv()) {
                os << getParkingSpot() << "," << getLicensePlate() << "," << getMakeModel() << ",";
            }else {
                os << "Parking Spot Number: ";
                if (ps_number != 0) {
                    os << getParkingSpot() ;
                }else {
                    os << "N/A";
                }
                os << std::endl;
                os << "Licence Plate: " << getLicensePlate() << std::endl;
                os << "Make and Model: " << getMakeModel() << std::endl;
            }
        }else{
            os << "Invalid Vehicle Object" << std::endl;
        }
        return os;
    }

    bool operator==(const Vehicle& src, const char* ptr){
        bool ch = false;
        if (ptr != nullptr || src.l_plate[0] != '\0') {
            char tmp[MAX_PLATE];
            char tmpl[MAX_PLATE];
            strcpy(tmp, src.l_plate);
            strcpy(tmpl, ptr);
            for (int a = 0; tmpl[a] != '\0'; a++) {
                tmpl[a] = char(toupper(tmpl[a]));
            }
            for (int i = 0; tmp[i] != '\0'; i++) {
                tmp[i] = char(toupper(tmp[i]));
            }
            if (strcmp(tmp, tmpl) == 0) {
                ch = true;
            }

        }
        return ch;
    }

    bool operator==(const Vehicle& src, const Vehicle& ptr){
        bool ch = false;
        
        if (src.l_plate[0] != '\0' || ptr.l_plate[0] != '\0') {
            char tmp[MAX_PLATE];
            char tmpl[MAX_PLATE];
            strcpy(tmp, src.l_plate);
            strcpy(tmpl, ptr.l_plate);
            for (int a = 0; tmpl[a] != '\0'; a++) {
                tmpl[a] = char(toupper(tmpl[a]));
            }
            for (int i = 0; tmpl[i] != '\0'; i++) {
                tmp[i] = char(toupper(tmpl[i]));
            }
            if (strcmp(tmp, tmpl) == 0) {
                ch = true;
            }
        
        }
        return ch;
    }


    Vehicle::~Vehicle(){
        delete[] m_model;
        m_model = nullptr;
    }

}


