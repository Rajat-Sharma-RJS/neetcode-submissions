class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> hash;
        for(int i=0; i<nums.size(); i++) {
            hash[nums[i]]++;
        }
        vector<int> ret;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        for(auto itr=hash.begin(); itr!=hash.end(); itr++) {
            if(pq.size() == k) {
                if(pq.top().first < itr->second) {
                    pq.pop();
                    pq.push({itr->second, itr->first});
                }
            } else {
                pq.push({itr->second, itr->first});
            }
        }
        while(!pq.empty()) {
            ret.push_back(pq.top().second);
            pq.pop();
        }
        return ret;
    }
};
