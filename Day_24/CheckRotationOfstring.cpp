#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
void Reverse(string &str, int i, int j)
{
    while (i < j)
    {
        swap(str[i], str[j]);
        i++;
        j--;
    }
}
int main()
{
    string str = "leetcode";
    string str1 = "deleetco";
    int n = str.size();
    int k = 2;
    int i, j;
    Reverse(str, 0, n - k - 1);
    Reverse(str, n - k, n - 1);
    Reverse(str, 0, n - 1);
    if(str == str1){
        cout<<"Rotated string :: ";
    }else{
        cout<<"Not Rotated string :: ";
    }
}
