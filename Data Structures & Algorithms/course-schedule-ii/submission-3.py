class Solution:
    def findOrder(self, numCourses: int, prerequisites: List[List[int]]) -> List[int]:
        adj=[[]for _ in range(numCourses)]
        inDegree=[0]*numCourses
        for pre in prerequisites:
            inDegree[pre[0]]+=1
            adj[pre[1]].append(pre[0])
        res=[]
        q=deque()
        for i,e in enumerate(inDegree):
            if e==0:
                q.append(i)
        while len(q):

            curr= q.popleft()
            res.append(curr)
            for nei in adj[curr]:
                inDegree[nei]-=1
                if inDegree[nei]==0:
                    q.append(nei)


        return res if len(res)==numCourses else[]