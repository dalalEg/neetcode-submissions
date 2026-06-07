class Solution:
    def letterCombinations(self, digits: str) -> List[str]:
        res = []
        digitToChar = {
            "2": "abc",
            "3": "def",
            "4": "ghi",
            "5": "jkl",
            "6": "mno",
            "7": "qprs",
            "8": "tuv",
            "9": "wxyz",
        }
        def backtracking(i,st):
            if i == len(digits):
                res.append(st)
                return 
            for s in digitToChar[digits[i]]:
                t=st+s
                backtracking(i+1,t)
        if digits:
            backtracking(0,"")
        return res