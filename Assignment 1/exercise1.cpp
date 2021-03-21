/* Prime Number Finder
 * 
 * This program allows input of a number, and will print true if that number is prime.
 */

#include <iostream>
#include <string>

using namespace std;

bool isPrime(int n);
int getInt(void);

int main()
{
  cout << "Enter a number: ";
  int n = getInt();
  string result = isPrime(n) ? "true" : "false";
  cout << result << endl;
  return 0;
}

bool isPrime(int n)
{
  for (int i = 2; i <= n / 2; i++)
  {
    if (n % i == 0)
      return false;
  }
  return true;
}

int getInt()
{
  string s;
  cin >> s;
  return stoi(s);
}