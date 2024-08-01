class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        
        int n = nums.size();
        int cnt = 0;
        
        int i=0, j=0;
        while(j < n){

            if(nums[j] != 0){
                nums[i] = nums[j];
                i++;
            }
            else{
                cnt++;
            }
            j++;
        }

        for(i=n-cnt; i<n; i++){
            nums[i] = 0;
        }
    }
};