/* Problem 2: Queues
 *
 * This function takes a queue reference and reverses it.
 * */

#include "../Library/common.h"
#include <queue>
#include <stack>

void reverseQueue(queue<int> &q)
{
  stack<int> s;

  while (!q.empty())
  {
    s.push(q.front());
    q.pop();
  }

  while (!s.empty())
  {
    q.push(s.top());
    s.pop();
  }

  return;
}
