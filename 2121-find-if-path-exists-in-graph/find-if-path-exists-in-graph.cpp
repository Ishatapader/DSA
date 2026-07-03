class Solution {
public:
    bool hasPath(int src, int dest, vector<bool>& vis,
                 vector<vector<int>>& graph) {
        if (src == dest) {
            return true;
        }
        vis[src] = true;
        for (int v : graph[src]) {
            if (!vis[v]) {
                if (hasPath(v, dest, vis, graph)) {
                    return true;
                }
            }
        }
        return false;
    }
    bool validPath(int n, vector<vector<int>>& edges, int source,
                   int destination) {
        vector<vector<int>> graph(n);
        for (auto edge : edges) {
            int u = edge[0];
            int v = edge[1];
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
        vector<bool> vis(n, false);
        return hasPath(source, destination, vis, graph);
    }
};