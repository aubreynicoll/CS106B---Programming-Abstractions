/* Prime Number Finder
 * 
 * This program allows input of a number, and will print true if that number is perfect (e.g. is the equal to the sum of its divisors).
 */

#include <iostream>
#include <string>

using namespace std;

bool isPerfect(int n);

int main()
{
  for (int i = 1; i <= 10000; i++)
  {
    if (isPerfect(i))
      cout << i << endl;
  }
}

bool isPerfect(int n)
{
  int sum = 0;
  for (int i = 1; i <= n / 2; i++)
  {
    if (n % i == 0)
      sum += i;
  }
  return n == sum;
}