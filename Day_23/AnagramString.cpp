#include <iostream>
#include <string>
#include <map>
using namespace std;
void Anagram(string &str1, string &str2)
{
    map<string, int> m2;
    map<string, int> m1;
    for (int i = 0; i < str1.size(); i++)
    {
        string s;
        s = str1[i];
        m1[s]++;
    }
    for (int i = 0; i < str2.size(); i++)
    {
        string s;
        s = str2[i];
        m2[s]++;
    }

    
    if (m1 == m2)
    {
        cout << "ANAGRAM STRING ";
    }else{
        cout<<"NOT ANAGRAM STRING ";
    }
}
int main()
{
    string str1 = "cinema";

    string str2 = "iceman";

    Anagram(str1, str2);
}
