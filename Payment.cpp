#include <iostream>

// Abstract Base Payment Class
// OOP Concepts Demonstrated:
// 1. Abstraction (Pure virtual pay function)
// 2. Extensibility (NFR2 & SOLID OCP)
class Payment {
public:
    // Pure virtual function enforcing payment contract
    virtual bool pay(double amount) = 0; 
    virtual ~Payment() {}
};
