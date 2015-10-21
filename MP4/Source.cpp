////////////////////////////////////////////////////////////////////////// 
//       Name: Jeremy Nims
// Assignment: MP4
//     Course: CPS 272, Wed 5:30
//////////////////////////////////////////////////////////////////////////

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