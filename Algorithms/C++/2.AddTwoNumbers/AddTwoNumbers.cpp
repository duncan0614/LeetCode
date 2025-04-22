
#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;

/**
 * Definition for singly-linked list.
 *  */
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};


class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dummy = new ListNode();
        ListNode* head = dummy;

        int sum = 0;
        while (l1 != nullptr || l2 != nullptr || sum != 0) {
            int v1 = (l1 != nullptr) ? l1 -> val : 0;
            int v2 = (l2 != nullptr) ? l2 -> val : 0;

            int val = v1 + v2 + sum;
            sum = val / 10;
            val = val % 10;
            head -> next = new ListNode(val);

            head = head -> next;
            l1 = (l1 != nullptr) ? l1 -> next : nullptr;
            l2 = (l2 != nullptr) ? l2 -> next : nullptr;
        }

        return dummy -> next;
    }
};
    