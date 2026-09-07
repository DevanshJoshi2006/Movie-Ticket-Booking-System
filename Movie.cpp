#include <iostream>
#include <string>

// Movie Class: Represents movie details
// OOP Concept Demonstrated: Encapsulation (private members, public getters)
class Movie {
private:
    std::string title;
    std::string language;
    int durationMinutes;

public:
    Movie(std::string t = "", std::string lang = "", int dur = 0) {
        this->title = t;            // OOP Concept: 'this' keyword
        this->language = lang;
        this->durationMinutes = dur;
    }

    std::string getTitle() const { return this->title; }
    std::string getLanguage() const { return this->language; }
    int getDuration() const { return this->durationMinutes; }

    void displayInfo() const {
        std::cout << "Movie: " << this->title << " | Lang: " << this->language 
                  << " | Duration: " << this->durationMinutes << " mins\n";
    }
};
