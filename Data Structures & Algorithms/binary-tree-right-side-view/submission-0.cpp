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
    vector<int> rightSideView(TreeNode* root) {
        if(!root) return vector<int>();
        vector<int> result;
        queue<TreeNode*> bfs;
        bfs.push(root);

        while(!bfs.empty()) {

            int len = bfs.size();
            for(int i = 0; i < len; ++i) {

                TreeNode* node = bfs.front();
                bfs.pop();
                if(!i) result.push_back(node->val);
                if(node->right) bfs.push(node->right);
                if(node->left) bfs.push(node->left);
            }
        }

        return result;
    }
};
