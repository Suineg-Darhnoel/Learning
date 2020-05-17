#include <iostream>
#include <string>
using namespace std;

int main()
{
    /* string mystring; */
    /* cin >> mystring; */
    /* cout << mystring.substr(2); */

    /* string literal */
    string s1 ("xyz"), s2 ("abc");

    cout << (s1 + "something") << '\n';
    cout << "string::npos => " << string::npos << '\n';
    // npos is the return value of find used to indicate no matches.
    cout << s1.find(">") << '\n';

    return 0;
}
