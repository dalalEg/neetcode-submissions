class Solution:
    def asteroidCollision(self, asteroids: List[int]) -> List[int]:
        lst=[]
        for a in asteroids:
            while lst and a < 0 and lst[-1] > 0:
                curr=lst[-1]+a
                if curr==0:
                    a=0
                    lst.pop()
                elif curr<0:
                    lst.pop()
                else:
                    a=0
            if a:
                lst.append(a)
        return lst