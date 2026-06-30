#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;

struct Expense {
    string category;
    double amount;
};

// Function to add an expense
void addExpense(vector<Expense> &expenses, map<string, double> &categoryTotals) {
    Expense e;
    cout << "Enter category (Food, Travel, Shopping, etc.): ";
    cin.ignore();
    getline(cin, e.category);
    cout << "Enter amount: ";
    cin >> e.amount;

    expenses.push_back(e);
    categoryTotals[e.category] += e.amount;

    cout << "Expense added successfully!\n";
}

// Function to view all expenses
void viewExpenses(const vector<Expense> &expenses) {
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

// Function to view total expense
void viewTotal(const vector<Expense> &expenses) {
    double total = 0;
    for (auto &e : expenses) {
        total += e.amount;
    }
    cout << "Total Expense: Rs. " << total << endl;
}

// Function to view category-wise totals
void viewCategoryTotals(const map<string, double> &categoryTotals) {
    if (categoryTotals.empty()) {
        cout << "No expenses recorded.\n";
    } else {
        cout << "\n--- Category-wise Totals ---\n";
        for (auto &pair : categoryTotals) {
            cout << pair.first << " : Rs. " << pair.second << endl;
        }
    }
}

int main() {
    vector<Expense> expenses;
    map<string, double> categoryTotals;
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

        switch (choice) {
            case 1: addExpense(expenses, categoryTotals); break;
            case 2: viewExpenses(expenses); break;
            case 3: viewTotal(expenses); break;
            case 4: viewCategoryTotals(categoryTotals); break;
            case 5: cout << "Exiting...\n"; break;
            default: cout << "Invalid choice! Try again.\n";
        }
    } while (choice != 5);

    return 0;
}
