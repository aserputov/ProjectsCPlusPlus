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
#ifndef SDDS_MOTORCYCLE_H__
#define SDDS_MOTORCYCLE_H__
#include <iostream>
#include "Vehicle.h"

using namespace std;

namespace sdds{
    class Motorcycle : public Vehicle {
        bool h_flag;
    public:
        Motorcycle();
        Motorcycle(const Motorcycle& src) = delete;
        Motorcycle& operator=(const Motorcycle& src) = delete;
        Motorcycle(const char* l_plate, const char* m_model);
        istream& read(istream& in = cin);
        ostream& write(ostream& os = cout) const;
    };
        

}
#endif
