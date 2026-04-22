class Solution {
public:
    int dfs(int i, vector<int>& visited, vector<vector<int>>& undag) {
        visited[i] = 1;
        int val = 1;
        for(int j=0; j<undag[i].size(); j++) {
            if(visited[undag[i][j]] == 0) {
                val += dfs(undag[i][j], visited, undag);
            }
        }
        return val;
    }

    int countComponents(int n, vector<vector<int>>& edges) {
        vector<int> visited(n);
        vector<vector<int>> undag(n);

        for(int i=0; i<edges.size(); i++) {
            int a = edges[i][0], b = edges[i][1];
            undag[a].push_back(b);
            undag[b].push_back(a);
        }

        int count = 0, sccomp = 0;
        while(count < n) {
            for(int i=0; i<n; i++) {
                if(visited[i] == 0) {
                    count += dfs(i, visited, undag);
                    sccomp++;
                }
            }
        }
        return sccomp;
    }
};
