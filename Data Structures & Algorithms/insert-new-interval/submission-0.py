class Solution:
    def insert(self, intervals: List[List[int]], newInterval: List[int]) -> List[List[int]]:
        res = []
        s,e=newInterval[0],newInterval[1]
        for i in range(len(intervals)):
            start,end=intervals[i][0],intervals[i][1]
            if end < s:
                res.append(intervals[i])
            elif start > e:
                res.append([s,e])
                return res + intervals[i:]
            else:
                s,e=min(s,start),max(e,end)
        res.append([s,e])
        return res