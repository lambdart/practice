// 189. Rotate Array
#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;

union _ut_t {
    char c;
    char e;
    char f;
    int i;
};

struct _test_t {
    static int i;
    static void f();
    static int e() { return 1; }
    static int c();
    // virtual void d();
    // virtual void a();
    // virtual void s();
};

class Solution {
public:
    static void rotate(vector<int>& nums, int k) {
        k = k % nums.size();

        std::reverse(nums.begin(), nums.end());
        std::reverse(nums.begin(), (nums.begin() + (k - 1)));
        std::reverse((nums.begin() + (k - 1)), nums.end());
    }
};

int main (void)
{
    // Solution solution;

    int k = 2;
    vector<int> nums = {1,2,3};

    Solution::rotate(nums, 2);

    for (const auto& v : nums)
        cout << v << " ";
    cout << endl;

    cout << sizeof(struct _test_t);

    return 0;
}
