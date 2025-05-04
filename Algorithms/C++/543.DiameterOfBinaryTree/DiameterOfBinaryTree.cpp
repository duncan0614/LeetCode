#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    int diameterOfBinaryTree(TreeNode* root) {
        int ret = 0;
        dfs(root, ret);
        return ret;
    }

private:
    int dfs(TreeNode* root, int& ret) {
        if (root == nullptr) {
            return 0;
        }

        int left = dfs(root -> left, ret);
        int right = dfs(root -> right, ret);
        ret = max(ret, left + right);
        return 1 + max(left, right);
    }

};
    
    
    