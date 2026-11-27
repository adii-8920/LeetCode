class Solution {
public:

    int solve(int start, int end){
        
        if(start >= end){
            return 0;
        }

        int mini= INT_MAX;
        for(int i= start; i<= end; i++){
            mini= min(mini, i + max(solve(start, i-1) , solve(i+ 1, end)));
        }

        return mini;
    }

    int solveMem(int start, int end, vector<vector<int>> &dp){
        
        if(start >= end){
            return 0;
        }

        if(dp[start][end] != -1){
            return dp[start][end];
        }

        int mini= INT_MAX;
        for(int i= start; i<= end; i++){
            mini= min(mini, i + max(solveMem(start, i-1, dp) , solveMem(i+ 1, end, dp)));
        }

        return dp[start][end]= mini;
    }

    int solveTab(int n){

        vector<vector<int>> dp(n+2, vector<int>(n+1, 0  ));

        for(int start= n; start >= 1; start--){
            for(int end= start; end<= n; end++){

                if(start == end){
                    continue;
                }

                int mini= INT_MAX;
                for(int i= start; i<= end; i++){
                    mini= min(mini, i + max(dp[start][i-1], dp[i+ 1][end])) ;
                }

                dp[start][end]= mini;
            }
        }
        return dp[1][n];
    }




    int getMoneyAmount(int n) {
        
        //return solve(1,n);

        //vector<vector<int>> dp(n+1, vector<int>(n+1, -1));
        //return solveMem(1, n, dp);

        return solveTab(n);
    }
};