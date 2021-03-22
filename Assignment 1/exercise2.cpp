/* Exercise 2: Vote Simulation
 *
 * This program accepts several parameters related to voting simulation.
 * Given the parameters, it will then simulate 500 outcomes and state the likelihood of an invalid result.
 * */

#include "../Headers/common.h"
#include <random>

int main()
{
  string input;
  int nVoters;
  double pSpread, pError;

  cout << "Enter the number of voters (positive integer): ";
  getline(cin, input);
  nVoters = stoi(input);

  cout << "Enter the percentage spread between candidates (0.0 to 1.0): ";
  getline(cin, input);
  pSpread = stod(input);

  cout << "Enter the percentage of voting error (0.0 to 1.0): ";
  getline(cin, input);
  pError = stod(input);

  return 0;
}