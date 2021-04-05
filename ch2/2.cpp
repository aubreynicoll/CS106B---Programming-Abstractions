/* Ch. 2, Exercise 2
 *
 * This program reimplements the meters to feet & inches conversion of Ch. 1 Ex.
 * 2, but with the stipulation that one must pass by reference.
 * */

#include <iostream>
#include <sstream>
#include <string>

#include "myio.h"

using namespace std;

const double METERS_PER_INCH = 0.0254;
const int INCHES_PER_FOOT = 12;

void meters2finches(double meters, int &feet, int &inches);

int main() {
  double meters = getDouble("Input a value in meters: ");
  int feet = 0;
  int inches = 0;

  meters2finches(meters, feet, inches);

  cout << meters << " meters in feet and inches is: " << feet << "'" << inches
       << "\"" << endl;

  return 0;
}

void meters2finches(double meters, int &feet, int &inches) {
  double totalInches = meters / METERS_PER_INCH;
  feet = int(totalInches) / INCHES_PER_FOOT;
  inches = int(totalInches) % INCHES_PER_FOOT;
  return;
}