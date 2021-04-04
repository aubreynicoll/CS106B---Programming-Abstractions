/* Ch. 1, Exercise 7
 *
 * This program reads in a list of integers representing exam scores, then
 * produces the average.
 * ASSUME: An exam could be scored 0 through 100.
 * */

#include <vector>

#include "myio.h"

using namespace std;

const int SENTINEL = -1;

void getUserInput(vector<int> &scores);
double computeAverage(vector<int> &scores);

int main() {
  vector<int> scores;
  double average = 0.0;

  getUserInput(scores);
  average = computeAverage(scores);

  cout << "The average score was: " << average << endl;

  return 0;
}

void getUserInput(vector<int> &scores) {
  while (true) {
    int n = getInt();

    if (n == SENTINEL) break;

    scores.push_back(n);
  }
  return;
}

double computeAverage(vector<int> &scores) {
  int sum = 0;

  for (int i = 0; i < scores.size(); i++) {
    sum += scores[i];
  }

  return double(sum) / scores.size();
}