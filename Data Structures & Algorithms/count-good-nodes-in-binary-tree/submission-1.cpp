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
    int count = 0;
public:
    int dfs(TreeNode* root, int maxVal) {
        int result = 0;
        if(root->val >= maxVal) {
            result = 1;
            maxVal = root->val;
        }
        if(root->left) result += dfs(root->left, maxVal);
        if(root->right) result += dfs(root->right, maxVal);

        return result;
    }

    int goodNodes(TreeNode* root) {
        if(!root) return 1;

        return dfs(root, -INT_MAX);
    }
};
 