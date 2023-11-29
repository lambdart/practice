#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int removeDuplicates (vector<int>& nums)
    {
        int i = 0;
        int j = 0;
        int temp;

        temp = nums[0];
        while (i < nums.size())
        {
            if (temp == nums[i])
                i++;
            else {
                nums[j] = temp;
                temp = nums[i];
                j++;
            }
        }
        nums[j] = nums.back();
        return j + 1;
    }
};

int main (void)
{
    Solution s;

    vector<int> nums = {0,0,1,1,1,2,2,3,3,4};
    int ret;

    ret = s.removeDuplicates(nums);

    for (const auto& i : nums)
        cout << i << " ";
    cout << "\n";

    cout << ret << "\n";

    return 0;
}
