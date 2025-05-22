class MinStack {
    stack<int> s;
    stack<int> m;  //minstack
public:
    MinStack() {
        
    }
    
    void push(int val) {
        s.push(val);
        if(m.empty() || val<=m.top()){
            m.push(val);
        }
    }
    
    void pop() {
        if(s.empty()) return;
        if(s.top()==m.top()){
            m.pop();
            
        }
        s.pop();
    }
    
    int top() {
        if(s.empty()) return -1;
        return s.top();
        
    }
    
    int getMin() {
        if(m.empty()) return -1;
        return m.top();
    }
};
