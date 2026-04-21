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
    int recurse(TreeNode* root, int& maxPath) {
        if(root == nullptr) return -10000;
        int leftMax = recurse(root->left, maxPath);
        int rightMax = recurse(root->right, maxPath);
        int ret = max(leftMax + root->val, max(rightMax + root->val, root->val));
        maxPath = max(maxPath, leftMax + rightMax + root->val);
        maxPath = max(maxPath, ret);
        return ret;
    }
    int maxPathSum(TreeNode* root) {
        int maxPath = -10000;
        int ret = recurse(root, maxPath);
        maxPath = max(maxPath, ret);
        return maxPath;
    }
};
