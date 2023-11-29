#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>

struct point {
    int value;
    int index;
};

class Solution {
public:
    vector<int> twoSum (vector<int>& nums, int target)
    {
        std::pair<int, int> point;
        std::vector<pair<int, int>> points(nums.size());
        for (int i = 0; i < nums.size(); i++)
        {
            point.first = nums[i];
            point.second = i;
            points[i] = point;
        }

        // O(n * logn)
        sort(points.begin(),
             points.end(),
             [](auto &left, auto &right) {
                 return left.first < right.first;
             });

        int i = 0;
        int j = points.size() - 1;

        int guess = points[0].first + points[j].first;

        // O(n)
        while (guess != target &&
               i < points.size() &&
               j > 0) {
            if (guess > target)
                j--;
            else
                i++;
            guess = points[i].first + points[j].first;
        }
        return (vector<int> {points[i].second,
                             points[j].second});
    }
};

int main (void)
{
    Solution s;

    vector<int> nums0 = {-1,-2,-3,-4,-5};
    int target0 = -8;

    vector<int> nums1 = {3,2,4};
    int target1 = 6;

    vector<int> result;

    result = s.twoSum(nums1, target1);

    for (const auto& v : result)
        cout << v << " ";
    cout << endl;

    // cout << ((-6) > (-8)) << endl;

    return 0;
}
