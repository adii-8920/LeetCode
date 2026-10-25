class Solution {
public:
    int solveRec(vector<int> &coins, int amount, vector<int> &dp){

        //Base Case
        if(amount == 0){
            return 0;
        }
        if(amount < 0){
            return INT_MAX;
        }

        if(dp[amount] != -1){
            return dp[amount];
        }

        int mini= INT_MAX;
        for(int i= 0; i< coins.size(); i++){
            int ans= solveRec(coins, amount-coins[i], dp);//sub-problem ka answer nikala via recursion

            if(ans!= INT_MAX){
                mini= min(mini, 1+ ans);
            }
        }

        dp[amount]= mini;
        return dp[amount];

    }
    //Approach 2: Tabulation (Bottom-Up Approach)

int solveTab(vector<int> &coins, int x){

    vector<int> dp(x+1, INT_MAX);
    dp[0]= 0;
    
    for(int i= 1; i<= x; i++){
        //I am trying to solve for every amount figure from 1 to x 

        for(int j= 0; j< coins.size(); j++){
            
            if(i- coins[j] >= 0 && dp[i-coins[j]] != INT_MAX){
                dp[i]= min(dp[i], 1+ dp[i- coins[j]]);
            }

        }

    }

    if(dp[x] == INT_MAX){
        return -1;
    }

    return dp[x];

}





    int coinChange(vector<int>& coins, int amount) {
/*
        vector<int> dp(amount+1, -1);
        int ans= solveRec(coins, amount, dp);

        if(ans == INT_MAX){
            return -1;
        }

        return ans;
*/
        return solveTab(coins, amount);        
    }


};