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
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "ReadWritable.h"

using namespace std;

namespace sdds{

    ReadWritable::ReadWritable(){
        flag = false;
    }
    bool ReadWritable::isCsv()const{
        return flag;
    }
    void ReadWritable::setCsv(bool value){
        this->flag = value;
        
    }
    
    ostream& operator<<(ostream& os, const ReadWritable& C){
    C.write(os);
    return os;
    }
    
    istream& operator>>(istream& in, ReadWritable& C){
    C.read(in);
    return in;
    }

}


