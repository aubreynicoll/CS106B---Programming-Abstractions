/* calendar.h
 *
 * This library offers an enumeration of the months of the year, as well as
 * functions that can provide the name of a month as a string literal, determine
 * a leap year, and state the number of days in a month.
 * */

#ifndef _calendar_h
#define _calendar_h

#include <string>

enum Month {
  JANUARY = 1,
  FEBRUARY,
  MARCH,
  APRIL,
  MAY,
  JUNE,
  JULY,
  AUGUST,
  SEPTEMBER,
  OCTOBER,
  NOVEMBER,
  DECEMBER
};

/* func: monthToString
 *
 * Given a month, this function returns a string literal.
 * */
std::string monthToString(Month month);

/* func: daysInMonth
 *
 * Given a month and a year, this function returns the number of days in the
 * month.
 * */
int daysInMonth(Month month, int year);

/* func: isLeapYear
 *
 * Given a year, returns true if it is a leap year.
 * */
bool isLeapYear(int year);

#endif