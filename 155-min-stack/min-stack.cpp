class MinStack {
public:
    stack<long long> st;
    long long currMin = LLONG_MAX;

    MinStack() {}

    void push(int val) {
        long long x = val;
        if (st.empty()) {
            st.push(x);
            currMin = x;
        } else {
            if (x >= currMin) 
                st.push(x);
            else {
                st.push(2 * x - currMin);
                currMin = x;
            }
        }
    }
    
    void pop() {
        if (st.empty()) return;
        long long x = st.top();
        st.pop();
        if (x < currMin) {
            currMin = 2 * currMin - x;
        }
    }
    
    int top() {
        if (st.empty()) return 0;
        long long x = st.top();
        if (x < currMin) return (int)currMin;
        return (int)x;
    }
    
    int getMin() {
        return (int)currMin;
    }
};
