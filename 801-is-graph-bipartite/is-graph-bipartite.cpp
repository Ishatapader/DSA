class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int V = graph.size();
        queue<int> q;
        vector<int> color(V, -1);
        for (int i = 0; i < V; i++) {
            if (color[i] != -1) {
                continue;
            }
                q.push(i);
                color[i] = 0;
                while (q.size() > 0) {
                    int curr = q.front();
                    q.pop();
                    

                    for (int v : graph[curr]) {
                        if (color[v] == -1) {

                            color[v] = !color[curr];
                            q.push(v);
                    
                        }else {
                            if (color[v] == color[curr]) {
                                return false;
                            }
                        }
                    }
                }
            }
        return true;
    }
};