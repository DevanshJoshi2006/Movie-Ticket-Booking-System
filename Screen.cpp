#include <iostream>
#include <vector>
#include "Seat.cpp"

// Screen Class: Owns physical seats
// OOP Concept Demonstrated: Composition (Screen owns Seat objects)
class Screen {
private:
    int screenNumber;
    std::vector<Seat> physicalSeats; // Composition relationship

public:
    Screen(int num = 0) {
        this->screenNumber = num;
        initializeSeats();
    }

    void initializeSeats() {
        // Creates 6 physical seats per screen
        physicalSeats.push_back(Seat("A1", SILVER));
        physicalSeats.push_back(Seat("A2", SILVER));
        physicalSeats.push_back(Seat("B1", GOLD));
        physicalSeats.push_back(Seat("B2", GOLD));
        physicalSeats.push_back(Seat("C1", PLATINUM));
        physicalSeats.push_back(Seat("C2", PLATINUM));
    }

    int getScreenNumber() const { return this->screenNumber; }
    const std::vector<Seat>& getPhysicalSeats() const { return this->physicalSeats; }
};
