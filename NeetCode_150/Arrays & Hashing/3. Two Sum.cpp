// https://leetcode.com/problems/two-sum/description/

// using hashing
// we will iterate array only once and check if there exist a number
// that when added to current number gives target, if it exists then
// we will return its index from map along with current index
// if dne then we will store the current array's value with its index
// and iterate throughout the array

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        
        int n=nums.size();
        unordered_map<int, int>mp; // {num, ind}
        vector<int> ans;

        for(int i=0; i<n; i++){

            if(mp.find(target-nums[i]) != mp.end()){
                
                ans.push_back(i);
                ans.push_back(mp[target-nums[i]]);
                break;
            }

            mp[nums[i]] = i;
        }

        return ans;
    }
};