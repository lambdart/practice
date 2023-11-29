// 217. Contains Duplicate

#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;


class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int guess = 1;
        int j = 0;

        vector<int> stack;

        sort(nums.begin(), nums.end());



    }
};


class Solution {
public:
    bool solution(vector<int>& nums) {
        int i = 0;

        if (nums.size() < 2)
            return false;

        // complexity?
        sort(nums.begin(), nums.end());

        // O(n)
        do {
            if (nums[i] == nums[i + 1])
                return true;
            i++;
        } while (i < nums.size() - 1);

        return false;
    }
};

int main (void)
{
    Solution s;

    vector<int> nums0 = {1,2,3,1};
    vector<int> nums1 = {1,2,3,4};
    vector<int> nums2 = {1,1,1,3,3,4,3,2,4,2};
    vector<int> nums4 = {0};

    cout << s.solution(nums0) << endl;
    cout << s.solution(nums1) << endl;
    cout << s.solution(nums2) << endl;

    return 0;
}
