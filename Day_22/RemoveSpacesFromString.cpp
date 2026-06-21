#include <iostream>
#include<algorithm>
#include <string>
using namespace std;
void RemoveSpaces(string &str)
{
    str.erase(remove(str.begin(),str.end(),' '),str.end());
}
int main()
{
    string str;
    cout << "Enter string :: ";
    getline(cin, str);
    RemoveSpaces(str);
    cout<<str;
}
