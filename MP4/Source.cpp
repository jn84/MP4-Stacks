#include "palindromeTester.h"
#include "baseConverter.h"
#include "balancedBraceChecker.h"

using namespace std;

void main()
{
    palindromeTester::runPalindromeTests(cout, cin);
    BaseConverter::runBaseConverter(cout, cin);
    balancedBraceChecker::runBraceChecker(cout, cin);
}