#include <bits/stdc++.h>
using namespace std;

class BankAccount {
private:
    int accountNumber;
    string holderName;
    double balance;
    const double MIN_BALANCE = 500; // minimum balance rule

public:
    // Constructor
    BankAccount(int accNo, string name, double initialBalance) {
        accountNumber = accNo;
        holderName = name;
        
        if (initialBalance < MIN_BALANCE) {
            cout << "Initial balance must be at least " << MIN_BALANCE << endl;
            balance = MIN_BALANCE;
        } else {
            balance = initialBalance;
        }
    }

    // Deposit function
    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            cout << "Deposited: " << amount << endl;
        } else {
            cout << "Invalid deposit amount!" << endl;
        }
    }

    // Withdraw function
    void withdraw(double amount) {
        if (amount <= 0) {
            cout << "Invalid withdrawal amount!" << endl;
        }
        else if (balance - amount < MIN_BALANCE) {
            cout << "Withdrawal denied! Minimum balance of " << MIN_BALANCE << " must be maintained." << endl;
        }
        else {
            balance -= amount;
            cout << "Withdrawn: " << amount << endl;
        }
    }

    // Display balance
    void displayBalance() {
        cout << "\nAccount Details:\n";
        cout << "Account Number: " << accountNumber << endl;
        cout << "Holder Name: " << holderName << endl;
        cout << "Balance: " << balance << endl;
    }
};

int main() {
    int accNo;
    string name;
    double initialBalance;

    cout << "Enter Account Number: ";
    cin >> accNo;

    cin.ignore(); // to handle getline after cin
    cout << "Enter Holder Name: ";
    getline(cin, name);

    cout << "Enter Initial Balance: ";
    cin >> initialBalance;

    BankAccount acc(accNo, name, initialBalance);

    int choice;
    double amount;

    do {
        cout << "\n--- MENU ---\n";
        cout << "1. Deposit\n";
        cout << "2. Withdraw\n";
        cout << "3. Display Balance\n";
        cout << "4. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter amount to deposit: ";
                cin >> amount;
                acc.deposit(amount);
                break;

            case 2:
                cout << "Enter amount to withdraw: ";
                cin >> amount;
                acc.withdraw(amount);
                break;

            case 3:
                acc.displayBalance();
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