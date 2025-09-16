#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
      int ans = 0;
      int l, r = 1;

      while (r < nums.size()) {
        if (nums[l] == nums[r]) {
          ++l;
        }
        ++r;
      }

      return ans;
    }
};

int main (void)
{
  Solution solution;

  vector<int> nums = {1,1,2};
  // vector<int> nums = {0,0,1,1,1,2,2,3,3,4};
  int ans;

  ans = solution.removeDuplicates(nums);
  for (auto n : nums) cout << n << " ";
  cout << endl;
  cout << ans << endl;

  return 0;
}
