#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Item {
    int id;
    string name;
    int quantity;
    double price;
};

class Inventory {
private:
    vector<Item> items;

public:
    void addItem(int id, string name, int quantity, double price) {
        items.push_back({id, name, quantity, price});
        cout << "Item added successfully!\n";
    }

    void displayItems() {
        if (items.empty()) {
            cout << "Inventory is empty!\n";
            return;
        }
        cout << "\n--- Inventory List ---\n";
        for (auto &item : items) {
            cout << "ID: " << item.id
                 << " | Name: " << item.name
                 << " | Quantity: " << item.quantity
                 << " | Price: " << item.price << endl;
        }
    }

    void searchItem(int id) {
        auto it = find_if(items.begin(), items.end(),[id](Item &i){ return i.id == id; });
        if (it != items.end()) {
            cout << "Item Found: " << it->name
                 << " | Quantity: " << it->quantity
                 << " | Price: " << it->price << endl;
        } else {
            cout << "Item not found!\n";
        }
    }

    void updateQuantity(int id, int newQty) {
        auto it = find_if(items.begin(), items.end(),[id](Item &i){ return i.id == id; });
        if (it != items.end()) {
            it->quantity = newQty;
            cout << "Quantity updated successfully!\n";
        } else {
            cout << "Item not found!\n";
        }
    }

    void deleteItem(int id) {
        auto it = find_if(items.begin(), items.end(),[id](Item &i){ return i.id == id; });
        if (it != items.end()) {
            items.erase(it);
            cout << "Item deleted successfully!\n";
        } else {
            cout << "Item not found!\n";
        }
    }
};

int main() {
    Inventory inv;
    int choice, id, qty;
    string name;
    double price;

    do {
        cout << "\n--- Inventory Management System ---\n";
        cout << "1. Add Item\n";
        cout << "2. Display Items\n";
        cout << "3. Search Item\n";
        cout << "4. Update Quantity\n";
        cout << "5. Delete Item\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                
                cout << "Enter ID: "; 
                cin >> id;
                cout << "Enter Name: ";
                cin.ignore();
                getline(cin, name);
                cout << "Enter Quantity: ";
                cin >> qty;
                cout << "Enter Price: ";
                cin >> price;
                inv.addItem(id, name, qty, price);
                break;
            case 2:
                inv.displayItems();
                break;
            case 3:
                cout << "Enter ID to search: ";
                cin >> id;
                inv.searchItem(id);
                break;
            case 4:
                cout << "Enter ID to update: "; 
                cin >> id;
                cout << "Enter new Quantity: "; 
                cin >> qty;
                inv.updateQuantity(id, qty);
                break;
            case 5:
                cout << "Enter ID to delete: "; 
                cin >> id;
                inv.deleteItem(id);
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
