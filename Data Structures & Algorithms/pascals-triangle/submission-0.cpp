class Solution {
public:
    unordered_map<int, vector<int>> store;
    int curr = 0;

    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> vec;
        if(store.find(numRows) == store.end()) {
            if(curr == 0) {
                store[1] = vector<int>{1};
                curr = 1;
            }
            for(int len=curr+1; len<=numRows; len++) {
                vector<int> arr;
                arr.push_back(1);
                for(int i=1; i<store[len-1].size(); i++) {
                    arr.push_back(store[len-1][i-1]+store[len-1][i]);
                }
                arr.push_back(1);
                store[len] = arr;
            }
        }

        for(int i=1; i<=numRows; i++) {
            vec.push_back(store[i]);
        }
        curr = numRows;
        return vec;
    }
};