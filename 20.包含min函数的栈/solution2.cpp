
class Solution {
    typedef pair<int, int> fs;
    stack<fs> st;
public:
    void push(int value) {
        st.push(fs(value, ::min(value, st.empty()?value:st.top().second)));
    }
    void pop() {
        st.pop();
    }
    int top() {
        return st.top().first;
    }
    int min() {
        return st.top().second;
    }
};
