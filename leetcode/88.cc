#include <iostream>
#include <sstream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    void merge (vector<int>& nums1, int m, vector<int> nums2, int n)
    {
        int i = 0, j = 0, k = 0;

        vector<int>temp(m + n);

        while (i < m && j < n)
        {
            if (nums1[i] < nums2[j]) {
                temp[k] = nums1[i];
                i++;
            }
            else
            {
                temp[k] = nums2[j];
                j++;
            }
            k++;
        }
        while (i < m)
        {
            temp[k] = nums1[i];
            i++;
            k++;
        }
        while (j < n)
        {
            temp[k] = nums2[j];
            j++;
            k++;
        }
        nums1 = temp;
    }
};

int main (void)
{
    Solution s;

    // vector<int> nums1 = {-1,0,0,3,3,3,0,0,0};
    // vector<int> nums2 = {1,2,2};

    // vector<int> nums1 = {1,2,3,0,0,0};
    // vector<int> nums2 = {2,5,6};

    // vector<int> nums1 = {4,0,0,0,0,0};
    // vector<int> nums2 = {1,2,3,5,6};

    s.merge(nums1, 3, nums2, nums2.size());

    for (const auto& v : nums1)
        cout << v << " ";
    cout << "\n";

    return 0;
}
