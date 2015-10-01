#pragma once

#include <cmath>
#include <iostream>

using namespace std;

static class BaseConverter
{
public:
    static void runBaseConverter(
        ostream& os = cout, 
        istream& is = cin)
    {
        unsigned long long base = 0, number = 0;
        while (true)
        {
            os << "Enter a non-negative decimal number and base " <<
                  "(2 <= B <= 16)" << endl << "or 0 0 to terminate: ";
            is >> number >> base;
            if (cin.fail())
            {
                cin.clear();
                cin.ignore(INT_MAX, '\n');
            }
            if (!base && !number)
                break;
        }

    }

private:
    static void multibaseOutput(
        int num, 
        int b, 
        ostream& os = cout, 
        istream& is = cin)
    {

    }

};