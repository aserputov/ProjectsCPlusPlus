// Gift.cpp
//==============================================
// Name:           Anatoliy Serputov
// Student Number: 167389188
// Email:          aserputov@myseneca.ca
// Section:        NCC
// Date:           26/01/2020
//==============================================
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "Gift.h"


using namespace std;
namespace sdds
{
	struct Gift gift;
	void gifting(char* g_description) {
		cout << "Enter gift description: ";
		cin.width(16);
		cin >> g_description;
	}

	void gifting(double& g_price) {
		do {
			cout << "Enter gift price: ";
			cin >> g_price;
			if (g_price > MAX_PRICE || g_price < 0  ) {
				cout << "Gift price must be between 0 and " << MAX_PRICE << endl;
			}
		} while (g_price < 0 || g_price > MAX_PRICE);
	}

    void gifting(int& unit) {
        do {
            cout << "Enter gift units: ";
            cin >> unit;
            if (unit < 1) {
                cout << "Gift units must be at least 1" << endl;
            }
        } while (unit < 1);
    }

	void display(const Gift& gift) {
		cout << "Gift Details:" << endl;
		cout << "Description: " << gift.g_description << endl;
		cout << "Price: " << gift.g_price << endl;
		cout << "Units: " << gift.g_units << endl;
		if (gift.wrap == nullptr) {
			cout << "Unwrapped" << endl;
		}
		else {
			cout << "Wrap Layers: " << gift.wrap_layers << endl;
			for (int i = 0; i < gift.wrap_layers; i++) {
				cout << "Wrap #" << i + 1 << ": " << gift.wrap[i].pattern << endl;
			}
		}
	}
	bool wrap(Gift& wrapingift) {

		bool flag = true;
		if (wrapingift.wrap_layers > 0) {
			cout << "Gift is already wrapped!" << endl;
			flag= false;
		}
		else {
			cout << "Wrapping gifts..." << endl;
			while (wrapingift.wrap_layers < 1){
				cout << "Enter the number of wrapping layers for the Gift: ";
				cin >> wrapingift.wrap_layers;
				if (wrapingift.wrap_layers < 1) {
					cout << "Layers at minimum must be 1, try again." << endl;
				}
			}
			wrapingift.wrap = new Wrapping[wrapingift.wrap_layers];
			for (int i = 0; i < wrapingift.wrap_layers; i++) {
				char temp_pattern[MAX_LENGTH + 1];
				cout << "Enter wrapping pattern #" << i + 1 << ": ";
				cin >> temp_pattern;
				wrapingift.wrap[i].pattern = new char[strlen(temp_pattern) + 1];
				strcpy(wrapingift.wrap[i].pattern,temp_pattern);
			}
			flag= true;
		}
		return flag;
	}
	bool unwrap(Gift& unwrapgift) {
	bool flag = true;
		if (unwrapgift.wrap_layers <= 0) {
			cout << "Gift isn't wrapped! Can't unwrap." << endl;
			flag = false;
		} 
		else {
			cout << "Gift being unwrapped."<< endl;
			for (int i = 0; i < unwrapgift.wrap_layers; i++) {
				delete[] unwrapgift.wrap[i].pattern; //dealocatting dynamic memmory
				unwrapgift.wrap[i].pattern = nullptr;
			}
			unwrapgift.wrap_layers = 0;
			delete[] unwrapgift.wrap; //dealocatting dynamic memmory
			unwrapgift.wrap = nullptr;
			flag= true;
		}
		return flag;
	}
	void gifting(Gift& gift) {
		cout << "Preparing a gift..." << endl;
		gifting(gift.g_description);
		gifting(gift.g_price);
		gifting(gift.g_units);
		wrap(gift);
	}
	
}


