#include <string>
#include <algorithm>
#include <iostream>

using namespace std;

class Solution {
public:
  int strStr(string haystack, string needle) {
    int j = 0;
    for (int i = 0; i < haystack.size(); ++i) {
      while (j < needle.size()) {
        if (haystack[i + j] != needle[j])
          break;
        ++j;
      }
      if (j == needle.size())
        return i;
      j = 0;
    }
    return -1;
  }
};

int main(int argc, char *argv[])
{
  Solution solution;

  cout << solution.strStr("sad", "sad") << endl;
  cout << solution.strStr("s1dbutsad", "sad") << endl;
  cout << solution.strStr("mississippi", "issi") << endl;
  cout << solution.strStr("mississippi", "issi") << endl;

  return 0;
}

