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
