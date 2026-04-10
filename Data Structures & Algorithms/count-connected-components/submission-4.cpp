class Solution {
public:
    void dfs(vector<vector<int>> &graph, vector<bool> &visited, int node) {
        visited[node] = true;
        for (int i = 0; i < visited.size(); ++i) {
            if (graph[node][i] == 1 && !visited[i]) dfs(graph, visited, i);
        }
    }

    int countComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> graph(n, vector<int>(n, 0));
        vector<bool> visited(n, false);

        for (auto &edge : edges) {
            graph[edge[0]][edge[1]] = 1;
            graph[edge[1]][edge[0]] = 1;
        }

        int count = 0;

        for (int i = 0; i < n; ++i) {
            if (!visited[i]) {
                count++;
                dfs(graph, visited, i);
            }
        }

        return count;
    }
};
