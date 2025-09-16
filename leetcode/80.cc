#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;

class Solution {
public:
  int removeDuplicates(vector<int>& nums)
  {
    int j = 0;
    for (int i = 0; i < nums.size(); ++i)
      // if (i < 2 || nums[i] > nums[i - 2])
        nums[j++] = nums[i];
    return j;
  }
};

int main (void)
{
  Solution s;

  // vector<int> nums = {1,1,2,2,3,3};
  vector<int> nums = {0,0,1,1,1,1,2,3,3};
  // vector<int> nums = {1,1,1,2,2,3};
  // vector<int> nums = {1,1};

  cout << s.removeDuplicates(nums) << endl;

  for(const auto& v: nums) {
    cout << v << " ";
  }
  cout << endl;

  return 0;
}
