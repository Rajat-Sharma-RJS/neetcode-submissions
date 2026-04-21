class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<pair<int, int>> numbers;
        for(int i=0; i<nums.size(); i++) {
            numbers.push_back({nums[i], i});
        }
        sort(numbers.begin(), numbers.end());
        int first = 0, last = numbers.size()-1;
        while(first < last) {
            int p1 = numbers[first].second, p2 = numbers[last].second;
            int val = numbers[first].first + numbers[last].first;
            if(val == target) {
                return vector<int>{min(p1, p2), max(p1, p2)};
            } else if (val < target) {
                first++;
            } else {
                last--;
            }
        }
        return vector<int>{-1, -1};
    }
};
