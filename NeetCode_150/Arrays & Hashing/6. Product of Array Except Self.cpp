// https://leetcode.com/problems/product-of-array-except-self/description/

// approach : calculate forward products[except num at that index] and backward products[except num at that
// index]. then multiple these forward backward at their indeces and return as answer. 
// this works as the forward product array[prefix] has product of nums upto i-1 for ith [means ith num is 
// not present] and backward product array[suffix] has product of nums from n-1 to i+1th [means ith num 
// is not present]. hence multiplying these two will give ans array.

// TC : O(n)
// SC : O(n).

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        
        int n=nums.size();

        vector<int> prefix(n), suffix(n);
        prefix[0]=1;
        suffix[n-1]=1;

        for(int i=1; i<n; i++){

            prefix[i] += prefix[i-1]*nums[i-1];
        }

        for(int i=n-2; i>=0; i--){

            suffix[i] += suffix[i+1]*nums[i+1];
        }

        vector<int> ans(n);

        for(int i=0; i<n; i++){

            ans[i] = prefix[i]*suffix[i];
        }

        return ans;
    }
};

// space optimized : TC : O(n), SC : O(1)

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        
        int n=nums.size();
        vector<int> ans(n);

        int prefix = 1;
        int postfix = 1;

        for(int i=0; i<n; i++){

            ans[i] = prefix;
            prefix *= nums[i];
        }

        for(int i=n-1; i>=0; i--){

            ans[i] *= postfix;
            postfix *= nums[i];
        }

        return ans;
    }
};