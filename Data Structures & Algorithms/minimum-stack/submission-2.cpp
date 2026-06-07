class MinStack {
    stack<int>stk;
   map<int,int>mp;
public:
    MinStack() {
        
    }
    
    void push(int val) {
        stk.push(val);
        mp[val]++;
    }
    
    void pop() {
        int val=stk.top();
        stk.pop();
        mp[val]--;
        if(mp[val]==0)
          mp.erase(val);
    }
    
    int top() {
        return stk.top();
    }
    
    int getMin() {
        return mp.begin()->first;
    }
};
