class Solution {
public:
    //Tail recursion 
    int Fibonacci(int n) {
        return TailRecursion(n, 0, 1);
    }
    
    int TailRecursion(int n, int a, int b){
        if(n == 0) return 0;
        else if(n==1) return b;
        return TailRecursion(n-1, b, a + b);
    }
};
