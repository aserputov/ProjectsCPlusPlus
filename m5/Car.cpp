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
    istream& Car::read(istream& in){
    if (isCsv()){
        int car_wash_flag; // 1 or 0
        Vehicle::read(in);
        in >> car_wash_flag;
        in.ignore(1000, '\n');
        flag = bool(car_wash_flag);
    }else{
            cout<< std::endl;
            cout<<"Car information entry"<< std::endl;
            Vehicle::read(in);
            
                cout<<"Carwash while parked? (Y)es/(N)o: ";
                        char answer[8];
                      in.ignore(1);
                      in.getline(answer, 10);

                    while((answer[0] != 'Y' || answer[0] != 'y' || answer[0] != 'N' || answer[0] != 'n') && strlen(answer) != 1){
                        cout<<"Invalid response, only (Y)es or (N)o are acceptable, retry: ";
                        in >> answer;

                    }
                if((answer[0] == 'y' || answer[0] == 'Y') && strlen(answer) == 1){
                  
                   flag = true;
               }else
                   flag = false;
        }

        return in;
    }
    ostream& Car::write(ostream& os) const{
        if (Vehicle::isEmpty()){
            os<<"Invalid Car Object"<<std::endl;
        }else{
            if (this->isCsv()){
                os<<"C,";
                 Vehicle::write(os);
                 os<< flag;
                os << std::endl;
            }else{
                os << "Vehicle type: Car" << std::endl;
                Vehicle::write(os);
                if(flag){
                    os<<"With Carwash"<<std::endl;
                }else{
                    os<<"Without Carwash"<<std::endl;
                }
            }
            
        }
        return os;
        
    }


}
