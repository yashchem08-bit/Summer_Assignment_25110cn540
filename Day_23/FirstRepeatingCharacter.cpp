#include<iostream>
#include<string>
#include<unordered_map>
using namespace std;
int main(){
    string str ;
    cout<<"Enter string :: ";
    getline(cin,str);
    unordered_map<string , int> m;
    for(int i = 0 ;i<str.size();i++){
        string s;
        s = str[i];
        m[s]++;
    }
    for(auto &val : m){
        if(val.second >= 2){
            cout<<val.first<<" "<<endl;
            break;
        }
    }
}