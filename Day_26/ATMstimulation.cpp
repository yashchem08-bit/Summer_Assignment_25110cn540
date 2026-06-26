#include <bits/stdc++.h>
using namespace std;
void withdraw_money_user(int &pin, unordered_map<int, double> &m, vector<pair<string, int>> &v);
void save_money(int pin, unordered_map<int, double> &m, vector<pair<string, int>> &v);
void existing_user(vector<pair<string, int>> &v, unordered_map<int, double> &m)
{
    cout << "Enter your details here :: " << endl;
    string st;
    int pin;
    cin.ignore();
    cout << "Enter your name :: ";
    getline(cin, st);
    cout << "Enter PIN :: ";
    cin >> pin;

    for (auto &val : v)
    {
        if (val.first == st && val.second == pin)
        {
            cout << "WELCOME :: " << val.first << endl;
        }
    }
    cout << ":: WANT TO WITHDRAW YOUR MONEY OR TO SAVE THEM INTO YOUR ACCOUNT :: " << endl;
    cout << "PRESS 1 IF WITHDRAW  || PRESS 0 IF SAVE" << endl;
    int c;
    cin >> c;
    if (c == 1)
    {
        withdraw_money_user(pin, m, v);
    }
    else if (c == 0)
    {
        save_money(pin, m, v);
    }
    else
    {
        cout << "---INVALID INPUT----";
    }
}
void Main_menu(vector<pair<string, int>> &v, unordered_map<int, double> &m)
{
    existing_user(v, m);
}
void withdraw_money_user(int &pin, unordered_map<int, double> &m, vector<pair<string, int>> &v)
{
    double money;
    if (m.find(pin) != m.end())
    {
        cout << "Your balance is :: " << m[pin] << endl;
        cout << "Enter amount to withdraw: ";
        cin >> money;
        if (money <= m[pin])
        {
            m[pin] -= money;
            cout << "Now your balance is :: " << m[pin] << endl;
            cout << "Rupee's : " << m[pin] << " Debited from your Bank~--" << endl;
        }
        else
        {
            cout << "Insufficient balance!" << endl;
        }
    }
    else
    {
        cout << "PIN not found!" << endl;
    }
    cout << "WANT TO GO MAIN MENU AGAIN :: " << endl;
    int c;
    cout << "enter 1 if yes || enter 0 to exit program :: ";
    cin >> c;
    if (c == 1)
    {
        Main_menu(v, m);
    }
    else if (c == 0)
    {
        cout << "-- EXITING PROGRAM --" << endl;
    }
    else
    {
        cout << "--INVAID INPUT --" << endl;
    }
}

void save_money(int pin, unordered_map<int, double> &m, vector<pair<string, int>> &v)
{
    double money;
    cout << "Enter money to be saved: ";
    cin >> money;
    m[pin] += money;
    cout << "Money saved successfully. Current balance: " << m[pin] << endl;
    cout << "WANT TO WITHDRAW MONEY IF YES PRESS 1 || PRESS 0 TO EXIT :: ";
    int c;
    cin >> c;
    if (c == 1)
    {
        withdraw_money_user(pin, m, v);
    }
    else if (c == 0)
    {
        cout << "MONEY SAVED SUCCESSFULY ";
    }
}

int new_user(vector<pair<string, int>> &v, unordered_map<int, double> &m)
{
    cout << "Enter your details here :: " << endl;
    string str;
    int PIN;
    long long phone_num;
    cin.ignore();
    cout << "Enter your name :: ";
    getline(cin, str);
    cout << "Enter your phone number :: ";
    cin >> phone_num;
    cout << "Now set your PIN of 4 digits :: ";
    cin >> PIN;
    cout << endl;
    v.push_back({str, PIN});
    m[PIN] = 0;
    cout << "WANT TO SAVE YOUR MONEY" << endl;
    int conf;
    cout << "enter 1 if yes || enter 0 if want to exit ";
    cin >> conf;
    if (conf == 1)
    {
        existing_user(v, m);
    }
    else
    {
        cout << "---EXITING PROGRAM---";
        return 1;
    }
}

int main()
{
    cout << "========================" << endl;
    cout << "== WELCOME TO C++ ATM ==" << endl;
    cout << "=========================";
    cout << endl
         << endl;
    vector<pair<string, int>> v;
    double money;
    unordered_map<int, double> m;
    int con;
    cout << "Enter 1 if you are existing user || Enter 0 for new entry :: ";
    cin >> con;
    if (con == 1)
    {
        existing_user(v, m);
    }
    else if (con == 0)
    {
        new_user(v, m);
    }
    else
    {
        cout << "--INVALID INPUT--";
    }
}
