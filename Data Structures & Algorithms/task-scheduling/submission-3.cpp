class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char, int> taskCount;
        for (auto c : tasks) {
            taskCount[c]++;
        }
    
        vector<pair<int, char>> heap; // count, char
        for (auto& p : taskCount) {
            heap.push_back({p.second, p.first});
            push_heap(heap.begin(), heap.end());
        }

        int time = 0;
        queue<pair<char, vector<int>>> toProcess; // char, time to add, amount
        while (!heap.empty() || !toProcess.empty()) {
            time++;
            if (!heap.empty()) {
                pair<int, char> element = heap.front();
                pop_heap(heap.begin(), heap.end());
                heap.pop_back();
                if (element.first > 1) {
                    toProcess.push({element.second, {time + n, element.first - 1}});
                }
            }
            if (!toProcess.empty()) {
                pair<char, vector<int>> front = toProcess.front();
                if (front.second[0] == time) {
                    toProcess.pop();
                    heap.push_back({front.second[1], front.first});
                    push_heap(heap.begin(), heap.end());
                }  
            } 
        }
        return time;
    }
};
