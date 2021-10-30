/* Citation and Sources...
Final Project Milestone ?
Module: Menu
Filename: Menu.h
Version 1.0
Author Anatoliy Serputov
Revision History
-----------------------------------------------------------
Date
2020/13/04
2020/13/04
Reason
Preliminary release
Debugged DMA
-----------------------------------------------------------
Write exactly which part of the code is given to you as help and
who gave it to you, or from what source you acquired it.
My friend Andrei Batomonkuev 119124196 helped me exactly with:
 void Parking::ParkVehicle(just some small parts(logic))
 bool Parking::LoadDataFile()
 and also he helped me while submiting with mistakes. -----------------------------------------------------------*/
#pragma once
#include <iostream>
#include <string>
#include "Menu.h"
#include "Vehicle.h"
using namespace std;
const int MAX_SPOTS = 100;
namespace sdds
{
    class Parking
    {
        int pspots_number; //empty spots
        int pvehicle_number;// vehicle number
        Vehicle* ps[MAX_SPOTS];
        char *f_name;
        Menu* parkingMenu;
        Menu* vehicleMenu;
        
        Parking(const Parking& tmp) = delete; //copy constr
        Parking& operator=(const Parking& tmp) = delete; //copy operators
        bool isEmpty();
        void ParkingStatus() const;
        void ListParkedVehicles() const;
        bool LoadDataFile();
        void SaveDataFile();
        void ParkVehicle();
        void ReturnVehicle();
        bool CloseParking();
        bool ExitParkingApp() const;
        
    public:
        Parking();
        Parking(const char* name, int noOfSpots);
        int run();
        ~Parking();
    };
        
}
        
        
       

