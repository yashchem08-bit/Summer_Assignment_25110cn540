#include <bits/stdc++.h>
using namespace std;
class Contact
{
private:
    int id;
    string name;
    string phone;
    string email;

public:
    Contact(int id, string name, string phone, string email)
    {
        this->id = id;
        this->name = name;
        this->phone = phone;
        this->email = email;
    }

    int getId() const
    {
        return id;
    }
    string getName() const
    {
        return name;
    }
    string getPhone() const
    {
        return phone;
    }
    string getEmail() const
    {
        return email;
    }

    void setName(string newName)
    {
        name = newName;
    }
    void setPhone(string newPhone)
    {
        phone = newPhone;
    }
    void setEmail(string newEmail)
    {
        email = newEmail;
    }

    void display() const
    {
        cout << "ID: " << id
             << " | Name: " << name
             << " | Phone: " << phone
             << " | Email: " << email << endl;
    }
};

class ContactManagementSystem
{
private:
    vector<Contact> contacts;

public:
    void addContact(int id, string name, string phone, string email)
    {
        contacts.push_back(Contact(id, name, phone, email));
        cout << "Contact added successfully!\n";
    }

    void displayAll()
    {
        if (contacts.empty())
        {
            cout << "No contacts found.\n";
            return;
        }
        for (const auto &c : contacts)
        {
            c.display();
        }
    }

    void searchContact(int id)
    {
        for (const auto &c : contacts)
        {
            if (c.getId() == id)
            {
                c.display();
                return;
            }
        }
        cout << "Contact not found.\n";
    }

    void updateContact(int id, string newName, string newPhone, string newEmail)
    {
        for (auto &c : contacts)
        {
            if (c.getId() == id)
            {
                c.setName(newName);
                c.setPhone(newPhone);
                c.setEmail(newEmail);
                cout << "Contact updated successfully!\n";
                return;
            }
        }
        cout << "Contact not found.\n";
    }

    void deleteContact(int id)
    {
        for (auto it = contacts.begin(); it != contacts.end(); ++it)
        {
            if (it->getId() == id)
            {
                contacts.erase(it);
                cout << "Contact deleted successfully!\n";
                return;
            }
        }
        cout << "Contact not found.\n";
    }
};

int main()
{
    ContactManagementSystem cms;
    int choice;

    do
    {
        cout << "\n--- Contact Management System ---\n";
        cout << "1. Add Contact\n";
        cout << "2. Display All Contacts\n";
        cout << "3. Search Contact\n";
        cout << "4. Update Contact\n";
        cout << "5. Delete Contact\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        int id;
        string name, phone, email;

        switch (choice)
        {
        case 1:
            cout << "Enter ID, Name, Phone, Email: ";
            cin >> id >> name >> phone >> email;
            cms.addContact(id, name, phone, email);
            break;
        case 2:
            cms.displayAll();
            break;
        case 3:
            cout << "Enter Contact ID: ";
            cin >> id;
            cms.searchContact(id);
            break;
        case 4:
            cout << "Enter Contact ID to update: ";
            cin >> id;
            cout << "Enter new Name, Phone, Email: ";
            cin >> name >> phone >> email;
            cms.updateContact(id, name, phone, email);
            break;
        case 5:
            cout << "Enter Contact ID to delete: ";
            cin >> id;
            cms.deleteContact(id);
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
