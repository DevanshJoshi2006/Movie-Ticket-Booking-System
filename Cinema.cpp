#include <iostream>
#include <vector>
#include <string>
#include "Screen.cpp"

// Cinema Class: Manages auditorium screens
// OOP Concept Demonstrated: Composition (Cinema owns Screen objects)
class Cinema {
private:
    std::string name;
    std::vector<Screen> screens; // Composition relationship

public:
    Cinema(std::string n = "Grand Cinema") {
        this->name = n;
        // Composition: Cinema creates and owns Screen objects
        screens.push_back(Screen(1));
        screens.push_back(Screen(2));
    }

    std::string getName() const { return this->name; }
    const std::vector<Screen>& getScreens() const { return this->screens; }
};
