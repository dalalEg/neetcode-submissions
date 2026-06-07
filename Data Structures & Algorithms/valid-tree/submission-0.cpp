class Solution {
        map<int,vector<int>> adj;
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        if(edges.size()!=n-1) return false;
        for( auto& edge :edges){
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
            set<int> visited;
            if(!dfs(0,-1,visited,n))return false;
        return true;
    }
    bool dfs(int node,int parent, set<int>& visited,int n){
        if(visited.count(node)) return false;
        visited.insert(node);
        for(int pre:adj[node]){
            if (pre ==parent) continue;
            if(!dfs(pre,node,visited,n))return false;
        }
        return true;
    }
};
