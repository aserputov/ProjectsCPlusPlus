//==============================================
// Name:           Anatoliy Serputov
// Student Number: 167389188
// Email:          aserputov@myseneca.ca
// Section:        NCC
// Date:           24/03/2020
//==============================================
#ifndef SDDS_EMPLOYEE_H__
#define SDDS_EMPLOYEE_H__
#include <iostream>
#include "Employee.h"
const int MIN_W_HOURS = 6;
const int MAX_CHAR = 21;
using namespace std;

namespace sdds{
    class Doctor : public Employee {
        char m_type[MAX_CHAR];
        double m_salary;
        int m_whours;
        bool m_specialist;
    public:
        Doctor();
        Doctor(const char* type, double salary,int whours,bool speciallist=false);
        void setSalary(double);
        bool workHours();
        void bonus();
        ostream& display(ostream& os) const;
        ~Doctor();
    };
        

}
#endif
