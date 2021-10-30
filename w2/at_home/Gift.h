#pragma once
// Gift.h
//==============================================
// Name:           Anatoliy Serputov
// Student Number: 167389188
// Email:          aserputov@myseneca.ca
// Section:        NCC
// Date:           26/01/2020
//==============================================
#ifndef sdds_Gift_H
#define sdds_Gift_H

namespace sdds
{
	const int MAX_DESC = 15; 
	const double MAX_PRICE = 999.99;
	const int MAX_LENGTH = 20;
	struct Gift
	{
		char g_description[MAX_DESC + 1];
		double g_price;
		int g_units;
		struct Wrapping *wrap;
		int wrap_layers;
	};
	struct Wrapping
	{
		char* pattern;
	};
	void gifting(char*);
	void gifting(double&);
	void gifting(int&);
	void gifting(Gift&);
	void display(const Gift&);
	bool wrap(Gift&);
	bool unwrap(Gift&);


}


#endif // !sddds_Gift_H


