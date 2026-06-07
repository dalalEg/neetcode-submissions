class Solution:
    def checkInclusion(self, s1: str, s2: str) -> bool:
        if s1==s2:
            return True
        if len(s1)>len(s2):
            return False
        count1={}
        for s in s1:
            count1[s] = 1 + count1.get(s, 0)
        l=0
        count2={}
        for r in range(len(s2)):
            count2[s2[r]] = 1 + count2.get(s2[r], 0)
            print(count2)
            if r-l+1 == len(s1):
                if count1==count2:
                    return True
                count2[s2[l]] = count2.get(s2[l], 0) -1
                if count2[s2[l]]==0:
                    count2.pop(s2[l])
                l=l+1
        return False
