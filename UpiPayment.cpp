#include <iostream>
#include <string>

// Derived Class 1
// OOP Concepts Demonstrated: Inheritance & Polymorphism
class UpiPayment : public Payment {
private:
    std::string upiId;

public:
    UpiPayment(std::string id) : upiId(id) {}

    // Runtime Polymorphism: Overridden pay method
    bool pay(double amount) override {
        std::cout << "[UPI PAYMENT] Processing RS" << amount << " via UPI ID: " << upiId << "...";
        if (upiId == "fail") {
            std::cout << " FAILED!\n";
            return false; // Simulated failure for edge case testing
        }
        std::cout << " SUCCESS!\n";
        return true;
    }
};
