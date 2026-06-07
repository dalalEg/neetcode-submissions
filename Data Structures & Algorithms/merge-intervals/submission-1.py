class Solution:
    def merge(self, intervals: List[List[int]]) -> List[List[int]]:
        intervals.sort()
        res=[]
        res.append([-1,-1])
        for i in range(len(intervals)):
            x,y = res[-1][0],res[-1][1]  
            z,w=intervals[i][0],intervals[i][1]
            print(z,w)
            if z >= x and z<=y:
                res.pop()
                z= min(x,z)
                w=max(y,w)
            print(z,w)
            res.append([z,w])


        return  res[1:len(res)]