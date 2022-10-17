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
    int fun(TreeNode* node, bool canTake, map<TreeNode*, unordered_map<bool,int>> &dp){
      if(node -> left == NULL and node -> right == NULL) return canTake ? node -> val : 0;  
        
        if(dp[node][canTake] > 0) return dp[node][canTake];
        int npl = 0, npr = 0, pl = 0, pr = 0;
        if(node -> left)
            npl = fun(node -> left, true, dp);
        if(node -> right)
            npr = fun(node -> right, true, dp);
        if(canTake and node -> left)
            pl = fun(node -> left, false, dp);
        if(canTake and node -> right)
            pr = fun(node -> right, false, dp);
        int p = 0, np = 0;
        if(canTake)
            p = (pl+pr)+ node -> val;
        np = (npl+npr);
        // cout<<p<<" "<<np<<endl;
        return dp[node][canTake] = max(p, np);
    }
    
    int rob(TreeNode* root) {
        map<TreeNode*, unordered_map<bool,int>> dp;
        return fun(root, true, dp);
    }
};