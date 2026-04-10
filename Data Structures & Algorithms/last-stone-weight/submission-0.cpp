class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> maxHeap;
        for (int i : stones) {
            maxHeap.push(i);
        }

        while (maxHeap.size() > 1) {
            int stone1 = maxHeap.top();
            maxHeap.pop();
            int stone2 = maxHeap.top();
            maxHeap.pop();
            int smashedWeight = abs(stone1 - stone2);
            if (smashedWeight != 0) {
                maxHeap.push(smashedWeight);
            }
        }
        if (maxHeap.size() == 1) {
            return maxHeap.top();
        }
        return 0;
    }
};
