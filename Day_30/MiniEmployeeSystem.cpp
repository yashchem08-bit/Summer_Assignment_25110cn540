#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Employee {
private:
    int id;
    string name;
    string department;
    double salary;

public:
    Employee(int id, string name, string department, double salary) {
        this->id = id;
        this->name = name;
        this->department = department;
        this->salary = salary;
    }

    int getId() const { return id; }
    string getName() const { return name; }
    string getDepartment() const { return department; }
    double getSalary() const { return salary; }

    void setName(string newName) { name = newName; }
    void setDepartment(string newDept) { department = newDept; }
    void setSalary(double newSalary) { salary = newSalary; }

    void display() const {
        cout << "ID: " << id
             << " | Name: " << name
             << " | Department: " << department
             << " | Salary: " << salary << endl;
    }
};

class EmployeeManagementSystem {
private:
    vector<Employee> employees;

public:
    void addEmployee(int id, string name, string dept, double salary) {
        employees.push_back(Employee(id, name, dept, salary));
        cout << "Employee added successfully!\n";
    }

    void displayAll() {
        if (employees.empty()) {
            cout << "No employees found.\n";
            return;
        }
        for (const auto& emp : employees) {
            emp.display();
        }
    }

    void searchEmployee(int id) {
        for (const auto& emp : employees) {
            if (emp.getId() == id) {
                emp.display();
                return;
            }
        }
        cout << "Employee not found.\n";
    }

    void updateEmployee(int id, string newName, string newDept, double newSalary) {
        for (auto& emp : employees) {
            if (emp.getId() == id) {
                emp.setName(newName);
                emp.setDepartment(newDept);
                emp.setSalary(newSalary);
                cout << "Employee updated successfully!\n";
                return;
            }
        }
        cout << "Employee not found.\n";
    }

    void deleteEmployee(int id) {
        for (auto it = employees.begin(); it != employees.end(); ++it) {
            if (it->getId() == id) {
                employees.erase(it);
                cout << "Employee deleted successfully!\n";
                return;
            }
        }
        cout << "Employee not found.\n";
    }
};

int main() {
    EmployeeManagementSystem ems;
    int choice;

    do {
        cout << "\n--- Employee Management System ---\n";
        cout << "1. Add Employee\n";
        cout << "2. Display All Employees\n";
        cout << "3. Search Employee\n";
        cout << "4. Update Employee\n";
        cout << "5. Delete Employee\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        int id;
        string name, dept;
        double salary;

        switch (choice) {
            case 1:
                cout << "Enter ID, Name, Department, Salary: ";
                cin >> id >> name >> dept >> salary;
                ems.addEmployee(id, name, dept, salary);
                break;
            case 2:
                ems.displayAll();
                break;
            case 3:
                cout << "Enter Employee ID: ";
                cin >> id;
                ems.searchEmployee(id);
                break;
            case 4:
                cout << "Enter Employee ID to update: ";
                cin >> id;
                cout << "Enter new Name, Department, Salary: ";
                cin >> name >> dept >> salary;
                ems.updateEmployee(id, name, dept, salary);
                break;
            case 5:
                cout << "Enter Employee ID to delete: ";
                cin >> id;
                ems.deleteEmployee(id);
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
