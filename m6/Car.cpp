/* Citation and Sources...
Final Project Milestone ?
Module: ReadWritable
Filename: ReadWritable.cpp
Version 1.0
Author Anatoliy Serputov
Revision History
-----------------------------------------------------------
Date
2020/05/04
2020/05/04
Reason
Preliminary release
Debugged DMA
-----------------------------------------------------------
 I have done all the coding by myself and only copied the code
 that my professor provided to complete my workshops and assignments.
 The same way like Motorcycle.h
-----------------------------------------------------------*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "Car.h"
#include <cctype>
#include <cstring>
#include "string.h"
using namespace std;

namespace sdds{
    Car::Car(){
        flag = false;
    }
    Car::Car(const char* l_plate, const char* m_model):Vehicle(l_plate,m_model){
        flag = false;
    }
    istream& Car::read(istream& in){
    if (isCsv()){
        int cw_flag; 
        Vehicle::read(in);
        in >> cw_flag;
        in.ignore(1000, '\n');
        flag = bool(cw_flag);
    }else {
            bool ch = true;
            char value[5];
            cout << endl;
            cout << "Car information entry" << endl;
            Vehicle::read(in);
            cout << "Carwash while parked? (Y)es/(N)o: ";
            while (ch) {
                cin >> value;
                if (strlen(value) == 1) {
                    switch (value[0]) {
                    case 'Y':
                    case 'y':
                        ch = false;
                        flag = true;
                        break;
                    case 'N':
                    case 'n':
                        ch = false;
                        flag = false;
                        break;
                    default:
                        cout << "Invalid response, only (Y)es or (N)o are acceptable, retry: ";
                        ch = true;
                        cin.clear();
                        break;
                    }
                }
                else {
                    cout << "Invalid response, only (Y)es or (N)o are acceptable, retry: ";
                }
                cin.ignore(1000, '\n');
            }
        }

        return in;
    }

    ostream& Car::write(ostream& os) const{
        if (isEmpty()) {
            os << "Invalid Car Object" << endl;
        }else {
            if (isCsv()) {
                os << "C,";
            }else {
                os << "Vehicle type: Car" << std::endl;
            }
            Vehicle::write(os);
            if (isCsv()) {
                os << flag << std::endl;
            }else {
                if (flag) {
                    os << "With Carwash" << std::endl;
                }else {
                    os << "Without Carwash" << std::endl;
                }
            }
        }
        return os;
    }


}
