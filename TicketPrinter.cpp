#include <iostream>

// Single Responsibility: Ticket Formatting & Printing Service
class TicketPrinter {
public:
    void printTicket(const Booking& booking) {
        std::cout << "\n=============================================\n";
        std::cout << "             THEATRE BOOKING TICKET          \n";
        std::cout << "=============================================\n";
        std::cout << " Booking ID : " << booking.getBookingId() << "\n";
        std::cout << " Customer   : " << booking.getCustomer().getName() << " (" << booking.getCustomer().getPhone() << ")\n";
        std::cout << " Movie      : " << booking.getShow()->getMovie().getTitle() << "\n";
        std::cout << " Screen     : Screen " << booking.getShow()->getScreen().getScreenNumber() << "\n";
        std::cout << " Show Time  : " << booking.getShow()->getStartTime() << "\n";
        std::cout << " Seats      : ";
        for (const auto& s : booking.getBookedSeatNumbers()) {
            std::cout << s << " ";
        }
        std::cout << "\n Total Paid : RS" << booking.getTotalAmount() << "\n";
        std::cout << " Status     : " << (booking.getStatus() == CONFIRMED ? "CONFIRMED" : "CANCELLED") << "\n";
        std::cout << "=============================================\n\n";
    }
};
