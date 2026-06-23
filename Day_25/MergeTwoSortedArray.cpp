#include<bits/stdc++.h>
using namespace std;
void Merge(vector<int> &v1 , vector<int> &v2){
    int n1 = v1.size();
    int n2 = v2.size();
    vector<int> merged;
    int i = 0 ,j = 0, k = 0;
    while(i < n1 && j < n2){
        if(v1[i] < v2[j]){
           merged.push_back(v1[i]);
           i++;
        }else{
            merged.push_back(v2[j]);
            j++;
        }
    }
    while(i < n1){
        merged.push_back(v1[i]);
        i++;
    }
    while(j < n2){
        merged.push_back(v2[j]);
        j++;
    }
    for(auto & val : merged){
        cout<<val<<" ";
    }
}
int main(){
    vector<int> v1 = {1,3,5,7};
    vector<int> v2 = {2,4,6,8};
    Merge(v1,v2);
}