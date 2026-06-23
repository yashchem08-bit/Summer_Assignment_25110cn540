#include<iostream>
#include<string>
#include<map>
using namespace std;
int main(){
    string str ;
    cout<<"Enter string :: ";
    getline(cin,str);
    map<string , int> m;
    for(int i = 0 ;i<str.size();i++){
        string s;
        s = str[i];
        m[s]++;
    }
    for(auto &val : m){
        if(val.second == 1){
            cout<<val.first<<" "<<endl;
            break;
        }
    }
}