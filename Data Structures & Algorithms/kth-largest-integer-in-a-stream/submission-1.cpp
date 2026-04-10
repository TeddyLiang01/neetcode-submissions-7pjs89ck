class KthLargest {
private:
    int k;
    priority_queue<int, vector<int>, greater<int>> maxHeap;
public:
    KthLargest(int k, vector<int>& nums) {
        this->k = k;
        for (int i : nums) {
            maxHeap.push(i);
            if (maxHeap.size() > k) {
                maxHeap.pop();
            }
        }
    }
    
    int add(int val) {
        maxHeap.push(val);
        if (maxHeap.size() > k) {
            maxHeap.pop();
        }
        return maxHeap.top();
    }

};
