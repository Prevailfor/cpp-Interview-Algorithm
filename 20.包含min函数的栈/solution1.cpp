class Solution {
public:
    
    stack<int> st;
    stack<int> stmin;
    
    void push(int value) {
        st.push(value);
        if(stmin.empty()){
            stmin.push(value);
        }
        else{
            if(value < stmin.top()){
                stmin.push(value);
            }
        }
        
    }
    void pop() {
        if(st.top() == stmin.top()){
            st.pop();
            stmin.pop();
        }
        else {
            st.pop();
        }
    }
    int top() {
        return st.top();
    }
    int min() {
        return stmin.top();
    }
};
