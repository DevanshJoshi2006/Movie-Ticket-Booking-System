#include <iostream>
#include <vector>
#include <string>
#include "Movie.cpp"
#include "ShowSeat.cpp"

// Show Class: Screening of a movie on a screen
// OOP Concepts Demonstrated:
// 1. Aggregation (Show references independent Movie and Screen objects)
// 2. Composition (Show creates and owns ShowSeat status instances)
class Show {
private:
    int showId;
    Movie movie;            // Aggregation: Movie exists independently
    Screen screen;          // Association
    std::string startTime;
    std::vector<ShowSeat> showSeats; // Composition

public:
    Show(int id, Movie m, Screen sc, std::string time) 
        : showId(id), movie(m), screen(sc), startTime(time) {
        
        // Populate showSeats from physical screen seats
        for (const auto& physicalSeat : sc.getPhysicalSeats()) {
            showSeats.push_back(ShowSeat(physicalSeat));
        }
    }

    int getShowId() const { return this->showId; }
    Movie getMovie() const { return this->movie; }
    Screen getScreen() const { return this->screen; }
    std::string getStartTime() const { return this->startTime; }
    std::vector<ShowSeat>& getShowSeats() { return this->showSeats; }

    void displayLayout() const {
        std::cout << "\n--- SEAT LAYOUT FOR SHOW #" << showId << " (" << movie.getTitle() << ") ---\n";
        for (const auto& ss : showSeats) {
            std::cout << "[" << ss.getSeatNumber() << " | " 
                      << ss.getSeatType() << " | " 
                      << (ss.isAvailable() ? "AVAILABLE" : "BOOKED") << "]  ";
        }
        std::cout << "\n-----------------------------------------------------\n";
    }
};
