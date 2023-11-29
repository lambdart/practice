#include <iostream>
#include <vector>

using namespace std;

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {

        int sum = 0;
        int val = 0;
        int carry = 0;

        ListNode *ret = new ListNode(0);
        ListNode *head = ret;

        while (l1 != nullptr && l2 != nullptr)
        {
            sum   = l1->val + l2->val + carry;
            val   = sum % 10;
            carry = sum / 10;

            ret->next = new ListNode(val);
            ret = ret->next;
            l1  = l1->next;
            l2  = l2->next;
        }
        while (; l1 != nullptr; l1 = l1->next)
        {
            sum = l1->val + carry;
            val = sum % 10;
            carry = sum / 10;
            ret->next = new ListNode(val);
            ret = ret->next;
        }
        for (; l2 != nullptr; l2 = l2->next)
        {
            sum = l2->val + carry;
            carry = sum / 10;
            val = sum % 10;
            ret->next = new ListNode(val);
            ret = ret->next;
        }
        if (carry > 0) {
            ret->next = new ListNode(carry);
            ret = ret->next;
        }
        return head->next;
    }
};

// Example 3:

// Input: l1 = [9,9,9,9,9,9,9], l2 = [9,9,9,9]
// Output: [8,9,9,9,0,0,0,1]


// int main (void)
// {
//     Solution s;

//     auto *a = new ListNode();
//     auto *b = new ListNode();
//     auto *ret = s.addtwoSum(a, b);

//     for (const auto& i : ret)
//         cout << i << " ";
//     cout << "\n";

//     return 0;
// }
