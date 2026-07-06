class Solution:
    def canCompleteCircuit(self, gas: List[int], cost: List[int]) -> int:
        if sum(gas)<sum(cost):
            return -1
        curr,index=0,0
        for i in range(len(cost)):
            curr+=(gas[i]-cost[i])
            if curr<0:
                index=i+1
                curr=0
        return  index