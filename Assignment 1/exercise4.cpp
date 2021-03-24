/* Exercise 4: Strings
 *
 * This program converts a surname into a Soundex code.
 * */

#include "../Headers/common.h"
#include <map>

string getSoundexCode(string name);
map<char, char> getCharMap(void);
void addFirst(string &s, string name);
void convertRest(string &s, string name);
void removeConsecutiveDupes(string &s);
void removeZeros(string &s);
void formatCode(string &s);

int main()
{
  string name, code;
  while (true)
  {
    cout << "Enter a surname (BLANK to exit): ";
    getline(cin, name);
    if (name == "")
      break;
    code = getSoundexCode(name);
    cout << "Code is: " << code << endl;
  }

  cout << "Goodbye!" << endl;
  return 0;
}

string getSoundexCode(string name)
{
  string code;

  addFirst(code, name);
  convertRest(code, name);
  removeConsecutiveDupes(code);
  removeZeros(code);
  formatCode(code);

  return code;
}

map<char, char> getCharMap()
{
  map<char, char> charMap;

  charMap['A'] = '0';
  charMap['B'] = '1';
  charMap['C'] = '2';
  charMap['D'] = '3';
  charMap['E'] = '0';
  charMap['F'] = '1';
  charMap['G'] = '2';
  charMap['H'] = '0';
  charMap['I'] = '0';
  charMap['J'] = '2';
  charMap['K'] = '2';
  charMap['L'] = '5';
  charMap['M'] = '4';
  charMap['N'] = '4';
  charMap['O'] = '0';
  charMap['P'] = '1';
  charMap['Q'] = '2';
  charMap['R'] = '6';
  charMap['S'] = '2';
  charMap['T'] = '3';
  charMap['U'] = '0';
  charMap['V'] = '1';
  charMap['W'] = '0';
  charMap['X'] = '2';
  charMap['Y'] = '0';
  charMap['Z'] = '2';

  return charMap;
}

void addFirst(string &s, string name)
{
  s = toupper(name[0]);
  return;
}

void convertRest(string &s, string name)
{
  map<char, char> charMap = getCharMap();

  for (int i = 1; i < name.length(); i++)
  {
    char curr = toupper(name[i]);
    if (curr >= 'A' && curr <= 'Z')
      s += charMap[curr];
  }

  return;
}

void removeConsecutiveDupes(string &s)
{
  for (int i = 1; i < s.length(); i++)
  {
    if (s[i] == s[i - 1])
      s.erase(i--, 1);
  }

  return;
}

void removeZeros(string &s)
{
  int index = 0;
  while ((index = s.find('0', index)) != string::npos)
    s.erase(index, 1);

  return;
}

void formatCode(string &s)
{
  if (s.length() < 4)
  {
    s.insert(s.length(), 4 - s.length(), '0');
  }
  else if (s.length() > 4)
  {
    s.erase(4);
  }

  return;
}