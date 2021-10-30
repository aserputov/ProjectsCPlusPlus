//==============================================
// Name:           Anatoliy Serputov
// Student Number: 167389188
// Email:          aserputov@myseneca.ca
// Section:        NCC
// Date:           03/03/2020
//==============================================
#ifndef sdds_BASKET_H
#define sdds_BASKET_H

using namespace std;

namespace sdds
{
    class Basket
     {
         char* m_fruitName;
         int m_qty;
         double m_price;
     public:
         Basket();
         Basket (const char* fruit_name, int qty, double price );
         Basket(const Basket& src );
         ~Basket();
         void setName(const char*);
         void setQty(int);
         void setPrice(double);
         bool isempty() const;
         bool addPrice(double);
         ostream& display(ostream& os) const;
         Basket& operator=(const Basket&);
         bool operator==(const Basket&);
         bool operator!=(const Basket&);
        
     };
    ostream& operator<<(ostream& os, const Basket& bsk);
       
}

#endif

   
 
    // Copy constructor is called here
  

//Magic numbers used instead of defined constants    -0.25
//Statically allocated char array did not account for nullbyte (+1)    -0.25
//Initializing member data values in header files isn't necessary
//Compilation Safeguard should follow the convention of NAMESPACE_HEADERFILE_H where the NAMESPACE and HEADERFILE's actual names used, eg SDDS_SAIYAN_H    -0.25
//set function doesn't set empty state, if any one of the params are invalid, some data could be set while others aren't. Generally speaking you should combine your if statements to comprise the conditions.    -0.5
//hasLost function doesn't power up both saiyans    -0.25
//diy doesn't really incorporate dynamic memory for the m_name and all_name isn't used anywhere beyond the set function    -1
//Reflection -10% reduction, the reflection is a bit unclear on the concepts of the constructor and destructor as to what they actually do rather the the syntax
