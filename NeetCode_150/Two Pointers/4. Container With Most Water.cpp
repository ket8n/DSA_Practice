// https://leetcode.com/problems/container-with-most-water/description/

// area will be product of min(height of i , height of j) and width btw i and j.
// to maximize the product, we can initially try max width i.e. i==0 and j==n-1
// and at each iteration, width is going to decrease by 1. so we greedily
// disregard the pointer of small height and move accordingly.

// TC : O(n)
// SC : O(1)

class Solution {
public:
    int maxArea(vector<int>& height) {
        
        int i = 0, j = height.size()-1;
        int maxi = INT_MIN;

        while(i<j){

            int area = min(height[i], height[j])*(j-i);
            maxi = max(maxi, area);

            if(height[i] < height[j]){
                i++;
            }
            else if(height[i] > height[j]){
                j--;
            }
            else{
                i++;
                j--;
            }
        }

        return maxi;
    }
};