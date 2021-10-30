//==============================================
// Name:           Anatoliy Serputov
// Student Number: 167389188
// Email:          aserputov@myseneca.ca
// Section:        NCC
// Date:           4/02/2020
//==============================================
#define _CRT_SECURE_NO_WARNINGS
//Train.cpp
// Train.h
#include <iostream>
#include<cstring>
#include <iomanip> 
#include "Saiyan.h"
#include "Saiyan.h"  // this is on purpose
using namespace std;

namespace sdds
{
	Saiyan::Saiyan()
	{
		setEmpty();
	}
	Saiyan::Saiyan(const char m_name [], int m_dob, unsigned int m_power)
	{
		if (m_dob > 2020) {
			m_dob = 0;
		};
		set( m_name, m_dob, m_power);

	}

	bool Saiyan::isSuper() const
	{
		if (m_super == false) {
			return false;
		}
		return true;
	}

	bool Saiyan::isValid() const
	{
		if (m_name[0] == '\0' || m_dob == 0 || m_power == 0 ) {
			return false;
		}
		else{
			return true;
		}
		

	}

	void Saiyan::setEmpty()
	{
		 m_name[0] = '\0';
		 m_dob = 0;
		 m_power = 0;
		 m_super = false;
	}

	void Saiyan::display() const
	{
		if (isValid() == true) {
			cout << m_name << endl;
			cout << "DOB: " << m_dob << " Power: " << m_power << endl;
			if (m_super == false) {
				cout << "Super Saiyan Ability: " << "Not super Saiyan." << endl << endl;
			}
			else if (m_super == true) {
				cout << "Super Saiyan Ability: " << "Super Saiyan." << endl << endl;
			}
		}else{
			cout << "Invalid Saiyan!" << endl;
		}
	
		
		
	}

	void Saiyan::set(const char* name, int dob, int power, bool super)
	{
		
		if ((name == nullptr) || strcmp(name, "") == 0) {
			strcpy(m_name, "");
		}
		else {
			strcpy(m_name, name);
		}
		if (dob < 1 ) {
			m_dob = 0;	
		}
		else {
			m_dob = dob;
		}
		if(power < 0){
		m_power=0;
		}
		else{
		m_power=power;
		}
		if(super==true){
		m_super = super;
		}
		else{
		m_super=false;
		}
			
		
		
	}

	bool Saiyan::hasLost(const Saiyan& other) const{
	bool check;
	if (m_power > other.m_power && isValid() && other.isValid()) 
		check = false;
	
	else 
		check = true;
	
	return check;
	}








}