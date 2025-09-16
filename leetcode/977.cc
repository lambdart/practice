// 977. Squares of a Sorted Array

#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;

class Solution {
public:
    vector<int> sortedSquares(vector<int>& A) {
        int n = A.size();
        int L = 0;
        int R = n - 1;
        int i = n - 1;
        int a = 0;
        int b = 0;

        std::vector<int> ans(n);

        while (n > 0) {
            a = pow(A[L], 2);
            b = pow(A[R], 2);
            if (a > b) {
                ans[i] = a;
                L = L + 1;
            }
            else {
                ans[i] = b;
                R = R - 1;
            }
            i = i - 1;
            n = n - 1;
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

int main(int argc, char *argv[])
{
    Solution s;
    std::vector<int> nums {-4,-1,0,3,10};

    for(const auto& v: s.sortedSquares(nums))
        cout << v << " ";
    cout << endl;

    return 0;
}

