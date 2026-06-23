#include <bits/stdc++.h>
using namespace std;
void Remove_Duplicate(string &str)
{
    unordered_set<string> s;
    for(int i = 0;i<str.size();i++){
        string st;
        st = str[i];
        if(s.find(st) == s.end()){
            s.insert(st);
        }
    }
    for(auto &val :s){
        cout<<val;
    }
    cout<<endl;
}
int main()
{
    string str;
    getline(cin, str);
    Remove_Duplicate(str);
}