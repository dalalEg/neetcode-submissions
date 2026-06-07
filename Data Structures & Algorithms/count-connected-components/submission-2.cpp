class Solution {
    vector<vector<int>> adj;
    set<int>visited;
     void dfs(int node,int n){
        visited.insert(node);
        for(int pre:adj[node]){
            if(visited.count(pre)==0) dfs(pre,n);
        }
    }
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        adj.assign(n,vector<int>());
       for(auto& edge:edges){
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
       }
       int res=0;
      
       for(int i=0;i<n;i++){
          if(visited.count(i)>0)
            continue; 
        else {
            dfs(i,n);
            res++;
            }    }
       return res;
    }
};
