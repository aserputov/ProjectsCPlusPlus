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

My friend in another section Kairat Orozobekov heped me,exactly with
ostream& Menu::display(ostream& os) const;
int run(ostream& os = cout, istream& in = cin) const;
-----------------------------------------------------------*/
#include "Menu.h"
#include <string.h>
#include <string>
using namespace std;

namespace sdds
{
    
    Menuitem::Menuitem(){
        m_str = nullptr;
    }
    Menuitem::Menuitem(const char* str){
        put(str);
    }
    ostream& Menuitem::display(ostream& os) const{
        if (m_str != nullptr)
            os << m_str << std::endl;
        return os;
    }
    void Menuitem::put(const char* str){
        delete[] m_str;
        if (str == nullptr || strlen(str) == 0){
            m_str= nullptr;
        }else{
            m_str = new char[strlen(str)+1];
            strcpy(m_str, str);
        }
    }
    Menuitem::~Menuitem(){
    delete [] m_str;
}


    Menu::Menu(){ //set empty states
         m_title = nullptr;
         ind = 0;
         
     }
    Menu::Menu(const char* title, int indentation){
        if (title == nullptr){
            Menu();
        }
        else{
            m_title = new char[strlen(title) + 1];
            strcpy(m_title, title);
            if (indentation == ' '){
                indentation = 0;
            }else{
                ind = indentation;
            }
        }
    }
    Menu::Menu(const Menu& tmp){
        delete[] m_title;
        if (!(tmp.isEmpty())){
            m_Nitems = tmp.m_Nitems;
            ind = tmp.ind;
            
            m_title = new char[strlen(tmp.m_title) + 1];
            strcpy(m_title, tmp.m_title);

            for (int i = 0; i < m_Nitems; i++){
                items[i].put(tmp.items[i].m_str);
                // items[i]=tmp.items[i];
            }
        }else{
             Menu();
        }
    }
    
    Menu& Menu::operator=(const char* title){
        addtitle(title);
        m_Nitems = 0;
        return *this;
    }

    Menu& Menu::operator=(const Menu& tmp){
        delete[] m_title;
        if (!(tmp.isEmpty())){
            m_Nitems = tmp.m_Nitems;
            ind = tmp.ind;
            
            m_title = new char[strlen(tmp.m_title) + 1];
            strcpy(m_title, tmp.m_title);
            
            for (int i = 0; i < m_Nitems; i++){
                items[i].put(tmp.items[i].m_str);
                //  items[i]=tmp.items[i];
            }
        }else{
            m_title = nullptr;
            m_Nitems = 0;
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
        if (isEmpty()){
            os << "Invalid Menu!" << std::endl;
        }else{
            for (int y = 0; y < ind; y++){
                os << "    ";
            }
            os << m_title << std::endl;
            if (m_Nitems == 0){
                os << "No Items to display!" << std::endl;
            }else {
                for (int i = 0; i < m_Nitems; i++){
                    for (int indent = 0; indent < ind; indent++){
                        os << "    ";
                    }
                    os << i + 1 << "-" << " ";
                    items[i].display(os);
//                  items[i]->display(os);
                }
                for (int end = 0; end < ind; end++){
                    os << "    ";
                }
                os << ">";
            }
        }
        return os;
    }

    
    void Menu::add(const char* item){
        if (m_Nitems < MAX_NO_OF_ITEMS){
            if (item != nullptr && strlen(item) > 0 && m_title != nullptr){
                items[m_Nitems].put(item);
//              itmems[m_Nitems]->init(item);
                m_Nitems++;
            }else{
                delete[] m_title;
                m_title = nullptr;
                m_Nitems = 0;
            }
        }
    }


    Menu& Menu::operator<<(const char* item){
        add(item);
        return *this;
    }



    int Menu::run(ostream& os, istream& in) const{
        int value = 0;
        display(os);
        bool result = true;
            while (result && m_Nitems > 0){
                os << " ";
                in >> value;
                if (in.fail()){
                    os << "Invalid Integer, try again:";
                    in.clear();
                }else if (value < 1 || value > m_Nitems){
                    os << "Invalid selection, try again:";
                }else{
                    result = false;
                }
                in.ignore(100000000, '\n');
            }
            return value;
    }

    void Menu::addtitle(const char* title){
        delete[] m_title;
        if (m_title == nullptr){
            Menu();
        }else{
            m_title = new char[strlen(title) + 1];
            strcpy(m_title, title);
        }
    }

    Menu::operator int() const{
        return run();
    }

    Menu::~Menu(){
        delete[] m_title;
    }
}

