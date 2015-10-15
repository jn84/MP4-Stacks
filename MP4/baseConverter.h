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
            if (base == 0 && number == 0)
                break;
            cout << '\t' << number << " in base " << base
                << " is " << multiBaseOutput(number, base) << "\n\n";
        }
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