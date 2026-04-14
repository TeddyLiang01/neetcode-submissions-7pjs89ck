class Solution {
public:
    bool topologicalSort(unordered_map<int, vector<int>>& adjacencyList, unordered_set<int>& visited, vector<int>& sortedOrder, unordered_set<int>& path, int course) {
        if (path.count(course) > 0) return false;
        if (visited.count(course) > 0) return true;
        visited.insert(course);
        path.insert(course);

        for (auto c : adjacencyList[course]) {
            if (!topologicalSort(adjacencyList, visited, sortedOrder, path, c)) return false;
        }

        path.erase(course);
        sortedOrder.push_back(course);
        return true;
    }
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int, vector<int>> adjacencyList;

        for (int i = 0; i < prerequisites.size(); ++i) {
            vector<int>& prereq = prerequisites[i];
            if (adjacencyList.count(prereq[0]) <= 0) {
                adjacencyList[prereq[0]] = {prereq[1]};
            } else {
                adjacencyList[prereq[0]].push_back(prereq[1]);
            }
        }

        unordered_set<int> visited;
        unordered_set<int> path;
        vector<int> sortedOrder;
        for (int i = 0; i < numCourses; ++i) {
            if (!topologicalSort(adjacencyList, visited, sortedOrder, path, i)) {
                return {};
            }
        }
        return sortedOrder;
    }
};

// topological ordering

