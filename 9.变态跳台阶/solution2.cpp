class Solution {
public:
    //f(n)=2*f(n-1), n>=2;
    int jumpFloorII(int number) {
        if(number <= 0) return 0;
        if(number == 1) return 1;
        else return 2*jumpFloorII(number-1);
    }
};
