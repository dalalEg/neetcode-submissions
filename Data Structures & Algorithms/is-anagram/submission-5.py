class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        dicS,dicT=Counter(s),Counter(t)
        return dicS==dicT