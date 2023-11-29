// 643. Maximum Average Subarray I

#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <limits>

using namespace std;

class Solution {
public:

    double findMaxAverage(vector<int>& nums, int k) {
        int j = 0;
        int i = 0;
        int d = k;

        int sum = 0;
        int max = std::numeric_limits<int>::min();

        while (i < nums.size())
        {
            if (i < k) {
                sum += nums[i];
                i++;
            }
            else {
                max = (sum > max) ? sum : max;
                sum -= nums[j];
                ++j;
                ++k;
            }
        }
        max = (sum > max) ? sum : max;

        return ((double)max/(double)d);
    }
};

int main (void)
{
    Solution s;

    vector<int> nums0 = {1,12,-5,-6,50,3};
    vector<int> nums1 = {-1};

    double ret = s.findMaxAverage(nums0, 4);

    cout << ret << endl;

    return 0;
}
