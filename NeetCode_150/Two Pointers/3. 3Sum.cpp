// https://leetcode.com/problems/3sum/description/

// The optimal approach is to sort the array traverse the array, in the loop we are fixing 
// the 1st element to the current element. we need 2 more element so it reduces to 2 sum approach, 
// we will be using 2 pointer method because the array is sorted and we can point to elements
// according to the need if sum is < 0 or > 0.

// TC : O(n^2)
// SC : O(1), assuming we dont count the return array as extra memory

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        
        int n = nums.size();

        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());

        for(int i=0; i<n; i++){

            // skip same numbers to avoid duplicate
            if(i > 0 && nums[i] == nums[i-1]) continue;

            int j=i+1, k=n-1;
            
            while(j < k){

                int sum = nums[i]+nums[j]+nums[k];
                if(sum == 0){
                    
                    ans.push_back({nums[i], nums[j], nums[k]});
                    j++;
                    k--;
                    
                    // ensure next for j and k are elements are unique
                    while(j<k && nums[j]==nums[j-1]){
                        j++;
                    }
                    while(j<k && nums[k]==nums[k+1]){
                        k--;
                    }
                }
                else if(sum > 0){
                    k--;
                }
                else{
                    j++;
                }
            }   
        }

        return ans;
    }
};