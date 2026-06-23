#include <iostream>
#include <string>
#include <vector>
#include<algorithm>
using namespace std;
void Sort(string name)
{
    vector<string> vec;
    int j = 0;
    while (j < name.size())
    {
        string c;
        while (name[j] != ' ' && j <name.size())
        {
            c.push_back(name[j]);
            j++;
        }
        if(!c.empty()){
            vec.push_back(c);
        }
        j++;
    }
    int n = vec.size();
    for (int i = 0; i < n - 1; i++)
    {
        for(int j = 0;j < n-i-1;j++){
            if(vec[j].length() > vec[j+1].length()){
                string temp = vec[j];
                vec[j] = vec[j+1];
                vec[j+1] = temp;
            }
        }
    }
    for (auto &val :  vec)
    {
        cout << val;
        cout<<endl;
    }
}
int main()
{
    string name = "hello my name is yash";
    Sort(name);
}

