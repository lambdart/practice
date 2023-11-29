// 904. Fruit Into Baskets

#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <limits>

using namespace std;

class Solution {
public:

    int totalFruit(vector<int>& fruits) {
        int i{0};
        int j{0};
        int sum{0};
        int max{0};

        unordered_map<int, bool> basket;

        while (i < fruits.size()) {
            // how to start, put a fruit in the basket
            if (basket.size() < 2) {
                basket[fruits[i]] = true;
                ++sum;
                ++i;
            }
            else if (basket[fruits[i]] == true) {
                ++sum;
                ++i;
            }
            else {
                basket.clear();
                j = i - 1;
                max = (sum > max) ? sum : max;
                sum = 0;

                while (fruits[j] == fruits[j - 1])
                    --j;

                i = j + 1;
            }
        }
        return ((sum > max) ? sum : max);
    }
};

int main (void)
{
    Solution s;

    vector<int> fruits = {0,1,6,6,4,4,6};

    int ret = s.totalFruit(fruits);

    cout << ret << endl;

    return 0;
}
