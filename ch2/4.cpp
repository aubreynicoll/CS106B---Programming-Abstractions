/* Ch. 2, Exercise 4
 *
 * This program contains a function to compute the windchill factor, given a
 * temperature in fahrenheit and a windspeed in mph.
 * */

#include <iostream>

#include "error.h"
#include "simpio.h"

using namespace std;

double getWindChill(double temp, double windspeed);

int main() {
  double temp = getReal("Enter a temperature: ");
  double windspeed = getReal("Enter a windspeed: ");

  double windchill = getWindChill(temp, windspeed);

  cout << "The windchill factor is: " << windchill << endl;

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