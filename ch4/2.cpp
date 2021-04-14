/* Exercise 4.2
 *
 * This program prints a table of windchill factors.
 * */

#include <iomanip>
#include <iostream>

#include "error.h"
#include "simpio.h"

using namespace std;

double getWindChill(double temp, double windspeed);
void printTable();

int main() {
  printTable();
  return 0;
}

double getWindChill(double temp, double windspeed) {
  if (windspeed < 5) return temp;
  if (temp > 40) {
    error("Windchill undefined for temperatures above 40 F.");
  }
  return 35.74 + 0.6215 * temp - 35.75 * pow(windspeed, 0.16) +
         0.4275 * temp * pow(windspeed, 0.16);
}

void printTable() {
  cout << right << fixed << setprecision(0);
  for (int windspeed = 0; windspeed <= 60; windspeed += 5) {
    cout << setw(4) << windspeed;
    for (int temp = 40; temp >= -45; temp -= 5) {
      cout << setw(4) << getWindChill(temp, windspeed);
    }
    cout << endl;
  }
  return;
}