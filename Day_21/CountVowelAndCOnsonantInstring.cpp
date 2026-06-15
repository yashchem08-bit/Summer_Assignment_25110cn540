#include <iostream>
#include <string>
using namespace std;
void count(string &str)
{
    int vowelcount = 0, consocount = 0;
    int i = 0;
    while (str[i] != '\0')
    {
        if (str[i] == 'a' || str[i] == 'e' || str[i] == 'i' || str[i] == 'o' || str[i] == 'u')
        {
            vowelcount++;
        }
        else
        {
            consocount++;
        }
        i++;
    }
    cout << "vowel count is :: " << vowelcount << endl
         << " consonant count is :: " << consocount << endl;
}
int main()
{
    string str;
    cout << "Enter string :: ";
    getline(cin,str);
    count(str);
}