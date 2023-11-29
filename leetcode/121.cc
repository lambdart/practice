// 121. Best Time to Buy and Sell Stock

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    static int maxProfit(vector<int>& prices) {

        int buy = prices[0];
        int ans = 0;

        prices[0] = 0;

        for (int i = 1; i < prices.size(); i++) {
            if (buy > prices[i])
            {
                buy = prices[i];
                prices[i] = 0;
            }
            else {
                ans = max(ans, prices[i] - buy);
            }
        }
        return ans;
    }
};

int main (void)
{
    // vector<int> prices = {2,1,2,1,0,1,2};
    // vector<int> prices = {7,3,2,6,5,0,3};
    vector<int> prices = {1,2};

    int ret = Solution::maxProfit(prices);

    // for (const auto& v : prices)
    //     cout << v << " ";
    // cout << "\n";

    cout << ret << endl;

    return 0;
}
