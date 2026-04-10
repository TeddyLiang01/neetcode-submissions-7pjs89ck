class MinStack {

private:
    stack<int> minStack;
    stack<int> normalStack;
public:
    MinStack() {

    }
    
    void push(int val) {
        normalStack.push(val);
        if (minStack.size() != 0) {
            if (val < minStack.top()) {
                minStack.push(val);
            } else {
                minStack.push(minStack.top());
            }
        } else {
            minStack.push(val);
        }
    }
    
    void pop() {
        normalStack.pop();
        minStack.pop();    
    }
    
    int top() {
        return normalStack.top();
    }
    
    int getMin() {
        return minStack.top();
    }
};
