class Solution:
    def calPoints(self, operations: List[str]) -> int:
        stack=[]
        res=0
        for op in operations:
            if op=="+":
                top=stack[-1]
                stack.pop()
                toAdd=top+stack[-1]
                stack.append(top)
                stack.append(toAdd)
                res+=toAdd
            elif op=="D":
                top=stack[-1]
                toAdd=top*2
                stack.append(toAdd)
                res+=toAdd
            elif op=="C":
                res-=stack[-1]
                stack.pop()
            else:
                res+=int(op)
                stack.append(int(op))
        return res
