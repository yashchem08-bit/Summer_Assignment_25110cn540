#include <bits/stdc++.h>
using namespace std;
int main()
{
    int users;
    cout << "HOW MANY USERS WANT TO CHECK THEIR ELIGIBILTY :: ";
    cin >> users;
    int i = 0;
    while (i <= users)
    {
        int age;
        cout << "Enter your age :: ";
        cin >> age;
        
        if (age >= 18)
        {
            cout << "YOU ARE ELIGIBLE FOR VOTING ";
        }
        else
        {
            cout << "YOU ARE NOT ELIGIBLE FOR VOTING";
        }
        cout<<endl;
        i++;
    }
}