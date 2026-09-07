# Movie Ticket Booking System

A modular, menu-driven low-level system design (LLD) project for a Movie Ticket Booking System built in object-oriented C++.

## Project Overview
This application simulates a real-world cinema ticket booking platform. It allows users to browse active movies, view show schedules and interactive seat layouts, calculate tier-based pricing, process payments, and manage booking cancellations.

## Key Features
* **Movie & Show Management:** Browse playing movies and show schedules across screens.
* **Interactive Seat Layout:** Visual representation of seats ( Available / Booked).
* **Tier-Based Pricing:** Automatic pricing for Silver, Gold, and Platinum seat categories.
* **Polymorphic Payments:** Supports UPI, Card, and Cash payment methods with error handling.
* **Ticket Generation:** Auto-generates structured tickets with unique Booking IDs.
* **Booking Cancellation:** Cancel active bookings and automatically release seats back to the available pool.

## Design & Architecture
* **SOLID Principles:** Decoupled business logic, polymorphic interfaces, and dependency inversion.
* **OOP Concepts:** Encapsulation, Abstraction, Inheritance, Runtime Polymorphism, Static Members, and `this` pointer usage.
* **Entity Relationships:** Lifetime management using Composition (`Cinema` → `Screen`) and Aggregation (`Show` → `Movie`).

CLASS DIAGRAM:
<img width="2560" height="1662" alt="class diagram" src="https://github.com/user-attachments/assets/873697cd-da02-44c9-b0ea-af59ad8703a5" />

SEQUENCED DIAGRAM:
<img width="2560" height="1518" alt="sequenced diagram" src="https://github.com/user-attachments/assets/a32a3ee5-3958-4cd8-bf27-d37e99edb48d" />

OUTPUTS:
<img width="624" height="557" alt="1" src="https://github.com/user-attachments/assets/56f18999-41b4-42ad-bc1c-5aae320b6392" />
<img width="624" height="605" alt="2" src="https://github.com/user-attachments/assets/8d818660-a4d8-4c44-b500-e2cd3a0660f6" />
<img width="624" height="782" alt="3" src="https://github.com/user-attachments/assets/f0cbadf8-b346-496e-a4c8-45cc27a40dd9" />
<img width="624" height="697" alt="4" src="https://github.com/user-attachments/assets/550b1f56-0372-4c96-b8a9-5f7f3f72984c" />
<img width="624" height="687" alt="5" src="https://github.com/user-attachments/assets/ac8c7292-f7c1-45b5-94bf-36425695179a" />
<img width="601" height="242" alt="6" src="https://github.com/user-attachments/assets/7ab3299b-f48a-49cd-a89b-b5876a19d394" />

## File Structure
```text
├── 01_Movie.cpp
├── 02_Seat.cpp
├── 03_Screen.cpp
├── 04_Cinema.cpp
├── 05_Show.cpp
├── 06_ShowSeat.cpp
├── 07_Customer.cpp
├── 08_Booking.cpp
├── 09_Payment.cpp
├── 10_PaymentTypes.cpp
├── 11_PriceCalculator.cpp
├── 12_TicketPrinter.cpp
├── 13_BookingService.cpp
├── main.cpp
├── .gitignore
└── README.md
