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

        // {time, tweetId, userId, index}
        priority_queue<vector<int>> pq;

        if (!tweets[userId].empty()) {
            int idx = tweets[userId].size() - 1;
            pq.push({tweets[userId][idx].second, // time
                     tweets[userId][idx].first,  // tweetId
                     userId, idx});
        }
        for (int followee : followeeMap[userId]) {
            if (!tweets[followee].empty()) {
                int idx = tweets[followee].size() - 1;
                pq.push({tweets[followee][idx].second,
                         tweets[followee][idx].first, followee, idx});
            }
        }
        vector<int> ans;
        while (!pq.empty() && ans.size() < 10) {
            vector<int> curr = pq.top();
            pq.pop();

            int tweetId = curr[1];
            int user = curr[2];
            int idx = curr[3];
            ans.push_back(tweetId);

            // push provious tweet of the same user
            idx--;

            if (idx >= 0) {
                pq.push({tweets[user][idx].second, tweets[user][idx].first,
                         user, idx});
            }
        }
        return ans;
    }

    void follow(int followerId, int followeeId) {
        if (followerId != followeeId) {

            followeeMap[followerId].insert(followeeId);
        }
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