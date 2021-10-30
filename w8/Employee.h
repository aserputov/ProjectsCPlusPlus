//==============================================
// Name:           Anatoliy Serputov
// Student Number: 167389188
// Email:          aserputov@myseneca.ca
// Section:        NCC
// Date:           24/03/2020
//==============================================
#ifndef SDDS_DOCTOR_H__
#define SDDS_DOCTOR_H__
#include <iostream>
using namespace std;
namespace sdds
{
    class Employee
    {
    public:
        virtual void setSalary(double) = 0;
        virtual void bonus() = 0;
        virtual bool workHours() = 0;
        virtual ostream& display(std::ostream& os) const = 0;
        virtual ~Employee() {};
        
    };
}
#endif

