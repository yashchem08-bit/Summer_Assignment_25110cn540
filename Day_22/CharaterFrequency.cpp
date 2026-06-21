#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;
int main()
{
    unordered_map<string, int> m;
    string str;
    cout << "Enter string :: ";
    getline(cin, str);
    for(int i = 0 ;i<str.size();i++){
        string s;
        s = str[i];
        m[s]++;
    }
    for(auto &val : m){
        cout<<val.first<<" "<<val.second<<" "<<endl;
    }
}
