/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
    Node* dfs(Node* root){
        if(!root)
            return root;
        if (mapping.count(root))
            return mapping[root];
        Node* curr = new Node(root->val);
        mapping[root]=curr;
        for(Node* neighbor: root->neighbors){
            curr->neighbors.push_back(dfs(neighbor));
        }
        return curr;
    }
public:
    map<Node*,Node*> mapping;
    Node* cloneGraph(Node* node) {
        return dfs(node);
    }
};
