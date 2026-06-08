class MyStack {
    queue<int> q1;
    queue<int> q2;

public:
    MyStack() {}
    void push(int x) {
        // Q1 -> Q2
        while (!q1.empty()) {
            q2.push(q1.front());
            q1.pop();
        }
        q1.push(x);
        // Q2 -> Q1
        while (!q2.empty()) {
            q1.push(q2.front());
            q2.pop();
        }
    }
    int pop() {
        if (empty()) {
            return -1;
        }
        int top = q1.front();
        q1.pop();
        return top;
    }
    int top() {
        if (empty()) {
            return -1;
        }
        return q1.front();
    }
    bool empty() { return q1.empty(); }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */