// https://leetcode.com/problems/group-anagrams/

// hash the string with its sorted version [bcz it will be same for other anagrams, as each anagrams as 
// same numbers of chars with same fq]. 
// then append the string to its anagram group. then append all groups under one vector and return it.

// TC : O(n*mlogm), where m is len of the longest string
// SC : O(n*m), as it stores each string of length up to m

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        
        vector<vector<string>> ans;
        unordered_map<string, vector<string>>mp;

        for(auto& str : strs){

            string s = str;
            sort(s.begin(), s.end());
            mp[s].push_back(str);
        }
        
        for(auto& [vecstr, vecstrs] : mp){
            
            ans.push_back(vecstrs);
        }

        return ans;
    }
};