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
    vector<vector<int>> levelOrder(TreeNode* root) {
      if(!root){
      vector<vector<int>> res;
       return res;}
        int level=0;
        queue<pair<TreeNode*,int>>st;
        st.push({root,level});
        vector<vector<int>> res(1000);
        while(!st.empty()){
           TreeNode* curr=st.front().first;
           int currL=st.front().second;
           level=max(level,currL);
           st.pop();
           res[currL].push_back(curr->val);
           if(curr->left!=nullptr){
             st.push({curr->left,currL+1});
           }
           if(curr->right!=nullptr){
             st.push({curr->right,currL+1});
           }
        }
        res.resize(level+1);
        return  res;
    }
};
