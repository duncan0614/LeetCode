#include <algorithm>
#include <vector>
#include <iostream>
#include <unordered_map>
using namespace std;

/*
// Definition for a Node.
*/
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};


class Solution {
public:
    unordered_map<Node*, Node*> nodeMap;

    Node* copyRandomList(Node* head) {
        if (head == nullptr) return nullptr;
        if (nodeMap.count(head)) return nodeMap[head];

        Node* tmp = new Node(head -> val);
        nodeMap[head] = tmp;
        tmp -> next = copyRandomList(head -> next);
        tmp -> random = nodeMap[head -> random];
        return tmp;
    }
};
    