//stack1 use to store the element of queue push
//stack2 use to pop the element of queue pop
//when stack2 is empty, push all the elements of stack1 to stack2
class Solution
{
public:
    void push(int node) {
     stack1.push(node);   
    }

    int pop() {
        /*
        while(!stack2.empty())
            stack2.pop();
        while(!stack1.empty()){
            stack2.push(stack1.top());
            stack1.pop();
        }
        int res = stack2.top();
        stack2.pop();
        while(!stack2.empty()){
            stack1.push(stack2.top());
            stack2.pop();
        }
        return res;
        */
        int res;
        if(stack2.empty()){
            while(!stack1.empty()){
                stack2.push(stack1.top());
                stack1.pop();
            }
        }
        res = stack2.top();
        stack2.pop();
        return res;
    }

private:
    stack<int> stack1;
    stack<int> stack2;
};
