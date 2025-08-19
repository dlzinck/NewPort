CS-210 Project One: Chada Tech Clock Application  
Author: Drew Lane Zinck II  
Date: 07/18/2025
Course: CS-210: Programming Languages  

______________________________________________________________________________________

Overview:  
This program simulates a digital clock for Chada Tech. It displays the current time in both 12-hour (with AM/PM) and 24-hour (military) formats. The user can interact with the program by selecting options from a simple text-based menu to increment the time by one hour, one minute, or one second.

______________________________________________________________________________________

How It Works:  
- Both 12-hour and 24-hour clocks are shown side by side.  
- The user is repeatedly presented with a menu until they choose to exit the program.  
- Time rolls over appropriately:
  - 60 seconds adds 1 minute
  - 60 minutes adds 1 hour
  - 24 hours rolls back to 0  

______________________________________________________________________________________

Menu Options:  
1 - Add One Hour  
2 - Add One Minute  
3 - Add One Second  
4 - Exit Program  

______________________________________________________________________________________

Files Included:  
- `main.cpp` — Contains the main function and menu loop.  
- `Clock.h` — Contains the Clock class declaration.  
- `Clock.cpp` — Contains the Clock class implementation.  
- `README.txt` — Project overview and instructions.  

______________________________________________________________________________________

Notes:  
- This project was written in C++ using object-oriented design.  
- It was tested in both VS Code and OnlineGDB.  
- All time formatting uses two-digit padding (e.g., 09:05:03) for a realistic digital clock display.  
- This program assumes numeric input for menu options.

______________________________________________________________________________________

Thank you for reviewing my project!
