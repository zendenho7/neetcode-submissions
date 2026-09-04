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
    void dfs(TreeNode* root, int maxVal) {
        if(root->val >= maxVal) {
            ++count;
            maxVal = root->val;
        }
        if(root->left) dfs(root->left, maxVal);
        if(root->right) dfs(root->right, maxVal);
    }

    int goodNodes(TreeNode* root) {
        if(!root) return 1;

        dfs(root, -INT_MAX);
        
        return count;
    }
};
 