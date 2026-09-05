class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source,
                   int destination) {

        if (source == destination)
            return true;

        unordered_map<int, vector<int>> graph;

        for (auto& edge : edges) {
            int u = edge[0];
            int v = edge[1];
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
        vector<bool> vis(n, false);
        queue<int> q;
        vis[source] = true;
        q.push(source);

        while (!q.empty()) {
            int cur = q.front();
            q.pop();
            for (int x : graph[cur]) {
                if (vis[x] != true) {
                    vis[x] = true;
                    q.push(x);
                    if (x == destination) {
                        return true;
                    }
                }
            }
        }
        return false;
    }
};