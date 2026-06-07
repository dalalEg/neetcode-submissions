class Twitter {
    map<int, vector<pair<int, int>>> tweets; // userId -> list of (timestamp, tweetId)
    map<int,set<int>>followee;
    int id;
public:
    Twitter() {
        id=0;
    }
    
    void postTweet(int userId, int tweetId) {
        tweets[userId].push_back({id,tweetId});
        id++;
    }
    
    vector<int> getNewsFeed(int userId) {
    priority_queue<pair<int, int>> pq; // (timestamp, tweetId)

    // Add user's tweets
    for (auto& [time, tweet] : tweets[userId]) {
        pq.push({time, tweet});
    }

    // Add followees' tweets
    for (int fId : followee[userId]) {
        for (auto& [time, tweet] : tweets[fId]) {
            pq.push({time, tweet});
        }
    }

    vector<int> res;
    for (int i = 0; i < 10 && !pq.empty(); i++) {
        res.push_back(pq.top().second);
        pq.pop();
    }
    return res;


    }
    
    void follow(int followerId, int followeeId) {
        if(followerId==followeeId)
         return;
        followee[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        if(followerId==followeeId)
         return;
        followee[followerId].erase(followeeId);

    }
};
