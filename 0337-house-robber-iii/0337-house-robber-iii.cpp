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
    int rob(TreeNode* root) {
        int robMax = 0, notRobMax = 0;
        return fun(root, robMax, notRobMax);
    }
    
    int fun(TreeNode* node, int &rob, int &notRob){
        if(!node) return 0;
        
        int leftrob = 0, leftnotrob = 0, rightrob = 0, rightnotrob = 0;
        int left = fun(node -> left, leftrob, leftnotrob);
        int right = fun(node -> right, rightrob, rightnotrob);
        
        rob = node -> val + leftnotrob + rightnotrob;
        notRob = left + right;
        
        return max(rob, notRob);
    }
};