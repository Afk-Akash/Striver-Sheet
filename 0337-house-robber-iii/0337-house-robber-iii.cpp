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
    unordered_map<TreeNode*, int> dp;
public:
    int rob(TreeNode* root) {
        if(root == NULL ) return 0;
        if(dp[root] > 0) return dp[root];
        int val = 0;
        if(root -> left)
            val = rob(root -> left -> left) + rob(root -> left -> right);
        if(root -> right)
            val += rob(root -> right -> left) + rob(root -> right -> right);
        
        return dp[root] = max(val + root -> val, rob(root -> left) + rob(root -> right));
    }
};