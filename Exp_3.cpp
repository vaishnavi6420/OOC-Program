#include <iostream>
#include <string>
using namespace std;

class Account {
private:
    string accountHolder;
    int accountNumber;
    double balance;

public:
    Account(string name, int number, double initialBalance)
        : accountHolder(name), accountNumber(number), balance(initialBalance) {}

    void deposit(double amount) {
        balance += amount;
    }

    void withdraw(double amount) {
        if (amount <= balance)
            balance -= amount;
        else
            cout << "Insufficient balance\n";
    }

    void accountStatement() const {
        cout << "\nAccount Statement:\n";
        cout << "Holder: " << accountHolder << endl;
        cout << "Number: " << accountNumber << endl;
        cout << "Balance: " << balance << endl;
    }
};

class SavingAccount {
private:
    string accountHolder;
    int accountNumber;
    double balance;
    double interestRate;

public:
    SavingAccount(string name, int number, double initialBalance, double rate)
        : accountHolder(name), accountNumber(number), balance(initialBalance), interestRate(rate) {}

    void deposit(double amount) {
        balance += amount;
    }

    void applyInterest() {
        balance += balance * interestRate / 100;
    }

    void withdraw(double amount) {
        if (amount <= balance)
            balance -= amount;
        else
            cout << "Insufficient balance\n";
    }

    void accountStatement() const {
        cout << "\nSaving Account Statement:\n";
        cout << "Holder: " << accountHolder << endl;
        cout << "Number: " << accountNumber << endl;
        cout << "Balance: " << balance << endl;
        cout << "Interest Rate: " << interestRate << "%\n";
    }
};

class CheckingAccount {
private:
    string accountHolder;
    int accountNumber;
    double balance;
    double transactionFee;

public:
    CheckingAccount(string name, int number, double initialBalance, double fee)
        : accountHolder(name), accountNumber(number), balance(initialBalance), transactionFee(fee) {}

    void deposit(double amount) {
        balance += amount;
    }

    void withdraw(double amount) {
        double total = amount + transactionFee;
        if (total <= balance)
            balance -= total;
        else
            cout << "Insufficient balance (including fee)\n";
    }

    void accountStatement() const {
        cout << "\nChecking Account Statement:\n";
        cout << "Holder: " << accountHolder << endl;
        cout << "Number: " << accountNumber << endl;
        cout << "Balance: " << balance << endl;
        cout << "Transaction Fee: " << transactionFee << "\n";
    }
};

int main() {
    Account basic("Charlie", 3001, 4000.0);
    SavingAccount sa("Alice", 1001, 5000.0, 2.5);
    CheckingAccount ca("Bob", 2001, 3000.0, 50.0);

    basic.deposit(500);
    basic.withdraw(1000);
    basic.accountStatement();

    sa.deposit(1000);
    sa.applyInterest();
    sa.withdraw(200);
    sa.accountStatement();

    ca.deposit(500);
    ca.withdraw(1000);
    ca.accountStatement();

    return 0;
}