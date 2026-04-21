class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> ret;
        vector<vector<string>> vec;
        int m = strs.size();
        if(m == 0) return vec;

        for(int i=0; i<m; i++) {
            string str(strs[i]);
            sort(str.begin(), str.end());

            ret[str].push_back(strs[i]);
        }

        for(auto itr=ret.begin(); itr!=ret.end(); itr++) {
            vec.push_back(itr->second);
        }
        return vec;
    }
};
