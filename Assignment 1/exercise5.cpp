/* Exercise 5: File Processing and Vectors
 *
 * This program reads input from a file given its name from a prompt.
 * The file contains 1 score on each line, where 0 <= score <= 99.
 * ASSUME: The file is well formed.
 * */

#include "../Headers/common.h"
#include <vector>

int main()
{
  // initialize data
  ifstream file;
  vector<int> histogram(10, 0);

  // get filename & open file
  do
  {
    string filename;
    cout << "Enter filename: ";
    getline(cin, filename);
    file.open(filename);
  } while (file.fail());

  // read file and tally histogram
  string line;
  while (getline(file, line))
  {
    int score = stoi(line);
    histogram[score / 10]++;
  }

  // print results
  for (int i = 0; i < histogram.size(); i++)
  {
    cout << i * 10 << "-" << i * 10 + 9 << ": ";
    for (int j = 0; j < histogram[i]; j++)
      cout << "X";
    cout << endl;
  }

  // close file and exit
  file.close();
  return 0;
}