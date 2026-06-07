class MinStack {
    stack<int> st,minSt;
public:
    MinStack() {
        
    }
    
    void push(int val) {
        st.push(val);
        if (minSt.size()!=0)
            val=min(val,minSt.top());
        minSt.push(val);
    }
    
    void pop() {
        st.pop();
        minSt.pop();
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        return minSt.top();
    }
};
