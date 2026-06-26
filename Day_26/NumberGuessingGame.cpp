#include <bits/stdc++.h>
#include <cstdlib>
#include <random>
#include <ctime>
using namespace std;
int main()
{
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> distr(1, 100);
    int Random_number = distr(gen);
    int attempts = 0;
    cout << " ======================================= " << endl;
    cout << "===  WELCOME TO NUMBER GUESSING GAME   ===" << endl;
    ;
    cout << " ========================================    " << endl;
    int user_attempt;
    do
    {
        cout << "Guess Number :: ";
        cin >> user_attempt;
        if (user_attempt > Random_number)
        {
            cout << "GUESS SOMETHING LOW:: ";
            attempts++;
        }
        if (user_attempt < Random_number)
        {
            cout << "GUESS SOMETHING HIGH:: ";
            attempts++;
        }
        if (user_attempt > 100 || user_attempt < 0)
        {
            cout << "INVALID INPUT" << endl;
        }
        if (user_attempt == Random_number)
        {
            cout << "congratulations you have guessed it in " << attempts << " attempts" << endl;
        }
        cout << endl;

    } while (user_attempt != Random_number);
    return 0;
}