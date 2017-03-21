/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> path;
        if (!root)
            return path;
        stack<struct TreeNode*> s;
        while (root || !s.empty()) {
            while (root) {
                s.push(root);
                root = root->left;
            }
            if (!s.empty()) {
                root = s.top();
                path.push_back(root->val);
                s.pop();
                root = root->right;
            }
        }
        return path;
    }
};
