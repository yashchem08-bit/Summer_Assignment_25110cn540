#include<iostream>
#include<string>
using namespace std;
int main(){
    string str;
    cout<<"Enter string :: ";
    getline(cin,str);
    int count = 0;
    while(str[count] != '\0'){
        count++;
    }
    cout<<"size of string is :: "<<count;
}