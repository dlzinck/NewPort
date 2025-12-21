// Clock.h
// Author: Drew Lane Zinck II
// Date: 07/18/2025
// Description: Header file for the Clock class used in the CS210 Project One (Chada Tech).
//              Declares class structure and public methods for time and display.

#ifndef CLOCK_H
#define CLOCK_H

// Clock class, a digital clock capable of displaying time in both 12-hour and 24-hour formats.
class Clock {
private:
    int hours;    // Hour value in 24-hour format (0–23)
    int minutes;  // Minute value (0–59)
    int seconds;  // Second value (0–59)

public:
    // Constructor initializes all time values to 0
    Clock();

    // Adds one hour, rolls over to 0 after 23
    void addHour();

    // Adds one minute, increments hour if 60 minutes reached
    void addMinute();

    // Adds one second, increments minute if 60 seconds reached
    void addSecond();

    // Outputs time in 12-hour format (with AM/PM)
    void display12HourClock();

    // Outputs time in 24-hour (military) format
    void display24HourClock();
};

#endif
