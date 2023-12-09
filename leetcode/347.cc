// 347. Top K Frequent Elements

#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k)
    {
        unordered_map<int, int> db;
        unordered_map<int, vector<int>> tmp;
        vector<int> ans;
        int n = nums.size();
        int i{0};
        int j{0};

        while (i < nums.size()) {
            db[nums[i]] += 1;
            ++i;
        }
        for (auto [k, v]: db)
            tmp[v].push_back(k);

        i = n;
        while (i > 0) {
            if (tmp.find(i) != tmp.end()) {
                j = 0;
                while (j < tmp[i].size()) {
                    ans.push_back(tmp[i][j]);
                    ++j;
                }
                if (ans.size() >= k)
                    break;
            }
            --i;
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
