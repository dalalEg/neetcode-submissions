class Solution:
    def openLock(self, deadends: List[str], target: str) -> int:
        if target =="0000":
            return 0
        visited=set(deadends)
        if "0000"  in visited:
            return -1
        dq=deque()
        dq.append("0000")
        visited.add("0000")
        turns=0
        while dq:
            turns+=1
            size=len(dq)
            for _ in range(size):
                curr=dq.popleft()
                for i in range(4):
                    for j in [1,-1]:
                        digit = str((int(curr[i]) + j + 10) % 10)
                        nextLock = curr[:i] + digit + curr[i+1:]
                        if nextLock in visited:
                            continue
                        if nextLock == target:
                            return turns
                        dq.append(nextLock)
                        visited.add(nextLock)
        return -1