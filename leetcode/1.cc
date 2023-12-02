// 1. Two Sum

#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>

struct point {
    int v;
    int i;
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
        int ans = points[0].first + points[j].first;

        // O(n)
        while (ans != target &&
               i < points.size() &&
               j > 0) {
            if (ans > target)
                j--;
            else
                i++;
            ans = points[i].first + points[j].first;
        }
        return (vector<int> {points[i].second,
                             points[j].second});
    }
};
