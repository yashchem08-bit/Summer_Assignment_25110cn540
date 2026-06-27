#include <iostream>
#include <string>
using namespace std;
class Student {
private:
    int rollNumber;
    string name;
    float gpa;

public:
 
    Student() : rollNumber(0), name(""), gpa(0.0) {}
    Student(int roll, string rName, float rGpa) : rollNumber(roll), name(rName), gpa(rGpa) {}

    int getRollNumber() const { return rollNumber; }
    string getName() const { return name; }
    float getGpa() const { return gpa; }

    void printDetails() const {
        cout << "Roll No: " << rollNumber 
             << " | Name: " << name 
             << " | GPA: " << gpa << "\n";
    }
};


class GradeBook {
private:
    static const int MAX_STUDENTS = 100;
    Student records[MAX_STUDENTS];
    int studentCount;

public:

    GradeBook() : studentCount(0) {}

    void addRecord() {
        if (studentCount >= MAX_STUDENTS) {
            cout << "\nError: System database storage is full!\n";
            return;
        }

        int roll;
        string fullName;
        float gpaValue;

        cout << "\nEnter Roll Number: ";
        cin >> roll;
        cin.ignore(); 

        cout << "Enter Full Name: ";
        getline(cin, fullName);

        cout << "Enter GPA: ";
        cin >> gpaValue;

        records[studentCount] = Student(roll, fullName, gpaValue);
        studentCount++;
        cout << "\nRecord added successfully!\n";
    }

    void displayRecords() const {
        if (studentCount == 0) {
            cout << "\nNo records found. The database is empty.\n";
            return;
        }

        cout << "\n--- All Student Records ---\n";
        for (int i = 0; i < studentCount; i++) {
            records[i].printDetails();
        }
    }

    void searchRecord() const {
        if (studentCount == 0) {
            cout << "\nNo records available to search.\n";
            return;
        }

        int targetRoll;
        cout << "\nEnter Roll Number to search: ";
        cin >> targetRoll;

        for (int i = 0; i < studentCount; i++) {
            if (records[i].getRollNumber() == targetRoll) {
                cout << "\nRecord Found:\n";
                records[i].printDetails();
                return;
            }
        }
        cout << "\nStudent with Roll Number " << targetRoll << " not found.\n";
    }
};


int main() {
    GradeBook systemBook; 
    int choice;

    do {
        cout << "\n===================================\n";
        cout << "     STUDENT RECORD SYSTEM\n";
        cout << "===================================\n";
        cout << "1. Add Student Record\n";
        cout << "2. Display All Records\n";
        cout << "3. Search Record by Roll No\n";
        cout << "4. Exit\n";
        cout << "Enter your choice (1-4): ";
        cin >> choice;

        switch (choice) {
            case 1:
                systemBook.addRecord();
                break;
            case 2:
                systemBook.displayRecords();
                break;
            case 3:
                systemBook.searchRecord();
                break;
            case 4:
                cout << "\nExiting system. Goodbye!\n";
                break;
            default:
                cout << "\nInvalid choice! Please select between 1 and 4.\n";
        }
    } while (choice != 4);

    return 0;
}
