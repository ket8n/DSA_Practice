class Solution {
public:
    int characterReplacement(string s, int k) {
        
        // len - maxFq => no of chars to be replaced

        int n = s.length();
        int i = 0, j = 0;
        int maxi = 0, maxFq = 0;
        vector<int> hash(26, 0);

        while(j < n){

            hash[s[j] - 'A']++;
            maxFq = max(maxFq, hash[s[j] - 'A']);

            while((j-i+1) - maxFq > k){

                hash[s[i] - 'A']--;
                maxFq = 0;
                for(int ind=0; ind<26; ind++){
                    maxFq = max(maxFq, hash[ind]);
                }
                i++;
            }
            
            maxi = max(maxi, j-i+1);
            j++;
        }

        return maxi;
    }
};