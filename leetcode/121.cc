// 121. Best Time to Buy and Sell Stock

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    static int maxProfit(vector<int>& prices) {
      int l = 0, r = 1, ans = 0;
      while (r < prices.size()) {
        if (prices[r] < prices[l]) ++l;
        else {
          ans = max(ans, prices[r] - prices[l]);
          ++r;
        }
      }
      return ans;
    }
};

int main (void)
{
    // vector<int> prices = {7,1,5,3,6,4};
    // vector<int> prices = {2,1,2,1,0,1,2};
    // vector<int> prices = {7,3,2,6,5,0,3};
    // vector<int> prices = {1,2,3};
    vector<int> prices = {1};

    cout << Solution::maxProfit(prices) << endl;

    return 0;
}
