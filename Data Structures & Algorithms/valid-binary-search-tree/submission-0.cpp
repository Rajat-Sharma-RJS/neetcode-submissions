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
    void recurse(TreeNode* root, vector<int>& fill) {
        if(root == nullptr) return;
        recurse(root->left, fill);
        fill.push_back(root->val);
        recurse(root->right, fill);
    }
    bool isValidBST(TreeNode* root) {
        // do in order traversal
        vector<int> fill;
        recurse(root, fill);
        for(int i=1; i<fill.size(); i++) {
            if(fill[i] <= fill[i-1]) return false;
        }
        return true;
    }
};
