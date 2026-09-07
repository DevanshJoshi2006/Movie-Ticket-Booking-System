#include <iostream>
#include <string>

enum SeatStatus { AVAILABLE, BOOKED };

// ShowSeat Class: Tracks seat availability status per show
// OOP Concept Demonstrated: Association/Aggregation (refers to physical Seat)
class ShowSeat {
private:
    Seat seat;
    SeatStatus status;

public:
    ShowSeat(Seat s) : seat(s), status(AVAILABLE) {}

    std::string getSeatNumber() const { return seat.getSeatNumber(); }
    SeatType getSeatType() const { return seat.getType(); }
    SeatStatus getStatus() const { return this->status; }

    bool isAvailable() const { return this->status == AVAILABLE; }

    bool book() {
        if (this->status == BOOKED) {
            return false; // Edge Case Handling: Cannot book already booked seat
        }
        this->status = BOOKED;
        return true;
    }

    void cancel() {
        this->status = AVAILABLE; // Reverts status to AVAILABLE on cancellation
    }
};
