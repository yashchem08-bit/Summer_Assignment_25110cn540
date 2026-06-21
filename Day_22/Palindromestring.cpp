#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
void Reverse(string &str , int i , int j){
    while(i<j){
        int temp = str[i];
        str[i] = str[j];
        str[j] = temp;
        i++;
        j--;
    }
    
}
int main(){
    string str;
    string revstr1;
    revstr1 = str;
    cout<<"Enter string :: ";
    getline(cin,str);
    int i , j;
    Reverse(str,0,str.size()-1);
    if(revstr1 == str){
        cout<<"Palindrome string :: ";
    }else{
        cout<<"Not Plaindrome string :: ";
    }
}
