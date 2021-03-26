/* 
Problem 1: Vectors (AKA C++ ArrayLists…)

Say we are writing the next version of a nifty new mail reading program and want to use
a Vector (interface in reader appendix) to store all the data. The following structure is
used to hold the data of an email message:

struct eMailMsg {
  string to; // i.e. "professor@stanford.edu"
  string from; // i.e. "student@stanford.edu"
  string message; // body of message
  string subject; // i.e. "CS106 Rocks!"
  int date; // date email was sent
  int time; // time email was sent
};

a) How would you declare a Vector that stores eMailMsgs?

b) Write a function RemoveSpam that takes a vector containing elements of type
eMailMsg and removes all elements whose subject begins with the string "SPAM".

c) How could you modify the to field of the eMailMsg structure so that it can hold the
email addresses of an arbitrary number of recipients of an email? With the modification
in place, given an eMailMsg email, how would you access the last address listed in the
to field?
*/

#include "../Library/common.h"
#include <vector>

struct eMailMsg
{
  string to;      // i.e. "professor@stanford.edu"
  string from;    // i.e. "student@stanford.edu"
  string message; // body of message
  string subject; // i.e. "CS106 Rocks!"
  int date;       // date email was sent
  int time;       // time email was sent
};

// a.
vector<eMailMsg> emailVector;

// b.
void removeSpam(vector<eMailMsg> &emails)
{
  for (int i = 0; i < emails.size(); i++)
  {
    if (emails[i].subject.substr(0, 4) == "SPAM")
      emails.erase(emails.begin() + i--);
  }
}

// c.
struct RevisedEmail
{
  vector<string> to;
  vector<string> from;
  string message;
  string message;
  int date;
  int time;
};

/* Accessing the last field in such a struct would be done as:
 * vector<T> someVector;
 * someVector[someVector.size() - 1];
 * or using the built-in back() reference:
 * someVector.back();
 * */
