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
    int inorder(TreeNode* root, int& res){
        if (root == nullptr) return 0;
        int l=max(0,inorder(root->left,res));
        int v= root->val;
        int r= max(0,inorder(root->right,res));
        res=max(res,l+v+r);
        return v+max(l,r) ;
    }

public:
    int maxPathSum(TreeNode* root) {
        int pathSum=INT_MIN;
        inorder(root,pathSum);
        return pathSum;
    }
};





