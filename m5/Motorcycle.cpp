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
#include "Motorcycle.h"
#include <cctype>
#include <cstring>
#include "string.h"
using namespace std;

namespace sdds{
    Motorcycle::Motorcycle(){
        h_flag= false;
    }
    istream& Motorcycle::read(istream& in){
        if (isCsv()){
                Vehicle::read(in);
                in >> h_flag;
               
        }else{
                cout<<std::endl;
                cout<<"Motorcycle information entry"<<endl;
                Vehicle::read(in);
                
                char answer[8];
                cout<<"Does the Motorcycle have a side car? (Y)es/(N)o: ";
                in.getline(answer, 10);
                while((answer[0] != 'Y' || answer[0] != 'y' || answer[0] != 'N' || answer[0] != 'n') && strlen(answer) != 1){
                cout<<"Invalid response, only (Y)es or (N)o are acceptable, retry: ";
                in>>answer;
                        }
                if((answer[0] == 'y' || answer[0] == 'Y') && strlen(answer) == 1){
                    h_flag = true;
                }else
                    h_flag = false;
            }
        return in;
    }
    ostream& Motorcycle::write(ostream& os) const{
        if (Vehicle::isEmpty()){
            os<<"Invalid Motorcycle Object"<<std::endl;
        }else{
            if (this->isCsv()){
                os<<"M,";
                 Vehicle::write(os);
                 os<< h_flag;
                 os << std::endl;
            }else{
                os << "Vehicle type: Motorcycle" << std::endl;
                Vehicle::write(os);
                if(h_flag){
                    os<<"With Sidecar"<<std::endl;
                }
            }
            
        }
        return os;
    }
}
