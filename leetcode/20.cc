#include <iostream>
#include <limits>
#include <stack>
#include <algorithm>

using namespace std;

class Solution {
public:
  bool isValid(string s) {
    stack<char> charStack;
    char topChar;

    for (int i = 0; i < s.size(); ++i) {
      if (s[i] == '(' || s[i] == '[' || s[i] == '{')
        charStack.push(s[i]);
      else {
        if (charStack.empty()) return false;
        topChar = charStack.top();
        if (topChar == '(' && s[i] == ')' ||
            topChar == '[' && s[i] == ']' ||
            topChar == '{' && s[i] == '}')
          charStack.pop();
        else
          return false;
      }
    }
    return charStack.empty();
  }
};

int main (void)
{
  Solution s;

  cout << s.isValid("(])") << endl;

  return 0;
}

