/* calendar.cpp
 *
 * This library offers an enumeration of the months of the year, as well as
 * functions that can provide the name of a month as a string literal, determine
 * a leap year, and state the number of days in a month.
 * */

#include "calendar.h"

#include "error.h"

using namespace std;

string monthToString(Month month) {
  switch (month) {
    case JANUARY:
      return "JANUARY";
    case FEBRUARY:
      return "FEBRUARY";
    case MARCH:
      return "MARCH";
    case APRIL:
      return "APRIL";
    case MAY:
      return "MAY";
    case JUNE:
      return "JUNE";
    case JULY:
      return "JULY";
    case AUGUST:
      return "AUGUST";
    case SEPTEMBER:
      return "SEPTEMBER";
    case OCTOBER:
      return "OCTOBER";
    case NOVEMBER:
      return "NOVEMBER";
    case DECEMBER:
      return "DECEMBER";
    default:
      error("Not a month.");
  }
}

int daysInMonth(Month month, int year) {
  switch (month) {
    case APRIL:
    case JUNE:
    case SEPTEMBER:
    case NOVEMBER:
      return 30;
    case FEBRUARY:
      return (isLeapYear(year)) ? 29 : 28;
    default:
      return 31;
  }
}

bool isLeapYear(int year) {
  return ((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0);
}