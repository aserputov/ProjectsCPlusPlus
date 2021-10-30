//==============================================
// Name:           Anatoliy Serputov
// Student Number: 167389188
// Email:          aserputov@myseneca.ca
// Section:        NCC
// Date:           24/03/2020
//==============================================
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include "Engineer.h"

using namespace std;

namespace  sdds {
    Engineer::Engineer(){
         m_esalary = 0;
         m_ewhours = 0;
         m_level = 0 ;
    }
    Engineer::Engineer(double esalary, int ewhours, int level){
        if(esalary >= 0 && ewhours >= 0 && level >= 0 ){
            m_ewhours = ewhours;
            m_level = level;
            setSalary(esalary);
        }else
            Engineer();
    }
    
    void Engineer::setSalary(double esalary){
        if(m_level == MAX_LEVEL){
            m_esalary = esalary + 3000;
        }else{
            m_esalary = esalary;
        }
    }
    bool Engineer::workHours(){
        if(m_ewhours == MIN_HOURS){
            return true;
        }
        return false;
    }
    void Engineer::bonus(){
        if(m_ewhours > MIN_HOURS && m_level == MAX_LEVEL){
            m_esalary = m_esalary + m_esalary*0.10;
        }else
            m_esalary = m_esalary + m_esalary*0.05;
    
    }
    ostream& Engineer::display(ostream& os) const{
        if(m_esalary>0 && m_ewhours > 0){
              os << "Engineer details" <<  std::endl;
              os << "level: " << m_level <<  std::endl;
              os << "Salary: " << fixed  << setprecision(2) << m_esalary <<  std::endl;
              os << "Working hours: "<< m_ewhours <<  std::endl;
          }else if(m_ewhours == 0 && m_level == 0 && m_esalary == 0){
              os<< "Engineer is not initiated yet" << std::endl;
          }
          return os;
    }
     Engineer::~Engineer(){
        
    }



}
