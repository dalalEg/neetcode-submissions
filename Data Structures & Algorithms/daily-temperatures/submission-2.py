class Solution:
    def dailyTemperatures(self, temperatures: List[int]) -> List[int]:
        res = [0] * len(temperatures)
        stack = []  # pair: [temp, index]
        for index,temp in enumerate(temperatures):
            while len(stack)!=0 and stack[-1][0] < temp:
                ind = stack[-1][1]
                res[ind]=index - ind
                stack.pop()
            stack.append((temp,index))
        return res
