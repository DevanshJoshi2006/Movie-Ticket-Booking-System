#include <iostream>
#include <vector>
#include <string>
#include "Cinema.cpp"
#include "Show.cpp"
#include "Booking.cpp"
#include "Payment.cpp"
#include "UpiPayment.cpp"
#include "CardPayment.cpp"
#include "CashPayment.cpp"
#include "PriceCalculator.cpp"
#include "TicketPrinter.cpp"

// BookingService Orchestrator Class
// OOP Concepts Demonstrated:
// 1. Dependency Inversion Principle (DIP - depends on Payment interface)
// 2. Workflow Coordination & Validation (NFR3)
class BookingService {
private:
    Cinema cinema;
    std::vector<Movie> movies;
    std::vector<Show> shows;
    std::vector<Booking> activeBookings;
    PriceCalculator calculator;
    TicketPrinter printer;

public:
    BookingService() : cinema("PVR Cinemas") {
        setupData();
    }

    void setupData() {
        movies.push_back(Movie("Pokemon Movie I", "Hindi", 126));
        movies.push_back(Movie("Spiderman 2", "English", 127));

        const auto& screens = cinema.getScreens();
        shows.push_back(Show(1, movies[0], screens[0], "10:00 AM"));
        shows.push_back(Show(2, movies[1], screens[1], "02:00 PM"));
    }

    void listMovies() const {
        std::cout << "\n--- MOVIES CURRENTLY PLAYING ---\n";
        for (size_t i = 0; i < movies.size(); ++i) {
            std::cout << i + 1 << ". " << movies[i].getTitle() 
                      << " (" << movies[i].getLanguage() << ", " 
                      << movies[i].getDuration() << " mins)\n";
        }
    }

    void listShows() const {
        std::cout << "\n--- AVAILABLE SHOWS ---\n";
        for (const auto& show : shows) {
            std::cout << "Show ID: " << show.getShowId() 
                      << " | Movie: " << show.getMovie().getTitle() 
                      << " | Screen: " << show.getScreen().getScreenNumber() 
                      << " | Time: " << show.getStartTime() << "\n";
        }
    }

    Show* findShow(int showId) {
        for (auto& show : shows) {
            if (show.getShowId() == showId) return &show;
        }
        return nullptr;
    }

    void bookTicketsWorkflow() {
        listShows();
        std::cout << "Enter Show ID: ";
        int showId;
        if (!(std::cin >> showId)) { clearInput(); return; }

        Show* selectedShow = findShow(showId);
        if (!selectedShow) {
            std::cout << "Error: Invalid Show ID!\n"; // Input validation
            return;
        }

        selectedShow->displayLayout();

        std::cout << "Enter number of seats to book: ";
        int count;
        if (!(std::cin >> count) || count <= 0) { clearInput(); return; }

        std::vector<std::string> requestedSeats;
        std::vector<SeatType> selectedTypes;
        std::vector<ShowSeat*> seatsToBook;

        for (int i = 0; i < count; ++i) {
            std::cout << "Enter Seat Number " << (i + 1) << " (e.g. A1, B1, C1): ";
            std::string sNum;
            std::cin >> sNum;

            bool found = false;
            for (auto& ss : selectedShow->getShowSeats()) {
                if (ss.getSeatNumber() == sNum) {
                    found = true;
                    if (!ss.isAvailable()) {
                        std::cout << "Error: Seat " << sNum << " is ALREADY BOOKED!\n"; // Reject already booked seat
                        return;
                    }
                    seatsToBook.push_back(&ss);
                    requestedSeats.push_back(sNum);
                    selectedTypes.push_back(ss.getSeatType());
                    break;
                }
            }
            if (!found) {
                std::cout << "Error: Invalid Seat Number " << sNum << "!\n"; // Input validation
                return;
            }
        }

        // Calculate Price using PriceCalculator Service
        double totalAmount = calculator.calculatePrice(selectedTypes);
        std::cout << "Total Price: RS" << totalAmount << "\n";

        // Payment Processing (Polymorphism)
        std::cout << "Select Payment Method (1. UPI, 2. Card, 3. Cash): ";
        int pChoice;
        std::cin >> pChoice;

        Payment* paymentObj = nullptr;
        if (pChoice == 1) {
            std::cout << "Enter UPI ID: ";
            std::string upi;
            std::cin >> upi;
            paymentObj = new UpiPayment(upi);
        } else if (pChoice == 2) {
            std::cout << "Enter Card Number: ";
            std::string card;
            std::cin >> card;
            paymentObj = new CardPayment(card);
        } else if (pChoice == 3) {
            paymentObj = new CashPayment();
        } else {
            std::cout << "Invalid Payment Method!\n";
            return;
        }

        // Process Payment (Runtime Polymorphism)
        bool success = paymentObj->pay(totalAmount);
        delete paymentObj;

        if (!success) {
            std::cout << "Payment Failed! Booking is NOT confirmed. Selected seats remain AVAILABLE.\n"; // Edge case 2
            return;
        }

        // Confirm Seat Lock
        for (auto* ss : seatsToBook) {
            ss->book();
        }

        std::cout << "Enter Customer Name: ";
        std::string name;
        std::cin >> name;
        std::cout << "Enter Customer Phone: ";
        std::string phone;
        std::cin >> phone;

        Customer cust(name, phone);
        Booking newBooking(cust, selectedShow, requestedSeats, totalAmount);
        activeBookings.push_back(newBooking);

        std::cout << "\nBooking Successful!\n";
        printer.printTicket(newBooking);
    }

    void cancelBookingWorkflow() {
        std::cout << "Enter Booking ID to cancel: ";
        int bId;
        if (!(std::cin >> bId)) { clearInput(); return; }

        for (auto& b : activeBookings) {
            if (b.getBookingId() == bId && b.getStatus() == CONFIRMED) {
                b.cancelBooking();
                // Release seats back to AVAILABLE status
                Show* show = b.getShow();
                for (const std::string& seatNum : b.getBookedSeatNumbers()) {
                    for (auto& ss : show->getShowSeats()) {
                        if (ss.getSeatNumber() == seatNum) {
                            ss.cancel();
                        }
                    }
                }
                std::cout << "Booking ID " << bId << " CANCELLED successfully! Seats are now AVAILABLE again.\n"; // Edge case 3
                return;
            }
        }
        std::cout << "Error: Confirmed Booking ID not found!\n";
    }

    void clearInput() {
        std::cin.clear();
        std::cin.ignore(10000, '\n');
        std::cout << "Invalid Input! Please try again.\n"; // Input validation (NFR3)
    }
};
