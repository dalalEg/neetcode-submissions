class Solution:
    def merge(self, intervals: List[List[int]]) -> List[List[int]]:
        intervals.sort()   
        res=[]
        for i in range(0,len(intervals)):
            if len(res)==0 or res[-1][1] < intervals[i][0] :
                res.append(intervals[i])
            else:
                x,y=res[-1][0],res[-1][1]
                res.pop()
                res.append([min( x,intervals[i][0]),max(y,intervals[i][1])])
        return res