class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size(), count = 1;
        vector<int> lis(n, 1);
        for(int i=1; i<n; i++) {
            for(int j=0; j<i; j++) {
                if(nums[j] < nums[i]) lis[i] = max(lis[i], lis[j]+1);
            }
            count = max(count, lis[i]);
        }
        return count;
    }
};
