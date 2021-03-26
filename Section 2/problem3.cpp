/* Exercise 3: Using the Scanner and Stack Classes
 *
 * This program reads in an HTML file and determines if the HTML is properly nested.
 * ASSUME: The HTML tags are all well-formed and there are no erroneous angle brackets.
 * ALSO: The tags are not self-closing. E.g. No <hr> or <div /> nonsense.
 * */

#include "../Library/common.h"
#include "../Library/tokenscanner.h"
#include <stack>

bool isCorrectlyNested(ifstream &file)
{

  return true;
}

int main()
{
  ifstream file;
  do
  {
    string filename;
    cout << "Enter filename: ";
    getline(cin, filename);
    file.open(filename);
  } while (file.fail());

  return 0;
}