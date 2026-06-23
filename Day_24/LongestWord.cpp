#include <bits/stdc++.h>
using namespace std;
void longestword(string &str)
{
    string longstr;
    vector<string> vec;
    int j = 0;
    while (j < str.size())
    {
        string c;
        while (str[j] != ' ' && j < str.size())
        {
            c.push_back(str[j]);
            j++;
        }
        if (!c.empty())
        {
            vec.push_back(c);
        }
        j++;
    }
    int max = INT_MIN;
    for (int i = 0; i < vec.size(); i++)
    {
        int n1;
        n1 = vec[i].size();
        if (max < n1)
        {
            max = n1;
            longstr = vec[i];
        }
    }

    cout << longstr << endl;
}
int main()
{
    string str = "hello there i am yash mishra presenting my program which finds out the longest string into the string";
    longestword(str);
}