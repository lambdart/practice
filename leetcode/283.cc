// 283. Move Zeroes

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    void moveZeroes(vector<int>& A) {
        int n = A.size();
        int L = 0;
        int R = 1 % n;
        int t;

        while (L < n && R < n)
        {
            if (A[L] == 0)
            {
                if (A[R] != 0)
                {
                    // swap
                    t = A[L];
                    A[L] = A[R];
                    A[R] = t;

                    R = R + 1;
                    L = L + 1;
                }
                else
                    R = R + 1;
            }
            else {
                R = R + 1;
                L = L + 1;
            }
        }
    }
};

int main (void)
{
    Solution solution;

    vector<int> A = {4,2,4,0,0,3,0,5,1,0};

    solution.moveZeroes(A);

    for(const auto& v: A) {
        cout << v << " ";
    }
    cout << endl;

    return 0;
}
