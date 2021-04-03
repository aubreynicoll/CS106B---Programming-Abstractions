/* Problem 2: Files & Structs
 *
 * This program reads scores from a text file, where 0 <= score <= 100.
 * It then saves these scores as a struct.
 * Assumes there is one score per line.
 * */

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

struct scoresT
{
  int min;
  int max;
  double avg;
};

scoresT readScores(string filename);

int main()
{
  scoresT score = readScores("scores.txt");

  cout << "min: " << score.min << endl;
  cout << "max: " << score.max << endl;
  cout << "avg: " << score.avg << endl;

  return 0;
}

scoresT readScores(string filename)
{
  scoresT scores;
  ifstream in;

  try
  {
    in.open(filename);
    if (in.fail())
      throw 1;
  }
  catch (int e)
  {
    cout << "Error: " << e << endl;
  }

  string line;
  int sum = 0, nOfScores = 0;
  scores.min = 100;
  while (getline(in, line))
  {
    int score = stoi(line);
    scores.min = score < scores.min ? score : scores.min;
    scores.max = score > scores.max ? score : scores.max;
    sum += score;
    nOfScores++;
  }

  scores.avg = (double)sum / nOfScores;

  in.close();

  return scores;
}