class Solution:
    def eraseOverlapIntervals(self, intervals: List[List[int]]) -> int:
        intervals.sort()
        res=0
        temp=[]
        for i in range(len(intervals)):
            print(intervals[i])
            if i>0 and intervals[i][0]<temp[-1][1]:
                res+=1
                temp.append([intervals[i][0],min(intervals[i][1],temp[-1][1])])
            else:
                temp.append(intervals[i])
        return res