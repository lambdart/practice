// 167. Two Sum II - Input Array Is Sorted
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int> &A, int target) {
        int L = 0;
        int R = A.size() - 1;
        int sum = 0;

        while (L < R) {
          sum = A[L] + A[R];
          // update the sum
          if (sum == target) return {L + 1, R + 1};
          if (sum > target) --R;
          else ++L;
        }
        return {L + 1, R + 1};
    }
};

int main (void)
{
    Solution solution;

    vector<int> A = {2,7,11,15}; // 9
    //vector<int> A = {2,3,4};   // 6
    //vector<int> A = {-1,0};    // -1

    auto ans = solution.twoSum(A, 9);

    for(const auto& v: ans)
        cout << v << " ";
    cout << endl;

    return 0;
}

