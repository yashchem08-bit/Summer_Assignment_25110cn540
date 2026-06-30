#include <bits/stdc++.h>
using namespace std;
class library
{
public:
    vector<pair<string, string>> Book_Student;
    vector<pair<string, int>> Student_id;
    library(vector<pair<string, string>> Book_Student, vector<pair<string, int>> Student_id)
    {
        this->Book_Student = Book_Student;
        this->Student_id = Student_id;
    }
    library()
    {
    }
    void issue_book(string name, string Book, int id)
    {
        Book_Student.push_back({name, Book});
        Student_id.push_back({name, id});
        cout << name << " :: HAS ISSUED A BOOK :: " << Book << endl;
        cout << ":: DON'T FORGET TO RETURN IT WHEN YOUR TIME PERIOD IS OVER :: " << endl;
    }
    void return_book(string name, string book, int id)
    {
        cout << "THANK YOU FOR RETURNING IT BACK TO IT'S CORRECT POSITION " << endl;
        auto to_remove = make_pair(name, book);
        auto to_remove_id = make_pair(name, id);
        bool verify = false;
        for (auto &val : Student_id)
        {
            if (val.second == id)
            {
                cout << "--VERIFIACTION SUCCESSFUL--" << endl;
                verify = true;
            }
        }
        if (verify == true)
        {
            Book_Student.erase(remove(Book_Student.begin(), Book_Student.end(), to_remove), Book_Student.end());
            Student_id.erase(remove(Student_id.begin(), Student_id.end(), to_remove_id), Student_id.end());
            cout << "--DATA REMOVED SUCCESSFULLY--" << endl;
        }
        else
        {
            cout << "--INALID INPUT";
            return;
        }
    }
    void Pending_returns(string name, int id)
    {
        bool found = false;
        for (auto &val : Student_id)
        {
            if (val.first == name && val.second == id)
            {
                pending(name,found);
            }
        }
        if(found == true){
            cout<<"PLEASE RETURN YOUR PENDINGS AS SOON AS POSSIBLE "<<endl;
        }else{
            cout<<" !! GOOD JOB NO PENDINGS !!"<<endl;
        }
    }
    void pending(string name,bool &found)
    {
        for (auto &out : Book_Student)
        {
            if (out.first == name)
            {   
                found = true;
                cout << "PENDINGS ARE :: " << out.second << endl;
                break;
            }
        }
    }
};
int main()
{
    library student;
    int choice;

    do
    {
        cout << "------------------------------" << endl;
        cout << "---LIBRARY MANGEMENT SYSTEM----" << endl;
        cout << "1. IISUE BOOK :: " << endl;
        cout << "2. RETURN BOOK :: " << endl;
        cout << "3. SEARCH FOR YOUR PENDING RETURNS :: " << endl;
        cout << "4. EXIT" << endl;
        cin >> choice;
        string user_name;
        string book_name;
        int id;
        switch (choice)
        {
        case 1:
        {
            cin.ignore();
            cout << "ENTER YOUR NAME :: ";
            getline(cin, user_name);
            cout << "ENTER BOOK NAME TO BE ISSUED :: ";
            getline(cin, book_name);
            cout << "ENTER YOUR ID :: \n(::note it should be 4 digits::)\n";
            cin >> id;
            student.issue_book(user_name, book_name, id);
            break;
        }
        case 2:
        {
            cin.ignore();
            cout << "ENTER YOUR NAME AS WELL AS NAME OF BOOK :: ";
            getline(cin, user_name);
            getline(cin, book_name);
            cout << "ENTER YOUR PIN FOR VERIFICATION :: ";
            cin >> id;
            student.return_book(user_name, book_name, id);
            break;
        }
        case 3:
        {
            cin.ignore();
            cout << "ENTER YOUR NAME :: ";
            getline(cin, user_name);
            cout << "ENTER ID :: ";
            cin >> id;
            student.Pending_returns(user_name, id);
            break;
        }
        case 4:
        {
            cout << "--EXITING PROGRAM--";
            break;
        }

        default:
        {
            break;
        }
        }
    } while (choice != 4);
}