class Solution:
    def merge(self, intervals: List[List[int]]) -> List[List[int]]:
        intervals.sort()   
        res=[]
        for i in range(0,len(intervals)):
            w,z=intervals[i][0],intervals[i][1]
            if len(res)==0 or res[-1][1] < w :
                res.append(intervals[i])
            else:
                x,y=res[-1][0],res[-1][1]
                res.pop()
                res.append([min( x,w),max(y,z)])
        return res