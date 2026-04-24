class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        // ni + nj + nk = 0
        // -> ni + nj = -nk
        sort(nums.begin(), nums.end());
        set<vector<int>> ret;
        int n = nums.size();

        for(int i=0; i<=n-3; i++) {
            int target = 0-nums[i];
            int p = i+1, q = n-1;
            while(p < q) {
                if(nums[p] + nums[q] == target) {
                    vector<int> v1{nums[p], nums[q], nums[i]};
                    sort(v1.begin(), v1.end());
                    ret.insert(v1);
                    p++;
                    q--;
                } else if(nums[p] + nums[q] > target) {
                    q--;
                } else {
                    p++;
                }
            }
        }
        vector<vector<int>> ans;
        for(auto itr=ret.begin(); itr!=ret.end(); itr++) {
            ans.push_back(*itr);
        }
        return ans;
    }
};
