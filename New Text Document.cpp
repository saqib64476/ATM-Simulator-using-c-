#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

// OOP Concept: ATM Class
class ATM {
private:
    string pin;
    double balance;
    vector<string> transactionHistory;

    // Helper function to log history
    void logTransaction(string type, double amount) {
        transactionHistory.push_back(type + " of Rs. " + to_string(amount));
    }

    // File Handling: Save balance to file
    void saveBalance() {
        ofstream outFile("balance.txt");
        if (outFile.is_open()) {
            outFile << balance;
            outFile.close();
        }
    }

    // File Handling: Load balance from file
    void loadBalance() {
        ifstream inFile("balance.txt");
        if (inFile.is_open()) {
            inFile >> balance;
            inFile.close();
        }
    }

public:
    // Constructor
    ATM(string initPin) {
        pin = initPin;
        balance = 0.0;
        loadBalance(); // Puraana balance load karega
    }

    // Destructor: Program band hone par balance save karega
    ~ATM() {
        saveBalance();
    }

    bool verifyPIN(string p) {
        return pin == p;
    }

    void checkBalance() {
        cout << "-> Current Balance: Rs. " << balance << endl;
        transactionHistory.push_back("Checked Balance");
    }

    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            cout << "-> Rs. " << amount << " deposited successfully!" << endl;
            logTransaction("Deposit", amount);
        } else {
            cout << "-> Invalid amount!" << endl;
        }
    }

    void withdraw(double amount) {
        if (amount > 0 && amount <= balance) {
            balance -= amount;
            cout << "-> Rs. " << amount << " withdrawn successfully!" << endl;
            logTransaction("Withdrawal", amount);
        } else if (amount > balance) {
            cout << "-> Insufficient balance! Transaction failed." << endl;
        } else {
            cout << "-> Invalid amount!" << endl;
        }
    }

    void miniStatement() {
        cout << "\n----- MINI STATEMENT -----" << endl;
        if (transactionHistory.empty()) {
            cout << "No recent transactions in this session." << endl;
        } else {
            for (const string& trans : transactionHistory) {
                cout << " - " << trans << endl;
            }
        }
        cout << "--------------------------\n" << endl;
    }
};

void showMenu() {
    cout << "\n========== ADVANCED ATM ==========" << endl;
    cout << "1. Check Balance" << endl;
    cout << "2. Deposit Money" << endl;
    cout << "3. Withdraw Money" << endl;
    cout << "4. Mini Statement" << endl;
    cout << "5. Exit" << endl;
    cout << "==================================" << endl;
    cout << "Enter your choice: ";
}

int main() {
    ATM myATM("1234"); // Set default PIN here
    string enteredPin;
    int choice;
    double amount;

    cout << "Welcome to the OOP ATM Simulator!" << endl;
    cout << "Please enter your 4-digit PIN: ";
    cin >> enteredPin;

    if (!myATM.verifyPIN(enteredPin)) {
        cout << "Incorrect PIN. Access Denied." << endl;
        return 0;
    }

    do {
        showMenu();
        cin >> choice;

        switch (choice) {
            case 1:
                myATM.checkBalance();
                break;
            case 2:
                cout << "-> Enter amount to deposit: Rs. ";
                cin >> amount;
                myATM.deposit(amount);
                break;
            case 3:
                cout << "-> Enter amount to withdraw: Rs. ";
                cin >> amount;
                myATM.withdraw(amount);
                break;
            case 4:
                myATM.miniStatement();
                break;
            case 5:
                cout << "-> Saving data... Thank you for using our ATM!" << endl;
                break;
            default:
                cout << "-> Invalid choice! Please select an option from 1 to 5." << endl;
        }
    } while (choice != 5);

    return 0;
}