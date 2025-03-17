#ifndef DATE_H
#define DATE_H

#include <string>

class Date {
private:
    int month;
    int day;
    int year;

    bool isValidDate(int m, int d, int y);

public:
    Date(int m = 1, int d = 1, int y = 1900);

    // Mutator
    void setDate(int m, int d, int y);

    // Accessors
    int getMonth() const { return month; }
    int getDay() const { return day; }
    int getYear() const { return year; }

    // Leap year checkers
    bool isLeapYear() const;
    bool isLeapYear(int y) const;

    // Last day functions
    int lastDay() const;
    int lastDay(int m, int y) const;

    // Print formats
    std::string format1() const; // mm/dd/yyyy
    std::string format2() const; // MonthName dd, yyyy
    std::string format3() const; // dd MonthName yyyy
};

#endif


