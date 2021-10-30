//==============================================
// Name:           Anatoliy Serputov
// Student Number: 167389188
// Email:          aserputov@myseneca.ca
// Section:        NCC
// Date:           03/03/2020
//==============================================

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <iomanip>
#include "Basket.h"
#include "Basket.h"  // this is on purpose
using namespace std;

namespace sdds
{

    Basket::Basket(){
        m_fruitName = nullptr;
        m_qty = 0 ;
        m_price = 0;
    
    }
    Basket::Basket (const char* fruit_name, int qty, double price ){
        if(fruit_name == nullptr || fruit_name[0] == '\0'){
            m_fruitName = nullptr;
            }else{
                setName(fruit_name);
                
            }
        setQty(qty);
        setPrice(price);
    }
    Basket::Basket (const Basket& src ){
         m_qty = src.m_qty;
         m_price = src.m_price;
        if (src.m_fruitName != nullptr) {
            this->setName(src.m_fruitName);
            
        }
        else {
            m_fruitName = nullptr;
        }
      
    }
  

    
    void Basket::setName(const char* name){
            this->m_fruitName = new char[strlen(name)+1];
            strcpy(this->m_fruitName,name);
        
    }
    void Basket::setQty(int qty){
        if(qty < 0){
            m_qty = 0 ;
        }
         this->m_qty = qty;
    }
    void Basket::setPrice(double price){
        if(price < 0){
            m_price = 0;
        }
                this->m_price = price;
           }

    bool Basket::isempty() const{
        
        if(m_price < 0 || m_qty < 0 || m_fruitName == nullptr){
            return true;
        }
        return false;
    }

    bool Basket::addPrice(double price){
        if(price > 0){
            m_price+=price;
            return true;
        }
        return false;
    }
    std::ostream& Basket::display(std::ostream& os) const {
        if(isempty()== true){
            os << "The Basket has not yet been filled"<< std::endl;;
        }else{
            os<<"Basket Details"<< std::endl;
            os<<"Name: " << this->m_fruitName << std::endl;
            os<<"Quantity: " << this->m_qty << std::endl;
            os<<"Price: " << fixed << setprecision(2)<< this->m_price << std::endl;
        }
            return os;
    }
    
    Basket& Basket::operator=(const Basket& src){
        m_qty = src.m_qty;
        m_price = src.m_price;
        delete[] m_fruitName;
            
            if (src.m_fruitName != nullptr) {
                this->setName(src.m_fruitName);
                
            }
            else {
                m_fruitName = nullptr;
            }
        
            return *this;
        }
    bool Basket::operator==(const Basket& src){
        if(m_qty == src.m_qty && m_price == src.m_price &&  strncmp(m_fruitName,src.m_fruitName,strlen(src.m_fruitName)) == 0){
            return true;
        }
        return false;
    }
    bool Basket::operator!=(const Basket& src){
    if(m_qty != src.m_qty && m_price != src.m_price && strncmp(m_fruitName,src.m_fruitName,strlen(src.m_fruitName)) !=0){
            return false;
        }
        return true;
    
    }

    ostream& operator<<(ostream& os, const Basket& bsk){
        bsk.display(os);
        return os;
    }
    
    Basket::~Basket(){
        delete[] m_fruitName;
        
    }


}






