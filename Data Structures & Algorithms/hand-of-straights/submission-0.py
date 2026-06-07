from typing import List

class Solution:
    def isNStraightHand(self, hand: List[int], groupSize: int) -> bool:
        if len(hand) % groupSize != 0:
            return False

        # Frequency array for card values
        arr = [0] * 1001  # Assuming card values range from 0 to 10000
        least = float('inf')

        # Count frequencies and track the smallest card
        for e in hand:
            arr[e] += 1
            least = min(least, e)

        # Try to form groups starting from the smallest available card
        while least < len(arr):
            if arr[least] == 0:
                least += 1
                continue

            count = arr[least]
            # Try to form a group of size groupSize starting from 'least'
            for i in range(groupSize):
                if arr[least + i] < count:
                    return False
                arr[least + i] -= count

        return True