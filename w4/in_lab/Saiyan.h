//==============================================
// Name:           Anatoliy Serputov
// Student Number: 167389188
// Email:          aserputov@myseneca.ca
// Section:        NCC
// Date:           04/02/2020
//==============================================
// Train.h
#ifndef sdds_Train_H
#define sdds_Train_H
#pragma once
using namespace std;

namespace sdds
{
	
	class Saiyan
	{
		char m_name[30];
		int m_dob;
		unsigned int m_power;
		bool m_super = false;

	public:
		Saiyan();
		Saiyan(const char m_name [],
			int m_dob,
			unsigned int m_power);
		bool isSuper() const;
		bool isValid()const;
		void setEmpty();
		void display() const;
		void set(const char* name, int dob, int power, bool super = false);
		bool hasLost(const Saiyan& other) const;
	};
	
}

#endif
