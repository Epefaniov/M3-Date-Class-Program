#include <iostream>
#include "Date.h"

void printTestHeader(const std::string& testName) {
    std::cout << "\n=== " << testName << " ===\n";
}

int main() {
    // Default constructor
    printTestHeader("Test default constructor");
    Date d1;
    std::cout << d1.format1() << std::endl;

    // Valid constructor
    printTestHeader("Test constructor with valid date (2/28/2009)");
    Date d2(2, 28, 2009);
    std::cout << d2.format1() << std::endl;

    // Invalid month
    printTestHeader("Test constructor with invalid month (45, 2, 2009)");
    Date d3(45, 2, 2009);
    std::cout << d3.format1() << std::endl;

    // Invalid day
    printTestHeader("Test constructor with invalid day (2/29/2009)");
    Date d4(2, 29, 2009); // Not a leap year
    std::cout << d4.format1() << std::endl;

    // setDate with invalid month
    printTestHeader("Test setDate with bad month (13, 1, 2020)");
    d1.setDate(13, 1, 2020);
    std::cout << d1.format1() << std::endl;

    // Valid leap year check
    printTestHeader("Leap year check");
    std::cout << "2020 is leap year? " << (d1.isLeapYear(2020) ? "Yes" : "No") << std::endl;
    std::cout << "1900 is leap year? " << (d1.isLeapYear(1900) ? "Yes" : "No") << std::endl;
    std::cout << "2000 is leap year? " << (d1.isLeapYear(2000) ? "Yes" : "No") << std::endl;

    // Display formats
    printTestHeader("Display formats for (12/25/2021)");
    Date d5(12, 25, 2021);
    std::cout << d5.format1() << std::endl;
    std::cout << d5.format2() << std::endl;
    std::cout << d5.format3() << std::endl;

    return 0;
}
