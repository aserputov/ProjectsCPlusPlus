#define _CRT_SECURE_NO_WARNINGS
//Train.cpp
// Train.h
#include <iostream>
#include<cstring>
#include "Train.h"
#include "Train.h" // intentional
using namespace std;


namespace sdds
{

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
	;

	bool Train::isEmpty() const
	{
		if (id <= 0) {
			return true;
		}
		else
			return false;
	};

	void Train::display()const {

		cout << "***Train Summary***" << endl;
		bool res = isEmpty();
		if (res == true) {
			cout << "This is an empty train." << endl;
		}
		else {
			cout << "Name: " << name << " ID: " << id << endl;
			if (cargo != nullptr) {
				cout << "Cargo: " << cargo->description << " Weight: " << cargo->weight << endl;
			}
			else {
				cout << "No cargo on this train." << endl;
			}
		}
	};

	void Train::loadCargo(Cargo c)
	{
		cargo = new Cargo;
		strcpy(cargo->description, c.description);
		cargo->weight = c.weight;

	}
	;

	void Train::unloadCargo()
	{
		delete cargo;
		cargo = nullptr;
	};
}