#pragma once

#include <string>
#include <stack>
#include <iostream>

using namespace std;

static class palindromeTester
{
public:
    static void runPalindromeTests(
        ostream& os = cout,
        istream& is = cin)
    {
        string input;
        while (true)
        {
            os << "Input a string: ";
            getline(is, input);
            if (input == "")
                break;
            os << input;
            if (isPalindrome(input))
                os << " matches the pattern." << endl << endl;
            else
                os << " does not match the pattern." << endl << endl;
        }
    }

private:
    static bool isPalindrome(const string& str)
    {
        stack<char> charStk;
        string::const_iterator strIter = str.begin();
        while (strIter != str.end() && *strIter != '#')
        {
            charStk.push(*strIter);
            strIter++;
        }
        if (strIter == str.end())
            return false;
        strIter++;
        while (strIter != str.end())
        {
            if (charStk.empty() || *strIter != charStk.top())
                return false;
            charStk.pop();
            strIter++;
        }
        if (!charStk.empty())
            return false;
        return true;
    }
};