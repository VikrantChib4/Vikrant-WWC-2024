#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class Item {
public:
    int itemID;
    string name;
    string category;
    int quantity;
    int reorderLevel;

    Item(int id, const string& n, const string& c, int q, int r) 
        : itemID(id), name(n), category(c), quantity(q), reorderLevel(r) {}
};
class Inventory {
private:
    Item* items[100];
    int itemCount;

public:
    Inventory() : itemCount(0) {}
    void addItem(int id, const string& name, const string& category, int quantity, int reorderLevel) {
        for (int i = 0; i < itemCount; ++i) {
            if (items[i]->itemID == id) {
                cout << "Item with ID " << id << " already exists." << endl;
                return;
            }
        }
        items[itemCount++] = new Item(id, name, category, quantity, reorderLevel);
    }

    // Update stock of an existing item
    void updateStock(int id, int newQuantity) {
        for (int i = 0; i < itemCount; ++i) {
            if (items[i]->itemID == id) {
                items[i]->quantity = newQuantity;
                cout << "Stock updated for Item ID " << id << endl;
                return;
            }
        }
        cout << "Item with ID " << id << " not found." << endl;
    }

    void checkReorder() const {
        for (int i = 0; i < itemCount; ++i) {
            if (items[i]->quantity < items[i]->reorderLevel) {
                cout << "Reorder Alert: " << items[i]->name << " is below reorder level." << endl;
            }
        }
    }

    void viewInventory() const {
        for (int i = 0; i < itemCount; ++i) {
            cout << "ID: " << items[i]->itemID 
                 << ", Name: " << items[i]->name 
                 << ", Category: " << items[i]->category 
                 << ", Quantity: " << items[i]->quantity 
                 << ", Reorder Level: " << items[i]->reorderLevel << endl;
        }
    }

    void exportToFile() const {
        ofstream file("inventory.txt");
        if (!file) {
            cout << "Unable to open file for writing." << endl;
            return;
        }
        for (int i = 0; i < itemCount; ++i) {
            file << items[i]->itemID << "," << items[i]->name << "," 
                 << items[i]->category << "," << items[i]->quantity << "," 
                 << items[i]->reorderLevel << endl;
        }
        file.close();
        cout << "Inventory exported to file." << endl;
    }

    ~Inventory() {
        for (int i = 0; i < itemCount; ++i) {
            delete items[i];
        }
    }
};

int main() {
    Inventory inventory;
    int choice;

    do {
        cout << "1. Add Item\n2. Update Stock\n3. View Inventory\n4. Check Reorder\n5. Export to File\n6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                int id, quantity, reorderLevel;
                string name, category;
                cout << "Enter Item ID, Name, Category, Quantity, Reorder Level: ";
                cin >> id >> name >> category >> quantity >> reorderLevel;
                inventory.addItem(id, name, category, quantity, reorderLevel);
                break;
            }
            case 2: {
                int id, newQuantity;
                cout << "Enter Item ID and New Quantity: ";
                cin >> id >> newQuantity;
                inventory.updateStock(id, newQuantity);
                break;
            }
            case 3:
                inventory.viewInventory();
                break;
            case 4:
                inventory.checkReorder();
                break;
            case 5:
                inventory.exportToFile();
                break;
            case 6:
                cout << "Exiting the program." << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 6);

    return 0;
}
