#include <bits/stdc++.h>
using namespace std;

// Base Class
class Item {
protected:
    int id;
    string title;
    bool isIssued;

public:
    Item(int id, string title) {
        this->id = id;
        this->title = title;
        isIssued = false;
    }

    virtual void displayDetails() {
        cout << "ID: " << id << "\nTitle: " << title;
        cout << "\nStatus: " << (isIssued ? "Issued" : "Available") << endl;
    }

    void issueItem() {
        if (!isIssued) {
            isIssued = true;
            cout << "Item issued successfully\n";
        } else {
            cout << "Item already issued\n";
        }
    }

    void returnItem() {
        if (isIssued) {
            isIssued = false;
            cout << "Item returned successfully\n";
        } else {
            cout << "Item was not issued\n";
        }
    }

    bool available() {
        return !isIssued;
    }
};

// Derived Class: Book
class Book : public Item {
    string author;

public:
    Book(int id, string title, string author)
        : Item(id, title) {
        this->author = author;
    }

    void displayDetails() override {
        Item::displayDetails();
        cout << "Author: " << author << endl;
    }
};

// Derived Class: Magazine
class Magazine : public Item {
    int issueNumber;

public:
    Magazine(int id, string title, int issueNumber)
        : Item(id, title) {
        this->issueNumber = issueNumber;
    }

    void displayDetails() override {
        Item::displayDetails();
        cout << "Issue Number: " << issueNumber << endl;
    }
};

// Bonus: Fine Calculation
int calculateFine(int daysLate) {
    int finePerDay = 5;
    return daysLate * finePerDay;
}

// Main Function
int main() {
    vector<Item*> library;

    // Adding items
    library.push_back(new Book(1, "C++ Basics", "Bjarne"));
    library.push_back(new Magazine(2, "Tech Monthly", 101));

    // Display all items
    cout << "\n--- Library Items ---\n";
    for (auto item : library) {
        item->displayDetails();
        cout << "-------------------\n";
    }

    // Issue first item
    library[0]->issueItem();

    // Return item
    library[0]->returnItem();

    // Count available items
    int count = 0;
    for (auto item : library) {
        if (item->available()) count++;
    }
    cout << "\nAvailable items: " << count << endl;

    // Fine example
    int daysLate = 3;
    cout << "Fine for " << daysLate << " days: ₹" 
         << calculateFine(daysLate) << endl;

    return 0;
}