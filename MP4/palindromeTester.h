#pragma once

#include <string>
#include <stack>
#include <iostream>

using namespace std;

static class palindromeTester
{
public:
    static void runPalindromeTests()
    {
        string input;
        while (true)
        {
            cout << "Input a string: ";
            getline(cin, input);
            if (input == "")
                break;
            cout << input;
            if (isPalindrome(input))
                cout << " matches the pattern." << endl << endl;
            else
                cout << " does not match the pattern." << endl << endl;
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