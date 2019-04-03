class Solution {
public:
    // f(n) = f(n-1) + f(n-2): imply that this can use recursion, but have too many repeat calculate
    // repeat calculate can use memory table to avoid, but in this problem that is not wisdom. 
    int Fibonacci(int n) {
        int a = 1;
        int b = 1;
        if(n == 0)
            return 0;
        if(n == 1 || n == 2){
            return 1;
        }
        int i = 3;
        int c;
        while(i <= n){
            c = a + b;
            a = b;
            b = c;
            i++;
        }
        return c;
        
        //OR write in this way
      /*int a = 0;
        int b = 1;
        while(n--){
        b = a + b;
        a = b - a;
        }
        return b;
    }
};
