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
    TreeNode* removeLeafNodes(TreeNode* root, int target) {
        stack<pair<TreeNode *,TreeNode *>> st;
        st.push({root,root});
        stack<TreeNode*> curr;
        curr.push(root);
        while(!curr.empty()){
            TreeNode* temp=curr.top();
            curr.pop();
            if(temp->left){
               st.push({temp,temp->left});
               curr.push(temp->left);
            }
            if(temp->right){
               st.push({temp,temp->right});
               curr.push(temp->right);
            }
        }
        while(!st.empty()){
            auto a = st.top();
            st.pop();
            if(a.second->val==target){
                if (a.second->left==nullptr &&a.second->right==nullptr){
                   if(a.first->left==a.second ){
                    a.first->left=nullptr;
                   }
                   if(a.first->right ==a.second){
                    a.first->right=nullptr;
                   }
                   if(st.empty()){
                    return nullptr;
                   }
                }

            }
        }
        return root;
    }
};