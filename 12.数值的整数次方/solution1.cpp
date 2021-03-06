class Solution {
public:       
    /* normal way
        double reuslt = 1;
        for(int i = 0; i < exponent; ++i)
            result *= base;
        return result;
    */
    double Power(double base, int exponent) {
        if(equal_(base, 0.0) && exponent < 1)
            return 0.0;
        double absexp = exponent < 0? -exponent:exponent;
        double pexp = calculate(base, exponent);
        if(exponent < 0)
            pexp = 1./pexp;
        return pexp;
    }
    
    double calculate(double base, int times){ //快速幂运算递归写法
        if(times == 0) return 1;
        else if(times == 1) return base;
        double midv = calculate(base, times/2)* calculate(base, times/2);
        if(times % 2) midv *= base;
        return midv;
    }
    /* OR 快速幂迭代写法
    double rt = 1, mids = base;;
    while(times){
        rt *= mids;
        mids *= mids;
        rt = rt >> 1;
    }
    */
    
    bool equal_(double a, double b){
        if(a-b < 0.0000001 && a-b >-0.0000001)
            return true;
        else return false;
    }
};
