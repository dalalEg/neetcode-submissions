class Solution:
    def mySqrt(self, x: int) -> int:
        i=1
        while True:
            if i*i==x:
                return i
            if i*i>x:
                return i-1
            i=i+1
        return 4