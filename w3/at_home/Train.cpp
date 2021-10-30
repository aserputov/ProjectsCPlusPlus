//==============================================

// Name:           Anatoliy Serputov

// Student Number: 167389188

// Email:          aserputov@myseneca.ca

// Section:        NCC

// Date:           26/01/2020

//==============================================
#define _CRT_SECURE_NO_WARNINGS
//Train.cpp
// Train.h
#include <iostream>
#include<cstring>
#include <iomanip>
#include "Train.h"
#include "Train.h" // intentional
using namespace std;


namespace sdds
{
	double Cargo::takeW() {
		return weight; // this function I create to take information of my weight from my private variables(I can get this infotmation just from member functions)
	}
	const char* Cargo::takeD()const {
		return description; // this function I create to take information about description of cargo from my private variables(I can get this infotmation just from member functions)
	}
	void Cargo::putw(double in) {
		weight = in;    // this function I create to INSERT information about weight of cargo from my private variables(I can't get access to my variables from another class)
	}
	void Cargo::putd(const char* des) {
		strcpy(description, des);   // this function I create to INSERT information about description of cargo from my private variables(I can't get access to my variables from another class)
	}
	void Train::setTrain(const char* p, int id2)
	{

		if (p == nullptr || p[0] == '\0' || id2 < 0) {
			name[0] = '\0';
			id = 0;

		}
		else {
			strcpy(name, p);
			id = id2;

		}
		cargo = nullptr;
	}
	

	bool Train::isEmpty() const // checking train if it's empty
	{
		if (id <= 0) {
			return true;
		}
		else
			return false;
	}

	void Train::display()const { // displaying summary information about my train(about weight and description of train)

		cout << "***Train Summary***" << endl;
		bool res = isEmpty();
		if (res == true) {
			cout << "This is an empty train." << endl;
		}
		else {
			cout << "Name: " << name << " ID: " << id << endl;
			if (cargo != nullptr) {
				cout << "Cargo: " << cargo->takeD()  << " Weight: " << setprecision (2) << fixed << cargo->takeW() << endl; // here I use at first fucntions which get my weight and description(and setprecision I find on "Stack Overflow" like an function to get two decimal after a dot.
			}
			else {
				cout << "No cargo on this train." << endl; // if my train is empty
			}
		}
	}



	void Train::loadCargo(Cargo c) // loading cargo on my train
	{
		cargo = new Cargo; // Allocating memory
		char* des = new char[MAX_DESC + 1];
		double* we = new double; // Allocating memory
		strcpy(des, c.takeD());
		cargo->putd(des);
		*we = c.takeW();
		cargo->putw(*we);
		delete [] des; // deallocating memory
		des = nullptr;
		delete we;  // deallocating memory
		we = nullptr;

	}

	void Train::unloadCargo()
	{
		delete cargo; // deallocating memory
		cargo = nullptr;
	}
	
	void Cargo::init(const char* des, double we) {

		if (we > MIN_WEIGHT && we < MAX_WEIGHT) { // checking my weight with maximum available and minimum
			weight = we;
		}
		else {
			weight = MIN_WEIGHT;
		}
		/*if (we < MIN_WEIGHT && we > MAX_WEIGHT) {
			weight = MIN_WEIGHT;
		}else {                                         Why these is not working ??I didn't find any answers
			weight = we;
		}*/
		
		if (strlen(des) < MAX_DESC) { // checking my desciption with maximum available

			strcpy(description, des);
		}

	}

	

	bool Train::swapCargo(Train& swap) {
		Cargo* swap_ptr = nullptr;
		swap_ptr = new Cargo;
		bool check; // variable to return my true or false of function
		if (cargo != nullptr && swap.cargo != nullptr) {
			Cargo* swap_ptr = nullptr;
			swap_ptr = new Cargo; // allocating memory
			swap_ptr = swap.cargo;
			swap.cargo = cargo;
			cargo = swap_ptr;
			check = true;
		}
		else {
			check = false;
		}
		delete swap_ptr;        //deallocating memory
		swap_ptr = nullptr;
		return check;  // retutrning my value value for bool varuable
	}



	bool Train::increaseCargo(double in) { // this function will increase my cargo
		bool* check = new bool;        // variable to return my true or false of function(using this to allocate memory )

		if (cargo->takeW() != in && cargo->takeW() != MAX_WEIGHT) {
			if (in <= MAX_WEIGHT && cargo != nullptr) {
				double* increase = new double; // allocating memory(for not getting memory leak )
				*increase = cargo->takeW() + in; // increasing my cargo
				cargo->putw(*increase);
				*check = true; // deallocating memory
				delete increase;
			}
			else {
				cargo->putw(MAX_WEIGHT);
				*check = true;
			}
		}
		else {
			*check = false;
		}
		return *check;
		delete check; // deallocating memory
	}



	bool Train::decreaseCargo(double in) {
		bool check;     // variable to return my true or false of function(without allocating memory  )
		if (cargo != nullptr) {
			if (cargo->takeW() != in && cargo->takeW() != MIN_WEIGHT) {
				if (in <= MIN_WEIGHT && cargo != nullptr) {
					double* decrease = new double; //allocating memory
					*decrease = cargo->takeW() - in; // just decreasing my cargo
					cargo->putw(*decrease);
					check = true;
					delete decrease; // deallocating my memmory
				}
				else {
					cargo->putw(MIN_WEIGHT); 
					check = true;
				}
			}
			else {
				check = false;
			}
		}
		else {
			check = false;
		}
		return check;
	}
			
	







}

