#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;

/**
 * Definition for singly-linked list.
 */
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    bool hasCycle(ListNode* head) {
        ListNode* ptr1 = head;
        ListNode* ptr2 = head;

        while (ptr2 != nullptr && ptr2 -> next != nullptr) {
            ptr1 = ptr1 -> next;
            ptr2 = ptr2 -> next -> next;
            if (ptr1 == ptr2){
                return true;
            }

        }

        return false;
    }
};