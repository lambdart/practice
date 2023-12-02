// 128. Longest Consecutive Sequence

#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int, bool> db;
        int num = 0;
        int sum = 0;
        int ans = 0;

        for (auto v: nums)
            db[v] = true;

        for (int i = 0; i < nums.size(); ++i)
        {
            num = nums[i];
            sum = 0;
            if (db.count(num - 1) == 0)
            {
                while (db.count(num) == 1)
                {
                    sum = sum + 1;
                    num = num + 1;
                }
                ans = max(ans, sum);
            }
        }
        return ans;
    }
};

static const int _ = []()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 0;
}();
