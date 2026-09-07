#include <iostream>
#include <string>

enum SeatType { SILVER, GOLD, PLATINUM };

// Seat Class: Represents physical seat configuration
// OOP Concept Demonstrated: Encapsulation
class Seat {
private:
    std::string seatNumber;
    SeatType type;

public:
    Seat(std::string num = "", SeatType t = SILVER) {
        this->seatNumber = num;    // OOP Concept: 'this' keyword
        this->type = t;
    }

    std::string getSeatNumber() const { return this->seatNumber; }
    SeatType getType() const { return this->type; }

    std::string getTypeString() const {
        if (this->type == SILVER) return "SILVER";
        if (this->type == GOLD) return "GOLD";
        return "PLATINUM";
    }
};
