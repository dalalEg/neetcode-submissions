class Solution:
    def isHappy(self, n: int) -> bool:
        lst=[]
        ch=0
        while ch!=1:
            ch=0
            while n>0:
                ch+=(n%10)*(n%10)
                n=n//10
            print(ch)
            n=ch
            if ch in lst: 
                return False
            lst.append(ch)
        return True