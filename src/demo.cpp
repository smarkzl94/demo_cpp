#include <iostream>

class Circle{
private:
    double radius;

public:
    Circle(double radius){
        if (radius <= 0) {
            throw std::invalid_argument("Radius must be positive");
        }
        this->radius = radius;
    }

    double getRadius() const {
        return radius;
    }

    double getArea() const {
        return 3.14 * radius * radius;
    }
    
    double getCircumference() const {
        return 2 * 3.14 * radius;
    }
};

class BankAccount{
private:
    
    std::string accountNumber;
    double balance;
    
public:
    BankAccount(std::string accountNumber, double balance){
        this->accountNumber = accountNumber;
        this->balance = balance;
    }

    void withdrawMoney(double money){
        if (money <= 0) {
            throw std::invalid_argument("Money must be positive");
        }
        if (money > balance) {
            throw std::runtime_error("Insufficient balance");
        }
        balance -= money;
    }

    void addMoney(double money){
        if (money <= 0) {
            throw std::invalid_argument("Money must be positive");
        }
        balance += money;
    }

    double getBalance() const {
        return balance;
    }
};


int main() {
    Circle circle(10);
    std::cout << "Radius: " << circle.getRadius() << std::endl;
    std::cout << "Area: " << circle.getArea() << std::endl;
    std::cout << "Circumference: " << circle.getCircumference() << std::endl;

    BankAccount bankAccount("1234567890", 1000);
    std::cout << "Balance: " << bankAccount.getBalance() << std::endl;
    bankAccount.withdrawMoney(500);
    std::cout << "Balance: " << bankAccount.getBalance() << std::endl;
    bankAccount.addMoney(200);
    std::cout << "Balance: " << bankAccount.getBalance() << std::endl;
    return 0;
}
