class Twitter {
public:
    unordered_map<int, unordered_set<int>> followeeMap;
    unordered_map<int, vector<pair<int, int>>> tweets;
    int time;
    Twitter() { time = 0; }

    void postTweet(int userId, int tweetId) {
        time++;
        tweets[userId].push_back({tweetId, time});
    }

    vector<int> getNewsFeed(int userId) {
        //user's tweet
        priority_queue<pair<int, int>> pq;
        for (auto tweet : tweets[userId]) {
            pq.push({tweet.second, tweet.first});
        }

        // followees tweet
        for (auto followe : followeeMap[userId]) {
            for (auto tweet : tweets[followe]) {
                pq.push({tweet.second, tweet.first});
            }
        }
        vector<int> ans;
        while (!pq.empty() && ans.size() < 10) {
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
    }

    void follow(int followerId, int followeeId) {
        followeeMap[followerId].insert(followeeId);
    }

    void unfollow(int followerId, int followeeId) {
        followeeMap[followerId].erase(followeeId);
    }
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */