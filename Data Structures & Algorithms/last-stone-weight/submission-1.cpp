class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> maxqueue; // weight
        for (int n : stones) {
            maxqueue.push(n);
        }

        while (maxqueue.size() > 1) {
            int s1 = maxqueue.top();
            maxqueue.pop();
            int s2 = maxqueue.top();
            maxqueue.pop();

            if (s2 != s1) {
                maxqueue.push(s1 - s2);
            }
        }

        if (maxqueue.size() == 1) {
            return maxqueue.top();
        }
        return 0;
    }
};
