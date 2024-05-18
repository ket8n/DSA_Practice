// https://leetcode.com/problems/top-k-frequent-elements/description/

// better soln : count the freqs, then sort the numbers according to freqs and choose top k.
// TC : O(nlogn)
// SC : O(n)

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        
        unordered_map<int, int> mp;
        
        for(auto& num : nums){
            mp[num]++;
        }

        vector<pair<int, int>> v;
        vector<int> ans;

        for(auto& [num, fq] : mp){
            v.push_back({fq, num});
        }

        sort(v.begin(), v.end());

        int i = v.size()-1;
        while(k--){
            ans.push_back(v[i].second);
            i--;
        }

        return ans;
    }
};

// optimal soln : use bucket sort[store the nums on the indeces such that index == freqs], and choose top k
// TC : O(n)
// SC : O(n)

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        
        int n=nums.size();
        unordered_map<int, int> mp;
        
        for(auto& num : nums){
            mp[num]++;
        }

        vector<vector<int>> bucket(n+1);
        vector<int> ans;

        for(auto& [num, fq] : mp){
            bucket[fq].push_back(num);
        }

        for(int i=n; i>=0; i--){

            if(ans.size() >= k) break;

            for(auto& it : bucket[i]){
                ans.push_back(it);
            }
        }

        return ans;
    }
};