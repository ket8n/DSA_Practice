// https://leetcode.com/problems/longest-increasing-subsequence/description/

// Naive approach : create a new str according to constraints and check if it is palindrome or not
// TC : O(n)
// SC : O(n)

class Solution {
public:
    bool isPalindrome(string s) {
        
        string str = "";
        for(auto& ch : s){

            if(isalpha(ch) || isdigit(ch)){
                str += tolower(ch);
            }
        }

        int l=0, r=str.length()-1;

        while(l<=r){

            if(str[l++] != str[r--]){
                return false;
            }
        }
        
        return true;
    }
};

// Optimal approach : skip non alphanumeric char and check alphanumeric char for palindrome simultaneously
// TC : O(n)
// SC : O(1) 

class Solution {
public:
    bool isPalindrome(string s) {
        
        int l=0, r=s.length()-1;

        while(l <= r){

            if(!isalpha(s[l]) && !isdigit(s[l])){
                l++;
                continue;
            }

            if(!isalpha(s[r]) && !isdigit(s[r])){
                r--;
                continue;
            }

            if(tolower(s[l]) != tolower(s[r])){
                return false;
            }

            l++;
            r--;
        }

        return true;
    }
};
