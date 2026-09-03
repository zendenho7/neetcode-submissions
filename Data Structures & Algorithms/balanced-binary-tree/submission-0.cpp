/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    int dfs(TreeNode* node, bool& res) {
        if(!node) return 0;
        if(!node->left && !node->right) return 1;
        int leftHeight = dfs(node->left, res);
        int rightHeight = dfs(node->right, res);
        if(abs(leftHeight - rightHeight) > 1) res = false;
        return 1 + max(leftHeight, rightHeight);
    }

    bool isBalanced(TreeNode* root) {
        if(!root) true;

        bool res = true;

        dfs(root, res);

        return res;
    }
};
