#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums)
    {
        unsigned int l = 0;
        unsigned int r = 1;
        unsigned int n = nums.size();

        while (r < n && l < n)
        {
            if (nums[l] == nums[r])
            {
                // find the window size
                while (r < (n - 1) && nums[r] == nums[r + 1])
                    r++;
                if (r - l > 1)
                {
                    l = l + 2;
                    reverse(nums.begin() + l, nums.end());
                    reverse(nums.begin() + l, nums.end() - ((r - l) + 1));
                    n = n - ((r - l) + 1);
                    r = l + 1;
                }
                else {
                    l = r;
                    r = l + 1;
                }
            }
            else {
                ++l;
                ++r;
            }
        }
        return n;
    }
};

int main (void)
{
    Solution s;

    // vector<int> nums = {1,1,2,2,3,3};
    // vector<int> nums = {0,0,1,1,1,1,2,3,3};
    // vector<int> nums = {1,1,1,2,2,3};
    vector<int> nums = {1,1};

    cout << s.removeDuplicates(nums) << endl;

    for(const auto& v: nums) {
        cout << v << " ";
    }
    cout << endl;

    return 0;
}
