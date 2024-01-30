class MinStack {

    stack<long long int>ST;
    long long curr_min;
public:
    MinStack() {
        // while(ST.empty()==false)
        //     ST.pop();
        curr_min = LONG_MAX;
    }
    
    void push(int value) {

        long long val = value;
        if(ST.empty())
        {
            ST.push(val);
            curr_min = val;
        }
        else if(val < curr_min)
        {
            ST.push((long long)(2*val) - curr_min);
            curr_min = val;
        }
        else
        {
            ST.push(val);
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
            curr_min = (long long)(2*curr_min) - ST.top();
            ST.pop();
        }
    }
    
    int top() {
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