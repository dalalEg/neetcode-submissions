class Solution {
    vector<vector<int>> adj;
    vector<bool> visited;
     void dfs(int node,int n){
        visited[node]=true;
        for(int pre:adj[node]){
            if(!visited[pre]) dfs(pre,n);
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
      visited.assign(n,false);
       for(int i=0;i<n;i++){
         if(!visited[i]){
            dfs(i,n);
            res++;
            }  }  
       return res;
    }
};
