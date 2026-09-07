#include <iostream>
#include <string>

// Derived Class 2
// OOP Concepts Demonstrated: Inheritance & Polymorphism
class CardPayment : public Payment {
private:
    std::string cardNumber;

public:
    CardPayment(std::string card) : cardNumber(card) {}

    bool pay(double amount) override {
        std::cout << "[CARD PAYMENT] Processing RS" << amount << " via Card: " << cardNumber << "...";
        if (cardNumber == "0000") {
            std::cout << " FAILED!\n";
            return false;
        }
        std::cout << " SUCCESS!\n";
        return true;
    }
};
