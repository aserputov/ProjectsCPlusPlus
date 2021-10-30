//==============================================
// Name:           Anatoliy Serputov
// Student Number: 167389188
// Email:          aserputov@myseneca.ca
// Section:        NCC
// Date:           30/03/2020
//==============================================
#ifndef SDDS_NUMBERBOX_H__
#define SDDS_NUMBERBOX_H__
#include <iostream>
#include "string.h"
using namespace std;
const int MAX_SIZE = 16;
namespace sdds{
    template<typename T>
    class NumbersBox{
        char b_name[MAX_SIZE];
        int b_size;
        T* b_items;
    public:
       
        NumbersBox<T>(){
             b_name[0] = '\0';
             b_size = 0;
             b_items= nullptr;
        };
       
        NumbersBox<T>(int size,const char* name){
            if( name[0] == '\0' || size == 0){
                NumbersBox();
            }else{
                b_items=new T[size];
                strcpy(b_name,name);
                b_size = size;
            }
        };
 
        T& operator[](int i){
                return b_items[i];
        };
        
        NumbersBox<T>& operator*=(const NumbersBox<T>& other){
            if(b_size==other.b_size){
                for(int i = 0;i<b_size;i++){
                    b_items[i] = b_items[i] * other.b_items[i];
                }
            }
             return *this;
            
        };

        NumbersBox<T>& operator+=(T num){
            T* tmp_size =new T[b_size+1];
            
            for(int i=0; i<b_size;i++){
                tmp_size[i]= b_items[i];
            }
                tmp_size[b_size] = num;
                delete[] b_items;
                b_items = nullptr;
                b_items = tmp_size;
                b_size++;
            
            return *this;
        };
        ostream& display(ostream& os) const{
            if(b_name[0] == '\0' && b_size == 0 && b_items== nullptr){
                os<<"Empty Box"<<std::endl;
                
            }else{
                os<<"Box name: " << b_name << std::endl;
                for(int i=0;i<b_size;i++){
                    os<<b_items[i];
                    if(i<b_size-1){
                        os<<", ";
                    }
                }
                os << std::endl;
            }
            return os;
        };
        friend ostream& operator<<(ostream& os, NumbersBox<T>& box){
            box.display(os);
            return os;
        };
        ~NumbersBox<T>(){
            delete[] b_items;
        };
    };



}
#endif
