/* Citation and Sources...
Final Project Milestone ?
Module: ReadWritable
Filename: ReadWritable.h
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
#pragma once
#ifndef SDDS_READWRITABLE_H__
#define SDDS_READWRITABLE_H__
#include <iostream>
using namespace std;
   

namespace sdds
{
    class ReadWritable{
        bool flag ;
    public:
        ReadWritable();
        bool isCsv()const;
        void setCsv(bool value);
        virtual ostream& write(ostream& os) const = 0;
        virtual istream& read(istream& in) = 0;
        friend ostream& operator<<(ostream& os, const ReadWritable& C);
        friend istream& operator>>(istream& in, ReadWritable& C);
        virtual ~ReadWritable() {};
    };



}



#endif
