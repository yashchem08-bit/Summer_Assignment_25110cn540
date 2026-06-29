#include <iostream>
#include <algorithm>
#include <cctype>
using namespace std;

class StringOS {
private:
    string str;

public:
    void setString(string s) {
        str = s;
        cout << "String set successfully!\n";
    }

    void displayString() {
        if (str.empty()) {
            cout << "String is empty!\n";
            return;
        }
        cout << "Current String: " << str << endl;
    }

    void concatenate(string s) {
        str += s;
        cout << "String concatenated successfully!\n";
    }

    void compare(string s) {
        if (str == s)
            cout << "Strings are equal.\n";
        else
            cout << "Strings are not equal.\n";
    }

    void length() {
        cout << "Length of string: " << str.length() << endl;
    }

    void reverseString() {
        reverse(str.begin(), str.end());
        cout << "String reversed successfully!\n";
    }
    void toUpperCase() {
        transform(str.begin(), str.end(), str.begin(), ::toupper);
        cout << "Converted to UPPERCASE.\n";
    }

    void toLowerCase() {
        transform(str.begin(), str.end(), str.begin(), ::tolower);
        cout << "Converted to lowercase.\n";
    }
};

int main() {
    StringOS sos;
    int choice;
    string input;

    do {
        cout << "\n--- String Operating System ---\n";
        cout << "1. Set String\n";
        cout << "2. Display String\n";
        cout << "3. Concatenate String\n";
        cout << "4. Compare String\n";
        cout << "5. Length of String\n";
        cout << "6. Reverse String\n";
        cout << "7. Convert to Uppercase\n";
        cout << "8 Convert to Lowercase\n";
        cout << "9. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter string: ";
                cin.ignore();
                getline(cin, input);
                sos.setString(input);
                break;
            case 2:
                sos.displayString();
                break;
            case 3:
                cout << "Enter string to concatenate: ";
                cin.ignore();
                getline(cin, input);
                sos.concatenate(input);
                break;
            case 4:
                cout << "Enter string to compare: ";
                cin.ignore();
                getline(cin, input);
                sos.compare(input);
                break;
            case 5:
                sos.length();
                break;
            case 6:
                sos.reverseString();
                break;
            case 7:
                sos.toUpperCase();
                break;
            case 8:
                sos.toLowerCase();
                break;
            case 9:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice!\n";
        }
    } while (choice != 10);

    return 0;
}
