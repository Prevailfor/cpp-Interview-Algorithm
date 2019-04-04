
class Solution {
public:
    
     int sdfs(int n){
        if(n == 0)
            return 1;
        else if(n < 0)
            return 0;
        int num = 0;
        //num += dfs2(n-1);
        //num += dfs2(n-2);
        return sdfs(n-1) + sdfs(n-2);
    }
    
    int mark[10000];
    int cts;
    //static int cts;
    int jumpFloor(int number) {
        /*
        for(int i = 0; i < sizeof(mark)/sizeof(mark[0]); ++i)
            mark[i] = 0;
        
        cts = 0;
        dfs(number);
        return cts;
        */
        
        
        
        //int res = sdfs(0);
        //why have problem?  
        //return dfs2(number);
      
        // dp 
        // state: dp[i] the numbers of step of i step
        // state transition equation: dp[i] = dp[i-1] + dp[i-2](i>=2)
        // edge: dp[1] = 1, dp[2] = 2;
        // calculation oder : for i:3->n;
        int n = number;
        int dp[100000] = {0};
        dp[0] = 0;
        dp[1] = 1;
        dp[2] = 2;
        for(int i = 3; i <=n; ++i)
            dp[i] = dp[i-1] + dp[i-2];
        
        return dp[n];
    }
    
    
    void dfs(int n){
        if(n == 0){
            cts++;
            return ;
        }
        else if(n < 0)
            return;

        dfs(n-1);
        dfs(n-2);
    }
    
    
};
