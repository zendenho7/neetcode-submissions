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
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(!root) return vector<vector<int>>();
        vector<vector<int>> result;
        queue<TreeNode*> bfs;
        bfs.push(root);

        while(!bfs.empty()) {

            //Sub list
            vector<int> subList;

            //Extract len of current queue
            int len = bfs.size();
            for(int i = 0; i < len; ++i) {

                //Pop from front of queue
                TreeNode* root = bfs.front();
                bfs.pop();
                if(root) subList.push_back(root->val);

                //Add childs back into queue
                if(root->left) bfs.push(root->left);
                if(root->right) bfs.push(root->right);
            }

            //Append sublist to result
            result.push_back(subList);
        }

        return result;
    }
};
