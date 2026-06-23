#include <bits/stdc++.h>
#include<algorithm>
using namespace std;
void compress(string &str, vector<string> &ans)
{
    map<string, int> m;
    for (int i = 0; i < str.size(); i++)
    {
        string temp;
        temp = str[i];
        m[temp]++;
    }
    for (auto &val : m)
    {
        ans.push_back(val.first);
        ans.push_back(to_string(val.second));
    }
    for (auto &out : ans)
    {
        cout << out<<" ";
    }
}
int main()
{
    string str;
    getline(cin, str);
    vector<string> ans;
    compress(str, ans);
}