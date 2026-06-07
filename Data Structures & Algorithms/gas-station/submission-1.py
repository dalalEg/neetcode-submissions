class Solution:
    def canCompleteCircuit(self, gas: List[int], cost: List[int]) -> int:
        if sum(gas) < sum(cost):
            return -1

        g = 0
        res = 0
        for i in range(len(gas)):
            g+=(gas[i]-cost[i])
            if g < 0:
                g=0
                res=i+1
        return res