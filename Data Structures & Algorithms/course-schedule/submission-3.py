class Solution:
    def canFinish(self, numCourses: int, prerequisites: List[List[int]]) -> bool:
        indegree=numCourses*[0]
        adj=[[]for _ in range(numCourses)]
        for pre in prerequisites:
            adj[pre[0]].append(pre[1])
            indegree[pre[1]]+=1
        q=deque()
        for n in range(numCourses):
            if indegree[n] == 0:
                q.append(n)
        res=0
        while q :
            n=q.popleft()
            res += 1
            for nei in adj[n]:
                indegree[nei]-=1
                if indegree[nei]==0:
                    q.append(nei)
        return True if res==numCourses else False            
        