#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int removeElement (vector<int>& nums, int val)
    {
        int i = 0;
        int j = 0;
        int k = 0;
        int temp;

        while (k < nums.size()) {
            if (nums[i] == val) {
                // rotate
                for (j = i; j < nums.size() - 1; j++) {
                    temp = nums[j];
                    nums[j] = nums[j + 1];
                    nums[j + 1] = temp;
                }
            }
            else {
                i++;
            }
            k++;
        }
        i = 0;
        while (i < nums.size()) {
            if (nums[i] == val)
                break;
            i++;
        }
        return i;
    }
};

int main (void)
{
    Solution s;

    vector<int> nums = {3, 3, 3, 2};
    int val = 3;
    int ret;

    ret = s.removeElement(nums, val);

    for (const auto& i : nums)
        cout << i << " ";
    cout << "\n";

    cout << ret << "\n";

    return 0;
}
