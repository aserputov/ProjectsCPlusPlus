//************************************************
// Name:                Anatoliy Serputov        *
// Student Number:      167389188                *
// Date:                1.21.2020                *
// email:               aserputov@myseneca.ca    *
//************************************************
#define _CRT_SECURE_NO_WARNINGS


//using namespace std;

#ifndef SDDS_GIFT_H
#define SDDS_GIFT_H
namespace sdds
{
    const int MAX_DESC = 15;
    const double MAX_PRICE = 999.99;
    struct Gift
    {
        char g_description[MAX_DESC];
        double g_price;
        int g_units;
    };

    void gifting(char*);
    void gifting(double&);
    void gifting(int&);
    void display(const Gift&);
}
// Gift.h
#endif
