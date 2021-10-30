// Gift.cpp
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
//************************************************
// Name:                Anatoliy Serputov        *
// Student Number:      167389188                *
// Date:                1.21.2020                *
// email:               aserputov@myseneca.ca    *
//************************************************
#include <cctype>
#include <cstring>
#include "Gift.h"
using namespace std;

namespace sdds
{
    //struct Gift gift;
    void gifting(char* g_description) {
        cout << "Enter gift description: ";
        cin.width(16);
        
        cin >> g_description;
     
    }
    void gifting(double& g_price) {
        do {
            cout << "Enter gift price: ";
            cin >> g_price;
            if (g_price < 0 || g_price > MAX_PRICE)
            {
                cout << "Gift price must be between 0 and " << MAX_PRICE << endl;
            }
      
        } while (g_price < 0 || g_price > MAX_PRICE);
    }
    void gifting(int& g_units) {
        do {
            cout << "Enter gift units: ";
            cin >> g_units;
            if (g_units < 1)
            {
                cout << "Gift units must be at least 1" << endl;
            }
        } while (g_units < 1);
        
    };
    void display(const Gift& gift) {
        cout << "Gift Details:" << endl;
        cout << "Description: " << gift.g_description << endl;
        cout << "Price: " << gift.g_price << endl;
        cout << "Units: " << gift.g_units << endl;

    };
}


