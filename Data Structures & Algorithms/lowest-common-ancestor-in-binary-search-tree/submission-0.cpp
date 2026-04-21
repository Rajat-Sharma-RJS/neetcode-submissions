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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        queue<TreeNode*> que;
        que.push(root);
        unordered_map<TreeNode*, TreeNode*> parent;
        parent[root] = nullptr;

        int count = 2;
        while(!que.empty()) {
            if(count == 0) break;
            TreeNode* node = que.front();
            if(node->left != nullptr) {
                parent[node->left] = node;
                que.push(node->left);
                if(node->left == p || node->left == q) count--;
            }
            if(node->right != nullptr) {
                parent[node->right] = node;
                que.push(node->right);
                if(node->right == p || node->right == q) count--;
            }
            que.pop();
        }
        vector<TreeNode*> first, second;
        
        TreeNode* temp = p;
        first.push_back(temp);
        while(parent[temp] != nullptr) {
            first.push_back(parent[temp]);
            temp = parent[temp];
        }

        temp = q;
        second.push_back(temp);
        while(parent[temp] != nullptr) {
            second.push_back(parent[temp]);
            temp = parent[temp];
        }

        int len1 = first.size(), len2 = second.size();
        int i1 = len1-1, i2 = len2-1;
        while(first[i1] == second[i2] && i1 >= 0 && i2 >= 0) {
            i1--;
            i2--;
        }
        if(i1 < 0) return p;
        if(i2 < 0) return q;
        return first[i1+1];
    }
};
