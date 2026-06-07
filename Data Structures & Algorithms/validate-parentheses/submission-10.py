class Solution:
    def isValid(self, s: str) -> bool:
        stack=[]
        CTO= { ")" : "(", "]" : "[", "}" : "{" }
        for ss in s:
            if ss in CTO:
                if len(stack)==0 or stack[-1]!=CTO[ss]:
                    return False
                stack.pop()
            else:
                stack.append(ss)
        return len(stack)==0