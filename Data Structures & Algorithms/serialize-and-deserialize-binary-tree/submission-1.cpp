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

class Codec {

    TreeNode* dfsDeserialize(vector<string>& vals, int& i) {
        if (vals[i] == "*") {
            i++;
            return NULL;
        }
        TreeNode* node = new TreeNode(stoi(vals[i]));
        i++;
        node->left = dfsDeserialize(vals, i);
        node->right = dfsDeserialize(vals, i);
        return node;
    }

    vector<string> split(const string& s, char delim) {
        vector<string> elems;
        stringstream ss(s);
        string item;
        while (getline(ss, item, delim)) {
            elems.push_back(item);
        }
        return elems;
    }

public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if (!root)
            return "*&";
        string encode = "";
        stack<TreeNode*> st;
        st.push(root);
        while (!st.empty()) {
            TreeNode* curr = st.top();
            st.pop();
            if (!curr) {
                encode += "*&";
                continue;
            }
            encode += to_string(curr->val) + "&";
            // Push right first so left is processed first
            st.push(curr->right);
            st.push(curr->left);
        }
        return encode;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        vector<string> vals = split(data, '&');
     
        int i = 0;
        return dfsDeserialize(vals, i);
    }
};
