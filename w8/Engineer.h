//==============================================
// Name:           Anatoliy Serputov
// Student Number: 167389188
// Email:          aserputov@myseneca.ca
// Section:        NCC
// Date:           24/03/2020
//==============================================
#ifndef SDDS_ENGINEER_H__
#define SDDS_ENGINEER_H__
#include <iostream>
#include "Employee.h"
const int MIN_HOURS = 5;
const int MAX_LEVEL = 4;
using namespace std;

namespace sdds{
    class Engineer : public Employee {
        double m_esalary;
        int m_ewhours;
        int m_level;
    public:
        Engineer();
        Engineer(double esalary, int ewhours, int level);
        void setSalary(double);
        bool workHours();
        void bonus();
        ostream& display(ostream& os) const;
        virtual ~Engineer();
    };


}
#endif
