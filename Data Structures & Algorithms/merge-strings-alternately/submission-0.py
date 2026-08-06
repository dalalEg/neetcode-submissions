class Solution:
    def mergeAlternately(self, word1: str, word2: str) -> str:
        res=""
        i1, i2=0,0
        n1,n2=len(word1),len(word2)
        while i1 < n1 and i2<n2:
            res=res+(word1[i1])
            res=res+(word2[i2])
            i1+=1
            i2+=1
        while i1 < n1 :
            res=res+(word1[i1])
            i1+=1
        while  i2<n2:
            res=res+(word2[i2])
            i2+=1
        return res

