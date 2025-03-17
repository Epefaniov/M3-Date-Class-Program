#include "Date.h"
#include <iostream>
#include <sstream>

static const std::string MONTH_NAMES[13] = {
    "", "January", "February", "March", "April", "May", "June",
    "July", "August", "September", "October", "November", "December"
};

Date::Date(int m, int d, int y) {
    setDate(m, d, y);
}

bool Date::isValidDate(int m, int d, int y) {
    if (m < 1 || m > 12) return false;
    int maxDay = lastDay(m, y);
    return d >= 1 && d <= maxDay;
}

void Date::setDate(int m, int d, int y) {
    if (isValidDate(m, d, y)) {
        month = m;
        day = d;
        year = y;
    } else {
        std::cout << "Invalid date provided. Resetting to default (1/1/1900)." << std::endl;
        month = 1;
        day = 1;
        year = 1900;
    }
}

bool Date::isLeapYear() const {
    return isLeapYear(year);
}

bool Date::isLeapYear(int y) const {
    return (y % 4 == 0 && y % 100 != 0) || (y % 400 == 0);
}

int Date::lastDay() const {
    return lastDay(month, year);
}

int Date::lastDay(int m, int y) const {
    switch (m) {
        case 1: case 3: case 5: case 7: case 8: case 10: case 12: return 31;
        case 4: case 6: case 9: case 11: return 30;
        case 2: return isLeapYear(y) ? 29 : 28;
        default: return 0;
    }
}

std::string Date::format1() const {
    std::ostringstream oss;
    oss << month << "/" << day << "/" << year;
    return oss.str();
}

std::string Date::format2() const {
    std::ostringstream oss;
    oss << MONTH_NAMES[month] << " " << day << ", " << year;
    return oss.str();
}

std::string Date::format3() const {
    std::ostringstream oss;
    oss << day << " " << MONTH_NAMES[month] << " " << year;
    return oss.str();
}
