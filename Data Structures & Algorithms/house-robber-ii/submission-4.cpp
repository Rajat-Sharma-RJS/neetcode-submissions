class Solution {
public:
    int robArr(vector<int>& nums, int low, int high) {
        int n = high-low+1;
        vector<int> onedp(n);

        if(n > 0) onedp[0] = nums[low];
        if(n > 1) onedp[1] = nums[low + 1];
        if(n > 2) onedp[2] = nums[low + 0] + nums[low + 2];

        for(int i=3; i<n; i++) {
            onedp[i] = nums[low + i] + max(onedp[i-2], onedp[i-3]);
        }

        if(n-2 >= 0) return max(onedp[n-2], onedp[n-1]);
        if(n-1 >= 0) return onedp[n-1];
        return 0;
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 0) return 0;
        if(n == 1) return nums[0];
        if(n == 2) return max(nums[0], nums[1]);
        
        int robArr1 = robArr(nums, 0, n-2);
        int robArr2 = robArr(nums, 1, n-1);
        return max(robArr1, robArr2);
    }
};
