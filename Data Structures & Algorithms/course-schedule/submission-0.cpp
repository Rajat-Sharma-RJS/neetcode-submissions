class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> graph(numCourses);
        vector<int> indeg(numCourses), visited(numCourses);

        for(int i=0; i<prerequisites.size(); i++) {
            int u = prerequisites[i][1], v = prerequisites[i][0];
            graph[u].push_back(v);
            indeg[v]++;
        }
        // topological sort -> kahn's algo
        int count = 0;
        queue<int> que;

        for(int i=0; i<numCourses; i++) {
            if(indeg[i] == 0) {
                que.push(i);
                visited[i] = 1;
                count++;
            }
        }

        while(!que.empty()) {
            // delete que's top
            int u = que.front();
            que.pop();

            for(int i=0; i<graph[u].size(); i++) {
                int v = graph[u][i];
                if(visited[v] == 0) {
                    indeg[v]--;
                    if(indeg[v] == 0) {
                        que.push(v);
                        visited[v] = 1;
                        count++;
                    }
                }
            }
        }
        if(count == numCourses) return true;
        return false;
    }
};
