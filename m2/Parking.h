/* Citation and Sources...
Final Project Milestone ?
Module: Menu
Filename: Menu.h
Version 1.0
Author Anatoliy Serputov
Revision History
-----------------------------------------------------------
Date
2020/9/03
2020/15/03
Reason
Preliminary release
Debugged DMA
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------
OR
-----------------------------------------------------------
Write exactly which part of the code is given to you as help and
who gave it to you, or from what source you acquired it.
-----------------------------------------------------------*/
#pragma once
#include <iostream>
#include <string>
#include "Menu.h"
using namespace std;
   

namespace sdds
{
    class Parking
    {
        char *f_name;
        Menu* parkingMenu;
        Menu* vehicleMenu;
        
        void loadDF();
        
        Parking(const Parking& tmp) = delete; //copy constr
        Parking& operator=(const Parking& tmp) = delete; //copy operators
        bool isEmpty();
        void ParkingStatus();
        void ParkVehicle();
        void ReturnVehicle();
        void ListParkedVehicles();
        bool CloseParking();
        bool ExitParkingApp();
        bool LoadDataFile();
        void SaveDataFile();
    public:
        Parking();
        Parking(const char* name);
        int run();
        ~Parking();
    };





    
    
    
    
    
    
    
    
}
