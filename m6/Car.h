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
#ifndef SDDS_CAR_H__
#define SDDS_CAR_H__
#include <iostream>
#include "Vehicle.h"

using namespace std;

namespace sdds{
    class Car : public Vehicle {
        bool flag;
        
    public:
        Car();
        Car(const Car& src) = delete;
        Car& operator=(const Car& src) = delete;
        Car(const char* plate, const char* model);
        istream& read(istream& in);
        ostream& write(ostream& os) const;
 
    };
        

}
#endif
