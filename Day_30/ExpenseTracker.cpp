#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;

struct Expense {
    string category;
    double amount;
};

int main() {
    vector<Expense> expenses;
    map<string, double> categoryTotals; // category → total amount
    int choice;

    do {
        cout << "\n--- Expense Tracker ---\n";
        cout << "1. Add Expense\n";
        cout << "2. View All Expenses\n";
        cout << "3. View Total Expense\n";
        cout << "4. View Category-wise Totals\n";
        cout << "5. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 1) {
            Expense e;
            cout << "Enter category (Food, Travel, Shopping, etc.): ";
            cin.ignore();
            getline(cin, e.category);
            cout << "Enter amount: ";
            cin >> e.amount;

            expenses.push_back(e);
            categoryTotals[e.category] += e.amount; // accumulate by category

            cout << "Expense added successfully!\n";
        }
        else if (choice == 2) {
            if (expenses.empty()) {
                cout << "No expenses recorded.\n";
            } else {
                cout << "\n--- Expense List ---\n";
                for (int i = 0; i < expenses.size(); i++) {
                    cout << i+1 << ". " << expenses[i].category 
                         << " - Rs. " << expenses[i].amount << endl;
                }
            }
        }
        else if (choice == 3) {
            double total = 0;
            for (auto &e : expenses) {
                total += e.amount;
            }
            cout << "Total Expense: Rs. " << total << endl;
        }
        else if (choice == 4) {
            if (categoryTotals.empty()) {
                cout << "No expenses recorded.\n";
            } else {
                cout << "\n--- Category-wise Totals ---\n";
                for (auto &pair : categoryTotals) {
                    cout << pair.first << " : Rs. " << pair.second << endl;
                }
            }
        }
        else if (choice == 5) {
            cout << "Exiting...\n";
        }
        else {
            cout << "Invalid choice! Try again.\n";
        }
    } while (choice != 5);

    return 0;
}
