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
    void recurse(TreeNode* root, unordered_map<TreeNode*, int>& without,
                 unordered_map<TreeNode*, int>& with) {
        int without_left = 0, with_left = 0, without_right = 0, with_right = 0;
        if(root->left) {
            recurse(root->left, without, with);
            without_left = without[root->left];
            with_left = with[root->left];
        }
        if(root->right) {
            recurse(root->right, without, with);
            without_right = without[root->right];
            with_right = with[root->right];
        }
        without[root] = max(without_left, with_left) + max(without_right, with_right);
        with[root] = root->val + without_left + without_right;
    }
    int rob(TreeNode* root) {
        if(root == nullptr) return 0;
        unordered_map<TreeNode*, int> without, with;
        recurse(root, without, with);
        return max(without[root], with[root]);
    }
};