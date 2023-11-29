// 136. Single Number

#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
public:
    int solution(vector<int>& nums) {
        int ret = nums[0];
        int i = 1;

        while (i < nums.size())
        {
            ret = ret ^ nums[i];
            i++;
        }
        return ret;
    }
};

int main (void)
{
    Solution s;

    vector<int> nums0 = {4,1,2,1,2};
    vector<int> nums1 = {2, 2, 1};

    cout << s.solution(nums0) << endl;

    return 0;
}
