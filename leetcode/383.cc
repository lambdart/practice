#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine)
    {
        unordered_map<char, int> a;

        for (char i = 0x61; i < 0x7a; i++)
            a[i] = 0;

        for (const auto& k : magazine)
            a[k] += 1;

        for (const auto& k : ransomNote)
        {
            if (a.count(k) == 0) return false;
            a[k] -= 1;
            if (a[k] < 0) return false;
        }
        return true;
    }
};

int main (void)
{
    Solution solution;

    cout << solution.canConstruct("aa", "aab") << "\n";

    return 0;
}
