class UnionFind:
    def __init__(self, n):
        self.parent = list(range(n))
        self.rank = [1] * n

    def find(self, x):
        if self.parent[x] != x:
            self.parent[x] = self.find(self.parent[x])  # path compression
        return self.parent[x]

    def union(self, a, b):
        rootA = self.find(a)
        rootB = self.find(b)

        if rootA == rootB:
            return False   # already connected

        # union by rank/size
        if self.rank[rootA] < self.rank[rootB]:
            rootA, rootB = rootB, rootA

        self.parent[rootB] = rootA
        self.rank[rootA] += self.rank[rootB]

        return True

class Solution:
    def countComponents(self, n: int, edges: List[List[int]]) -> int:
        uf=UnionFind(n)
        res=0
        for u,v in edges:
            if uf.union(u,v):
                res+=1
        print(uf.parent)
        return n-res
        