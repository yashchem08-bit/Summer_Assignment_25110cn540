#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class ArrayOS {
private:
    vector<int> arr;

public:
    void insertElement(int element) {
        arr.push_back(element);
        cout << "Element inserted successfully!\n";
    }

    void deleteElement(int element) {
        auto it = find(arr.begin(), arr.end(), element);
        if (it != arr.end()) {
            arr.erase(it);
            cout << "Element deleted successfully!\n";
        } else {
            cout << "Element not found!\n";
        }
    }

    void searchElement(int element) {
        auto it = find(arr.begin(), arr.end(), element);
        if (it != arr.end()) {
            cout << "Element found at position: " << (it - arr.begin()) << endl;
        } else {
            cout << "Element not found!\n";
        }
    }

    void sortArray() {
        sort(arr.begin(), arr.end());
        cout << "Array sorted successfully!\n";
    }

    void displayArray() {
        if (arr.empty()) {
            cout << "Array is empty!\n";
            return;
        }
        cout << "Array elements: ";
        for (int x : arr) {
            cout << x << " ";
        }
        cout << endl;
    }
};

int main() {
    ArrayOS aos;
    int choice, element;

    do {
        cout << "\n--- Array Operating System ---\n";
        cout << "1. Insert Element\n";
        cout << "2. Delete Element\n";
        cout << "3. Search Element\n";
        cout << "4. Sort Array\n";
        cout << "5. Display Array\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter element to insert: ";
                cin >> element;
                aos.insertElement(element);
                break;
            case 2:
                cout << "Enter element to delete: ";
                cin >> element;
                aos.deleteElement(element);
                break;
            case 3:
                cout << "Enter element to search: ";
                cin >> element;
                aos.searchElement(element);
                break;
            case 4:
                aos.sortArray();
                break;
            case 5:
                aos.displayArray();
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
