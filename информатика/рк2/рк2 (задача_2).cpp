#include <iostream>
#include <string>
#include <iomanip>
using namespace std;
// 1. BankAccount
class BankAccount {
protected:
    string accountNumber;
    string ownerName;
    double balance;
public:
    BankAccount(string accNum, string owner, double initialBalance = 0.0)
        : accountNumber(accNum), ownerName(owner), balance(initialBalance) {}
    //пополнение средств
    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            cout << "Внесено: " << amount << " руб. Баланс: " << balance << " руб." << endl;
        }
    }
    //снятие средств
    void withdraw(double amount) {
        if (amount > 0 && amount <= balance) {
            balance -= amount;
            cout << "Снято: " << amount << " руб. Баланс: " << balance << " руб." << endl;
        } else {
            cout << "Недостаточно средств или неверная сумма!" << endl;
        }
    }

    void displayInfo() const {
        cout << "\nСчёт: " << accountNumber << endl;
        cout << "Владелец: " << ownerName << endl;
        cout << "Баланс: " << fixed << setprecision(2) << balance << " руб." << endl;
    }
};

// 2. SavingsAccount
class SavingsAccount : public BankAccount {
private:
    double interestRate;
public:
    SavingsAccount(string accNum, string owner, double initialBalance = 0.0, double rate = 0.0)
        : BankAccount(accNum, owner, initialBalance), interestRate(rate) {}
    //для начисления процентов
    void calculateInterest() {
        double interest = balance * (interestRate / 100.0);
        balance += interest;
        cout << "Начислены проценты: " << interest << " руб." << endl;
        cout << "Новый баланс: " << balance << " руб." << endl;
    }
    void displayInfo() const {
        BankAccount::displayInfo();
        cout << "Процентная ставка: " << interestRate << "%" << endl;
    }
};

// 3
int main() {
    cout << "=== МОДЕЛИРОВАНИЕ РАБОТЫ БАНКА ===\n" << endl;
    cout << "1. СОЗДАНИЕ ОБЫЧНОГО СЧЁТА:" << endl;
    BankAccount regularAcc("40817810099910004312", "Иванов Иван Иванович", 10000.0);
    regularAcc.displayInfo();

    cout << "\nОперации с обычным счётом:" << endl;
    regularAcc.deposit(5000.0);
    regularAcc.withdraw(3000.0);
    regularAcc.displayInfo();
    cout << "\n" << string(50, '=') << "\n" << endl;
    cout << "2. СОЗДАНИЕ СБЕРЕГАТЕЛЬНОГО СЧЁТА:" << endl;
    SavingsAccount savingsAcc("42301810712345678901", "Петрова Мария Сергеевна", 50000.0, 5.5);
    savingsAcc.displayInfo();
    cout << "\nОперации со сберегательным счётом:" << endl;
    savingsAcc.deposit(15000.0);
    savingsAcc.withdraw(10000.0);
    cout << "\nНачисление процентов:" << endl;
    savingsAcc.calculateInterest();
    cout << "\nЕщё одно начисление процентов (спустя время):" << endl;
    savingsAcc.calculateInterest();
    savingsAcc.displayInfo();
    cout << "\n" << string(50, '=') << "\n" << endl;
    cout << "3. ДЕМОНСТРАЦИЯ:" << endl;
    BankAccount* accounts[2];
    accounts[0] = &regularAcc;
    accounts[1] = &savingsAcc;
    for (int i = 0; i < 2; i++) {
        cout << "\nСчёт " << i + 1 << ":" << endl;
        accounts[i]->displayInfo();
    }
    return 0;
}