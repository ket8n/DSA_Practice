// https://leetcode.com/problems/longest-consecutive-sequence/description/

// use hash set. now when traversing, check if the current num is
// starting for the seq or not, by checking num-1 does not exists. if 
// current num is starting then check for the seq why adding +1 until hash
// set has its seq nums, and record max seq.

// TC : O(n)
// SC : O(n)

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        
        unordered_set<int> st;
        st.insert(nums.begin(), nums.end());

        int maxi = 0;
        int n = nums.size();

        for(int i=0; i<n; i++){
            
            // check if the currNum is potential starting num
            // by checking that its left num [num-1] dne.
            if(st.find(nums[i]-1) == st.end()){

                int currlen = 1;
                while(st.find(nums[i]+currlen) != st.end()){
                    currlen++;
                }

                maxi = max(maxi, currlen);
            }
        }

        return maxi;
    }
};