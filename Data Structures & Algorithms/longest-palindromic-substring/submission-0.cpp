class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.length(), p = 0, q = 0;
        vector<vector<int>> lps(n, vector<int>(n));

        for(int i=n-1; i>=0; i--) {
            for(int j=i; j<n; j++) {
                if(j == i)        lps[i][i] = 1;
                else if(j == i+1) lps[i][i+1] = (s[i] == s[i+1]) ? 1 : 0;
                else              lps[i][j] = (lps[i+1][j-1] == 1 && s[i] == s[j]) ? 1 : 0;
                if(lps[i][j] == 1 && (q-p) < (j-i)) {
                    p = i;
                    q = j;
                }
            }
        }

        string str;
        for(int i=p; i<=q; i++) str.push_back(s[i]);
        return str;
    }
};
