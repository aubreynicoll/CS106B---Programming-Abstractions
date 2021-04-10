/* exercise 2.11
 *
 * Using the direction.h interface as an example, design and implement a
 * calendar.h interface that exports the Month type from Chapter 1, along with
 * the functions daysInMonth and isLeapYear, which also appear in that
 * chapter. Your interface should also export a monthToString function that
 * returns the constant name for a value of type Month.
 * */

#include <iostream>

#include "calendar.h"
#include "simpio.h"

int main() {
  std::cout << "This program reads in a year and calculates the number of days "
               "in each month."
            << std::endl;

  int year = getInteger("Enter a year of the common era: ");

  for (int i = JANUARY; i <= DECEMBER; i++) {
    Month month = Month(i);
    std::cout << monthToString(month) << " has " << daysInMonth(month, year)
              << " days." << std::endl;
  }

  return 0;
}