/* Ch. 1, Exercises 6
 *
 * This program continues to read in integers until the sentinel value is given.
 * It then returns the largest and second-largest integers given.
 * */

#include <vector>

#include "myio.h"

using namespace std;

const int SENTINEL = 0;

int main() {
  vector<int> list;

  while (true) {
    int n = getInt("Enter an integer: (0 to quit) ");

    if (n == SENTINEL) break;

    list.push_back(n);
  }

  sort(list.begin(), list.end());

  int largest = list[list.size() - 1];
  int secondLargest = list[list.size() - 2];

  cout << "The largest number was: " << largest
       << " The second largest number was: " << secondLargest << "." << endl;

  return 0;
}