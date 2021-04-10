/* Exercise 2.15
 *
 * This programs simulates flipping a coin and records how long it takes to get
 * N consecutive heads.
 * */

#include <iostream>
#include <random>

const int TARGET_HEADS = 3;

enum CoinFlip { TAILS, HEADS };

CoinFlip flipCoin();

int main() {
  srand(time(NULL));

  std::cout << "This program flips coins. It counts how long it takes to get "
            << TARGET_HEADS << " heads in a row." << std::endl;

  int numFlips = 0;
  int headsInARow = 0;

  while (headsInARow < TARGET_HEADS) {
    CoinFlip flip = flipCoin();

    if (flip == HEADS) {
      std::cout << "HEADS" << std::endl;
      headsInARow++;
    } else {
      std::cout << "TAILS" << std::endl;
      headsInARow = 0;
    }
    numFlips++;
  }

  std::cout << "It took " << numFlips << " flips to get " << TARGET_HEADS
            << " heads in a row." << std::endl;
  return 0;
}

CoinFlip flipCoin() {
  int flipInt = floor(rand() / (double(RAND_MAX) + 1) * 2);
  return CoinFlip(flipInt);
}