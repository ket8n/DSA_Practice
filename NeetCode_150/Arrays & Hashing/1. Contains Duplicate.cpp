// https://leetcode.com/problems/contains-duplicate/description/

// approach 1 [Better/optimal soln] : simply sort the original array [or first create a duplicate array to 
// preverse the original array and then sort the duplicate array] and check if adjacent nums are equal or not.
// TC : O(nlogn), SC : O(1)
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(), nums.end());
        bool ans = false;
        for(int i=1; i<n; i++){
            if(nums[i] == nums[i-1]){
                ans = true;
                break;
            }
        }
        return ans;
    }
};

// approach 2 [Better/optimal soln] : use unordered map [or unordered set] to count the frequncy of the nums
// as soon as a num with frequncy > 1 is encountered, return true [i.e. duplicate exists].
// TC : O(n), SC : O(n)
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        int n=nums.size();
        unordered_map<int, int>mp;
        bool ans = false;
        for(int i=0; i<n; i++){
            if(++mp[nums[i]] > 1){
                ans = true;
                break;
            }
        }
        return ans;
    }
};
