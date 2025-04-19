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
    void reorderList(ListNode* head) {
        ListNode* ptr1 = head;
        ListNode* ptr2 = head -> next;
        while (ptr2 != nullptr && ptr2 -> next != nullptr) {
            ptr1 = ptr1 -> next;
            ptr2 = ptr2 -> next -> next;
        }

        ListNode* second = ptr1 -> next;
        ListNode* prev = ptr1 -> next = nullptr;
        while (second != nullptr){
            ListNode* tmp = second -> next;
            second -> next = prev;
            prev = second;
            second = tmp;
        }

        ListNode* first = head;
        second = prev;
        while (second != nullptr) {
            ListNode* tmp1 = first -> next;
            ListNode* tmp2 = second -> next;
            first -> next = second;
            second -> next = tmp1;
            first = tmp1;
            second = tmp2;
        }
    }
};