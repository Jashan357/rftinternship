#include <bits/stdc++.h>
using namespace std;

// Product Class
class Product {
public:
    string name;
    double price;
    int quantity;

    Product(string n, double p, int q) {
        name = n;
        price = p;
        quantity = q;
    }
};

// Cart Class
class Cart {
private:
    vector<Product> products;

    // separate helper so discount message only prints once
    double getTotal() {
        double total = 0;
        for (auto p : products) {
            total += p.price * p.quantity;
        }
        return total;
    }

public:
    // Add product to cart
    void addProduct(string name, double price, int quantity) {
        // Check if product already exists
        for (auto &p : products) {
            if (p.name == name) {
                p.quantity += quantity;
                cout << name << " already in cart. Quantity updated.\n";
                return;
            }
        }
        products.push_back(Product(name, price, quantity));
        cout << name << " added to cart.\n";
    }

    // Remove product from cart
    void removeProduct(string name) {
        // FIX 1: use size_t instead of int to avoid signed/unsigned mismatch warning
        for (size_t i = 0; i < products.size(); i++) {
            if (products[i].name == name) {
                products.erase(products.begin() + i);
                cout << name << " removed from cart.\n";
                return;
            }
        }
        cout << "Product not found!\n";
    }

    // Calculate total bill
    // FIX 2: removed cout from here so discount message doesn't print twice
    double calculateBill() {
        double total = getTotal();
        if (total > 1000) {
            total = total - (0.10 * total);
        }
        return total;
    }

    // Display cart summary
    void displayCart() {
        if (products.empty()) {
            cout << "Cart is empty.\n";
            return;
        }

        cout << "\n===== CART SUMMARY =====\n";
        for (auto p : products) {
            cout << "Product: "  << p.name << endl;
            cout << "Price: "    << p.price << endl;
            cout << "Quantity: " << p.quantity << endl;
            cout << "Subtotal: " << p.price * p.quantity << endl;
            cout << "----------------------\n";
        }

        double raw = getTotal();
        cout << "Total before discount: " << raw << endl;
        if (raw > 1000) {
            cout << "10% Discount Applied!\n";
        }
        cout << "Final Bill: " << calculateBill() << endl;
    }
};

int main() {
    Cart cart;
    int choice;

    do {
        cout << "\n===== MINI SHOPPING CART =====\n";
        cout << "1. Add Product\n";
        cout << "2. Remove Product\n";
        cout << "3. Display Cart\n";
        cout << "4. Calculate Bill\n";
        cout << "5. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;
        cin.ignore();   // clear leftover newline before getline

        if (choice == 1) {
            string name;
            double price;
            int quantity;
            // FIX 3: use getline so names with spaces work (e.g. "Cooking Oil")
            cout << "Enter product name: ";
            getline(cin, name);
            cout << "Enter price: ";
            cin >> price;
            cout << "Enter quantity: ";
            cin >> quantity;
            cin.ignore();
            cart.addProduct(name, price, quantity);
        }
        else if (choice == 2) {
            string name;
            cout << "Enter product name to remove: ";
            getline(cin, name);
            cart.removeProduct(name);
        }
        else if (choice == 3) {
            cart.displayCart();
        }
        else if (choice == 4) {
            double bill = cart.calculateBill();
            if (bill > 0) cout << "10% Discount Applied (if total > 1000)\n";
            cout << "Total Bill = " << bill << endl;
        }
        else if (choice == 5) {
            cout << "Exiting...\n";
        }
        else {
            cout << "Invalid Choice!\n";
        }

    } while (choice != 5);

    return 0;
}
