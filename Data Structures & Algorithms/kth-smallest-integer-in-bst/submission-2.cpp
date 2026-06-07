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
    void order(TreeNode* root,vector<int>&vc){
        if (!root)
            return;
        order(root->left,vc);
        vc.push_back(root->val);
        order(root->right,vc);

    }
    int kthSmallest(TreeNode* root, int k) {
        vector<int> vec;
        order(root,vec);
        return vec[k-1];
    }
};
