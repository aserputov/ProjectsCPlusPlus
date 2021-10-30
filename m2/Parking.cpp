/* Citation and Sources...
Final Project Milestone ?
Module: Menu
Filename: Menu.h
Version 1.0
Author Anatoliy Serputov
Revision History
-----------------------------------------------------------
Date
2020/22/03
2020/22/03
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
#include "Parking.h"
#include <string.h>
#include <string>
using namespace std;

namespace sdds
{
    Parking::Parking(){
        f_name = nullptr;
        parkingMenu = nullptr;
        vehicleMenu = nullptr;
    }
    Parking::Parking(const char* name){
        if(name != nullptr && strlen(name) != 0){
            f_name = new char[strlen(name)+1];
            strcpy(f_name, name);
//            parkingMenu = nullptr;
//            vehicleMenu = nullptr;
            if(LoadDataFile()){
                parkingMenu = new Menu("Parking Menu, select an action:",0);
                parkingMenu->add("Park Vehicle");
                parkingMenu->add("Return Vehicle");
                parkingMenu->add("List Parked Vehicles");
                parkingMenu->add("Close Parking (End of day)");
                parkingMenu->add("Exit Program");

                vehicleMenu = new Menu("Select type of the vehicle:",1);
                vehicleMenu->add("Car");
                vehicleMenu->add("Motorcycle");
                vehicleMenu->add("Cancel");
            }else{
                cout<< "Error in data file"<< endl;
                parkingMenu = nullptr;
                vehicleMenu = nullptr;
                f_name = nullptr;
            }
        }else{
            cout<< "Error in data file"<< endl;
            parkingMenu = nullptr;
            vehicleMenu = nullptr;
            f_name = nullptr;
        }
    }
        
    bool Parking::isEmpty(){
        if(f_name == nullptr && parkingMenu == nullptr && vehicleMenu == nullptr){
            return true;
        }else
            return false;
    }
    void  Parking::ParkingStatus(){
        cout << "****** Seneca Valet Parking ******" << endl;
    }
    void Parking::ParkVehicle(){
        
        int option = vehicleMenu->run();
        if(option == 1){
            cout<<"Parking Car"<< endl;
        }else if(option == 2){
            cout<<"Parking Motorcycle"<<endl;
        }else if(option == 3){
            cout<<"Cancelled parking"<< endl;
        }
        
    }
    void Parking::ReturnVehicle(){
        cout << "Returning Vehicle" << endl;
    }
    void Parking::ListParkedVehicles(){
        cout << "Listing Parked Vehicles" << endl;
    }
    bool Parking::CloseParking(){
        cout << "Closing Parking" << endl;
        return true;
    }
    bool Parking::ExitParkingApp(){
        char answer[3];
        cout<<"This will terminate the program!" << endl;
        cout<< "Are you sure? (Y)es/(N)o: ";
        cin>> answer;
        while((answer[0] != 'Y' || answer[0] != 'y' || answer[0] != 'N' || answer[0] != 'n') && strlen(answer) != 1){
            cout<<"Invalid response, only (Y)es or (N)o are acceptable, retry: ";
            cin>>answer;

        }
        if((answer[0] == 'y' || answer[0] == 'Y') && strlen(answer) == 1){
            cout<< "Exiting program!" << endl;
            return true;
        }
        return false;
        
    }
    bool Parking::LoadDataFile(){
        if(isEmpty()==false){
            cout<<"loading data from "<< f_name << endl;
            return true;
        }
        return false;
    }
    void Parking::SaveDataFile(){
        if(isEmpty() == false){
                 cout<<"Saving data into "<< f_name << endl;
             }
    }
    int Parking::run(){
         int rv = 1;
         if(!isEmpty()){
             rv = 0;
             int option;
             bool check = true;
             while(check){
                 ParkingStatus();
                 option=parkingMenu->run();
                 if(option == 1){
                         ParkVehicle();
                 }else if(option == 2){
                         ReturnVehicle();
                 }else if(option == 3){
                         ListParkedVehicles();
                 }else if(option == 4){
                     if(CloseParking()){
                             check = false;
                     }
                 }else if(option == 5 ){
                     if(ExitParkingApp()){
                             check = false;
                     }
                 }
             }
         }
             return rv;
     }
   
    Parking::~Parking(){
        SaveDataFile();
        delete[] f_name;
        delete parkingMenu;
        delete vehicleMenu;
    }



}
