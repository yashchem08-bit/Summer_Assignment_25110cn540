#include <bits/stdc++.h>
using namespace std;
class BankAccount
{

public:
    vector<pair<string, string>> user_account;
    vector<pair<string, int>> user_pin;
    vector<pair<double, int>> pin_balance;
    BankAccount(vector<pair<string, string>> user_account, vector<pair<string, int>> user_pin, vector<pair<double, int>> pin_balance)
    {
        this->user_account = user_account;
        this->user_pin = user_pin;
        this->pin_balance = pin_balance;
    }
    BankAccount()
    {
    }
    void New_Account(string accnum, string name, int pin, double bal)
    {
        user_account.push_back({accnum, name});
        user_pin.push_back({name, pin});
        pin_balance.push_back({bal, pin});
        cout << "--CREATED NEW ACCOUNT SUCCEESFULLY--" << endl;
    }
    double mybalance(int pin) const
    {
        for (auto &val : pin_balance)
        {
            if (pin == val.second)
            {
                cout << "your balance is :: " << val.first << endl;
            }
        }
    }
    void deposit(string name, int pin, double amount)
    {
        bool pin_found = false;
        double bal;
        for (auto &val : user_pin)
        {
            if (name == val.first && pin == val.second)
            {
                pin_found = true;
            }
        }
        for (auto &out : pin_balance)
        {
            if (pin == out.second)
            {
                bal = out.first;
            }
        }
        if (pin_found == true)
        {
            if (amount > 0)
            {
                bal += amount;
                pin_balance.push_back({bal, pin});
            }
            else
            {
                cout << "INVALID INPUT";
            }
        }
        else
        {
            cout << "--PIN NOT FOUND--";
        }
    }
    void withdraw(string name, int pin, double amount)
    {
        bool pin_found = false;
        double bal;
        for (auto &val : user_pin)
        {
            if (name == val.first && pin == val.second)
            {
                pin_found = true;
            }
        }
        for (auto &out : pin_balance)
        {
            if (pin == out.second)
            {
                bal = out.first;
            }
        }
        if (pin_found == true)
        {
            if (amount > 0 && amount <= bal)
            {
                bal -= amount;
                pin_balance.push_back({bal, pin});
                cout << "YOUR BALANCE IS :: " << bal;
            }
            else
            {
                cout << "INVALID INPUT";
            }
        }
        else
        {
            cout << "--INVALID PIN--";
            return;
        }
    }
};
int main()
{
    BankAccount myacount;

    int choice;
    do
    {
        cout << "------------------------------" << endl;
        cout << "---BANK ACCOUNT SYSTEM----" << endl;
        cout << "1. CREATE NEW ACCOUNT :: " << endl;
        cout << "2. WITHDRAW MONEY :: " << endl;
        cout << "3. PRINT BALANCE :: " << endl;
        cout << "4. DEPOSIT MONEY :: " << endl;
        cout << "5. EXIT" << endl;
        cin >> choice;
        string accNum;
        string user_name;
        int pin;
        double balance;
        switch (choice)
        {
        case 1:
        {
            cin.ignore();
            cout << "Enter name :: ";
            getline(cin, user_name);
            cout << "Enter Account number :: ";
            getline(cin, accNum);
            cout << "--SET YOUR 4 DIGIT PIN-- ::";
            cin >> pin;
            cout << "Deposit some money :: ";
            cin >> balance;
            myacount.New_Account(accNum, user_name, pin, balance);
            break;
        }
        case 2:

        {
            cin.ignore();
            cout << "Enter your name ::";
            getline(cin, user_name);
            cout << "Enter pin :: ";
            cin >> pin;
            cout << "Enter amount to be withdrawn :: ";
            cin >> balance;
            myacount.withdraw(user_name, pin, balance);
            break;
        }
        case 3:
        {
            cout << "Enter your pin :: ";
            cin >> pin;
            myacount.mybalance(pin);
            break;
        }
        case 4:
        {
            cin.ignore();
            cout << "Enter your name :: ";
            getline(cin, user_name);
            cout << "Enter your pin :: ";
            cin >> pin;
            cout << "Enter amount to be deposit :: ";
            cin >> balance;
            myacount.deposit(user_name, pin, balance);
            break;
        }
        case 5:
        {
            cout << "--EXITING PROGRAM---";
            break;
        }
        default :{
            break;
        }
        }
    } while (choice != 5);

    return 0;
}
