#include <set>
#include <algorithm>
#include <iostream>

using namespace std;

class Solution {
public:
  int lengthOfLongestSubstring(string s) {
    multiset<char> charSet;
    unsigned int l = 0;
    unsigned int ans = 0;

    for (unsigned int r = 0; r < s.size(); ++r) {
      while (charSet.count(s[r]) > 0) {
        charSet.erase(s[l]);
        ++l;
      }
      charSet.insert(s[r]);
      ans = std::max(ans, r - l + 1);
    }
    return ans;
  }
};

int main (void)
{
  Solution solution;

  std::string test_case_1 = "abcabcbb";
  std::string test_case_2 = "bbbbb";
  std::string test_case_3 = "pwwkew";
  std::string test_case_4 = " ";
  std::string test_case_5 = "dvdf";

  std::cout << solution.lengthOfLongestSubstring(test_case_1) << std::endl;
  std::cout << solution.lengthOfLongestSubstring(test_case_2) << std::endl;
  std::cout << solution.lengthOfLongestSubstring(test_case_3) << std::endl;
  std::cout << solution.lengthOfLongestSubstring(test_case_4) << std::endl;
  std::cout << solution.lengthOfLongestSubstring(test_case_5) << std::endl;

  return 0;
}

