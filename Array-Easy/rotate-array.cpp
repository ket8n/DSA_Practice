class Solution {
public:
    void rotate(vector<int>& nums, int k) {

        int n = nums.size();  
        k %= n;      
        vector<int> ans(n);
        int i = n-k;
        int j = 0;
        while(n--){
            ans[j++] = nums[(i++)%nums.size()];
        }
        for(i=0; i<nums.size(); i++){
            nums[i] = ans[i];
        }
    }
};

class Solution {
public:
    void rotate(vector<int>& nums, int k) {

        k %= nums.size();      
        reverse(nums.end()-k, nums.end());
        reverse(nums.begin(), nums.end()-k);
        reverse(nums.begin(), nums.end());
    }
};