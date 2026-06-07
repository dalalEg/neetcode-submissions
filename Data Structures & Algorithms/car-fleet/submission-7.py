class Solution:
    def carFleet(self, target: int, position: List[int], speed: List[int]) -> int:
        pair = [(p, s) for p, s in zip(position, speed)]
        pair.sort(reverse=True)

        prevTime = (target - pair[0][0]) / pair[0][1]
        res,i=1,1
        while i < len(position):
            currTime =(target - pair[i][0]) / pair[i][1]
            if prevTime < currTime:
                res+=1
                prevTime=currTime
            i+=1
        return res