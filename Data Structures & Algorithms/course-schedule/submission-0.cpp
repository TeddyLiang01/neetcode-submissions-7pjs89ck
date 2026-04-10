class Solution {
public:
    bool dfs(int curCourse, unordered_map<int, vector<int>> &prereqList, unordered_set<int> &visiting) {
        if (visiting.count(curCourse) > 0) return false;
        if (prereqList[curCourse].empty()) return true;

        visiting.insert(curCourse);
        for (int course : prereqList[curCourse]) {
            if (!dfs(course, prereqList, visiting)) return false;
        }
        visiting.erase(curCourse);
        prereqList[curCourse] = {};
        return true;
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int, vector<int>> prereqList;
        for (auto &pair : prerequisites) {
            if (prereqList.count(pair[0]) == 0) prereqList[pair[0]] = {pair[1]};
            else prereqList[pair[0]].push_back(pair[1]);
            if (prereqList.count(pair[1]) == 0) prereqList[pair[1]] = {};
        }
        unordered_set<int> visiting;

        for (int i = 0; i < numCourses; ++i) {
            if (!dfs(i, prereqList, visiting)) return false;
        }
        return true;
        
    }
};
