#include <iostream>
#include <sstream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    void fizzBuzz(int n)
    {
        vector<string> temp(n);

        for (int i = 0, j = 1; i < n; i++, j++) {
            if ((j % 3) == 0) temp[i] = "Fizz";
            if ((j % 5) == 0) temp[i] = temp[i] + "Buzz";
            if (((j % 3) != 0) &&
                ((j % 5) != 0)) temp[i] = to_string(j);
        }
        for (const auto &s : temp) {
            cout << s;
            cout << "\n";
        }
    }
};

int main (void)
{
    Solution solution;

    // for (auto& s : solution.fizzBuzz(15))
    //     cout << s << "\n";

    solution.fizzBuzz(15);

    return 0;
}
