// 239. Sliding Window Maximum

#include <iostream>
#include <vector>
#include <unordered_map>
#include "dbg.h"

using namespace std;

// template <typename T, size_t N> const T* mybegin(const T (&a)[N]) {return a;}
// template <typename T, size_t N> const T* myend  (const T (&a)[N]) {return a+N;}



struct test {
    static int i;
    static int j;
};

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> db;
        vector<int> ans;

        for (int i = 0; i < nums.size(); i++) {
            // if (i > 0 && i % k == 0) {
            //     ans.push_back(db.pop_back());
            //     dbg(ans);
            // }
            // else
            // {
            //     db.push_back(nums[i]);
            // }
            dbg(db);
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

void foo() {}
void (*fp)();

int main(int argc, char *argv[])
{
    Solution s;
    struct test test;

    fp = foo;
    //fp(1);

    // // vector<int> nums{1,3,-1,-3,5,3,6,7};
    // vector<int> nums{8,7,6,9};
    // int k = 2;
    // dbg(s.maxSlidingWindow(nums, k));

    dbg(&s);
    // dbg(sizeof(fp));
    // dbg(foo);

    return 0;
}

