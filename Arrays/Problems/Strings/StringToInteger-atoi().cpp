/**
 * Implement _atoi() of C++ standard library
 * It returns integer value, if no valid conversion is found, it returns 0
 * e.g.  "25"       ->      25
 * e.g.  "251"      ->      251
 * e.g.  "ab"       ->      0
 * e.g.  "ab"       ->      0
 * e.g.  "25ab"     ->      25
 * e.g.  "a25b"     ->      0
 * e.g.  "43a25b"   ->      43
 * PS - only positive intergers are working, will implement for negative integers
 **/

#include <iostream>
using namespace std;

int atoi(const string &str)
{
    if (str.length() == 0)
        return 0;
    int mul = 1;
    int num = 0;

    for (auto c : str)
    {
        int n = c - '0';
        if (n < 0 || n > 9)
            return num;

        num = num * 10 + n;
    }

    return num;
}

int main()
{
    string s("125");
    cout << "Integer value of string '" << s << "': " << atoi(s) << endl;

    s = "223ab";
    cout << "Integer value of string '" << s << "': " << atoi(s) << endl;

    s = "ab23ab";
    cout << "Integer value of string '" << s << "': " << atoi(s) << endl;

    s = "-1";
    cout << "Integer value of string '" << s << "': " << atoi(s) << endl;

    return 0;
}