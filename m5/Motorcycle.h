#ifndef SDDS_MOTORCYCLE_H__
#define SDDS_MOTORCYCLE_H__
#include <iostream>
#include "Vehicle.h"

using namespace std;

namespace sdds{
    class Motorcycle : public Vehicle {
        bool h_flag;
    public:
        Motorcycle();
        Motorcycle(const Motorcycle& src) = delete;
        Motorcycle& operator=(const Motorcycle& src) = delete;
        istream& read(istream& in);
        ostream& write(ostream& os) const;
    };
        

}
#endif
