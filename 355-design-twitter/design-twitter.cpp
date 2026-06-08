class Twitter {
private:
    int timer; 
    unordered_map<int, unordered_set<int>> following ; 
     unordered_map<int, vector<pair<int, int>>> tweets;

public:
    // Constructor System start hone par timer 0 se shuru hoga
    Twitter() {
        timer = 0;
    }
    
    // Naya tweet post karna
    void postTweet(int userId, int tweetId) {
        tweets[userId].push_back({timer++, tweetId});
    }
    
    vector<int> getNewsFeed(int userId) {
        priority_queue<pair<int, int>> pq;
        
        int myTweetsCount = tweets[userId].size();
        for(int i = max(0, myTweetsCount - 10); i < myTweetsCount; i++) {
            pq.push(tweets[userId][i]);
        }
        
        // 2. User JINKO FOLLOW karta hai, unke bhi aakhiri 10 tweets heap mein daalo
        for(int followeeId : following[userId]) {
            int theirTweetsCount = tweets[followeeId].size();
            for(int i = max(0, theirTweetsCount - 10); i < theirTweetsCount; i++) {
                pq.push(tweets[followeeId][i]);
            }
        }
        
        // 3. Heap se top 10 (sabse naye) tweets nikal lo
        vector<int> feed;
        int count = 0;
        // Wahi condition jo tumne sochi thi!
        while(!pq.empty() && count < 10) {
            feed.push_back(pq.top().second); // Humein result mein sirf tweetId chahiye
            pq.pop();
            count++;
        }
        
        return feed;
    }
    
    // Follow karna
    void follow(int followerId, int followeeId) {
        following[followerId].insert(followeeId);
    }
    
    // Unfollow karna
    void unfollow(int followerId, int followeeId) {
        following[followerId].erase(followeeId);
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