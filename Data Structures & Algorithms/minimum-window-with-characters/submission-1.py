class Solution:
    def minWindow(self, s: str, t: str) -> str:
        if t==s:
            return s
        if len(t)>len(s):
            return ""
        countT={}
        for ts in t:
            countT[ts]=countT.get(ts,0)+1
        l=0
        countS={}
        have, need = 0, len(countT)
        res, resLen = [-1, -1], float("infinity")
        for r in range(len(s)):
            ss= s[r]
            countS[ss]=countS.get(ss,0)+1
            if ss in countT and countS[ss] == countT[ss]:
                have += 1
            while have==need:
                if (r-l+1)< resLen:
                    res=[l,r]
                    resLen = r - l + 1
                countS[s[l]]-=1
                if s[l] in countT and countS[s[l]] < countT[s[l]]:
                    have -= 1
                l += 1
        l, r = res
        return s[l : r + 1] if resLen != float("infinity") else ""