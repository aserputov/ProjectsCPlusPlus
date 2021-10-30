//==============================================

// Name:           Anatoliy Serputov

// Student Number: 167389188

// Email:          aserputov@myseneca.ca

// Section:        NCC

// Date:           26/01/2020

//==============================================
// Train.h
#ifndef sdds_Train_H
#define sdds_Train_H
#pragma once
using namespace std;
namespace sdds
{
	const double MAX_WEIGHT = 700.555;
	const double MIN_WEIGHT = 40.444;
	const int MAX_NAME = 30;
	const int MAX_DESC = 20; 
	class Cargo
	{   
        char description[MAX_DESC]; // private variable
		double weight;  // private variable
        
	public:
        void init(const char*, double);
        double takeW();
        const char *takeD()const;
        void putw(double);
        void putd(const char*);
		
	};
	class Train
	{
		char name[MAX_NAME];
		int id;
		struct Cargo* cargo;
	public:
		void setTrain(const char*, int);
		bool isEmpty() const;
		void display() const;
		void loadCargo(Cargo);
		void unloadCargo();
		bool swapCargo(Train&);
		bool increaseCargo(double);
		bool decreaseCargo(double);
	};

	
}

#endif
