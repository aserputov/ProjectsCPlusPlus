//==============================================
// Name:           Anatoliy Serputov
// Student Number: 167389188
// Email:          aserputov@myseneca.ca
// Section:        NCC
// Date:           11/02/2020
//==============================================
#ifndef sdds_engine_H
#define sdds_engine_H
using namespace std;

namespace sdds
{
    class Engine
     {
         double eng_size;
         char eng_type[31];
     public:
         Engine();
         Engine(const char* eng_type,double eng_size);
         double get() const;
         void display() const;
         void setEmpty();
     };
       
}

#endif
