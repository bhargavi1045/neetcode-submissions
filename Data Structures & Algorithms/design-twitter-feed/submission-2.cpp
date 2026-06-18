class Twitter {
public:
    unordered_map<int,set<int>> follower;
    unordered_map<int,vector<pair<int,int>>> tweetMap;
    int time;

    Twitter() {
        time=0;
    }
    
    void postTweet(int userId, int tweetId) {
        time++;
        tweetMap[userId].push_back({time,tweetId});
    }
    
    vector<int> getNewsFeed(int userId) {

        vector<int> newsFeedTweets;
        priority_queue<pair<int,int>> maxHeap;

        if(tweetMap.find(userId)!=tweetMap.end()){
            for(int i=0;i<tweetMap[userId].size();i++){
                maxHeap.push(tweetMap[userId][i]);
            }
        }

        for(auto flwr : follower[userId]){
            if(tweetMap.find(flwr)!=tweetMap.end()){
                for(int i=0;i<tweetMap[flwr].size();i++){
                    maxHeap.push(tweetMap[flwr][i]);
                }
            }
        }
        
        while(!maxHeap.empty() && newsFeedTweets.size()<10){
            int tweet=maxHeap.top().second;
            maxHeap.pop();

            newsFeedTweets.push_back(tweet);
        }
        
        return newsFeedTweets;
    }
    
    void follow(int followerId, int followeeId) {
        if(followerId==followeeId) return;
        follower[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        follower[followerId].erase(followeeId);
    }
};
