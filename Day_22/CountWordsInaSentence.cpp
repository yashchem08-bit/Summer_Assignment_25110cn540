#include <iostream>
#include <string>
using namespace std;

int main()
{
    string str;
    cout << "Enter string :: ";
    getline(cin, str);
    int words = 0;

    for (int i = 0; i < str.size(); i++)
    {

        while (str[words] != ' ')
        {
            words++;
        }
    }
    cout << words;
}
