#include <iostream>
#include <vector>

// Single Responsibility: Price Calculation Service
// OOP Concept Demonstrated: SRP & Compile-Time Constants
class PriceCalculator {
public:
    static constexpr double SILVER_PRICE = 150.0;
    static constexpr double GOLD_PRICE = 250.0;
    static constexpr double PLATINUM_PRICE = 400.0;

    // Compile-Time Polymorphism / Overloading or single specialized calculator
    double calculatePrice(const std::vector<SeatType>& seatTypes) {
        double total = 0.0;
        for (SeatType type : seatTypes) {
            if (type == SILVER) total += SILVER_PRICE;
            else if (type == GOLD) total += GOLD_PRICE;
            else if (type == PLATINUM) total += PLATINUM_PRICE;
        }
        return total;
    }
};
