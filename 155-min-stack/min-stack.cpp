class MinStack {
    stack<long long int> ST;
    long long int curr_min ;
public:
    MinStack() {
        curr_min = INT_MAX;
    }
    
    void push(int val) {
        long long int value = val;
        if(ST.empty())
        {
            curr_min = value;
            ST.push(value);
        }
        else if(value < curr_min)
        {
            ST.push(2*value - curr_min);
            curr_min = value;
        }
        else
        {
            ST.push(value);
        }
    }
    
    void pop() {
        if(ST.empty())
            return;
        
        if(ST.top() > curr_min)
        {
            ST.pop();
        }
        else
        {
            
            curr_min = (2*curr_min - ST.top());
            ST.pop();
        }
    }
    
    int top() {
        if(ST.empty())
            return -1;
        if(ST.top() > curr_min)
            return ST.top();
        return curr_min;
    }
    
    int getMin() {
        return curr_min;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */