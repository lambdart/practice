// 11. Container With Most Water

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maxArea(vector<int>& A) {
        int n = A.size();
        int ans = 0;
        int h = 0;
        int L = 0;
        int R = n - 1;

        while (R != L && L < n && R > 0)
        {
            h = (A[L] <= A[R]) ? A[L] : A[R];
            ans = max(ans, (h * (R - L)));

            if (A[L] < A[R])
                L = L + 1;
            else
                R = R - 1;
        }
        return ans;
    }
};

int main (void)
{
    Solution solution;

    vector<int> A = {1,8,6,2,5,4,8,3,7};
    // vector<int> A = {1,1};

    int ans = solution.maxArea(A);

    cout << ans << endl;

    return 0;
}
