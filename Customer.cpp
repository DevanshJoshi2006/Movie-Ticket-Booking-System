#include <iostream>
#include <string>

// Customer Class: Stores customer detail
// OOP Concept Demonstrated: Encapsulation
class Customer {
private:
    std::string name;
    std::string phone;

public:
    Customer(std::string n = "Guest", std::string p = "0000000000") {
        this->name = n;
        this->phone = p;
    }

    std::string getName() const { return this->name; }
    std::string getPhone() const { return this->phone; }
};
