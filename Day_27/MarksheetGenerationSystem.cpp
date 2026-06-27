#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Student {
private:
    int id;
    string name;
    vector<int> marks;
    int total;
    double percentage;
    char grade;

    void calculateResults() {
        total = 0;
        for (int m : marks) total += m;
        percentage = (double)total / marks.size();
        if (percentage >= 90) grade = 'A';
        else if (percentage >= 75) grade = 'B';
        else if (percentage >= 60) grade = 'C';
        else if (percentage >= 40) grade = 'D';
        else grade = 'F';
    }

public:
    Student(int id, string name, vector<int> marks) {
        this->id = id;
        this->name = name;
        this->marks = marks;
        calculateResults();
    }

    int getId() const { return id; }
    string getName() const { return name; }
    double getPercentage() const { return percentage; }
    char getGrade() const { return grade; }

    void display() const {
        cout << "\n--- Marksheet ---\n";
        cout << "ID: " << id << "\nName: " << name << endl;
        cout << "Marks: ";
        for (int m : marks) cout << m << " ";
        cout << "\nTotal: " << total
             << "\nPercentage: " << percentage
             << "\nGrade: " << grade << endl;
    }
};

class MarksheetSystem {
private:
    vector<Student> students;

public:
    void addStudent(int id, string name, vector<int> marks) {
        students.push_back(Student(id, name, marks));
        cout << "Student added successfully!\n";
    }

    void displayAll() {
        if (students.empty()) {
            cout << "No student records found.\n";
            return;
        }
        for (const auto& st : students) {
            st.display();
        }
    }

    void searchStudent(int id) {
        for (const auto& st : students) {
            if (st.getId() == id) {
                st.display();
                return;
            }
        }
        cout << "Student not found.\n";
    }
};

int main() {
    MarksheetSystem ms;
    int choice;

    do {
        cout << "\n--- Marksheet Generation System ---\n";
        cout << "1. Add Student\n";
        cout << "2. Display All Marksheets\n";
        cout << "3. Search Student by ID\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        int id, nSubjects;
        string name;
        vector<int> marks;

        switch (choice) {
            case 1:
                cout << "Enter Student ID and Name: ";
                cin >> id >> name;
                cout << "Enter number of subjects: ";
                cin >> nSubjects;
                marks.resize(nSubjects);
                cout << "Enter marks for " << nSubjects << " subjects: ";
                for (int i = 0; i < nSubjects; i++) cin >> marks[i];
                ms.addStudent(id, name, marks);
                break;
            case 2:
                ms.displayAll();
                break;
            case 3:
                cout << "Enter Student ID: ";
                cin >> id;
                ms.searchStudent(id);
                break;
            case 4:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice!\n";
        }
    } while (choice != 4);

    return 0;
}
