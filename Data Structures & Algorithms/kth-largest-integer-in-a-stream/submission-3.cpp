class KthLargest {

private:
    int kth;
    priority_queue<int, vector<int>, greater<int>> minHeap;

public:
    KthLargest(int k, vector<int>& nums) : kth{k} {
        for (int n : nums) {
            minHeap.push(n);
            if (minHeap.size() > kth) {
                minHeap.pop();
            }
        }
       
    }
    int add(int val) {
        if (minHeap.size() < kth) {
            minHeap.push(val);
        } else {
            if (minHeap.top() < val) {
                minHeap.pop();
                minHeap.push(val);
            }
        }
        return minHeap.top();
    }
};
