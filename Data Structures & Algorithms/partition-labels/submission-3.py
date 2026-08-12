class Solution:
    def partitionLabels(self, s: str) -> List[int]:
        lastAppear={}
        for i,c in enumerate(s):
            lastAppear[c]=i
        size ,cEnd= 0,0
        res=[]
        for i,c in enumerate(s):
            size+=1
            cEnd=max(cEnd,lastAppear[c])
            if i == cEnd:
                res.append(size)
                size=0
        return res
