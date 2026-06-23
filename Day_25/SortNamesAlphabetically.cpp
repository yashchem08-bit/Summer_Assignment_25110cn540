#include <iostream>
#include<string>
#include<vector>
using namespace std;
void Sort(string name)
{
    vector<char> vec;
    int i = 0;
    while(i<name.size()){
        char c = name[i];
        vec.push_back(c);
        i++;
    }
    int n = vec.size();
    
    for(int i = 0 ;i<n-1;i++){
        int minidx = i;
        for(int j = i+1 ;j<n;j++){
            if(vec[j] < vec[minidx]){
                minidx = j;
            }
            char temp = vec[minidx];
            vec[minidx] = vec[i];
            vec[i] = temp;
        }
    }
    for(char &val :vec){
        cout<<val<<" ";
    }
}
int main()
{
   string name ;
   getline(cin,name);
   Sort(name);

}