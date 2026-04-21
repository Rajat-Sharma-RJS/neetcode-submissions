class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        sort(coins.begin(), coins.end());
        vector<vector<int>> dp(n+1, vector<int>(amount+1));
        
        for(int i=0; i<=amount; i++) dp[0][i] = -1;
        for(int j=0; j<=n; j++) dp[j][0] = 0;
        for(int i=1; i<=n; i++) {
            for(int j=1; j<=amount; j++) {
                if(j < coins[i-1]) dp[i][j] = dp[i-1][j];
                else if(j % coins[i-1] == 0) dp[i][j] = j/coins[i-1];
                else {
                    int val = (dp[i][j-coins[i-1]] == -1) ? -1 : dp[i][j-coins[i-1]] + 1;
                    if(val == -1) dp[i][j] = dp[i-1][j];
                    else if(dp[i-1][j] != -1) dp[i][j] = min(val, dp[i-1][j]);
                    else dp[i][j] = val;
                }
            }
        }
        return dp[n][amount];
    }
};
