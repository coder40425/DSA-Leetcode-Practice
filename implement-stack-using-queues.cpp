class MyStack {
    queue<int> q1;
    queue<int> q2;

public:
    void push(int x) {
        // Step 1: Move all elements from q1 to q2
        while (!q1.empty()) {
            q2.push(q1.front());
            q1.pop();
        }

        // Step 2: Push x into q1 (new element goes to front)
        q1.push(x);

        // Step 3: Move everything back from q2 to q1
        while (!q2.empty()) {
            q1.push(q2.front());
            q2.pop();
        }
    }

    int pop() {
        if (!q1.empty()) {
            int val = q1.front();
            q1.pop();
            return val;
        }
        return -1;
    }

    int top() {
        if (!q1.empty()) {
            return q1.front();
        }
        return -1;
    }

    bool empty() {
        return q1.empty();
    }
};
