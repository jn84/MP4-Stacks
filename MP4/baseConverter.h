////////////////////////////////////////////////////////////////////////// 
//       Name: Jeremy Nims
// Assignment: MP4
//     Course: CPS 272, Wed 5:30
//////////////////////////////////////////////////////////////////////////

#pragma once

#include <cmath>
#include <iostream>
#include <stack>
#include <string>

using namespace std;

const string digits = "0123456789ABCDEF";

static class BaseConverter
{
public:
    static void runBaseConverter(
        ostream& os = cout, 
        istream& is = cin)
    {
        unsigned long long base = 0, number = 0;
        os << "Base Converter:" << endl;
        while (true)
        {
            os << "Enter a non-negative decimal number and base " <<
                  "(2 <= B <= 16)" << endl << "or 0 0 to terminate: ";
            is >> number >> base;
            if (is.fail())
            {
                is.clear();
                is.ignore(INT_MAX, '\n');
            }
            if (base == 0 && number == 0)
                break;
            os << '\t' << number << " in base " << base
                << " is " << multiBaseOutput(number, base) << "\n\n";
        }
        os << "Quitting Base Converter..." << endl << endl;
    }

private:
    static string multiBaseOutput(int num, const int b)
    {
        stack<char> baseStack;
        string digits = "0123456789ABCDEF", str = "";
        do
        {
            baseStack.push(digits[num % b]);
            num /= b;
        } while (num != 0);

        while (!baseStack.empty())
        {
            str += baseStack.top();
            baseStack.pop();
        }
        return str;
    }
};