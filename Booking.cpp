#include <iostream>
#include <vector>
#include <string>
#include "Customer.cpp"

enum BookingStatus { CONFIRMED, CANCELLED };

// Booking Domain Object
// OOP Concepts Demonstrated:
// 1. Static Members (Static counter for unique Booking IDs)
// 2. Aggregation (Refers to Customer and ShowSeats)
class Booking {
private:
    static int idCounter; // Static member
    int bookingId;
    Customer customer;
    Show* show;
    std::vector<std::string> bookedSeatNumbers;
    double totalAmount;
    BookingStatus status;

public:
    Booking(Customer c, Show* s, std::vector<std::string> seats, double amount)
        : customer(c), show(s), bookedSeatNumbers(seats), totalAmount(amount), status(CONFIRMED) {
        this->bookingId = ++idCounter; // Auto-incrementing static counter
    }

    int getBookingId() const { return this->bookingId; }
    Customer getCustomer() const { return this->customer; }
    Show* getShow() const { return this->show; }
    std::vector<std::string> getBookedSeatNumbers() const { return this->bookedSeatNumbers; }
    double getTotalAmount() const { return this->totalAmount; }
    BookingStatus getStatus() const { return this->status; }

    void cancelBooking() {
        this->status = CANCELLED;
    }
};

// Initialize static counter member
int Booking::idCounter = 1000;
