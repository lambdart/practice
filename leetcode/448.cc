// 448. Find All Numbers Disappeared in an Array

#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& A) {
        vector<int> ans{};

        for (int i = 0; i < A.size(); ++i)
            A[abs(A[i]) - 1] = -1 * abs(A[abs(A[i]) - 1]);

        for (int i = 0; i < A.size(); ++i)
            if (A[i] > 0)
                ans.push_back(i + 1);

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
