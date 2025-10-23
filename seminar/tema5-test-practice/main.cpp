#include <iostream>

using namespace std;

class BankAccount {
    int accountNumber;
    string accountOwner;
    double balance;
public:
    BankAccount(int _accountNumber, const char* _accountOwner, double _balance):
    accountNumber(_accountNumber),accountOwner(_accountOwner),balance(_balance){}

    BankAccount() : BankAccount(0, "Anonim", 0){}

    double getBalance() const {
        return this->balance;
    }

    void withdraw(double amount) {
        if (amount > 0) {
            if (this->balance >= amount) {
                this->balance-=amount;
            }
        }
    }

    void deposit(double amount) {
        if (amount > 0) {
            this->balance += amount;
        }
    }

    void displayAccount() const {
        cout << "Account Number: " << this->accountNumber << endl;
        cout << "Account Owner: " << this->accountOwner << endl;
        cout << "Account Balance: " << this->balance << endl;
    }
};

int main() {

    BankAccount a1(1,"Catalin",500);

    // a1.displayAccount();
    // cout << a1.getBalance();
    a1.deposit(500.50);
    cout << a1.getBalance();

    return 0;
}