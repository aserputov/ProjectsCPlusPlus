#ifndef SDDS_CAR_H__
#define SDDS_CAR_H__
#include <iostream>
#include "Vehicle.h"

using namespace std;

namespace sdds{
    class Car : public Vehicle {
        bool flag;
        
    public:
        Car();
        Car(const char* plate, const char* model);
        Car(const Car& src) = delete;
        Car& operator=(const Car& src) = delete;
        istream& read(istream& in);
        ostream& write(ostream& os) const;
 
    };
        

}
#endif
