class Solution:
    def isValid(self, s: str) -> bool:
        stack = []
        closeToOpen = { ")" : "(", "]" : "[", "}" : "{" }
        for ss in s:
            if ss in closeToOpen:
                if  len(stack)==0 or  closeToOpen[ss] !=stack.pop():
                    return False
            else:
                stack.append(ss)
        return len(stack)==0