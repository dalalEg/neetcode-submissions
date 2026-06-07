class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>>adj(numCourses);
        vector<int> in_degree(numCourses,0);
        for(auto & pre:prerequisites){
            adj[pre[0]].push_back(pre[1]);
            in_degree[pre[1]]++;
        }
        queue<int> q;
        for(int i=0;i<numCourses;i++){
            if(in_degree[i]==0)
                q.push(i);
        }
        vector<int> res;
        while(!q.empty()){
            int node= q.front();
            q.pop();
            res.push_back(node);
            for( int pre:adj[node]){
                if(--in_degree[pre]==0)
                    q.push(pre);
            }

        }
        return res.size()==numCourses;
    }
};