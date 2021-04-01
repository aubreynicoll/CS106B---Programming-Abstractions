/* Problem 5: Minesweeper
 *
 * This program contains a function that takes a reference to a matrix<bool>,
 * and returns a matrix<int> where int is the number of true values within a
 * radius of 1.
 * */

#include <random>

#include "../Library/common.h"
#include "../Library/grid.tpp"

Grid<bool> makeRandomGridOfBombs(size_t maxRows, size_t maxCols);
Grid<int> makeGridOfCounts(Grid<bool> &bombLocations);

int main() {
  srand(time(0));

  Grid<bool> bombGrid = makeRandomGridOfBombs(10, 10);
  bombGrid.print();

  for (int i = 0; i < bombGrid.numCols(); i++) cout << "-";
  cout << endl;

  Grid<int> countGrid = makeGridOfCounts(bombGrid);
  countGrid.print();

  return 0;
}

Grid<bool> makeRandomGridOfBombs(size_t maxRows, size_t maxCols) {
  size_t numRows = rand() % maxRows + 1;
  size_t numCols = rand() % maxCols + 1;

  Grid<bool> bombGrid(numRows, numCols);

  for (int row = 0; row < numRows; row++) {
    for (int col = 0; col < numCols; col++) {
      bombGrid.set(row, col, rand() % 2);
    }
  }
  return bombGrid;
}

Grid<int> makeGridOfCounts(Grid<bool> &bombLocations) {
  Grid<int> countGrid(bombLocations.numRows(), bombLocations.numCols());

  // for every cell in matrix...
  for (int row = 0; row < countGrid.numRows(); row++) {
    for (int col = 0; col < countGrid.numCols(); col++) {
      // count local bombs
      int localBombs = 0;
      for (int localRow = row - 1; localRow <= row + 1; localRow++) {
        for (int localCol = col - 1; localCol <= col + 1; localCol++) {
          // check bounds
          if (localRow < 0 || localRow >= bombLocations.numRows() ||
              localCol < 0 || localCol >= bombLocations.numCols()) {
            continue;
          } else if (bombLocations.get(localRow, localCol)) {
            localBombs++;
          }
        }
      }
      countGrid.set(row, col, localBombs);
    }
  }
  return countGrid;
}
