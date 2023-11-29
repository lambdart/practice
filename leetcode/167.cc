// 167. Two Sum II - Input Array Is Sorted
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& A, int T) {
        vector<int> ans(2);

        int n = A.size();
        int L = 0;
        int R = n - 1;

        int sum = A[L] + A[R];

        while (sum != T && L < n && R > 0)
        {
            if (sum > T)
                R = R - 1;
            else
                L = L + 1;
            // update the sum
            sum = A[L] + A[R];

        }
        ans[0] = L + 1;
        ans[1] = R + 1;

        return ans;
    }
};


int main (void)
{
    Solution solution;

    //vector<int> A = {2,7,11,15}; // 9
    //vector<int> A = {2,3,4};   // 6
    //vector<int> A = {-1,0};    // -1

    auto ans = solution.twoSum(A, -1);

    for(const auto& v: ans)
        cout << v << " ";

    cout << endl;

    return 0;
}


