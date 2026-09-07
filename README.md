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
<img width="601" height="242" alt="6" src="https://github.com/user-attachments/assets/d8d022be-d7ad-4aee-80c7-f55772689188" />
<img width="624" height="687" alt="5" src="https://github.com/user-attachments/assets/74d8f058-c51c-4c70-8bc7-f8f72844f673" />
<img width="624" height="697" alt="4" src="https://github.com/user-attachments/assets/da92a2b4-1b0f-42e1-b1e2-b5cb1ee9263a" />
<img width="624" height="782" alt="3" src="https://github.com/user-attachments/assets/9e923998-c12b-4b92-95ec-7c143a5fde9c" />
<img width="624" height="605" alt="2" src="https://github.com/user-attachments/assets/fe10598e-f45a-453f-8491-4597edb34b56" />
<img width="624" height="557" alt="1" src="https://github.com/user-attachments/assets/7c0e4881-8ec7-49bb-a8c6-7ad0b4cff663" />



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
