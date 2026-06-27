#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Employee {
private:
    int id;
    string name;
    double salary;

public:
    Employee(int id, string name, double salary) {
        this->id = id;
        this->name = name;
        this->salary = salary;
    }

    int getId() const { return id; }
    string getName() const { return name; }
    double getSalary() const { return salary; }

    void setSalary(double newSalary) { salary = newSalary; }

    void display() const {
        cout << "ID: " << id
             << " | Name: " << name
             << " | Salary: " << salary << endl;
    }
};

class SalaryManagementSystem {
private:
    vector<Employee> employees;

public:
    void addEmployee(int id, string name, double salary) {
        employees.push_back(Employee(id, name, salary));
        cout << "Employee added successfully!\n";
    }

    void displayAll() {
        if (employees.empty()) {
            cout << "No salary records found.\n";
            return;
        }
        for (const auto& emp : employees) {
            emp.display();
        }
    }

    void searchSalary(int id) {
        for (const auto& emp : employees) {
            if (emp.getId() == id) {
                cout << "Salary record found:\n";
                emp.display();
                return;
            }
        }
        cout << "Employee not found.\n";
    }

    void updateSalary(int id, double newSalary) {
        for (auto& emp : employees) {
            if (emp.getId() == id) {
                emp.setSalary(newSalary);
                cout << "Salary updated successfully!\n";
                return;
            }
        }
        cout << "Employee not found.\n";
    }

    void calculateStats() {
        if (employees.empty()) {
            cout << "No salary records available.\n";
            return;
        }
        double total = 0;
        for (const auto& emp : employees) {
            total += emp.getSalary();
        }
        cout << "Total Salary: " << total << endl;
        cout << "Average Salary: " << total / employees.size() << endl;
    }
};

int main() {
    SalaryManagementSystem sms;
    int choice;

    do {
        cout << "\n--- Salary Management System ---\n";
        cout << "1. Add Employee\n";
        cout << "2. Display All Salaries\n";
        cout << "3. Search Salary by ID\n";
        cout << "4. Update Salary\n";
        cout << "5. Calculate Total & Average Salary\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        int id;
        string name;
        double salary;

        switch (choice) {
            case 1:
                cout << "Enter ID, Name, Salary: ";
                cin >> id >> name >> salary;
                sms.addEmployee(id, name, salary);
                break;
            case 2:
                sms.displayAll();
                break;
            case 3:
                cout << "Enter Employee ID: ";
                cin >> id;
                sms.searchSalary(id);
                break;
            case 4:
                cout << "Enter Employee ID to update: ";
                cin >> id;
                cout << "Enter new Salary: ";
                cin >> salary;
                sms.updateSalary(id, salary);
                break;
            case 5:
                sms.calculateStats();
                break;
            case 6:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice!\n";
        }
    } while (choice != 6);

    return 0;
}
