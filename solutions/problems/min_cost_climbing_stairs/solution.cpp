class Solution {
public:

    //Approach- 1: Recursion + Memoization
    /* 

    int solve2(vector<int> &cost, int n, vector<int> &dp){

        //Base Case
        if(n== 0){
            return cost[0];
        }
        if(n== 1){
            return cost[1];
        }

        //Step-3 
        if(dp[n] != -1){
            return dp[n];
        }

        //Step-2 
        dp[n]= cost[n] + min(solve2(cost, n-1, dp), solve2(cost, n-2, dp));
        return dp[n];
    }
*/  

/*
    int solve3(vector<int> &cost, int n){

        //Approach 2: Tabulation 
        //Step 1: Creation of DP array
        vector<int> dp(n+1);

        //Step 2: Base case analyse
        dp[0]= cost[0];
        dp[1]= cost[1];

        //Step 3: Populate the DP Array
        for(int i=2 ; i< n; i++){
            dp[i]= cost[i] + min(dp[i-1], dp[i-2]);
        }

        //Return answer 
        return min(dp[n-1], dp[n-2]);//Recursive Call

    }
*/

    int solve4(vector<int> &cost, int n){

        //Approach 3: Space Optimization 
        
        int prev2= cost[0];
        int prev1= cost[1];

        for(int i=2 ; i< n; i++){
            int curr= cost[i] + min(prev1, prev2);
            prev2= prev1;
            prev1= curr;
        }

        //Return answer 
        return min(prev1, prev2);//Recursive Call

    }


    

    int minCostClimbingStairs(vector<int>& cost) {

        /*
        int n= cost.size();
        vector<int> dp(n+1, -1);

        int ans= min(solve2(cost,n-1, dp), solve2(cost, n-2, dp)); //for n
        return ans;  
        */

        int n= cost.size();
        return solve4(cost, n);
    }
    

    


};