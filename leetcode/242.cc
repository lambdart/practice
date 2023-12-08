// 242. Valid Anagram

#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() == t.size()) {
            sort(s.begin(), s.end());
            sort(t.begin(), t.end());
            return s == t;
        }
        return false;
    }
};

static const int _ = []()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 0;
}();
