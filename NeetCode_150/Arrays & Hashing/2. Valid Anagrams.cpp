// https://leetcode.com/problems/valid-anagram/description/

// use hashmap and check if the freq matches or not [they must be 0 at the end, if they are equal].
// TC : O(n), SC : O(n)

class Solution {
public:
    bool isAnagram(string s, string t) {

        if(s.length() != t.length()) return false;

        unordered_map<char, int>mp;
        for(auto& ch : s){
            mp[ch]++;
        }
        for(auto& ch : t){
            mp[ch]--;
        }

        for(auto& [ch, fq] : mp){

            if(fq != 0) return false;
        }

        return true;
    }
};