class Solution:
    def eraseOverlapIntervals(self, intervals: List[List[int]]) -> int:
        intervals.sort()
        res=0
        arr=[intervals[0][1]]
        for i in range(1,len(intervals)):
            if intervals[i][0]< arr[-1]:
                res+=1
                arr.append(min(arr[-1],intervals[i][1]))
            else :
                arr.append(intervals[i][1])
        return res
        