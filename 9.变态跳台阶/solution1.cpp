class Solution {
public:
    // f(n) = f(n-1)+f(n-2)+...+f(n-(n-1))+f(n-n).here f(n-n) = f(0) = 0;
    int jumpFloorII(int number) {
        int n = number;
        int dp[100000] = {0};
        memset(dp, 0, sizeof(dp)/sizeof(dp[0]));
        dp[0] = 0;
        dp[1] = 1;
        dp[2] = 2;
        for(int i = 3; i <= n; ++i){
            for(int j = 1; j <= i-1; ++j){
                dp[i] += dp[j];
            }
            dp[i] += 1;
        }
        
        return dp[n];
    }
};
