class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> onedp(n);

        if(n > 0) onedp[0] = nums[0];
        if(n > 1) onedp[1] = nums[1];
        if(n > 2) onedp[2] = nums[0] + nums[2];

        for(int i=3; i<n; i++) {
            onedp[i] = nums[i] + max(onedp[i-2], onedp[i-3]);
        }

        if(n-2 >= 0) return max(onedp[n-2], onedp[n-1]);
        if(n-1 >= 0) return onedp[n-1];
        return 0;
    }
};
