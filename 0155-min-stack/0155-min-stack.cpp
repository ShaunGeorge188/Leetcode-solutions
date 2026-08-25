class MinStack {
    stack<pair<int,int>> st;   // {value, min-so-far}
public:
    void push(int val) {
        int currMin = st.empty() ? val : min(val, st.top().second);
        st.push({val, currMin});
    }

    void pop() { st.pop(); }

    int top() { return st.top().first; }

    int getMin() { return st.top().second; }
};