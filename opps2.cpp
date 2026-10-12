#include <iostream>
using namespace std;

class Account {
    int id;
    double balance;
    static double rate;
    static int total;

public:
    Account(double b) {
        total++;
        id = total;
        balance = b;
    }

    static void setRate(double r) {
        rate = r;
    }

    static double getRate() {
        return rate;
    }

    static int getTotal() {
        return total;
    }

    void addInterest() {
        balance += balance * rate / 100;
    }

    void show() const {
        cout << "Account " << id << ": " << balance << endl;
    }
};

double Account::rate = 0;
int Account::total = 0;

int main() {
    Account::setRate(0.5);
    cout << "Rate set to " << Account::getRate() << "%\n";

    Account x(10000), y(5000);
    cout << "After creating " << Account::getTotal() << " accounts\n";

    x.addInterest();
    y.addInterest();

    x.show();
    y.show();

    return 0;
}