// Clock.cpp
// Author: Drew Lane Zinck II
// Date: 07/18/2025
// Description: Implements the Clock class methods for time and display formatting.

#include <iostream>
#include <iomanip>
#include "Clock.h"
using namespace std;

// Constructor: Initialize all values to zero (midnight)
Clock::Clock() {
    hours = 0;
    minutes = 0;
    seconds = 0;
}

// Add one hour to current time; wrap around to 0 after 23
void Clock::addHour() {
    hours = (hours + 1) % 24;
}

// Add one minute to current time; reset to 0 and adds hour if 60 is reached
void Clock::addMinute() {
    minutes++;
    if (minutes >= 60) {
        minutes = 0;
        addHour(); // Handle hour rollover
    }
}

// Add one second to current time; reset to 0 and adds minute if 60 is reached
void Clock::addSecond() {
    seconds++;
    if (seconds >= 60) {
        seconds = 0;
        addMinute(); // Handle minute rollover
    }
}

// Format and display the current time in 12-hour format with AM/PM
void Clock::display12HourClock() {
    int displayHour = hours % 12;
    if (displayHour == 0) displayHour = 12;
    string period = (hours >= 12) ? "PM" : "AM";

    cout << setw(2) << setfill('0') << displayHour << ":"
         << setw(2) << minutes << ":" << setw(2) << seconds << " " << period;
}

// Format and display the current time in 24-hour (military) format
void Clock::display24HourClock() {
    cout << setw(2) << setfill('0') << hours << ":"
         << setw(2) << minutes << ":" << setw(2) << seconds;
}
