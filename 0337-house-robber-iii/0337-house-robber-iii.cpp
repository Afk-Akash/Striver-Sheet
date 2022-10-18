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
    pair<int,int> fun(TreeNode* root){
        if(root == NULL) return {0,0};
        pair<int,int> left, right;
        
        left = fun(root -> left);
        right = fun(root -> right);
        
        pair<int,int> pair;
        pair.first = max(left.first, left.second) + max(right.first , right.second);
        pair.second = root -> val + left.first + right.first;
        return pair;
    }
public:
    int rob(TreeNode* root) {
        auto p = fun(root);
        return max(p.first, p.second);
    }
};