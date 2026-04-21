class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        if (n < 2) return n;
        sort(nums.begin(), nums.end());

        int start = 0, count = 1, maxCount = 1;
        for(int i=1; i<n; i++) {
            if(nums[i] > nums[i-1] + 1) { // 2 -> 4
                maxCount = max(count, maxCount);
                start = i;
                count = 1;
            } else if (nums[i] == nums[i-1]) { // 2 -> 2
                // do nothing
                count = count*1;
            } else { // 2 -> 3
                count++;
            }
        }
        maxCount = max(count, maxCount);
        return maxCount; 
    }
};
