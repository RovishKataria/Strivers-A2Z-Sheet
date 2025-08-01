// https://www.naukri.com/code360/problems/design-twitter_8380711
// https://www.geeksforgeeks.org/problems/design-twitter/1
// https://leetcode.com/problems/design-twitter/
// https://www.youtube.com/watch?v=pNichitDD2E

class Twitter {
private:
    int count;
    unordered_map<int, vector<pair<int, int>>> tweetMap; // userId -> list of [count, tweetId]
    unordered_map<int, unordered_set<int>> followMap; // userId -> set of followeeId

    struct Tweet {
        int count;
        int tweetId;
        int followeeId;
        int index;
        bool operator<(const Tweet& other) const {
            return count > other.count;
        }
    };

public:
    Twitter() {
        count = 0;
    }
    
    void postTweet(int userId, int tweetId) {
        tweetMap[userId].push_back({count--, tweetId});
    }
    
    vector<int> getNewsFeed(int userId) {
        vector<int> res;
        priority_queue<Tweet> minHeap;

        followMap[userId].insert(userId);
        for (int followeeId : followMap[userId]) {
            if (tweetMap.find(followeeId) != tweetMap.end() && !tweetMap[followeeId].empty()) {
                int index = tweetMap[followeeId].size() - 1;
                minHeap.push({tweetMap[followeeId][index].first, tweetMap[followeeId][index].second, followeeId, index - 1});
            }
        }

        while (!minHeap.empty() && res.size() < 10) {
            Tweet tweet = minHeap.top();
            minHeap.pop();
            res.push_back(tweet.tweetId);

            if (tweet.index >= 0) {
                minHeap.push({tweetMap[tweet.followeeId][tweet.index].first, tweetMap[tweet.followeeId][tweet.index].second, tweet.followeeId, tweet.index - 1});
            }
        }
        return res;
    }
    
    void follow(int followerId, int followeeId) {
        followMap[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        if (followeeId != followerId && followMap.find(followerId) != followMap.end()) {
            followMap[followerId].erase(followeeId);
        }
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
