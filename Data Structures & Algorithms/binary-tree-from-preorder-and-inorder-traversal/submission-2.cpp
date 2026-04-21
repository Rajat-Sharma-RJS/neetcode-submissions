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
    TreeNode* makeNode(int val) {
        TreeNode* root = new TreeNode(val);
        return root;
    }
    TreeNode* recurse(vector<int>& preorder, vector<int>& inorder, 
                        int p1, int p2, int i1, int i2, unordered_map<int, int>& store) {
        if(p2 < p1 || i2 < i1) return nullptr;
        TreeNode* root = makeNode(preorder[p1]);
        int rootValue = root->val;

        int fi = store[rootValue];
        int count = fi-i1;
        root->left = recurse(preorder, inorder, p1+1, p1+count, i1, fi-1, store);
        root->right = recurse(preorder, inorder, p1+count+1, p2, fi+1, i2, store);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int p2 = preorder.size(), i2 = inorder.size();
        
        unordered_map<int, int> store;
        for(int i=0; i<i2; i++) store[inorder[i]] = i;

        TreeNode* root = recurse(preorder, inorder, 0, p2-1, 0, i2-1, store);
        return root;
    }
};
