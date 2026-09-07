#include <iostream>

// Derived Class 3
// OOP Concepts Demonstrated: Inheritance & Polymorphism
class CashPayment : public Payment {
public:
    CashPayment() {}

    bool pay(double amount) override {
        std::cout << "[CASH PAYMENT] Received RS" << amount << " in cash... SUCCESS!\n";
        return true;
    }
};
