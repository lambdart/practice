// 209.

#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <limits>

using namespace std;

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums)
    {
        uint n = nums.size();
        uint L{0};
        uint R{0};
        uint ans{0};
        uint sum{0};

        for (R = 0; R < n; R = R + 1)
        {
            sum = sum + nums[R];
            while (L <= R && sum >= target) {
                sum = sum - nums[L];
                ans = (ans == 0) ?  R - L + 1 : min(ans, R - L + 1);
                L = L + 1;
            }
        }
        return ans;
    }
};

int main (void)
{
    Solution s;

    vector<int> nums = {1,1,1,1,1,1,1,1};
    // vector<int> nums = {2,3,1,2,4,3};
    // vector<int> nums = {1,4,4};
    // vector<int> nums = {1,2,3,4,5};

    int ret = s.minSubArrayLen(11, nums);

    cout << ret << endl;

    return 0;
}

