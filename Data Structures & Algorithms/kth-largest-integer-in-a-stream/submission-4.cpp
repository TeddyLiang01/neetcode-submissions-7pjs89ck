class KthLargest {
public:
    priority_queue<int, vector<int>, greater<int>> minHeap;
    int kth;

    KthLargest(int k, vector<int>& nums) : kth{k} {
        for (int &n : nums) {
            add(n);
        }

    }
    
    int add(int val) {
        if (minHeap.size() < kth) minHeap.push(val);
        else if (minHeap.top() < val) {
            minHeap.pop();
            minHeap.push(val);
        }
        return minHeap.top();
    }
};
