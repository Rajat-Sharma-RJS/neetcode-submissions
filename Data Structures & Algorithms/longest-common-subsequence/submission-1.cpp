class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int m = text1.length(), n = text2.length();
        vector<vector<int>> lcs(m, vector<int>(n));

        for(int i=0; i<n; i++) {
            if(i == 0)                    lcs[0][0] = (text1[0] == text2[0]) ? 1 : 0;
            else if(text1[0] == text2[i]) lcs[0][i] = 1;
            else                          lcs[0][i] = lcs[0][i-1];
        }
        for(int i=1; i<m; i++) {
            if(text1[i] == text2[0]) lcs[i][0] = 1;
            else                     lcs[i][0] = lcs[i-1][0];
        }

        for(int i=1; i<m; i++) {
            for(int j=1; j<n; j++) {
                int value = lcs[i-1][j-1] + (text1[i] == text2[j] ? 1 : 0);
                lcs[i][j] = max(max(lcs[i][j-1], lcs[i-1][j]), value);
            }
        }
        return lcs[m-1][n-1];
    }
};
