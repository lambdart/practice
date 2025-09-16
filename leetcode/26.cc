#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  int removeDuplicates (vector<int>& nums) {
    int L = 0, R = 1, T = nums.size();
    while (R < T) {
      if (nums[L] == nums[R])
        ++R;
      else {
        swap(nums[L + 1], nums[R]);
        ++L;
        ++R;
      }
    }
    return L + 1;
  }
};

// class Solution {
// public:
//     int removeDuplicates (vector<int>& nums)
//     {

//       int L = 0, R = 1, T = nums.size();

//       while (L < T && R < T) {
//         if (nums[L] == nums[R]) {
//           for (int i = R; i < T - 1; ++i) {
//             swap(nums[i], nums[i + 1]);
//           }
//           --T;
//         }
//         else {
//           ++L;
//           ++R;
//         }
//       }
//       return T;
//     }
// };

int main (void)
{
  Solution solution;

  vector<int> nums = {0,0,1,1,1,2,2,3,3,4};
  // vector<int> nums = {0};
  auto ans = solution.removeDuplicates(nums);
  for (const auto& num : nums)
    cout << num << " ";
  cout << endl;
  cout << ans << endl;
  return 0;
}

