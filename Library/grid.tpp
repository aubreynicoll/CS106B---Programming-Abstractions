#include <vector>

using namespace std;

template <typename T>
class Grid {
  vector<vector<T> > grid;
  size_t nRows;
  size_t nCols;

 public:
  Grid(size_t rows, size_t cols);

  size_t numRows();
  size_t numCols();

  T get(size_t row, size_t col);
  void set(size_t row, size_t col, T value);

  void resize(size_t rows, size_t cols);
  void clear();
  void print();
};

template <typename T>
Grid<T>::Grid(size_t rows, size_t cols) {
  this->resize(rows, cols);
}

template <typename T>
size_t Grid<T>::numRows() {
  return this->nRows;
}

template <typename T>
size_t Grid<T>::numCols() {
  return this->nCols;
}

template <typename T>
T Grid<T>::get(size_t row, size_t col) {
  if ((0 <= row && row < this->nRows) && (0 <= col && col < this->nCols)) {
    return this->grid[row][col];
  } else {
    cout << "ERROR: out of bounds" << endl;
    exit(EXIT_FAILURE);
  }
}

template <typename T>
void Grid<T>::set(size_t row, size_t col, T value) {
  if ((0 <= row && row < this->nRows) && (0 <= col && col < this->nCols)) {
    this->grid[row][col] = value;
  } else {
    cout << "ERROR: out of bounds" << endl;
    exit(EXIT_FAILURE);
  }
}

template <typename T>
void Grid<T>::resize(size_t rows, size_t cols) {
  this->nRows = rows;
  this->nCols = cols;

  this->grid.resize(rows);
  for (int i = 0; i < rows; i++) {
    this->grid[i].resize(cols);
  }
}

template <typename T>
void Grid<T>::clear() {
  this->nRows = 0;
  this->nCols = 0;

  this->grid.clear();
}

template <typename T>
void Grid<T>::print() {
  for (int i = 0; i < this->nRows; i++) {
    for (int j = 0; j < this->nCols; j++) {
      cout << this->get(i, j) << " ";
    }
    cout << endl;
  }
}