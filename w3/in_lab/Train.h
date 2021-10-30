// Train.h
#ifndef sdds_Train_H
#define sdds_Train_H
#pragma once
using namespace std;
namespace sdds
{
	const int MAX_NAME = 30;
	const int MAX_DESC = 20;
	struct Cargo
	{
		char description[MAX_DESC];
		double weight; 
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
	};

	
}

#endif