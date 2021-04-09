/* Exercise 2.8
 *
 * This program features Gauss's computation of the date of Easter on a given
 * year (1700, 1899). It also includes the 1961 New Scientist version of the
 * algorithm, which works for any year.
 * */

#include <iostream>

#include "error.h"
#include "simpio.h"

void gaussianEaster(int year, int &month, int &date);
void trueEaster(int year, int &month, int &date);

int main() {
  int year = getInteger("Enter a year: ");
  int month = 0, date = 0;

  trueEaster(year, month, date);

  std::cout << "Easter was on " << month << "/" << date << " in " << year << "."
            << std::endl;
  return 0;
}

void gaussianEaster(int year, int &month, int &date) {
  int a = year % 19;
  int b = year % 4;
  int c = year % 7;
  int d = (19 * a + 23) % 30;
  int e = 0;

  if (year >= 1700 && year < 1800) {
    e = (2 * b + 4 * c + 6 * d + 3) % 7;
  } else if (year >= 1800 && year < 1900) {
    e = (2 * b + 4 * c + 6 * d + 4) % 7;
  } else {
    error("Gauss's algorithm only works for years 1700 through 1899.");
  }

  if (d + e > 9) {
    month = 4;
    date = d + e - 9;
  } else {
    month = 3;
    date = 22 + d + e;
  }

  return;
}

void trueEaster(int year, int &month, int &date) {
  int a = year % 19;
  int b = year / 100;
  int c = year % 100;
  int d = b / 4;
  int e = b % 4;
  int g = (8 * b + 13) / 25;
  int h = (19 * a + b - d - g + 15) % 30;
  int i = c / 4;
  int k = c % 4;
  int l = (32 + 2 * e + 2 * i - h - k) % 7;
  int m = (a + 11 * h + 19 * l) / 433;
  month = (h + l - 7 * m + 90) / 25;
  date = (h + l - 7 * m + 33 * month + 19) % 32;

  return;
}