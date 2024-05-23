// https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/description/

// basic 2 pointers question : taking advantage of sorted array, we can point to first and last numbers
// and check if their sum makes up to target or not, if not move towards the target direction by increasing
// first pointer if sum is < target OR move last target backward if sum is > target

// TC : O(n)
// SC : O(1)

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        
        int i = 0;
        int j = numbers.size()-1;

        while(i < j){

            if(numbers[i]+numbers[j] == target){
                return {i+1, j+1};
            }

            if(numbers[i]+numbers[j] > target){
                j--;
            }
            else{
                i++;
            }
        }

        return {-1};
    }
};