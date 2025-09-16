#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  int removeElement (vector<int>& nums, int val)
  {
    int k = 0, i = 0, t = nums.size(), temp;

    while (i < t) {
      if (nums[i] == val) {
        for (int j = i; j < nums.size() - 1; ++j) {
          temp = nums[j + 1];
          nums[j + 1] = nums[j];
          nums[j] = temp;
        }
        if (nums[i] != val) {
          ++i;
          ++k;
        }
        --t;
      }
      else {
        ++k;
        ++i;
      }
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
