class Solution:
    def longestCommonPrefix(self, strs: List[str]) -> str:
        res=""
        cur=""
        for i in range(len(strs[0])):
            cur+=strs[0][i]
            for j in range(1,len(strs)):
                if len(strs[j]) <=i:
                    return res
                if strs[j][i]!=strs[0][i]:
                    return res
            res=cur
        return res