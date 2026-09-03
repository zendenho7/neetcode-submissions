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
    TreeNode* invertTree(TreeNode* root) {

        if(!root) return root;
        
        stack<TreeNode*> dfs;
        dfs.push(root);

        while(!dfs.empty()) {
            TreeNode* top = dfs.top();
            dfs.pop();
            TreeNode* left = top->left;
            TreeNode* right = top->right;
            top->left = right;
            top->right = left;
            if(right) dfs.push(right);
            if(left) dfs.push(left);
        }

        return root;
    }
};
