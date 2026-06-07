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
    Node* dfs(Node* node){
        if(node==nullptr) return nullptr;
        if(mapping.count(node)) return mapping[node];
        Node* curr = new Node(node->val);
        mapping[node]=curr;
        for(Node* neighbor: node->neighbors){
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
