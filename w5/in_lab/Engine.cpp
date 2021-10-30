//==============================================
// Name:           Anatoliy Serputov
// Student Number: 167389188
// Email:          aserputov@myseneca.ca
// Section:        NCC
// Date:           11/02/2020
//==============================================
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <iomanip>
#include "Engine.h"
#include "Engine.h"  // this is on purpose
using namespace std;

namespace sdds
{
    Engine::Engine(){
    setEmpty();
    };
    Engine::Engine(const char* type,double size){
        
        if (type != nullptr || size > 0) {
            strcpy(eng_type,type);
            eng_size = size;
        }else{
            setEmpty();
        }
        
    }

    void Engine::setEmpty(){
        eng_type[0] = '\0';
        eng_size = 0.00;
    }
    double Engine::get()const{
        return eng_size;
    }
    void Engine::display()const{
        cout << fixed << setprecision(2) << eng_size ;
        cout << " liters - " << eng_type << endl;
        
    }
    

}
