#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <stack>

using namespace std;

const string  openBraceChars = { "([{" },
             closeBraceChars = { ")]}" };

static class balancedBraceChecker 
{
public:
    static void runBraceChecker(
        ostream& os = cout,
        istream& is = cin)
    {
        if (checkBraces("test.txt"))
            cout << "yes" << endl;
        else
            cout << "no" << endl;
    }
private:
    static bool checkBraces(const string& fileName)
    {
        stack<char> braceStk;
        ifstream inFile(fileName);
        char temp;
        int index = 0;
        while (!inFile.eof())
        {
            temp = inFile.get();
            if (openBraceChars.find(temp) != string::npos)
            {
                braceStk.push(temp);
                continue;
            }
            index = closeBraceChars.find(temp);
            if (index != string::npos) // found closing brace
            {
                if (openBraceChars.find(braceStk.top()) != index)
                {
                    inFile.close();
                    return false;
                }
                braceStk.pop();
            }
        }
        inFile.close();
        return true;
    }
};
