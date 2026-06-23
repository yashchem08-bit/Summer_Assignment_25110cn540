#include <iostream>
#include <unordered_map>
#include <vector>
#include <limits.h>
using namespace std;
int main()
{
    string str;
    cout << "Enter string :: ";
    getline(cin, str);
    unordered_map<char, int> m;

    for (char c1 : str)
    {
        m[c1]++;
    }
    char result;
    int maxfreq = INT_MIN;

    for (auto &pr : m)
    {
        if(pr.second > maxfreq){
            maxfreq = pr.second;
            result = pr.first;
        }
       
    }
     cout << result << " occurs maximum times " << maxfreq << endl;
}