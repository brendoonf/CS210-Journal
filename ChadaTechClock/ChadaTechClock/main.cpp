/*Brenden Fowler  */
#include <iostream>
#include <sstream>
#include <string>
using namespace std;
int hour = 0;
int hour24 = 0;
int minute = 0;
int second = 0;
string AmPm;

std::string repeatAsterisk(int count) {
    return string(count, '*'); // Asterisks for clock and menu output
}
string formatTwoDigits(int number) { //Formats time to have a zero infront of it depending on the number
    if (number < 10) {
        return "0" + to_string(number);
    }
    else {
        return to_string(number);
    }

}

int processUserInput() { // gets user input for menu choice
    int choice;
    cin >> choice;
    return choice;

}

void printClock12(int hour, int minute, int second) { //prints clock in 12 hour format
    cout << repeatAsterisk(26) << endl;
    cout << repeatAsterisk(1) << "     12-Hour Clock      " << repeatAsterisk(1) << endl;
    if (hour > 12) {
        hour = hour - 12;     //if hour is greater than 12, 12 is subtracted from the hour

    }
    cout << repeatAsterisk(1) << "     " << (formatTwoDigits(hour)) << ":" << (formatTwoDigits(minute)) << ":" << (formatTwoDigits(second)) <<  " " << AmPm << "      " << repeatAsterisk(1) << endl;
    cout << repeatAsterisk(26) << endl;
}

void printClock24(int& hour24, int minute, int second) {  //prints clock in 24 hour format
    cout << repeatAsterisk(26) << endl;
    cout << repeatAsterisk(1) << "     24-Hour Clock      " << repeatAsterisk(1) << endl;
    if (hour >= 24) {
        hour = 0;               //if hour is 24 or greater, it is reset to 0
    }
    cout << repeatAsterisk(1) << "       " << (formatTwoDigits(hour)) << ":" << (formatTwoDigits(minute)) << ":" << (formatTwoDigits(second)) << "         " << repeatAsterisk(1) << endl;
    cout << repeatAsterisk(26) << endl;
}

void printMenu() {       //prints menu
    cout << repeatAsterisk(26) << endl;
    cout << repeatAsterisk(1) << " 1 - Add One Hour       " << repeatAsterisk(1) << endl;
    cout << repeatAsterisk(1) << " 2 - Add One Minute     " << repeatAsterisk(1) << endl;
    cout << repeatAsterisk(1) << " 3 - Add One Second     " << repeatAsterisk(1) << endl;
    cout << repeatAsterisk(1) << " 4 - Exit Program       " << repeatAsterisk(1) << endl;
    cout << repeatAsterisk(26) << endl;
}


void addHour() {         //adds one hour to time
    hour = hour + 1;
}

void addMinute() {       //adds one minute to time, and if the time is 59 before adding, it is reset to 0
    if (minute == 59) {
        minute = -1;
    }
    minute = minute + 1;
}

void addSecond() {      //adds one second to time, and if the time is 59 before adding, it is reset to 0
    if (second == 59) {
        second = -1;
    }
    second = second + 1;
}

int main() {
    int op = 0;
    cout << "Enter current time: " << endl;
    cin >> hour >> minute >> second;
    cout << "A.M. or P.M.? ";
    cin >> AmPm;
    printMenu();
    printClock12(hour, minute, second);
    printClock24(hour, minute, second);
    while (op != 4) {           //got confused on the menu loop here, found that this works online
        op = processUserInput();
        switch (op) {
        case 1:
            addHour();
            printClock12(hour, minute, second);
            printClock24(hour, minute, second);
            break;
        case 2:
            addMinute();
            printClock12(hour, minute, second);
            printClock24(hour, minute, second);
            break;
        case 3:
            addSecond();
            printClock12(hour, minute, second);
            printClock24(hour, minute, second);
            break;
        case 4:
            break;
        }
    }
}
