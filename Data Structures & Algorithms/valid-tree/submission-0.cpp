class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        if (edges.size() != n - 1) return false;
        queue<int> que;
        vector<vector<int>> adj(n);

        for(int i=0; i<edges.size(); i++) {
            int u = edges[i][0], v = edges[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<int> dad(n, -1);
        vector<int> visited(n);

        que.push(0);
        visited[0] = 1;
        int visitedCount = 0;

        while(!que.empty()) {
            int u = que.front();
            que.pop();
            visitedCount++;

            for(int i=0; i<adj[u].size(); i++) {
                int v = adj[u][i];
                if(visited[v] == 0) {
                    dad[v] = u;
                    visited[v] = 1;
                    que.push(v);
                } else {
                    if(dad[u] != v) return false;
                }
            }
        }
        return visitedCount == n;
    }
};
