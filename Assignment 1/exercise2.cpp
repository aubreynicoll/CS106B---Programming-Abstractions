/* Exercise 2: Vote Simulation
 *
 * This program accepts several parameters related to voting simulation.
 * Given the parameters, it will then simulate 500 outcomes and state the likelihood of an invalid result.
 * The program assumes that Candidate A is ahead, and therefore calculates an invalid trial when A loses to B.
 * */

#include "../Headers/common.h"
#include <random>

#define NUMBER_OF_TRIALS 500

int main()
{
  string input;
  int nVoters;
  double pSpread, pError;

  do
  {
    cout << "Enter the number of voters (positive integer): ";
    getline(cin, input);
    nVoters = stoi(input);
  } while (nVoters < 1);

  do
  {
    cout << "Enter the percentage spread between candidates (0.0 to 1.0): ";
    getline(cin, input);
    pSpread = stod(input);
  } while (pSpread < 0.0 || pSpread > 1.0);

  do
  {
    cout << "Enter the percentage of voting error (0.0 to 1.0): ";
    getline(cin, input);
    pError = stod(input);
  } while (pSpread < 0.0 || pSpread > 1.0);

  int nInvalid = 0;
  for (int i = 0; i < NUMBER_OF_TRIALS; i++)
  {
    int votesA = nVoters * (.5 + pSpread / 2.0);
    int votesB = nVoters * (.5 - pSpread / 2.0);

    int errorsA = 0, errorsB = 0;

    for (int vote = 0; vote < votesA; vote++)
    {
      if (double(rand()) / (double(RAND_MAX) + 1.0) < pError)
        errorsA++;
    }

    for (int vote = 0; vote < votesB; vote++)
    {
      if (double(rand()) / (double(RAND_MAX) + 1.0) < pError)
        errorsB++;
    }

    votesA = votesA - errorsA + errorsB;
    votesB = votesB - errorsB + errorsA;

    if (votesA < votesB)
      nInvalid++;
  }

  cout << "Chance of Invalid Trial: " << double(nInvalid) / double(NUMBER_OF_TRIALS) * 100.0 << endl;

  return 0;
}