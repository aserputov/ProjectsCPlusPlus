//************************************************
// Name:                Anatoliy Serputov        *
// Student Number:      167389188                *
// Date:                1.21.2020                *
// email:               aserputov@myseneca.ca    *
//************************************************
/***********************************************************************
// OOP244 Workshop 2: Dynamic Memory & Function Overloading 
// File GiftMain.cpp
// Version 1.0
// Date	2020/01/05
// Author Michael Huang
// Description
// Tests Gift module and provides a set of TODOs to complete
// which the main focuses are dynamic memory allocation
//
// Revision History
// -----------------------------------------------------------
// Name            Date            Reason
// 
/////////////////////////////////////////////////////////////////
***********************************************************************/

#include <iostream>
#include "Gift.h"
#include "Gift.h" // Intentional
using namespace std;
using namespace sdds;

int main() {
  int numberOfGifts = 0; 
  int b;

  Gift* gift = nullptr;
  

  cout << "Enter number of Gifts to allocate: ";
  cin >> numberOfGifts;

  if (numberOfGifts < 1) return 1;


  gift= new Gift[0];
  
  
  for (int i = 0; i < numberOfGifts; ++i) {
    cout << "Gift #" << i + 1 << ": " << endl;
 
    gifting(gift[i].g_description);//this function stores description of gifts
	
    cin.ignore(2000,'\n'); //clearing buffer 
    
    gifting(gift[i].g_price);// this function stores price of gifts 
	
    cin.ignore(2000,'\n'); //clearing buffer 
    
    gifting(gift[i].g_units);//this function stores quantity of units 
	
    cin.ignore(2000, '\n');//clearing buffer 
    cout << endl;
  }

 
  for (int i = 0; i < numberOfGifts; i++)
  {
      cout << "Gift #" << i + 1 << ":" << endl;
      display(gift[i]);
      cout << endl;
      
    }
 
    delete[] gift;

  return 0;
}
