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
    int res;
    int dfs(TreeNode* node){
        if (!node)
            return 0;
       int left= max(0,dfs(node->left));
       int right=max(0,dfs(node->right));
       int val = node->val;
       res=max(left+right+val,res);
       return val+max(left,right);
    }
public:
    int maxPathSum(TreeNode* root) {
        res=INT_MIN;
        dfs(root);
        return res;
    }
};
