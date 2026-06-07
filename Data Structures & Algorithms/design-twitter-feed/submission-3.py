class Twitter:

    def __init__(self):
        self.tweets = defaultdict(list)
        self.followMap = defaultdict(set)
        self.i = 0

    def postTweet(self, userId: int, tweetId: int) -> None:
        self.tweets[userId].append([self.i, tweetId])
        self.i -= 1   # timestamp decreases so newer = smaller
        

    def getNewsFeed(self, userId: int) -> List[int]:
        minHeap = []

        for pair in self.tweets[userId]:
            heapq.heappush(minHeap, pair)

        for fId in self.followMap[userId]:
            for pair in self.tweets[fId]:
                heapq.heappush(minHeap, pair)

        top = heapq.nsmallest(10, minHeap)
        return [tweetId for (_, tweetId) in top]

    def follow(self, followerId: int, followeeId: int) -> None:
        if followerId != followeeId:
            self.followMap[followerId].add(followeeId)

    def unfollow(self, followerId: int, followeeId: int) -> None:
        if followeeId in self.followMap[followerId]:
            self.followMap[followerId].remove(followeeId)