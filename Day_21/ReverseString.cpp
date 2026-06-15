#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
void Reverse(string &str , int i , int j){
    while(i<j){
        char temp = str[i];
        str[i] = str[j];
        str[j] = temp;
        i++;
        j--;
    }
    cout<<str;
    
}
int main(){
    string str;
    cout<<"Enter string :: ";
    getline(cin,str);
    int i , j;
    Reverse(str,0,str.size()-1);
    return 0;
}
