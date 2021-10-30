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
My friend Andrei Batomonkuev 119124196 helped with function read and write
He helped me to make a switch case,before you can check my ms 5 I use different way to work with this function
-----------------------------------------------------------*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "Motorcycle.h"
#include <cctype>
#include <cstring>
#include "string.h"
using namespace std;

namespace sdds{
    Motorcycle::Motorcycle(){
        h_flag= false;
    }
    Motorcycle::Motorcycle(const char* l_plate, const char* m_model):Vehicle(l_plate,m_model){
    h_flag = false;
    }
    istream& Motorcycle::read(istream& in)
    {
        if (isCsv()) {
            int h_car; // 1 or 0
            Vehicle::read(in);
            in >> h_car;
            in.ignore(1000, '\n');
            h_flag = bool(h_car);
        }
        else {
            bool ch = true;
            char value[5]; // Y or N
            cout << endl;
            cout << "Motorcycle information entry" << endl;
            Vehicle::read(in);
            cout << "Does the Motorcycle have a side car? (Y)es/(N)o: ";
            while (ch) {
                cin >> value;
                if (strlen(value) == 1) {
                    switch (value[0]) {
                    case 'Y':
                    case 'y':
                        ch = false;
                        h_flag = true;
                        break;
                    case 'N':
                    case 'n':
                        ch = false;
                        h_flag = false;
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
    ostream& Motorcycle::write(ostream& os) const
    {
        if (isEmpty()) { // Checking invalid empty state
            os << "Invalid Motorcycle Object" << endl;
        }else {
            if (isCsv()) {
                os << "M,";
            }else {
                os << "Vehicle type: Motorcycle" << std::endl;
            }
            Vehicle::write(os);
            if (isCsv()) {
                os << h_flag << std::endl;
            }else {
                if (h_flag) {
                    os << "With Sidecar" << std::endl;
                }
            }
        }
        return os;
        }
}
