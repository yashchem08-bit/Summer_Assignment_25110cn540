#include <bits/stdc++.h>
using namespace std;
void common(string &str1, string &str2)
{
    int n1 = str1.size();
    int n2 = str2.size();
    set<char> s1(str1.begin(),str1.end());
    set<char> result;
    for(char c : str2){
        if(s1.find(c) != s1.end()){
            result.insert(c);
        }
    }
    for(auto &val : result){
        cout<<val;
    }

}
int main()
{
    string str1 = "yash";
    string str2 = "yash mishra";
    common(str1, str2);
}
