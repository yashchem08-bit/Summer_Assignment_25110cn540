#include<iostream>
using namespace std;
void convert(string &str){
    for(int i = 0 ;i<str.size();i++){
        if(str[i] >= 'a' && str[i] <= 'z'){
            str[i] = str[i] -32;
        }
    }
    cout<<str<<endl;
}
int main(){
    string str;
    cout<<"Enter string :: ";
    getline(cin,str);
    convert(str);
}
