// brute force

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
        int n = s.length();
        int ans = 0;
        
        for(int i=0; i<n; i++){

            unordered_set<char> st;
            for(int j=i; j<n; j++){
                
                if(st.find(s[j]) != st.end()){
                    break;
                }

                st.insert(s[j]);
                ans = max(ans, j-i+1);
            }
        }        

        return ans;
    }
};

// better

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
        int n = s.length();
        int i = 0, j = 0;
        int ans = 0;
        unordered_set<int> st;

        while(j < n){

            if(st.find(s[j]) != st.end()){

                while(i < j && st.find(s[j]) != st.end()){
                    st.erase(s[i]);
                    i++;
                }
            }

            st.insert(s[j]);
            ans = max(ans, (int)st.size());
            j++;
        }

        return ans;
    }
};

// optimal

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
        int n = s.length();
        int i = 0, j = 0;
        int ans = 0;
        vector<int> hash(256, -1);

        while(j < n){

            if(hash[s[j]] != -1){

                if(hash[s[j]] >= i){
                    i = hash[s[j]] + 1;
                }
            }

            hash[s[j]] = j;
            ans = max(ans, j-i+1);  
            j++;    
        }

        return ans;
    }
};