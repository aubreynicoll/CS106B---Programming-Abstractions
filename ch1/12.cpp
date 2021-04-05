/* Ch. 1, Exercise 12
 *
 * This program computes the area of a quarter circle, radius of 2, by
 * calculating the area of a series of rectangles whose upper mid-points
 * intersect the arc of the quarter circle.
 * */

#include <iostream>

using namespace std;

const int RADIUS = 2;
const int N_RECTANGLES = 10000;

int main() {
  cout << "This program prints an approximation of the area of a quarter "
          "circle, radius "
       << RADIUS << endl;
  double width = double(RADIUS) / N_RECTANGLES;
  double area = 0.0;

  for (int i = 0; i < N_RECTANGLES; i++) {
    double midpoint = i * width + width / 2;
    double height = sqrt(pow(RADIUS, 2) - pow(midpoint, 2));

    area += height * width;
  }

  cout << "The area is approximately: " << area << endl;
  return 0;
}