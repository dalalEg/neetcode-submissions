class Solution {
    map<int,vector<int>> graph;
    unordered_set<int> visiting;
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        for(auto&prerequisite:prerequisites ){
            int u=prerequisite[0],v=prerequisite[1];
            graph[u].push_back(v);
        }
        for(int c=0;c<numCourses;c++){
            if(!dfs(c))
                return false;
        }
        return true;
    }
    bool dfs(int currNode){
        if(visiting.count(currNode)) return false;
        if(graph[currNode].empty()) return true;
        visiting.insert(currNode);
        for(int pre:graph[currNode]){
            if(!dfs(pre)) return false;
        }
        visiting.erase(currNode);
        graph[currNode].clear();
        return true;
    }
};
