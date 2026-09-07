#include <iostream>
#include "BookingService.cpp"

// Main Menu Driver Program
int main() {
    BookingService service;
    int choice = 0;

    while (true) {
        std::cout << "\n=============================================\n";
        std::cout << "    MOVIE TICKET BOOKING SYSTEM        \n";
        std::cout << "=============================================\n";
        std::cout << "1. List Movies\n";
        std::cout << "2. List Shows & View Seat Layout\n";
        std::cout << "3. Book Tickets\n";
        std::cout << "4. Cancel Booking\n";
        std::cout << "5. Exit\n";
        std::cout << "Enter choice: ";

        if (!(std::cin >> choice)) {
            service.clearInput();
            continue;
        }

        switch (choice) {
            case 1:
                service.listMovies();
                break;
            case 2:
                service.listShows();
                std::cout << "Enter Show ID to view layout: ";
                int sId;
                if (std::cin >> sId) {
                    Show* s = service.findShow(sId);
                    if (s) s->displayLayout();
                    else std::cout << "Invalid Show ID!\n";
                } else {
                    service.clearInput();
                }
                break;
            case 3:
                service.bookTicketsWorkflow();
                break;
            case 4:
                service.cancelBookingWorkflow();
                break;
            case 5:
                std::cout << "Thank you for using Movie Ticket Booking System!\n";
                return 0;
            default:
                std::cout << "Invalid Choice! Please enter 1-5.\n"; // Edge case 4: invalid menu handling
                break;
        }
    }
    return 0;
}
