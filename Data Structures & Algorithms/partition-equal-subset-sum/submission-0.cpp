class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        for(int i=0; i<n; i++) sum += nums[i];
        if(sum % 2 == 1) return 0;
        // even sum
        int target = sum/2;
        // is it knapsack ?
        sort(nums.begin(), nums.end());
        vector<vector<int>> dp(n+1, vector<int>(target+1));
        for(int i=0; i<=n; i++) {
            for(int j=0; j<=target; j++) {
                if(i == 0 && j == 0) dp[i][j] = 1;
                else if(i == 0) dp[i][j] = 0;
                else if(j == 0) dp[i][j] = 0;
                else if(j < nums[i-1]) dp[i][j] = dp[i-1][j];
                else dp[i][j] = dp[i-1][j] | dp[i-1][j-nums[i-1]];
            }
        }
        return dp[n][target];
    }
};
