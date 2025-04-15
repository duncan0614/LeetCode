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
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* curr = head;

        while (curr){
            ListNode* temp = curr -> next;
            curr -> next = prev;
            prev = curr;
            curr = temp;
        }

        return prev;
    }
};

// Utility function to print linked list
void printList(ListNode* head) {
    while (head) {
        cout << head->val;
        if (head->next) cout << " -> ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    // Construct the linked list: 0 -> 1 -> 2 -> 3
    ListNode* head = new ListNode(0);
    head->next = new ListNode(1);
    head->next->next = new ListNode(2);
    head->next->next->next = new ListNode(3);

    Solution solution;
    ListNode* reversed = solution.reverseList(head);

    // Print reversed list
    cout << "Reversed List: ";
    printList(reversed);

    // Clean up memory (optional for debugging)
    while (reversed) {
        ListNode* next = reversed->next;
        delete reversed;
        reversed = next;
    }

    return 0;
}
    