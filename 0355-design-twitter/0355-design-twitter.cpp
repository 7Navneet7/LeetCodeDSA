#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <tuple>

using namespace std;

class Twitter {
private:
    int timestamp;
    unordered_map<int, vector<pair<int, int>>> user_tweets; // userId -> list of {time, tweetId}
    unordered_map<int, unordered_set<int>> follows;         // userId -> set of followees

public:
    Twitter() {
        timestamp = 0;
    }
    
    void postTweet(int userId, int tweetId) {
        user_tweets[userId].push_back({timestamp++, tweetId});
    }
    
    vector<int> getNewsFeed(int userId) {
        // Max-heap storing {timestamp, tweetId, followeeId, tweetIndex}
        priority_queue<tuple<int, int, int, int>> max_heap;

        // User views their own tweets as well
        follows[userId].insert(userId);

        for (int followeeId : follows[userId]) {
            auto& tweets = user_tweets[followeeId];
            if (!tweets.empty()) {
                int last_idx = tweets.size() - 1;
                max_heap.push({tweets[last_idx].first, tweets[last_idx].second, followeeId, last_idx});
            }
        }

        vector<int> news_feed;
        while (!max_heap.empty() && news_feed.size() < 10) {
            auto [time, tweetId, followeeId, idx] = max_heap.top();
            max_heap.pop();
            news_feed.push_back(tweetId);

            if (idx > 0) {
                auto& tweets = user_tweets[followeeId];
                max_heap.push({tweets[idx - 1].first, tweets[idx - 1].second, followeeId, idx - 1});
            }
        }

        return news_feed;
    }
    
    void follow(int followerId, int followeeId) {
        follows[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        if (followerId != followeeId) {
            follows[followerId].erase(followeeId);
        }
    }
};