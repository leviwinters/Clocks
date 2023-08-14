/*
 * CS 210 Chada Tech Clocks
 * 
 * Date: 7/7/2023
 * Author: Levi Winters
 */

#include <iostream>

#include <string>

#include <cstdlib>

using namespace std;

class Clock {
private: unsigned int hour;
       unsigned int minute;
       unsigned int second;

       // Helper function that takes a number and converts it into a two-digit string
       string twoDigitString(unsigned int n) {
           if (n < 10) {
               return "0" + to_string(n);
           }
           else if (n <= 59) {
               return to_string(n);
           }
           return "";
       }

public:
    // Constructor method that sets the initial clock values
    Clock(unsigned int h, unsigned int m, unsigned int s) {
        hour = h;
        minute = m;
        second = s;
    }

    // Setter methods to update the hour, minute, and second values
    void setHour(unsigned int h) {
        hour = h;
    }

    void setMinute(unsigned int m) {
        minute = m;
    }

    void setSecond(unsigned int s) {
        second = s;
    }

    // Getter methods to retrieve the hour, minute, and second values
    unsigned int getHour() {
        return hour;
    }

    unsigned int getMinute() {
        return minute;
    }

    unsigned int getSecond() {
        return second;
    }

    // Display the time in 24 hour format (hh:mm:ss)
    string formatTime24() {
        string hourStr = twoDigitString(hour);
        string minuteStr = twoDigitString(minute);
        string secondStr = twoDigitString(second);

        return hourStr + ":" + minuteStr + ":" + secondStr;
    }

    // Display the time in 12 hour format (hh:mm:ss A M or hh:mm:ss P M)
    string formatTime12() {
        unsigned int hour12 = hour % 12;
        if (hour12 == 0) {
            hour12 = 12;
        }

        string timePeriod = (hour < 12) ? "A M" : "P M";
        string hourStr = twoDigitString(hour12);
        string minuteStr = twoDigitString(minute);
        string secondStr = twoDigitString(second);

        return hourStr + ":" + minuteStr + ":" + secondStr + " " + timePeriod;
    }

    // Adds one hour
    void addOneHour() {
        if (hour >= 0 && hour < 23) {
            hour += 1;
        }
        else if (hour == 23) {
            hour = 0;
        }

        system("cls"); // Clears the console
        displayClocks();
    }

    // Adds one minute
    void addOneMinute() {
        if (minute >= 0 && minute < 59) {
            minute += 1;
        }
        else if (minute == 59) {
            minute = 0;
            addOneHour();
        }

        system("cls"); // Clears the console
        displayClocks();
    }

    // Adds one second
    void addOneSecond() {
        if (second >= 0 && second <= 58) {
            second += 1;
        }
        else if (second == 59) {
            second = 0;
            addOneMinute();
        }

        system("cls"); // Clears the console
        displayClocks();
    }

    // Display the 12 hour and 24 hour clock formats
    void displayClocks() {
        cout << string(27, '*') << string(3, ' ') << string(27, '*') << endl;
        cout << "*" << string(6, ' ') << "12-Hour Clock" << string(6, ' ') << "*" << string(3, ' ');
        cout << "*" << string(6, ' ') << "24-Hour Clock" << string(6, ' ') << "*" << endl;
        cout << endl;
        cout << "*" << string(6, ' ') << formatTime12() << string(7, ' ') << "*" << string(3, ' ');
        cout << "*" << string(8, ' ') << formatTime24() << string(9, ' ') << "*" << endl;
        cout << string(27, '*') << string(3, ' ') << string(27, '*') << endl;
    }
};

int main() {
    Clock clock(0, 0, 0); // Create a Clock object and initialize it

    clock.displayClocks();

    cout << "Enter 1 to open the menu: ";

    unsigned int choice;
    cin >> choice;

    if (choice != 1) {
        cout << "Invalid choice." << endl;
        return 0;
    }

    while (true) {
        cout << string(27, '*') << endl;
        cout << "*" << " " << "1 - Add One Hour" << string(8, ' ') << "*" << endl;
        cout << "*" << " " << "2 - Add One Minute" << string(6, ' ') << "*" << endl;
        cout << "*" << " " << "3 - Add One Second" << string(6, ' ') << "*" << endl;
        cout << "*" << " " << "4 - Exit Program" << string(8, ' ') << "*" << endl;
        cout << string(27, '*') << endl;

        cin >> choice; // Read the user's choice

        switch (choice) {
        case 1:
            clock.addOneHour();
            break;
        case 2:
            clock.addOneMinute();
            break;
        case 3:
            clock.addOneSecond();
            break;
        case 4:
            return 0; // Program is terminated when the user chooses option 4
        default:
            cout << "Invalid choice." << endl;
        }
    }

    return 0;
}