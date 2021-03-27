/* Exercise 3: Using the Scanner and Stack Classes
 *
 * This program reads in an HTML file and determines if the HTML is properly
 * nested. ASSUME: The HTML tags are all well-formed and there are no erroneous
 * angle brackets. ALSO: The tags are not self-closing. E.g. No <hr> or <div />
 * nonsense.
 * */

#include <stack>

#include "../Library/common.h"
#include "../Library/tokenscanner.h"

bool isCorrectlyNested(string htmlString);

int main() {
  string input;
  bool result = false;

  cout << "Enter a string: ";
  getline(cin, input);

  result = isCorrectlyNested(input);

  cout << result << endl;
  return 0;
}

bool isCorrectlyNested(string htmlString) {
  TokenScanner scanner;
  scanner.ignoreWhitespace();
  scanner.setInput(htmlString);

  stack<string> stack;
  bool isTag = false, isClosingTag = false;

  while (scanner.hasMoreTokens()) {
    string token = scanner.nextToken();

    if (token == "<") {
      isTag = true;
    } else if (isTag && token == "/") {
      isTag = false;
      isClosingTag = true;
    } else if (token == ">") {
      isTag = isClosingTag = false;
    } else if (isTag) {
      stack.push(token);
    } else if (isClosingTag) {
      if (stack.top() == token) stack.pop();
    }
  }

  return stack.empty();
}
