class Twitter {
    const int requiredFeedSize = 10; 
    unordered_map<int, unordered_set<int>> st;
    vector<pair<int, int>> q;
    
    void addRecentTweets(vector<pair<int, int>>& q, vector<int>& feed, int user) {
        if(feed.size() == requiredFeedSize || !q.size()) {
            return;
        }
        
        int userId = q.back().first;
        int tweetId = q.back().second;
        q.pop_back();
        
        if(user == userId) {
            feed.push_back(tweetId);
        } else{
            if(st[userId].count(user)) {
                feed.push_back(tweetId);
            }
        }
        
        addRecentTweets(q, feed, user);
        q.push_back({userId, tweetId});
    }
public:
    Twitter() {
        
    }
    
    void postTweet(int userId, int tweetId) {
        q.push_back({userId, tweetId});
    }
    
    vector<int> getNewsFeed(int userId) {
        vector<int> feed;
        addRecentTweets(q, feed, userId);
        return feed;
    }
    
    void follow(int followerId, int followeeId) {
        st[followeeId].insert(followerId);
    }
    
    void unfollow(int followerId, int followeeId) {
        st[followeeId].erase(followerId);
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