// we make decision of single digit all the times, but for 2 digits, we check if the 
// current digit [i.e. also first digit for two digit] is 1 or 2, if it is 1, then 
// any number [0-1] is accepted, but if current digit is 2 then the second digit must 
// be in range [0-6] inclusive. and if current digit is > 3 then we only consider it 
// for single digit. and any time we encounter 0, we return 0

class Solution {
public:

    int dfs(int ind, string& s){

        int n = s.length();

        if(ind == n){
            return 1;
        }

        if(s[ind] == '0'){
            return 0;
        }

        int res = dfs(ind+1, s);

        if(ind < n-1 && (s[ind]=='1' 
        || s[ind] == '2' && s[ind+1] < '7')){
            
            res += dfs(ind+2, s);
        }

        return res;
    }

    int numDecodings(string s) {
        
        int ans = dfs(0, s);
        return ans;
    }
};

// Memoize : 

class Solution {
public:

    int dfs(int ind, string& s, vector<int>& dp){

        int n = s.length();

        if(ind == n){
            return 1;
        }

        if(dp[ind] != -1){
            return dp[ind];
        }

        if(s[ind] == '0'){
            return 0;
        }

        int res = dfs(ind+1, s, dp);

        if(ind < n-1 && (s[ind]=='1' 
        || s[ind] == '2' && s[ind+1] < '7')){
            
            res += dfs(ind+2, s, dp);
        }

        return dp[ind] = res;
    }

    int numDecodings(string s) {
        
        int n = s.length();

        vector<int> dp(n, -1);

        int ans = dfs(0, s, dp);
        return ans;
    }
};

// Tabulation : 

class Solution {
public:

    int dfs(int ind, string& s, vector<int>& dp){

        int n = s.length();

        if(ind == n){
            return 1;
        }

        if(dp[ind] != -1){
            return dp[ind];
        }

        if(s[ind] == '0'){
            return 0;
        }

        int res = dfs(ind+1, s, dp);

        if(ind < n-1 && (s[ind]=='1' 
        || s[ind] == '2' && s[ind+1] < '7')){
            
            res += dfs(ind+2, s, dp);
        }

        return dp[ind] = res;
    }

    int numDecodings(string s) {
        
        int n = s.length();

        // vector<int> dp(n, -1);

        // int ans = dfs(0, s, dp);
        // return ans;

        vector<int> dp(n+1, 0);
        dp[n] = 1;

        if(s[0] == '0') return 0;

        for(int ind=n-1; ind>=0; ind--){

            if(s[ind] == '0'){
                dp[ind] = 0;
                continue;
            }

            int res = dp[ind+1];

            if(ind < n-1 && (s[ind]=='1' 
            || s[ind] == '2' && s[ind+1] < '7')){
                
                res += dp[ind+2];
            }

            dp[ind] = res;
        }

        return dp[0];
    }
};

// Space Optimized : 

class Solution {
public:

    int dfs(int ind, string& s, vector<int>& dp){

        int n = s.length();

        if(ind == n){
            return 1;
        }

        if(dp[ind] != -1){
            return dp[ind];
        }

        if(s[ind] == '0'){
            return 0;
        }

        int res = dfs(ind+1, s, dp);

        if(ind < n-1 && (s[ind]=='1' 
        || s[ind] == '2' && s[ind+1] < '7')){
            
            res += dfs(ind+2, s, dp);
        }

        return dp[ind] = res;
    }

    int numDecodings(string s) {
        
        int n = s.length();

        // vector<int> dp(n, -1);

        // int ans = dfs(0, s, dp);
        // return ans;

        // vector<int> dp(n+1, 0);
        // dp[n] = 1;

        int one = 1;
        int two = 0;

        if(s[0] == '0') return 0;

        for(int ind=n-1; ind>=0; ind--){

            if(s[ind] == '0'){

                two = one;
                one = 0;

                continue;
            }

            int res = one;

            if(ind < n-1 && (s[ind]=='1' 
            || s[ind] == '2' && s[ind+1] < '7')){
                
                res += two;
            }

            two = one;
            one = res;
        }

        return one;
    }
};