class Solution:
    def plusOne(self, digits: List[int]) -> List[int]:
        res=[0]*(len(digits)+1)
        res[0]=1
        carry=1
        for i in range(len(digits)-1,-1,-1):
            digit=digits[i]+carry
            if digit > 9 :
                res[i+1]=digit%10
                carry=1
            else:
                carry=0
                res[i+1]=digit
        return res if carry==1 else res[1:len(digits)+1]
