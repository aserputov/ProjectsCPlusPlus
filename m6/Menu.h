/* Citation and Sources...
Final Project Milestone ?
Module: Menu
Filename: Menu.h
Version 1.0
Author Anatoliy Serputov
Revision History
-----------------------------------------------------------
Date
2020/9/03
2020/15/03
Reason
Preliminary release
Debugged DMA
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------
OR
-----------------------------------------------------------
Write exactly which part of the code is given to you as help and
who gave it to you, or from what source you acquired it.

-----------------------------------------------------------*/
#pragma once
#include <iostream>
#include <string>
using namespace std;
const int MAX_NO_OF_ITEMS = 10;


namespace sdds
{
    class Menuitem{
        char* m_str ;
        
        Menuitem();
        Menuitem(const char* str);
        ostream& display(ostream& os) const;
        ~Menuitem();
        Menuitem(const Menuitem& tmp) = delete; //copy constr
        Menuitem& operator=(const Menuitem& tmp) = delete; // copy operator
       
        friend class Menu;
    };


    class Menu{
        int m_Nitems = 0;
        char* m_title = nullptr;
        Menuitem* items[MAX_NO_OF_ITEMS];
        int ind;
    public:
        Menu();
        Menu(const char*title, int indentation = 0);
        void set();
        Menu(const Menu& tmp); //copy constr
        Menu& operator=(const Menu& tmpr); // copy operator
        void operator=(const char* title);
        bool isEmpty() const;
        operator bool() const;
        ostream& display(ostream &os = cout) const;
        void addtitle(const char* title);
        void add(const char* item);
        Menu& operator<<(const char* item);
        operator int() const;
        int run(ostream& os = cout, istream& in = cin) const;
       
        ~Menu();
        
    };
     


    
}
