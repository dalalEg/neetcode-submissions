class Solution:

    def encode(self, strs: List[str]) -> str:
        res =""
        for st in strs:
            res+=st 
            res+= '\x80'
        return res

    def decode(self, s: str) -> List[str]:
        res=[]
        temp=""
        for i in range(len(s)):
            if s[i]=='\x80' :
                res.append(temp)
                temp=""
            else:
                temp+=s[i]
    
        return res 
