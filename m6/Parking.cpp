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
 and also he helped me while submiting with mistakes.
 -----------------------------------------------------------*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "Menu.h"
#include <fstream>
#include <cstring>
#include "string.h"
#include<iomanip>
#include "Car.h"
#include "Motorcycle.h"
#include "Parking.h"



using namespace std;

namespace sdds
{
    Parking::Parking(){
        f_name = nullptr;
        parkingMenu = nullptr;
        vehicleMenu = nullptr;
        pspots_number = 0;
        pvehicle_number = 0;
    }
    
    Parking::Parking(const char* name,int noOfSpots) {
    if (name != nullptr && strlen(name) != 0 && (noOfSpots > 10 || noOfSpots < MAX_SPOTS)) {
        f_name = new char[strlen(name)+1];
        strcpy(f_name, name);
            for (int i = 0; i < MAX_SPOTS; i++) {
                ps[i] = nullptr;
            }
        pvehicle_number = 0;
        pspots_number = noOfSpots;
        if (LoadDataFile()) {
            parkingMenu = new Menu("Parking Menu, select an action:", 0);
            parkingMenu->add("Park Vehicle");
            parkingMenu->add("Return Vehicle");
            parkingMenu->add("List Parked Vehicles");
            parkingMenu->add("Close Parking (End of day)");
            parkingMenu->add("Exit Program");
            
            vehicleMenu = new Menu("Select type of the vehicle:", 1);
            vehicleMenu->add("Car");
            vehicleMenu->add("Motorcycle");
            vehicleMenu->add("Cancel");
        }else {
            cout << "Error in data file" << endl;
            f_name = nullptr;
            parkingMenu = nullptr;
            vehicleMenu = nullptr;
            pspots_number = 0;
            pvehicle_number = 0;
        }
    }else {
        cout << "Error in data file" << endl;
        f_name = nullptr;
        parkingMenu = nullptr;
        vehicleMenu = nullptr;
        pspots_number = 0;
        pvehicle_number = 0;
    }

    }

    bool Parking::isEmpty(){
        if(f_name == nullptr ){
            return true;
        }else
            return false;
    }
    void Parking::ParkingStatus() const{
            cout << "****** Seneca Valet Parking ******" << endl;
            cout << "*****  Available spots: "<< setw(4) << std::left<< pspots_number - pvehicle_number ;
            cout << " *****" << endl;
    }

    void Parking::SaveDataFile(){
        if (!isEmpty()) {
            std::ofstream fout(f_name);
            if (fout.is_open()) {
                for (int i = 0; i <= pvehicle_number; i++) {
                    if (ps[i] != nullptr) {
                        ps[i]->setCsv(true);
                        ps[i]->write(fout);
                    }
                }
                fout.close();
            }
        }
    }
    
    void Parking::ListParkedVehicles() const {
        cout << "*** List of parked vehicles ***" << endl;
        for (int i = 0; i <= pvehicle_number; i++) {
            if (ps[i] != nullptr) {
                ps[i]->write();
                cout << "-------------------------------" << endl;
            }
        }
    }
  
    bool Parking::LoadDataFile(){
    int ind;
    bool value = false;
    int check_numOfParked = pvehicle_number;
    if (!isEmpty()) {
        std::ifstream fin(f_name);
        if (!fin) {
            value = false;
        }else {
            if (fin.is_open()) {
                value = true;
                char answer;
                Vehicle* vehicle;
                while (check_numOfParked < pspots_number) {
                    answer = fin.get();
                    if (fin.fail()) {
                        fin.clear();
                        fin.ignore(1000, '\n');
                        check_numOfParked = pspots_number;
                    }else {
                        fin.ignore();
                        answer = char(toupper(answer));
                        if (answer == 'M' ) {
                            vehicle = new Motorcycle();
                        }else if(answer == 'C'){
                            vehicle = new Car();
                        }else{
                            vehicle = nullptr;
                        }
                        if (vehicle != nullptr) {
                            vehicle->setCsv(true);
                            vehicle->read(fin);
                            vehicle->setCsv(false);
                            if (cin.fail()) {
                               delete[] vehicle;
                               vehicle = nullptr;
                               value = false;
                            }else{
                                ind = vehicle->getParkingSpot() - 1;
                                ps[ind] = vehicle;
                                pvehicle_number++;
                                value = true;
                                }
                            }
                        }
                    }

                }
            }
        }
        return value;
    }

    void Parking::ParkVehicle()  {
        int value;
        Vehicle* vehicle;
        bool ch = true;
        int num_of_spots = 0;
        if (pspots_number == pvehicle_number) {
            cout << "Parking is full" << endl;
        }else {
            value = vehicleMenu->run();
            if(value == 1){
                vehicle = new Car();
                vehicle->setCsv(false);
                vehicle->read(cin);
                while (ch==true && num_of_spots < MAX_SPOTS) {
                    if (ps[num_of_spots] == nullptr) {
                        ps[num_of_spots] = vehicle;
                        ps[num_of_spots]->setParkingSpot(num_of_spots + 1);
                        pvehicle_number++;
                        ch = false;
                    }
                    num_of_spots++;
                }
                cout << endl;
                cout << "Parking Ticket" << endl;
                vehicle->write(cout);
                cout << endl;
            }else if(value==2){
                vehicle = new Motorcycle();
                vehicle->setCsv(false);
                vehicle->read(cin);
                while (ch && num_of_spots < MAX_SPOTS) {
                    if (ps[num_of_spots] == nullptr) {
                        ps[num_of_spots] = vehicle;
                        ps[num_of_spots]->setParkingSpot(num_of_spots + 1);
                        pvehicle_number++;
                        ch = false;
                    }
                    num_of_spots++;
                }
                cout << endl;
                cout << "Parking Ticket" << endl;
                vehicle->write(cout);
                cout << endl;
            }else if(value==3){
                cout << "Parking cancelled" << endl;
                }
            }
        }
    void Parking::ReturnVehicle(){
        char tempPlate[MAX_PLATE + 1]="";
        cout << "Return Vehicle" << endl;
        cout << "Enter Licence Plate Number: ";
        cin.getline(tempPlate, 60, '\n');
        while (strlen(tempPlate) > 8 || strlen(tempPlate) < 1) {
            cout << "Invalid Licence Plate, try again: ";
            cin.getline(tempPlate, 60, '\n');
        }
        for (int i = 0; tempPlate[i] != '\0'; i++) {
            tempPlate[i] = char(toupper(tempPlate[i]));
        }
        for (int i = 0; i < pspots_number; i++) {
            if (ps[i] != nullptr) {
                const char* l_plate = ps[i]->getLicensePlate();
                if (strcmp(tempPlate, l_plate) == 0) {
                    cout << endl;
                    cout << "Returning: " << endl;
                    ps[i]->write();
                    cout << endl;
                    delete ps[i];
                    ps[i] = nullptr;
                    i = pvehicle_number;
                    pvehicle_number--;
                }
            }else if (ps[i] == nullptr && i == (pspots_number - 1)) {
                cout << "License plate" << tempPlate << " Not found" << endl;
            }
        }

    }
    bool Parking::CloseParking(){
        bool value = false;
        bool ch = true;
        char option[5];
        if (pvehicle_number != 0) {
           cout << "This will Remove and tow all remaining vehicles from the parking!" << endl;
           cout << "Are you sure? (Y)es/(N)o: ";
            do{
               cin >> option;
               if (strlen(option) == 1) {
                   if(option[0] == 'Y'||option[0] == 'y'){
                       cout << "Closing Parking" << endl;
                       for (int i = 0; i < pspots_number; i++){
                           if (ps[i] != nullptr) {
                               cout << endl;
                               cout << "Towing request" << endl;
                               cout << "*********************" << endl;
                               ps[i]->write();
                               delete ps[i];
                               ps[i] = nullptr;
                               pvehicle_number--;
                           }
                       }
                       ch = false;
                       value = true;
                   }else if(option[0] == 'N' ||option[0] =='n'){
                       cout << "Aborted!" << endl;
                       ch = false;
                       value = false;
                   }else{
                       cout << "Invalid response, only (Y)es or (N)o are acceptable, retry: ";
                       ch = true;
                       cin.clear();
                   }
               }else{
                   cout << "Invalid response, only (Y)es or (N)o are acceptable, retry: ";
               }
               cin.ignore(1000, '\n');
            }while (ch);
        }else{
            cout << "Closing Parking" << endl;
            value = true;
        }
        return value;
    }
    bool Parking::ExitParkingApp() const {
        bool value;
        char option[5];
        bool ch = true;
        cout << "This will terminate the program!" << endl;
        cout << "Are you sure? (Y)es/(N)o: ";
        while (ch) {
            cin >> option;
            if (strlen(option) == 1) {
                if(option[0]=='Y' || option[0] == 'y'){
                    cout << "Exiting program!" << endl;
                    ch = false;
                    value = true;
                }else if(option[0]=='N' || option[0] == 'n'){
                    ch = false;
                    value = false;
                }else{
                    cout << "Invalid response, only (Y)es or (N)o are acceptable, retry: ";
                    ch = true;
                    cin.clear();
                }
            }else {
                cout << "Invalid response, only (Y)es or (N)o are acceptable, retry: ";
            }
            cin.ignore(1000, '\n');
        }
        return value;
    }
    int Parking::run(){
        int value = 1;
              if(!isEmpty()){
                  value = 0;
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
                  return value;
       
    }
    Parking::~Parking(){
        SaveDataFile();
        delete[] f_name;
        f_name = nullptr;
        delete parkingMenu;
        parkingMenu = nullptr;
        delete vehicleMenu;
        vehicleMenu = nullptr;
        for (int i = 0; i < pspots_number; i++){
            delete ps[i];
            ps[i] = nullptr;
        }
    }

    
}
