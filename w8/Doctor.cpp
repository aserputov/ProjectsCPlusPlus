//==============================================
// Name:           Anatoliy Serputov
// Student Number: 167389188
// Email:          aserputov@myseneca.ca
// Section:        NCC
// Date:           24/03/2020
//==============================================
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <iomanip>
#include "Doctor.h"

using namespace std;

namespace  sdds {

    Doctor:: Doctor(){
        m_type[0] = '\0';
        m_whours = 0;
        m_specialist = false;
        m_salary = 0;
    }
    Doctor::Doctor(const char* type, double salary,int whours,bool speciallist){
        if(salary <= 0 && whours <= 0){
            Doctor();
        }else{
            strcpy(m_type, type);
            m_whours = whours;
            m_specialist = speciallist;
            setSalary(salary);
        }

    }
    void Doctor::setSalary(double salary){
        if(m_specialist == true){
            m_salary = salary + 2000;
        }else{
            m_salary = salary;
            
        }
    }
    bool Doctor::workHours(){
        if(m_whours == MIN_W_HOURS){
            return true;
        }
        return false;
    }
    void Doctor::bonus(){
        if(!workHours()){
            m_salary = m_salary + m_salary*0.10;
        }else
            m_salary = m_salary + m_salary*0.05;
    }

    ostream& Doctor::display(ostream& os) const{
        if(m_salary>0 && m_whours > 0){
            os << "Doctor details" <<  std::endl;
            os << "Doctor Type: " << m_type <<  std::endl;
            os << "Salary: " << fixed  << setprecision(2) << m_salary <<  std::endl;
            os << "Working Hours: "<< m_whours <<  std::endl;
        }else if( m_type[0] == '\0' && m_whours == 0 && m_specialist == false && m_salary == 0){
            os<< "Doctor is not initiated yet" << std::endl;
        }
        return os;
    }
    Doctor::~Doctor(){
        
    }
     // deletes only FooBase-part of Foo-object;

   


}
