/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
    TreeNode* helper(int preStart, int inStart, int inEnd,
                     vector<int>& preorder,
                     unordered_map<int, int>& inorderIndexMap) {
        if (inStart > inEnd) return nullptr;
        TreeNode* root = new TreeNode(preorder[preStart]);
        int  index =inorderIndexMap[preorder[preStart]];
        int size= index-inStart;
        root->left = helper(preStart+1,inStart,index-1,preorder,inorderIndexMap);
        root->right =helper(preStart + size + 1,index+1,inEnd,preorder,inorderIndexMap);
         return root;
    }

public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int, int> inorderIndexMap;
        int n = preorder.size();
        for (int i = 0; i < n; i++) {
            inorderIndexMap[inorder[i]] = i;
        }

        return helper(0, 0, preorder.size() - 1, preorder, inorderIndexMap);
    }
};