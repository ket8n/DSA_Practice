// we can use map that stores relationship of follow and unfollow. for getting feed, 
// we can use time variable that is stored incremented by one and using follower list, 
// we can retrieve tweets using max heap.

class Twitter {
private:
    unordered_map<int, set<int>> f;
    unordered_map<int, vector<pair<int, int>>> t;
    long long time;

public:
    Twitter() {
        time = 0;    
    }
    
    void postTweet(int userId, int tweetId) {
        t[userId].push_back({time++, tweetId});
    }
    
    vector<int> getNewsFeed(int userId) {
        
        priority_queue<pair<int, int>> pq;

        for(auto& it : t[userId]){
            pq.push(it);
        }

        for(auto& usr : f[userId]){

            for(auto& it : t[usr]){

                pq.push(it);
            }
        }

        vector<int> res;
        while(!pq.empty()){

            res.push_back(pq.top().second);
            if(res.size() >= 10) break;
            pq.pop();
        }

        return res;
    }
    
    void follow(int followerId, int followeeId) {
        
        if(followerId != followeeId){
            f[followerId].insert(followeeId);
        }
    }
    
    void unfollow(int followerId, int followeeId) {
        f[followerId].erase(followeeId);
    }
};