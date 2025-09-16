#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  int removeElement (vector<int>& nums, int val)
  {
    int k = 0;

    for (int i = 0; i < nums.size(); ++i) {
      if (nums[i] == val) {
        nums[i] = 95;
      }
      else ++k;
    }

    int t = nums.size() - k;
    int i = 0;
    while(i < nums.size() && t > 0) {
      if (nums[i] == 95) {
        for (int j = i; j < nums.size() - 1; ++j)
          swap(nums[j], nums[j + 1]);
        --t;
      }
      if (nums[i] != 95) ++i;
    }
    return k;
  }
};

int main (void)
{
  Solution solution;

  // vector<int> nums = {2, 3, 3, 2};
  vector<int> nums = {0,1,2,2,3,0,4,2};
  int val = 2;
  int ans;

  ans = solution.removeElement(nums, val);
  for (auto n : nums) cout << n << " ";
  cout << endl;
  cout << ans << endl;

  // solution.rotateNums(nums);
  // solution.rotateNums(nums);
  // for (auto n : nums) cout << n << " ";
  // cout << endl;

  return 0;
}
