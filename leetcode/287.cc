// 287. Find the Duplicate Number

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int findDuplicate(vector<int>& A) {
        int n = A.size();
        int L = A[0];
        int R = A[A[0]];

        while (L != R)
        {
            L = A[L];
            R = A[A[R]];
        }
        L = A[0];
        R = A[R];
        while (L != R)
        {
            L = A[L];
            R = A[R];
        }
        return L;
    }
};

int main (void)
{
    Solution solution;

    //vector<int> A = {1,1};
    //vector<int> A = {3,1,3,4,2};
    //vector<int> A = {1,3,4,2,1};
    //vector<int> A = {2,5,8,6,8,3,9,8,1,7};
    //vector<int> A = {4,3,1,4,2};
    vector<int> A = {1,3,4,2,2};

    int ans = solution.findDuplicate(A);

    cout << ans << endl;

    return 0;
}
