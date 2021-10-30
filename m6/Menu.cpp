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
Write exactly which part of the code is given to you as help and
who gave it to you, or from what source you acquired it.

My friend Andrei Batomonkuev 119124196 helped me with array of pointers. I did it another before. He helped me with exactly
    ostream& Menu::display(ostream& os) const and helped to solve some mistakes in run function
-----------------------------------------------------------*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <iomanip>
#include "string.h"
#include "Menu.h"
using namespace std;

namespace sdds
{
    Menuitem::Menuitem() {
       m_str = nullptr;
    }
    Menuitem::Menuitem(const char* str) {
        if (str != nullptr){
            m_str = new char[strlen(str) + 1];
            strcpy(m_str, str);
        }else{
            m_str = nullptr;
        }
    }
    ostream& Menuitem::display(ostream& os) const{
        if (m_str != nullptr) {
            os << m_str << std::endl;
        }
        return os;
    }
    Menuitem::~Menuitem(){
        delete[] m_str;
        m_str = nullptr;
    }
   

  



    Menu::Menu(){
        set();
    }
    Menu::Menu(const char* title, int indentation) {
        if (title == nullptr){
            set();
        }else {
            set();
            addtitle(title);
            ind = indentation;
        }
    }
    void Menu::set(){
           m_title = nullptr;
           m_Nitems = 0;
           ind = 0;
           for (int i = 0; i < MAX_NO_OF_ITEMS; i++) {
               items[i] = nullptr;
           }
       }
    Menu::Menu(const Menu& tmp) {
        set();
        *this = tmp;
    }
    Menu& Menu::operator=(const Menu& tmpr){
        if (this != &tmpr) {
            ind = tmpr.ind;
            if (!tmpr.isEmpty()) {
                addtitle(tmpr.m_title);
                if (tmpr.m_Nitems != 0) {
                    for (int i = 0; i < m_Nitems; i++) {
                        delete items[i];
                        items[i] = nullptr;
                    }
                    for (int i = 0; i < tmpr.m_Nitems; i++) {
                        add(tmpr.items[i]->m_str);
                    }
                    m_Nitems = tmpr.m_Nitems;
                }
            }else{
                delete[] m_title;
                for (int i = 0; i < m_Nitems; i++) {
                    delete items[i];
                    items[i] = nullptr;
                }
                set();
            }
        }
        return *this;
    }

    bool Menu::isEmpty() const{
        if (m_title == nullptr){
            return true;
        }else{
            return false;
        }
    }

    Menu::operator bool() const{
        if (m_title != nullptr){
            return true;
        }else{
            return false;
        }
    }

    ostream& Menu::display(ostream& os) const{
        if (isEmpty()) {
            os << "Invalid Menu!" << endl;
        }else if (m_Nitems == 0){
           os << setw((4 * ind) + strlen(m_title)) << fixed << right << m_title << endl;
            os << "No Items to display!" << endl;
        }else {
            os << setw((4 * ind) + strlen(m_title)) << fixed << right << m_title << endl;
            for (int i = 0; i < m_Nitems; i++) {
                os << setw((4 * ind) + 1) << fixed << right << i + 1 << "- ";
                items[i]->display(os);
            }
            os << setw((4 * ind) + 2) << "> ";
        }
        return os;
    }

    void Menu::addtitle(const char* title){
        if (!isEmpty()) {
            delete[] m_title;
        }
        if (title == nullptr) {
            m_title = nullptr;
        }else {
           m_title = new char[strlen(title) + 1];
            strcpy(m_title, title);
        }
    }

    void Menu::operator=(const char* title){
        if (title != nullptr) {
           delete[] m_title;
            m_title = nullptr;
            addtitle(title);
        for (int i = 0; i < m_Nitems; i++) {
                delete items[i];
                items[i] = nullptr;
        }
           
            m_Nitems = 0;
        }else {
            set();
        }
    }

    void Menu::add(const char* item){
        if (item != nullptr && m_Nitems < MAX_NO_OF_ITEMS && m_title != nullptr) {
            items[m_Nitems] = new Menuitem(item);
            m_Nitems++;
        }else{
           delete[] m_title;
           for (int i = 0; i < m_Nitems; i++) {
                delete items[i];
                items[i] = nullptr;
            }
            set();
        }
    }


    int Menu::run(ostream& os , istream& in) const{
        int option = 0;
        bool ch = true;
        this->display();
        if (this->m_Nitems > 0) {
            while (ch) {
                cin >> option;
                if (cin.fail()) {
                    cin.clear();
                    cout << "Invalid Integer, try again: ";
                }else if (option > m_Nitems || option <= 0) {
                    cout << "Invalid selection, try again: ";
                }else {
                    ch = false;
                }
                cin.ignore(1000, '\n');
            } ;
        }
        return option;
    }

    Menu::operator int() const{
        return run();
    }

    Menu& Menu::operator<<(const char* item){
        add(item);
        return *this;
    }
    Menu::~Menu(){
           delete[] m_title;
           m_title = nullptr;
           for (int i = 0; i < m_Nitems; i++) {
               delete items[i];
               items[i] = nullptr;
           }
       }
   



}
