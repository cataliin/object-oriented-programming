#include <iostream>
#include <string>

using namespace std;

class BankAccount {
protected:
    int accountNumber;
    string accountOwner;
    float balance;
public:
    BankAccount() {
        accountNumber = 0;
        accountOwner = "Anonim";
        balance = 0;
    }

    void setAccountNumber(int _accountNumber) {
        if (_accountNumber >=0) {
            this->accountNumber = _accountNumber;
        }
    }

    int getAccountNumber() const {
        return this->accountNumber;
    }

    void setAccountOwner(string _accountOwner) {
        this->accountOwner = _accountOwner;
    }

    string getAccountOwner() const {
        return this->accountOwner;
    }

    bool deposit(float amount) {
        if (amount > 0) {
            this->balance+=amount;
            return true;
        }
        return false;
    }

    bool withdraw(float amount) {
        if (amount > 0 && amount <= this->balance) {
            this->balance-=amount;
            return true;
        }
        return false;
    }

    float getBalance() const {
        return this->balance;
    }
};

int main() {
    BankAccount b1;
    b1.setAccountNumber(1);
    cout << b1.getAccountNumber() << endl;
    b1.setAccountOwner("Popescu Stefan");
    cout << b1.getAccountOwner() << endl;
    cout << b1.getBalance() << endl;
    if (b1.deposit(500)) {
        cout << "Ai adaugat cu succes fondurile, sold curent : " << b1.getBalance() << endl;
    }
    else {
        cout << "Eroare, suma trebuie sa fie mai mare de 0"<<endl;
    }
    if (b1.withdraw(200)) {
        cout << "Ai retras cu succes fondurile, sold curent : "  << b1.getBalance() << endl;
    }
    else {
        cout << "EROARE, ori nu ai atatea fonduri, ori ai introdus o suma gresita" << endl;
    }
    return 0;
}