#include <iostream>
#include <cmath>
using namespace std;
class clac
{
public:
    float x;
    char op;
    float y;
    clac()
    {
    }
    clac(float x, char op, float y)
    {
        this->x = x;
        this->op = op;
        this->y = y;
    }
    void add(float a, char ch, float b)
    {
        float sum = a + b;
        cout << sum << endl;
    }
    void sub(float a, char ch, float b)
    {
        float sub = a - b;
        cout << sub << endl;
    }
    void multi(float a, char ch, float b)
    {
        float mul = a * b;
        cout << mul << endl;
    }
    void div(float a, char ch, float b)
    {
        if (b == 0)
        {
            cout << "CANNOT DIVIDE BY ZERO" << endl;
            return;
        }
        float divi = a / b;
        cout << divi << endl;
    }
    void mod(int a, char ch, int b)
    {
        if (b == 0)
        {
            cout << "CANNOT DIVIDE BY ZERO" << endl;
            return;
        }
        int mod = a % b;
        cout << mod << endl;
    }
    void Pow_fn(float a, char ch, float b)
    {
        if (a == 0)
        {
            cout << "INVALID INPUT" << endl;
            return;
        }
        float Pow;
        Pow = pow(a, b);
        cout << Pow << endl;
    }
    int fact(int a, char ch)
    {
        if (a == 0)
        {
            return 1;
        }
        if (a == 1)
        {
            return 1;
        }
        return a * fact(a - 1, ch);
    }
};
int main()
{
    clac c;
    int choice;
    do
    {
        cout << "--WELCOME TO C++ CALCULATOR---" << endl;
        cout << "1. ADDITION " << endl;
        cout << "2. SUBSTRACTION " << endl;
        cout << "3. MULTIPLICATION " << endl;
        cout << "4. DIVISION " << endl;
        cout << "5. MODULUS " << endl;
        cout << "6. POWER FUNCTION " << endl;
        cout << "7. FACTORIAL " << endl;
        cout << "8. --EXIT-- " << endl;
        cin >> choice;
        float a, b;
        char ch;
        switch (choice)
        {
        case 1:
        {
            cin.ignore();
            cout << "ENTER A ::";
            cin >> a;
            cout << "ENTER B :: ";
            cin >> b;
            c.add(a, '+', b);
            break;
        }
        case 2:
        {
            cin.ignore();
            cout << "ENTER A ::";
            cin >> a;
            cout << "ENTER B :: ";
            cin >> b;
            c.sub(a, '-', b);
            break;
        }
        case 3:
        {
            cin.ignore();
            cout << "ENTER A ::";
            cin >> a;
            cout << "ENTER B :: ";
            cin >> b;
            c.multi(a, '*', b);
            break;
        }
        case 4:
        {
            cin.ignore();
            cout << "ENTER A ::";
            cin >> a;
            cout << "ENTER B :: ";
            cin >> b;
            c.div(a, '/', b);
            break;
        }
        case 5:
        {
            cin.ignore();
            cout << "ENTER A ::";
            cin >> a;
            cout << "ENTER B :: ";
            cin >> b;
            c.mod(a, '%', b);
            break;
        }
        case 6:
        {
            cin.ignore();
            cout << "ENTER A ::";
            cin >> a;
            cout << "ENTER B :: ";
            cin >> b;
            c.Pow_fn(a, '^', b);
            break;
        }
        case 7:
        {
            cin.ignore();
            cout << "ENTER A ::";
            cin >> a;
            cout<<c.fact(a, '!')<<endl;
            
            break;
        }
        case 8:
        {
            cout << "--EXITING PROGRAM--";
            break;
        }
        default:
            cout << "---INVALID INPUT---" << endl;
            break;
        }
    } while (choice != 8);
}