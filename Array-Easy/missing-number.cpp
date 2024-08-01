class Solution {
public:
    int missingNumber(vector<int>& nums) {
        
        int n = nums.size();
        int sum = n*(n+1)/2;
        for(auto& it : nums) sum -= it;
        return sum;
    }
};

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        
        int n = nums.size();
        int ans = n;
        for(int i=0; i<n; i++){
            ans = ans^i^nums[i];
        }
        return ans;
    }
};