class Solution {
public:
    void pathHelper(int src, int dest, vector<int>& path,
                    vector<vector<int>>& ans, vector<vector<int>>& graph) {
        path.push_back(src);
        if (src == dest) {
            ans.push_back(path);
        } else {
            for (int v : graph[src]) {

                pathHelper(v, dest, path, ans, graph);
            }
        }
        path.pop_back();
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        int dest = graph.size() - 1;
        vector<vector<int>> ans;
        vector<int> path;
        pathHelper(0, dest, path, ans, graph);
        return ans;
    }
};