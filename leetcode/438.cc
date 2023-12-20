// 438. Find All Anagrams in a String

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int n = s.size();
        int i = 0;
        int L = 0;
        int R;

        vector<int> ans;
        unordered_map<char,int> a;
        unordered_map<char,int> b;

        for (i = 0; i < p.size(); ++i)
            b[p[i]] += 1;

        for (i = 0; i < p.size() - 1; ++i)
            a[s[i]] += 1;

        R = i;

        while (R < s.size()) {
            a[s[R]] += 1;
            if (a == b) {
                ans.push_back(L);
            }
            if (a[s[L]] > 1) {
                a[s[L]] -= 1;
            }
            else {
                a.erase(s[L]);
            }
            L = L + 1;
            R = R + 1;
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
