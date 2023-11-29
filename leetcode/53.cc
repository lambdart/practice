// 53. Maximum subarray

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums)
    {
        int n = nums.size();
        int ans = 0;
        int L = 0;
        int R = 0;

        for (L = 0; L < n; L = L + 1)
            ans = ans + nums[L];

        sum = ans;

        return ans;
    }
};

int main (void)
{
    Solution solution;

    vector<int> nums = {5,4,-1,7,8};
    // vector<int> nums = {7,3,2,6,5,0,3};
    // vector<int> nums = {1,2};
    int ans = solution.maxSubArray(nums);

    // for (const auto& v : nums)
    //     cout << v << " ";
    // cout << "\n";

    cout << ans << endl;

    return 0;
}
