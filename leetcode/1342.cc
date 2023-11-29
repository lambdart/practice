#include <iostream>
#include <sstream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    int numberOfSteps(int num)
    {
        unsigned int  i = 0;
        unsigned char t = 1;
        while (num > 0) {
            num = (!(num & t)) ? num >> t : num - t;
            i++;
        }
        return i;
    }
};

int main (void)
{

    int n;
    Solution solution;

    cin >> n;
    cout << solution.numberOfSteps(n);

    return 0;
}
