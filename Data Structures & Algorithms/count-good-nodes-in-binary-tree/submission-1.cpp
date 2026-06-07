class Solution {
public:
    int goodNodes(TreeNode* root) {
        if (!root) return 0;

        stack<pair<TreeNode*, int>> st;
        st.push({root, root->val});
        int res = 0;

        while (!st.empty()) {
            auto [node, maxSoFar] = st.top();
            st.pop();

            if (node->val >= maxSoFar) res++;
            int newMax = max(maxSoFar, node->val);

            if (node->right) st.push({node->right, newMax});
            if (node->left) st.push({node->left, newMax});
        }

        return res;
    }
};
