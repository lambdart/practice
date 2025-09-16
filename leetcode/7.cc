#include <iostream>
#include <stack>
#include <climits>
#include <string>
#include <iterator>
#include <algorithm>

using namespace std;

class Solution {
public:
    int reverse(int x) {
      string n = to_string(x);
      int t = n.size() - 1, ans = 0;

      for (int i = t, j = 0; i > t / 2; --i, ++j)
        swap(n[j], n[i]);

      try {
        if (n[t] == '-') {
          n.pop_back();
          ans = stoi(n);
          ans *= -1;
        }
        else {
          ans = stoi(n);
        }
      }
      catch (const std::exception& e) {
        ans = 0;
      }
      return ans;
    }
};

int main(int argc, char *argv[])
{
  Solution solution;
  solution.reverse(1534236469);

  return 0;
}

