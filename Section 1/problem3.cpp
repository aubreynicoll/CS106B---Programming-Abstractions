/* Problem 3: Vectors
 *
 * This program contains a function countLetters that takes a filename and 
 * prints the number of occurances of each letter, case-insensitive.
 * */

#include "../Headers/common.h"
#include <vector>

void countLetters(string filename);

int main()
{
  countLetters("text.txt");
  return 0;
}

void countLetters(string filename)
{
  // open the file...
  ifstream in;
  try
  {
    in.open(filename);
    if (in.fail())
      throw 1;
  }
  catch (int e)
  {
    cout << "error: " << e << endl;
    return;
  }

  // initialize and loop through the file...
  vector<int> count(26, 0);
  string line;
  while (getline(in, line))
  {
    // read each char and increment indices appropriately...
    for (int i = 0; i < line.length(); i++)
    {
      char c = tolower(line[i]);
      if (c >= 'a' && c <= 'z')
        count[c - 'a']++;
    }
  }

  // print results...
  for (int i = 0; i < count.size(); i++)
  {
    cout << char('a' + i) << ": " << count[i] << endl;
  }

  in.close();
  return;
}